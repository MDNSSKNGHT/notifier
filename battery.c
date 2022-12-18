#include <stdio.h>
#include <stdlib.h>

#define BATT "BAT1"
#define BATT_PATH "/sys/class/power_supply/%s/%s"

/* Is the battery present in the device? */

int batt_present() {
  char path[0xFF];
  char buff[0xFF];
  FILE *fd;

  if (snprintf(path, sizeof(path), BATT_PATH, BATT, "present") < 0)
    return -1;
  if ((fd = fopen(path, "r")) == NULL)
    return -1;
  if (fgets(buff, sizeof(buff), fd) == NULL)
    return -1;
  return atoi(buff);
}

/* Returns battery level (percent) as an integer or -1 if we got any error. */

int get_batt_level() {
  char buff[0xFF];
  char path[0xFF];
  FILE *fd;

  if (!batt_present())
    return -1;
  if (snprintf(path, sizeof(path), BATT_PATH, BATT, "capacity") < 0)
    return -1;
  if ((fd = fopen(path, "r")) == NULL)
    return -1;
  if (fgets(buff, sizeof(buff), fd) == NULL)
    return -1;
  return atoi(buff);
}
