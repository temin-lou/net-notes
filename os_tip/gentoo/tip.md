# 选择编辑器
    eselect editor list

# 添加用户
    useradd -m -G users,wheel,audio -s /bin/bash tuser

# 绑定dev
    mount -o bind /dev /mnt/gentoo/dev

# cu命令
    uucp 在 gentoo 的taylor-uucp包里
    awk '{print $8}'  取出一列

# gentoo
    make CONFIG_BLK_DEV_NBD=m M=drivers/block
    cp drivers/block/nbd.ko /lib/modules/$(uname -r)/kernel/drivers/block/

# 去掉注释和空行
    grep -v "^#" keystone.conf.example | grep -v "^$" > keystone.conf
 
# 挂载macos文件系统，可读写
    mount -t hfsplus -o force,rw /dev/sdb1 /media/mac
