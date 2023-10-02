#include "model.h"

#include "transformations.h"

namespace s21 {

Model* Model::GetInstance() {
  if (instance_ptr_ == nullptr) {
    instance_ptr_ = new Model();
  }
  return instance_ptr_;
}

Model* Model::instance_ptr_ = nullptr;

void Model::InitModel(std::string filename) { parser_.ReadFile(filename); }

std::vector<double>* Model::GetVertices() { return parser_.GetVertices(); }

std::vector<unsigned int>* Model::GetLines() { return parser_.GetLines(); }

std::vector<double>::size_type Model::GetVerticesCount() {
  return parser_.GetVertices()->size() / 3;
}

std::vector<unsigned int>::size_type Model::GetLinesCount() {
  return parser_.GetLines()->size() / 2;
}

void Model::Move(double x, double y, double z) {
  ContextStrategy k;
  if (x != 0) {
    double diff = MoveDiffCalculate(x, previous_x_move_);
    k.SetStrategy(std::make_unique<MoveXStrategy>());
    k.ExecuteStrategy(parser_.GetVertices(), diff);
    previous_x_move_ = x;
  }
  if (y != 0) {
    double diff = MoveDiffCalculate(y, previous_y_move_);
    k.SetStrategy(std::make_unique<MoveYStrategy>());
    k.ExecuteStrategy(parser_.GetVertices(), diff);
    previous_y_move_ = y;
  }
  if (z != 0) {
    double diff = MoveDiffCalculate(z, previous_z_move_);
    k.SetStrategy(std::make_unique<MoveZStrategy>());
    k.ExecuteStrategy(parser_.GetVertices(), diff);
    previous_z_move_ = z;
  }
}

void Model::Rotate(double x, double y, double z) {
  ContextStrategy k;
  if (x != 0) {
    double diff = RotateDiffCalculate(x, previous_x_rotate_);
    k.SetStrategy(std::make_unique<RotateXStrategy>());
    k.ExecuteStrategy(parser_.GetVertices(), diff);
    previous_x_rotate_ = x;
  }
  if (y != 0) {
    double diff = RotateDiffCalculate(y, previous_y_rotate_);
    k.SetStrategy(std::make_unique<RotateYStrategy>());
    k.ExecuteStrategy(parser_.GetVertices(), diff);
    previous_y_rotate_ = y;
  }
  if (z != 0) {
    double diff = RotateDiffCalculate(z, previous_z_rotate_);
    k.SetStrategy(std::make_unique<RotateZStrategy>());
    k.ExecuteStrategy(parser_.GetVertices(), diff);
    previous_z_rotate_ = z;
  }
}

void Model::Scale(double x) {
  double diff = 1 + (x - previous_scale_) / kMaxValue_;
  ContextStrategy k;
  k.SetStrategy(std::make_unique<ScaleStrategy>());
  k.ExecuteStrategy(parser_.GetVertices(), diff);
  previous_scale_ = x;
}

double Model::MoveDiffCalculate(double value, double previous) {
  return (value - previous) / kMaxValue_;
}

double Model::RotateDiffCalculate(double value, double previous) {
  return (value - previous) * (M_PI / kRotate_);
}

}  // namespace s21
