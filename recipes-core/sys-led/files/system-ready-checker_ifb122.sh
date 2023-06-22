#!/bin/sh

echo "System Ready" | tee /dev/kmsg

# Enable system status LED

echo default-on > /sys/class/leds/sys_status/trigger

exit 0
