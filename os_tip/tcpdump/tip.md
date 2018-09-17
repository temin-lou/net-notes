# 打印所有源或目的端口是80, 含有数据,而不是SYN,FIN以及ACK-only等不含数据的数据包.
    tcpdump 'tcp port 80 and (((ip[2:2] - ((ip[0]&0xf)<<2)) - ((tcp[12]&0xf0)>>2)) != 0)'

# 打印通过端口80的数据
    tcpdump tcp -i eth0 -w target.cap -t -s 0 -c 100 and dst port 80 
        (1)tcp: ip icmp arp rarp 和 tcp、udp、icmp这些选项等都要放到第一个参数的位置，用来过滤数据报的类型
        (2)-i eth1 : 只抓经过接口eth1的包
        (3)-t : 不显示时间戳
        (4)-s 0 : 抓取数据包时默认抓取长度为68字节。加上-S 0 后可以抓到完整的数据包
        (5)-c 100 : 只抓取100个数据包
        (6)dst port ! 22 : 不抓取目标端口是22的数据包
        (7)src net 192.168.1.0/24 : 数据包的源网络地址为192.168.1.0/24
        (8)-w ./target.cap : 保存成cap文件，方便用ethereal(即wireshark)分析
# 打印通过端口80的数据
    tcpdump -XvvennSs 0 -w target.cap -i eth0 tcp[20:2]=0x4745 or tcp[20:2]=0x4854
# tcpdump 读解
    src > dst 表明从源地址到目的地址
    flags TCP包中的标志信息：
       S SYN
       F FIN- P PUSH
       R RST
       . 没有标记
    data-seqno 数据包中的数据的顺序号
    ack 下次期望的顺序号
    window 接收缓存的窗口大小
    urgent 表明数据包中是否有紧急指针
    options是选项
# tcpdump 示例
    tcpdump tcp -n -i enp3s0 -t  and host 192.168.0.31 and port ! 22 -X

