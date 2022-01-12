#include <algorithm>
#include <iostream>
#include <math.h>
#include <numeric>

#include "KNN.h"

double eucledianDistance(Point p1, Point p2) {
  return sqrt(pow((p1.getF1() - p2.getF1()), 2) +
              pow((p1.getF2() - p2.getF2()), 2));
}

KNN::KNN(int const K, Dataset const &dataset) : K(K), dataset(dataset) {

  trainData = dataset.getTrainData();
  testData = dataset.getTestData();
}

KNN::~KNN() {}

std::vector<Point> KNN::getTrainData() const { return trainData; }
std::vector<Point> KNN::getTestData() const { return testData; }

void KNN::run() {

  std::map<int, int>::iterator result;
  int classId;
  for (std::vector<Point>::iterator testIt = testData.begin();
       testIt != testData.end(); testIt++) {
    nearestNeighbors.clear();

    std::sort(trainData.begin(), trainData.end(),
              [testIt](const Point &pLeft, const Point &pRight) {
                return eucledianDistance(*testIt, pLeft) <
                       eucledianDistance(*testIt, pRight);
              });
    for (std::vector<Point>::iterator trainIt = trainData.begin();
         trainIt != trainData.begin() + K; trainIt++)
      nearestNeighbors[trainIt->getClassId()]++;
    result = std::max_element(
        nearestNeighbors.begin(), nearestNeighbors.end(),
        [](const std::pair<int, int> &p1, const std::pair<int, int> &p2) {
          return p1.second < p2.second;
        }); 

    testIt->setClassId(result->first);
  }
  printResults();
}

void KNN::printResults() {
  std::cout << "\t\t" << std::string(10, '*') << " Inference Results "
            << std::string(10, '*') << std::endl;
  for (std::vector<Point>::iterator testIt = testData.begin();
       testIt != testData.end(); testIt++) {
    std::cout << *testIt << std::endl;
  }
}
