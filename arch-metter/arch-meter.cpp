#include "stdafx.h"
#include <Windows.h>

#define random() rand()%100;

int main()
{
	metphase a;
	struct metter_datetime dt = {18,7,1,12,30};
	arch_phases ph = { dt,9,1,2,3 };
	int x = 0;
	chech_file();
	while (true)
	{
		
		ph.phase_1 = random();
		//printf("records:%d\r\n", ph_records);
		_add_minutes(&ph.adt, 30);
		add_record(&ph);
		//add_record_to_archive(&ph);
		Sleep(10);
		
		if (__current_index > 11) {
			//arch_phases al[10];
			//arch_get_record_by_index(0,al,10);
			struct metter_datetime dts = { 18,7,1,14,0 };
			arch_phases ph_1;
			bool res=get_values_from_datetime(&dts, &ph_1);
			if (res) {
				int x = 0;
			}
			int x = 0;
		}
		struct arch_phases spp;
		unpack_arch_phase(&a, &spp);
		//x++;
		//printf("%d.%d.%d %d:%d\r\n", ph.adt.year, ph.adt.month, ph.adt.day, ph.adt.hour, ph.adt.minute);
		//printarch();
		//OUTD("current index:%d\r\n", __current_index);
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

