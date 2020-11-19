#include <iostream>
#include <windows.h>
#include <conio.h>
#include <string.h>
#include "Funciones.hpp"

using namespace std;


int main(){

    queue canciones;
    registro sesion;
    bool terminos = false;
    initialize(&canciones);

    inicio(&sesion);
    
    terminosycondiciones(&terminos);
    musica(&canciones);

    if (terminos == true)
    {
        menu(&canciones);
    }
    
    Sleep(100);
    return 0;
}

