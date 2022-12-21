#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "battery.h"

#define POWER_SUPPLY_NAME "BAT1"
#define POWER_SUPPLY_PATH "/sys/class/power_supply/%s/%s"

char *power_supply_path(char *name, char *prop)
{
    char path[64];
    snprintf(path, sizeof(path), POWER_SUPPLY_PATH, name, prop);
    return strdup(path);
}

char *power_supply_read_prop(char *name, char *prop)
{
    char *path, buff[256];
    FILE *fd;

    path = power_supply_path(name, prop);
    if ((fd = fopen(path, "r")) == NULL)
        return NULL;
    if (fgets(buff, sizeof(buff), fd) == NULL)
        return NULL;
    free(path);
    fclose(fd);

    return strdup(buff);
}

struct power_supply_t *power_supply_init()
{
    return malloc(sizeof(struct power_supply_t));
}

void power_supply_update(struct power_supply_t *ref)
{
    char *buffer;
    char *remaining;

    /* no need to free here, we're already freeing the
     * memory address this reference points to in the
     * `power_supply_free` function. */
    buffer = power_supply_read_prop(POWER_SUPPLY_NAME, "status");
    ref->status = buffer;

    buffer = power_supply_read_prop(POWER_SUPPLY_NAME, "capacity");
    ref->capacity = strtol(buffer, &remaining, 0);
    free(buffer);
}

void power_supply_free(struct power_supply_t *ref)
{
    free(ref->status);
    free(ref);
}
