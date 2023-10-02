#include "mainwindow.h"

#include <QTimer>

#include "QtGifImage/qgifimage.h"
#include "ui_mainwindow.h"

namespace s21 {

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent),
      gif_(nullptr),
      timer_(new QTimer),
      ui_(new Ui::MainWindow) {
  ui_->setupUi(this);
  CheckConfig();
}

MainWindow::~MainWindow() {
  SetConfig();
  delete ui_;
}

void MainWindow::SetConfig() {
  QFile config_file;
  config_file.setFileName(qApp->applicationDirPath() + "/3dviewer.cfg");
  if (!config_file.open(QIODevice::WriteOnly | QFile::Text)) return;
  config_file.write("\nvert_size=");
  config_file.write(std::to_string(ui_->widget->point_size).c_str());
  config_file.write("\nline_thick=");
  config_file.write(std::to_string(ui_->widget->line_size).c_str());
  config_file.write("\nline_type=");
  config_file.write(std::to_string(ui_->widget->line_type).c_str());
  config_file.write("\nvert_type=");
  config_file.write(std::to_string(ui_->widget->point_type).c_str());
  config_file.write("\nback_red=");
  config_file.write(std::to_string(ui_->widget->color_back_red).c_str());
  config_file.write("\nback_green=");
  config_file.write(std::to_string(ui_->widget->color_back_green).c_str());
  config_file.write("\nback_blue=");
  config_file.write(std::to_string(ui_->widget->color_back_blue).c_str());
  config_file.write("\nvert_red=");
  config_file.write(std::to_string(ui_->widget->color_vert_red).c_str());
  config_file.write("\nvert_green=");
  config_file.write(std::to_string(ui_->widget->color_vert_green).c_str());
  config_file.write("\nvert_blue=");
  config_file.write(std::to_string(ui_->widget->color_vert_blue).c_str());
  config_file.write("\nline_red=");
  config_file.write(std::to_string(ui_->widget->color_line_red).c_str());
  config_file.write("\nline_green=");
  config_file.write(std::to_string(ui_->widget->color_line_green).c_str());
  config_file.write("\nline_blue=");
  config_file.write(std::to_string(ui_->widget->color_line_blue).c_str());
  config_file.close();
}

void MainWindow::CheckConfig() {
  QFile config_file;
  QString line;
  QStringList list;
  config_file.setFileName(qApp->applicationDirPath() + "/3dviewer.cfg");
  if (!config_file.open(QIODevice::ReadOnly | QFile::Text)) return;
  while (!config_file.atEnd()) {
    line = config_file.readLine();
    list = line.split('=', Qt::SkipEmptyParts);
    if (list.count() == 2) {
      list[1].chop(1);
      if (list[0] == "vert_size") ui_->widget->point_size = list[1].toFloat();
      if (list[0] == "line_thick") ui_->widget->line_size = list[1].toFloat();
      if (list[0] == "line_type") ui_->widget->line_type = list[1].toFloat();
      if (list[0] == "vert_type") ui_->widget->point_type = list[1].toFloat();
      if (list[0] == "back_red")
        ui_->widget->color_back_red = list[1].toFloat();
      if (list[0] == "back_green")
        ui_->widget->color_back_green = list[1].toFloat();
      if (list[0] == "back_blue")
        ui_->widget->color_back_blue = list[1].toFloat();
      if (list[0] == "vert_red")
        ui_->widget->color_vert_red = list[1].toFloat();
      if (list[0] == "vert_green")
        ui_->widget->color_vert_green = list[1].toFloat();
      if (list[0] == "vert_blue")
        ui_->widget->color_vert_blue = list[1].toFloat();
      if (list[0] == "line_red")
        ui_->widget->color_line_red = list[1].toFloat();
      if (list[0] == "line_green")
        ui_->widget->color_line_green = list[1].toFloat();
      if (list[0] == "line_blue")
        ui_->widget->color_line_blue = list[1].toFloat();
    }
  }
}

void MainWindow::on_actionReally_exit_triggered() { close(); }

void MainWindow::on_horizontalSlider_MoveX_valueChanged(int value) {
  ui_->doubleSpinBox_MoveX->setValue(value);
}

void MainWindow::on_doubleSpinBox_MoveX_valueChanged(double value) {
  ui_->horizontalSlider_MoveX->setValue(value);
  controller_.Move(value, 0, 0);
  ui_->widget->update();
}

void MainWindow::on_horizontalSlider_MoveY_valueChanged(int value) {
  ui_->doubleSpinBox_MoveY->setValue(value);
}

void MainWindow::on_doubleSpinBox_MoveY_valueChanged(double value) {
  ui_->horizontalSlider_MoveY->setValue(value);
  controller_.Move(0, value, 0);
  ui_->widget->update();
}

