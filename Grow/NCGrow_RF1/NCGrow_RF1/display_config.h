#ifndef DISPLAY_CONFIG_H
#define DISPLAY_CONFIG_H

/* Purpose:
 * This package handles the LCD display text specific for this 
 * project.
 */

//Variables

//Functions
void initiate_display();
void update_display(const String& line1, const String& line2);
void welcome_to_grow();
#endif