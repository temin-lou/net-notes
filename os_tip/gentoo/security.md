# 添加超级用户组 
    sudo addgroup admin
    sudo adduser  super
    sudo usermod -a -G admin super
# 添加用户
    useradd -m -G users,wheel,audio -s /bin/bash tuser
# 添加证书验证
    authorized_keys
# sshd_config
    PermitRootLogin no
    PermitEmptyPasswords no
    PasswordAuthentication no
    AllowUsers super
# 更新服务器
    sudo apt-get update
    sudo apt-get upgrade
# 安装防火墙
    mkdir /etc/iptables
    *filter
    :INPUT DROP [0:0]
    :FORWARD DROP [0:0]
    :OUTPUT DROP [0:0]
     
    # Accept any related or established connections
    -I INPUT  1 -m state --state RELATED,ESTABLISHED -j ACCEPT
    -I OUTPUT 1 -m state --state RELATED,ESTABLISHED -j ACCEPT
     
    # Allow all traffic on the loopback interface
    -A INPUT  -i lo -j ACCEPT
    -A OUTPUT -o lo -j ACCEPT
     
    # Allow outbound DHCP request - Some hosts (Linode) automatically assign the primary IP
    #-A OUTPUT -p udp --dport 67:68 --sport 67:68 -j ACCEPT
     
    # Outbound DNS lookups
    -A OUTPUT -o eth0 -p udp -m udp --dport 53 -j ACCEPT
     
    # Outbound PING requests
    -A OUTPUT -p icmp -j ACCEPT
     
    # Outbound Network Time Protocol (NTP) request
    -A OUTPUT -p udp --dport 123 --sport 123 -j ACCEPT
     
    # SSH
    -A INPUT  -i eth0 -p tcp -m tcp --dport 22 -m state --state NEW -j ACCEPT
     
    # Outbound HTTP
    -A OUTPUT -o eth0 -p tcp -m tcp --dport 80 -m state --state NEW -j ACCEPT
    -A OUTPUT -o eth0 -p tcp -m tcp --dport 443 -m state --state NEW -j ACCEPT
     
    COMMIT
    
    iptables-apply /etc/iptables/rules

    vim /etc/network/if-pre-up.d/iptables
    #!/bin/sh
    iptables-restore < /etc/iptables/rules



# 安装Fall2ban
    cp /etc/fail2ban/jail.{conf,local}
    vi /etc/fail2ban/jail.local
     [DEFAULT]
      
     # "ignoreip" can be an IP address, a CIDR mask or a DNS host
     ignoreip = 127.0.0.1/8
     bantime  = 600
     maxretry = 3
      
     # "backend" specifies the backend used to get files modification. Available
     # options are "gamin", "polling" and "auto".
     # yoh: For some reason Debian shipped python-gamin did not work as expected
     #      This issue left ToDo, so polling is default backend for now
     backend = auto
      
     # Destination email address used solely for the interpolations in
     # jail.{conf,local} configuration files.
     destemail = root@localhost,fail2ban@blocklist.de

     vi /etc/fail2ban/jail.local
        action = %(action_mwl)s
        [ssh]
        enabled  = true
        port     = ssh
        filter   = sshd
        logpath  = /var/log/auth.log
        maxretry = 6
        [ssh-ddos]
        enabled  = true
        port     = ssh
        filter   = sshd-ddos
        logpath  = /var/log/auth.log
        maxretry = 6


https://news.ycombinator.com/item?id=6384603
