#include <iostream>
#include <string.h>

using namespace std;

// registo del tipo que sera mi cola.
struct Node {
    string titulo;
    string cantante;
    string genero;
    int duracion;
    struct Node *next;
};
typedef struct Node node;

// Punteros que apuntan el primer y ultimo elemento de mi cola.
struct Queue {
    node *front;
    node *back;
};
typedef struct Queue queue;

//registrode inicio de sesion del usurio.
struct Sesion{
    string nombre;
    string correo;
    string contrasena;

};
typedef struct Sesion registro;

// Inicializa mi cola.
void initialize(queue *q) {
    q->front = NULL;
    q->back = NULL;
}

// Verifica si la cola esta vacia.
bool empty(queue *q) {
    return (q->front == NULL) ? true : false;
}

// Ingresa un elemennto a la cola.
void push(queue *q, string nombre, string autor, string genero,int tiempo) {
    node *newNode;
    newNode = new node;
    newNode->titulo = nombre;
    newNode->cantante = autor;
    newNode->genero = genero;
    newNode->duracion = tiempo;
    newNode->next = NULL;

    if(q->back == NULL) {
        q->front = newNode;
        q->back = newNode;
    }else {
        (q->back)->next = newNode;
        q->back = newNode;
    }    
}

// Elimina un elemento de la cola.
void pop(queue *q) {
    if(empty(q)) {
        cout << "Underflow" << endl;
        return;
    }
    node *aux = q->front;
    q->front = q->front->next;

    if(q->front == NULL) {
        q->back = NULL;
    }

    delete(aux);
}

// Funcion que imprime los elementos de la cola.
void showQueue(queue *q) {
    if(empty(q)) {
        cout << "\t\t\t\t\t\t\tLa cola esta vacia" << endl;
    }else {
        node *aux = q->front;
        while(aux) {
            cout << "\t\t\t\t\t\t\t[ "<<aux->titulo << " "<<aux->cantante<<" "<<aux->genero<<" "<<aux->duracion<<" "<<" ]";
            cout<<endl;
            aux = aux->next;
        }
    }
}

//funcion que elimina un elemento de la cola
void eliminar(queue *s){
    if(empty(s)){
        
        return;
    }else{
        pop(s);
        eliminar(s);
    }
    
}

//solicitud de datos del usuario para inicio de sesion
void inicio (registro *sesion){
    
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
        cout<<endl<<endl;

         cout << "\t\t\t\t\t\t\t\t\tBIENIDO A SPOTIFY ++"<<endl;

    cout << "\t\t\t\t\t\t\t\t\tIngrese el nombre de usurio: ";
    getline(cin, sesion->nombre);
    cout << "\t\t\t\t\t\t\t\t\tCorreo electronico: ";
    getline( cin, sesion->correo);
    cout << "\t\t\t\t\t\t\t\t\tContrasena: ";
    getline( cin, sesion->contrasena);
    cout<<endl<<endl;
    
}

//solicitud para aceptar terminos y condiciones del reproductor
void terminosycondiciones( bool * terminos){
    int opcion, status= true;

    cout << "\t\t\t\t\t\t\t\t\tTERMINOS Y CONDICIONES DE USO"<<endl;
    cout<<endl;
    cout << "\t\t\t\t\t\tEstos Terminos del Servicio reflejan la forma de trabajar de Spotify++ como empresa,"<<endl;
    cout << "\t\t\t\t\t\tlas leyes por las que nos regimos y determinados aspectos que siempre hemos creido"<<endl;
    cout << "\t\t\t\t\t\tque son ciertos. Por ello, estos Terminos del Servicio ayudan a definir la relacion"<<endl;
    cout << "\t\t\t\t\t\tque tiene Spotify++ contigo cuando interactuas con nuestros servicios. Por ejemplo,"<<endl;
    cout << "\t\t\t\t\t\testos terminos incluyen las siguientes secciones:"<<endl<<endl;
    cout << "\t\t\t\t\t\tSeguir leyendo ...."<<endl<<endl;
    cout << "\t\t\t\t\t\t\t\tACEPTAR=1\t\t\t\t\tRECHAZAR=2"<<endl<<endl<<endl;
    while (status)
    
    {
     cout << "\t\t\t\t\t\tIngrese la opcion a elegir:";
     cin>>opcion;
     cin.ignore();

     if (opcion == 1 )
     {
        *terminos = true;
        status = false;
     }else if (opcion == 2)
     {
         cout << "\t\t\t\t\t\tNo podra continuar sin haber acpetado los terminos."<<endl;
     }else{
          cout << "\t\t\t\t\t\tOpcion incorrecta, intente de nuevo."<<endl;
     }
     
     
    }

}

