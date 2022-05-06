#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "heap.h"

typedef struct nodo{
   void* data;
   int priority;
}heapElem;

typedef struct Heap{
  heapElem* heapArray;
  int size;
  int capac;
} Heap;


void* heap_top(Heap* pq){
   if(pq->size == 0) return NULL;
   return pq->heapArray[0].data;
}


void view_array(Heap* h){
    int i;
    printf("\t[");
    for(i=0; i<h->size; i++){
        printf("%d ",h->heapArray[i].priority);
    }
    printf("]\n");
}
void heap_push(Heap* pq, void* data, int priority){
   if(pq->size == pq->capac)
   {
      pq->heapArray = (heapElem *) realloc(pq->heapArray, (pq->capac * 2) + 1);
      pq->capac = (pq->capac * 2) + 1;
   }
   view_array(pq);
   pq->heapArray[pq->size].data = data;
   pq->heapArray[pq->size].priority = priority;

   int aux = pq->size;
   void *tmp_data;
   int tmp_priority;
   while(aux != 0 && pq->heapArray[aux].priority > pq->heapArray[(aux - 1)/2].priority)
   {
      tmp_data = pq->heapArray[aux].data;
      tmp_priority = pq->heapArray[aux].priority;

      pq->heapArray[aux].data = pq->heapArray[(aux - 1)/2].data;
      pq->heapArray[aux].priority = pq->heapArray[(aux - 1)/2].priority;

      pq->heapArray[(aux - 1)/2].data = tmp_data;
      pq->heapArray[(aux - 1)/2].priority = tmp_priority;

      aux = (aux - 1)/2;
   }
   
   pq->size++;
}


void heap_pop(Heap* pq){

}

Heap* createHeap(){
   Heap *heap = (Heap *) malloc(sizeof(Heap));
   heap->heapArray = (heapElem *) malloc(3 * sizeof(heapElem));
   heap->size = 0;
   heap->capac = 3;
   return heap;
}
