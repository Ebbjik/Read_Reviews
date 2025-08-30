#!/bin/bash
set -e # 出错就退出

# 清理旧的构建目录
rm -rf build
mkdir build

# 生成 Makefile
/usr/bin/qmake

# 编译
make

# 运行
./build/Read_Reviews
