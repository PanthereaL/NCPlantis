#ifndef MOTORS_H
#define MOTORS_H

//Purpose: There are four pump motors connected currently. This is how
//we interface with them.

//Variables
extern int motorStates[4];

//Functions
void initiate_motors();
void evaluate_motors();

#endif