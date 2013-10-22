# gentoo 下生成和使用二进制包
    /etc/make.conf，添加 PKGDIR="/usr/portage/packages/"

# 安装包的同时生成二进制包
    emerge -avb <package_name>

# 利用生成的二进制包安装
    emerge -avk <package_name>
