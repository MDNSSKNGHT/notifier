/* Main file.
 * Just the entry point and no more. */
#include <unistd.h>

#include "x.h"
#include "battery.h"

int main (__attribute__((unused)) int argc, __attribute__((unused)) char ** argv)
{
    struct power_supply_t *battery = NULL;

    battery = power_supply_init();

    while (1) {
        power_supply_update(battery);
        if (battery->capacity <= 5) {
            x_connect();
            create_window();
            set_up_gc();
            set_up_font();
            if (event_loop())
                break;
        }
    }

    power_supply_free(battery);
    sleep(5);
    execl("/usr/bin/zzz", "", NULL);

    return 0;
}
