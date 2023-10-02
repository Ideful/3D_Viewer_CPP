#include "controller.h"

namespace s21 {

void Controller::SetModel(std::string filename) {
  model_ = Model::GetInstance();
  model_->InitModel(filename);
}

std::vector<double>* Controller::GetVertices() { return model_->GetVertices(); }

std::vector<unsigned int>* Controller::GetLines() { return model_->GetLines(); }

std::vector<double>::size_type Controller::GetVerticesCount() {
  return model_->GetVerticesCount();
}

std::vector<unsigned int>::size_type Controller::GetLinesCount() {
  return model_->GetLinesCount();
}

void Controller::Move(double x, double y, double z) { model_->Move(x, y, z); }

void Controller::Rotate(double x, double y, double z) {
  model_->Rotate(x, y, z);
}

void Controller::Scale(double x) { model_->Scale(x); }

}  // namespace s21
