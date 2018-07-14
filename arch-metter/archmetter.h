#include "global.h"
#ifndef __ARCHMETTER_H__
#define __ARCHMETTER_H__


#define SIZE_RECORD 16
#define COUNT_DAY_RECORD 48
#define COUNT_DAYS_RECORDS 1
#define DAY_RECORD (SIZE_RECORD*COUNT_DAY_RECORD)
#define ALL_RECORDS (DAY_RECORD*COUNT_DAYS_RECORDS)
#define COUNT_RECORDS	(ALL_RECORDS/SIZE_RECORD)

extern u8 __datas[ALL_RECORDS];
extern u32 __arch_count_records;
extern u32 __current_record;

/*memory copy src-where dest-when size-size write*/

typedef u8 metphase[SIZE_RECORD];

void check_phase(float phase_1, float phase_2, float phase_3, u8 veracity, struct metter_datetime mdt, struct arch_phases* valmet);
//u32 arch_time_to_value(struct metter_datetime *time);
//void arch_value_to_time(const u32 value, struct metter_datetime *time);
void pack_arch_phase(metphase* data, arch_phases* ph);
void unpack_arch_phase(metphase* data, arch_phases* ph);
void add_record(struct arch_phases* aph);
void printarch();
#endif // !__ARCHMETTER_H__

