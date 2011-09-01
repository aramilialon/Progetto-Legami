HEADERS += lib/username.h \
    lib/experience.h \
    lib/message.h \
    lib/account.h \
    lib/legami.h \
    lib/useraccount.h \
    lib/userinfo.h \
    lib/loader.h \
    lib/error.h \
    lib/companyaccount.h \
    lib/companyinfo.h \
    lib/group.h \
    lib/photo.h \
	lib/payment.h \
    gui/legamimainwindow.h \
    gui/legamilogin.h \
	gui/reguser.h \
	gui/showuserprofile.h \
    gui/showuserinfo.h \
    gui/showusern.h \
    gui/showcompanyprofile.h \
    gui/showcompanyinfo.h \
    gui/modifyuserprofile.h \
    gui/showuserexperieces.h \
    gui/showuserexperience.h \
    gui/modifyusern.h

SOURCES += lib/username.cpp \
    lib/experience.cpp \
    lib/message.cpp \
    lib/account.cpp \
    lib/legami.cpp \
    lib/useraccount.cpp \
    lib/userinfo.cpp \
    lib/loader.cpp \
    lib/companyaccount.cpp \
    lib/companyinfo.cpp \
    lib/group.cpp \
	lib/payment.cpp \
	lib/photo.cpp \
    main.cpp \
    gui/legamimainwindow.cpp \
	gui/legamilogin.cpp \
	gui/reguser.cpp \
	gui/showuserprofile.cpp \
    gui/showuserinfo.cpp \
    gui/showusern.cpp \
    gui/showcompanyprofile.cpp \
    gui/showcompanyinfo.cpp \
    gui/modifyuserprofile.cpp \
    gui/showuserexperieces.cpp \
    gui/showuserexperience.cpp \
    gui/modifyusern.cpp

QT += xml
FORMS +=   
TRANSLATIONS += translation/legami_ita.ts \
    translation/legami_eng.ts


