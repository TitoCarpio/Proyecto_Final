#include <iostream>
#include <string.h>
#include <stack>

using namespace std;

// registo del tipo que sera mi cola.
struct Node {
    string titulo;
    string cantante;
    string genero;
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

stack<string> gener;

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
void push(queue *q, string nombre, string autor, string genero){
    node *newNode;
    newNode = new node;
    newNode->titulo = nombre;
    newNode->cantante = autor;
    newNode->genero = genero;
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
void showQueue(queue *q, string g) {
    if(empty(q)) {
        cout << "\t\t\t\t\t\t\tLa cola esta vacia" << endl;
    }else {
        node *aux = q->front;
        while(aux) {
            if(aux->genero == g){
                cout << "\t\t\t\t\t\t\t[ "<<aux->titulo << ", "<<aux->cantante<<", "<<aux->genero<<" ]";
                cout<<endl;
            }
            aux = aux->next;
        }
        cout<< "\t\t\t\t\t\t\t......\n";
    }
}

//funcion que elimina un elemento de la cola
void eliminar(queue *s, string g){
    // La funcion se ha cambiado para vaciar todas las canciones de un solo genero con un string
    // y de paso solo guarda las canciones de otros generos que no se deben borrar
    queue aux ;
    initialize(&aux);
    while(!empty(s)){
        if(s->front->genero == g){
            pop(s);
        }else{
            node* ayuda = s->front;
            string titu = ayuda->titulo, artista = ayuda->cantante, gen = ayuda->genero;
            push(&aux, titu, artista, gen);
            pop(s);
        }
    }
    while(!empty(&aux)){
        node* ayuda2 =  aux.front;
        string titu = ayuda2->titulo, artista = ayuda2->cantante, gen = ayuda2->genero;
        push(s, titu, artista, gen);
        pop(&aux);
    }
    /*if(empty(s)){
        return;
    }else{
        if(s->front->genero == g){
            pop(s);
            eliminar(s, g);
        }else{
            node *ayuda = s->front;
            pop(s);
            eliminar(s, g);
            string titu = ayuda->titulo, artista = ayuda->cantante, gen = ayuda->genero;
            int tiemp = ayuda->duracion;
            push(s, titu, artista, gen, tiemp);
        }
        return;
    }*/
}

// FUNCIONES CON PILAS, USANDO LIBRERIA STACK.
int MostrarGeneros(){ // Funcion que usa PILAS para mostrar los generos que tenga el usuario.
    stack<string> Aux = gener;
    int n=1;
    while(!Aux.empty()){
        string nombre = Aux.top();
        cout << "\t\t\t\t\t\t\t" << n << ". " << nombre << "\n";
        Aux.pop();
        n++;
    }
    return n;
}

void AgregarCancion(int opcion, queue *s){// funcion para agregar una cancion a cola
    stack<string> Aux = gener;
    for(int i=1; i < opcion; i++){
        Aux.pop();
    }
    string g = Aux.top(), titulo, cantante;
    int duracion=0;
    cout<<"\t\t\t\t\t\t\tTitulo: ";
    getline(cin,titulo);                 
    cout<<"\t\t\t\t\t\t\tCantante: ";
    getline(cin,cantante);

    push(s,titulo,cantante,g);
}

void EliminarCancion(int opcion, queue *s){// funcion para eliminar una cancion de cola
    stack<string> Aux = gener;
    queue aux ;
    initialize(&aux);
    for(int i=1; i<opcion; i++){
        Aux.pop();
    }
    string g = Aux.top();
    while(!empty(s)){
        if(s->front->genero == g){
            pop(s);
            break;
        }
        node* ayuda = s->front;
        string titu = ayuda->titulo, artista = ayuda->cantante, gen = ayuda->genero;
        push(&aux, titu, artista, gen);
        pop(s);
    }
    while(!empty(&aux)){
        node* ayuda2 =  aux.front;
        string titu = ayuda2->titulo, artista = ayuda2->cantante, gen = ayuda2->genero;
        push(s, titu, artista, gen);
        pop(&aux);
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
void menu(queue *canciones){

    string titulo,cantante, genero;
    int optionMenu=0, optionCola=0, duracion=0, maximo=0;
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
        cout << "\t\t\t\t\t\t\t1. Agregar otra cola de reproduccion" << endl;
        cout << "\t\t\t\t\t\t\t2. Ingresar cancion a cola de reproduccion" << endl;
        cout << "\t\t\t\t\t\t\t3. Eliminar  cancion de la cola" << endl;
        cout << "\t\t\t\t\t\t\t4. Vaciar cola de reproduccion" << endl;
        cout << "\t\t\t\t\t\t\t5. Mostrar cola de reproduccion" << endl;
        cout << "\t\t\t\t\t\t\t6. Agregar cancion a descargar" << endl;
        cout << "\t\t\t\t\t\t\t7. Salir del menu" << endl;
        cout<<"\t\t\t\t\t\t_________________________________________________________"<<endl;
        cout << "\n" << "\t\t\t\t\t\t\tIngrese la opcion que deseas ejectuar: ";
        cin >> optionMenu;
        cin.ignore();
        cout << "\n";

        switch (optionMenu) {
           
            case 1:
                cout<<"\t\t\t\t\t\t\tGenero de la cola a crear: ";
                getline(cin, genero);
                gener.push(genero);
                break;
            case 2:
                cout<<"\t\t\t\t\t\t\tColas de reproduccion disponible: "<<endl;
                maximo = MostrarGeneros();
                cout<<"\t\t\t\t\t\t\t_____________________________________________________"<<endl;
                cout<<"\t\t\t\t\t\t\tIngrese el numero de la cola a la que se le agregara: ";
                cin>>optionCola;
                cin.ignore();
                    if (optionCola>=1 && optionCola<maximo){
                        AgregarCancion(optionCola, canciones);
                    }else{
                        cout<<"Opcion incorrecta, intente de nuevo"<<endl;
                    }
                break;

            case 3:
                cout<<"\t\t\t\t\t\t\tColas de reproduccion disponible: "<<endl;
                maximo = MostrarGeneros();
                cout<<"\t\t\t\t\t\t\t_____________________________________________________"<<endl;
                cout<<"\t\t\t\t\t\t\tIngrese el numero de la cola a la que se eliminara la cancion: ";
                cin>>optionCola;
                
                if (optionCola >= 1 && optionCola < maximo){
                    EliminarCancion(optionCola, canciones);
                }else
                {
                    cout<<"Opcion invalida, intente de nuevo"<<endl;
                }
                
                break;

            case 4:
                cout<<"\t\t\t\t\t\t\tColas de reproduccion disponible: "<<endl;
                maximo = MostrarGeneros();
                cout<<"\t\t\t\t\t\t\t_____________________________________________________"<<endl;
                cout<<"\t\t\t\t\t\t\tIngrese el numero de la cola que se vaciar: ";
                cin>>optionCola;

                
                if (optionCola >= 1 && optionCola < maximo){
                    stack<string> Aux = gener;
                    for(int i=1; i< optionCola; i++){
                        Aux.pop();
                    }
                    string g = Aux.top();
                    eliminar(canciones, g);
                }else{
                    cout<<"Opcion invalida intente de nuevo"<<endl;
                }
                
                break;
            case 5:
                cout<<"\t\t\t\t\t\t\tColas de reproduccion disponible: "<<endl;
                maximo =MostrarGeneros();
                cout<<"\t\t\t\t\t\t\t_____________________________________________________"<<endl;
                cout<<"\t\t\t\t\t\t\tIngrese el numero de la cola que desea visualizar: ";
                cin>>optionCola;
                
                if (optionCola >= 1 && optionCola < maximo){
                    stack<string> aux = gener;
                    for(int i=1; i<optionCola; i++){
                        aux.pop();
                    }
                    string g = aux.top();
                    showQueue(canciones, g);
                }else{
                    cout<<"Opcion invalida intente de nuevo"<<endl;
                }
                break;
            case 6:
                cout<<"\t\t\t\t\t\t\tIngrese los datos de la cancion a descargar: "<<endl;
                cout<<"\t\t\t\t\t\t\tTitulo: ";
                getline(cin,titulo);
                        
                cout<<"\t\t\t\t\t\t\tCantante: ";
                getline(cin,cantante);

                cout<<"\t\t\t\t\t\t\tGenero: ";
                getline(cin, genero );

                push(canciones,titulo,cantante,genero);
                break;
            case  7:
                status = false;
                break;
            default:
                cout<<"Opcion invalida, intente nuevamente."<<endl;               
                break;
        }
    } 
}

void musica(queue * canciones){
    
    //llenado de cola de electronica
    gener.push("electronica");
    push(canciones,"Wake me up", "Avicii", "electronica");
    push(canciones, "Animals", "Martin Garrix","electronica");
    push(canciones, "Pushin", "Danny Avila", "electronica");
    push(canciones, "Will not look back", "Duke Dumont","electronica");
    push(canciones, "Ignite", "Zedd", "electronica");
    push(canciones, "One Touch", "Jess Glynne & Jax Jones", "electronica");
    push(canciones, "Floating", "Grenda", "electronica");
    push(canciones, "Sugar" , "Robin Schulz", "electonica");
    push(canciones, "Ocean Drive", "Duke Dumont","electronica");
    push(canciones, "Kangaroo Court", "Capital Cities", "electronica");

    //llenado de cola regueton
    gener.push("regueton");
    push(canciones,"La Toxica", "Farruko","regueton");
    push(canciones,"Bellaquita", "Dalex","regueton");



    //llenado de cola de canciones
    gener.push("rap");
    push(canciones,"Till I Collapse","Eminem","rap");
    push(canciones,"21 Questions ","50 Cent","rap");
    push(canciones,"Gangsta is paradise","Coolio", "rap");
    push(canciones,"Last breath", "Future", "rap");
    push(canciones, "Groupie Love", "A$ap rocky", "rap");
    push(canciones, "When i grow up","NF", "rap");
    push(canciones, "HUMBLE", "Kendrick Lamar", "rap");
    push(canciones, "See you again","Wiz Khalifa","rap");
    push(canciones, "Young, wild and free","Snoop Dogg", "rap");
    push(canciones, "canciones God ","Eminem","rap");


    //llenado de cola de canciones
    gener.push("pop");
    push(canciones,"Counting Stars","One Republic", "pop");
    push(canciones, "Rude","MAGIC!", "pop");
    push(canciones, "Angel of small", "Hozie", "pop");
    push(canciones, "Congratulations", "Post Malone", "pop");
    push(canciones, "Uptown Funk", "Mark Ronson", "pop");
    push(canciones, "Dance Monkey", "Tones and I", "pop");
    push(canciones, "Get Lucky", "Daft Punk", "pop");
    push(canciones, "Wonder", "Shawn Mendes" ,"pop");
    push(canciones, "How do you sleep" ,"Sam Smith" , "pop");
    push(canciones, "Hotline Bling"  , "Drake", "pop");

    //llenado de cola de salsa
    gener.push("salsa");
    push(canciones,"Conteo Regresivo", "Gilberto Santa Rosa","salsa");
    push(canciones,"Valio la pena","Marc Anthony","salsa");

}

