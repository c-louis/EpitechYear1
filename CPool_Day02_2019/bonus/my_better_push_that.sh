#!/bin/bash
git add .
[ -z $1 ] && echo "Commit Reason ?" && read message && git commit -m "$message" || git commit -m $1
git push origin master
