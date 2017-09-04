#include <iostream>
#include "Dequeue.h"

main(){
	
	Dequeue * test = new Dequeue();

	test = new Bounded_Dequeue(5);

	std::cout<<"contents of test is ";

	test->print();
	test->push_front(1);
	test->push_back(2);
	test->print();

}