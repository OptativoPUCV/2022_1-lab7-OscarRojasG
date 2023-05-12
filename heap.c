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
   if (pq->size == 0) return NULL;
   return pq->heapArray[0].data;
}

void swap(heapElem* array, int pos1, int pos2) {
   heapElem aux = array[pos1];
   array[pos1] = array[pos2]; 
   array[pos2] = aux;
}

void heap_push(Heap* pq, void* data, int priority){
   if (pq->size == pq->capac) {
      pq->capac = pq->capac * 2 + 1;
      pq->heapArray = (heapElem *) realloc(&(pq->heapArray), pq->capac);
   }

   int pos = pq->size;

   while(1) {
      pq->heapArray[pos].data = data;
      pq->heapArray[pos].priority = priority;

      int parentPos = (pos-1)/2;
      if (pos == 0 || pq->heapArray[parentPos].priority >= priority) {
         break;
      }

      swap(pq->heapArray, pos, parentPos);
      pos = parentPos;
   }

   pq->size++;
}


void heap_pop(Heap* pq){

}

Heap* createHeap(){
   Heap *heap = (Heap *) malloc(sizeof(Heap));
   heap->heapArray = (heapElem *) calloc(3, sizeof(heapElem));
   heap->size = 0;
   heap->capac = 3;
   return heap;
}
