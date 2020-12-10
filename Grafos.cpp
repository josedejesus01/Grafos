#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;

//se declaran las variables globales
int opc;
int volver;
int valor;

//se declaran las funciones


//se va a declarar los  nodo que tendra el numero entero y dos punteros 
struct nodo{
	int numero;//se declara el nombre del vertice o nodo
	struct nodo *sgte;
	struct arista *ady;//el puntero que va hacia la primera arista del nodo
	
	
};
//instanciamos++
// el nodo y se crea una variable punteros 
typedef struct nodo *Tnodo;
Tnodo puntero;//se declara el puntero cabeza o el principal

//se declaran arista que tiene el nodo destino y la arista siguiente 
struct arista {
	struct nodo *destino;
	struct arista *sgte;
	
};
// se inserta las arista 
typedef struct arista *Tarista;

//se declara un metodo para capturar e insertar un nuevo nodo al grafo
void insertar_nodo (){
	//se instancia el nodo y declara un nuevo puntero
	Tnodo t,nuevo=new struct nodo;
	cout<<"ingrese un numero para el nodo: "<<endl;
	//captura el nuevo nodo que fue ingresado
	cin>>nuevo->numero;
	nuevo->sgte=NULL;
	nuevo->ady=NULL;
	//si el puntero esta vacio se crea
	if(puntero==NULL){
		puntero=nuevo;
		cout<<"Nodo ingresado."<<endl;
	}else{
		//si no se cumple la condicon recorre el puntero para pedir datos
		//por la variable siguiente que este vacia 
		t=puntero;
		while (t->sgte!=NULL){
		    t = t->sgte;
		}
		t->sgte=nuevo;
		cout<<"Nodo ingresado."<<endl;    
	}	
}
//se crea un metodo para agregar las aristas
void agregar_arista (Tnodo &aux, Tnodo &aux2, Tarista &nuevo){
	//con el puntero de la arista se inicializa otro puntero
	Tarista q;
	//se pide al usuario  si esta vacia para ingresar la nueva arista 
	if (aux->ady==NULL){
		aux->ady=nuevo;
		nuevo->destino=aux2;
	}else{
		//de lo contrario se debe  recorrer, por que ya hay arista en esa posicion
		q=aux->ady;
		//se rrecorre la lista  
		while (q->sgte!=NULL){
			q=q->sgte;
		}
		//cuando se encuentra sin ningun dato se ingresa la arista
		nuevo->destino=aux2,
		q->sgte=nuevo;
		cout<<"Arista ingresado"<<endl;	
	}
	
}

//se crea un metodo para insertar las aristas
void insertar_arista(){
	//declaramos las variables para capturar el nodo final y el nodo inicial 
	int ini,fin;
	//se instancia una arista con un nuevo valor
	Tarista nuevo=new struct arista;
	// se instacia dos nodos que se van a utilizar
	Tnodo aux, aux2;
	//si el puntero esta vacio es por que no se ha definido ningun nodo
	if (puntero==NULL){
		cout<<"No hay grafo"<<endl;
		return;
	}
	//de lo contrario instancia el nodo siguiente a la referencia  null 
	nuevo->sgte=NULL;
	//con las variables ini,fin  captura el nodo inicial y el nodo final
	cout<<"Ingrese el nodo del inicio: "<<endl;
	cin>>ini;
	cout<<"Ingrese el nodo del final: "<<endl;
	cin>>fin;
	//a las dos variables auxiliares le indicamos la direccion del  puntero
	aux=puntero;
	aux2=puntero;
	//verificamos si el auxiliar dos tiene algun dato 
	while (aux2!=NULL){
		//se visualiza  si ese auxiliar es el puntero final
		if (aux2->numero==fin){
			//si es el final entonces se sale de la operacion 
			break;
		}
		//de lo contrario le llevamos el valor del nodo sgte
		aux2=aux2->sgte;
	}
	//se ingresan  la arista al primer puntero
	while (aux!=NULL){
		//se indica si la variable auxiliar es igual a la arista del puntero 1 
		if (aux->numero==ini){
			//agrega las nuevas arista
			agregar_arista(aux,aux2,nuevo);
			return;
		}
		//sino se cumple la condicion va, con el siguiente
		aux=aux->sgte;
	}	
}
//se muestran la matriz 
void mostrar_grafo() {
	//se instancia el puntero del nodo y el puntero de la arista 
	Tnodo ptr;
	Tarista ar;
	//al puntero del nodo lo introducimos al que tenemos inicialmente 
	ptr=puntero;
	cout<<"Nodo:Adyacencia"<<endl;
	//si el nodo  esta vacia
	while (ptr!=NULL){
		//muestra los  dato del puntero
		cout<<"  "<<ptr->numero<<"|";
		if(ptr->ady!=NULL){
			ar=ptr->ady;
		//despues de ese operacion muestra todas las aristas que tiene ese puntero
			while(ar!=NULL){
				cout<<"  "<<ar->destino->numero;
				ar=ar->sgte;
			}
		}
		//despues pasa el siguiente puntero y repite el proceso para visualizar las aristas
		ptr=ptr->sgte;
		cout<<endl;
	}	 
}

