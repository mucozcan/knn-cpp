## KMeans++ Clustering
### TODO
* edit .gitignore
* visualize data
* clear comments
* convert dtype from double to int depending on visual results

### Installation
#### Prerequisites
* Ubuntu 20.04
* g++ 9.3.0
* gnuplot 5.2
* cmake 3.16.3
* [Matplot++](https://github.com/alandefreitas/matplotplusplus)

To install gnuplot;
```
sudo apt-get install gnuplot 
```

clone the Matplot++ into root directory of project:
``` 
git clone https://github.com/alandefreitas/matplotplusplus.git
```

#### Building

``` 
cd build/
cmake ..
make
```

#### Running
```
cd ..
cd bin
./main 2 3 ../data/20.txt
```
# knn-cpp
