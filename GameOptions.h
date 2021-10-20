#include <iostream> //import the nessesary packages
#include <fstream>
#include <random>
#include <thread>
#include <stdio.h>
#include <stdlib.h>
#include<time.h>

using namespace std; //standard name space

class GameOptions{ //create class
public:
  GameOptions(); // default
  GameOptions(int userRows, int userCols, int gameType, int outType); //overloaded
  ~GameOptions(); // destructor
  char** getArray(); //create all the methods
  void createArrayFile();
  void createArrayInput();
  int getOutType();
  int getGameType();
  int getRows();
  int getCols();
  void setUp();

private: //create all the member variables
  int m_userRows;
  int m_userCols;
  char** m_arr;
  int m_gameType;
  int m_outType;
};
