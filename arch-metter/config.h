#ifndef __GLOBAL_H__
#define __GLOBAL_H__

#define MEMORY_SIZE	64*1024 //64 килобайт памяти
#define SIZE_RECORD 16		//16 размер одной записи
#define COUNT_RECORDS	(MEMORY_SIZE/SIZE_RECORD)

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef u8 metphase[SIZE_RECORD];

#define OUTD(FORMAT,...) \
printf(FORMAT,##__VA_ARGS__,"\r\n");

/**/
#define __memcpy(destination,source,size) memcpy(destination,source,size)
/*поиск строки*/
#define __strstr(source_string,sub_string) strstr(source_string,sub_string) 
/*строка в число*/
#define __atoi(str) atoi(str)
/*проверка на сисло*/
#define __isdigit(int_c) isdigit(int_c)
/*значение по модулю*/
#define __abs(int_c) abs(int_c)
/*участок памяти заполненный value*/
#define __memset(dest,value,size) memset(dest,value,size)
/*выделение памяти*/
#define __malloc(size) malloc(size)


/*Общие константы устройства*/
struct genl_metter {
	//тип счетчика
	u8 type_metter[4];
	//серийный номер
	u32 serial_part;
	//дата изготовления
	u32 date_produced;
	//версия ПО
	u8 version_po[8];
};

/*Дата и время архивной записи
year   - 7 бит 2000 год + 163
month  - 4 бит 1-12 месяц
day    - 5 бит 1-31 день
hour   - 5 бит 0-23 час
minute - 6 бит 0-59 минут
*/

struct metter_datetime
{
	u8 year : 7;
	u8 month : 4;
	u8 day : 5;
	u8 hour : 5;
	u8 minute : 6;
};

/*Дата, время, значение по фазам, достоверность 
	adt      - дата и время среза
	veracity - 5 бит 1 бит - достоверность 1 фаза,
					 2 бит - достоверность 2 фаза,
					 3 бит - достоверность 3 фаза,
					 4-5 биты зарезервированы
	phase_1  - значение по фазе 1
	phase_2  - значение по фазе 2
	phase_3  - значение по фазе 3
*/
struct arch_phases
{
	metter_datetime adt;
	u8 veracity : 5;
	u32 phase_1;
	u32 phase_2;
	u32 phase_3;
};

extern u8 __datas[MEMORY_SIZE];
extern u32 __arch_count_records;
extern u32 __current_index;


#endif // !__GLOBAL_H__

