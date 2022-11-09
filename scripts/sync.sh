#! /bin/bash

rsync -drvtu --delete ./samples memento:~/memento-radio/
rsync -drvtu --delete ./cfg/radio.cfg memento:~/memento-radio/cfg/radio.cfg