//menu de usurio.
void menu(queue *electronica, queue *regueton, queue *rap, queue *Pop,queue *salsa, queue *descargas) {

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
    

        cout << "\n" << "\t\t\t\t\t\t\t\t******* MENU DE USUARIO *******" << endl<<endl;
        cout << "\t\t\t\t\t\t\t1. Ingresar cancion a cola de reproduccion" << endl;
        cout << "\t\t\t\t\t\t\t2. Eliminar  cancion de la cola" << endl;
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
                cout<<"\t\t\t\t\t\t\tColas de reproduccion disponible: "<<endl;
                cout<<"\t\t\t\t\t\t\t1. Electronica"<<endl;
                cout<<"\t\t\t\t\t\t\t2. Regueton"<<endl;
                cout<<"\t\t\t\t\t\t\t3. Rap"<<endl;
                cout<<"\t\t\t\t\t\t\t4. Pop"<<endl;
                cout<<"\t\t\t\t\t\t\t5. Salsa"<<endl;
                cout<<"\t\t\t\t\t\t\t_____________________________________________________"<<endl;
                cout<<"\t\t\t\t\t\t\tIngrese el numero de la cola a la que se le agregara: ";
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

                        push(electronica,titulo,cantante,genero,duracion);



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

                        push(regueton,titulo,cantante,genero,duracion);

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

                        push(rap,titulo,cantante,genero,duracion);

                    }else if (optionCola == 4)
                    {
                        cout<<"Titulo: ";
                        getline(cin,titulo);
                        
                        cout<<"Cantante: ";
                        getline(cin,cantante);

                        cout<<"Genero: ";
                        getline(cin, genero );

                        cout<<"Duracion: ";
                        cin>>duracion;
                        cin.ignore();

                        push(Pop,titulo,cantante,genero,duracion);
                    }else if (optionCola == 4)
                    {
                        cout<<"Titulo: ";
                        getline(cin,titulo);
                        
                        cout<<"Cantante: ";
                        getline(cin,cantante);

                        cout<<"Genero: ";
                        getline(cin, genero );

                        cout<<"Duracion: ";
                        cin>>duracion;
                        cin.ignore();

                        push(salsa,titulo,cantante,genero,duracion);
                    }else
                    {
                        cout<<"Opcion incorrecta, intente de nuevo"<<endl;
                    }
              
               
                break;

            case 2:
                cout<<"\t\t\t\t\t\t\tColas de reproduccion disponible: "<<endl;
                cout<<"\t\t\t\t\t\t\t1. Electronica"<<endl;
                cout<<"\t\t\t\t\t\t\t2. Regueton"<<endl;
                cout<<"\t\t\t\t\t\t\t3. Rap"<<endl;
                cout<<"\t\t\t\t\t\t\t4. Pop"<<endl;
                cout<<"\t\t\t\t\t\t\t5. Salsa"<<endl;
                cout<<"\t\t\t\t\t\t\t_____________________________________________________"<<endl;
                cout<<"\t\t\t\t\t\t\tIngrese el numero de la cola a la que se eliminara la cancion: ";
                cin>>optionCola;
                cin.ignore();

                if(optionCola == 1){
                    pop(electronica);
                }else if(optionCola == 2){
                    pop(regueton);
                }else if(optionCola == 3){
                    pop(rap);
                }else if (optionCola == 4)
                {
                    pop(Pop);
                }else if (optionCola == 5)
                {
                    pop(salsa);
                }else
                {
                     cout<<"Opcion invalida, intente de nuevo"<<endl;
                }
                
                break;

            case 3:
                cout<<"\t\t\t\t\t\t\tColas de reproduccion disponible: "<<endl;
                cout<<"\t\t\t\t\t\t\t1. Electronica"<<endl;
                cout<<"\t\t\t\t\t\t\t2. Regueton"<<endl;
                cout<<"\t\t\t\t\t\t\t3. Rap"<<endl;
                cout<<"\t\t\t\t\t\t\t4. Pop"<<endl;
                cout<<"\t\t\t\t\t\t\t5. Salsa"<<endl;
                cout<<"\t\t\t\t\t\t\t_____________________________________________________"<<endl;
                cout<<"\t\t\t\t\t\t\tIngrese el numero de la cola que se vaciar: ";
                cin>>optionCola;
                cin.ignore();

                if(optionCola == 1){
                    eliminar(electronica);
                }else if(optionCola == 2){
                    eliminar(regueton);
                }else if(optionCola == 3){
                    eliminar(rap);
                }else if (optionCola == 4)
                {
                    eliminar(Pop);
                }else if (optionCola == 5)
                {
                    eliminar(salsa);
                
                }else{
                    cout<<"Opcion invalida intente de nuevo"<<endl;
                }
                
                break;
            case 4:
                cout<<"\t\t\t\t\t\t\tColas de reproduccion disponible: "<<endl;
                cout<<"\t\t\t\t\t\t\t1. Electronica"<<endl;
                cout<<"\t\t\t\t\t\t\t2. Regueton"<<endl;
                cout<<"\t\t\t\t\t\t\t3. Rap"<<endl;
                cout<<"\t\t\t\t\t\t\t4. Pop"<<endl;
                cout<<"\t\t\t\t\t\t\t5. Salsa"<<endl;
                cout<<"\t\t\t\t\t\t\t_____________________________________________________"<<endl;
                cout<<"\t\t\t\t\t\t\tIngrese el numero de la cola que desea visualizar: ";
                cin>>optionCola;
                cin.ignore();

                if(optionCola == 1){
                    showQueue(electronica);
                }else if(optionCola == 2){
                    showQueue(regueton);
                }else if(optionCola == 3){
                    showQueue(rap);
                }else if (optionCola == 4)
                {
                    showQueue(Pop);
                }else if (optionCola == 5)
                {
                    showQueue(salsa);
                
                }else{
                    cout<<"Opcion invalida intente de nuevo"<<endl;
                }

                break;

            case 5:
            cout << "\t\t\t\t\t\t\tIngrese los datos de la cancion a descargar: "<<endl;
                cout<<"\t\t\t\t\t\t\tTitulo: ";
                getline(cin,titulo);
                        
                cout<<"\t\t\t\t\t\t\tCantante: ";
                getline(cin,cantante);

                cout<<"\t\t\t\t\t\t\tGenero: ";
                getline(cin, genero );

                cout<<"\t\t\t\t\t\t\tDuracion: ";
                cin>>duracion;
                cin.ignore();

                push(descargas,titulo,cantante,genero,duracion);
                
                break;

            
            case  6:
                status = false;
                break;


            default:
                cout<<"Opcion invalida, intente nuevamente."<<endl;
               
                break;
        }
    } 
}

