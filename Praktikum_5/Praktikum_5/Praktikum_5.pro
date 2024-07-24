QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    airport.cpp \
    algorithmen.cpp \
    booking.cpp \
    buchungsdetails.cpp \
    check.cpp \
    configurationwindow.cpp \
    customer.cpp \
    customersearchdialog.cpp \
    flightbooking.cpp \
    hotelbooking.cpp \
    main.cpp \
    meldungen.cpp \
    rentalcarreservation.cpp \
    trainticket.cpp \
    travel.cpp \
    travelagency.cpp \
    travelagencyui.cpp

HEADERS += \
    airport.h \
    booking.h \
    buchungsdetails.h \
    check.h \
    configurationwindow.h \
    customer.h \
    customersearchdialog.h \
    digraph.h \
    flightbooking.h \
    hotelbooking.h \
    meldungen.h \
    rentalcarreservation.h \
    trainticket.h \
    travel.h \
    travelagency.h \
    travelagencyui.h

FORMS += \
    buchungsdetails.ui \
    configurationwindow.ui \
    customersearchdialog.ui \
    meldungen.ui \
    travelagencyui.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Ressource.qrc
