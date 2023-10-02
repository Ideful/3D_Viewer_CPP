#ifndef CPP4_3DVIEWER_V2_0_SRC_MODEL_TRANSFORMATIONS_H_
#define CPP4_3DVIEWER_V2_0_SRC_MODEL_TRANSFORMATIONS_H_

#include <cmath>
#include <memory>
#include <vector>

namespace s21 {

/** \brief
 * Реализация паттерна Стратегия для трансформаций модели
 */
class Strategy {
 public:
  virtual void Execute(std::vector<double>* data, double value) = 0;
  virtual ~Strategy() {}
};

class ContextStrategy {
 public:
  void SetStrategy(std::unique_ptr<Strategy> strat) {
    strat_ = std::move(strat);
  }
  void ExecuteStrategy(std::vector<double>* data, double value) {
    if (strat_) strat_->Execute(data, value);
  }

 private:
  std::unique_ptr<Strategy> strat_{};
};

class MoveXStrategy : public Strategy {
 public:
  void Execute(std::vector<double>* data, double value);
};

class MoveYStrategy : public Strategy {
 public:
  void Execute(std::vector<double>* data, double value);
};

class MoveZStrategy : public Strategy {
 public:
  void Execute(std::vector<double>* data, double value);
};

class RotateXStrategy : public Strategy {
 public:
  void Execute(std::vector<double>* data, double value);
};

class RotateYStrategy : public Strategy {
 public:
  void Execute(std::vector<double>* data, double value);
};

class RotateZStrategy : public Strategy {
 public:
  void Execute(std::vector<double>* data, double value);
};

class ScaleStrategy : public Strategy {
 public:
  void Execute(std::vector<double>* data, double value);
};

}  // namespace s21

#endif  // CPP4_3DVIEWER_V2_0_SRC_MODEL_TRANSFORMATIONS_H_
