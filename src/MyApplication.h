/**
   @author Naoki Wakisaka
   Copyright (C) 2017 Naoki Wakisaka
*/
#ifndef __MY_APPLICATION_H__
#define __MY_APPLICATION_H__

#include <iostream>
#include <QApplication>

#include "MyMainWindow.h"

class MyApplication : public QObject
{
  Q_OBJECT
public:
  MyApplication(int& argc, char**& argv);
  ~MyApplication();

  int exec();
private:
  QApplication *app;
  MyMainWindow *window;
};

#endif // __MY_APPLICATION_H__
