# 选择编辑器
    eselect editor list

# 添加用户
    useradd -m -G users,wheel,audio -s /bin/bash tuser

# 帮定dev
    mount -o bind /dev /mnt/gentoo/dev
