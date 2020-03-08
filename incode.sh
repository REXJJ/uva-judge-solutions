#!/bin/bash

file_name=$1
echo "Creating Files for $1"

mkdir $1
cd ./$1
cp ../sample_src.cpp ./src.cpp
cp ../sample.txt ./sample.txt
cp ../comp.sh ./comp.sh
cp ../exe.sh ./exe.sh
chmod +x ./*.sh

echo "Done...."
