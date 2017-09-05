/**
   @author Naoki Wakisaka
   Copyright (C) 2017 Naoki Wakisaka
*/
#include <cstring>
#include "MyGLWidget.h"
#include "MyMainWindow.h"

MyGLWidget::MyGLWidget(QWidget *parent)
  : QOpenGLWidget(parent)
{
  rkChainInit( &chain );
  gc.chain = NULL;
}

MyGLWidget::~MyGLWidget()
{
  if( gc.chain != NULL ){
    rkglChainUnload( &gc );
  }
  rkChainDestroy( &chain );
}

bool MyGLWidget::loadChain(QString modelfile)
{
  if( gc.chain != NULL ){
    rkglChainUnload( &gc );
  }
  rkChainDestroy( &chain );
  if( !rkChainReadFile( &chain, (char*)modelfile.toStdString().c_str() ) ||
      !rkglChainLoad( &gc, &chain, &attr ) ){
    ZOPENERROR( (char*)modelfile.toStdString().c_str() );
    return false;
  }
  update();
  return true;
}

// protected
void MyGLWidget::initializeGL()
{
  zRGB rgb;

  initializeOpenGLFunctions();
  // opengl setting
  rkglEnableDefault();
  zRGBDec( &rgb, const_cast<char*>("#505050") );
  rkglBGSet( &cam, rgb.r, rgb.g, rgb.b );
  rkglCASet( &cam, 5.0, 0.0, 0.0, 0.0, 0.0, 0.0 );
  _setFrustum();

  glEnable( GL_LIGHTING );
  rkglLightCreate( &light, 0, 0.5, 0.5, 0.5, 0.8, 0.8, 0.8, 0, 0, 0, 0 );
  rkglLightSetPos( &light, 3.0, 0.0, 3.0 );

  rkglChainAttrInit( &attr );
}

void MyGLWidget::resizeGL(int w, int h)
{
  rkglVPCreate( &cam, 0, 0, w, h );
  _setFrustum();
}

void MyGLWidget::paintGL()
{
  rkglClear();
  rkglCALoad( &cam );
  rkglLightPut( &light );
  if( gc.chain != NULL ) rkglChainDraw( &gc );
  glFlush();
}

void MyGLWidget::mousePressEvent(QMouseEvent *event)
{
  mouse_pos = event->pos();
}

void MyGLWidget::mouseMoveEvent(QMouseEvent *event)
{
  double dx = (double)( event->pos().x() - mouse_pos.x() ) / cam.vp[3];
  double dy =-(double)( event->pos().y() - mouse_pos.y() ) / cam.vp[2];

  if( event->buttons() & Qt::LeftButton ){
    double r = 180 * sqrt( dx*dx + dy*dy );
    rkglCALockonRotate( &cam, r, -dy, dx, 0 );
    update();
  }else if( event->buttons() & Qt::RightButton ){
    rkglCARelMove( &cam, 0, dx, dy );
    update();
  }else if( event->buttons() & Qt::MiddleButton ){
    rkglCARelMove( &cam, -2*dy, 0, 0 );
    update();
  }

  mouse_pos = event->pos();
}

void MyGLWidget::wheelEvent(QWheelEvent *event)
{
  rkglCARelMove( &cam, -(double)event->delta()/1200, 0 ,0);
  update();
}

// private
void MyGLWidget::_setFrustum()
{
  double x, y;
  x = 0.1;
  y = x / rkglVPAspect(&cam);
  rkglFrustum( &cam, -x, x, -y, y, 1, 200 );
}
