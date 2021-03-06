/*
 * Queue.cpp
 *
 *  Created on: Apr 7, 2020
 *      Author: Jack
 */

#include "Queue.h"


template <typename T>
//Default constructor
Queue<T>::Queue(int size){
	//Index of array where head is located
	head = 0;
	//Index of array where tail is located
	tail = -1;
	//Maximum number of entries the queue can hold
	maxSize = size;
	//Current size of element
	currentSize = 0;
	//Elements of the queue
	elems = new T[size];
}

template <typename T>
//Destructor
Queue<T>::~Queue(){
	delete[] elems;
}

template <typename T>
// inserts an element at the end of the	queue
void Queue<T>::enqueue(T object){
	if(isFull()){
		cout << "Queue is already full! No space to add another item!" << endl;
	}else{
		tail = (tail + 1) % maxSize;
		elems[tail] = object;
		currentSize++;
	}
}

template <typename T>
//Returns the element at the front of the queue and then shrinks the active area of the array by 1
T Queue<T>::dequeue(){
	if(isEmpty()){
		cout << "Queue is already empty! No item to remove!" << endl;
	}else{
		head = (head + 1) % maxSize;
		currentSize--;
		return elems[head -1];
	}
}

template <typename T>
//Prints out all the data in the queue
void Queue<T>::print(){
	for(int i = 0; i < currentSize; i++){
		cout << "element " << i << ": " << elems[(head + i) % maxSize] << endl;
	}
	cout << endl;
}
