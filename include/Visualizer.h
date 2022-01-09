#ifndef VISUALIZER_H
#define VISUALIZER_H

#include <iostream>
#include <set>
#include <string>
#include <vector>


typedef std::pair<std::pair<double, double>, int> ClusterPair;
typedef std::set<ClusterPair> ClusterSet;

/*
 * @brief Visualizer Class
 * 
 * This is a class for plotting data and saving figures on local storage
 */

class Visualizer {

public:
  /*
   * Constructor takes data and sets x and y coordinates.
   * @param clusters includes x and y coordinates of point with the centroid it belongs*/
  Visualizer(ClusterSet& clusters);
  ~Visualizer();
  
  /**plots the points and saves figure
   * @param bool save boolen expression to check saving figure
   * @param string filename path to save figure*/
  void plot(bool, std::string);

  std::vector<double> getXCoords();
  std::vector<double> getYCoords();
  std::vector<double> getColors();

private:
  /*
   * takes cluster data and split x coords, y coords and centroid id
   * @param clusters includes x and y coordinates of point with the centroid it belongs*/
  void initialize(ClusterSet &clusters);
  std::vector<double> xCoords;
  std::vector<double> yCoords;
  std::vector<double> colors;
};

#endif
