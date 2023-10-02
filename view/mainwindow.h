#ifndef CPP4_3DVIEWER_V2_0_SRC_VIEW_MAINWINDOW_H_
#define CPP4_3DVIEWER_V2_0_SRC_VIEW_MAINWINDOW_H_

#define GL_SILENCE_DEPRECATION

#include <QFileDialog>
#include <QMainWindow>
#include <QOpenGLWidget>
#include <QTimer>

#include "../controller/controller.h"
#include "QtGifImage/qgifimage.h"

QT_BEGIN_NAMESPACE
namespace Ui {

/** \brief
 * Методы управляющих воздействий, сохранения и загрузки конфигураций интерфейса
 */
class MainWindow;
}  // namespace Ui
QT_END_NAMESPACE

namespace s21 {

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

 private slots:
  void SetConfig();
  void CheckConfig();
  void on_actionReally_exit_triggered();
  void on_horizontalSlider_MoveX_valueChanged(int value);
  void on_doubleSpinBox_MoveX_valueChanged(double value);
  void on_horizontalSlider_MoveY_valueChanged(int value);
  void on_doubleSpinBox_MoveY_valueChanged(double value);
  void on_horizontalSlider_MoveZ_valueChanged(int value);
  void on_doubleSpinBox_MoveZ_valueChanged(double value);
  void on_horizontalSlider_RotateX_valueChanged(int value);
  void on_doubleSpinBox_RotateX_valueChanged(double value);
  void on_horizontalSlider_RotateY_valueChanged(int value);
  void on_doubleSpinBox_RotateY_valueChanged(double value);
  void on_horizontalSlider_RotateZ_valueChanged(int value);
  void on_doubleSpinBox_RotateZ_valueChanged(double value);
  void on_horizontalSlider_Scale_valueChanged(int value);
  void on_doubleSpinBox_Scale_valueChanged(double value);
  void on_dial_Red_valueChanged(int value);
  void on_dial_Green_valueChanged(int value);
  void on_dial_Blue_valueChanged(int value);
  void on_pushButton_File_clicked();
  void on_radioButton_Central_toggled(bool checked);
  void on_radioButton_Parallel_toggled(bool checked);
  void on_radioButton_Parallel_clicked();
  void on_radioButton_Central_clicked();
  void on_radioButton_Thin_clicked(bool checked);
  void on_radioButton_Norm_toggled(bool checked);
  void on_radioButton_Thick_toggled(bool checked);
  void on_radioButton_Thin_clicked();
  void on_radioButton_Norm_clicked();
  void on_radioButton_Thick_clicked();
  void on_radioButton_Vert_No_toggled(bool checked);
  void on_radioButton_Vert_Crcl_toggled(bool checked);
  void on_radioButton_Vert_Sqr_toggled(bool checked);
  void on_radioButton_Vert_No_clicked();
  void on_radioButton_Vert_Crcl_clicked();
  void on_radioButton_Vert_Sqr_clicked();
  void on_radioButton_Vert_Size1_toggled(bool checked);
  void on_radioButton_Vert_Size2_toggled(bool checked);
  void on_radioButton_Vert_Size3_toggled(bool checked);
  void on_radioButton_Vert_Size1_clicked();
  void on_radioButton_Vert_Size2_clicked();
  void on_radioButton_Vert_Size3_clicked();
  void on_radioButton_Tune_Back_toggled(bool checked);
  void on_radioButton_Tune_Lines_toggled(bool checked);
  void on_radioButton_Tune_Points_toggled(bool checked);
  void on_radioButton_Line_Solid_toggled(bool checked);
  void on_radioButton_LineStipple_toggled(bool checked);
  void on_radioButton_Line_Solid_clicked();
  void on_radioButton_LineStipple_clicked();
  void TakeFrame();
  void on_pushButton_jpeg_clicked();
  void on_pushButton_bmp_clicked();
  void on_pushButton_gif_clicked();

 private:
  Controller controller_;
  QGifImage *gif_;
  QTimer *timer_;
  Ui::MainWindow *ui_;
  int tuner_flag_ = 1;
};

}  // namespace s21

#endif  // CPP4_3DVIEWER_V2_0_SRC_VIEW_MAINWINDOW_H_
