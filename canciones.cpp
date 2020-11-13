#include <iostream>
#include <conio.h>
#include <string.h>
#include "Funciones.hpp"

using namespace std;

void menu(queue *,queue *,queue *,queue *);

int main(){

    queue feliz, triste, estudiar, descargas;
    registro sesion;
    bool terminos = false;
    initialize(&feliz);
    initialize(&triste);
    initialize(&estudiar);
    initialize(&descargas);

    inicio(&sesion);
    
    terminosycondiciones(&terminos);

    if (terminos == true)
    {
        menu(&feliz,&triste,&estudiar,&descargas);
    }
    

    


    getch();
    return 0;
}

void menu(queue *feliz, queue *triste, queue *estudiar, queue *descargas) {

    string titulo,cantante, genero;
    int optionMenu=0, optionCola=0, duracion=0;
    bool status = true;
    node *newFeliz;

        cout << endl << endl << endl;
        cout << "\t\t\t\t\t\t\t**" << endl;
        cout << "\t\t\t\t\t\t\t*****" << endl;
        cout << "\t\t\t\t\t\t\t*******"<< endl;
        cout << "\t\t\t\t\t\t\t**********" << endl;
        cout << "\t\t\t\t\t\t\t*************              ____   __          _    __     __" << endl;
        cout << "\t\t\t\t\t\t\t***************           |    | |  |        / *   *  *  /  /  " << endl;
        cout << "\t\t\t\t\t\t\t******************        |  __| |  |       /   *   *  **  /" << endl;
        cout << "\t\t\t\t\t\t\t*********************     | |    |  |___   /  *  *   *    /" << endl;
        cout << "\t\t\t\t\t\t\t******************        |_|    |______| /_______*   |___|" << endl;
        cout << "\t\t\t\t\t\t\t***************" <<endl;
        cout << "\t\t\t\t\t\t\t*************" <<endl;
        cout << "\t\t\t\t\t\t\t**********" <<endl;
        cout << "\t\t\t\t\t\t\t*******" <<endl ;
        cout << "\t\t\t\t\t\t\t*****" <<endl;
        cout << "\t\t\t\t\t\t\t**" << endl;

    while (status) {
        // cout << endl << endl << endl;
        // cout << "\t\t\t\t\t\t\t**" << endl;
        // cout << "\t\t\t\t\t\t\t*****" << endl;
        // cout << "\t\t\t\t\t\t\t*******"<< endl;
        // cout << "\t\t\t\t\t\t\t**********" << endl;
        // cout << "\t\t\t\t\t\t\t*************              ____   __          _    __     __" << endl;
        // cout << "\t\t\t\t\t\t\t***************           |    | |  |        / *   *  *  /  /  " << endl;
        // cout << "\t\t\t\t\t\t\t******************        |  __| |  |       /   *   *  **  /" << endl;
        // cout << "\t\t\t\t\t\t\t*********************     | |    |  |___   /  *  *   *    /" << endl;
        // cout << "\t\t\t\t\t\t\t******************        |_|    |______| /_______*   |___|" << endl;
        // cout << "\t\t\t\t\t\t\t***************" <<endl;
        // cout << "\t\t\t\t\t\t\t*************" <<endl;
        // cout << "\t\t\t\t\t\t\t**********" <<endl;
        // cout << "\t\t\t\t\t\t\t*******" <<endl ;
        // cout << "\t\t\t\t\t\t\t*****" <<endl;
        // cout << "\t\t\t\t\t\t\t**" << endl;


        cout << "\n" << "\t\t\t\t\t\t\t\t***** MENU DE COLAS *****" << endl<<endl;
        cout << "\t\t\t\t\t\t\t1. Ingresar cancion a cola de reproduccion" << endl;
        cout << "\t\t\t\t\t\t\t2. Eliminar primera cancion de la cola" << endl;
        cout << "\t\t\t\t\t\t\t3. Vaciar cola de reproduccion" << endl;
        cout << "\t\t\t\t\t\t\t4. Mostrar cola de reproduccion" << endl;
        cout << "\t\t\t\t\t\t\t5. Agregar cancion a descargar" << endl;


        cout << "\t\t\t\t\t\t\t6. Salir del menu" << endl;
        cout<<"\t\t\t\t\t\t_________________________________________________________"<<endl;
        cout << "\n" << "\t\t\t\t\t\t\tIngrese la opcion que deseas ejectuar: ";
        cin >> optionMenu;
        cin.ignore();
        cout << "\n";

        switch (optionMenu) {
           
            case 1:
                cout<<"Colas de reproduccion disponible: "<<endl;
                cout<<"1. Happy Life"<<endl;
                cout<<"2. Sad Life"<<endl;
                cout<<"3. Reay to Study"<<endl;
                cout<<"_____________________________________________________"<<endl;
                cout<<"Ingrese el numero de la cola a la que se le agregara: ";
                cin>>optionCola;
                cin.ignore();

                    if (optionCola == 1){
                        cout<<"Titulo: ";
                        getline(cin,titulo);
                        
                        
                        
                        cout<<"Cantante: ";
                        getline(cin,cantante);

                        cout<<"Genero: ";
                        getline(cin, genero );

                        cout<<"Duracion: ";
                        cin>>duracion;
                        cin.ignore();

                        push(feliz,titulo,cantante,genero,duracion);



                    }else if (optionCola == 2){
                        cout<<"Titulo: ";
                        getline(cin,titulo);
                        
                        
                        
                        cout<<"Cantante: ";
                        getline(cin,cantante);

                        cout<<"Genero: ";
                        getline(cin, genero );

                        cout<<"Duracion: ";
                        cin>>duracion;
                        cin.ignore();

                        push(triste,titulo,cantante,genero,duracion);

                    }else if (optionCola == 3){
                        cout<<"Titulo: ";
                        getline(cin,titulo);
                        
                        
                        
                        cout<<"Cantante: ";
                        getline(cin,cantante);

                        cout<<"Genero: ";
                        getline(cin, genero );

                        cout<<"Duracion: ";
                        cin>>duracion;
                        cin.ignore();

                        push(feliz,titulo,cantante,genero,duracion);

                    }else 
                        cout<<"Opcion incorrecta, intente de nuevo"<<endl;
               
                break;

            case 2:
                cout<<"Colas de reproduccion disponible: "<<endl;
                cout<<"1. Happy Life"<<endl;
                cout<<"2. Sad Life"<<endl;
                cout<<"3. Reay to Study"<<endl;
                cout<<"_____________________________________________________"<<endl;
                cout<<"Ingrese el numero de la cola a la que se eliminara la cancion: ";
                cin>>optionCola;
                cin.ignore();

                if(optionCola == 1){
                    pop(feliz);
                }else if(optionCola == 2){
                    pop(triste);
                }else if(optionCola == 3){
                    pop(estudiar);
                }else
                {
                    cout<<"Opcion invalida, intente de nuevo"<<endl;
                }
                
                
                break;
            case 3:
                cout<<"Colas de reproduccion disponible: "<<endl;
                cout<<"1. Happy Life"<<endl;
                cout<<"2. Sad Life"<<endl;
                cout<<"3. Reay to Study"<<endl;
                cout<<"_____________________________________________________"<<endl;
                cout<<"Ingrese el numero de la cola que se vaciara: ";
                cin>>optionCola;
                cin.ignore();

                if(optionCola == 1){
                    eliminar(feliz);
                }else if(optionCola==2){
                    eliminar(triste);
                }else if(optionCola==3){
                    eliminar(estudiar);
                }else{
                    cout<<"Opcion invalida intente de nuevo"<<endl;
                }
                
                break;
            case 4:
                cout<<"Colas de reproduccion disponible: "<<endl;
                cout<<"1. Happy Life"<<endl;
                cout<<"2. Sad Life"<<endl;
                cout<<"3. Reay to Study"<<endl;
                cout<<"_____________________________________________________"<<endl;
                cout<<"Ingrese el numero de la cola que desea visualizar: ";
                cin>>optionCola;
                cin.ignore();

                if(optionCola==1){
                    showQueue(feliz);
                    cout<<endl;

                }else if(optionCola == 2){
                    showQueue(triste);
                    cout<<endl;

                }else if(optionCola==3){
                    showQueue(estudiar);
                    cout<<endl;
                }else{
                    cout<<"Opcion invalida, intente de nuevo"<<endl;

                }
                break;
            case 5:
                cout<<"Titulo: ";
                getline(cin,titulo);
                        
                cout<<"Cantante: ";
                getline(cin,cantante);

                cout<<"Genero: ";
                getline(cin, genero );

                cout<<"Duracion: ";
                cin>>duracion;
                cin.ignore();

                push(descargas,titulo,cantante,genero,duracion);
                
                break;
            
            // case 6:
            //     cout << "Ingrese el nombre de usurio: ";
            //     getline(cin, sesion->nombre);
            //     cout << "Correo electronico: ";
            //     getline( cin, sesion->correo);
            //     cout << "Contrasena: ";
            //     getline( cin, sesion->contrasena);

            //     cout << sesion->nombre <<" "<< sesion->correo<<endl; 

            
            case  6:
                status = false;
                break;


            default:
                cout<<"Opcion invalida, intente nuevamente."<<endl;
               
                break;
        }
    } 
}

