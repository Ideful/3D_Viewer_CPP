#include "transformations.h"

namespace s21 {

void MoveXStrategy::Execute(std::vector<double>* data, double value) {
  std::vector<double>::size_type i = 0;
  while (i < data->size()) {
    (*data)[i] += value;
    i += 3;
  }
}

void MoveYStrategy::Execute(std::vector<double>* data, double value) {
  std::vector<double>::size_type i = 1;
  while (i < data->size()) {
    (*data)[i] += value;
    i += 3;
  }
}

void MoveZStrategy::Execute(std::vector<double>* data, double value) {
  std::vector<double>::size_type i = 2;
  while (i < data->size()) {
    (*data)[i] += value;
    i += 3;
  }
}

void RotateXStrategy::Execute(std::vector<double>* data, double value) {
  std::vector<double>::size_type i = 0;
  double temp_y = 0;
  double temp_z = 0;
  while (i < data->size()) {
    temp_y = (*data)[i + 1];
    temp_z = (*data)[i + 2];
    (*data)[i + 1] = cos(value) * temp_y - sin(value) * temp_z;
    (*data)[i + 2] = sin(value) * temp_y + cos(value) * temp_z;
    i += 3;
  }
}

void RotateYStrategy::Execute(std::vector<double>* data, double value) {
  std::vector<double>::size_type i = 0;
  double temp_x = 0;
  double temp_z = 0;
  while (i < data->size()) {
    temp_x = (*data)[i];
    temp_z = (*data)[i + 2];
    (*data)[i] = cos(value) * temp_x + sin(value) * temp_z;
    (*data)[i + 2] = cos(value) * temp_z - sin(value) * temp_x;
    i += 3;
  }
}

void RotateZStrategy::Execute(std::vector<double>* data, double value) {
  std::vector<double>::size_type i = 0;
  double temp_x = 0;
  double temp_y = 0;
  while (i < data->size()) {
    temp_x = (*data)[i];
    temp_y = (*data)[i + 1];
    (*data)[i] = cos(value) * temp_x + sin(value) * temp_y;
    (*data)[i + 1] = cos(value) * temp_y - sin(value) * temp_x;
    i += 3;
  }
}

void ScaleStrategy::Execute(std::vector<double>* data, double value) {
  for (std::vector<double>::size_type i = 0; i < data->size(); ++i)
    (*data)[i] *= value;
}

}  // namespace s21
