QT       += core gui widgets multimedia sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    basemusicmodel.cpp \
    coverflowwi.cpp \
    global.cpp \
    httpmgr.cpp \
    likemusicwi.cpp \
    likewidelegate.cpp \
    listmusicitemwi.cpp \
    localfolderdialog.cpp \
    localwi.cpp \
    main.cpp \
    mainwidget.cpp \
    musicdbmanager.cpp \
    musicinfo.cpp \
    musicitemwi.cpp \
    musicmanager.cpp \
    musicplayerwi.cpp \
    playerworker.cpp \
    playlistmodel.cpp \
    playlistwi.cpp \
    recommendwi.cpp \
    recordwi.cpp \
    recordwi.cpp \
    searchrecomwi.cpp \
    searchwi.cpp \
    searchwidelegate.cpp \
    songlistcardwi.cpp \
    songlistwi.cpp \
    statepushbutton.cpp\
    volumetoolwi.cpp

HEADERS += \
  bannerinfo.h \
    basemusicmodel.h \
    coverflowwi.h \
    global.h \
    httpmgr.h \
    likemusicwi.h \
    likewidelegate.h \
    listmusicitemwi.h \
    localfolder.h \
    localfolderdialog.h \
    localwi.h \
    mainwidget.h \
    musicdbmanager.h \
    musicinfo.h \
    musicitemwi.h \
    musicmanager.h \
    musicplayerwi.h \
    playerworker.h \
    playlistmodel.h \
    playlistwi.h \
    progressbarwi.h \
    recommendwi.h \
    recordwi.h \
    searchrecomwi.h \
    searchwi.h \
    searchwidelegate.h \
    singleton.h \
    songlistcardwi.h \
    songlistwi.h \
    statepushbutton.h\
    volumetoolwi.h


FORMS += \
    likemusicwi.ui \
    listmusicitemwi.ui \
    localfolderdialog.ui \
    localwi.ui \
    mainwidget.ui \
    musicitemwi.ui \
    musicitemwi.ui \
    musicplayerwi.ui \
    playlistwi.ui \
    recommendwi.ui \
    searchwi.ui \
    songlistwi.ui \
    volumetoolwi.ui



# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc \


DISTFILES += \
    config.ini

