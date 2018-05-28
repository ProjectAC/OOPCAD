#pragma once

#include <QOpenGLWidget>
#include <QOpenGLFunctions>

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
};
