QT += network
CONFIG += jsonserializer

HEADERS += \
    KeyValue.h \
    Key.h \
    QStringEx.h \
    Question.h \
    User.h \
    Envelope.h \
    RequestFactory.h \
    Poller.h \
    EmailComposer.h \
    EmailClient.h \
    Email.h

SOURCES += \
    main.cpp \
    KeyValue.cpp \
    Key.cpp \
    QStringEx.cpp \
    Question.cpp \
    User.cpp \
    Envelope.cpp \
    RequestFactory.cpp \
    Poller.cpp \
    EmailComposer.cpp \
    EmailClient.cpp \
    Email.cpp

LIBS += -lGrantlee_Templates -lquickmail

DISTFILES += \
    template.html
