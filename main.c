/* Main file.
 * Just the entry point and no more.
 */
#include <unistd.h>

#include "x.h"
#include "battery.h"

int main (__attribute__((unused)) int argc, __attribute__((unused)) char ** argv)
{
    while (1) {
        if (get_batt_level() <= 5) {
            x_connect ();
            create_window ();
            set_up_gc ();
            set_up_font ();
            event_loop ();
            sleep (5);
            execl ("/usr/bin/zzz", "", NULL);
        }
    }

    return 0;
}