void MainWindow::on_horizontalSlider_MoveZ_valueChanged(int value) {
  ui_->doubleSpinBox_MoveZ->setValue(value);
}

void MainWindow::on_doubleSpinBox_MoveZ_valueChanged(double value) {
  ui_->horizontalSlider_MoveZ->setValue(value);
  controller_.Move(0, 0, value);
  ui_->widget->update();
}

void MainWindow::on_horizontalSlider_RotateX_valueChanged(int value) {
  ui_->doubleSpinBox_RotateX->setValue(value);
}

void MainWindow::on_doubleSpinBox_RotateX_valueChanged(double value) {
  ui_->horizontalSlider_RotateX->setValue(value);
  controller_.Rotate(value, 0, 0);
  ui_->widget->update();
}

void MainWindow::on_horizontalSlider_RotateY_valueChanged(int value) {
  ui_->doubleSpinBox_RotateY->setValue(value);
}

void MainWindow::on_doubleSpinBox_RotateY_valueChanged(double value) {
  ui_->horizontalSlider_RotateY->setValue(value);
  controller_.Rotate(0, value, 0);
  ui_->widget->update();
}

void MainWindow::on_horizontalSlider_RotateZ_valueChanged(int value) {
  ui_->doubleSpinBox_RotateZ->setValue(value);
}

void MainWindow::on_doubleSpinBox_RotateZ_valueChanged(double value) {
  ui_->horizontalSlider_RotateZ->setValue(value);
  controller_.Rotate(0, 0, value);
  ui_->widget->update();
}

void MainWindow::on_horizontalSlider_Scale_valueChanged(int value) {
  ui_->doubleSpinBox_Scale->setValue(value);
}

void MainWindow::on_doubleSpinBox_Scale_valueChanged(double value) {
  ui_->horizontalSlider_Scale->setValue(value);
  controller_.Scale(value);
  ui_->widget->update();
}

void MainWindow::on_dial_Red_valueChanged(int value) {
  if (tuner_flag_ == 0) ui_->widget->color_back_red = value / 255.0f;
  if (tuner_flag_ == 1) ui_->widget->color_line_red = value / 255.0f;
  if (tuner_flag_ == 2) ui_->widget->color_vert_red = value / 255.0f;
  ui_->widget->update();
}

void MainWindow::on_dial_Green_valueChanged(int value) {
  if (tuner_flag_ == 0) ui_->widget->color_back_green = value / 255.0f;
  if (tuner_flag_ == 1) ui_->widget->color_line_green = value / 255.0f;
  if (tuner_flag_ == 2) ui_->widget->color_vert_green = value / 255.0f;
  ui_->widget->update();
}

void MainWindow::on_dial_Blue_valueChanged(int value) {
  if (tuner_flag_ == 0) ui_->widget->color_back_blue = value / 255.0f;
  if (tuner_flag_ == 1) ui_->widget->color_line_blue = value / 255.0f;
  if (tuner_flag_ == 2) ui_->widget->color_vert_blue = value / 255.0f;
  ui_->widget->update();
}

void MainWindow::on_pushButton_File_clicked() {
  QString str;
  str = QFileDialog::getOpenFileName(this, "Choose OBJ file", "/Users/",
                                     "OBJ Files (*.obj);; All Files (*.*)");
  ui_->horizontalSlider_MoveX->setValue(50);
  ui_->horizontalSlider_MoveY->setValue(50);
  ui_->horizontalSlider_MoveZ->setValue(50);
  ui_->horizontalSlider_RotateX->setValue(50);
  ui_->horizontalSlider_RotateY->setValue(50);
  ui_->horizontalSlider_RotateZ->setValue(50);
  ui_->horizontalSlider_Scale->setValue(50);
  try {
    controller_.SetModel(str.toStdString());
    ui_->label->setText(str.split('/').last());
    ui_->statusbar->showMessage("");
    ui_->widget->SetVertices(controller_.GetVertices());
    ui_->widget->SetLines(controller_.GetLines());
    ui_->label_vertex_count->setText(
        QString::number(controller_.GetVerticesCount()));
    ui_->label_lines_count->setText(
        QString::number(controller_.GetLinesCount()));
  } catch (std::exception& e) {
    ui_->label->setText("No file loaded");
    ui_->statusbar->showMessage(e.what());
    ui_->widget->SetVertices(nullptr);
    ui_->widget->SetLines(nullptr);
    ui_->label_vertex_count->setText("-");
    ui_->label_lines_count->setText("-");
  }
  ui_->widget->update();
}

void MainWindow::on_radioButton_Central_toggled(bool checked) {
  if (checked == true) ui_->widget->projection = true;
}

