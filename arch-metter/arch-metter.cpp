#include "stdafx.h"

int main()
{
	metphase a;
	struct metter_datetime dt = {18,7,1,12,59};
	arch_phases ph = {dt,9,1,2,3};
	pack_arch_phase(&a, &ph);
	arch_phases ph_1;
	unpack_arch_phase(&a, &ph_1);
    return 0;
}

