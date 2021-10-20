#include <iostream> //packages

using namespace std;

class Classic{ //classic game mode
public:
  Classic(); //default
  Classic(int i, int j); //overloaded
  ~Classic(); //destructor
  int gameClassic(int i, int j, char** currGen); //method
private:
  int m_userRows; //member variables
  int m_userCols;
};
