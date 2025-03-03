#ifndef BUTTONS_H
#define BUTTONS_H

/*Purpose
 *Buttons are fairly simple. They need to be set, and they need to be polled for their
 *current state, which will be an int.
 */

extern int buttonState;

void initiate_buttons();
namespace Buttons {
void poll();
}
#endif