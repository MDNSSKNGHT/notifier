/* Header file that declares and defines
 * functions related to the device battery.
 */
#ifndef NOTIFIER_BATTERY_H
#define NOTIFIER_BATTERY_H

/* Is the battery present in the device? */

int batt_present();

/* Returns battery level (percent) as an integer or -1 if we got any error. */

int get_batt_level();

#endif //NOTIFIER_BATTERY_H
