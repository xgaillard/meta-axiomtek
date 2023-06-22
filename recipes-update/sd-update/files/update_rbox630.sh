#!/bin/sh

UPDATE_PATH="/home/root/update"
# BACKUP_PATH="/home/root/backup"
KERNEL_PATH="/mnt/fat"
ROOTFS_PATH="/mnt/ext4"
BOOTLOADER_IMAGE="u-boot.imx"
KERNEL_IMAGE="zImage"
KERNEL_DTB="imx6dl-rbox630.dtb"
FILESYSTEM="imx-image-full-rbox630-6dl.tar.bz2"

dev=`ls /dev/mmcblk*boot*`; dev=($dev); dev=${dev[0]}; dev=${dev#/dev/mmcblk}; dev=${dev%boot*}; echo $dev > /tmp/mmcdev
mmc=`cat /tmp/mmcdev`

clear

while [ ! -e /dev/mmcblk*boot0 ]
do
	echo "Wait for mmcblk0 device appear."
	echo ""
	sleep 1
done

# clear MBR
dd if=/dev/zero of=/dev/mmcblk${mmc} bs=512 count=1 > /dev/null 2>&1
# create partition
PARTSTR=$'10M,500M,0c\n600M,,83\n'; echo "$PARTSTR" | sfdisk --force /dev/mmcblk${mmc} > /dev/null 2>&1
# clear u-boot arg
dd if=/dev/zero of=/dev/mmcblk${mmc} bs=1k seek=4096 conv=fsync count=8 > /dev/null 2>&1
sync

if [ -f "$UPDATE_PATH/$BOOTLOADER_IMAGE" ]; then
	echo "Installing U-boot bootloader image ..."
	echo ""

	echo 0 > /sys/block/mmcblk${mmc}boot0/force_ro
	dd if=$UPDATE_PATH/$BOOTLOADER_IMAGE of=/dev/mmcblk${mmc}boot0 bs=1k seek=1 conv=fsync > /dev/null 2>&1
	echo 1 > /sys/block/mmcblk${mmc}boot0/force_ro
	mmc bootpart enable 1 1 /dev/mmcblk${mmc}
fi

echo "Installing Kernel/DTB image ..."
echo ""

while [ ! -e /dev/mmcblk${mmc}p1 ]
do 
	echo "Wait for kernel partition appear."
	echo ""
	sleep 1
done

mkfs.vfat /dev/mmcblk${mmc}p1 > /dev/null 2>&1
mkdir -p $KERNEL_PATH
mount -t vfat /dev/mmcblk${mmc}p1 $KERNEL_PATH > /dev/null 2>&1
cp $UPDATE_PATH/$KERNEL_IMAGE $KERNEL_PATH
cp $UPDATE_PATH/$KERNEL_DTB $KERNEL_PATH
sync
umount $KERNEL_PATH

echo "Installing Rootfs image ..."
echo ""

while [ ! -e /dev/mmcblk${mmc}p2 ]
do
	echo "Wait for rootfs partition appear."
	echo ""
	sleep 1
done

mkfs.ext4 -F -E nodiscard /dev/mmcblk${mmc}p2 > /dev/null 2>&1
mkdir -p $ROOTFS_PATH
mount -t ext4 /dev/mmcblk${mmc}p2 $ROOTFS_PATH > /dev/null 2>&1
pv $UPDATE_PATH/$FILESYSTEM | tar -I pbzip2 -xm -C $ROOTFS_PATH

echo ""
echo "Synchronizing Rootfs image ..."
echo ""
sync

umount $ROOTFS_PATH

echo "Done"
echo ""
echo "Please disconnect power supply and remove the SD card."
read -s done

exit 0