void MainWindow::on_radioButton_Parallel_toggled(bool checked) {
  if (checked == true) ui_->widget->projection = false;
}

void MainWindow::on_radioButton_Central_clicked() { ui_->widget->update(); }

void MainWindow::on_radioButton_Parallel_clicked() { ui_->widget->update(); }

void MainWindow::on_radioButton_Thin_clicked(bool checked) {
  if (checked == true) ui_->widget->line_size = 1;
}

void MainWindow::on_radioButton_Norm_toggled(bool checked) {
  if (checked == true) ui_->widget->line_size = 2;
}

void MainWindow::on_radioButton_Thick_toggled(bool checked) {
  if (checked == true) ui_->widget->line_size = 3;
}

void MainWindow::on_radioButton_Thin_clicked() { ui_->widget->update(); }

void MainWindow::on_radioButton_Norm_clicked() { ui_->widget->update(); }

void MainWindow::on_radioButton_Thick_clicked() { ui_->widget->update(); }

void MainWindow::on_radioButton_Vert_No_toggled(bool checked) {
  if (checked == true) ui_->widget->point_type = 0;
}

void MainWindow::on_radioButton_Vert_Crcl_toggled(bool checked) {
  if (checked == true) ui_->widget->point_type = 1;
}

void MainWindow::on_radioButton_Vert_Sqr_toggled(bool checked) {
  if (checked == true) ui_->widget->point_type = 2;
}

void MainWindow::on_radioButton_Vert_No_clicked() { ui_->widget->update(); }

void MainWindow::on_radioButton_Vert_Crcl_clicked() { ui_->widget->update(); }

void MainWindow::on_radioButton_Vert_Sqr_clicked() { ui_->widget->update(); }

void MainWindow::on_radioButton_Vert_Size1_toggled(bool checked) {
  if (checked == true) ui_->widget->point_size = 5;
}

void MainWindow::on_radioButton_Vert_Size2_toggled(bool checked) {
  if (checked == true) ui_->widget->point_size = 10;
}

void MainWindow::on_radioButton_Vert_Size3_toggled(bool checked) {
  if (checked == true) ui_->widget->point_size = 15;
}

void MainWindow::on_radioButton_Vert_Size1_clicked() { ui_->widget->update(); }

void MainWindow::on_radioButton_Vert_Size2_clicked() { ui_->widget->update(); }

void MainWindow::on_radioButton_Vert_Size3_clicked() { ui_->widget->update(); }

void MainWindow::on_radioButton_Tune_Back_toggled(bool checked) {
  if (checked == true) tuner_flag_ = 0;
}

void MainWindow::on_radioButton_Tune_Lines_toggled(bool checked) {
  if (checked == true) tuner_flag_ = 1;
}

void MainWindow::on_radioButton_Tune_Points_toggled(bool checked) {
  if (checked == true) tuner_flag_ = 2;
}

void MainWindow::on_radioButton_Line_Solid_toggled(bool checked) {
  if (checked == true) ui_->widget->line_type = 0;
}

void MainWindow::on_radioButton_LineStipple_toggled(bool checked) {
  if (checked == true) ui_->widget->line_type = 1;
}

void MainWindow::on_radioButton_Line_Solid_clicked() { ui_->widget->update(); }

void MainWindow::on_radioButton_LineStipple_clicked() { ui_->widget->update(); }

void MainWindow::on_pushButton_jpeg_clicked() {
  QString file = QFileDialog::getSaveFileName(
      this, "Save as...", "screenshot.jpeg", "JPEG (*.jpeg)");
  ui_->widget->grabFramebuffer().save(file, NULL, 100);
}

void MainWindow::on_pushButton_bmp_clicked() {
  QString file = QFileDialog::getSaveFileName(this, "Save as...",
                                              "screenshot.bmp", "BMP (*.bmp)");
  ui_->widget->grabFramebuffer().save(file, NULL, 100);
}

void MainWindow::on_pushButton_gif_clicked() {
  gif_ = new QGifImage;
  timer_ = new QTimer(this);
  gif_->setDefaultDelay(100);
  timer_->start(100);
  connect(timer_, SIGNAL(timeout()), this, SLOT(TakeFrame()));
}

void MainWindow::TakeFrame() {
  QImage frame = ui_->widget->grabFramebuffer();
  gif_->addFrame(frame.scaled(640, 480), 0);
  if (gif_->frameCount() == 50) {
    timer_->stop();
    QString gif_path = QFileDialog::getSaveFileName(
        this, ("Save as GIF"), "image.gif", "GIF Image Files (*.gif)");
    gif_->save(gif_path);
    delete timer_;
    delete gif_;
  }
}

}  // namespace s21
