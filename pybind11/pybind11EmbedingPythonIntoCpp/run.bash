#!/bin/bash

apt update
apt install python3 python3-venv python3-dev g++ cmake git gdb
python3 -m venv myenv
source myenv/bin/activate
pip install pandas pybind11
git clone https://github.com/pybind/pybind11.git
mkdir build
cd build
cmake ..
make
gdb ./test