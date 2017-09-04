//final h

# include <iostream>
#include <string>
using namespace std;
// declare methods


class MemoryList{

public:
	MemoryList(); //String programName, int ProgramSize
	int fragments();
	void add(string data);
	void print();
	void allocate(int choice, string file, bool worstfit);
	void kill(string file);

private:
	struct node{
		string fileName;
		node* next;
		bool free;
	};

//3 nodes to construct the list
	node* head;
	node* now;
	node* temp;
};



