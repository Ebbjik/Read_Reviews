TEMPLATE = app
CONFIG += console c++17
QT += widgets

include(./pris/sources.pri)
include(./pris/headers.pri)

# 设置构建输出目录
DESTDIR = build        # 可执行文件放到 build/
OBJECTS_DIR = build/obj
MOC_DIR = build/moc
RCC_DIR = build/rcc
UI_DIR = build/ui


RESOURCES += resources.qrc