/* Main file.
 * Just the entry point and no more.
 */
#include "x.h"

int main (__attribute__((unused)) int argc, __attribute__((unused)) char ** argv)
{
    x_connect ();
    create_window ();
    set_up_gc ();
    set_up_font ();
    event_loop ();
    return 0;
}
