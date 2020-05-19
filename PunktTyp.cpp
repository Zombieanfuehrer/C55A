#include "PunktTyp.h"

//Konstruktordefinitionen
/*-----------------------------------------------------------------*/
//Default Konstruktor
PunktTyp::PunktTyp(void){

    this->x_Koordiante = 0;
    this->y_Koordinate = 0;
}
/*-----------------------------------------------------------------*/
//Konstruktor 1:
PunktTyp::PunktTyp(const double value_x,const double value_y){

    this->x_Koordiante = value_x;
    this->y_Koordinate = value_y;
}
/*-----------------------------------------------------------------*/
//Desructor:
PunktTyp::~PunktTyp(){
}
/*-----------------------------------------------------------------*/
//Methodendefinitionen
/*-----------------------------------------------------------------*/
    void PunktTyp::print (void){
        cout<<"x= "<<x_Koordiante<<", y= "<<y_Koordinate<<endl;
    }

    bool PunktTyp::scan (double& X, double& Y){   
        cout<<"Geben Sie den Wert für die X-Koordinate ein:";
        cin>>X;
        cout<<endl<<"Geben Sie den Wert für die X-Koordinate ein:";
        cin>>Y;
        cout<<endl; 
        return true;   
    }

    double PunktTyp::get_x(void){return this->x_Koordiante;}
    double PunktTyp:: get_y(void){return this->y_Koordinate;}

    void PunktTyp::set_x(double& X){ this->x_Koordiante = X;}    
    void PunktTyp::set_y(double& Y){ this->y_Koordinate = Y;} 

    bool PunktTyp::pgleicherquadrant(class PunktTyp p1){
        
        if (((this->x_Koordiante < 0 && p1.x_Koordiante < 0) && (this->y_Koordinate >= 0 && p1.y_Koordinate >= 0))
           ||
           ((this->x_Koordiante >= 0 && p1.x_Koordiante >= 0) && (this->y_Koordinate < 0 && p1.y_Koordinate < 0)))
        {
            return true;
        }
        else return false;     
    } 

    double PunktTyp::UrAbstand(void){return(sqrt((this->x_Koordiante*this->x_Koordiante)+(this->y_Koordinate*this->y_Koordinate)));}
