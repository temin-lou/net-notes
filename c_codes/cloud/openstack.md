https://docs.openstack.org/developer/devstack/
http://www.chenshake.com/page/6/

＃Add Stack User

    $ sudo useradd -s /bin/bash -d /opt/stack -m stack
    $ echo "stack ALL=(ALL) NOPASSWD: ALL" | sudo tee /etc/sudoers.d/stack
    $ sudo su - stack
＃Download DevStack
     
    $ git clone https://git.openstack.org/openstack-dev/devstack
    $ git clone http://git.trystack.cn/openstack-dev/devstack.git
    $ cd devstack
＃Create a local.conf

    [[local|localrc]]
    ADMIN_PASSWORD=secret
    DATABASE_PASSWORD=$ADMIN_PASSWORD
    RABBIT_PASSWORD=$ADMIN_PASSWORD
    SERVICE_PASSWORD=$ADMIN_PASSWORD
    
    wget -O - https://raw.githubusercontent.com/shake/devstack/gh-pages/local.conf-sample-mitaka > ./local.conf
    mitaka-->newton
#Start the install

    ./stack.sh
