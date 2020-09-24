Assignment 5 Readme.txt

Author: Jacob Reger

Date: May 25, 2020

Struct PQ:
    Struct PQ simply defines a priority queue struct as a struct pointer to a dynamic array and an integer to
    represent the size of the array. This is not necessary because there is a function in dynarray.c that gives
    the length of a dynarray but it was included for ease of use.

pq_create():
    This function simply creates a priority queue struct object. It begins by allocating memory for the function,
    followed by creating the dynamic array inside of it and then returning a pointer to that priority queue.

pq_free():
    This function simply frees the allocated memory. This is done by first calling for the dynamic array inside
    the priority queue to be freed, then the priority queue itself.

pq_isempty():
    This function simply returns a boolean value if the size of the dynamic array in the priority queue is 0.

pq_max():
    This function simply returns the root of the heap / the first element of the dynamic array that the PQ struct 
    has a pointer to. Since this PQ is a max heap, that element is the highest priority element in the queue.

pq_max_priority():
    This fucnction returs the element with the maximum priority, which may or may not be the element with the largest
    integer value, as the elements may or may not contain integers at all.

pq_insert():
    This function inserts an element by creating an alement struct, populating it with the given information, and
    inserting it at the end of the dynamic array, followed by a call to resort the dynamic array until that element
    has reached the position it was supposed to be located in.

pq_max_dequeue():
    This function dequeues the highest priority element from the max-heap. This is done by creating an element pointer 
    and pointing it to the highest priority element in the heap, retrieving its value, swapping it with the element at
    the end of the dynamic array, deleting the max element, freeing the top element, decrementing the size, and finally 
    resorting the max-heap to leave the swapped element where it belongs.