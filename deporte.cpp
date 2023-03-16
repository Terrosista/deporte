#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

struct nodo{
 //char valu[20] ;	
 	int camisa ;
 	char  nombre[20];
 	int valu;
 	int da;
 	int bas;
 nodo *sig, *sig1,*sig2;
	
};



nodo *cab,*tiemp,*cab1 ,*aux,*aux2,*aux3,*aux1,*aux4;



int registrar(){


	if(cab==NULL){
	cab = (struct nodo *) malloc (sizeof(struct nodo));
   cout<<"Ingrese numero de la Camisa : ";

	cin>>cab->camisa;
	   cout<<"Ingrese el nombre  del participante : ";
       cin>> cab->nombre;
      cab1 =cab;
      
	cab1->sig2=NULL;
	cab->sig =NULL;


	 }else{
	
		
		aux = (struct nodo *) malloc (sizeof(struct nodo));
		

		cout<<"\n";
   cout<<"Ingrese numero de la Camisa : ";

	cin>>aux->camisa;
	cout<<"Ingrese el nombre  del participante : ";
       cin>> aux->nombre;
	   //orden
	    aux->sig2 = cab1;
        cab1 = aux ;
	   //
	 aux->sig =NULL;
	aux2 = cab;
			 	
	while(aux2->sig !=NULL)
     	aux2 = aux2->sig;
     	 
	aux2->sig =aux;
	
	aux2 = aux = NULL;
	     aux =NULL;
	  	free(aux);
	  	free(aux2);
}

}
int mostrar(){
	int i=1,c=1;
	int a = 0;
		cout<<" \t\t\tLista de tiempo de los participante "<<endl;
		cout<<"\n";
		cout<<"\n";
		
	for(aux1=tiemp; aux1 != NULL; aux1=aux1->sig1){
		
	cout<<"                         \t\t\t\t "<<c++<<".Tiempo"":  "<<aux1->valu<<endl;
	
}
	for(aux=cab; aux != NULL; aux=aux->sig){
    
	cout<<i++<<" : numero de camisa de jugador: "<<aux->camisa<<" Nombre: "<<aux->nombre <<endl;		  	              
	
	
		 
		 }
	
}


int mostraordenamiento(){
 int cont=1;


	for( aux=cab1; aux != NULL; aux=aux->sig2){
		 
		 
	cout<<cont++<<" : numero de camisa de jugador: "<<aux->camisa<<" Nombre: "<<aux->nombre <<endl;
		
		
	}


}	
	
	
	




int mostra2(){
	int i=0;
	int b=1;
	int c=1;
   for(aux1=tiemp; aux1 != NULL; aux1=aux1->sig1){

       aux1->da =aux1->valu+ aux1->valu;
	     
       cout<<i++<<" promedio: "<<aux1->da<<endl;
       cout<<"Numero de Participan "<<c++<<endl;
}


}



int tiempo1(){
	
	if(tiemp ==NULL){
		
	tiemp = (struct nodo *) malloc (sizeof(struct nodo));
   cout<<"ingrese un valor: ";

	cin>>tiemp->valu;
	tiemp->sig1 =NULL;
	
		
	}
	 else {
	
		
		aux1 = (struct nodo *) malloc (sizeof(struct nodo));
		cout<<"\n";
   cout<<"Ingrese un valor 1: ";

	cin>>aux1->valu;
	
	

	aux1->sig1 =NULL;
	aux3 = tiemp;
		 
		 	
	while(aux3->sig1 !=NULL)
     	aux3 = aux3->sig1;
     	 
	aux3->sig1 =aux1;
	
	aux3 = aux1 = NULL;
	  	free(aux1);
	  	free(aux3);
	  	


}
	
	
	
}
			
 int eliminar(){
 	
 if(cab != NULL){
 	
	 aux = cab;
	 cab =cab->sig;
	 free(aux);
	 
	 return 0;
 	 
 	
 	
 }



}
                                                                                                     	



	



int main(){
    int opc=0;
    do{  cout<<"\n";
        cout<<"\tmenu"<<endl;
         cout<<"\n";
      cout<<"1.Regresar participante"<<endl;
      cout<<"2.Colacar tiempo de llegada"<<endl;
        cout<<"3. Ver lista de participante"<<endl;
        cout<<"4. Promedio  "<<endl;
        cout<<"5. ordenamiento "<<endl;
        cout<<"6. Eliminacionar "<<endl;
        cout<<"7. Salir"<<endl;
        cin>>opc;
        switch(opc){
            case 1:
               registrar();
				break;
				   case 2:
			 tiempo1();
			 
			break;
            case 3:
            	
			mostrar();
			  
			break;
			case 4:
				mostra2();
				break;
				
				case 5:
					
				mostraordenamiento(); 
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
        
        
