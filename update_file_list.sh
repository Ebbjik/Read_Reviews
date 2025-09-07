#!/bin/bash
set -e  # 出错就退出

# 确保目录存在
mkdir -p ./pris

# 生成 cpp 文件列表
find src -name "*.cpp" | sed 's|^|SOURCES += |' > ./pris/sources.pri

# 生成 h 文件列表
find src -name "*.h" | sed 's|^|HEADERS += |' > ./pris/headers.pri

echo "File lists updated!"
