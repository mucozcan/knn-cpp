#include <iostream>

#include "Dataset.h"
#include "Node.h"

int Dataset::dataIndex = 0;
/*  */
/* Dataset::Dataset(int const sampleCount, double const lowerBound, */
/*                  double const upperBound, int const classCount, */
/*                  int const dataPerClass, bool isTrain) */
/*     : sampleCount(sampleCount), lowerBound(lowerBound),
 * upperBound(upperBound), */
/*       classCount(classCount), dataPerClass(dataPerClass), isTrain(isTrain){
 */
/*          */
/*         if(isTrain){ */
/*           initializeTrainData(lowerBound, upperBound, classCount,
 * dataPerClass); */
/*         } */
/*         else initializeTestData(sampleCount, lowerBound, upperBound); */
/*       } */
Dataset::Dataset(){};
Dataset::~Dataset() {}

void Dataset::initializeTrainData(double lowerBound, double upperBound,
                                  int classCount, int dataPerClass) {
  double x, y;

  for (int i = 0; i < classCount; i++) {
    for (int j = 0; j < dataPerClass; j++, dataIndex++) {

      x = random(lowerBound, upperBound);
      y = random(lowerBound, upperBound);
      trainData.push_back(Sample(dataIndex,x, y, i));
    }
  }
}

void Dataset::initializeTestData(double lowerBound, double upperBound, int sampleCount){
  double x,y;
  for(int i = 0; i < sampleCount; i++, dataIndex++){
      x = random(lowerBound, upperBound);
      y = random(lowerBound, upperBound);
      testData.push_back(Sample(dataIndex, x, y));

  }
}

double Dataset::random(double const lowerBound, double const upperBound) {
  double f = (double)rand() / RAND_MAX;

  return lowerBound + f * (upperBound - lowerBound);
}


void Dataset::printTrainData(){
  
  if(!trainData.empty()){
    for(std::vector<Sample>::const_iterator trainIt = trainData.begin(); trainIt!=trainData.end(); trainIt++){
      std::cout << *trainIt << std::endl;
    }
  }
  else std::cout <<"There is no train data" <<std::endl;
}

void Dataset::printTestData(){
  if(!trainData.empty()){
    for(std::vector<Sample>::const_iterator testIt = testData.begin(); testIt!=testData.end(); testIt++){
      std::cout << *testIt << std::endl;
    }
  }
  else std::cout <<"There is no test data" <<std::endl;
}
