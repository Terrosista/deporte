#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

/* Autores

jose alberto rodriguez panameño
gilary daniela varga hurtado
 

*/


using namespace std;

struct nodo{
 	char  nombre[25];
 	int camisa;
 	int valu;
 	int da;
 	
 nodo *sig, *sig1,*sig2,*sig3;
	
};



nodo *cab,*tiemp,*tiemp1,*cab1 ,*aux,*aux2,*aux3,*aux1,*aux4;

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);


int registrar(){
system("cls");

	if(cab==NULL){
	cab = (struct nodo *) malloc (sizeof(struct nodo));
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
}

}
int mostrar(){
	system("cls");
	int i=1,c=1;
	int a = 0;
	 SetConsoleTextAttribute( hConsole,3);
		cout<<" \t\t\tLista de tiempo de los participante "<<endl;
		cout<<"\n";
		cout<<"\n";
		
	for(aux1=tiemp; aux1 != NULL; aux1=aux1->sig1){
		
	cout<<"\t\t\t\t\t "<<c++<<".Tiempo"":  "<<aux1->valu<<endl;
	
}
	for(aux=cab; aux != NULL; aux=aux->sig){
    
	cout<<i++<<" camisa de jugador: "<<aux->camisa<<" Nombre: "<<aux->nombre <<endl;		  	              
	
	
		 
		 }
	
}


int mostraordenamiento(){
	system("cls");
 int cont=1;
 int cont1=1;   
 
  SetConsoleTextAttribute( hConsole,4);
    for(aux1=tiemp1; aux1 !=NULL; aux1=aux1->sig3){
    	
	
    	cout<<"\t\t\t\t\t "<<cont1++<<".Tiempo"":  "<<aux1->valu<<endl;
		
}

	for( aux=cab1; aux != NULL; aux=aux->sig2){
		 
		 
	cout<<cont++<<" : camisa de jugador: "<<aux->camisa<<" Nombre: "<<aux->nombre <<endl;
		
	
	}


}	
	
	
	




int mostra2(){
	system("cls");
	int i=0;
	int c=1;
	 SetConsoleTextAttribute( hConsole,4);
   for(aux1=tiemp; aux1 != NULL; aux1=aux1->sig1){

       aux1->da =aux1->valu+ aux1->valu;
	     
       cout<<i++<<" promedio: "<<aux1->da<<endl;
       cout<<"Numero de Participan "<<c++<<endl;
}


}



int tiempo1(){
	system("cls");
	if(tiemp ==NULL){
		
	tiemp = (struct nodo *) malloc (sizeof(struct nodo));
   cout<<"ingrese el tiempo: ";

	cin>>tiemp->valu;
	
	tiemp1 = tiemp;
	tiemp1->sig3 = NULL;
	tiemp->sig1 =NULL;
	
	
	
		system("cls");
	}
	 else {
	
		
		aux1 = (struct nodo *) malloc (sizeof(struct nodo));
		cout<<"\n";
   cout<<"Ingrese el tiempo: ";

	cin>>aux1->valu;
	
	aux1->sig3 = tiemp1;
        tiemp1 = aux1 ;

	aux1->sig1 =NULL;
	aux3 = tiemp;
		 
		 	
	while(aux3->sig1 !=NULL)
     	aux3 = aux3->sig1;
     	 
	aux3->sig1 =aux1;
	
	aux3 = aux1 = NULL;
	
	 aux1 =NULL;
	  	free(aux1);
	  	free(aux3);
	  	

 system("cls");
}
	
	
	
}
			
         
int eliminar(){
 	SetConsoleTextAttribute( hConsole,6);
 if(cab != NULL){
 	
	 aux = cab;
	 cab =cab->sig;
	 free(aux);
	  cout<<" Fue eliminado "<<endl;
	 return 0;
 	 
 	
 	
 }



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
			  cout<<"Regritro de Tiempo"<<endl;tiempo1();
			 
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
        
        
        
        
    
