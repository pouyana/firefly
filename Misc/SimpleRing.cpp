///*
// * simpleRing.cpp
// *
// *  Created on: 04.12.2014
// *      Author: thomas
// */
//
//#include "SimpleRing.h"
//
//template <class T>
//SimpleRing<T>::SimpleRing(const int max_size)
//{
//	this->maxSize = max_size;
//	this->content = (T*) malloc(max_size*sizeof(T));
//	this->front = 0;
//	this->end = 0;
//	this->mySem = new Semaphore();
//}
//
//template <class T>
//SimpleRing<T>::SimpleRing()
//{
//	this->maxSize = 1;
//	this->content = (T*) malloc(maxSize*sizeof(T));
//	this->front = 0;
//	this->end = 0;
//	this->mySem = new Semaphore();
//}
//
//template <class T>
//int SimpleRing<T>::getMaxSize(){
//	return this->maxSize;
//}
//
//template <class T>
//int SimpleRing<T>::increase(int i) {
//	return (i + 1) % maxSize;
//}
//
//template <class T>
//int SimpleRing<T>::size() {
//	return (end - front) % maxSize;
//}
//
//template <class T>
//int SimpleRing<T>::push(T thing) {
//
//	mySem.enter();
//	content[end] = thing;
//	end = increase(end);
//
//	if (end == front) {
//		front = increase(front);
//		mySem.leave();
//		return 1;
//	}
//	else {
//		mySem.leave();
//		return 0;
//	}
//}
//
//template<class T>
//T SimpleRing<T>::pop() {
//	T next;
//
//	if (size() == 0) {
//		//throw std::out_of_range("Really evil, don't pop empty ringBuffers!");
//		return 0;
//	}
//	else {
//		mySem.enter();
//		next = content[front];
//		front = increase(front);
//		mySem.leave();
//	}
//
//	return next;
//}

//template <class T>
//SimpleRing<T>::~SimpleRing(){ };







