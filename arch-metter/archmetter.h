#include "global.h"
#ifndef __ARCHMETTER_H__
#define __ARCHMETTER_H__

#define MEMORY_SIZE	5*1024 //90 килобайт памяти
#define SIZE_RECORD 16		//16 размер одной записи
//#define COUNT_DAY_RECORD 48
//#define COUNT_DAYS_RECORDS 1
//#define DAY_RECORD (SIZE_RECORD*COUNT_DAY_RECORD)
//#define ALL_RECORDS (DAY_RECORD*COUNT_DAYS_RECORDS)
#define COUNT_RECORDS	(MEMORY_SIZE/SIZE_RECORD)

extern u8 __datas[MEMORY_SIZE];
extern u32 __arch_count_records;
extern u32 __current_record;

/*memory copy src-where dest-when size-size write*/
typedef u8 metphase[SIZE_RECORD];

void check_phase(u32 phase_1, u32 phase_2, u32 phase_3, u8 veracity, struct metter_datetime mdt, struct arch_phases* valmet);
void pack_arch_phase(metphase* data, arch_phases* ph);
void unpack_arch_phase(metphase* data, arch_phases* ph);
void add_record(struct arch_phases* aph);
void printarch();
#endif // !__ARCHMETTER_H__

