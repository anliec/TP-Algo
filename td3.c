#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int allocated; /* current allcoation of array */
  int filled;    /* number of items present in the binheap */
  int *array;    /* array of values */
} BinaryHeap;

/* Init allocates the structure BinaryHeap and
 * also the membre array with the given size 
 * it also fill allocated (size) and intializes 
 * filled to 0 */
BinaryHeap * Init(int size);

/* InsertValue insert value into the binary heap
 * the array is reallocated if necessary (allocated changed 
 * with respect to the new size )
 * filled is incremented by 1 */
void InsertValue(BinaryHeap * heap, int value);

/* ExtractMAx returns 0 if the binary heap is empty
 * otherwise it return 1 and fills *val with the maximum 
 * value present in the binary heap
 * filled is decremented by 1  and the max value is removed
 * from the binary heap */
int ExtractMax(BinaryHeap * heap, int * val);

/* Destroy frees the structure and the array */
void Destroy(BinaryHeap * heap);


int main(void) 
{
  char lecture[100];
  int val;
  BinaryHeap * heap;
  heap = Init(10);

  fscanf(stdin,"%99s",lecture);
  while (strcmp(lecture,"bye")!=0) {
    if (strcmp(lecture,"insert")==0) {
      fscanf(stdin,"%99s",lecture);
      val = strtol(lecture,NULL,10);
      InsertValue(heap,val);
    } else if (strcmp(lecture,"extract")==0) {
      if(ExtractMax(heap,&val))
      {
        printf("%d\r\n",val);
      }
    }
    fscanf(stdin,"%99s",lecture);
  }
  Destroy(heap);
  return 0;
}

BinaryHeap * Init(int size)
{
  BinaryHeap * heap;
  heap->allocated = size;
  heap->filled = 0;
  heap->array = malloc(sizeof(int)*heap->allocated);
  return heap;
}

void InsertValue(BinaryHeap * heap, int value)
{
  heap->array[heap->filled] = value;
  int i = heap->filled;
  while (value > heap->array[(i-1)/2])
  {
    swap(heap, i, (i - 1) / 2);
    i = (i-1)/2;
  }
}

int ExtractMax(BinaryHeap * heap, int *res)
{
  if(heap->filled > 0)
  {
    *res = heap->array[0];

    return 1;
  }
  else
  {
    return 0; //error code: the array is empty
  }
}

void Destroy(BinaryHeap * heap)
{
  free(heap->array);
}

void swap(BinaryHeap * heap,const unsigned int posA,const unsigned int posB)
{
  int temp = heap->array[posA];
  heap->array[posA] = heap->array[posB];
  heap->array[posB] = temp;
}

void cutHead(BinaryHeap * heap)
{
  int currantPos = 0;
  while(currantPos = putTheBiggerUp(heap,currantPos) != -1)
  {

  }
}

int putTheBiggerUp(BinaryHeap * heap, int posFather)
{
  int fils1 = posFather*2+1, fils2 = posFather*2+2;
  if(fils1 >= heap->filled)
  {
    return -1;
  }
  else if(fils2 >= heap->filled)
  {
    swap(heap,posFather,fils1);
    return -1;
  }
  else
  {
    if(heap->array[fils1] > heap->array[fils2])
    {
      swap(heap,posFather,fils1);
      return fils1;
    }
    else
    {
      swap(heap,posFather,fils2);
      return fils2;
    }
  }
}



