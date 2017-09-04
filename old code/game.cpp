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
#include "entity.h"
#include <string>

using namespace std;

//Global variables set to default values
bool alive;
bool questOnePass = false;
bool questTwoPass = false;
bool questThreePass = false;
int fightCount = 0;
bool hasShoes = false;
int caveCount = 0;
string sideQuest;

//"fight" mechanic that compares player strength to enemy strength.
//Random number element that highly favors success if you are stronger than enemy, but very unfavored if not.
bool fight(Player you, Player enemy){
  int rng = rand() % 100 +1;
  if(you.getStrength() >= enemy.getStrength()){
    if(rng>=10){
      return true;
    }else{
      return false;
    }
  }else{
    if(rng>=90){
      return true;
    }else{
      return false;
    }
  }
}
//Player encounters trolls in this main checkpoint scene. By hiding long enough the player easily defeats the trolls.
void trollScene(Player &mainPlayer){
  int input;
  int hideCount = 0;
  cout<<"Trolls!\n0. Hide from the trolls.\n1. Attack the trolls."<<endl;
  Player troll(15,1,"Troll");

  while(true){
    cin >> input;
    if(cin.fail() || input < 0 || input > 1){
      cout << "Invalid Input, try again \n";
      cin.clear();
      cin.ignore(10000,'\n');
    }
    else{
      break;
    }
  }
  while(hideCount != 6 && input == 0){
    hideCount++;
    cout<<"You're crouching behind a rock. The trolls don't seem to have noticed you yet.\n0. Hide from the trolls.\n1. Attack the trolls."<<endl;
    while(true){
      cin >> input;
      if(cin.fail() || input < 0 || input > 1){
        cout << "Invalid Input, try again \n";
        cin.clear();
        cin.ignore(10000,'\n');
      }
      else{
        break;
      }
    }

  }
  if(hideCount == 6){
    cout<<"You sneeze and your location is revealed. The trolls start to close in. You begin to run but you know it's too late. You've been crouching behind a rock all night and your legs are tired. Suddenly the sun starts to rise and you hear a strange groan behind you. You turn, and to your surprise, the trolls have been turned to stone. You keep walking."<<endl;
    questOnePass = true;
  }
  if(input == 1){
    if(fight(mainPlayer, troll)){
      cout<<"You attack the trolls and succeed!"<<endl;
      questOnePass = true;
    }else{
      cout<<"You attack the trolls and die. Game over."<<endl;
      alive = false;
    }
  }
}
//Player encounters a dragon in this main checkpoint scene. By wielding a sword obtained from the sphinx scene, the
//dragon is easily defeated, otherwise, sneaking past may be successful.
void dragonScene (Player &mainPlayer) {
  int input;
  cout << "In the distance you spot a dragon in your path. There are no other routes. You get closer and notice it is fast asleep.\n0. Try and sneak past the dragon.\n1. Fight the dragon."<<endl;
  Player dragon (45,20,"Dragon");

  while(true){
    cin >> input;
    if(cin.fail() || input < 0 || input > 1){
      cout << "Invalid Input, try again \n";
      cin.clear();
      cin.ignore(10000,'\n');
    }
    else{
      break;
    }
  }


  switch (input) {
    case 0: if(mainPlayer.getStealth() > dragon.getStealth()){
      cout << "You successfully snuck past the dragon while it slept." << endl;
      questThreePass = true;
    }else{
      cout << "You woke the dragon and in a fit of rage it kills you." << endl;
      alive = false;
    }
    break;
    case 1: if(mainPlayer.getHasSword()){
      cout << "You use your sword and effortlessly slay the dragon." << endl;
      questThreePass = true;
    }else if(fight(mainPlayer, dragon)){
      cout << "You fought the dragon and slew it." << endl;
      questThreePass = true;
    }else{
      cout << "The dragon slew you." << endl;
      alive = false;
    }
    break;
  }
}
//Player encounters a sphinx in this main checkpoint scene. Answering the riddle correctly allows the
//player to move further into the game. Failure leads to game over. If the riddle is answered correctly on the first try the player
//receives a Dragonslaying sword.
void sphinxScene (Player &mainPlayer) {

  cout << "You encounter a Sphinx and it wants to ask you a riddle before you may pass. The answer to the riddle is only one word. You have three tries to answer the riddle so answer carefully." << endl;

  int attemptsUsed = AskRiddle();
  switch (attemptsUsed)
  {
    case 1:
    cout << "\"Congratulations. You have passed the test of time.\"" << endl;
    cout << "\"Take this sword, as a gift. It might prove useful in the future.\"" << endl;
    mainPlayer.setHasSword();
    questTwoPass = true;
    break;
    case 2:
    cout << "\"Congratulations. You have passed the test of time.\"" << endl;
    questTwoPass = true;
    break;
    case 3:
    cout << "\"Congratulations. You have passed the test of time.\"" << endl;
    questTwoPass = true;
    break;
    case 4:
    cout << "\"You are out of tries. Game Over.\""<<endl;
    alive = false;
    break;

  }

}
//The final scene, the player enters a castle where randomly generated monsters continue to spawn until the player
//is defeated.
void castleScene (Player &mainPlayer) {
  int input;
  int rn = rand() % 4;
  string monsterName;
  if (rn == 3) monsterName = "snake";
  else if (rn == 2) monsterName = "rabid princess";
  else if (rn == 1) monsterName = "bear";
  else monsterName = "vicious beast";
  int monsterStrength = (rand() % 15) + 5;
  int monsterStealth = (rand() % 15) + 5;
  Player monster(monsterStrength, monsterStealth, monsterName);
  cout << "Up ahead you see a castle. You feel compelled to enter. Suddenly a " << monsterName << " jumps out at you.\n0. Try and sneak past the " << monsterName << ".\n1. Fight the " << monsterName <<"."<<endl;

  while(true){
    cin >> input;
    if(cin.fail() || input < 0 || input > 1){
      cout << "Invalid Input, try again \n";
      cin.clear();
      cin.ignore(10000,'\n');
    }
    else{
      break;
    }
  }

  switch (input) {
    case 0: if (mainPlayer.getStealth() > monster.getStealth()) {
      cout << "You successfully snuck past the " << monsterName << "." << endl;
    }
    else {
      cout << "The " << monsterName << " notices you in your sad attempt to hide and in a fit of rage it kills you.\n" << endl;
      alive = false;
    }
    break;
    case 1: if (fight (mainPlayer, monster)) {
      cout << "You fought the " << monsterName << " and slew it." << endl;
    }
    else {
      cout << "The " << monsterName << " slew you." << endl;
      alive = false;
    }
    break;
  }
  int fightCount = 0;
  while(alive){
    rn = rand() % 4;
    if (rn == 3) monsterName = "snake";
    else if (rn == 2) monsterName = "rabid princess";
    else if (rn == 1) monsterName = "bear";
    else monsterName = "vicious beast";
    int monsterStrength = (rand() % 15) + 5;
    int monsterStealth = (rand() % 15) + 5;
    Player monster(monsterStrength, monsterStealth, monsterName);
    cout<<"You go further into the castle. Suddenly a " << monsterName << " jumps out at you.\n0. Try and sneak past the " << monsterName <<
    ".\n1. Fight the " << monsterName <<"."<<endl;

    while(true){
      cin >> input;
      if(cin.fail() || input < 0 || input > 1){
        cout << "Invalid Input, try again \n";
        cin.clear();
        cin.ignore(10000,'\n');
      }
      else{
        break;
      }
    }

    switch (input) {
      case 0: if (mainPlayer.getStealth() > monster.getStealth()) {
        cout << "You successfully snuck past the " << monsterName << "." << endl;
        fightCount++;
      }
      else {
        cout << "The " << monsterName << " notices you in your sad attempt to hide and in a fit of rage it kills you.\n" << endl;
        alive = false;
      }
      break;
      case 1: if (fight(mainPlayer, monster)) {
        cout << "You fought the " << monsterName << " and slew it." << endl;
        fightCount++;
      }
      else {
        cout << "The " << monsterName << " slew you." << endl;
        alive = false;
      }
      break;
    }
  }
  if (fightCount > 5)
  {
    mainPlayer.setStrength(1);
    mainPlayer.setStealth(1);
  }
}
//A sidequest scene. The player is given the option to fight and doing so rewards in increased strength points.
void tavern(Player &mainPlayer){
  cout << "While exploring you notice a building in the distance, upon closer inspection you see a sign that says: Drunken Horseman Tavern\nYou enter the tavern and notice they are holding bar fights."<<endl;
  int choice;
  while(true){
    int i = rand() % 10;
    cout << "What would you like to do?\n0. Leave the tavern.\n1. Fight." << endl;
    cin >> choice;
    if(cin.fail() || choice < 0 || choice > 1){
      cout << "Invalid Input, try again \n";
      cin.clear();
      cin.ignore(10000,'\n');
    }else if(choice == 1 && fightCount < 4 && i > 2){
      cout << "You enter the ring and made quick work of your opponent \n";
      mainPlayer.addStrength();
      ++fightCount;
    }else if(choice == 1 && fightCount >= 4){
      cout << "You have grown too tired for another fight." << endl;
    }
    else if(choice == 1 && fightCount < 3 && i <= 2){
      cout << "Your opponent was much bigger than expected and beat you up. \n" <<endl;
      ++fightCount;
    }
    else if(choice == 0){
      return;
    }
    else{
      cout << "You have grown too tired for another fight." << endl;
      return;
    }
  }
}
//A sidequest scene. The player is given the option to either fight monsters or evade them, granting strength points or stealth points respectively.
void cave(Player &mainPlayer){
  if(caveCount != 0){
    cout<<"The cave you entered previously has collapsed."<<endl;
    return;
  }
  cout << "You have discovered a cave.\nYou decide to enter in the hopes that there might be treasure.\n";
  int choice;

  string caveEncounters[] = {"some cave bats", "a giant centipede", "a bear", "a giant lizard", "a golem"};

  for (int i = 0; i < 6; i++) {
    if (i < 5) {
      cout << "You encounter "<<caveEncounters[i]<<".\n0. Fight them.\n1. Run past them, further into the cave." << endl;
      cin >> choice;
      if(cin.fail() || choice < 0 || choice > 1) {
        cout << "Invalid Input, try again \n";
        cin.clear();
        cin.ignore(10000,'\n');
      }
      else if (choice == 0){
        cout << "You kill the beast and absorbed their strength." << endl;
        mainPlayer.addStrength();
      }
      else if (choice == 1) {
        cout << "You managed to escape." << endl;
        mainPlayer.addStealth();
      }
    }
    else if (i == 5) {
      caveCount++;
      cout << "You have discovered a treasure chest at the end of the cave.\nEagerly, you open the chest and discover that it is empty.\nYou decide to leave the cave disappointed.";
    }
  }
}
//A sidequest scene. The player is given the option to assist a boy, and doing so increases stealth.
void forest(Player &mainPlayer){
  if (hasShoes == true){
    cout<<"You enter a peaceful forest. There's not much to do here. \n";
  }
  else{
    cout << "While exploring you enter a forest. You spot a little boy wandering around alone. \n"<<endl;
  }
  int choice = 0;
  while(hasShoes == false){
    cout << "What would you like to do?\n0. He's probably lost. Offer help.\n1. I don't talk to strangers. Continue walking." << endl;
    cin >> choice;
    if(cin.fail() || choice < 0 || choice > 1){
      cout << "Invalid Input, try again \n";
      cin.clear();
      cin.ignore(10000,'\n');
    }else if(choice == 0 ){
      cout << "The boy thanks you for your kindness and offers you new shoes. \n";
      hasShoes = true;
      mainPlayer.addStealth();
    }
    else{
      return;
    }
  }
}

