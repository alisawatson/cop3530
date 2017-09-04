#include <iostream>
#include <stack>
#include <string>
#include <fstream>
#include "practice.h"

int main(){
	string code;
	ifstream codeFile2 ("code.txt");

	if(!codeFile2){
		cout<<"No file found.";
	}
	
	cout<<st.top();
	string temp;
	int depth =0;
	while(getline(codeFile2,code)){
		for (int i =0; i+2< code.length();++i){
			if (code[i]=='E'){
				i++;
				if (code[i]=='N')
				i++;
				if (code[i]=='D')
				depth ++;
			}
		}
	}
}