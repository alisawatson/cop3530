//bounded dequeue.h
#include "Dequeue.h"

template<class type>
class Bounded_Dequeue : public Dequeue<type>{

public:
	Bounded_Dequeue(int cap);
	~Bounded_Dequeue();

	void push_front(type element) override;
	void push_back(type element) override;
	type pop_front(void) override;
	type pop_back(void) override;

	type peek_front(void) override;
	type peek_back(void) override;
	int size(void) override;
	bool is_empty(void) override;
	bool is_full(void) override;
	void clear(void) override;
	void print(void);
private:
	type * array;
	int length;
	int head;
	int tail;
};