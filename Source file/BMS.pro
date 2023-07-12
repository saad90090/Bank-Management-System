QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    accountstatement.cpp \
    changepin.cpp \
    changepword.cpp \
    deposit.cpp \
    dialog.cpp \
    fundstransfer.cpp \
    hehe.cpp \
    hello.cpp \
    main.cpp \
    mainpage.cpp \
    options.cpp \
    withdrawl.cpp

HEADERS += \
    accountstatement.h \
    changepin.h \
    changepword.h \
    deposit.h \
    dialog.h \
    fundstransfer.h \
    hehe.h \
    hehehe.h \
    hello.h \
    mainpage.h \
    options.h \
    withdrawl.h

FORMS += \
    accountstatement.ui \
    changepin.ui \
    changepword.ui \
    deposit.ui \
    dialog.ui \
    fundstransfer.ui \
    mainpage.ui \
    options.ui \
    withdrawl.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
