#include <algorithm>
#include <iostream>
#include <math.h>

#include "KNN.h"

KNN::KNN(int const K, Dataset const &dataset) : K(K), dataset(dataset) {

  trainData = dataset.getTrainData();
  testData = dataset.getTestData();
}

KNN::~KNN() {}

void KNN::run() {

  double dist;
  std::map<int, int>::iterator result;

  for (std::vector<Point>::iterator testIt = testData.begin();
       testIt != testData.end(); testIt++) {
    neighbors.clear();
    nearestNeighbors.clear();

    for (std::vector<Point>::iterator trainIt = trainData.begin();
         trainIt != trainData.end(); trainIt++) {

      dist = eucledianDistance(*testIt, *trainIt);

      neighbors.insert({dist, trainIt->getClassId()});
    }

    /* std::copy_n(neighbors.begin(), K, std::inserter(nearestNeighbors,
     * nearestNeighbors.end())); */

    //find nearest neighbors and select most frequent class
    Neighbors::iterator nearIt = neighbors.begin();
    for (int i = 0; i < K; i++) {

      ++nearestNeighbors[nearIt->second];

      nearIt++;
      if (nearIt == neighbors.end())
        break;
    }

    result = std::max_element(nearestNeighbors.begin(), nearestNeighbors.end());
    testIt->setClassId(result->first);
  }
  printResults();
}

double KNN::eucledianDistance(Point p1, Point p2) {
  return sqrt(pow((p1.getX() - p2.getX()), 2) +
              pow((p1.getY() - p2.getY()), 2));
}

void KNN::printResults(){
    std::cout << "Inference Results:" <<std::endl;
    for(std::vector<Point>::iterator testIt = testData.begin(); testIt != testData.end(); testIt++){
      std::cout << *testIt <<std::endl;
    }
}
