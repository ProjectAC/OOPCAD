#include "stdafx.h"
#include "my_qopenglwidget.h"

my_QOpenGLWidget::my_QOpenGLWidget(QWidget *parent)
	: QOpenGLWidget(parent)
{
	QSurfaceFormat format;
	format.setRenderableType(QSurfaceFormat::OpenGL);
	format.setProfile(QSurfaceFormat::CoreProfile);
	format.setVersion(3, 3);
	setFormat(format);
}

my_QOpenGLWidget::~my_QOpenGLWidget()
{
}

void my_QOpenGLWidget::initializeGL()
{
	//initializeOpenGLFunctions();

	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	setGeometry(20, 50, 300, 200);
	glShadeModel(GL_FLAT);
	glClearColor(0.1, 1.0, 0.2, 0);//改变窗口的背景颜色，不过我这里貌似设置后并没有什么效果
	glClearDepth(1.0);//设置深度缓存
	glEnable(GL_DEPTH_TEST);//允许深度测试
	glDepthFunc(GL_LEQUAL);//设置深度测试类型
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);//进行透视校正

}

void my_QOpenGLWidget::paintGL()
{
	//清理屏幕
	glClear(GL_COLOR_BUFFER_BIT);
}

void my_QOpenGLWidget::resizeGL(int width, int height)
{
	//未使用
	Q_UNUSED(width);
	Q_UNUSED(height);
}