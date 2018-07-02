#ifndef __GLOBAL_H__
#define __GLOBAL_H__

#define SIZE_RECORD 16
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

/*memory copy src-where dest-when size-size write*/

typedef u8 metphase[SIZE_RECORD];
#define mem_cpy(src,dest,size) memcpy(src,dest,size)

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

