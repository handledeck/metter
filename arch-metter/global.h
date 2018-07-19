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
/*����� ������*/
#define __strstr(source_string,sub_string) strstr(source_string,sub_string) 
/*������ � �����*/
#define __atoi(str) atoi(str)
/*�������� �� �����*/
#define __isdigit(int_c) isdigit(int_c)
/*�������� �� ������*/
#define __abs(int_c) abs(int_c)
/*������� ������ ����������� value*/
#define __memset(dest,value,size) memset(dest,value,size)

/*���� � ����� �������� ������
year   - 7 ��� 2000 ��� + 163
month  - 4 ��� 1-12 �����
day    - 5 ��� 1-31 ����
hour   - 5 ��� 0-23 ���
minute - 6 ��� 0-59 �����
*/

struct metter_datetime
{
	u8 year : 7;
	u8 month : 4;
	u8 day : 5;
	u8 hour : 5;
	u8 minute : 6;
};

/*����, �����, �������� �� �����, ������������� 
	adt      - ���� � ����� �����
	veracity - 5 ��� 1 ��� - ������������� 1 ����,
					 2 ��� - ������������� 2 ����,
					 3 ��� - ������������� 3 ����,
					 4-5 ���� ���������������
	phase_1  - �������� �� ���� 1
	phase_2  - �������� �� ���� 2
	phase_3  - �������� �� ���� 3
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

