TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

HEADERS += \
    geometry/forms/square.h \
    geometry/forms/rectangle.h \
    geometry/forms/point.h \
    geometry/forms/circle.h \
    geometry/forms/basicshape.h \
    app/app.h \
    app/appstate.h \
    app/color.h \
    app/tool.h \
    view/scene.h

SOURCES += \
        main.cpp \
    app/app.cpp \
    app/appstate.cpp \
    geometry/forms/basicshape.cpp \
    geometry/forms/circle.cpp \
    geometry/forms/point.cpp \
    geometry/forms/rectangle.cpp \
    geometry/forms/square.cpp \
    view/scene.cpp
