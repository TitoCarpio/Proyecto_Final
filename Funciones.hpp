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
//Variables globales
int seleccion=0;
int opcion2=0;
//Funciones extras
void letras();

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

void eliminarCola(int opcion){
    stack<string> aux;
    int i=1;
    while(!gener.empty() && i<opcion){
        string genero = gener.top();
        aux.push(genero);
        gener.pop();
        i++;
    }
    gener.pop();
    while(!aux.empty()){
        string genero = aux.top();
        gener.push(genero);
        aux.pop();
    }
    cout <<"\t\t\t\t\t\t\tCola eliminada con exito..."<<endl;
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
        cout << "\t\t\t\t\t\t\t1. Opciones de cola" << endl;
        cout << "\t\t\t\t\t\t\t2. Ingresar cancion a cola de reproduccion" << endl;
        cout << "\t\t\t\t\t\t\t3. Eliminar  cancion de la cola" << endl;
        cout << "\t\t\t\t\t\t\t4. Vaciar cola de reproduccion" << endl;
        cout << "\t\t\t\t\t\t\t5. Mostrar cola de reproduccion" << endl;
        cout << "\t\t\t\t\t\t\t6. Agregar cancion a descargar" << endl;
        cout << "\t\t\t\t\t\t\t7. Mostrar sugerencia de canciones" << endl;
        cout << "\t\t\t\t\t\t\t8. Salir del menu" << endl;
        cout<<"\t\t\t\t\t\t_________________________________________________________"<<endl;
        cout << "\n" << "\t\t\t\t\t\t\tIngrese la opcion que deseas ejectuar: ";
        cin >> optionMenu;
        cin.ignore();
        cout << "\n";

        switch (optionMenu) {
           
            case 1:
                cout << "\t\t\t\t\t\t\t1. Agregar una cola de reproduccion" << endl;
                cout << "\t\t\t\t\t\t\t2. Eliminar una cola de reproduccion" << endl;
                cout<<"\t\t\t\t\t\t\t_____________________________________________________"<<endl;
                cout<<"\t\t\t\t\t\t\tIngrese el numero de la opcion que desea ejecutar: ";
                cin >> optionCola; 
                cin.ignore();
                if(optionCola == 1){
                    cout<<"\n" << "\t\t\t\t\t\t\tGenero de la cola a crear: ";
                    getline(cin, genero);
                    gener.push(genero);
                }else if(optionCola == 2){
                    cout<<"\n" << "\t\t\t\t\t\t\tColas de reproduccion disponible: "<<endl;
                    maximo = MostrarGeneros();
                    cout<<"\t\t\t\t\t\t\t_____________________________________________________"<<endl;
                    cout<<"\t\t\t\t\t\t\tIngrese el numero de la cola a la que eliminara: ";
                    cin >> optionCola;
                    if(optionCola >= 1 && optionCola<maximo){
                        eliminarCola(optionCola);
                    }
                }else{
                    cout<<"Opcion Invalida, vuelva a intentarlo"<<endl;
                }
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
                letras();
                break;
            case 8:
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
void logito(){
  cout<<" \t\t\t\t\t\t\t_____________________________"<<endl;
  cout<<"\t\t\t\t\t\t\t _____________________________"<<endl;
  cout<<"\t\t\t\t\t\t\t||          **                ||"<<endl;
  cout<<"\t\t\t\t\t\t\t||          *  *              ||"<<endl;
  cout<<"\t\t\t\t\t\t\t||          *   *             ||"<<endl;
  cout<<"\t\t\t\t\t\t\t||          *     *           ||"<<endl;
  cout<<"\t\t\t\t\t\t\t||          *    *            ||"<<endl;
  cout<<"\t\t\t\t\t\t\t||          *  *              ||"<<endl;
  cout<<"\t\t\t\t\t\t\t||          **                ||"<<endl;
  cout<<"\t\t\t\t\t\t\t _____________________________"<<endl;
  cout<<"\t\t\t\t\t\t\t _____________________________"<<endl;
}
void letras(){
  logito();
  int opcion=0,opcion2=0;
  cout<<"\t\t\t\t\t\t\tSugerencias de generos disponibles; "<<endl;
  cout<<"\t\t\t\t\t\t\t1. Electronica"<<endl;
  cout<<"\t\t\t\t\t\t\t2. Regueton"<<endl;
  cout<<"\t\t\t\t\t\t\t3. Rap"<<endl;
  cout<<"\t\t\t\t\t\t\t4. Pop"<<endl;
  cout<<"\t\t\t\t\t\t\t5. Salsa"<<endl;
  cin>>opcion;
  if(opcion==1)
  {
    
    cout<<"\t\t\t\t\t\t\tElectronica"<<endl;
    cout<<"\t\t\t\t\t\t\t1] Wake me up            Avicii"<<endl;        cout<<"\t\t\t\t\t\t\t2] Animals               Martin Garrix"<<endl;
    cout<<"\t\t\t\t\t\t\t3] Pushin                Danny Avila"<<endl;   cout<<"\t\t\t\t\t\t\t4] Will not look back    Duke Dumont"<<endl;
    cout<<"\t\t\t\t\t\t\t5] Ignite                Zedd"<<endl;          cout<<"\t\t\t\t\t\t\t6] One Touch             Jess Glynne & Jax Jones"<<endl;
    cout<<"\t\t\t\t\t\t\t7] Pressure              Grenda"<<endl;        cout<<"\t\t\t\t\t\t\t8] Sugar                 Robin Schulz"<<endl;
    cout<<"\t\t\t\t\t\t\t9] Ocean Drive           Duke Dumont"<<endl;   cout<<"\t\t\t\t\t\t\t10]Kangaroo Court        Capital Cities"<<endl; cout<<endl<<endl;
    cout<<"\t\t\t\t\t\t\tEscoger unas de las canciones de su interes"<<endl;
    cin>>opcion2;
    switch(opcion2)
    {
      case 1:
      cout<<"1.Letra de la cancion"<<endl; cout<<"2.Detalles de la cancion"<<endl; cout<<"Seleccione una de las opciones"<<endl; cin>>seleccion;
      
      if(seleccion==1){
        cout<<"Indicaciones dar CTRL + clic sobre el link para poder acceder."<<endl;
        cout<<"https://www.youtube.com/watch?v=SsYXnH9lzCY"<<endl;
      }
      else{
        cout<<"Nombre de la cancion:  Wake me up \nArtista:Avicci \nPublicacion:2013 \nDimension:5Mb \nGenero:Electronica "<<endl;
      }
      break;
      case 2:
      cout<<"1.Letra de la cancion"<<endl; cout<<"2.Detalles de la cancion"<<endl; cout<<"Seleccione una de las opciones"<<endl; cin>>seleccion;
      
      if(seleccion==1){
        cout<<"Indicaciones dar CTRL + clic sobre el link para poder acceder."<<endl;
        cout<<"https://www.youtube.com/watch?v=3_aqe6CNa8w"<<endl;
      }
      else{
        cout<<"Nombre de la cancion:  Animals \nArtista:Martin Garrix \nPublicacion:2013 \nDimension:5.5Mb \nGenero:Electronica "<<endl;
      }
      break;
      case 3:
      cout<<"1.Letra de la cancion"<<endl; cout<<"2.Detalles de la cancion"<<endl; cout<<"Seleccione una de las opciones"<<endl; cin>>seleccion;
      
      if(seleccion==1){
        cout<<"Indicaciones dar CTRL + clic sobre el link para poder acceder."<<endl;
        cout<<"https://www.youtube.com/watch?v=l83hc5mYZQY"<<endl;
      }
      else{
        cout<<"Nombre de la cancion:  Pushing \nArtista:Danny Avila \nPublicacion:2020 \nDimension:7.5Mb \nGenero:Electronica "<<endl;
      }
      break;
      case 4:
      cout<<"1.Letra de la cancion"<<endl; cout<<"2.Detalles de la cancion"<<endl;cout<<"Escoger unas de las opciones:"<<endl; cin>>seleccion;
      if(seleccion==1){
        cout<<"Indicaciones:\nDar CTRL + clic sobre el link para poder acceder."<<endl;
        cout<<"https://www.youtube.com/watch?v=Z6I4Kc84MRs"<<endl;
      }
      else{
        cout<<"Nombre de la cancion:Will not look back  \nArtista: Duke Dumont  \nPublicacion:2014 \nDimension:4.5Mb \nGenero:Electronica "<<endl;
      }
      break;
      case 5:
      cout<<"1.Letra de la cancion"<<endl; cout<<"2.Detalles de la cancion"<<endl; 
      cout<<"Seleccione una de las opciones"<<endl; cin>>seleccion;
      
      if(seleccion==1){
        cout<<"Indicaciones:\nDar CTRL + clic sobre el link para poder acceder."<<endl;
        cout<<"https://www.youtube.com/watch?v=7GY7RyFINsA"<<endl;
      }
      else{
        cout<<"Nombre de la cancion:Ignite  \nArtista:Zedd  \nPublicacion:2016 \nDimension:6.5Mb \nGenero:Electronica "<<endl;
      }
      break;
      case 6:
      cout<<"1.Letra de la cancion"<<endl; cout<<"2.Detalles de la cancion"<<endl; cout<<"Seleccione una de las opciones"<<endl; cin>>seleccion;
      
      if(seleccion==1){
        cout<<"Indicaciones:\nDar CTRL + clic sobre el link para poder acceder."<<endl;
        cout<<"https://www.youtube.com/watch?v=YiDeezkO7m8"<<endl;
       
      }
      else{
        cout<<"Nombre de la cancion:One Touch \nArtista: Jess Glynne & Jax Jones \nPublicacion:2019 \nDimension:6.5Mb \nGenero:Electronica "<<endl;
      }
      break;
      case 7:
      cout<<"1.Letra de la cancion"<<endl; cout<<"2.Detalles de la cancion"<<endl; cout<<"Seleccione una de las opciones"<<endl; cin>>seleccion;
      
      if(seleccion==1){
        cout<<"Indicaciones:\nDar CTRL + clic sobre el link para poder acceder."<<endl;
        cout<<"https://www.youtube.com/watch?v=OuN03__MjkE"<<endl;
      }
      else{
        cout<<"Nombre de la cancion:Pressure \nArtista:Grenda  \nPublicacion:2018 \nDimension:6.5Mb \nGenero:Electronica "<<endl;
      }
      break;
      case 8:
       cout<<"1.Letra de la cancion"<<endl; cout<<"2.Detalles de la cancion"<<endl; cout<<"Seleccione una de las opciones"<<endl; cin>>seleccion;
       
      if(seleccion==1){
        cout<<"Indicaciones dar CTRL + clic sobre el link para poder acceder."<<endl;
        cout<<"https://www.youtube.com/watch?v=AY0W3bGGC1o"<<endl;
      }
      else{
        cout<<"Nombre de la cancion:Sugar \nArtista:Robin Shculz  \nPublicacion:2017 \nDimension:6.5Mb \nGenero:Electronica "<<endl;
      }
      break;
      case 9:
       cout<<"1.Letra de la cancion"<<endl; cout<<"2.Detalles de la cancion"<<endl; cout<<"Seleccione una de las opciones"<<endl; cin>>seleccion;
       
      if(seleccion==1){
        cout<<"Indicaciones dar CTRL + clic sobre el link para poder acceder."<<endl;
        cout<<"https://www.youtube.com/watch?v=7CdEfL-XrSk"<<endl;
      }
      else{
        cout<<"Nombre de la cancion:Sugar \nArtista:Robin Shculz  \nPublicacion:2017 \nDimension:6.5Mb \nGenero:Electronica "<<endl;
      }
      break;
      case 10:
       cout<<"1.Letra de la cancion"<<endl; cout<<"2.Detalles de la cancion"<<endl; cout<<"Seleccione una de las opciones"<<endl; cin>>seleccion;
        if(seleccion==1){
        cout<<"Indicaciones dar CTRL + clic sobre el link para poder acceder."<<endl;
        cout<<"https://www.youtube.com/watch?v=bR-QyB-YpWs"<<endl;
        }
        else{
        cout<<"\t\t\t\t\t\t\tNombre de la cancion:Kangaroo Court  \nArtista:Capital Cities \nPublicacion:2012 \nDimension:9.5Mb \nGenero:Electronica "<<endl;
        }
      break;
      default:
      cout<<"Opcion no valida "<<endl;
      break;
    }
  }else if(opcion==2)
  {
    cout<<"\t\t\t\t\t\t\tRegueton"<<endl;
    cout<<"\t\t\t\t\t\t\t1]La Toxica            Farruko"<<endl;         cout<<"\t\t\t\t\t\t\t2]Bellaquita           Dalex"<<endl;
    cout<<"\t\t\t\t\t\t\t3]Con Calma            Daddy Yankee"<<endl;    cout<<"\t\t\t\t\t\t\t4]Dakiti               Bad Bunny"<<endl;
    cout<<"\t\t\t\t\t\t\t5]Agua                 J Balvin"<<endl;        cout<<"\t\t\t\t\t\t\t6]La curiosidad        Jay Wheeler"<<endl;
    cout<<"\t\t\t\t\t\t\t7]Caramelo             Ozuna"<<endl;
    cout<<"\t\t\t\t\t\t\tSeleccionar una cancion que desee:"<<endl; cin>>opcion2;
    switch(opcion2)
    {
      case 1:
      cout<<"1.Letra de la cancion"<<endl; cout<<"2.Detalles de la cancion"<<endl; cout<<"Seleccione una de las opciones"<<endl; cin>>seleccion;
      
      if(seleccion==1){
        cout<<"Indicaciones dar CTRL + clic sobre el link para poder acceder."<<endl;
        cout<<"https://www.youtube.com/watch?v=amiBCue4l24"<<endl;
      }
      else{
        cout<<"Nombre de la cancion:  La Toxica \nArtista:Farruko\nPublicacion:2020 \nDimension:2Mb \nGenero:Regueton "<<endl;
      }
      break;
      case 2:
      cout<<"1.Letra de la cancion"<<endl; cout<<"2.Detalles de la cancion"<<endl; cout<<"Seleccione una de las opciones"<<endl; cin>>seleccion;
      
      if(seleccion==1){
        cout<<"Indicaciones dar CTRL + clic sobre el link para poder acceder."<<endl;
        cout<<"https://www.youtube.com/watch?v=g-VuXtNJLYI"<<endl;
      }
      else{
        cout<<"Nombre de la cancion:  Bellaquita \nArtista:Dalex \nPublicacion:2019 \nDimension:2.5Mb \nGenero:Regueton "<<endl;
      }
      break;
      case 3:
      cout<<"1.Letra de la cancion"<<endl; cout<<"2.Detalles de la cancion"<<endl; cout<<"Seleccione una de las opciones"<<endl; cin>>seleccion;
      
      if(seleccion==1){
        cout<<"Indicaciones dar CTRL + clic sobre el link para poder acceder."<<endl;
        cout<<"https://www.youtube.com/watch?v=bNTRIdraX8c"<<endl;
      }
      else{
        cout<<"Nombre de la cancion:Con calma \nArtista:Daddy Yankee \nPublicacion:2019 \nDimension:2.5Mb \nGenero:Reguenton "<<endl;
      }
      break;
      case 4:
      cout<<"1.Letra de la cancion"<<endl; cout<<"2.Detalles de la cancion"<<endl;cout<<"Escoger unas de las opciones:"<<endl; cin>>seleccion;
      if(seleccion==1){
        cout<<"Indicaciones:\nDar CTRL + clic sobre el link para poder acceder."<<endl;
        cout<<"https://www.youtube.com/watch?v=WsUFhSDKYPI"<<endl;
      }
      else{
        cout<<"Nombre de la cancion:Dakiti  \nArtista: Bad Bunny  \nPublicacion:2020 \nDimension:1.5Mb \nGenero:Reguenton"<<endl;
      }
      break;
      case 5:
      cout<<"1.Letra de la cancion"<<endl; cout<<"2.Detalles de la cancion"<<endl; 
      cout<<"Seleccione una de las opciones"<<endl; cin>>seleccion;
      
      if(seleccion==1){
        cout<<"Indicaciones:\nDar CTRL + clic sobre el link para poder acceder."<<endl;
        cout<<"https://www.youtube.com/watch?v=-dHaDByOqFg"<<endl;
      }
      else{
        cout<<"Nombre de la cancion:Agua  \nArtista:J Balvin \nPublicacion:2020 \nDimension:2.5Mb \nGenero:Reguenton "<<endl;
      }
      break;
      case 6:
      cout<<"1.Letra de la cancion"<<endl; cout<<"2.Detalles de la cancion"<<endl; cout<<"Seleccione una de las opciones"<<endl; cin>>seleccion;
      
      if(seleccion==1){
        cout<<"Indicaciones:\nDar CTRL + clic sobre el link para poder acceder."<<endl;
        cout<<"https://www.youtube.com/watch?v=gfMi-MEdWZU"<<endl;
       
      }
      else{
        cout<<"Nombre de la cancion:La curiosidad \nArtista: Jay Wheeler \nPublicacion:2020 \nDimension:2.5Mb \nGenero:Reguenton "<<endl;
      }
      break;
      case 7:
      cout<<"1.Letra de la cancion"<<endl; cout<<"2.Detalles de la cancion"<<endl; cout<<"Seleccione una de las opciones"<<endl; cin>>seleccion;
      
      if(seleccion==1){
        cout<<"Indicaciones:\nDar CTRL + clic sobre el link para poder acceder."<<endl;
        cout<<"https://www.youtube.com/watch?v=wynf-I-k8es"<<endl;
      }
      else{
        cout<<"Nombre de la cancion:Caramelo \nArtista:Ozuna  \nPublicacion:2020 \nDimension:1.1Mb \nGenero:Electronica "<<endl;
      }
      break;
      default:
      cout<<"Opcion no valida "<<endl;
      break;
    }
  }else if(opcion==3)
  {
    cout<<"\t\t\t\t\t\t\tRap"<<endl; 
    cout<<"\t\t\t\t\t\t\t1]Till I Collapse       Eminem"<<endl;       cout<<"\t\t\t\t\t\t\t2]21 Questions          50 Cent"<<endl;
    cout<<"\t\t\t\t\t\t\t3]Gangsta is paradise   Coolio"<<endl;       cout<<"\t\t\t\t\t\t\t4]Last breath           Future"<<endl;
    cout<<"\t\t\t\t\t\t\t5]Groupie Love          A$ap rocky"<<endl;   cout<<"\t\t\t\t\t\t\t6]When i grow up        NF"<<endl;
    cout<<"\t\t\t\t\t\t\t7]HUMBLE                Kendrick L."<<endl;  cout<<"\t\t\t\t\t\t\t8]See you again         Wiz Khalifa"<<endl;
    cout<<"\t\t\t\t\t\t\t9]Young, wild and free  Snoop Dogg"<<endl;   cout<<"\t\t\t\t\t\t\t10]Rap God              Eminem"<<endl;
    
    cout<<endl; 
    cout<<"\t\t\t\t\t\t\tEscoger una cancion que desee"<<endl; cin>>opcion2;
    switch(opcion2)
    {
      case 1:
      cout<<"1.Letra de la cancion"<<endl; cout<<"2.Detalles de la cancion"<<endl; cout<<"Seleccione una de las opciones"<<endl; cin>>seleccion;
      
      if(seleccion==1){
        cout<<"Indicaciones dar CTRL + clic sobre el link para poder acceder."<<endl;
        cout<<"https://www.youtube.com/watch?v=gLMo7_VXU_s"<<endl;
      }
      else{
        cout<<"\t\t\t\t\t\t\tNombre de la cancion:Till I Collapse   \nArtista:Eminem \nPublicacion:2002 \nDimension:7Mb \nGenero:Rap "<<endl;
      }
      break;
      case 2:
      cout<<"1.Letra de la cancion"<<endl; cout<<"2.Detalles de la cancion"<<endl; cout<<"Seleccione una de las opciones"<<endl; cin>>seleccion;
      
      if(seleccion==1){
        cout<<"Indicaciones dar CTRL + clic sobre el link para poder acceder."<<endl;
        cout<<"https://www.youtube.com/watch?v=gb8Z7bTcLNo"<<endl;
      }
      else{
        cout<<"Nombre de la cancion:  21 Questions \nArtista:50 Cents\nPublicacion:2003 \nDimension:7.5Mb \nGenero:Rap "<<endl;
      }
      break;
      case 3:
      cout<<"1.Letra de la cancion"<<endl; cout<<"2.Detalles de la cancion"<<endl; cout<<"Seleccione una de las opciones"<<endl; cin>>seleccion;
      
      if(seleccion==1){
        cout<<"Indicaciones dar CTRL + clic sobre el link para poder acceder."<<endl;
        cout<<"https://www.youtube.com/watch?v=p9RtKPyAFZQ"<<endl;
      }
      else{
        cout<<"Nombre de la cancion:Gangsta paradise \nArtista:Coolio \nPublicacion:2010 \nDimension:7.5Mb \nGenero:Rap  "<<endl;
      }
      break;
      case 4:
      cout<<"1.Letra de la cancion"<<endl; cout<<"2.Detalles de la cancion"<<endl;cout<<"Escoger unas de las opciones:"<<endl; cin>>seleccion;
      if(seleccion==1){
        cout<<"Indicaciones:\nDar CTRL + clic sobre el link para poder acceder."<<endl;
        cout<<"https://www.youtube.com/watch?v=UeYQ49F3fnI"<<endl;
      }
      else{
        cout<<"Nombre de la cancion:Last breath \nArtista: Future \nPublicacion:2015 \nDimension:7.5Mb \nGenero:Rap  "<<endl;
      }
      break;
      case 5:
      cout<<"1.Letra de la cancion"<<endl; cout<<"2.Detalles de la cancion"<<endl; 
      cout<<"Seleccione una de las opciones"<<endl; cin>>seleccion;
      
      if(seleccion==1){
        cout<<"Indicaciones:\nDar CTRL + clic sobre el link para poder acceder."<<endl;
        cout<<"https://www.youtube.com/watch?v=U7aFg4HBx5o"<<endl;
      }
      else{
        cout<<"Nombre de la cancion:Groupie Love  \nArtista:A$ap rocky  \nPublicacion:2016 \nDimension:6.5Mb \nGenero:Rap "<<endl;
      }
      break;
      case 6:
      cout<<"1.Letra de la cancion"<<endl; cout<<"2.Detalles de la cancion"<<endl; cout<<"Seleccione una de las opciones"<<endl; cin>>seleccion;
      
      if(seleccion==1){
        cout<<"Indicaciones:\nDar CTRL + clic sobre el link para poder acceder."<<endl;
        cout<<"https://www.youtube.com/watch?v=xUM7FqUMCy0"<<endl;
      }
      else{
        cout<<"Nombre de la cancion:When i grow up  \nArtista:NF \nPublicacion:2019 \nDimension:7.5Mb \nGenero:Rap "<<endl;
      }
      break;
      case 7:
      cout<<"1.Letra de la cancion"<<endl; cout<<"2.Detalles de la cancion"<<endl; cout<<"Seleccione una de las opciones"<<endl; cin>>seleccion;
      
      if(seleccion==1){
        cout<<"Indicaciones:\nDar CTRL + clic sobre el link para poder acceder."<<endl;
        cout<<"https://www.youtube.com/watch?v=QzuIvNOeb8A&has_verified=1"<<endl;
      }
      else{
        cout<<"Nombre de la cancion:HUMBLE    \nArtista:Kendrick Lamar   \nPublicacion:2018 \nDimension:6.5Mb \nGenero:Rap  "<<endl;
      }
      break;
      case 8:
       cout<<"1.Letra de la cancion"<<endl; cout<<"2.Detalles de la cancion"<<endl; cout<<"Seleccione una de las opciones"<<endl; cin>>seleccion;
       
      if(seleccion==1){
        cout<<"Indicaciones dar CTRL + clic sobre el link para poder acceder."<<endl;
        cout<<"https://www.youtube.com/watch?v=fZsCg4mz364"<<endl;
      }
      else{
        cout<<"Nombre de la cancion:See you agian \nArtista:Wiz Khalifa \nPublicacion:2017 \nDimension:6.8Mb \nGenero:Rap  "<<endl;
      }
      break;
      case 9:
       cout<<"1.Letra de la cancion"<<endl; cout<<"2.Detalles de la cancion"<<endl; cout<<"Seleccione una de las opciones"<<endl; cin>>seleccion;
       
      if(seleccion==1){
        cout<<"Indicaciones dar CTRL + clic sobre el link para poder acceder."<<endl;
        cout<<"https://www.youtube.com/watch?v=J_r1ydhbN_g"<<endl;
      }
      else{
        cout<<"Nombre de la cancion:Young, wild and free \nArtista:Snoop Dog \nPublicacion:2017 \nDimension:7.5Mb \nGenero:Rap  "<<endl;
      }
      break;
      case 10:
       cout<<"1.Letra de la cancion"<<endl; cout<<"2.Detalles de la cancion"<<endl; cout<<"Seleccione una de las opciones"<<endl; cin>>seleccion;
        if(seleccion==1){
        cout<<"Indicaciones dar CTRL + clic sobre el link para poder acceder."<<endl;
        cout<<"https://www.youtube.com/watch?v=OCFshtUqM9E"<<endl;
        }
        else{
        cout<<"\t\t\t\t\t\t\tNombre de la cancion:Rap God  \nArtista:Eminem\nPublicacion:2013 \nDimension:9.5Mb \nGenero:Rap  "<<endl;
        }
      break;
      default:
      cout<<"Opcion no valida "<<endl;
      break;
    }
  }
  else if(opcion==4)
  {
    cout<<"\t\t\t\t\t\t\tPop"<<endl;
    cout<<"\t\t\t\t\t\t\t1]Counting Stars         One Republic"<<endl;  cout<<"\t\t\t\t\t\t\t2]Rude                   MAGIC!"<<endl;
    cout<<"\t\t\t\t\t\t\t3]Angel of small         Hozie"<<endl;         cout<<"\t\t\t\t\t\t\t4]Congratulations        Post Malone"<<endl;
    cout<<"\t\t\t\t\t\t\t5]Uptown Funk            Mark Ronson"<<endl;   cout<<"\t\t\t\t\t\t\t6]Dance Monkey           Tones and I"<<endl;
    cout<<"\t\t\t\t\t\t\t7]Get Lucky              Daft Punk"<<endl;     cout<<"\t\t\t\t\t\t\t8]Wonder                 Shawn Mendes"<<endl;
    cout<<"\t\t\t\t\t\t\t9]How do you sleep       Sam Smith"<<endl;     cout<<"\t\t\t\t\t\t\t10]Hotline Bling         Drake"<<endl<<endl;
    cout<<"Escoger una cancion que desee: "<<endl;
    cin>>opcion2;
    switch(opcion2)
    {
      case 1:
      cout<<"1.Letra de la cancion"<<endl; cout<<"2.Detalles de la cancion"<<endl; cout<<"Seleccione una de las opciones"<<endl; cin>>seleccion;
      
      if(seleccion==1){
        cout<<"Indicaciones dar CTRL + clic sobre el link para poder acceder."<<endl;
        cout<<"https://www.youtube.com/watch?v=Yim4--J44gk"<<endl;
      }
      else{
        cout<<"Nombre de la cancion: Counting Stars    \nArtista:One Republic \nPublicacion:2013 \nDimension:4.6Mb \nGenero:Pop "<<endl;
      }
      break;
      case 2:
      cout<<"1.Letra de la cancion"<<endl; cout<<"2.Detalles de la cancion"<<endl; cout<<"Seleccione una de las opciones"<<endl; cin>>seleccion;
      
      if(seleccion==1){
        cout<<"Indicaciones dar CTRL + clic sobre el link para poder acceder."<<endl;
        cout<<"https://www.youtube.com/watch?v=IlwIcTsmERw"<<endl;
      }
      else{
        cout<<"Nombre de la cancion:Rude  \nArtista:MAGIC!  \nPublicacion:2014 \nDimension:5.5Mb \nGenero:Pop "<<endl;
      }
      break;
      case 3:
      cout<<"1.Letra de la cancion"<<endl; cout<<"2.Detalles de la cancion"<<endl; cout<<"Seleccione una de las opciones"<<endl; cin>>seleccion;
      
      if(seleccion==1){
        cout<<"Indicaciones dar CTRL + clic sobre el link para poder acceder."<<endl;
        cout<<"https://www.youtube.com/watch?v=6mUDEBjFgm4"<<endl;
      }
      else{
        cout<<"Nombre de la cancion:Angel of small     \nArtista:Hozie \nPublicacion:2014 \nDimension:7.5Mb \nGenero:Pop "<<endl;
      }
      break;
      case 4:
      cout<<"1.Letra de la cancion"<<endl; cout<<"2.Detalles de la cancion"<<endl;cout<<"Escoger unas de las opciones:"<<endl; cin>>seleccion;
      if(seleccion==1){
        cout<<"Indicaciones:\nDar CTRL + clic sobre el link para poder acceder."<<endl;
        cout<<"https://www.youtube.com/watch?v=H6R2WRYyI08"<<endl;
      }
      else{
        cout<<"Nombre de la cancion:Congratulations  \nArtista: Post Malone \nPublicacion:2016 \nDimension:4.5Mb \nGenero:Pop"<<endl;
      }
      break;
      case 5:
      cout<<"1.Letra de la cancion"<<endl; cout<<"2.Detalles de la cancion"<<endl; 
      cout<<"Seleccione una de las opciones"<<endl; cin>>seleccion;
      
      if(seleccion==1){
        cout<<"Indicaciones:\nDar CTRL + clic sobre el link para poder acceder."<<endl;
        cout<<"https://www.youtube.com/watch?v=CeYuFSBkkVw"<<endl;
      }
      else{
        cout<<"Nombre de la cancion:Uptown Funk  \nArtista:Mark Ronson  \nPublicacion:2014 \nDimension:6.5Mb \nGenero:Pop "<<endl;
      }
      break;
      case 6:
      cout<<"1.Letra de la cancion"<<endl; cout<<"2.Detalles de la cancion"<<endl; cout<<"Seleccione una de las opciones"<<endl; cin>>seleccion;

      if(seleccion==1){
        cout<<"Indicaciones:\nDar CTRL + clic sobre el link para poder acceder."<<endl;
        cout<<"https://www.youtube.com/watch?v=1__CAdTJ5JU"<<endl;
      }
      else{
        cout<<"Nombre de la cancion: Dance Monkey   \nArtista:Tones and I \nPublicacion:2019 \nDimension:6.5Mb \nGenero:Pop "<<endl;
      }
      break;
      case 7:
      cout<<"1.Letra de la cancion"<<endl; cout<<"2.Detalles de la cancion"<<endl; cout<<"Seleccione una de las opciones"<<endl; cin>>seleccion;
      
      if(seleccion==1){
        cout<<"Indicaciones:\nDar CTRL + clic sobre el link para poder acceder."<<endl;
        cout<<"https://www.youtube.com/watch?v=5glDAaCaazc"<<endl;
      }
      else{
        cout<<"Nombre de la cancion:Get Lucky \nArtista:Daft Punk \nPublicacion:2013 \nDimension:6.5Mb \nGenero:Pop "<<endl;
      }
      break;
      case 8:
       cout<<"1.Letra de la cancion"<<endl; cout<<"2.Detalles de la cancion"<<endl; cout<<"Seleccione una de las opciones"<<endl; cin>>seleccion;
       
      if(seleccion==1){
        cout<<"Indicaciones dar CTRL + clic sobre el link para poder acceder."<<endl;
        cout<<"https://www.youtube.com/watch?v=T09bJIU9JP0"<<endl;
      }
      else{
        cout<<"Nombre de la cancion:Wonder   \nArtista:Shawn Mendes  \nPublicacion:2015 \nDimension:6.5Mb \nGenero:Pop "<<endl;
      }
      break;
      case 9:
       cout<<"1.Letra de la cancion"<<endl; cout<<"2.Detalles de la cancion"<<endl; cout<<"Seleccione una de las opciones"<<endl; cin>>seleccion;
       
      if(seleccion==1){
        cout<<"Indicaciones dar CTRL + clic sobre el link para poder acceder."<<endl;
        cout<<"https://www.youtube.com/watch?v=PmYypVozQb4"<<endl;
      }
      else{
        cout<<"Nombre de la cancion:How do you sleep  \nArtista:Sam Smith  \nPublicacion:2019 \nDimension:6.5Mb \nGenero:Pop "<<endl;
      }
      break;
      case 10:
       cout<<"1.Letra de la cancion"<<endl; cout<<"2.Detalles de la cancion"<<endl; cout<<"Seleccione una de las opciones"<<endl; cin>>seleccion;
        if(seleccion==1){
        cout<<"Indicaciones dar CTRL + clic sobre el link para poder acceder."<<endl;
        cout<<"https://www.youtube.com/watch?v=uJtaKS1ARoE"<<endl;
        }
        else{
        cout<<"\t\t\t\t\t\t\tNombre de la cancion:Hotline Bling         \nArtista:Drake \nPublicacion:2015 \nDimension:9.5Mb \nGenero:Pop "<<endl;
        }
      break;
      default:
      cout<<"Opcion no valida "<<endl;
      break;
    }
  } 
}
