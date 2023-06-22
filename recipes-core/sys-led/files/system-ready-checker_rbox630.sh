#!/bin/sh

echo "System Ready" | tee /dev/kmsg

# Enable CPLD system status LED
i2cset -y 1 0x77 0x4e 0x01
tmp=$(i2cget -y 1 0x77 0x51)
tmp=$(($tmp | 0x01))
i2cset -y 1 0x77 0x51 $tmp

exit 0
