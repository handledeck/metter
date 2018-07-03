#include "stdafx.h"

const u8 _month[2][12] = {
	{ 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 },
{ 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }
};


bool calendar_is_date_valid(struct metter_datetime *date) {
	if ((date->minute >= 60) || (date->hour >= 24)) {
		return false;
	}
	if ((date->month > 12) || (date->day > 31)) {
		return false;
	}
	else {
		return true;
	}
}

bool get_date_time_from_str(u8* dt_str, struct metter_datetime* time) {
	char* gdate = __strstr((char*)dt_str, "DATE:");
	if (gdate) {
		gdate += 5;
		time->year = __atoi(gdate);
		if (!__isdigit(time->year) && time->year<2000)
			return false;
		gdate += 5;
		time->month = __atoi(gdate);
		if (!isdigit(time->month) && time->month>12 && time->month<1)
			return false;
		gdate += 3;
		time->day = __atoi(gdate);
		if (!isdigit(time->day) && time->day>31 && time->day<1)
			return false;
		gdate += 3;
		time->hour = __atoi(gdate);
		if (!isdigit(time->hour) && time->hour>23 && time->hour<0)
			return false;
		gdate += 3;
		time->minute = __atoi(gdate);
		if (!isdigit(time->minute) && time->minute>59 && time->minute<1)
			return false;
		return true;
	}
	else
		return false;
}

bool _leapyear(u16 year)
{
	if (!((year) % 4) && (((year) % 100) || !((year) % 400))) {
		return true;
	}
	else {
		return false;
	}
}

void _add_month_to_date(struct metter_datetime *date)
{
	u8 months = date->month;
	months++;
	if (months == 13) {
		months = 1;
		date->year++;
	}
	date->month = months;
}

void _remove_month_to_date(struct metter_datetime *date)
{
	u8 months = date->month;
	months--;
	if (months == 0) {
		months = 12;
		date->year--;
	}
	date->month = months;
}

u32 add_minute_to_stamp(u32 valtime, s16 minutes) {
	struct metter_datetime ti;
	_calendar_value_to_time(valtime, &ti);
	_add_minutes(&ti, minutes);
	return _calendar_time_to_value(&ti);
}

void _add_day_to_date(struct metter_datetime *date)
{
	u8 dates = date->day;
	u8 months = date->month;
	u16 year = date->year;
	months--;
	dates++;
	if (dates > _month[_leapyear(year)][months]) {
		dates = 1;
		_add_month_to_date(date);
	}

	date->day = dates;
}

void _remove_day_to_date(struct metter_datetime *date)
{
	s8 dates = date->day;
	u8 months = date->month;
	u16 year = date->year;
	months--;
	dates--;
	if (dates < 1) {
		date->day = _month[_leapyear(year)][months];
		_remove_month_to_date(date);
	}
	else
		date->day = dates;
}

void _add_hour_to_date(struct metter_datetime *date)
{
	s8 hour = date->hour;
	hour++;
	if (hour == 24) {
		hour = 0;
		_add_day_to_date(date);
	}
	date->hour = hour;
}

void _remove_hour_to_date(struct metter_datetime *date)
{
	s8 hour = date->hour;
	hour--;
	if (hour < 0) {
		hour = 23;
		_remove_day_to_date(date);
	}
	date->hour = hour;
}


void _add_minute_to_date(struct metter_datetime *date)
{
	u8 minute = date->minute;
	minute++;
	if (minute == 60) {
		minute = 0;
		_add_hour_to_date(date);
	}
	date->minute = minute;
}

void _remove_minute_to_date(struct metter_datetime *date)
{
	s8 minute = date->minute;
	minute--;
	if (minute < 0) {
		minute = 59;
		_remove_hour_to_date(date);
	}
	date->minute = minute;
}

void _add_hours(struct metter_datetime* tm, s16 hours) {
	if (abs(hours) <= 12) {
		if (hours > 0) {
			s16 check = tm->hour + hours;
			if (check > 23) {
				s16 delt = check - 24;
				_add_day_to_date(tm);
				tm->hour = delt;
			}
			else
				tm->hour += hours;
		}
		else
		{
			if (tm->hour < abs(hours)) {
				_remove_day_to_date(tm);
				tm->hour = (24 - abs(hours)) + tm->hour;
			}
			else {
				tm->hour -= abs(hours);
			}

		}
	}
}

void _add_minutes(struct metter_datetime* tm, s16 minutes) {
	if (minutes != 0)
	{
		if (minutes > 0) {
			s16 delhours = minutes / 60;
			s16 remdel = minutes - (delhours * 60);
			if (delhours>0)
				_add_hours(tm, delhours);
			u16 check = tm->minute + abs(remdel);
			if (check > 59) {
				u16 delt = check - 60;

				_add_hours(tm, 1);
				tm->minute = delt;
			}
			else {
				tm->minute = check;
			}
		}
		else {
			s16 delhours = minutes / 60;
			s16 remdel = abs(minutes) - (abs(delhours) * 60);
			_add_hours(tm, delhours);
			if (remdel > 0) {
				if (tm->minute < remdel) {
					_remove_hour_to_date(tm);
					tm->minute = (60 - remdel) + tm->minute;
				}
				else {
					tm->minute -= remdel;
				}
			}
		}
	}
}


u32 _calendar_time_to_value(struct metter_datetime *time)
{
	/*u32 register_value;
	register_value = (time->year - 2000) << 22;
	register_value |= (time->month << 17);
	register_value |= (time->day << 12);
	register_value |= (time->hour << 6);
	register_value |= (time->minute << 0);
	return register_value;*/
	u32 value;
	__memset(&value, 0, sizeof(u32));
	value = time->year << 25;
	value |= (time->month << 21);
	value |= (time->day << 16);
	value |= (time->hour << 11);
	value |= (time->minute << 5);
	//value |= (time->veracity << 4);
	//value |= (time->reserved << 0);
	return value;
}

void _calendar_value_to_time(const u32 value, struct metter_datetime *time)
{
	/*time->year = ((register_value &  (0x3Ful << 22)) >> 22) + 2000;
	time->month = ((register_value & (0xFul << 17)) >> 17);
	time->day = ((register_value & (0x1Ful << 12)) >> 12);
	time->hour = ((register_value & (0x1Ful << 6)) >> 6);
	time->minute = ((register_value & (0x3Ful << 0)) >> 0);*/
	__memset(time, 0, SIZE_RECORD);
	time->year = (value &  (0x3Ful << 25)) >> 25;
	time->month = ((value & (0xFul << 21)) >> 21);
	time->day = ((value & (0x1Ful << 16)) >> 16);
	time->hour = ((value & (0x1Ful << 11)) >> 11);
	time->minute = ((value & (0x3Ful << 5)) >> 5);
}

