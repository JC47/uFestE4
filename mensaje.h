
#include <stdio.h>
#include <unistd.h>

using namespace std;

#define TAM_MAX_DATA 4000

struct mensaje{
    unsigned int requestId; //Identificador del mensaje
    unsigned char IP[16];
    int puerto;
    int n;
    char arguments[TAM_MAX_DATA];
};