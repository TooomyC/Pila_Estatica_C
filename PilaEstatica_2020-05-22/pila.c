#include <memory.h>
#include <defines.h>
#include <pilaEstatica.h>

void crearPila(tPila* pila)
{
    pila->tope = NULL; //Inicializo tope con NULO
}

int apilar(tPila* pila, const void* d, int tamElem)
{
    if(pila->tope + tamElem + sizeof(unsigned) > TAM_PILA)
        return FALSO;

    memcpy(pila->vPila + pila->tope, d, tamElem);
    pila->tope += tamElem;

    *(unsigned*)(pila->vPila + pila->tope) = tamElem; ///memcpy(pila->vPila + pila->tope, &tamElem, sizeof(unsigned);
    pila->tope += sizeof(unsigned);

    return VERDADERO;
}

int desapilar(tPila* pila, void* d, int tamElem)
{
    if(pila->tope == NULL) //La pila esta vacia
        return FALSO;

    pila->tope -= sizeof(unsigned);
    int tamElemReal = *(unsigned*)(pila->vPila + pila->tope);

    pila->tope -= tamElemReal;
    memcpy(d, pila->vPila + pila->tope, minimo(tamElem, tamElemReal));

    return VERDADERO;
}

int topePila(const Pila* pila, void* d, int tamElem)
{
    if(pila->tope == NULL)
        return FALSO;

    int topeTmp = pila->tope;

    topeTmp -= sizeof(unsigned);
    int tamElemReal = *(unsigned*)(pila->vPila + pila->tope);
    topeTmp -= tamElemReal;
    memcpy(d, pila->vPila + topeTmp, minimo(tamElem, tamElemReal));

    return VERDADERO;
}

int pilaVacia(const tPila* pila) //Veo si la pila esta vacia
{
    return pila->tope == NULL;
}

int pilaLlena(const tPila* pila) //Veo si la pila esta llena
{
    return pila->tope + tamElem + sizeof(unsigned) > TAM_PILA;
}

void vaciarPila(tPila* pila)
{
    pila->tope = NULL;
}

