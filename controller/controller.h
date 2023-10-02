#ifndef CPP4_3DVIEWER_V2_0_SRC_CONTROLLER_CONTROLLER_H_
#define CPP4_3DVIEWER_V2_0_SRC_CONTROLLER_CONTROLLER_H_

#include <string>
#include <vector>

#include "../model/model.h"

namespace s21 {

/** \brief
 * Контроллер реализован с использованием паттерна Фасад
 */
class Controller {
 public:
  /** \brief
   * Конструктор и деструктор контроллера
   */
  Controller() = default;
  ~Controller() = default;

  /** \brief
   * Метод передачи имени файла в парсер
   */
  void SetModel(std::string filename);

  /** \brief
   * Метод получения вершин из парсера
   */
  std::vector<double> *GetVertices();

  /** \brief
   * Метод получения линий из парсера
   */
  std::vector<unsigned int> *GetLines();

  /** \brief
   * Метод получения количества вершин из парсера
   */
  std::vector<double>::size_type GetVerticesCount();

  /** \brief
   * Метод получения количества линий из парсера
   */
  std::vector<unsigned int>::size_type GetLinesCount();

  /** \brief
   * Метод реализации сдвига модели
   */
  void Move(double x, double y, double z);

  /** \brief
   * Метод реализации вращения модели
   */
  void Rotate(double x, double y, double z);

  /** \brief
   * Метод реализации масштабирования модели
   */
  void Scale(double x);

 private:
  Model *model_ = nullptr;
};

}  // namespace s21

#endif  // CPP4_3DVIEWER_V2_0_SRC_CONTROLLER_CONTROLLER_H_
