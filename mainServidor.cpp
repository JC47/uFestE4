#include <stdio.h>
#include <iostream>
#include <string>
#include "Respuesta.h"
#include <string.h>
#include <stack>
#include <fstream>

using namespace std;


int main(int argc, char const *argv[])
{	
	
	//int* array=(int*)malloc(sizeof(int)*2);
	string line;
	ifstream myfile ("texto.txt");
	if (myfile.is_open())
	{
		while ( getline (myfile,line) )
		{
		cout << line << "*" << '\n';
		}
		myfile.close();
	}

	else cout << "Unable to open file\n"; 

	Respuesta resp(7201);
	mensaje *prueba=(mensaje*)malloc(sizeof(mensaje));
	mensaje respuesta;
  	int nbd=0;
	int requestIdPasado=1;
	
	while (true){
		prueba=resp.getRequest();
		respuesta.requestId = prueba->requestId;
		memcpy(respuesta.IP,(char *)prueba->IP,16);
		respuesta.puerto = prueba->puerto; //MI PUERTO
		respuesta.n = prueba->n;

		
		cout << prueba->arguments << endl;
		cout << prueba->n << endl;

		/*
		if(prueba->requestId==requestIdPasado){
			cout<<"El operation id es: "<<prueba->requestId<<endl;
			//nbd+=(*(int *) prueba->arguments);
			char * p_aux = (*(char *) prueba->arguments);
			int n_parrafo =(*(int *) prueba->n);
			cout << p_aux << endl;
			cout << n_parrafo << endl;
			string s=to_string(nbd);
			cout<<"modifico el saldo a --------------- "<<nbd<<" voy a enviar :  "<<s<<endl;
				memcpy(respuesta.arguments,(char*)(&nbd),sizeof(nbd));
				resp.sendReply((char*) &respuesta, (unsigned char *)prueba->IP,prueba->puerto, sizeof(respuesta));
			requestIdPasado++;
		}
		else if(prueba->requestId==requestIdPasado-1){
				cout<<"El operation id es: "<<prueba->requestId<<endl;
				//nbd+=(*(int *) prueba->arguments);
				string s=to_string(nbd);
				cout<<"modifico el saldo a --------------- "<<nbd<<" voy a enviar :  "<<s<<endl;
				memcpy(respuesta.arguments,(char*)(&nbd),sizeof(nbd));
				resp.sendReply((char*) &respuesta, (unsigned char *)prueba->IP,prueba->puerto, sizeof(respuesta));
			}
		else{
			int error=-1;
			cout<<"Recibi un "<< prueba->requestId <<" esperaba un"<< requestIdPasado<<endl;
			cout<<"El operaion id es: "<<prueba->requestId<<endl;
				memcpy(respuesta.arguments,(char*)(&error),sizeof(error));
				resp.sendReply((char*) &respuesta, (unsigned char *)prueba->IP,prueba->puerto, sizeof(respuesta));
		}*/

	}
	
	return 0;
}
