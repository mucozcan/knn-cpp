#include <iostream>
#include <string>

#include "Dataset.h"
#include "Point.h"

int Dataset::dataIndex = 0;
/*  */
/* Dataset::Dataset(int const pointCount, double const lowerBound, */
/*                  double const upperBound, int const classCount, */
/*                  int const dataPerClass, bool isTrain) */
/*     : pointCount(sampleCount), lowerBound(lowerBound),
 * upperBound(upperBound), */
/*       classCount(classCount), dataPerClass(dataPerClass), isTrain(isTrain){
 */
/*          */
/*         if(isTrain){ */
/*           initializeTrainData(lowerBound, upperBound, classCount,
 * dataPerClass); */
/*         } */
/*         else initializeTestData(pointCount, lowerBound, upperBound); */
/*       } */
Dataset::Dataset(){};
Dataset::~Dataset() {}

std::vector<Point> Dataset::getTrainData() const { return trainData; }
std::vector<Point> Dataset::getTestData() const { return testData; }

void Dataset::initializeTrainData(double lowerBound, double upperBound,
                                  int classCount, int dataPerClass) {
  double x, y;

  for (int i = 0; i < classCount; i++) {
    for (int j = 0; j < dataPerClass; j++, dataIndex++) {

      x = random(lowerBound, upperBound);
      y = random(lowerBound, upperBound);
      trainData.push_back(Point(dataIndex, x, y, i));
    }
  }
}

void Dataset::initializeTestData(double lowerBound, double upperBound,
                                 int pointCount) {
  double x, y;
  for (int i = 0; i < pointCount; i++, dataIndex++) {
    x = random(lowerBound, upperBound);
    y = random(lowerBound, upperBound);
    testData.push_back(Point(dataIndex, x, y));
  }
}

double Dataset::random(double const lowerBound, double const upperBound) {
  double f = (double)rand() / RAND_MAX;

  return lowerBound + f * (upperBound - lowerBound);
}

void Dataset::printTrainData() {

  std::cout << "\t\t" << std::string(10, '*') << " Train Data "
            << std::string(10, '*') << std::endl;
  if (!trainData.empty()) {
    for (std::vector<Point>::const_iterator trainIt = trainData.begin();
         trainIt != trainData.end(); trainIt++) {
      std::cout << *trainIt << std::endl;
    }
  } else
    std::cout << "There is no train data" << std::endl;
}

void Dataset::printTestData() {

  std::cout << "\t\t" << std::string(10, '*') << " Test Data "
            << std::string(10, '*') << std::endl;
  if (!trainData.empty()) {
    for (std::vector<Point>::const_iterator testIt = testData.begin();
         testIt != testData.end(); testIt++) {
      std::cout << *testIt << std::endl;
    }
  } else
    std::cout << "There is no test data" << std::endl;
}
