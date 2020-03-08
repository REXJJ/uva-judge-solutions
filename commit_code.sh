#!/bin/bash
message=$(date +'%m-%d-%Y %r')
git add .
git commit -m "$message"
git push origin master
