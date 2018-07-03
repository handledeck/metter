#include "global.h"
#ifndef __CALENDAR_H__
#define __CALENDAR_H__


bool get_date_time_from_str(u8* mdm_str, struct metter_datetime* time);
bool calendar_is_date_valid(struct metter_datetime *date);
bool _leapyear(u16 year);
void _add_month_to_date(struct metter_datetime *date);
void _remove_month_to_date(struct metter_datetime *date);
void _add_day_to_date(struct metter_datetime *date);
void _remove_day_to_date(struct metter_datetime *date);
void _add_hour_to_date(struct metter_datetime *date);
void _remove_hour_to_date(struct metter_datetime *date);
void _add_minute_to_date(struct metter_datetime *date);
void _remove_minute_to_date(struct metter_datetime *date);
void _add_hours(struct metter_datetime* tm, s16 hours);
void _add_minutes(struct metter_datetime* tm, s16 minutes);
u32 _calendar_time_to_value(struct metter_datetime *time);
void _calendar_value_to_time(const u32 register_value, struct metter_datetime *time);
#endif /* __CALENDAR_H__ */
