#ifndef CPP4_3DVIEWER_V2_0_SRC_MODEL_MODEL_H_
#define CPP4_3DVIEWER_V2_0_SRC_MODEL_MODEL_H_

#include <string>

#include "parser.h"

namespace s21 {

/** \brief
 * Модель реализована с использованием паттерна Singleton
 */
class Model {
 public:
  /** \brief
   * Деструктор модели
   */
  ~Model() = default;

  static Model* GetInstance();

  /** \brief
   * Метод передачи файла в парсер модели
   */
  void InitModel(std::string filaname);

  /** \brief
   * Геттеры вершин и линий
   */
  std::vector<double>* GetVertices();
  std::vector<unsigned int>* GetLines();

  /** \brief
   * Геттеры количества вершин и линий
   */
  std::vector<double>::size_type GetVerticesCount();
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
  /** \brief
   * Конструктор модели
   */
  Model() = default;

  const int kMaxValue_ = 100;
  const int kRotate_ = 36;
  static Model* instance_ptr_;
  Parser parser_;
  double previous_x_move_ = kMaxValue_ / 2;
  double previous_y_move_ = kMaxValue_ / 2;
  double previous_z_move_ = kMaxValue_ / 2;
  double previous_x_rotate_ = kMaxValue_ / 2;
  double previous_y_rotate_ = kMaxValue_ / 2;
  double previous_z_rotate_ = kMaxValue_ / 2;
  double previous_scale_ = kMaxValue_ / 2;

  /** \brief
   * Метод вычисления смещения модели
   */
  double MoveDiffCalculate(double value, double previous);

  /** \brief
   * Метод вычисления вращения модели
   */
  double RotateDiffCalculate(double value, double previous);
};

}  // namespace s21

#endif  // CPP4_3DVIEWER_V2_0_SRC_MODEL_MODEL_H_
