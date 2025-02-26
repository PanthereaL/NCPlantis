#ifndef RESET_H
#define RESET_H

/* Purpose: This function ensures that the Arduino unit is
 * automatically reset every 24 hours (12:00am). This helps
 * prevent memory leaks, maintaining system stability and
 * resolving any faults that could have ocurred during the day.
 * With a daily reset we ensure that the system starts in a 
 * "clean" state, improving long term performance and reliability.
 */

//Variables

//Functions
void setup_reset();
void reset_arduino();
void check_reset();

#endif