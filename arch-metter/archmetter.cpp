#include "stdafx.h"

void check_phase(float phase_1, float phase_2, float phase_3, u8 veracity, struct metter_datetime mdt, struct arch_phases* valmet)
{
	valmet->phase_1 = phase_1;
	valmet->phase_2 = phase_2;
	valmet->phase_3 = phase_3;
	valmet->veracity = veracity;
	valmet->adt = mdt;
};

//u32 arch_time_to_value(struct metter_datetime *time)
//{
//	u32 value;
//	value = time->year << 25;
//	value |= (time->month << 21);
//	value |= (time->day << 16);
//	value |= (time->hour << 11);
//	value |= (time->minute << 5);
//	//value |= (time->veracity << 4);
//	//value |= (time->reserved << 0);
//	return value;
//}
//
//void arch_value_to_time(const u32 value, struct metter_datetime *time)
//{
//	time->year = (value &  (0x3Ful << 25)) >> 25;
//	time->month = ((value & (0xFul << 21)) >> 21);
//	time->day = ((value & (0x1Ful << 16)) >> 16);
//	time->hour = ((value & (0x1Ful << 11)) >> 11);
//	time->minute = ((value & (0x3Ful << 5)) >> 5);
//	//time->veracity = ((value & (0x3Ful << 4)) >> 4);
//	//time->reserved = ((value & (0x3Ful << 0)) >> 0);
//}

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