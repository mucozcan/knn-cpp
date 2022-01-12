#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#include "Dataset.h"
#include "Visualizer.h"
#include <matplot/matplot.h>

Visualizer::Visualizer(std::vector<Point> &trainData,
                       std::vector<Point> &testData) {
  initialize(trainData, testData);
}

Visualizer::~Visualizer() {}

void Visualizer::initialize(std::vector<Point> &trainData,
                            std::vector<Point> &testData) {

  // merge dataset and split features
  trainData.insert(trainData.end(), testData.begin(), testData.end());
  std::transform(trainData.begin(), trainData.end(), std::back_inserter(feat1),
                 [](Point p) { return p.getF1(); });


  std::transform(trainData.begin(), trainData.end(), std::back_inserter(feat2),
                 [](Point p) { return p.getF2(); });

  std::transform(trainData.begin(), trainData.end(), std::back_inserter(classes),
                 [](Point p) { return p.getClassId(); });

  sizes.resize(classes.size());
  std::fill(sizes.begin(), sizes.end(), 12);
  std::fill(sizes.begin(), sizes.end() - testData.size() - 1, 20);
}
void Visualizer::plot(bool save, std::string filename) {
  auto l = matplot::scatter(feat1, feat2, sizes, classes);
  l->marker_face(true);
  matplot::show();
  if (save) {
    matplot::save(filename);
    std::cout << "Result is saved to: " << filename << std::endl;
  }
}
