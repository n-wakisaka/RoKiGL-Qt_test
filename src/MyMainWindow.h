/**
   @author Naoki Wakisaka
   Copyright (C) 2017 Naoki Wakisaka
*/
#ifndef __MY_MAIN_WINDOW_H__
#define __MY_MAIN_WINDOW_H__

#include <iostream>
#include <QMainWindow>
#include <QBoxLayout>
#include "MyGLWidget.h"

#include <roki/rk_chain.h>

class MyMainWindow : public QMainWindow
{
  Q_OBJECT
public:
  MyMainWindow(QWidget *parent = Q_NULLPTR);
  ~MyMainWindow();

public slots:
  void loadChain();

private:
  void createWindow();
  void createMenuToolBar();

  const int width = 640;
  const int height = 480;
  QWidget *central_widget;
  QVBoxLayout *central_layout;
  MyGLWidget *glwin;
};

#endif // __MY_MAIN_WINDOW_H__
