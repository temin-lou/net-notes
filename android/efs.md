# backup

    adb shell
    su
    ls -l /dev/block/platform/dw_mmc/by-name
    dd if=/dev/block/mmcblk0p3 of=/sdcard/efs.img
    (exit adb)
    adb pull /sdcard/efs.sbn

# restore

    adb push efs.sbn /sdcard/efs.img
    adb shell
    su
    dd if=/sdcard/efs.sbn of=/dev/block/mmcblk0p3
    reboot
