#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED

#define TODO_OK 0
#define SIN_MEM 1

void crearPila(Pila* pila);
int apilar(Pila* pila, const void* d, unsigned tamElem);
int desapilar(Pila* pila, void* d, unsigned tamElem);
int topePila(const Pila* pila, void* d, unsigned tamElem);
void vaciarPila(Pila* pila);
int pilaVacia(const Pila* pila);
int pilaLlena(const Pila* pila, unsigned tamElem);

#endif // PILA_H_INCLUDED
