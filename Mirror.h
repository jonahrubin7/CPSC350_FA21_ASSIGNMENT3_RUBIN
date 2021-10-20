#include <iostream> //packages
using namespace std;

class Mirror{ //mirror class with mirror rules
public:
  Mirror(); //default
  Mirror(int i, int j); //overloaded
  ~Mirror(); //destructor
  int gameMirror(int i, int j, char** currGen); //method
private:
  int m_userRows; //member varibles
  int m_userCols;
};
