/**
   @author Naoki Wakisaka
	 Copyright (C) 2017 Naoki Wakisaka
*/
#ifndef __MY_GLWIDGET_H__
#define __MY_GLWIDGET_H__

#include <iostream>
#include <vector>

#include <QOpenGLWidget>
#include <QOpenGLFunctions>

#include <QMouseEvent>
#include <QWheelEvent>
#include <QKeyEvent>

#include <roki/rokigl.h>

using namespace std;

class MyGLWidget : public QOpenGLWidget, protected QOpenGLFunctions
{
	Q_OBJECT
public:
	MyGLWidget(QWidget *parent = Q_NULLPTR);
	~MyGLWidget();

	bool loadChain(QString modelfile);

protected:
	void initializeGL() Q_DECL_OVERRIDE;
	void resizeGL(int w, int h) Q_DECL_OVERRIDE;
	void paintGL() Q_DECL_OVERRIDE;

  void mousePressEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
  void mouseMoveEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
  void wheelEvent(QWheelEvent *event) Q_DECL_OVERRIDE;

private:
	void _setFrustum();

	rkChain chain;
  rkglChain gc;

	rkglCamera cam;
  rkglLight light;
	rkglChainAttr attr;

	QPoint mouse_pos;
};

#endif // __MY_GLWIDGET_H__
