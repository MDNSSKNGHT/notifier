/* Header file that declares and defines
 * functions related to the device battery. */
#ifndef NOTIFIER_BATTERY_H_
#define NOTIFIER_BATTERY_H_

struct power_supply_t {
    char *status;
    long capacity;
};

struct power_supply_t *power_supply_init();

void power_supply_update(struct power_supply_t *ref);

void power_supply_free(struct power_supply_t *ref);

#endif //NOTIFIER_BATTERY_H_
