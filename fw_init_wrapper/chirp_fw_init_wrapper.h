#include <stdint.h>
#include <soniclib.h>

uint8_t ch_zephyr_fw_init(ch_dev_t *dev_ptr, ch_group_t *grp_ptr,
                          uint8_t i2c_addr, uint8_t dev_num,
                          uint8_t i2c_bus_index);
