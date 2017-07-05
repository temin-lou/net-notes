# Linux下Android ADB驱动安装详解
    
    Linux下使用手机USB调试模式连接ADB进行Android程序的调试
    步骤
    1. 确认手机连接上电脑，lsusb查看下设备记录。
    $ lsusb
    Bus 001 Device 006: ID 04e8:6860 Samsung Electronics Co., Ltd GT-I9100 Phone [Galaxy S II], 
                        GT-I9300 Phone [Galaxy S III], GT-P7500 [Galaxy Tab 10.1]
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
    
＃ android 镜像使用帮助
 
    mkdir ~/bin
    PATH=~/bin:$PATH
    curl https://storage.googleapis.com/git-repo-downloads/repo > ~/bin/repo
    chmod a+x ~/bin/repo
    wget -c https://mirrors.tuna.tsinghua.edu.cn/aosp-monthly/aosp-latest.tar
    
# repo 使用帮助
    1：下载Android主线分支
         repo init -u https://android.googlesource.com/platform/manifest
    2：下载android其它分支
         repo init -u https://android.googlesource.com/platform/manifest -b android-4.0.1_r1
    3：查看android分支版本号
         git --git-dir .repo/manifests/.git/ branch -a
    4：查看android当前版本号
       在build/core/version_defaults.mk文件中查看PLATFORM_VERSION即可。
    5：切换android分支
       初始化repo客户端到某一分支(以android-4.0.3_r1为例)
          repo init -b android-4.0.3_r1
       可以在目录 .repo/manifest.xml中查看repo客户端是在哪个分支上。
       同步代码
          repo sync
    6：创建自己的本地分支
       构造本地分支
          repo start myandroid4.0.3 --all ，分支名称为myandroid4.0.3
       检出到自己创建的分支上
          repo checkout myandroid4.0.3 或
          repo checkout myandroid4.0.3 origin/android-4.0.3_r1
    7：下载android Linux kernel代码
       查看https://android.googlesource.com/
    8：如何获得指定版本的Linux内核
        在下载目录下执行：
         git checkout remotes/origin/android-2.6.29  
    9：查看repo可切换的分支
         cd .repo/manifests
         git branch -a | cut -d / -f 3
         
# android 编译
     source build/envsetup.sh
     lunch aosp_arm-eng
        BUILD NAME 	  DEVICE 	       NOTES
        aosp_arm 	  ARM emulator 	包括所有语言、APP和输入法的配置
        aosp_maguro   maguro 	    运行在Galaxy Nexus GSM/HSPA+ (“maguro”)上
        aosp_panda 	  panda 	    运行在 PandaBoard (“panda”)上
        
        BUILDTYPE 	  USE
        user 	      limited access; suited for production（有权限限制，适合产品级）
        userdebug     preferred for debugging（适合调试）
        eng 	      development configuration with additional debugging tools（有额外的调试工具）
     make -j4
     make into：out/target/product/generic
     驱动配置:
     a.balabala
     b.连接手机，打开USB调试，进入bootloader模式：
        adb reboot bootloader
        fastboot oem unlock
        fastboot flash boot boot.img
        fastboot flash system system.img
        fastboot flash userdata userdata.img
        
# android 编译步骤
    repo init -b android_5.1.1_r5
    repo sync
    source build/envsetup.sh
    lunch aosp_arm-eng
    make update-api
    make -j4
    
