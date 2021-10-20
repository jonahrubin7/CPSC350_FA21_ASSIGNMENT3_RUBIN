#include <iostream> //packages
using namespace std;

class Donut{ //class for donut rules
public:
  Donut(); //default
  Donut(int i, int j); //overloaded
  ~Donut(); //destructor
  int gameDonut(int i, int j, char** currGen); //method
private:
  int m_userRows; //member variables
  int m_userCols;
};
