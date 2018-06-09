#include "stdafx.h"
#include "my_qopenglwidget.h"
#include "CAD.h"
#include "include/Renderer.h"
#include "include/Ellipse.h"
#include "include/Polygon.h"
#include <GL/freeglut.h>
#include <thread>
#include <vector>


using namespace std;
using namespace ACCAD;

ACCAD::IFigure *t;
ACCAD::IFigure *s;

Renderer renderer;

my_QOpenGLWidget::my_QOpenGLWidget(QWidget *parent)
	: QOpenGLWidget(parent)
{
	rTri = 0.0;
}

my_QOpenGLWidget::~my_QOpenGLWidget()
{
}
void my_QOpenGLWidget::initializeGL()
{
	//设置全局变量
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	setGeometry(0, 0, 640, 480);//设置窗口初始位置和大小
	glShadeModel(GL_FLAT);//设置阴影平滑模式
	glClearColor(1.0, 1.0, 1.0, 0);//改变窗口的背景颜色，不过我这里貌似设置后并没有什么效果
	glClearDepth(1.0);//设置深度缓存
	glEnable(GL_DEPTH_TEST);//允许深度测试
	glDepthFunc(GL_LEQUAL);//设置深度测试类型
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);//进行透视校正
}
void my_QOpenGLWidget::paintGL()
{
	//清理屏幕
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);//清除屏幕和深度缓存
	glLoadIdentity();
	//glTranslatef(-1.5, 0.0, -6.0);
	
	glRotatef(rTri, 0.0, 1.0, 0.0);
	glBegin(GL_TRIANGLES);
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(0.0, 0.5, 0.0);
	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(-0.5, -0.5, 0.5);
	
	glVertex3f(0.5, -0.5, 0.5);

	glEnd();
	rTri += 0.2;
}

void my_QOpenGLWidget::resizeGL(int width, int height)
{
	//未使用
	Q_UNUSED(width);
	Q_UNUSED(height);
}
