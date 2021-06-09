#!/bin/bash

cd ./build
cmake .. -DCMAKE_BUILD_TYPE="Release"
make

cp test_lpd ..
