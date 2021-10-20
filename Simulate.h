#include "GameOptions.h" // import needed packages
#include "Classic.h"
#include "Mirror.h"
#include "Donut.h"
#include <thread>
#include <chrono>

using namespace std;

class Simulate{ //create class
public:
  Simulate(); //default
  Simulate(int userRows, int userCols); //overloaded
  ~Simulate(); //destructor
  void Run(GameOptions *go); //run method that takes in an instance of the game options class
  void gameEnterNext(int gameType); // methods for game output
  void gamePauseNext(int gameType);
  void gameToFile(int gameType);
  char** createNextGenClassic(Classic* game); //methods for creating the next generation based on game mode
  char** createNextGenMirror(Mirror* game);
  char** createNextGenDonut(Donut* game);
  bool isEqual();

private:
  ofstream outFS; // for writing to files
  char** m_currGen; // create memeber varibles
  char** m_nextGen;
  int m_userRows;
  int m_userCols;
};
