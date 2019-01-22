#-------------------------------------------------
#
# Project created by QtCreator 2018-12-20T18:33:28
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = UI-Designer
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        view/mainwindow/mainwindow.cpp \
    core/visual/scene.cpp \
    core/models/model.cpp \
    core/visual/htreeview.cpp \
    core/models/selectionmodel.cpp \
    core/lua/src/lapi.c \
    core/lua/src/lauxlib.c \
    core/lua/src/lbaselib.c \
    core/lua/src/lbitlib.c \
    core/lua/src/lcode.c \
    core/lua/src/lcorolib.c \
    core/lua/src/lctype.c \
    core/lua/src/ldblib.c \
    core/lua/src/ldebug.c \
    core/lua/src/ldo.c \
    core/lua/src/ldump.c \
    core/lua/src/lfunc.c \
    core/lua/src/lgc.c \
    core/lua/src/linit.c \
    core/lua/src/liolib.c \
    core/lua/src/llex.c \
    core/lua/src/lmathlib.c \
    core/lua/src/lmem.c \
    core/lua/src/loadlib.c \
    core/lua/src/lobject.c \
    core/lua/src/lopcodes.c \
    core/lua/src/loslib.c \
    core/lua/src/lparser.c \
    core/lua/src/lstate.c \
    core/lua/src/lstring.c \
    core/lua/src/lstrlib.c \
    core/lua/src/ltable.c \
    core/lua/src/ltablib.c \
    core/lua/src/ltm.c \
    core/lua/src/lua.c \
    core/lua/src/luac.c \
    core/lua/src/lundump.c \
    core/lua/src/lutf8lib.c \
    core/lua/src/lvm.c \
    core/lua/src/lzio.c \
    core/lua/luahandle.cpp \
    core/export/fileio.cpp \
    core/util/widgethelper.cpp \
    view/runscriptwizzard/runscriptwizard.cpp

HEADERS += \
        view/mainwindow/mainwindow.h \
    core/visual/scene.h \
    core/models/model.h \
    core/visual/htreeview.h \
    core/enums/enumerations.h \
    core/models/selectionmodel.h \
    core/lua/src/lapi.h \
    core/lua/src/lauxlib.h \
    core/lua/src/lcode.h \
    core/lua/src/lctype.h \
    core/lua/src/ldebug.h \
    core/lua/src/ldo.h \
    core/lua/src/lfunc.h \
    core/lua/src/lgc.h \
    core/lua/src/llex.h \
    core/lua/src/llimits.h \
    core/lua/src/lmem.h \
    core/lua/src/lobject.h \
    core/lua/src/lopcodes.h \
    core/lua/src/lparser.h \
    core/lua/src/lprefix.h \
    core/lua/src/lstate.h \
    core/lua/src/lstring.h \
    core/lua/src/ltable.h \
    core/lua/src/ltm.h \
    core/lua/src/lua.h \
    core/lua/src/lua.hpp \
    core/lua/src/luaconf.h \
    core/lua/src/lualib.h \
    core/lua/src/lundump.h \
    core/lua/src/lvm.h \
    core/lua/src/lzio.h \
    core/lua/luahandle.h \
    core/export/fileio.h \
    core/util/widgethelper.h \
    view/runscriptwizzard/runscriptwizard.h

FORMS += \
        view/mainwindow/mainwindow.ui \
    view/runscriptwizzard/runscriptwizard.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    core/visual/bla \
    Structure
