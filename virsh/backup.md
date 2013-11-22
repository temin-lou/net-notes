＃创建不停机快照过程
  本过程建立backupfile备份文件并且压缩系统大小
    qemu-img snapshot -c tag1 disk
    qemu-img convert -c -f qcow2 -t none -O qcow2 -s tag1 disk backupfile
    qemu-img snapshot -d tag1 disk
