qemu-img snapshot -c tag1 disk
qemu-img convert -c -f qcow2 -t none -O qcow2 -s tag1 disk backupfile
qemu-img snapshot -d tag1 disk
