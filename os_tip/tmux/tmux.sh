#!/bin/sh
#
# name : tmuxen, tmux environment made easy
# author : Xu Xiaodong <xxdlhy@gmail.com>
# license : GPL
# created : 2012 Jul 01
# modified : 2013 Jul 06
#

cmd=$(which tmux) # tmux path
session=$(hostname -s) # session name

if [ -z $cmd ]; then
    echo "You need to install tmux."
    exit 1
fi

$cmd has -t $session 2> /dev/null

if [ $? != 0 ]; then
    $cmd new -d -n vim -s $session "vim"
    $cmd neww -n mutt -t $session "mutt"
    $cmd neww -n bash1 -t $session "log"
    #$cmd neww -n bash2 -t $session "vim"
    $cmd neww -n bash3 -t $session "bash"
    $cmd splitw -h -p 50 -t $session "vim"
    $cmd selectw -t $session:1
fi

$cmd att -t $session

exit 0
