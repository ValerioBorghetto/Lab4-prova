#ifndef REGRESSIONE_HPP 
#define REGRESSIONE_HPP
#include <cassert>
#include <vector>

struct Point {
    double x;
    double y;
};

struct Result {  
  double A{};  
  double B{};
};

class Regression {
 private:
  
  std::vector<Point> points_{}; //si aggiunge un vector e la struct point per poter tener traccia dei vari punti aggiunti
  
  //int N_{};          


 public:
  void add(double x, double y);  
  
  Result fit() const  
  {
    double sium_x_{};  
    double sium_y_{};
    double sium_x2_ = 0;
    double sium_xy_ = 0;

    for (auto const& p : points_) {
      sium_x_ += p.x;
      sium_y_ += p.y;
      sium_x2_ += p.x * p.x;
      sium_xy_ += p.x * p.y; 
    }
    int N_=points_.size();

    assert(sium_x_!= 0 && N_>1 ); 
    double Q = (sium_y_ * sium_x2_ - sium_x_ * sium_xy_) /
               (N_ * sium_x2_ - sium_x_ * sium_x_);
    double M = (N_ * sium_xy_ - sium_x_ * sium_y_) /
               (N_ * sium_x2_ - sium_x_ * sium_x_);
     Result ciao{Q,M};       
    return ciao;
  }
};


Result fit(Regression const &reg); 
#endif