//esta funcion lo que hace es mostrar las aristas de un nodo 
void mostrar_aristas(){
	//inicializamos los  nodos y las aristas
	Tnodo aux;
	Tarista ar;
	int var;
	cout <<"Mostrar arista del nodo"<<endl;
	cout<<"Ingrese el nodo"<<endl;
	cin>>var;
	//captura el puntero y comienza el ciclo para realizar la operacion 
	aux=puntero;
	while(aux!=NULL){
		//se indica si es un puntero que ya esta definido
		if (aux->numero==var){
			if(aux->ady==NULL){
			cout<<"El nodo no tiene Aristas"<<endl;
			return;
		    }else{
			
		     	//preguntamos si el puntero tiene arista y que la imprima
			    cout<<"Nodo:Adyacencia"<<endl;
			    cout<<"  "<<aux->numero<<"|";
		    	ar=aux->ady;
			    //posteriormente los lleva en las siguiente posicion para mostrar todas las aristas que tiene este nodo; cuando termine se sale
			    while(ar!=NULL){
			 	    cout<<ar->destino->numero<<" ";
			 	    ar=ar->sgte;
			    }
			    cout<<endl;
			    return; 
		    }
	    }else{
		   aux=aux->sgte;
        }
	}
}		
	

// se crea un menu de opciones para que el usuario teclee la opcion a realizar
int crear_menu(){
	cout<<"**GRAFOS**"<<endl;
	cout<<"**Digite el numero de la opcion que desea realizar**"<<endl;
	cout<<"1. Insertar nodo"<<endl;
	cout<<"2. Insertar Arista"<<endl;
	cout<<"3. Mostrar Grafo"<<endl;
	cout<<"4. M0star Arista de la posicion deseada"<<endl;
	cout<<"5. Salir"<<endl;
} 

int main(){
	//se incializa el puntero principal en NULL
	puntero=NULL;
	
	//se utiliza un ciclo para ejecutar acciones del menu y que sea dinamico
	volver= 1;
	while(volver==1){
		//se inicializa el menu 
		 crear_menu();
		 cin>>opc;
		
		switch(opc){
		case 1:
				// se inserta los nodo en el grafo mediante el su de case y break para romper el case 
		    	insertar_nodo();
				break;
		case 2:
			    //este metodo lo que hace es insertar arista en el grafo
				insertar_arista();
				break;
		case 3:
			    //se inserta el metodo mostar grafo
				mostrar_grafo();
				break;
		case 4:
			    //se insertan el metodo mostrar un nodo y sus aristas adyacentes
				mostrar_aristas();
				break;
		case 5:
			    //se indica la funcion de salir del programa
			   cout<<"salir"<<endl;
			   return 0;
			   break;
				
		default:
		   cout<<"opcion invalida"<<endl;		
		}
		cout<<"para volver al menu principal, presione el numero 1\n";
		cin>>volver;
	}
return 0;
}


