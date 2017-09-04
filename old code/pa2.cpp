//final cpp

#include <iostream>
#include "pa2.h"
#include <string>

using namespace std;

MemoryList::MemoryList() {
    head = NULL;
    now = NULL;
    temp = NULL;
}

//method used to initialize empty List
void MemoryList::add(string data) {
    node* n = new node();
    n->next = NULL;
    n->fileName = data;
    n->free = true;

//check if anything is inside
    if (head == NULL) {
        head = n;
        now = n;
        return;
    }
//point to next
    now->next = n;
    now = n;
}

void MemoryList::print() {
    node* temp = head;
    int printCount =1;
    while (temp != NULL) {
    	//accessing data of each node and printing
        cout << temp->fileName << " ";
        if(printCount%8 ==0){
        	cout<<"\n";
        }
        temp = temp->next;
        printCount++;
    }
}

void MemoryList::allocate(int fileSize, string file, bool worstfit) {
	//checking to see how many pages needed
    int pages = fileSize / 4;
    if (fileSize % 4 != 0) {
        pages++;
    }
    //iterate through list to see if filename is in use
    node* temp = head;
    while (temp!=NULL){
    	if (temp->fileName == file){
    		cout<<"Error, Program "<<file<<" already running.\n";
    		return;
    	}
    	temp=temp->next;
    }
    
    //allocate by worst fit
    if (worstfit) {
        int count = 0;
        int maxCount = 0;
        //variable for storing node place
        node* maxChain = NULL;
        node* freeChainStart = this->head;
        
        for (node* current = this->head; current != NULL; current = current->next) {
            if (count == 0) {
                freeChainStart = current;
            }
            if (current->free) count++;
            else {
                //check each block and switch if count is bigger
                if (count > maxCount) {
                    maxCount = count;
                    maxChain = freeChainStart;
                }
                count = 0;
            }
        }
        //checking for the last node after exit loop
        if (count > maxCount) {
            maxCount = count;
            maxChain = freeChainStart;
        }

        //error if not enough space
        if (maxCount < pages) {
            cout << "Error, Not enough memory for Program ";
            cout << file;
            cout << "\n";
            return;
        }
        //placing pages to stored node pointers
        for (int i = 0; i < pages; i++) {
            maxChain->fileName = file;
            maxChain->free = false;
            maxChain = maxChain->next;
        }
        //print success
            cout<<"Program "<<file<<" added successfully: "<<pages<<" page(s) used.\n";
    }
    else {
        //BESTFIT!------------------------------------------------------------------------------------------------------
        //------------------------------------------------------------------------------------------------------------
        int count = 0;
        int minCount = 128;
        //variable for storing node place
        node* minChain = NULL;
        node* freeChainStart = this->head;
        
        for (node* current = this->head; current != NULL; current = current->next) {
            if (count == 0) {
                freeChainStart = current;
            }
            if (current->free) count++;
            else {
                //switch if min
                if (count < minCount && count >= pages) {
                    minCount = count;
                    minChain = freeChainStart;
                }
                count = 0;
            }
        }
        //checking for the last node after exit loop
        if (count < minCount && count >= pages) {
            minCount = count;
            minChain = freeChainStart;
        }

        // if not enough space
        if (minCount == 128) {
            cout << "Error, Not enough memory for Program ";
            cout << file;
            cout << "\n";
            return;
        }
        //placing pages to stored node pointers
        for (int i = 0; i < pages; i++) {
            minChain->fileName = file;
            minChain->free = false;
            minChain = minChain->next;
        }
        //print success
        cout<<"Program "<<file<<" added successfully: "<<pages<<" page(s) used.\n";
    }
}


void MemoryList::kill(string file) {
    temp = head;
    bool found = false;
    int killCount=0;
    //check untill end
    while (temp != NULL) {
        //file name found
        if (temp->fileName == file) {
            temp->fileName = "Free";
            temp->free = true;
            found = true;
            killCount++;
        }
        //move to next node
        temp = temp->next;
    }
    //error
    if (!found) {
        cout << "Program not found\n";
    }
     if (found){
     	cout << "Program " << file << " successfully killed, "<<killCount<<" page(s) reclaimed.\n";
     } 
}

int MemoryList::fragments() {
    temp = head;
    int count = 0;
    int none = 0;
    //check entire list
    while (temp != NULL) {
        if (temp->free) {
            count++;
            none++;
            while (temp != NULL && temp->free) {
                temp = temp->next;
                none++;
            }
        }
        else {
            temp = temp->next;
        }
    }
    //returns 0 if whole list is empty
    if (none == 33){
    	return 0;
    }
    else{
    //check if last node is empty
    	temp = head;
   		for (int i =1;i<32;i++){
    		temp=temp->next;
    	}
    	if(!temp->free){
    		count++;
    	}
     return count;	
   
    }
}

int main(int argc, char ** argv) {
    MemoryList empty;

    //initialize with free memory
    for (int i = 0; i < 32; i++) {
        empty.add("Free");
    }

    //start arguments
    if (argc == 2) {
        string argument = argv[1];
        //best fit  case-----------------------------------------------------------------
        if (argument.compare("best") == 0) {
            cout << "Using best fit algorithm\n\n";
            bool worstfit = false;
            int choice = 0;
            string file = "";
            int fileSize = 0;
            //dashboard
            do {
                cout << "1. Add program\n2. Kill program\n3. Fragmentation\n4. Print memory\n5. Exit\n\n";
                cout << "choice - ";
                cin >> choice;
                //switch statement depending on choice
                switch (choice) {
                case 1:
                    cout << "Program name - ";
                    cin >> file;
                    cout << "Program size (KB) - ";
               	//check for invalid size
                    cin >> fileSize;
                    if (fileSize<=0){
                    	cout<<"Invalid input.";
                    	break;
                    }
                    empty.allocate(fileSize, file, worstfit);
                    break;
                case 2:
                    cout << "Program name - ";
                    cin >> file;
                    empty.kill(file);
                    break;
                case 3:
                    cout << "There are " << empty.fragments() << " fragment(s).\n";;
                    break;
                case 4:
                    empty.print();
                    cout << "\n";
                    break;
                default:
                //check for invalid inputs in menu options
                    cin.clear();
                    cin.ignore();
                }

            } while (choice != 5);
        }
        //worst fit
        else if (argument.compare("worst") == 0) {
            cout << "Using worst fit algorithm\n\n";
            bool worstfit = true;
            int choice = 0;
            string file = "";
            int fileSize = 0;
            //dashboard
            do {
                cout << "1. Add program\n2. Kill program\n3. Fragmentation\n4. Print memory\n5. Exit\n\n";
                cout << "choice - ";
                cin >> choice;
                //switch statement depending on choice
                switch (choice) {
                case 1:
                    cout << "Program name - ";
                    cin >> file;
                    cout << "Program size (KB) - ";
                    cin >> fileSize;
                    //check for invalid filesize
                    if (fileSize<=0){
                    	cout<<"Invalid input.";
                    	break;
                    }
                    empty.allocate(fileSize, file, worstfit);
                    break;
                case 2:
                    cout << "Program name - ";
                    cin >> file;
                    empty.kill(file);
                    break;
                case 3:
                    cout << "There are " << empty.fragments() << " fragment(s).\n";
                    break;
                case 4:
                    empty.print();
                    cout << "\n";
                    break;
                default:
                //check for invalid menu option inputs
                    cin.clear();
                    cin.ignore();
                }

            } while (choice != 5);
        }
    }
    else {
        cout << "Invalid arguments\n";
    }

    return 0;
}