# github start 
Create a new repository on the command line

    touch README.md
    git init
    git add README.md
    git commit -m "first commit"
    git remote add origin git@github.com:louqh/net-notes.git
    git push -u origin master


# git server
Create git server

    On the server:
        SSH Keys 
        /etc/conf.d/git-daemon 
            GIT_USER="git"
            GIT_GROUP="git"
        /etc/init.d/git-daemon start
        cd /var/git/newproject.git
        git init --bare
    On the client:
        cd ~/newproject
        git init
        touch test
        git add test
        git commit -am"init commit"
        git remote add origin git@server.ip:newproject.git
        git push origin master

# git
        git checkout -- rm.file
