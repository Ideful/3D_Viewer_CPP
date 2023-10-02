QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
greaterThan(QT_MAJOR_VERSION, 5): QT += openglwidgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    view/QtGifImage/dgif_lib.cpp \
    view/QtGifImage/egif_lib.cpp \
    view/QtGifImage/gif_err.cpp \
    view/QtGifImage/gif_font.cpp \
    view/QtGifImage/gif_hash.cpp \
    view/QtGifImage/gifalloc.cpp \
    view/QtGifImage/qgifimage.cpp \
    view/QtGifImage/quantize.cpp \
    main.cc \
    view/mainwindow.cc \
    view/myopenglwidget.cc \
    controller/controller.cc \
    model/model.cc \ 
    model/parser.cc \ 
    model/transformations.cc

HEADERS += \
    view/QtGifImage/gif_hash.h \
    view/QtGifImage/gif_lib.h \
    view/QtGifImage/gif_lib_private.h \
    view/QtGifImage/qgifglobal.h \
    view/QtGifImage/qgifimage.h \
    view/QtGifImage/qgifimage_p.h \
    view/mainwindow.h \
    view/myopenglwidget.h \ 
    controller/controller.h \
    model/model.h \ 
    model/parser.h \ 
    model/transformations.h

FORMS += \
    view/mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
