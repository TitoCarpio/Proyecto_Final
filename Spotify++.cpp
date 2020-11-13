#include <iostream>
#include <conio.h>
#include <string.h>
#include "Funciones.hpp"

using namespace std;

void menu(queue *,queue *,queue *,queue *);

int main(){

    queue electronica, regueton, rap, pop, salsa, descargas;
    registro sesion;
    bool terminos = false;
    initialize(&electronica);
    initialize(&rap);
    initialize(&regueton);
    initialize(&pop);
    initialize(&salsa);
    initialize(&descargas);

    inicio(&sesion);
    
    terminosycondiciones(&terminos);
    musica(&electronica,&regueton,&rap,&pop,&salsa);

    if (terminos == true)
    {
        menu(&electronica,&regueton,&rap,&pop,&salsa,&descargas);
    }
    

    


    getch();
    return 0;
}

