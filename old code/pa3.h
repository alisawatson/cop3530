#ifndef PA3_H
#define PA3_H

#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

const int MAX = 500;
vector<string> keyw;
vector<string> error;
vector<string> iden;
vector<string> cons;
vector<string> oper;
vector<string> deli;
vector<string> pare;
int depthV=0;
void printO();
void printK();
void printI();
void printC();
void printD();
void printE();
void checkP();

//void printKeyw();
void parse(ifstream & file);
class Stack{

	public:
		Stack();
		int size();
		string peek();
		void push(string code);
		void pop();
		void printSt();
		int depth();
	private:
		string array[MAX];
		int top;

};
Stack st;


#endif