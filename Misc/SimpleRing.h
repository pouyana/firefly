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

template <class T>


class SimpleRing
{
private:

	/** holds pointer to the actual content, represented by array*/
	T* content;

	/** private pointer to the front element (next one to pop)*/
	int front;

	/** private pointer to the end element (next one gets pushed into here)*/
	int end;

	/** maximum amount of elements, ring can hold, is set in constructor as only static allocating memory*/
	const int max_size;

	/** increase int i properly by one to be a valid pointer to inner structure
	 *  @param: i value to be increased by one
	 *  @return: the result of increasing i
	 */
	int increase(int i);

	/**
	 * private semaphore to protect atomic functions
	 */
	Semaphore mySem;

public:
	SimpleRing();
	SimpleRing(const int max_size);
	~SimpleRing();

	/** deletes and returns next element, does not reallocate any memory
	 *  @return: next element T
	 */
	T pop();

	/** pushes T thing to the end of datastructure and deletes elements from the front, if content is full, does not reallocate any memory
	 *  @param: the object T to be pushed into
	 *  @return: the amount of deleted elements, due to overflow (0 or 1 only)
	 */
	int push(T thing);

	/** gets the number of elements currently stored to the datastructure
	 *  @return: the number of elements currently stored. always >= 0 and <= max_size
	 */
	int size();

	/** gets the maximum number of elements which can be stored in this object
	 *  @return: the maximum number
	 */
	int get_max_size();
};




#endif /* MISC_SIMPLERING_H_ */
