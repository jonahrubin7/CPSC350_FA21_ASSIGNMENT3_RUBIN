#include "GameOptions.h" //include header file

GameOptions::GameOptions(){ //default
  m_userRows = 0;
  m_userCols = 0;
  m_gameType = 0;
  m_outType = 0;
}

GameOptions::GameOptions(int userRows, int userCols, int gameType, int outType){ //overloaded
  m_userRows = userRows;
  m_userCols = userCols;
  m_gameType = gameType;
  m_outType = outType;
}

GameOptions::~GameOptions(){ //destructor

}

void GameOptions::setUp(){ //set up takes in most of the user inputs
  string outFileName = "";
  while(m_gameType != 1 && m_gameType != 2 && m_gameType != 3){
    cout << "Which game mode would you like?\n Type: \n 1:Classic \n 2:Mirror \n 3:Donut" <<endl;
    cin >> m_gameType;
  }
  while(m_outType != 1 && m_outType != 2 && m_outType != 3){
    cout << "If you would like to hit any button to move on to the next generation, type: 1" << endl;
    cout << "If you would like the computer to have a breif pause between generations, type: 2" << endl;
    cout << "If you would like to print everything to a file, type: 3" << endl;
    cin >> m_outType;
  }
}

char** GameOptions::getArray(){ //get the original array method
  return m_arr;
}

int GameOptions::getGameType(){ //returning game type
  return m_gameType;
}

int GameOptions::getOutType(){ // returns the out type
  return m_outType;
}

int GameOptions::getRows(){ //returns how many rows
  return m_userRows;
}

int GameOptions::getCols(){ // returns nuber of columns
  return m_userCols;
}

void GameOptions::createArrayFile(){ // creates an array from an input file
  ifstream inFS;
  string filename;
  int lineNum = 0;
  string line = "";

  cout<<"Enter input File Name"<< endl;
  cin>>filename; //take in file name
  inFS.open(filename);
  if(!inFS.is_open()){
    cout<< "There was an Error: File could not be opened" << endl;
    exit(0);
  }
  while(inFS >> line){
    if(lineNum == 0){ // take in the first line
      m_userRows = stoi(line);
      ++lineNum;
    }else if(lineNum == 1){ //take in second line
      m_userCols = stoi(line);
      ++lineNum;
      m_arr = new char*[m_userRows]; // create 2d array
      for(int i = 0; i < m_userRows; i++){
        m_arr[i] = new char[m_userCols];
      }
    }else{
      if(!inFS.fail()){
        for(int i = 0; i < line.size(); i++){
          m_arr[lineNum-2][i] = line[i];
        }
      }
      ++lineNum;
    }
  }
  inFS.close();
}

void GameOptions::createArrayInput(){ // create an array from user inputs
  float popDens = 0;

  cout << "Please enter the number of rows you would like:" << endl;
  cin >> m_userRows;
  cout << "Please enter the number of Columns you would like:" << endl;
  cin >> m_userCols;
  cout << "Please enter your desired population density (number between 0 and 1):" << endl;
  cin >> popDens;

  m_arr = new char*[m_userRows]; //create 2d array
  for(int i = 0; i < m_userRows; i++){
    m_arr[i] = new char[m_userCols];
  }

  int numX = popDens * m_userCols * m_userRows; // calculate how many x's should be made
  int countX = 0;
  int i;
  int j;
  srand(time(0)); //set time to 0
  while(countX < numX){
    i = rand() % m_userRows; //randomly generate number less than or equal to number of rows and columns
    j = rand() % m_userCols;
    if(m_arr[i][j] != 'X'){
      m_arr[i][j] = 'X';
      ++countX;
    }
  }
  for(int i = 0; i < m_userRows; i++){ //print out array
    for(int j = 0; j < m_userCols; j++){
      if(m_arr[i][j] != 'X'){
        m_arr[i][j] = '-';
      }
    }
  }
}
