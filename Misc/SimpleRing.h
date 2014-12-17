/*
 * simpleRing.h
 *
 *  Created on: 04.12.2014
 *      Author: thomas
 */

#ifndef MISC_SIMPLERING_H_
#define MISC_SIMPLERING_H_

#include "rodos.h"
#include "semaphore.h"
#include <stdlib.h>



template<class T>
class SimpleRing {
	//TODO protect with semaphore!!!
private:

	/** holds pointer to the actual content, represented by array*/
	T* content;

	/** private pointer to the front element (next one to pop)*/
	int front;

	/** private pointer to the end element (next one gets pushed into here)*/
	int end;

	/** maximum amount of elements, ring can hold, is set in constructor as only static allocating memory*/
	int maxSize;

	/** increase int i properly by one to be a valid pointer to inner structure
	 *  @param: i value to be increased by one
	 *  @return: the result of increasing i
	 */
	int increase(int i) {
		return (i + 1) % maxSize;
	}

	/**
	 * private semaphore to protect atomic functions
	 */
	Semaphore* mySem;

public:
	SimpleRing(Semaphore* sem) {
		this->maxSize = 1;
		this->content = (T*) malloc(maxSize * sizeof(T));
		this->front = 0;
		this->end = 0;
		this->mySem = sem;
	}

	SimpleRing(int maxSize, Semaphore* sem) {
		this->maxSize = maxSize;
		this->content = (T*) malloc(maxSize * sizeof(T));
		this->front = 0;
		this->end = 0;
		this->mySem = sem;
	}

	~SimpleRing() {
	}
	;

	/** deletes and returns next element, does not reallocate any memory
	 *  @return: next element T
	 */
	T pop() {
		T next;

		if (size() == 0) {
			//throw std::out_of_range("Really evil, don't pop empty ringBuffers!");
			return 0;
		} else {
			//mySem->enter();
			next = content[front];
			front = increase(front);
			//mySem->leave();
		}

		return next;
	}

	/** pushes T thing to the end of datastructure and deletes elements from the front, if content is full, does not reallocate any memory
	 *  @param: the object T to be pushed into
	 *  @return: the amount of deleted elements, due to overflow (0 or 1 only)
	 */
	int push(T thing) {

		//xprintf("1");


		//mySem->enter();
		//xprintf("2");
		content[end] = thing;
		end = increase(end);


		if (end == front) {
			front = increase(front);
			//mySem->leave();
			return 1;
		} else {
			//mySem->leave();
			return 0;
		}
	}

	/** gets the number of elements currently stored to the datastructure
	 *  @return: the number of elements currently stored. always >= 0 and <= max_size
	 */
	int size() {
		return (end - front) % maxSize;
	}

	/** gets the maximum number of elements which can be stored in this object
	 *  @return: the maximum number
	 */
	int getMaxSize() {
		return this->maxSize;
	}
};

#endif /* MISC_SIMPLERING_H_ */
