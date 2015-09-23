# 测试openflow 
    sudo apt-get install autoconf automake libtool libsnmp-dev libpcap-dev
    git clone git://gitosis.stanford.edu/oflops.git
    cd oflops; git submodule init && git submodule update
    git clone git://gitosis.stanford.edu/openflow.git
    cd openflow; git checkout -b release/1.0.0 remotes/origin/release/1.0.0
    wget http://hyperrealm.com/libconfig/libconfig-1.4.9.tar.gz
    tar -xvzf libcon fig-1.4.9.tar.gz
    cd libconfig-1.4.9
    ./con figure
    sudo make && sudo make install
    cd ../../netfpga-packet-generator-c-library/
    sudo ./autogen.sh && sudo ./confi gure && sudo make
    cd ..
    sh ./boot.sh ; ./configure --with-openflow-src-dir=<absolute path to openflow branch>; make
    sudo make install
    cd cbench$ sudo apt-get install autoconf automake libtool libsnmp-dev libpcap-dev
    git clone git://gitosis.stanford.edu/oflops.git
    cd oflops; git submodule init && git submodule update
    git clone git://gitosis.stanford.edu/openflow.git
    cd openflow; git checkout -b release/1.0.0 remotes/origin/release/1.0.0
    wget http://hyperrealm.com/libconfig/libconfig-1.4.9.tar.gz
    tar -xvzf libcon fig-1.4.9.tar.gz fig-1.4.9.tar.gz
    cd libconfig-1.4.9
    ./con figure figure
    sudo make && sudo make install
    cd ../../netfpga-packet-generator-c-library/
    sudo ./autogen.sh && sudo ./confi gure && sudo make gure && sudo make
    cd ..
    sh ./boot.sh ; ./configure --with-openflow-src-dir=<absolute path to openflow branch>; make
    sudo make install
    cd cbench
 

# 相关开源项目
    https://github.com/openmul/openmul.git
    git://gitosis.stanford.edu/openflow.git
    git clone git://gitosis.stanford.edu/oflops.git
    https://github.com/opendaylight/controller/tree/master
    https://github.com/openvswitch/ovs/
# 十大开源资源
    http://www.sdnlab.com/8091.html
