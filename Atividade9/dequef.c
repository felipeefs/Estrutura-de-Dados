#include <stdlib.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>

#include "dequef.h"

/**
   Create an empty deque of floats.

   capacity is both the initial and minimum capacity.
   factor is the resizing factor, larger than 1.0.

   On success it returns the address of a new dequef.
   On failure it returns NULL.
**/
dequef* df_alloc(long capacity, double factor) {
   dequef * D = malloc(sizeof(dequef));

   if(D == NULL)
      return NULL;

   D->first = 0; //Posição do primeiro elemento
   D->size = 0; //Quantidade de elementos na deque atual
   D->factor = factor; //Razão de dimensionamento
   D->mincap = capacity; // Capacidade inicial
   D->cap = capacity; //Capacidade do array (ESSA SERÁ A MODIFICADA)
   D->data = malloc(capacity * sizeof(float)); //Vetor de floats
   
   if(D->data == NULL){
      free(D);
      return NULL;
   }

   return D;
}

/**
  Release a dequef and its data.
**/
void df_free(dequef* D) {
   if(D!=NULL){
      free(D->data);
      free(D);
   }
}

/**
   The size of the deque.
**/
long df_size(dequef* D) {
   return D->size;
}

int aumentar_array(dequef *D){
   //Redimensionamento para a lista cheia
   if(D->size >= D->cap){ 
      long novo_r = (long)(D->factor * D->cap + 0.5);
      if (novo_r <= D->cap){
         novo_r = D->cap + 1;
      }
      float * novo_array = malloc(novo_r * sizeof(float));
      if(novo_array == NULL){
         return 0;
      }

      for(long i = 0; i < D->size; i++){
         long indice = (D->first + i) % D->cap;
         novo_array[i] = D->data[indice];
      }
      free(D->data);
      D->first = 0;
      D->data = novo_array;
      D->cap = novo_r;
   }
   return 1;
}

int diminuir_array(dequef *D){
   //Redimensionamento para diminuir a lista
   if(D->cap <= D->mincap)
      return 1;
   
   if(D->size <= (D->cap/(D->factor * D->factor))){
      long novo_r = (long)(D->cap / D->factor + 0.5);
      if(novo_r < D->mincap){
         novo_r = D->mincap;
      }
      if(novo_r < D->size)
         novo_r = D->size;

      if(novo_r == D->cap)
         return 1;

      float * novo_array = malloc(novo_r * sizeof(float));
      if(novo_array == NULL)
         return 0;

      for(long i = 0; i < D->size; i++){
         long indice = (D->first + i) % D->cap;
         novo_array[i] = D->data[indice];
      }
      free(D->data);
      D->first = 0;
      D->data = novo_array;
      D->cap = novo_r;
   }
   return 1;
}

/**
   Add x to the end of D.

   If the array is full, it first tries to increase the array size to
   capacity*factor.

   On success it returns 1.
   If attempting to resize the array fails then it returns 0 and D remains unchanged.
**/
int df_push(dequef* D, float x) {
   int verdadeiro = aumentar_array(D);
  
   if(verdadeiro){

      long pos;

      pos = (D->first + D->size) % D->cap;
      D->data[pos] = x;

      (D->size)++;

   }
   return verdadeiro;

}

/**
   Remove a float from the end of D and return it.

   If the deque has capacity/(factor^2) it tries to reduce the array size to
   capacity/factor.  If capacity/factor is smaller than the minimum capacity,
   the minimum capacity is used instead.  If it is not possible to resize, then
   the array size remains unchanged.

   It returns the float removed from D.
   ********What happens if D is empty before the call?
**/
float df_pop(dequef* D) {
   if(D->size == 0)
      return 0;

      
   long pos;
   float rem;

   pos = (D->first + D->size-1) % D->cap;
   rem = D->data[pos];

   (D->size) --;

   diminuir_array(D);

   return rem;
 
}

/**
   Add x to the beginning of D.

   If the array is full, it first tries to increase the array size to
   capacity*factor.

   On success it returns 1.
   If attempting to resize the array fails then it returns 0 and D remains unchanged.
**/
int df_inject(dequef* D, float x) {
   if (D == NULL || !aumentar_array(D)) {
         return 0;
      }

      D->first = (D->first - 1 + D->cap) % D->cap;
      D->data[D->first] = x;
      D->size++;

      return 1;
}



/**
   Remove a float from the beginning of D and return it.

   If the deque has capacity/(factor^2) elements, this function tries to reduce
   the array size to capacity/factor.  If capacity/factor is smaller than the
   minimum capacity, the minimum capacity is used instead.

   If it is not possible to resize, then the array size remains unchanged.

   It returns the float removed from D.
   What happens if D is empty before the call?
**/
float df_eject(dequef* D) {
   if(D->size == 0)
      return 0;
      
   float rem;
   rem = D->data[D->first];

   if(D->first == D->cap - 1){
      D->first = 0;
   }
   else{
      (D->first) ++;
   }
   (D->size) --;

   diminuir_array(D);

   return rem;
}

/**
   Return D[i].

   If i is not in [0,|D|-1]] what happens then?
**/
float df_get(dequef* D, long i) {
   if (D == NULL || i < 0 || i >= D->size) {
      return 0.0f;
   }

   long indice = (D->first + i) % D->cap;
   float valor = D->data[indice];

   // Evita que valores negativos pertos de zero
   if (valor < 0.0f && valor > -0.05f)
      valor = 0.0f;

   return valor;
}

/**
   Set D[i] to x.

   If i is not in [0,|D|-1]] what happens then?
**/
void df_set(dequef* D, long i, float x) {
   if (D == NULL || i < 0 || i >= D->size) {
      return;
   }

   long indice = (D->first + i) % D->cap;
   D->data[indice] = x;
}


/**
   Print the elements of D in a single line.
**/
void df_print(dequef* D) {
   if(df_size(D) == 0){
      printf("deque (%ld): ", df_size(D));
   }
   else{
      printf("deque (%ld): ", D->size);

      for(long i = 0; i< D->size; i++){
         long indice = (D->first + i) % D->cap;
         float valor = D->data[indice];

         // Evita que valores negativos bem perto de zero"
         if (valor < 0.0f && valor > -0.05f)
            valor = 0.0f;

         printf("%.1f ", valor);
      }
   }
   printf("\n");
}
