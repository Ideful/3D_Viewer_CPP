#include "../model/model.h"
#include "gtest/gtest.h"

TEST(TestModel, Test_1) {
  s21::Model* model;
  model = s21::Model::GetInstance();
  model->InitModel("obj/cube.obj");
  size_t v = 8, l = 36;
  EXPECT_EQ(model->GetVerticesCount(), v);
  EXPECT_EQ(model->GetLinesCount(), l);
}

TEST(TestModel, Test_2) {
  s21::Model* model;
  model = s21::Model::GetInstance();
  model->InitModel("obj/ball.obj");
  model->Move(60, 60, 60);
  model->Rotate(60, 60, 60);
  model->Scale(60);
  size_t v = 9667, l = 37376;
  EXPECT_EQ(model->GetVerticesCount(), v);
  EXPECT_EQ(model->GetLinesCount(), l);
}

TEST(TestModel, Test_3) {
  s21::Model* model;
  model = s21::Model::GetInstance();
  model->InitModel("obj/cube.obj");
  EXPECT_EQ(model->GetVerticesCount(), model->GetVertices()->size() / 3);
  EXPECT_EQ(model->GetLinesCount(), model->GetLines()->size() / 2);
}

TEST(TestModel, Test_Empty) {
  s21::Model* model;
  model = s21::Model::GetInstance();
  EXPECT_THROW(model->InitModel("obj/empty.obj"), std::logic_error);
}

TEST(TestModel, Test_NoFile) {
  s21::Model* model;
  model = s21::Model::GetInstance();
  EXPECT_THROW(model->InitModel("obj/nofile.obj"), std::logic_error);
}

TEST(TestModel, Test_Wrong1) {
  s21::Model* model;
  model = s21::Model::GetInstance();
  EXPECT_THROW(model->InitModel("obj/wrong1.obj"), std::logic_error);
}

TEST(TestModel, Test_Wrong2) {
  s21::Model* model;
  model = s21::Model::GetInstance();
  EXPECT_THROW(model->InitModel("obj/wrong2.obj"), std::logic_error);
}
