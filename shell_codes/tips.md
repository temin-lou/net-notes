# 修改默认目录名
    $ export LANG=en_US
    $ xdg-user-dirs-gtk-update
# 重定向输出到文件
    program [arguments...] 2>&1 | tee outfile
# 转码加tail
    tail -f sm_vox_20190122.log | while read LINE ; do echo $LINE | iconv -f gb2312 -t UTF-8 ; done
