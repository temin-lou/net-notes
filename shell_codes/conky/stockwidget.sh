#!/bin/bash
URL="http://hq.sinajs.cn/list=s_sh000001,s_sh600795,s_sh601600,s_sh600640,s_sz399001,s_sz000001,s_sz000666"

curl -s --connect-timeout 30 $URL | iconv -f gb2312 -t utf-8 |  awk -F\" '{ print $2 }'  | awk 'BEGIN { FS="," } \
{ if (NF==6) { printf("%1.4s\t %7.2f\t %7.2f %7.2f%%\n", $1, $2, $3, $4)}}'
