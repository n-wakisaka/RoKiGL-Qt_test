include(rokigl.pri)

TARGET = RoKiGL-Qt
DESTDIR = ../bin
RESOURCES =
QT += core gui opengl widgets
SOURCES += main.cpp MyApplication.cpp MyMainWindow.cpp MyGLWidget.cpp
HEADERS += MyApplication.h MyMainWindow.h MyGLWidget.h
