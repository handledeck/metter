#include "config.h"
#ifndef __ARCHMETTER_H__
#define __ARCHMETTER_H__



void check_phase(u32 phase_1, u32 phase_2, u32 phase_3, u8 veracity, struct metter_datetime mdt, struct arch_phases* valmet);
void pack_arch_phase(metphase* data, arch_phases* ph);
void unpack_arch_phase(metphase* data, arch_phases* ph);
void add_record(struct arch_phases* aph);
void arch_get_record_by_index(u32 index, arch_phases* arraymph, u8 count);
bool get_values_from_datetime(metter_datetime* dt, arch_phases* mph);
void printarch();
#endif // !__ARCHMETTER_H__

