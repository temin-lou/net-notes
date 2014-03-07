# 打印所有源或目的端口是80, 含有数据,而不是SYN,FIN以及ACK-only等不含数据的数据包.
    tcpdump 'tcp port 80 and (((ip[2:2] - ((ip[0]&0xf)<<2)) - ((tcp[12]&0xf0)>>2)) != 0)'

# 打印通过端口80的数据
    tcpdump tcp -i eth0 -w target.cap -t -s 0 -c 100 and dst port 80 

# 打印通过端口80的数据
    tcpdump -XvvennSs 0 -w target.cap -i eth0 tcp[20:2]=0x4745 or tcp[20:2]=0x4854
