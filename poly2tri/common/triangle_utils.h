
#ifndef RANDOM_UTILS_H
#define RANDOM_UTILS_H

#include "shapes.h"
#include <math.h>
#include <time.h>
#include <iostream>

namespace p2t {

double random(double (*fun)(double), double xmin = 0, double xmax = 1)
{
  static double (*Fun)(double) = NULL, YMin, YMax;
  static bool First = true;

  // Initialises random generator for first call
  if (First)
  {
    First = false;
    srand((unsigned) time(NULL));
  }

  // Evaluates maximum of function
  if (fun != Fun)
  {
    Fun = fun;
    YMin = 0, YMax = Fun(xmin);
    for (int iX = 1; iX < RAND_MAX; iX++)
    {
      double X = xmin + (xmax - xmin) * iX / RAND_MAX;
      double Y = Fun(X);
      YMax = Y > YMax ? Y : YMax;
    }
  }

  // Gets random values for X & Y
  double X = xmin + (xmax - xmin) * rand() / RAND_MAX;
  double Y = YMin + (YMax - YMin) * rand() / RAND_MAX;

  // Returns if valid and try again if not valid
  return Y < fun(X) ? X : random(Fun, xmin, xmax);
}


void random_points_in_triangle(double x1, double y1, double x2, double y2, double x3, double y3, long long num)
{
    for (long long it = 0; it < num; ++it)
    {
        double x = random(NULL);
        double y = random(NULL);
        //std::cout << x << "," << y << std::endl;
        if(x + y > 1)
        {
            x = 1 - x;
            y = 1 - y;
        }
        double p1 = (x2-x1)*x + (x3-x1)*y + x1;
        double p2 = (y2-y1)*x + (y3-y1)*y + y1;
        std::cout << p1 << "," << p2 << std::endl;
    }
}

double triangle_area(double x1, double y1, double x2, double y2, double x3, double y3)
{
    return (x1*y2 + x2*y3 + x3*y1 - x3*y2 - x2*y1 - x1*y3)/2.;
}

double triangle_area(Triangle& tri)
{
    Point& a = *tri.GetPoint(0);
    Point& b = *tri.GetPoint(1);
    Point& c = *tri.GetPoint(2);
    return triangle_area(a.x, a.y, b.x, b.y, c.x, c.y);
}

void random_points_in_triangle(Triangle& tri, long long num)
{
    Point& a = *tri.GetPoint(0);
    Point& b = *tri.GetPoint(1);
    Point& c = *tri.GetPoint(2);
    random_points_in_triangle(a.x, a.y, b.x, b.y, c.x, c.y, num);
}

}   // namespace p2t

#endif // RANDOM_UTILS_H
