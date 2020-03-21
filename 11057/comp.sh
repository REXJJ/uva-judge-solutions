#!/bin/bash

if [ $# -eq 0 ];then
g++ -std=c++11 -O3 ./src.cpp
else
g++ -std=c++11 -O3 ./src.cpp -DDBG
fi
