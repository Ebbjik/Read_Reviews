TEMPLATE = app
CONFIG += console c++17
QT += widgets

# 自动包含 src 目录下的所有 cpp/h 文件
SOURCES += $$files(src/*.cpp)
HEADERS += $$files(src/*.h)

# 设置构建输出目录
DESTDIR = build        # 可执行文件放到 build/
OBJECTS_DIR = build/obj
MOC_DIR = build/moc
RCC_DIR = build/rcc
UI_DIR = build/ui


RESOURCES += resources.qrc