//author: Gerardo Parra Rossignoli
//E45

#ifndef invertedQueue_h
#define invertedQueue_h

#include <iostream>
#include "queue_eda.h"

template <class T>
class invQueue : queue<T> {
	using Node = typename queue<T>::Nodo;

private:
	bool reverseImp() {
		if (this->prim == nullptr || this->prim->sig == nullptr)
			return false;

		Node * tmpPrim = this->prim; //now it's pointing to the first node, at the end it will point to the last node
		Node * prv = this->prim; //pointer to previous of prim 
		this->prim = this->prim->sig;
		Node * next = this->prim->sig;//pointer to next of prim
		prv->sig = nullptr;

		while (next != nullptr) {
			this->prim->sig = prv;
			prv = this->prim;
			this->prim = next;
			next = next->sig;
		}

		this->prim->sig = prv;
		this->ult = tmpPrim;
		tmpPrim = nullptr;
		prv = nullptr;
		next = nullptr;
		delete tmpPrim;
		delete prv;
		delete next;

		return true;
	}

	void printInvQueueImp() {
		if (this->prim != nullptr) {
			Node * tmpPrim = this->prim;

			while (this->prim != this->ult) {
				std::cout << this->prim->elem << " ";
				this->prim = this->prim->sig;
			}
			std::cout << this->ult->elem;
			
			this->prim = tmpPrim;
			tmpPrim = nullptr;
			delete tmpPrim;
		}
		std::cout << '\n';
	}

public:
	invQueue() : queue<T>() {}
	
	~invQueue() {
		queue<T>::~queue();
	}
	
	void reverse() {
		reverseImp();
	}

	void printInvQueue() {
		printInvQueueImp();
	}

	void push(T const& elem) {
		queue<T>::push(elem);
	}
};

#endif