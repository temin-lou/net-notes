https://docs.openstack.org/developer/devstack/

＃Add Stack User

    $ sudo useradd -s /bin/bash -d /opt/stack -m stack
    $ echo "stack ALL=(ALL) NOPASSWD: ALL" | sudo tee /etc/sudoers.d/stack
    $ sudo su - stack
＃Download DevStack
     
    $ git clone https://git.openstack.org/openstack-dev/devstack
    $ cd devstack
＃Create a local.conf

    [[local|localrc]]
    ADMIN_PASSWORD=secret
    DATABASE_PASSWORD=$ADMIN_PASSWORD
    RABBIT_PASSWORD=$ADMIN_PASSWORD
    SERVICE_PASSWORD=$ADMIN_PASSWORD
#Start the install

    ./stack.sh
