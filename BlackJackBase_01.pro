QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Buttons/button.cpp \
    Buttons/controlbuttons.cpp \
    Buttons/playercontrols.cpp \
    Entity/dealer.cpp \
    Entity/player.cpp \
    Misc/statusimage.cpp \
    card.cpp \
    deck.cpp \
    gameboard.cpp \
    main.cpp

HEADERS += \
    Buttons/button.h \
    Buttons/controlbuttons.h \
    Buttons/playercontrols.h \
    Misc/statusimage.h \
    defines.h \
    Entity/dealer.h \
    Entity/player.h \
    card.h \
    deck.h \
    gameboard.h \

FORMS +=

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Resources.qrc
