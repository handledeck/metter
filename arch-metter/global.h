#ifndef __GLOBAL_H__
#define __GLOBAL_H__

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

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


#endif // !__GLOBAL_H__

