#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <iostream>
#include <fstream>
/* Autores

jose alberto rodriguez panameño
gilary daniela varga hurtado
 

*/


using namespace std;
struct Tiempo {
	int time;
	int cont;
	int segtime;
	int promedio;
	
	
};


struct nodo{
	
 	char  nombre[25];
 	int camisa;
 	int valu;
 	int da;
 	Tiempo tiempo ;
 	int contador;
 nodo *sig,*sig2;
	
};



nodo *cab,*aux,*cab1,*aux2;

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);


int registrar(){
system("cls");

	if(cab==NULL){
	cab = (struct nodo *) malloc (sizeof(struct nodo));
	cab->contador=0;
	cab->tiempo.time=0;
   cout<<"Ingrese numero de la Camisa : ";
  
	cin>>cab->camisa;
	   cout<<"Ingrese el nombre  del participante : ";
       cin>> cab->nombre;
      cab1 =cab;
      
	cab1->sig2=NULL;
	cab->sig =NULL;

    system("cls");
	 }else{
	
		
		aux = (struct nodo *) malloc (sizeof(struct nodo));
	    aux->contador=0;
		aux->tiempo.time=0;	

		cout<<"\n";
   cout<<"Ingrese numero de la Camisa : ";

	cin>>aux->camisa;
	cout<<"Ingrese el nombre  del participante : ";
       cin>> aux->nombre;
	   //orden pila
	    aux->sig2 = cab1;
        cab1 = aux ;
	   //fin
	 aux->sig =NULL;
	aux2 = cab;
			 	
	while(aux2->sig !=NULL)
     	aux2 = aux2->sig;
     	 
	aux2->sig =aux;
	
	aux2 = aux = NULL;
	
	     aux =NULL;
	     
	  	free(aux);
	  	free(aux2);
	  	system("cls");
	  		ofstream archivo("datos.txt");
	
	 
}


}



int tiempo(){
	
		aux = (struct nodo *) malloc (sizeof(struct nodo));
		

    aux->sig = NULL;
    aux2 = cab;
    
   	bool  buscar= false ;
	int camis;
	 
	int cont;
   
   cout<<"Ingrese el numero de la camisa"<<endl;
   cin>>camis;
   for (aux2 = cab; aux2 != NULL; aux2 = aux2->sig){
   	
   	  if(camis == aux2->camisa){
   	
   	 
        buscar==true;
		 
   	  	cout<<"Ingrese el tiempo  del corrador"<<"|"<<"contador: "<<aux2->contador<<endl;
   	  	cin>>aux2->tiempo.time;
			 	
   	 aux2->contador++;
   	    aux2->tiempo.promedio = aux2->tiempo.time+aux2->tiempo.time/aux2->contador;
   	  
   	  aux2=NULL;
   	  break; 
   	  	cout<<"Registro Exitoso"<<endl;
	 
   	  
	}
		 
		 
		 
		 if(buscar==false ){
		 	
		 	cout<<"No se encontro el corredor "<<endl;

   	   	
   	
   }
}


	return 0;
	
}





int mostrar(){
	system("cls");
	int i=1,c=1;
	int a = 0;
	 SetConsoleTextAttribute( hConsole,3);
		cout<<" \t\t\tLista de tiempo de los participante "<<endl;
		cout<<"\n";
		cout<<"\n";
		
	
	for(aux=cab; aux != NULL; aux=aux->sig){
    
	cout<<i++<<" Camisa de jugador: "<<aux->camisa<<"|"<<"Nombre: "<<aux->nombre <<"|"<<" Tiempo trascurido: "<<aux->tiempo.time<<endl;		  	              
	  
	    
	
		 
		 }
	
}


int mostraordenamiento(){
	system("cls");
 int cont=1;
   
 
  SetConsoleTextAttribute( hConsole,4);
  

	for( aux=cab1; aux != NULL; aux=aux->sig2){
		 
		 
	cout<<cont++<<" : Camisa del jugador: "<<aux->camisa<<"|"<<" Nombre: "<<aux->nombre <<"|"<<"Tiempo"<<aux->tiempo.time<<endl;
		

	
	}

 return 0;
 
}	
	
	
	




int mostra2(){
	system("cls");
	
	int c=1;
	int cambio;
	int datos;
	int i,j;
	
	 SetConsoleTextAttribute( hConsole,4);
	 
  	for( aux=cab1; aux != NULL; aux=aux->sig2){
		 


cout<<c++<<" :Numero de camisa del jugador: "<<aux->camisa<<""<<": El promedio: "<<aux->tiempo.promedio<<endl;
	
	     
	  
	  
	

}
	
	  
	  
	  
	  
	  
	  
	  
	  
	  
	  
	  
	  
      // cout<<i++<<" promedio: "<<datos<<endl;
       //cout<<"Numero de Participan "<<c++<<endl;
}







			
         
int eliminar(){
	
 	SetConsoleTextAttribute( hConsole,6);	
 	
 if(cab != NULL){
 
	 aux = cab;
	 cab =cab->sig;
	 free(aux);
	  cout<<" Fue eliminado "<<endl;
	  
	 system("pause");
    system("cls");
 	 
 	
 	
 }else 
 
		 	
		 	cout<<"No se encontro el corredor "<<endl;


    system("pause");
    system("cls");
   	   	
  

   return 0;

}




int main(){
    int opc=0;
    
    
    SetConsoleTextAttribute( hConsole,1);
    
    
    do{  cout<<"\n";
        cout<<"\tmenu"<<endl;
         cout<<"\n";
      cout<<"1.Regresar participante"<<endl;
      cout<<"2.Colacar tiempo de llegada"<<endl;
        cout<<"3.Ver lista de participante"<<endl;
        cout<<"4.Promedio  "<<endl;
        cout<<"5.Ordenamiento "<<endl;
        cout<<"6.Eliminacionar "<<endl;
        cout<<"7.Salir"<<endl;
        cin>>opc;
        switch(opc){
            case 1:
            cout<<"Registro"<<endl; registrar();
				break;
				   case 2:
			 cout<<"Regritro de Tiempo"<<endl;tiempo();
			 
			break;
            case 3:
            	
			 cout<<"Mostrar lista de participante"<<endl;mostrar();
			  
			break;
			case 4:
				 cout<<"Lista de Promedio"<<endl;mostra2();
				break;
				
				case 5:
					
				 cout<<"Lista de  Ordenacion Pila"<<endl;mostraordenamiento(); 
				break;
				
				case 6: 
				eliminar();
				break;
					
            case 7:
                cout<<"Salir";
                break;
                default:
                    cout<<"Opcion no valida....";
                break;    
            }

        }while(opc!=7);
		} 
        
        
        
        
    
