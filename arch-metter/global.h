#ifndef __GLOBAL_H__
#define __GLOBAL_H__

//#include "archmetter.h"
//#include "calendar.h"

#define SIZE_RECORD 16

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;


/*memory copy src-where dest-when size-size write*/

typedef u8 metphase[SIZE_RECORD];
#define __memcpy(src,dest,size) memcpy(src,dest,size)
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

/*Дата и время архивной записи*/

struct metter_datetime
{
	u8 year : 7;
	u8 month : 4;
	u8 day : 5;
	u8 hour : 5;
	u8 minute : 6;
};

/*Дата, время, значение по фазам, достоверность */
struct arch_phases
{
	metter_datetime adt;
	u8 veracity : 5;
	u32 phase_1;
	u32 phase_2;
	u32 phase_3;
};


#endif // !__GLOBAL_H__

