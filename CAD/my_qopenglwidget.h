#pragma once

#include <QOpenGLWidget>




class my_QOpenGLWidget : public QOpenGLWidget
{
	Q_OBJECT

public:
	my_QOpenGLWidget(QWidget *parent);
	~my_QOpenGLWidget();

	void initializeGL();
	void resizeGL(int width, int height);
	void paintGL();
private:
	GLfloat rTri;


};

