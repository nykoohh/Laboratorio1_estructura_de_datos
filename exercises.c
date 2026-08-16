#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "arraylist.h"
#include "stack.h"

//#include "exercises.h"

//Funciones auxiliares que puedes utilizar para debuggear tus ejercicios
//NO MODIFICAR
void imprime_lista(List *L) {
   int *dato;
   dato = (int*)first(L);
   printf("[");
   while(dato != NULL) {
      printf("%d ", *dato);
      dato = (int*)next(L);
   }
   printf("]\n");

}

//Ojo que la pila se vacía al imprimir y se imprime en orden inverso
//NO MODIFICAR
void imprime_y_vacia_pila(Stack *P) {
   void *dato;
   printf("[");
   while((dato = pop(P)) != NULL) {
      printf("%d ", *(int*)dato);
   }
   printf("]\n");
}

/* 
Ejercicio 1.
Crea una Lista y agrega punteros a elementos del 1 al 10.
Recuerda que la lista almacena punteros, por lo que
debes reservar memoria para cada elemento que agregues.
Al finalizar retorna la lista creada.
*/

List* crea_lista() 
{
   List* ListaNum = create_list();

   for (int i = 0; i < 10; i++)
   {
      int *num = malloc(sizeof(int));
      *num = i+1;
      pushBack(ListaNum, num);
   }
   
   return ListaNum;
}

/*
Ejercicio 2.
Crea una función que reciba una lista de enteros (int*) y 
retorne la suma de sus elementos.
*/
int sumaLista(List *L) 
{
   int suma = 0;
   int* dato = first(L);

   while(dato != NULL)
   {
      suma += *dato;
      dato = next(L);
   }
   
   return suma;
}

/*
Ejercicio 3.
Crea una función que reciba una lista de punteros a int (int*) y
un entero elem. La función debe eliminar todos los elementos 
de la lista que sean iguales a elem.
Asume que popCurrent luego de eliminar un elemento se
posiciona en el elemento anterior.
*/

void eliminaElementos(List*L, int elem)
{
   int* dato = first(L);

   while(dato != NULL)
   {
       if (*dato == elem)
       {
          popCurrent(L);
       }
      dato = next(L);
   }
}

/*
Ejercicio 4.
La función copia los punteros de la pila P1 en la pila P2.
El orden de ambas pilas se debe mantener.
Puedes usar una pila auxiliar.
*/

void copia_pila(Stack* P1, Stack* P2) 
{
   Stack *pilaAux = create_stack();
   

   while(top(P1) != NULL)
   {
      void* dato = top(P1);
      push(pilaAux, dato);
      pop(P1);
   }
   
   while(top(pilaAux) != NULL)
   {
      void* dato2 = top(pilaAux);
      push(P2, dato2);
      push(P1, dato2);
      pop(pilaAux);
   }
   
   
}

/*
Ejercicio 5.
La función verifica si la cadena de entrada tiene sus 
paraéntesis balanceados. Retorna 1 si están balanceados,
0 en caso contrario.
*/

int parentesisBalanceados(char *cadena) 
{
   Stack *pilaParentesis = create_stack();
   int i = 0;

   while (cadena[i] != '\0')
   {
      char parentesis = cadena[i];
      if (parentesis == '(')
      {
         push(pilaParentesis, parentesis);
      }
      else
      {
         if (parentesis == ')')
         {
            if (top(pilaParentesis) == NULL)
            {
               free_stack(pilaParentesis);
               return 0;
            }
            pop(pilaParentesis);
         }
      }
      i++;
   }

   if (top(pilaParentesis) == NULL)
   {
      free_stack(pilaParentesis);
      return 1;
   }
   
   free_stack(pilaParentesis);
   return 0;
}

