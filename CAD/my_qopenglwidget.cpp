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
	//����ȫ�ֱ���
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	setGeometry(0, 0, 640, 480);//���ô��ڳ�ʼλ�úʹ�С
	glShadeModel(GL_FLAT);//������Ӱƽ��ģʽ
	glClearColor(1.0, 1.0, 1.0, 0);//�ı䴰�ڵı�����ɫ������������ò�����ú�û��ʲôЧ��
	glClearDepth(1.0);//������Ȼ���
	glEnable(GL_DEPTH_TEST);//������Ȳ���
	glDepthFunc(GL_LEQUAL);//������Ȳ�������
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);//����͸��У��
}
void my_QOpenGLWidget::paintGL()
{
	//������Ļ
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);//�����Ļ����Ȼ���
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
	//δʹ��
	Q_UNUSED(width);
	Q_UNUSED(height);
}
