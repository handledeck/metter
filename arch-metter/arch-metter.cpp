#include "stdafx.h"

int main()
{
	metphase a;
	metphase a_1;
	struct metter_datetime dt = {18,7,1,12,59};
	arch_phases ph;
	check_phase(1, 2, 3, 9, dt, &ph);
	pack_arch_phase(&a, &ph);
	
	//mem_cpy(mem, &ph, SIZE_RECORD);
	arch_phases ph_1;
	unpack_arch_phase(&a, &ph_1);
	//mem_cpy(&ph_1, mem, SIZE_RECORD);
	//u32 dd=arch_time_to_value(&dt);
	//struct metter_datetime ddtt;
	//arch_value_to_time(dd, &ddtt);
    return 0;
}

