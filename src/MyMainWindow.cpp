/**
   @author Naoki Wakisaka
	 Copyright (C) 2017 Naoki Wakisaka
*/
#include <QFileDialog>
#include <QDir>
#include <QToolBar>
#include <QMenuBar>
#include "MyMainWindow.h"

MyMainWindow::MyMainWindow(QWidget *parent)
	: QMainWindow(parent)
{
  createWindow();
  createMenuToolBar();
}

MyMainWindow::~MyMainWindow()
{
}

void MyMainWindow::createWindow()
{
	setWindowTitle("RoKiGL-Qt");
  resize(width, height);

	central_widget = new QWidget(this);
	setCentralWidget(central_widget);

	glwin = new MyGLWidget(central_widget);
	glwin->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

	// layout
	central_layout = new QVBoxLayout(central_widget);
	central_layout->setContentsMargins(5, 5, 5, 0);
	central_layout->setSpacing(0);
	central_layout->addWidget(glwin);

	central_widget->setLayout(central_layout);
}

void MyMainWindow::createMenuToolBar()
{
  // toolbar
	QToolBar *tool = addToolBar("Tools");

	// exit action
	QAction *exit_action = new QAction("exit", this);
	exit_action->setShortcut(QKeySequence(Qt::Key_Q));
	tool->addAction(exit_action);
	connect(exit_action, &QAction::triggered, this, &MyMainWindow::close);

	// open action
  QAction *open_action = new QAction("open", this);
	open_action->setShortcut(QKeySequence(Qt::Key_O));
	tool->addAction(open_action);
  connect(open_action, &QAction::triggered, this, &MyMainWindow::loadChain);

	// menu
	QMenu *menu;
	menu = menuBar()->addMenu("&File");
  menu->addAction(open_action);
	menu->addSeparator();
	menu->addAction(exit_action);
}

void MyMainWindow::loadChain()
{
	QString modelfile  =
		QFileDialog::getOpenFileName(this, "Open Model File", QDir().dirName(), "Model Files (*.zkc);;All Files (*.*)");
	if( modelfile.isEmpty() ) return;
	glwin->loadChain(modelfile);
}
