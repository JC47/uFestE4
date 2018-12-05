#include <stdio.h>
#include <iostream>
#include <string>
#include "Solicitud.h"
#include "mensaje.h"
using namespace std;



int main(int argc, char const *argv[])
{	
	int entrada;
	cout<<"Ingrese el monto a ingresar"<<endl;
	cin>>entrada;
	std::string ip("10.100.69.206"); //mi IP
	std::string ip2("10.100.69.40"); //IP DEL SERVIDOR

	mensaje prueba;
	Solicitud cliente;
	int r;
	int t;
	int n=1;
	int q=1;
	char *resultado=(char*)malloc(sizeof(TAM_MAX_DATA));
	while(entrada>0){
		prueba.requestId=entrada;
		memcpy(prueba.IP,(char *)ip.c_str(),16);
		prueba.puerto=7777; //MI PUERTO
		prueba.n=32;
		char* x = "Llega un momento en la vida en que una persona sabe perfectamente que, si no se lanza, si no deja de tener miedo a apostar y no sigue los dictámenes que su corazón ha forjado durante años, no lo hará nunca. Esas palabras, por supuesto, no las dijo Michael Ohayon en voz alta, pero exactamente así sonaron en su interior ante el farfulleo gruñón de Balilty, el jefe de la unidad de información, que no dejó de refunfuñar ni siquiera cuando Michael se inclinó sobre el cadáver. Se agachó para ver de cerca las fibras de seda que salían del pañuelo atado alrededor del cuello, debajo de esa cara convertida en una masa de sangre y huesos.\0";
		for(int i = 0; i<strlen(x); i++){
			prueba.arguments[i] = x[i]; 
		}
		//memcpy(prueba.arguments,p,sizeof(&p));

		

		mensaje *respuesta=(mensaje*)malloc(sizeof(mensaje));
		respuesta=((mensaje*)(cliente.doOperation((unsigned char *)ip2.c_str(),7201,(char *)&prueba))); //PUERTO DEL SERVIDOR
		cout<<"--------------------------"<<prueba.requestId<<endl;
		r=(*(int*)respuesta->arguments);
		t=(respuesta->requestId);
		if(t!=q){
			cout<<"Me ha llegado la respuesta  de "<<t<<" pero yo quiero la respuesta de "<<q<<endl;
		}
		else{
			if(q!=r){
				
				if(t==-1)
					q--;
				else{
					cout<<"Esperaba "<<q<<" recibi"<<r<<endl;
					cout<<"Hubo un error!!"<<endl;
				}
				puts(resultado);	
				//return 0;
			}
			else{
				cout<<"Antes tenia usted $"<<q<<" ahora tiene $"<<r<<endl;
				cout<<r<<endl;
				q++;
				entrada--;
			}
		}
		
		
	}

	

	


	
	return 0;
}
