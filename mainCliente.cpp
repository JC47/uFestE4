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
	std::string ip("10.100.70.115"); //mi IP
	std::string ip2("10.100.74.112"); //IP DEL SERVIDOR
	

	mensaje prueba;
	Solicitud cliente;
	int r;
	int t;
	int n=1;
	int q=1;
	char *resultado=(char*)malloc(sizeof(TAM_MAX_DATA));
	while(entrada>0){
		prueba.messageType=q;
		prueba.requestId=entrada;
		memcpy(prueba.IP,(char *)ip.c_str(),16);
		prueba.puerto=7777; //MI PUERTO
		prueba.operationId=2 ;
		memcpy(prueba.arguments,(char*)(&n),sizeof(int));

		

		mensaje *respuesta=(mensaje*)malloc(sizeof(mensaje));
		respuesta=((mensaje*)(cliente.doOperation((unsigned char *)ip2.c_str(),7201,prueba.operationId,(char *)&prueba))); //PUERTO DEL SERVIDOR
		cout<<"--------------------------"<<prueba.messageType<<endl;
		r=(*(int*)respuesta->arguments);
		t=(respuesta->messageType);
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
