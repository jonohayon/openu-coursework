/*
 * time.c
 *
 * This file holds the implementations of the prototypes defined in time.h, where also the documentation is held.
 */

#include "time.h"

int isBefore (time date1, time date2) {
  int isYearBefore = date1.year < date2.year;
  int isMonthBefore = date1.month < date2.month;
  int isDayBefore = date1.day < date2.day;
  int isHourBefore = date1.hour < date2.hour;
  int isMinuteBefore = date1.minute < date2.minute;
  int isSecBefore = date1.sec < date2.sec;

  return isYearBefore
    || isMonthBefore
    || isDayBefore
    || isHourBefore
    || isMinuteBefore
    || isSecBefore;
}

int secsInMonth (Month month) {
  switch (month) {
    case FEB:
      return SECS_IN_FEBRUARY;
    case APR:
    case JUN:
    case SEP:
    case NOV:
      return SECS_IN_MONTH_30;
    default: /* JAN, MAR, MAY, JUL, AUG, OCT, DEC */
      return SECS_IN_MONTH_31;
  }
}

int monthDiff (Month month1, Month month2) {
  int i, m1 = (int) month1, m2 = (int) month2, diff = 0;

  /*
   * If month2 is earlier than month1, swap them
   */
  if (m2 < m1) {
    m1 ^= m2;
    m2 ^= m1;
    m1 ^= m2;
  }

  /*
   * Since each month has a different number of days in it, an iterative
   * approach had to be taken. This algorithm utilizes the fact that each
   * enum value has an integer assigned to it (starting from 0). The loop
   * iterates between m1, the earlier date, and m2. Since m1 is earlier than
   * m2, its integer value is also less than it. The difference is incremented
   * by the number of seconds in each month between m1 and m2 during the loop.
   */
  for (i = m1; i < m2; i++) {
    diff += secsInMonth((Month) i);
  }

  return diff;
}

unsigned int time_diff (time date1, time date2) {
  int yearDiff = (date1.year - date2.year) * SECS_IN_YEAR;
  int dayDiff = (date1.day - date2.day) * SECS_IN_DAY;
  int hourDiff = (date1.hour - date2.hour) * SECS_IN_HOUR;
  int minDiff = (date1.minute - date2.minute) * 60; /* Each minute has 60 seconds in it */
  int secDiff = date1.sec - date2.sec;

  int sum = yearDiff + monthDiff(date1.month, date2.month) + dayDiff + hourDiff + minDiff + secDiff;

  return isBefore(date1, date2) ? -sum : sum;
}
