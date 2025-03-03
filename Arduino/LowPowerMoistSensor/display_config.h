#ifndef DISPLAY_CONFIG_H
#define DISPLAY_CONFIG_H

/* Purpose:
 * This package handles the LCD display text specific for this 
 * project.
 */

//Variables
extern const unsigned long displayDelay;

//Functions
void initiate_display();
void update_display(const String& line1, const String& line2);
void welcome_to_grow();
namespace Display {
  void turn_on();
  void turn_off();
}
#endif