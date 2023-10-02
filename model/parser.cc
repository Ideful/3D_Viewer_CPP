#include "parser.h"

#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>

#include "transformations.h"

namespace s21 {

void Parser::ReadFile(std::string filename) {
  filename_ = filename;
  vertices_.clear();
  lines_.clear();
  std::string str;
  std::ifstream myfile(filename_);
  if (myfile.is_open()) {
    while (getline(myfile, str)) {
      ParseLine(str);
    }
    myfile.close();
  } else {
    throw std::logic_error("Unable to open file");
  }
  if (!Validate()) throw std::logic_error("Incorrect file");
  Center();
}

void Parser::ParseLine(std::string str) {
  if (!str.empty() && str[str.size() - 1] == '\n') str.erase(str.size() - 1);
  if (!str.empty() && str[str.size() - 1] == '\r') str.erase(str.size() - 1);
  if (str[0] == 'v' && str[1] == ' ') {
    GetVerticesFromStr(str);
  } else if (str[0] == 'f' && str[1] == ' ') {
    GetLinesFromStr(str);
  }
}

void Parser::GetVerticesFromStr(std::string str) {
  auto it = str.cbegin() + 2;
  int count = 0;
  while (it < str.cend() && count < 3) {
    while (*it == ' ') ++it;
    std::size_t sz = 0;
    try {
      vertices_.push_back(std::stod(&(*it), &sz));
    } catch (std::exception& e) {
      throw std::logic_error("Stod error");
    }
    ++count;
    it += sz;
  }
  if (count != 3) throw std::logic_error("Incorrect file");
}

void Parser::GetLinesFromStr(std::string str) {
  auto it = str.cbegin() + 2;
  unsigned int first = 0, current = 0, count = 0;
  while (it < str.cend()) {
    while (*it == ' ' && it < str.cend()) ++it;
    if (*it == '/') {
      while (*it != ' ' && it < str.cend()) ++it;
    }
    if (it == str.cend()) break;
    std::size_t sz = 0;
    try {
      current = std::stoul(&(*it), &sz) - 1;
    } catch (std::exception& e) {
      throw std::logic_error("Stoul error");
    }
    if (count == 0) {
      lines_.push_back(current);
      first = current;
    } else {
      lines_.push_back(current);
      lines_.push_back(current);
    }
    ++count;
    it += sz;
  }
  lines_.push_back(first);
}

bool Parser::Validate() {
  bool res = true;
  for (std::vector<unsigned int>::size_type i = 0; i < lines_.size(); ++i) {
    if (lines_[i] >= vertices_.size()) {
      res = false;
      break;
    }
  }
  return res;
}

std::vector<double>* Parser::GetVertices() { return &vertices_; }

std::vector<unsigned int>* Parser::GetLines() { return &lines_; }

void Parser::Center() {
  double x_max = vertices_[0], x_min = vertices_[0];
  double y_max = vertices_[1], y_min = vertices_[1];
  double z_max = vertices_[2], z_min = vertices_[2];
  for (std::vector<double>::size_type i = 1; i < vertices_.size(); ++i) {
    if (i % 3 == 0) {
      if (vertices_[i] > x_max) x_max = vertices_[i];
      if (vertices_[i] < x_min) x_min = vertices_[i];
    } else if (i % 3 == 1) {
      if (vertices_[i] > y_max) y_max = vertices_[i];
      if (vertices_[i] < y_min) y_min = vertices_[i];
    } else if (i % 3 == 2) {
      if (vertices_[i] > z_max) z_max = vertices_[i];
      if (vertices_[i] < z_min) z_min = vertices_[i];
    }
  }
  double max_height = x_max - x_min;
  if (y_max - y_min > max_height) max_height = y_max - y_min;
  if (z_max - z_min > max_height) max_height = z_max - z_min;
  ContextStrategy k;
  k.SetStrategy(std::make_unique<MoveXStrategy>());
  k.ExecuteStrategy(&vertices_, -(x_max + x_min) / 2);
  k.SetStrategy(std::make_unique<MoveYStrategy>());
  k.ExecuteStrategy(&vertices_, -(y_max + y_min) / 2);
  k.SetStrategy(std::make_unique<MoveZStrategy>());
  k.ExecuteStrategy(&vertices_, -(z_max + z_min) / 2);
  k.SetStrategy(std::make_unique<ScaleStrategy>());
  k.ExecuteStrategy(&vertices_, 1 / max_height);
}

}  // namespace s21
