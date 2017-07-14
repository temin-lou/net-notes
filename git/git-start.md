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
        git checkout -b branch_name tag_name

# create a module for develop

        git checkout -b develop master
        git push --set-upstream origin develop
        git chechout -b myfeature develop
        balabala
        git chechout develop
        git merge --no-ff myfeature
        git branch -d myfeature
        git push origin develop

        create release branch
        git checkout -b release-1.2 develop
        balabala
        git commit -am "bumped version number to 1.2"
        git checkout master
        git merge --no-ff release-1.2
        git tag -a 1.2
        git checkout develop
        git merge --no-ff release-1.2
        git branch -d release-1.2

        git checkout -b hotfix-1.2.1 master
        balabala
        git commit -am "bumped version number to 1.2.1"
        git commit -m "Fixed server production problem"
        git checkout master
        git merge --no-ff hotfix-1.2.1
        git tag -a 1.2.1
        git checkout develop
        git merge --no-ff hotfix-1.2.1
        git branch -d hotfix-1.2.1

# github pull push 

        git clone http://github.com/louqh/net-notes.git
        git remote set-url origin git@github.com:louqh/net-notes.git
