#include <iostream>
#include <windows.h>
#include <conio.h>
#include <string.h>
#include "Funciones.hpp"

using namespace std;

int main(){
    queue canciones;
    registro sesion;
    sesion.nombre = "Admin";
    sesion.contrasena = "12345";
    sesion.correo = "admin@gmail.com";
    cuentas.push_back(sesion);

    bool terminos = false, seguir=true;
    initialize(&canciones);
    musica(&canciones);
    // La variable seguir es para que vuelva a registrarse en el programa si cierra su sesion
    // pero si quiere iniciar sesion en otra cuenta pues esta la opcion 2
    while(seguir){
        inicio();
        terminosycondiciones(&terminos);

        if (terminos == true)
        {
            menu(&canciones, &seguir);
        }
    }
    
    system("cls");
    Sleep(100);
    return 0;
}

