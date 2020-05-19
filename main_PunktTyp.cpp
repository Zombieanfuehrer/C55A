#include <windows.h>
#include <memory>
#include <vector>

#include "PunktTyp.cpp"
#include "inc.h"
#include "funktion_allgemein.h"

int main (void) {

    char eingabe;
    unsigned int anzahl = 0;
    //Vektor an unique Pointern für die Objektzuweisungen anlegen.
    /*Ein Vektor (#include <vector>) ist quasi ein "Bereich also Array" den man Dynamisch verwalten kann, darum habe ich diesen auch verwendet,
      da man ja nicht weiß wie viele Objekte bzw. Koordinaten erstellt werden.
      Ein unique_ptr (#include <memory>) gehört zu den Smartpointern, wie der Name schon sagt kann dieser nicht an Funktionen übergeben werden,
      da er nur auf dem Stack ({}) gültig ist. Der Vorteil, er ruft den destructor automatisch auf, darum sollten in C++ Smart Pointer genutzt werden.*/
    vector<unique_ptr<PunktTyp>>C55A_Koordinaten;
 
    int Dateneingabe = 0;
    do{
        double WertEingabe;

        //Vektor um Speicherbereich erweitern
        C55A_Koordinaten.push_back(make_unique<PunktTyp>());  //Mit .push_back() wird der Vector um einen "Speicherslot" erhöht also kann man sich vorstellen Array[x+1]. 
        //X-Koordinate
        cout<<"Wert der X-Koordiante eingeben:"; 
        cin>>WertEingabe; while(getchar() != '\n');
        C55A_Koordinaten[Dateneingabe]->set_x(WertEingabe);
        //Y-Koordinate
        cout<<"Wert der Y-Koordiante eingeben:"; 
        cin>>WertEingabe; while(getchar() != '\n');
        C55A_Koordinaten[Dateneingabe]->set_y(WertEingabe);
        //Abfrage
        cout<<"Weiteres Objekt erstellen? [J/N] :";                   
        cin.get(eingabe);while(getchar() != '\n');            //cin.get() Ließt ein einzelnes Zeichen aus dem std::cin puffer ein (Wichtig um sich gegen bufferoverflows abzusichern).
    
        ++Dateneingabe;
    }while (eingabe != 'N' && eingabe != 'n');

    C55A_Koordinaten.shrink_to_fit();                         //.shrink_to_fit() Löscht die Speicherreservierungen des Vectors, man muss dazu erwähnen das der Vector .push_back() nicht nur den
                                                              //einen Slot reserviert hatte, sondern ein paar, da Speicherreservierung kostbar ist verwaltet der Vector im Hintergrund mehr Speicher
                                                              //und weist diesen dann zu. 
                                                              //Darum sollte man wirklich erst nach sicherstellung das kein weiter Speicher angelegt werden soll die .shrink_to_fit() Methode nutzen.

    for (int AusgabeWerte = 0; AusgabeWerte < C55A_Koordinaten.size(); ++AusgabeWerte)
    {
        cout<<"Werte Nr. "<<AusgabeWerte<<" X = "<<C55A_Koordinaten[AusgabeWerte]->get_x()<<" Y = "<<C55A_Koordinaten[AusgabeWerte]->get_y()<<endl;
    }
    double Groesster_Y = pmax_y(C55A_Koordinaten);            //Hier wird der Komplette Vector übergeben, siehe inc.h
    cout<<"Der hoechste >-Wert ist: "<<Groesster_Y<<endl;

    cout<<"Werte im gleichen Quadranten?"<<endl;
    
    PunktTyp Uebergabe = *C55A_Koordinaten[1];                //Da für die Methode pgleicherquadrant definiert wurde eine einzelne Klasse zu übergeben und kein Vector of unique_ptr erstelle ich eine 
                                                              //ein neues Objekt von der Klasse und kopiere die Werte aus dem Vector.
                                                              //Wichtige anmerkung: Es gibt eigentlich einen weiteren Konstruktor, den kopierkonstruktor. Eigentlich sollte man disen Aufrufen, aber die Klasse ist 
                                                              //noch gar nicht so weit (hehe, also wir als Klasse und PunktTyp.h)

    if (C55A_Koordinaten[0]->pgleicherquadrant(Uebergabe)){    
        cout<<"Gleicherquadrant, Hurra"<<endl;
    }
    else cout<<"Nicht im gleichen quadranten!"<<endl;
    system("PAUSE");
}
