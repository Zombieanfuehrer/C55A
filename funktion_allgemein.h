#ifndef _funktion_allgemein_H_
#define _funktion_allgemein_H_

double pmax_y(vector<unique_ptr<PunktTyp>> &punktArray){
    double erg = 0.0;
    cout<<"Groesse der Y-Koordinaten wird ausgewertet"<<endl;
    cout<<punktArray.size()<<endl;
    for (unsigned int index = 0; index < punktArray.size(); index++)
    {
        cout<<"In Auswertung ["<<index<<"] "<<"Wert X: "<<punktArray[index]->get_x()<<" Wert Y: "<<punktArray[index]->get_y()<<endl;
        if (punktArray[index]->get_y() > erg)
        {
            erg = punktArray[index]->get_y(); 
        }
    }
        return erg;
}
#endif
