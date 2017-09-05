/**
   @author Naoki Wakisaka
   Copyright (C) 2017 Naoki Wakisaka
*/
#include "MyApplication.h"

MyApplication::MyApplication(int& argc, char**& argv)
{
  app = new QApplication(argc, argv);
  window = new MyMainWindow();
}

MyApplication::~MyApplication()
{
  delete window;
  delete app;
}

int MyApplication::exec()
{
  window->show();
  return app->exec();
}
