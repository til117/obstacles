#include "Obstacle.cc"
#include "World.hh"

#include <fstream>
#include <string>
#include <iostream>
#include <cmath>
#include <list>

using namespace std;

class MyWorld : public World
{
  private:

    std::list<Obstacle*> obslist;

  public:

    MyWorld() {}; 

    bool readObstacles(std::istream &fs) 
    {
      std::string type; 
      double cvar[3];
      double rvar[5];
      while(fs >> type)
      {  

        if (type == "CIRCLE")
        {  
	  fs >> cvar[0] >> cvar[1] >> cvar[2];

	  obslist.push_back(new Circle(cvar[0],cvar[1],cvar[2]));
        }

        else if (type=="RECTANGLE")
        { 
	  fs >> rvar[0] >> rvar[1] >> rvar[2] >> rvar[3] >> rvar[4];

	  obslist.push_back(new Rectangle(rvar[0],rvar[1],rvar[2],rvar[3],rvar[4]));
        }

        else{
	  return false; 
        }
      }
      return true;
    }

    void writeMatlabDisplayCode(std::ostream &fs)
    { 
      for (list<Obstacle*>::iterator it=obslist.begin(); it!=obslist.end(); it++)
      {
        (*it)->writeMatlabDisplayCode(fs);
      }
    }

    bool collidesWith(double x, double y)
    {
      for (list<Obstacle*>::iterator it=obslist.begin(); it!=obslist.end(); it++)
      {
        if ((*it)->collidesWith(x,y))
        {
	  return true;
        }  
      }
      return false;
    }
};
