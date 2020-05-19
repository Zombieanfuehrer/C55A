#ifndef _PunktTyp_H_
#define _PunktTyp_H_
#include <iostream>
#include <cmath>

using namespace std;

class PunktTyp
{
private:

    double x_Koordiante, y_Koordinate;

public:

    PunktTyp();
    PunktTyp(const double value_x,const double value_y);
    ~PunktTyp();

    void print(void);
    bool scan(double& X, double& Y);
    double get_x(void);
    double get_y(void);
    void set_x(double& X); 
    void set_y(double& Y);

    bool pgleicherquadrant(class PunktTyp p1); 
    double UrAbstand(void);

};

#endif
