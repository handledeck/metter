#include "stdafx.h"

u8 __datas[ALL_RECORDS];
u32 __arch_count_records = 0;
u32 __current_record=0;

void check_phase(float phase_1, float phase_2, float phase_3, u8 veracity, struct metter_datetime mdt, struct arch_phases* valmet)
{
	valmet->phase_1 = phase_1;
	valmet->phase_2 = phase_2;
	valmet->phase_3 = phase_3;
	valmet->veracity = veracity;
	valmet->adt = mdt;
};

void pack_arch_phase(metphase* data, arch_phases* ph) {
	metphase da;
	u32 val = _calendar_time_to_value(&ph->adt);
	val |= (ph->veracity << 0);
	__memcpy(&da[12], &val, 4);
	__memcpy(&da[8], &ph->phase_3, 4);
	__memcpy(&da[4], &ph->phase_2, 4);
	__memcpy(&da[0], &ph->phase_1, 4);
	__memcpy(data, &da[0], 16);
}

void unpack_arch_phase(metphase* data, arch_phases* ph) {
	metter_datetime dt;
	metphase da;
	u32 val = 0;
	__memcpy(&da, data, SIZE_RECORD);
	__memcpy(&val, &da[12], 4);
	_calendar_value_to_time(val, &ph->adt);
	ph->veracity = ((val & (0x3Ful << 0)) >> 0);
	__memcpy(&ph->phase_3, &da[8], 4);
	__memcpy(&ph->phase_2, &da[4], 4);
	__memcpy(&ph->phase_1, &da[0], 4);
}

void add_record(struct arch_phases* aph) {
	metphase mph;
	if ((__arch_count_records*SIZE_RECORD) + SIZE_RECORD <= ALL_RECORDS) {
		pack_arch_phase(&mph, aph);
		__memcpy(&__datas[__arch_count_records*SIZE_RECORD], &mph, SIZE_RECORD);
		__arch_count_records++;
		__current_record = __arch_count_records - 1;
	}
	else {
		u32 cur_rec = 0;
		for (u32 i = 0; i < COUNT_RECORDS; i++)
		{
			cur_rec++;
			metphase lph;
			struct arch_phases aph_;
			__memset(&aph_, 0, 0);
			__memcpy(&lph, &__datas[cur_rec*SIZE_RECORD], SIZE_RECORD);
			__memcpy(&__datas[(cur_rec - 1)*SIZE_RECORD], &lph, SIZE_RECORD);
		}
		pack_arch_phase(&mph, aph);
		__memcpy(&__datas[(cur_rec - 1)*SIZE_RECORD], &mph, SIZE_RECORD);
		__current_record = COUNT_RECORDS-1;
	}
}

/*получение архивных значений по индексу от текущего*/
void arch_get_record_by_index(u32 index) {

}

void printarch() {
	printf("----------------------------------------\r\n");
	for (u32 i = 0; i < COUNT_RECORDS; i++)
	{
		metphase lph;
		struct arch_phases aph_;
		__memset(&aph_, 0, 0);
		__memcpy(&lph, &__datas[i*SIZE_RECORD], SIZE_RECORD);
		unpack_arch_phase(&lph, &aph_);
		printf("record %d) %d.%d.%d %d:%d ph1:%d ph2:%d ph3:%d\r\n", i, aph_.adt.year, aph_.adt.month, aph_.adt.day, aph_.adt.hour, aph_.adt.minute,
			aph_.phase_1, aph_.phase_2, aph_.phase_3);
	}
}