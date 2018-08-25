#ifndef ExtendedQueue_h
#define ExtendedQueue_h

#include <iostream>
#include "queue_eda.h"


template <class T>
class extQueue : queue<T> {
	using Node = typename queue<T>::Nodo;

private:
	void mergeImp(queue<T> const& other) {
		Node * tmpPrim;
		if (this->prim->elem <= other->prim->elem) {
			tmpPrim = this->prim;
		}
		else
			tmpPrim = other->prim;

		Node* next = this->prim->sig; 
		Node* nextOther = other->prim->sig;
		Node* prv;

		while (next != nullptr || nextOther != nullptr) {
			if (this->prim->elem <= other->prim->elem) {
				this->prim->sig = other->prim;
				prv->sig = this->prim;
				prv = other->prim;
			}
			else {
				other->prim->sig = this->prim;
				prv->sig = other->prim;
				prv = this->prim;
			}
			this->prim = next;
			next = next->sig;
			other->prim = nextOther;
			nextOther = nextOther->sig;
		}

		if (this->nelems > other->nelems) {
			other->prim->sig = this->prim;
		}
		else if (this->nelems < other->nelems)
			this->prim->sig = other->prim;
		else {
			if (this->prim->elem <= other->prim->elem) {
				this->prim > sig = other->prim;
			}
			else
				other->prim->sig = this->prim;
		}
		this->prim = tmpPrim;


	}
public:
	extQueue() : queue<T>() {}
	~extQueue() {
		queue<T>::~queue();
	}

	void merge(queue<T> const& other) {
		mergeImp(other);
	}
};
	
#endif