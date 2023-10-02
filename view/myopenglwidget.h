#ifndef CPP4_3DVIEWER_V2_0_SRC_VIEW_MYOPENGLWIDGET_H_
#define CPP4_3DVIEWER_V2_0_SRC_VIEW_MYOPENGLWIDGET_H_

#include <QOpenGLWidget>
#include <QtWidgets>

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

namespace s21 {

/** \brief
 * Методы OpenGL отображения модели
 */
class MyOpenGLWidget : public QOpenGLWidget {
  Q_OBJECT
 public:
  explicit MyOpenGLWidget(QWidget* parent = 0);
  void SetVertices(std::vector<double>* v) { vertices_ = v; }
  void SetLines(std::vector<unsigned int>* l) { lines_ = l; }
  float color_back_red = 0, color_back_green = 0, color_back_blue = 0;
  float color_line_red = 1, color_line_green = 1, color_line_blue = 1;
  float color_vert_red = 1, color_vert_green = 1, color_vert_blue = 1;
  bool projection = true;
  int point_type = 0, point_size = 10, line_size = 2, line_type = 0;

 protected:
  void initializeGL();
  void paintGL();
  void resizeGL(int width, int height);

 private:
  std::vector<double>* vertices_{nullptr};
  std::vector<unsigned int>* lines_{nullptr};
};

}  // namespace s21

#endif  // CPP4_3DVIEWER_V2_0_SRC_VIEW_MYOPENGLWIDGET_H_
