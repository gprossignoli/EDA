//Gerardo Parra Rossignoli
//E45


#ifndef extendedQueue_h
#define extendedQueue_h

#include <iostream>
#include "queue_eda.h"

template <class T>
class extQueue : queue<T> {
	using Node = typename queue<T>::Nodo;

private:
	bool duplicateImp() {
		if (this->prim == nullptr) //empty queue
			return false; 

		Node * tmpPrim = this->prim;
		Node * aux;

		while (this->prim != this->ult) {
			aux = new Node(this->prim->elem);
			aux->sig = this->prim->sig;
			this->prim->sig = aux;
			this->prim = aux->sig;
		}
		aux = new Node(this->prim->elem);
		aux->sig = this->prim->sig;
		this->prim->sig = aux;
		this->ult = this->prim;
		this->prim = tmpPrim;

		tmpPrim = nullptr;
		aux = nullptr;
		delete tmpPrim;
		delete aux;
	}

	void printExtQueueImp() {
		if (this->prim != nullptr) { 
			Node * tmpPrim = this->prim;

			while (this->prim != nullptr) {
				std::cout << this->prim->elem << " ";
				this->prim = this->prim->sig;
			}
			this->prim = tmpPrim;
			tmpPrim = nullptr;
			delete tmpPrim;
		}
		std::cout << "\n";
	}

public:
	extQueue() : queue<T>() {}

	~extQueue() {
		queue<T>::~queue();
	}

	void duplicate() {
		duplicateImp();
	}

	void printExtQueue() {
		printExtQueueImp();
	}

	void push(T const& elem) {
		queue<T>::push(elem);
	}
};

#endif