/*
 * simpleRing.cpp
 *
 *  Created on: 04.12.2014
 *      Author: thomas
 */

#include "SimpleRing.h"

template <class T>
SimpleRing<T>::SimpleRing(const int max_size)
{
	this->max_size = max_size;
	this->content[this->max_size] = 0;
	this->front = 0;
	this->end = 0;
	this->mySem = new Semaphore();
}

template <class T>
SimpleRing<T>::SimpleRing()
{
	this->max_size = 1;
	this->content[1];
	this->front = 0;
	this->end = 0;
	this->mySem = new Semaphore();
}

template <class T>
int SimpleRing<T>::get_max_size(){
	return this->max_size;
}

template <class T>
int SimpleRing<T>::increase(int i) {
	return (i + 1) % max_size;
}

template <class T>
int SimpleRing<T>::size() {
	return (end - front) % max_size;
}

template <class T>
int SimpleRing<T>::push(T thing) {

	mySem.enter();
	content[end] = thing;
	end = increase(end);

	if (end == front) {
		front = increase(front);
		mySem.leave();
		return 1;
	}
	else {
		mySem.leave();
		return 0;
	}
}

template<class T>
T SimpleRing<T>::pop() {
	T next;

	if (size() == 0) {
		//throw std::out_of_range("Really evil, don't pop empty ringBuffers!");
		return 0;
	}
	else {
		mySem.enter();
		next = content[front];
		front = increase(front);
		mySem.leave();
	}

	return next;
}

template <class T>
SimpleRing<T>::~SimpleRing()
{};





