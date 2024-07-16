QT       += core gui
QT       += network
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# INCLUDEPATH += C:\msys64\mingw64\include
# LIBS += -LC:\msys64\mingw64\lib -lqca



# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Myclient.cpp \
    main.cpp \
    mainwindow.cpp \
    qaesencryption.cpp

HEADERS += \
    Myclient.h \
    mainwindow.h \
    qaesencryption.h \
    aesni/aesni-key-exp.h \
    aesni/aesni-enc-ecb.h \
    aesni/aesni-enc-cbc.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    images.qrc
