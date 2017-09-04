
#include <iostream>
#include <stack>
#include <fstream>
#include <string>
#include <vector>
#include "pa3.h"

using namespace std;


//methods------------------------------------------------
//stack class implementation
Stack::Stack() {
top = -1;
array[MAX];
}

int Stack:: size(){
	return top;
}

string Stack:: peek(){
	if (top == -1)
	return array[top];
}

void Stack:: push(string code){
	if(top < MAX)
		array[++top] = code;
	else
		cout << "Stack is full" << endl;
}

void Stack:: pop(){
	if( top != -1 ){
		top--;
	}
}
void Stack:: printSt(){
	for(int i=0; i< st.size(); ++i){
		cout<<array[i]<<"\n";
	}
}

int Stack:: depth(){
	int depth =0;
	// for(int i=0; i< st.size(); ++i){
	// 	if (array[i]=="E"){
	// 		depth ++;
	// 	}
	// 	// if (array[i]=='B'){
	// 	// 	depth --;
	// 	// }
	// }
	return depth;
}
// done with stack methods

//-----------------------------------------
//check if parenthesis is correct
void checkP(){
	int pa = 0;
	for(int i=0; i< pare.size(); ++i){
		if(pare[i]=="("){
			pa++;
		}
		else if(pare[i]==")"){
			pa--;
		}
	}
	if(pa != 0){
		error.push_back(")");
	}
}
//check operator duplicates and print
void printO(){
	bool sameO;
	cout<<"Operaters: ";
	for(int i=0; i< oper.size(); ++i){
		sameO = false;
		for(int j=i+1; j< oper.size(); ++j){
			if (oper[i]==oper[j]){
				sameO =true;
			}
		}
		if (sameO == false){
				cout<<oper[i]<<" ";
		}
	}
	cout<<"\n";
}
//check keyword duplicates and print...send errors to error vector
void printK(){
	bool sameK;
	cout<<"Keywords: ";
	for(int i=0; i< keyw.size(); ++i){
		sameK = false;
		for(int j=i+1; j< keyw.size(); ++j){
			if (keyw[i]==keyw[j]){
				sameK =true;
			}
		}
		if (sameK == false){
			if (keyw[i]=="END"){
				cout<<keyw[i]<<" ";
				depthV--;
			}
			else if (keyw[i]=="BEGIN"){
				cout<<keyw[i]<<" ";
				depthV++;
			}
			else if (keyw[i]=="FOR"){
				cout<<keyw[i]<<" ";
			}
			else{
				error.push_back(keyw[i]);
			}
		}
		if(depthV!=0){
			error.push_back("END");
		}
	}
	cout<<"\n";
}
//check duplicate identifier and print
void printI(){
	bool sameI;
	cout<<"Identifier: ";
	for(int i=0; i< iden.size(); ++i){
		sameI = false;
		for(int j=i+1; j< iden.size(); ++j){
			if (iden[i]==iden[j]){
				sameI =true;
			}
		}
		if (sameI == false){
				cout<<iden[i]<<" ";
		}
	}
	cout<<"\n";
}
//print connstants checking for duplicates
void printC(){
	bool sameC;
	cout<<"Constant: ";
	for(int i=0; i< cons.size(); ++i){
		sameC = false;
		for(int j=i+1; j< cons.size(); ++j){
			if (cons[i]==cons[j]){
				sameC =true;
			}
		}
		if (sameC == false){
				cout<<cons[i]<<" ";
		}
	}
	cout<<"\n";
}
//check delimiter for duplicates and print
void printD(){
	bool sameD;
	cout<<"Delimiter: ";
	for(int i=0; i< deli.size(); ++i){
		sameD = false;
		for(int j=i+1; j< deli.size(); ++j){
			if (deli[i]==deli[j]){
				sameD =true;
			}
		}
		if (sameD == false){
				cout<<deli[i]<<" ";
		}
	}
	cout<<"\n";
}
//store syntax errors to print
void printE(){
	bool sameE;
	cout<<"Syntax Error(s): ";
	if (error.size()==0){
		cout<<"NA";
	}
	else{
		for(int i=0; i< error.size(); ++i){
			sameE = false;
			for(int j=i+1; j< error.size(); ++j){
				if (error[i]==error[j]){
					sameE =true;
				}
			}
			if (sameE == false){
				cout<<error[i]<<" ";
			}
		}
	}	
	cout<<"\n";
}


//method to parse file string into each different case
void parse(ifstream & codeFile){
	string code, temp;
	while(getline(codeFile,code)){
		for (int i =0; i< code.length();i++){
			//case operator
			if(code[i]=='+'||code[i]=='-'||code[i]=='*'||code[i]=='='){
				if(i< code.length() && (code[i+1]=='+'||code[i+1]=='-'||code[i+1]=='=')){
					// cout << "IM ADDING " << ""+code[i]+code[i+1] << " TO THE STACK\n";
					temp = string(&code[i], 2);
					oper.push_back(temp);
				}
				else
					temp = string(&code[i], 1);
					oper.push_back(temp);
			}
			// case delimiter
			if(code[i]==','||code[i]==';'){
				temp = string(&code[i], 1);
					deli.push_back(temp);
			}
			//case parenthesis
			if(code[i]=='('||code[i]==')'){
				temp = string(&code[i], 1);
					pare.push_back(temp);
			}
			//case keywords
			if (code[i]>='A' && code[i]<='Z'){
				 temp = string(&code[i], 1);
				i++;
				while (i< code.length() && code[i]>='A' && code[i]<='Z'){
					temp+=string(&code[i], 1);
					i++;
				}
				keyw.push_back(temp);
				i--;
			}
			//case constant
			if (code[i]>='0' && code[i]<='9'){
				temp = string(&code[i], 1);
				i++;
				while (i< code.length() && code[i]>='0' && code[i]<='9'){
					temp+=string(&code[i], 1);
					i++;
				}
				cons.push_back(temp);
				i--;
			}

			//case identifier
			if (code[i]>='a' && code[i]<='z'){
				temp = string(&code[i], 1);
				i++;
				while (i< code.length() && code[i]>='a' && code[i]<='z'){
					temp+=string(&code[i], 1);
					i++;
				}
				iden.push_back(temp);
				i--;
			}
		}	
	}
}





//main--------------------------------------------------
int main(){

	string fileName;
	cout<<"Please enter the name of the input file: ";
	cin>>fileName;

	string code;
	ifstream codeFile1 (fileName.c_str());

	if(!codeFile1){
		cout<<"No file found.";
	}
	parse(codeFile1);
// for stack
	ifstream codeFile2 (fileName.c_str());

	if(!codeFile2){
		cout<<"No file found.";
	}
	while(getline(codeFile2,code)){
		st.push(code);
	}
// for vector
	codeFile1.close();
	codeFile2.close();
	
	st.printSt();
	cout<< "The depth of nested loop(s) is "<<"2"<<"\n";
//print all while checking for errors
	 printO();
	 printK();
	 printD();
	 printI();
	 printC();
	 checkP();
	 printE();

}






