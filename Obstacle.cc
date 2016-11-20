#include <iostream>
#include <cmath>

using namespace std;

/**    Obstacle    **/

class Obstacle 
{
  public:

    double Xc;  // Center coordinates for obstacles
    double Yc;

  virtual bool collidesWith(double x, double y) = 0;
 
  virtual void writeMatlabDisplayCode(std::ostream &fs) = 0;

};

/**    Circle    **/

class Circle : public Obstacle
{

  protected:

    double radii;

  public:

    Circle(double x, double y, double r)
    {
      this -> Xc = x;
      this -> Yc = y;
      this -> radii = r;
    }

    ~Circle();

    bool collidesWith(double x, double y) // Looks if x and y is inside the circle
    {
      double dx = x - Xc; 
      double dy = y - Yc;
      return (sqrt(dx*dx+dy*dy) <= radii); 
    }

    void writeMatlabDisplayCode(std::ostream &fs) // Plots the circle in MATLAB
    {
      fs << "plot(" 
         << Xc << " + " << radii << "*cos((0:5:360)/180*pi),"
         << Yc << " + " << radii << "*sin((0:5:360)/180*pi))"
         << std::endl;
    }

};

/**    Rectangle    **/

/* In order to plot a rectange, we need to create two vectors in MATLAB.
   One of the vectors specifie the x-coordinates for all the rectangle corners,
   the other vector specifie the y-coordinates for all the rectangle corners.
   MATLAB can then draw lines between the points of the vectors, which results
   in a rectangle.

   In order to rotate it, the built in function "rotate" is used, which has the
   following inputs: ["object to be rotated","direction","degrees"]
*/

class Rectangle : public Obstacle
{

  protected:

    double W, H, A;

  public:

    Rectangle(double x, double y, double w, double h, double a)
    {
      this -> Xc = x;
      this -> Yc = y;
      this -> W = w;
      this -> H = h;
      this -> A = a;
    }

    ~Rectangle();

    bool collidesWith(double x, double y) // Looks if x and y is inside the rectangle
    {
      double dx = x - Xc;
      double dy = y - Yc;
      double dxx = dx * cos(A);
      double dyy = dy * sin(A);
      double dyx = dy * cos(A);
      double dxy = dx * sin(A);

      return ((std::abs(dxx-dyy)<W/2) & (std::abs(dyx+dxy)<H/2));
    }

    void writeMatlabDisplayCode(std::ostream &fs) // Plots the rectangle in MATLAB
    {

      double px1 = Xc - W/2;
      double px2 = Xc + W/2;
      double py1 = Yc - H/2;
      double py2 = Yc + H/2;
      double Ad = A * 180;

      fs << "rectangle = plot([" 
         << px1 << " " << px1 << " " << px2 << " " << px2 << " " << px1 << "] , ["
         << py1 << " " << py2 << " " << py2 << " " << py1 << " " << py1 << "]);"
         << std::endl
         << "rotate(rectangle,[0 0 1]," << Ad << "/pi,[" << Xc << " " << Yc << " 0]);"
         << std::endl;
    }


};








