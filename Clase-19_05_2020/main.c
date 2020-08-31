#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include <defines.h>
#include <pilaEstatica.h>
#include <pilaDinamica.h>
#include <pila.h>

#define ARG_N1 1
#define ARG_N2 2

char* sumar (const char* num1, const char* num2);///HECHO
int cargarPila(const char* num, tPila* pila, int cantCeros); ///HECHO
void cargarVector(tPila* pila, char* num);///HECHO
int max(int tamN1, int tamN2);

///Clase_2020-05-19_suma_pila num1 num2

int main(int argc, char* argv[])
{
    char* suma = sumar(argv[ARG_N1], argv[ARG_N2]);

    if(!suma)
    {
        puts("No se pudo realizar la suma: Sin memoria.");
        return SIN_MEM;
    }

    puts(suma);

    free(suma);

    return TODO_OK;
}

char* sumar(const char* num1, const char* num2)
{
    tPila p1, p2, pr;

    crearPila(&p1);
    crearPila(&p2);
    crearPila(&pr);

    int tamN1 = strlen(num1);
    int tamN2 = strlen(num2);

    int cmp = tamN1 - tamN2; //Compara longitudes y guardo la diferencia
    int cantCeros = abs(cmp); //abs otorga el valor absoluto, porque cmp puede dar negativo. Proviene de la biblioteca math.h

    int ok;

    ok = cargarPila(num1, &p1, cmp < 07 cantCeros ? 0 :);

    if(!ok)
        return NULL;

    ok = cargarPila(num2, &p2, cmp < 07 cantCeros ? 0 :);

    if(!ok)
        return NULL;

    int dig1, dig2, ac = 0, digRes; //ac es el Acarreo

    while(!pilaVacia(&p1))
    {
        desapilar(&p1, &dig1, sizeof(int));
        desapilar(&p2, &dig2, sizeof(int));

        digRes = dig1 + dig2 + ac;

        ac = digRes / 10;
        digRes %= 10; //Me devuelve la unidad

        apilar(&pr, &digRes, sizeof(int));
    }

    if(ac == 1)
        apilar(&pr, &ac, sizeof(int));

    int tamVecSuma = max(tamN1, tamN2) + 2; //Se le suma dos por el acarreo y el \0
    char* sumar = (char*)malloc(tamVecSuma);

    if(!sumar)
        return NULL;

    cargarVector(&pr, sumar);

    return sumar;
}

int cargarPila(const char* num, tPila* pila, int cantCeros)
{
    int dig = 0;

    for(int i = 0; i < cantCeros; i++)
    {
        if(!apilar(pila, &dig, sizeof(int)))
            return FALSO;
    }

    const char* act = num; //Agrego Const porque no se modifica la direccion de act.

    while(*act != '\0')
    {
        dig= *act - '0'; //Le resto el binario de cero, no el fin de cadena

        if(!apilar(pila, &dig, sizeof(int)))
            return FALSO;
        act ++;
    }

    return VERDADERO;
}

void cargarVector(tPila* pila, char* num)
{
    char* act = num;
    int dig;

    while(!pilaVacia(pila))
    {
        desapilar(pila, &dig, sizeof(int));
        *act = dig + '0';
        act ++;
    }

    *act = '\0';
}
