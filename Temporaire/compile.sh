#!/bin/sh

mkdir build
cd build
cmake ..
make
mv Fuite_de_criminels ../Fuite_de_criminels
cd ..
rm -r build
