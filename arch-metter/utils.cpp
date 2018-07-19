#include "stdafx.h"

FILE* __f_datas;

void chech_file() {
	__f_datas = fopen(MEMORY_FILE, "r+");
	if(__f_datas==NULL){
		__f_datas = fopen(MEMORY_FILE, "wb");
		fclose(__f_datas);
	}
}

void add_record_to_archive(struct arch_phases* aph) {
	//chech_file();
	__f_datas= fopen(MEMORY_FILE, "r+");
	if (__f_datas != NULL) {
		metphase mph;
		if ((__arch_count_records + 1) <= COUNT_RECORDS) {
			pack_arch_phase(&mph, aph);
			//__memcpy(&__datas[__arch_count_records*SIZE_RECORD], &mph, SIZE_RECORD);
			fseek(__f_datas, __arch_count_records*SIZE_RECORD, SEEK_SET);
			fwrite(&mph, 16, 1, __f_datas);
			__arch_count_records++;
			__current_record = __arch_count_records - 1;
		}
		else {
			u32 cur_rec = 0;
			for (u32 i = 0; i < COUNT_RECORDS; i++)
			{
				cur_rec++;
				metphase lph;
				struct arch_phases aph_;
				__memset(&aph_, 0, 0);
				fseek(__f_datas, cur_rec*SIZE_RECORD, SEEK_SET);
				fread(&lph, 16, 1, __f_datas);
				//__memcpy(&lph, &__datas[cur_rec*SIZE_RECORD], SIZE_RECORD);
				fseek(__f_datas, (cur_rec - 1)*SIZE_RECORD, SEEK_SET);
				fwrite(&lph, 16, 1, __f_datas);
				__memcpy(&__datas[(cur_rec - 1)*SIZE_RECORD], &lph, SIZE_RECORD);
			}
			pack_arch_phase(&mph, aph);
			fseek(__f_datas, (cur_rec - 1)*SIZE_RECORD, SEEK_SET);
			fwrite(&mph, 16, 1, __f_datas);
			//__memcpy(&__datas[(cur_rec - 1)*SIZE_RECORD], &mph, SIZE_RECORD);
			__current_record = COUNT_RECORDS - 1;
		}
		if (__f_datas != NULL)
		{
			fclose(__f_datas);
		}
		//fseek(__f_datas, 0, SEEK_END);
		//fwrite(s, 6, 1, __f_datas);
		//fclose(__f_datas);
	}
}