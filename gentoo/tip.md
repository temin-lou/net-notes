# 选择编辑器
    eselect editor list

# 添加用户
    useradd -m -G users,wheel,audio -s /bin/bash tuser

# 绑定dev
    mount -o bind /dev /mnt/gentoo/dev

# cu命令
    uucp 在 gentoo 的taylor-uucp包里

    awk '{print $8}'  取出一列
