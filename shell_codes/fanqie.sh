#!/bin/sh

PATH=$PATH:~/bin
export PATH

yn="y"
while [ "$yn" == "y" -o "$yn" == "Y" ]
do
    echo "env DISPLAY=:0 feh ~/Pictures/xxx.gif" | at now+25 minutes
    echo "env DISPLAY=:0 feh ~/Pictures/xxx.gif" | at now+30 minutes

    sleep 30m
    read -p "Please input () to move on: " yn
done

atq | cut -s -f 1 | xargs atrm
echo "have a rest"