void musica(queue * electrinica, queue *regueton, queue *rap, queue *pop, queue *salsa){
    
    //llenado de cola de electronica
    push(electrinica,"Wake me up", "Avicii", "Electronica", 277);
    push(electrinica, "Animals", "Martin Garrix","Electronica", 191);
    push(electrinica, "Pushin", "Danny Avila", "Electronica", 149);
    push(electrinica, "Will not look back", "Duke Dumont","Electronica",237);
    push(electrinica, "Ignite", "Zedd", "Electronica", 226);
    push(electrinica, "One Touch", "Jess Glynne & Jax Jones", "Electronica",208);
    cout<<"https://www.youtube.com/watch?v=pCKDrDvaOKE"<<endl;
    


    //llenado de cola regueton
    push(regueton,"La Toxica", "Farruko","Regueton", 205);
    push(regueton,"Bellaquita", "Dalex","Regueton",208);



    //llenado de cola de rap
    push(rap,"Till I Collapse","Eminem","Rap",298);
    push(rap,"21 Questions ","50 Cent","Rap",258);


    //llenado de cola de pop
    push(pop,"Counting Stars","One Republic", "Pop",283);
    push(pop, "Rude","MAGIC!", "Pop",225);

    //llenado de cola de salsa
    push(salsa,"Conteo Regresivo", "Gilberto Santa Rosa","Salsa",267);
    push(salsa,"Valio la pena","Marc Anthony","Salsa",293);

}

