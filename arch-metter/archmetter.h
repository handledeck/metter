#include "global.h"
#ifndef __ARCHMETTER_H__
#define __ARCHMETTER_H__

void check_phase(float phase_1, float phase_2, float phase_3, u8 veracity, struct metter_datetime mdt, struct arch_phases* valmet);
u32 arch_time_to_value(struct metter_datetime *time);
void arch_value_to_time(const u32 value, struct metter_datetime *time);
void pack_arch_phase(metphase* data, arch_phases* ph);
void unpack_arch_phase(metphase* data, arch_phases* ph);
#endif // !__ARCHMETTER_H__

