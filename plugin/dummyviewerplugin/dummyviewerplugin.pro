# include global settings for all DLT Viewer Plugins
include( ../plugin.pri )

# Put intermediate files in the build directory
MOC_DIR     = build/moc
OBJECTS_DIR = build/obj
RCC_DIR     = build/rcc
UI_DIR      = build/ui

# target name
TARGET = $$qtLibraryTarget(dummyviewerplugin)

# plugin header files
HEADERS += \
    dummyviewerplugin.h \
    form.h

# plugin source files
SOURCES += \
    dummyviewerplugin.cpp \
    form.cpp

# plugin forms
FORMS += \
    form.ui
