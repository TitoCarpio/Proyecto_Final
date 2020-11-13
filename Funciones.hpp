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

// Ingresa un elemennto a mi cola.
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

// Elimina un elemento de mi cola.
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

// Funcion que imprime los elementos de mi cola.
void showQueue(queue *q) {
    if(empty(q)) {
        cout << "La cola esta vacia" << endl;
    }else {
        node *aux = q->front;
        while(aux) {
            cout << "[ "<<aux->titulo << " "<<aux->cantante<<" "<<aux->genero<<" "<<aux->duracion<<" "<<" ]";

            aux = aux->next;
        }
    }
}


void eliminar(queue *s){
    if(empty(s)){
        
        return;
    }else{
        pop(s);
        eliminar(s);
    }
    
}

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

