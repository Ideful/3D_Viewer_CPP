#include <locale.h>

#include <QApplication>

#include "view/mainwindow.h"

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  setlocale(LC_ALL, "en_US.UTF-8");
  s21::MainWindow w;
  w.show();
  return a.exec();
}
