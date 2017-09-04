//Dequeue.h
#include <iostream>

template<typename type>
class Dequeue{

public:

	virtual void push_front(type element) =0;
	virtual void push_back()=0;
	virtual void pop_front()=0;
	virtual void pop_back()=0;

	virtual void peek_front()=0;
	virtual void peek_back()=0;
	virtual void length()=0;
	virtual bool is_empty()=0;
	virtual bool is_full()=0;
	virtual void clear()=0;
};

