# Linux下Android ADB驱动安装详解
Linux下使用手机USB调试模式连接ADB进行Android程序的调试

    步骤

1. 确认手机连接上电脑，lsusb查看下设备记录。

$ lsusb
Bus 001 Device 006: ID 04e8:6860 Samsung Electronics Co., Ltd GT-I9100 Phone [Galaxy S II], GT-I9300 Phone [Galaxy S III], GT-P7500 [Galaxy Tab 10.1]

2. 然后在/etc/udev/rules.d/下创建一个配置文件: 70-android.rules
文件里添加如下配置参数:

SUBSYSTEM=="usb", SYSFS{"High Tech Computer Corp."}=="04e8", MODE="0666"
/etc/init.d/udev restart

下载adt-bundle-linux-x86_64-20131030.zip包，其中包括eclipse和sdk，
通过指定sdk就可以开发android程序，下载android-ndk包可以用ndk开发。

# android 源代码下载

    mkdir ~/bin 
    //curl http://commondatastorage.googleapis.com/git-repo-downloads/repo > ~/bin/repo 
    curl https://dl-ssl.google.com/dl/googlesource/git-repo/repo
    chmod a+x ~/bin/repo
    export PATH=~/bin:$PATH
    mkdir ~/android
    cd ~/android
    repo init -u git://github.com/AOKP/platform_manifest.git -b jb-mr2
    repo sync

