#include "stdafx.h"

#define COUNT_DAY_RECORD 48
#define COUNT_DAYS_RECORDS 60
#define DAY_RECORD (SIZE_RECORD*COUNT_DAY_RECORD)
#define ALL_RECORDS (DAY_RECORD*COUNT_DAYS_RECORDS)
#include <Windows.h>
int main()
{
	
	metphase a;
	struct metter_datetime dt = {18,7,1,12,59};
	u8 s = 1;
	while (true)
	{
		_add_hours(&dt,1);
		
		Sleep(500);
		printf("dt:%d.%d.%d %d:%d\r\n", dt.year, dt.month, dt.day, dt.hour, dt.minute);

	}

	arch_phases ph = {dt,9,1,2,3};
	pack_arch_phase(&a, &ph);
	arch_phases ph_1;
	unpack_arch_phase(&a, &ph_1);

    return 0;
}

