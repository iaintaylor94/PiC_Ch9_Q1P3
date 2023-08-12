// program to determine tomorrows date

#include <stdio.h>
#include <stdbool.h>

// Define Structs
struct date {
int month;
int day;
int year;
};

// Declare Functions
bool isLeapYear (struct date);
int numberOfDays (struct date);

int main(void) {

  // Declare Structs
  struct date today, tomorrow;

  // Get input
  printf ("Enter todays date (mm dd yyyy): ");
  scanf ("%d %d %d", &today.month, &today.day, &today.year);

  // Determine tomorrows date
  if (today.day != numberOfDays (today)) {
    tomorrow.day = today.day + 1;
    tomorrow.month = today.month;
    tomorrow. year = today.year;
  }
  else if (today.month == 12) { // End of year
    tomorrow.day = 1;
    tomorrow.month = 1;
    tomorrow.year = today.year + 1;
  }
  else {
    tomorrow.day = 1;
    tomorrow.month = today.month + 1;
    tomorrow.year = today.year;
  }

  // Print tomorrows date
  printf ("Tomorrows date is %d/%d/%.2d", tomorrow.month, tomorrow.day, tomorrow.year % 100);
  
  return 0;
}

// Define Functions
bool isLeapYear (struct date d) {
  bool leapYearFlag;

  if ((d.year % 4 == 0 && d.year % 100 != 0) || d.year % 400 == 0)
    leapYearFlag = true; // It is a leap year
  else
    leapYearFlag = false; // it is not a leap year

  return leapYearFlag;
}

int numberOfDays (struct date d) {
  int days;
  
  const int daysPerMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

  if (isLeapYear (d) == true && d.month == 2) {
    days = 29;
  }
  else {
    days = daysPerMonth[d.month -1];
  }

  return days;
}