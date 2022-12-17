/* Header file that prototypes X
 * functions.
 * No structure declaration here because we like
 * abstraction!
 */
#ifndef NOTIFIER_X_H
#define NOTIFIER_X_H

#include <X11/Xlib.h>

/* Connect to the display, set up the basic variables. */

void x_connect ();

/* Create the window. */

void create_window ();

/* Set up the GC (Graphics Context). */

void set_up_gc ();

/* Set up the text font. */

void set_up_font ();

/* Draw the window. */

void draw_screen ();

/* Loop over events. */

void event_loop ();

#endif //NOTIFIER_X_H
