//dequeue.cpp
#include "Bounded_Dequeue.h"

template<typename type>
Bounded_Dequeue<type>::Bounded_Dequeue(int cap){
	length = cap;
	head = 0;
	tail = 0;
	array = new type[length]; 
}

template<typename type>
Bounded_Dequeue<type>::~Bounded_Dequeue(){
	delete [] array;
}

template<typename type>
void Bounded_Dequeue<type>::push_back(type element){
	if (tail <  length)
		array[tail++] = element;
}

template<typename type>
void Bounded_Dequeue<type>::push_front(type element){
	if (tail < length){
		for (int i = length;i>=head+1;i--){
			array[i] = array[i-1];
		}
		array[head] = element;
		tail++;
	}
}

template<typename type>
type Bounded_Dequeue<type>::pop_back(void){
	if(head != tail){
		tail = 0;
	}
}

template<typename type>
type Bounded_Dequeue<type>::pop_front(void){
 if(head != tail){
 	for(int i = length; i>=head+1;i--){
 		array[i] = array[i-1];
 	}
 	array[head] = 0;
 }
}

template<typename type>
int Bounded_Dequeue<type>::size(void){
	return length;
}
 template<typename type>
bool Bounded_Dequeue<type>::is_empty(void){
	if(head == tail){
		return true;
	}
	else return false;
}

template<typename type>
bool Bounded_Dequeue<type>::is_full(void){
	if(tail == length){
		return true;
	}
	else return false;
}

template<typename type>
void Bounded_Dequeue<type>::clear(void){
	for (int i=0;i<=length;i++){
		array[i] = 0;
	}
}

template<typename type>
void Bounded_Dequeue<type>::print(void){
	for (int i=head; i<=tail; i++){
		std::cout<<array[i];
	}
}
