#include "stdafx.h"
#include <Windows.h>

#define COUNT_DAY_RECORD 10
#define COUNT_DAYS_RECORDS 1
#define DAY_RECORD (SIZE_RECORD*COUNT_DAY_RECORD)
#define ALL_RECORDS (DAY_RECORD*COUNT_DAYS_RECORDS)
#define COUNT_RECORDS	(ALL_RECORDS/SIZE_RECORD)

u8 datas[ALL_RECORDS];
u32 ph_records = 0;

void printda();

void add(struct arch_phases* aph) {
	metphase mph;
	if ((ph_records*SIZE_RECORD) + SIZE_RECORD <= ALL_RECORDS) {
		pack_arch_phase(&mph, aph);
		__memcpy(&datas[ph_records*SIZE_RECORD], &mph, SIZE_RECORD);
		ph_records++;
		
	}
	else {
		u32 cur_rec = 0;
		for (u32 i = 0; i < COUNT_RECORDS; i++)
		{
			cur_rec++;
			metphase lph;
			struct arch_phases aph_;
			__memset(&aph_, 0, 0);
			__memcpy(&lph, &datas[cur_rec*SIZE_RECORD], SIZE_RECORD);
			__memcpy(&datas[(cur_rec-1)*SIZE_RECORD],&lph, SIZE_RECORD);
			
			
		}
		pack_arch_phase(&mph, aph);
		__memcpy(&datas[(cur_rec-1)*SIZE_RECORD], &mph, SIZE_RECORD);
		printda();
	}
}

void printda() {
	printf("----------------------------------------\r\n");
	for (u32 i = 0; i < COUNT_RECORDS; i++)
	{
		metphase lph;
		struct arch_phases aph_;
		__memset(&aph_, 0, 0);
		__memcpy(&lph, &datas[i*SIZE_RECORD], SIZE_RECORD);
		unpack_arch_phase(&lph, &aph_);
		printf("record %d) %d:%d\r\n", i, aph_.adt.hour, aph_.adt.minute);

	}
}

int main()
{
	u32 sz = ALL_RECORDS;
	metphase a;
	struct metter_datetime dt = {18,7,1,12,30};
	arch_phases ph = { dt,9,1,2,3 };
	int x = 0;
	while (true)
	{
		ph.phase_1 = x;
		//printf("records:%d\r\n", ph_records);
		_add_minutes(&ph.adt, 30);
		add(&ph);
		Sleep(500);
		x++;
		
	}
/*	u8 s = 1;
	while (true)
	{
		_add_hours(&dt,1);
		Sleep(500);
		u32 val= _calendar_time_to_value(&dt);
		metter_datetime redt;
		_calendar_value_to_time(val, &redt);
		printf("dt:%d.%d.%d %d:%d\r\n", redt.year, redt.month, redt.day, redt.hour, redt.minute);
	}
*/
	
	pack_arch_phase(&a, &ph);
	arch_phases ph_1;
	
	unpack_arch_phase(&a, &ph_1);

    return 0;
}

