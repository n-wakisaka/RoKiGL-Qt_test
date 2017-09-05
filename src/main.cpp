#include <iostream>
#include <QSurfaceFormat>
#include "MyApplication.h"

void setDefaultFormat()
{
	QSurfaceFormat format;
	format.setDepthBufferSize(24);
	format.setStencilBufferSize(8);
	// format.setVersion(3, 2);
	format.setProfile(QSurfaceFormat::CoreProfile);
	QSurfaceFormat::setDefaultFormat(format);
}

int main(int argc, char **argv)
{
	MyApplication app(argc, argv);
	setDefaultFormat();

	int result = app.exec();
	return result;
}