//Input selector that after displaying the menu directs the player(and Player Object) to the appropriate task.
void inputSelection(int input, int race, Player &mainPlayer){
  if(cin.fail() || input < 0 || input > 2){
    cin.clear();
    cout <<"Selection not found. Try again.\n";
    cin.ignore(10000,'\n');
  }else if(input == 0){
    sideQuest = "Explore";
    if(questOnePass == false){
      trollScene(mainPlayer);
    }else if(questTwoPass == false){
      sphinxScene(mainPlayer);
    }else if(questThreePass == false){
      dragonScene(mainPlayer);
    }else{
      castleScene(mainPlayer);
    }
  }else if(input == 1){
    if(questOnePass == false){
      sideQuest = "Tavern";
      tavern(mainPlayer);
    }else if(questTwoPass == false){
      sideQuest = "Forest";
      forest(mainPlayer);
    }else if(questThreePass == false){
      sideQuest = "Cave";
      cave(mainPlayer);
    }else{
      cout<<"You go exploring and find nothing of interest."<<endl;
    }
  }else if(input == 2){
    mainPlayer.printStats(race);
  }

}
//Main function, that holds variables and calls to functions integral to starting/maintaining the game as well as making a character.
int main(){
  alive = true;
  string name;
  int input;
  int race;
  cout << "Enter Name: ";
  cin >> name;
  Player mainPlayer(0,0,name);
  sideQuest = "Explore";

  while(true){
    cout << "Select your race:\n";
    cout <<"1. Elf\n2. Orc\n3. Nord\n4. Goblin\n5. Human\n";
    cin >> race;
    if(cin.fail() || race > 5 || race < 1){
      cin.clear();
      cout <<"Selection not found. Try again.\n";
      cin.ignore(10000,'\n');
    }else{
      break;
    }
  }

  switch(race){
    case 1:
    mainPlayer.setStrength(1);
    mainPlayer.setStealth(10);
    break;
    case 2:
    mainPlayer.setStrength(10);
    mainPlayer.setStealth(1);
    break;
    case 3:
    mainPlayer.setStrength(8);
    mainPlayer.setStealth(3);
    break;
    case 4:
    mainPlayer.setStrength(3);
    mainPlayer.setStealth(8);
    break;
    case 5:
    mainPlayer.setStrength(5);
    mainPlayer.setStealth(5);
    break;
    default:
    break;
  }

  while(true){
    cout << "Welcome, "<<mainPlayer.getName()<<". You are on a road.\n0. Go forward.\n1. Explore.\n2. View stats."<<endl;
    cin >> input;
    inputSelection(input, race, mainPlayer);

    while(alive){
      cout<<"You are back on a road.\n0. Go forward.\n1. "<<sideQuest<<".\n2. View stats."<<endl;
      cin>>input;
      inputSelection(input, race, mainPlayer);
    }

    int decide;
    cout << "Would you like to try again?\n0. Yes\n1. No"<<endl;
    cin >> decide;

    while(cin.fail() || decide > 1 || decide < 0){
      cin.clear();
      cout <<"Selection not found. Try again.\n";
      cin.ignore(10000,'\n');
      cin >> decide;
    }

    if(decide == 0){
      alive = true;
    }else{
      return 0;
    }
  }
}