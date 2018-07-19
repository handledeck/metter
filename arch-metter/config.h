#ifndef __GLOBAL_H__
#define __GLOBAL_H__

#define MEMORY_SIZE	64*1024 //64 �������� ������
#define SIZE_RECORD 16		//16 ������ ����� ������
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
/*��������� ������*/
#define __malloc(size) malloc(size)


/*����� ��������� ����������*/
struct genl_metter {
	//��� ��������
	u8 type_metter[4];
	//�������� �����
	u32 serial_part;
	//���� ������������
	u32 date_produced;
	//������ ��
	u8 version_po[8];
};

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

extern u8 __datas[MEMORY_SIZE];
extern u32 __arch_count_records;
extern u32 __current_index;


#endif // !__GLOBAL_H__

