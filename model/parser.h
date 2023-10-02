#ifndef CPP4_3DVIEWER_V2_0_SRC_MODEL_PARSER_H_
#define CPP4_3DVIEWER_V2_0_SRC_MODEL_PARSER_H_

#include <string>
#include <vector>

namespace s21 {

class Parser {
 public:
  /** \brief
   * Конструктор и деструктор парсера модели
   */
  Parser() = default;
  ~Parser() = default;

  /** \brief
   * Метод доступа к obj-файлу
   */
  void ReadFile(std::string filename);

  /** \brief
   * Геттеры вершин и линий
   */
  std::vector<double>* GetVertices();
  std::vector<unsigned int>* GetLines();

 private:
  /** \brief
   * Вектор вершин
   */
  std::vector<double> vertices_{};

  /** \brief
   * Вектор линий
   */
  std::vector<unsigned int> lines_{};

  /** \brief
   * Строка, хранящая имя текущего файла
   */
  std::string filename_{};

  /** \brief
   * Метод парсинга obj-файла
   */
  void ParseLine(std::string str);

  /** \brief
   * Метод заполнения вектора вершин
   */
  void GetVerticesFromStr(std::string str);

  /** \brief
   * Метод заполнения вектора полигонов
   */
  void GetLinesFromStr(std::string str);

  /** \brief
   * Метод проверки корректности obj-файла
   */
  bool Validate();

  /** \brief
   * Метод центровки модели
   */
  void Center();
};

}  // namespace s21

#endif  // CPP4_3DVIEWER_V2_0_SRC_MODEL_PARSER_H_
