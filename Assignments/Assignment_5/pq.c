/*
 * In this file, you will write the structures and functions needed to
 * implement a priority queue.  Feel free to implement any helper functions
 * you need in this file to implement a priority queue.  Make sure to add your
 * name and @oregonstate.edu email address below:
 *
 * Name: Jacob Reger
 * Email: regerj@oregonstate.edu
 */

#include <stdlib.h>
#include <stdio.h>

#include "pq.h"
#include "dynarray.h"

/*
 * This is the structure that represents a priority queue.  You must define
 * this struct to contain the data needed to implement a priority queue.
 * in addition, you want to define an element struct with both data and priority, 
 * corresponding to the elements of the priority queue. 
 */
struct pq {
  struct dynarray * heap;
  int size;
};

struct pq_element {
  void * val;
  int priority;
};

/*
 * This function should allocate and initialize an empty priority queue and
 * return a pointer to it.
 */
struct pq* pq_create() {
  struct pq * temp = malloc(sizeof(struct pq));
  temp->heap = dynarray_create();
  return temp;
}


/*
 * This function should free the memory allocated to a given priority queue.
 * Note that this function SHOULD NOT free the individual elements stored in
 * the priority queue.  That is the responsibility of the caller.
 *
 * Params:
 *   pq - the priority queue to be destroyed.  May not be NULL.
 */
void pq_free(struct pq* pq) {
  dynarray_free(pq->heap);
  free(pq);
}


/*
 * This function should return 1 if the specified priority queue is empty and
 * 0 otherwise.
 *
 * Params:
 *   pq - the priority queue whose emptiness is to be checked.  May not be
 *     NULL.
 *
 * Return:
 *   Should return 1 if pq is empty and 0 otherwise.
 */
int pq_isempty(struct pq* pq) {
  if(dynarray_length(pq->heap) == 0){
    return 1;
  }else{
    return 0;
  }
}

void swap(struct pq * pq, int node1, int node2){
  struct element * temp1 = dynarray_get(pq->heap, node1);
  struct element * temp2 = dynarray_get(pq->heap, node2);
  dynarray_set(pq->heap, node1, temp2);
  dynarray_set(pq->heap, node2, temp1);
}

void heapify(struct pq * pq, int i){
  if(pq->size > 1){
    //printf("entered heapify if\n");
    int large = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    //printf("large: %d left: %d right: %d size: %d\n", large, left, right, pq->size);
    struct pq_element * temp3 = dynarray_get(pq->heap, large);
    if(left < pq->size){
      struct pq_element * temp1 = dynarray_get(pq->heap, left);
      if(right < pq->size){
        struct pq_element * temp2 = dynarray_get(pq->heap, right);

        if(left < pq->size && *(int *)(temp1->val) > *(int *)(temp3->val)){
          //printf("pre heapify1\n");
          temp3 = dynarray_get(pq->heap, left);
          //printf("post heapify1\n");
          large = left;
        }
        if(right < pq->size && *(int *)(temp2->val) > *(int *)(temp3->val)){
          //printf("pre heapify2\n");
          temp3 = dynarray_get(pq->heap, right);
          //printf("post heapify2\n");
          large = right;
        }
      }else{
        if(left < pq->size && *(int *)(temp1->val) > *(int *)(temp3->val)){
          //printf("pre heapify3\n");
          temp3 = dynarray_get(pq->heap, left);
          //printf("post heapify3\n");
          large = left;
        }
      }
    }
    
    
    if(large != i){
      swap(pq, i, large);
      heapify(pq, large);
    }
  }
}

/*
 * This function should insert a given element into a priority queue with a
 * specified priority value.  Note that in this implementation, higher priority
 * values are given precedent, and higher place in the queue.  In other words, the
 * element in the priority queue with the highest priority value should be the
 * FIRST one returned.
 *
 * Params:
 *   pq - the priority queue into which to insert an element.  May not be
 *     NULL.
 *   data - the data value to be inserted into pq.
 *   priority - the priority value to be assigned to the newly-inserted
 *     element.  Note that in this implementation, higher priority values
 *     should correspond to the first elements.  In other words,
 *     the element in the priority queue with the highest priority value should
 *     be the FIRST one returned.
 */
void pq_insert(struct pq* pq, void* data, int priority) {
  struct pq_element * temp1 = malloc(sizeof(struct pq_element));
  temp1->val = data;
  temp1->priority = priority;
  if(pq->size == 0){
    dynarray_insert(pq->heap, 0, temp1);
    pq->size = pq->size + 1;
  }else{
    dynarray_insert(pq->heap, -1, temp1);
    pq->size = pq->size + 1;
    for(int i = ((pq->size / 2) - 1); i >= 0; i--){
      heapify(pq, i);
    }
  }
}


/*
 * This function should return the data of the first element in a priority
 * queue, i.e. the data associated with the element with highest priority value.
 *
 * Params:
 *   pq - the priority queue from which to fetch a value.  May not be NULL or
 *     empty.
 *
 * Return:
 *   Should return the data of the first item in pq, i.e. the item with
 *   max priority value.
 */
void* pq_max(struct pq* pq) {
  struct pq_element * temp1 = dynarray_get(pq->heap, 0);
  void * temp_return = temp1->val;
  return temp_return;
}


/*
 * This function should return the priority value of the first item in a
 * priority queue, i.e. the item with highest priority value.
 *
 * Params:
 *   pq - the priority queue from which to fetch a priority value.  May not be
 *     NULL or empty.
 *
 * Return:
 *   Should return the priority value of the first item in pq, i.e. the item
 *   with highest priority value.
 */
int pq_max_priority(struct pq* pq) {
  struct pq_element * temp1 = dynarray_get(pq->heap, 0);
  int temp_return = temp1->priority;
  return temp_return;
}

/*
 * This function should return the value of the first item in a priority
 * queue, i.e. the item with highest priority value, and then remove that item
 * from the queue.
 *
 * Params:
 *   pq - the priority queue from which to remove a value.  May not be NULL or
 *     empty.
 *
 * Return:
 *   Should return the value of the first item in pq, i.e. the item with
 *   highest priority value.
 */
void* pq_max_dequeue(struct pq* pq) {
  struct pq_element * top = dynarray_get(pq->heap, 0);
  void * temp = top->val;
  struct pq_element * bottom = dynarray_get(pq->heap, -1);
  swap(pq, 0, -1);
  dynarray_remove(pq->heap, -1);
  free(top);
  pq->size = pq->size - 1;
  for(int i = (pq->size / 2) - 1; i >= 0; i--){
    heapify(pq, i);
  }
  return temp;
}
