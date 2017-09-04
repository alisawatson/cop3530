/*
Project Team 18 Presents:
Final Project Spring 2017
Team Members:
Alex deQuevedo
Andres Hernandez
Alisa Watson
Brendan Cohen
Janine Faith Penaflorida
Maxwell Nolan
Yi Lin
*/
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

string title[] = {"Elf","Orc","Nord","Goblin","Human"};
/******************
//Player Class//
******************/
class Player {
private:
    string name;
    bool hasSword;
    int strength;
    int stealth;
public:
    Player(int, int, string);
    
    void setName(string);
    void setHasSword();
    void setStrength(int);
    void setStealth(int);
    
   
    
    void printStats(int);
    
    bool attack(Player);
    
    void addStrength();
    void addStealth();
    void addStrength(int);
    void addStealth(int);
    
    string getName();
    bool getHasSword();
    int getStrength();
    int getStealth();
};

int Player::getStrength(){
    return strength;
}
int Player::getStealth(){
    return stealth;
}

void Player::setStrength(int str){
    this->strength = str;
}
void Player::setStealth(int sth){
    this->stealth = sth;
}

Player::Player(int str, int sth, string name) {
    this->name = name;
    this->hasSword = false;
    this->strength = str;
    this->stealth = sth;
}

void Player::setName(string name) {
    this->name = name;
}

void Player::setHasSword() {
    this->hasSword = true;
}

string Player::getName() {
    return name;
}

bool Player::getHasSword() {
    return hasSword;
}

void Player::printStats(int race) {
    cout << name << ", the "<< title[race-1] << endl;
    cout << "Strength: " << strength << endl;
    cout << "Stealth: " << stealth << "\n"<< endl;
}

void Player::addStrength(){
    int i = (rand() % 9) + 1;
    cout << "You gained " << i << " Strength points\n" << "\n";
    Player::addStrength(i);
}

void Player::addStealth(){
    int i = (rand() % 9) + 1;
    cout << "You gained " << i << " Stealth points\n" << "\n";
    Player::addStealth(i);
}

void Player::addStrength(int i){
    this->strength = strength + i;
}
void Player::addStealth(int i){
    this->stealth = stealth + i;
}
/******************
//Sphinx Subclass//
******************/
class Sphinx {

public:
    int AskRiddle();
};




int AskRiddle() //returns the number of tries that  it took (1-3) tries, or 4 if the player fails
{
    srand(time(NULL));
    int random_integer = (rand() % 10) + 1; // get random number to be converted to string
    string question;
    string answer;
    switch (random_integer) // all riddles have one word/letter answers
    {
    case 1:
        question = "Poor people have it. Rich people need it. If you eat it you die. What is it?";
        answer = "nothing";
        break;
    case 2:
        question = "If I drink, I die. If I eat, I am fine. What am I?";
        answer = "fire";
        break;
    case 3:
        question = "What word becomes shorter when you add two letters to it?";
        answer = "short";
        break;
    case 4:
        question = "What kind of tree can you carry in your hand?";
        answer = "palm";
        break;
    case 5:
        question = "We see it once in a year, twice in a week, and never in a day. What is it?";
        answer = "e";
        break;
    case 6:
        question = "The more it dries, the wetter it becomes. What is it?";
        answer = "towel";
        break;
    case 7:
        question = "I have keys but no locks. I have space but no room. You can enter but can't go outside. What am I?";
        answer = "keyboard";
        break;
    case 8:
        question = "What has many keys, but can't open even a single door?";
        answer = "piano";
        break;
    case 9:
        question = "What is black when you buy it, red when you use it, and gray when you throw it away?";
        answer = "charcoal";
        break;
    case 10:
        question = "I am full of holes but I can still hold water. What am I?";
        answer = "sponge";
        break;

    }
    cout << question << endl;
    string playerAnswer;
    

    for (int i = 1; i < 4; i++)
    {
        cin >> playerAnswer;

        if (playerAnswer.compare(answer) == 0)
        {
            cout << "Correct!" << endl;
            return i;
        }
        else
        {
            cout << "WRONG!!" << endl;
        }


    }

    return 4;


}
