# Linux下Android ADB驱动安装详解
Linux下使用手机USB调试模式连接ADB进行Android程序的调试

    步骤

1. 确认手机连接上电脑，lsusb查看下设备记录。

$ lsusb
Bus 001 Device 006: ID 04e8:6860 Samsung Electronics Co., Ltd GT-I9100 Phone [Galaxy S II], GT-I9300 Phone [Galaxy S III], GT-P7500 [Galaxy Tab 10.1]

然后在/etc/udev/rules.d/下创建一个配置文件: 70-android.rules
文件里添加如下配置参数:

SUBSYSTEM=="usb", SYSFS{"High Tech Computer Corp."}=="0bb4", MODE="0666"
/etc/init.d/udev restart
    
