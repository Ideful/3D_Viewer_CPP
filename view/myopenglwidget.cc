#include "myopenglwidget.h"

namespace s21 {

MyOpenGLWidget::MyOpenGLWidget(QWidget *parent) : QOpenGLWidget(parent) {}

void MyOpenGLWidget::initializeGL() { glEnable(GL_DEPTH_TEST); }

void MyOpenGLWidget::paintGL() {
  glClearColor(color_back_red, color_back_green, color_back_blue, 0);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  if (projection) {
    glFrustum(-1, 1, -1, 1, 2, 6);
    glTranslatef(0, 0, -3);
  } else {
    glOrtho(-1, 1, -1, 1, -1, 2);
  }
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glEnableClientState(GL_VERTEX_ARRAY);
  if (vertices_ != nullptr) {
    glVertexPointer(3, GL_DOUBLE, 0, &((*vertices_)[0]));
    if (point_type > 0) {
      if (point_type == 1)
        glEnable(GL_POINT_SMOOTH);
      else
        glDisable(GL_POINT_SMOOTH);
      glPointSize(point_size);
      glColor3d(color_vert_red, color_vert_green, color_vert_blue);
      glDrawArrays(GL_POINTS, 0, vertices_->size() / 3);
    }
  }
  if (lines_ != nullptr) {
    glColor3d(color_line_red, color_line_green, color_line_blue);
    glLineWidth(line_size);
    glLineStipple(1, 0x00F0);
    if (line_type == 1)
      glEnable(GL_LINE_STIPPLE);
    else
      glDisable(GL_LINE_STIPPLE);
    glDrawElements(GL_LINES, lines_->size(), GL_UNSIGNED_INT, &((*lines_)[0]));
  }
  glDisableClientState(GL_VERTEX_ARRAY);
}

void MyOpenGLWidget::resizeGL(int width, int height) {
  glViewport(0, 0, width, height);
}

}  // namespace s21
