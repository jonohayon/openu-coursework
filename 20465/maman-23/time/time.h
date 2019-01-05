/*
 * time.h
 *
 * This file holds the structures, enumerations and function prototypes of the functions defined in time.c
 */

#ifndef time_h /* Include time.h only once */
#define time_h

#define SECS_IN_YEAR 31536000 /* 365*24*60*60 */
#define SECS_IN_MONTH_30 2592000 /* For 30 days months */
#define SECS_IN_MONTH_31 2678400 /* For 31 days months */
#define SECS_IN_FEBRUARY 2419200 /* For 28 days months (February) */
#define SECS_IN_DAY 86400 /* 24*60*60 */
#define SECS_IN_HOUR 3600 /* 60*60 */

/**
 * An enumeration of the months of the year.
 */
typedef enum {
  JAN, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC
} Month;

/**
 * Calculates the number of seconds in a month. This is required
 * since there are a bunch of months that have 30 days in them and
 * because February has 28 days in it.
 * @param month The month to calculate the number of seconds in
 * @returns The number of seconds in the given month (days * 24 * 60 * 60)
 */
int secsInMonth (Month month);

/**
 * Calculates the difference in seconds between two given months. Since each
 * month has a different number of days in it, the difference between months
 * isn't (month2 * days2 - month1 * days1) * SECS_IN_DAY, since for example
 * if month2 == MAY and month1 == JAN, then February is between them and that
 * will make the calculations incorrect. Therefore, an iterative approach is
 * taken (documented inside the function). The order of the months (which one
 * is earlier) doesn't matter, since it is checked inside the function.
 * @param month1 The 1st month
 * @param month2 The 2nd month
 * @returns The difference between month1 and month2, in seconds
 */
int monthDiff (Month month1, Month month2);

/**
 * A time structure.
 */
typedef struct {
  signed int year; /* Adding support to B.C. */
  Month month;
  unsigned int day;

  unsigned int hour;
  unsigned int minute;
  unsigned int sec;
} time;

/**
 * Checks whether a certain date is before another date.
 * @param date1 The 1st date
 * @param date2 The 2nd date
 * @returns 1 if date1 is before date2, 0 otherwise
 */
int isBefore (time date1, time date2);

/**
 * Calculates the time difference between two given dates. Uses the
 * {@link #monthDiff(time, time)} function.
 * @param date1 The 1st date
 * @param date2 The 2nd date
 * @returns The difference between date1 and date2, in seconds
 */
unsigned int time_diff (time date1, time date2);

#endif
