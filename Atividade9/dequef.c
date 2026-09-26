#include <stdlib.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <math.h>


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

   D->first = 0;
   D->size = 0; //Quantidade de elementos na deque atual
   D->factor = factor; //Razão de dimensionamento
   D->mincap = capacity; // Capacidade inicial
   D->cap = capacity; //Capacidade do array (ESSA SERÁ A MODIFICADA)
   D->data = malloc(capacity * sizeof(float)); //Vetor de floats
   
   if(D!=NULL)
      return D;

   return NULL;
}

/**
  Release a dequef and its data.
**/
void df_free(dequef* D) {
   free(D->data);
   free(D);
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
      long novo_r = ((long)D->factor) * D->cap;
      if (novo_r < D->mincap){
         return 0;
      }
      float * novo_array = malloc(novo_r * sizeof(float));
      for(int i = 0; i < D->size; i++){
         novo_array[i] = D->data[i];
      }
      D->data = novo_array;
      D->cap = novo_r;
   }
}

int diminuir_array(dequef *D){
   //Redimensionamento para  **diminuir a lista
   if(D->size <= (D->size/pow(D->factor, 2))){
      long novo_r = (long)D->cap / D->factor;
      if(novo_r < D->mincap)
         printf("Unable to resize\n");
         return 0;
      if(novo_r < D->mincap)
         novo_r = D->mincap;
      float * novo_array = malloc(novo_r * sizeof(float));
      for(int i = 0; i < D->size; i++){
         novo_array[i] = D->data[i];
      }
      D->data = novo_array;
      D->cap = novo_r;
   }
}


/**
   Add x to the end of D.

   If the array is full, it first tries to increase the array size to
   capacity*factor.

   On success it returns 1.
   If attempting to resize the array fails then it returns 0 and D remains unchanged.
**/
int df_push(dequef* D, float x) {
   aumentar_array(D);

   int pos;

   pos = (D->first + D->size) % D->cap;
   D->data[pos] = x;

   (D->size)++;

   return 1;
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

   diminuir_array(D);
   
   int pos;
   float rem;

   pos = (D->first + D->size-1) % D->cap;
   rem = D->data[pos];

   (D->size) --;

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
   aumentar_array(D);

   if(D->first == 0)
      D->first = D->cap - 1; //Como a lista é circular, e o ex primeiro ocupa a posição 0, o primeiro passa a ficar ao final do vetor
   else
      (D->first) --;
   
   D->data[D->first] = x;
   (D->size)++;

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
   diminuir_array(D);

   float rem;
   rem = D->data[D->first];

   if(D->first == D->cap - 1){
      D->first = 0;
   }
   else{
      (D->first) ++;
   }
   (D->size) --;

   return rem;
}



/**
   Return D[i].

   If i is not in [0,|D|-1]] what happens then?
**/
float df_get(dequef* D, long i) {
   // printf("%.1f\n",D->data[-1]);
   // for(int i = 0; i < D->cap; i ++){
   //    printf("%.1f ", D->data[i]);
   // }

//    if(i >= 0 && i < D->cap){
//       printf("%.1f\n",D->data[i]);
//       return D->data[i];
//    }
   int printados = 0;
   for(int j = D->first; j < (D->cap); j++){
      if(printados == i){
         printf("%.1f", D->data[j]);
         return D->data[j];
      }
      printados ++;
    }
   if (D->first != 0){
      for(int j = 0; printados < D->size; j++){
         if(printados == i){
            printf("%.1f", D->data[j]);
            return D->data[j];
         }
         printados ++;
      }
   }

   


}



/**
   Set D[i] to x.

   If i is not in [0,|D|-1]] what happens then?
**/
void df_set(dequef* D, long i, float x) {
   if(i > 0 && i < D->cap - 1){
      D->data[i] = x;
   }
}


/**
   Print the elements of D in a single line.
**/
void df_print(dequef* D) {
   // printf("%ld %ld\n", D->cap, D->first);
   int printados = 0;
   for(int i = D->first; i < (D->cap); i++){
      printf("%.1f\n", D->data[i]);
      printados ++;
    }
   if (D->first != 0){
      for(int j = 0; printados < D->size; j++){
         printf("%.1f\n", D->data[j]);
         printados ++;
      }
   }

}
