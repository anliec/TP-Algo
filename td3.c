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

void swap(BinaryHeap * heap,const unsigned int posA,const unsigned int posB);

void cutHead(BinaryHeap * heap);

int putTheBiggerUp(BinaryHeap * heap, int posFather);

void printTab(BinaryHeap * heap);

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
    } else if (strcmp(lecture,"print")==0) {
      printTab(heap);
    }
    fscanf(stdin,"%99s",lecture);
  }
  Destroy(heap);
  return 0;
}

BinaryHeap * Init(int size)
{
  BinaryHeap * heap = malloc(sizeof(BinaryHeap));
  heap->allocated = size;
  heap->filled = 0;
  heap->array = malloc(sizeof(int[size]));
  return heap;
}

void InsertValue(BinaryHeap * heap, int value)
{
  if(heap->filled == heap->allocated)
  {
    //augmentation de la taille allou�e
    heap->allocated++;
    heap->array = realloc(heap->array, sizeof(int[heap->allocated]));
  }
  heap->array[heap->filled] = value;
  int i = heap->filled;
  heap->filled++;

  while (i != 0 && value > heap->array[(i-1)/2])
  {
    swap(heap, i, (i - 1) / 2);
    i = (i-1)/2;
  }
}
/*void InsertValue(BinaryHeap * heap, int value) ///Code de Paul Louis
{
  if(heap->filled == heap->allocated)
  {
    heap->allocated++;
    heap->array = realloc(heap->array, sizeof(int[heap->allocated]));
  }

  int index = heap->filled;
  heap->array[index] = value;
  heap->filled++;

  while(index!=0 && heap->array[index]>heap->array[(index-1)/2]) {
    heap->array[index] = heap->array[(index-1)/2];
    heap->array[(index-1)/2] = value;
    index = (index-1)/2;
  }

}*/
int ExtractMax(BinaryHeap * heap, int *res)
{
  if(heap->filled > 0)
  {
    *res = heap->array[0];
    cutHead(heap);
    return 1;
  }
  else
  {
    return 0; //error code: the array is empty
  }
}
/*int ExtractMax(BinaryHeap * heap, int *res)  ///Code de paul Louis
{
  if(heap->filled>0) {
    int value = heap->array[0];
    *res = value;


    int index = 0;
    while(index*2+2 < heap->filled)
    {
      if(heap->array[index*2+1]>heap->array[index*2+2]) {
        heap->array[index] = heap->array[index*2+1];
        index=index*2+1;
      } else {
        heap->array[index] = heap->array[index*2+2];
        index=index*2+2;
      }
    }
    heap->array[index] =  heap->array[heap->filled-1];
    heap->array[heap->filled-1] = 0;
    heap->filled--;

    return 1;
  }
  return 0;
}*/

void Destroy(BinaryHeap * heap)
{
  free(heap->array);
  free(heap);
}

void swap(BinaryHeap * heap,const unsigned int posA,const unsigned int posB)
{
  int temp = heap->array[posA];
  heap->array[posA] = heap->array[posB];
  heap->array[posB] = temp;
}

void cutHead(BinaryHeap * heap)
{
  swap(heap, 0, heap->filled-1);
  heap->filled--;
  int currantPos = 0;
  while ( currantPos != -1)
  {
    currantPos = putTheBiggerUp(heap,currantPos);
  }
}

int putTheBiggerUp(BinaryHeap * heap, int posFather)
{
  //printTab(heap);
  const unsigned int fils1 = posFather*2+1, fils2 = posFather*2+2;
  if(posFather >= heap->allocated || fils1>= heap->allocated)
  {
    return -1;
  }
  else if(fils2 < heap->filled && heap->array[posFather] > heap->array[fils1] && heap->array[posFather] > heap->array[fils2])
  {
    //printf("father is bigger end\n");
    return -1;
  }
  else if(fils1 >= heap->filled)
  {
    //printf("end\n");
    return -1;
  }
  else if(fils2 >= heap->filled)
  {
    //printf("swap de %d avec %d plutot que %d filled: %d end\n",posFather,fils1,fils2, heap->filled);
    if(heap->array[posFather] < heap->array[fils1])
    {
      swap(heap, posFather, fils1);
    }
    return -1;
  }
  else
  {
    if(heap->array[fils1] > heap->array[fils2])
    {
      //printf("swap de %d avec %d plutot que %d filled: %d cas1\n",posFather,fils1,fils2, heap->filled);
      swap(heap,posFather,fils1);
      return fils1;
    }
    else
    {
      //printf("swap de %d avec %d plutot que %d filled: %d cas2\n",posFather,fils2,fils1, heap->filled);
      swap(heap,posFather,fils2);
      return fils2;
    }
  }
}

void printTab(BinaryHeap * heap)
{
  int i;
  for (i = 0; i < heap->filled; i++)
  {
    printf(" %d",heap->array[i]);
  }
  printf("\n");
}



