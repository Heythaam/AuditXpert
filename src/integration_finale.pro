QT       += core gui sql network charts printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    STMP/src/emailaddress.cpp \
    STMP/src/mimeattachment.cpp \
    STMP/src/mimecontentformatter.cpp \
    STMP/src/mimefile.cpp \
    STMP/src/mimehtml.cpp \
    STMP/src/mimeinlinefile.cpp \
    STMP/src/mimemessage.cpp \
    STMP/src/mimemultipart.cpp \
    STMP/src/mimepart.cpp \
    STMP/src/mimetext.cpp \
    STMP/src/quotedprintable.cpp \
    add_amendes.cpp \
    add_client.cpp \
    add_employes.cpp \
    add_normes.cpp \
    add_produits.cpp \
    amendes.cpp \
    calendrier.cpp \
    chatbot.cpp \
    client.cpp \
    connection.cpp \
    employer.cpp \
    insert_image.cpp \
    mail_amendes.cpp \
    main.cpp \
    mainwindow.cpp \
    modify_amendes.cpp \
    modify_clients.cpp \
    modify_employes.cpp \
    modify_normes.cpp \
    modify_produits.cpp \
    normes.cpp \
    notifications.cpp \
    product.cpp \
    qr_code.cpp \
    qrcode.cpp \
    smtp.cpp \
    stats.cpp \
    stats_amendes.cpp \
    stats_clients.cpp \
    stats_normes.cpp \
    stats_produits.cpp

HEADERS += \
    STMP/src/SmtpMime \
    STMP/src/emailaddress.h \
    STMP/src/mimeattachment.h \
    STMP/src/mimecontentformatter.h \
    STMP/src/mimefile.h \
    STMP/src/mimehtml.h \
    STMP/src/mimeinlinefile.h \
    STMP/src/mimemessage.h \
    STMP/src/mimemultipart.h \
    STMP/src/mimepart.h \
    STMP/src/mimetext.h \
    STMP/src/quotedprintable.h \
    STMP/src/smtpexports.h \
    add_amendes.h \
    add_client.h \
    add_employes.h \
    add_normes.h \
    add_produits.h \
    amendes.h \
    calendrier.h \
    chatbot.h \
    client.h \
    connection.h \
    employer.h \
    insert_image.h \
    mail_amendes.h \
    mainwindow.h \
    modify_amendes.h \
    modify_clients.h \
    modify_employes.h \
    modify_normes.h \
    modify_produits.h \
    normes.h \
    notifications.h \
    numberformatdelegate.h \
    product.h \
    qr_code.h \
    qrcode.h \
    smtp.h \
    stats.h \
    stats_amendes.h \
    stats_clients.h \
    stats_normes.h \
    stats_produits.h

FORMS += \
    add_amendes.ui \
    add_client.ui \
    add_employes.ui \
    add_normes.ui \
    add_produits.ui \
    calendrier.ui \
    chatbot.ui \
    chatdialog.ui \
    insert_image.ui \
    mail_amendes.ui \
    mainwindow.ui \
    modify_amendes.ui \
    modify_clients.ui \
    modify_employes.ui \
    modify_normes.ui \
    modify_produits.ui \
    qr_code.ui \
    stats.ui \
    stats_amendes.ui \
    stats_clients.ui \
    stats_normes.ui \
    stats_produits.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    ressources.qrc \
    roussource.qrc

DISTFILES += \
    STMP/LICENSE \
    STMP/README.md \
    icon_valide.png \
    notification.jpg
