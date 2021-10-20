#include "Simulate.h" //include header


Simulate::Simulate(){ //default
  m_userRows = 0;
  m_userCols = 0;
}

Simulate::Simulate(int userRows, int userCols){ //overloaded
  m_userRows = userRows;
  m_userCols = userCols;
}

Simulate::~Simulate(){ //destructor
  delete m_nextGen;
  delete m_currGen;
}

void Simulate::Run(GameOptions *go){ //run method
  m_currGen = go->getArray(); //gets varibales from game options class
  m_userRows = go->getRows();
  m_userCols = go->getCols();

  int gameType = go->getGameType();
  int outType = go->getOutType();

  m_nextGen = new char*[m_userRows]; //create new 2d array
  for(int i = 0; i < m_userRows; i++){
    m_nextGen[i] = new char[m_userCols];
  }


  if(outType == 1){ //types of output for game
    gameEnterNext(gameType);
  }
  if(outType == 2){
    gamePauseNext(gameType);
  }
  if(outType == 3){
    gameToFile(gameType);
  }
}



void Simulate::gameEnterNext(int gameType){ // method for all games that require pressing a button to continue
  int simNum = 1;
  if(gameType == 1){
    cout << "Simulation #: " << simNum << endl; //print first generation
    for(int i = 0; i < m_userRows; ++i){
      for(int j = 0; j < m_userCols; ++j){
        cout << m_currGen[i][j];
      }
      cout << endl;
    }

    Classic *game = new Classic(m_userRows,m_userCols); //create new classic game
    while(true){ // while loop

      string goAgain = "";
      cout << "Hit any key to continue to next generation" << endl;
      cin >> goAgain; //a pause requiring an input

      m_nextGen = createNextGenClassic(game); // create the next generation grid
      ++simNum; //increment simulation number
      cout << "Simulation #: " << simNum << endl; // print new generation
      for(int i = 0; i < m_userRows; ++i){
        for(int j = 0; j < m_userCols; ++j){
          cout << m_nextGen[i][j];
        }
        cout << endl;
      }

      if(isEqual()){ //if the two generations are equal, stop
        break;
      }

      for(int i = 0; i < m_userRows; ++i){ //update currenet generation to next generation
        for(int j = 0; j < m_userCols; ++j){
          m_currGen[i][j] = m_nextGen[i][j];
        }
      }
      for(int i = 0; i < m_userRows; i++){ // empty next generation
        for(int j = 0; j < m_userCols; ++j){
          m_nextGen[i][j] = '-';
        }
      }

    }
    cout << "end game" << endl;
  }

  if(gameType == 2){
    cout << "Simulation #: " << simNum << endl; //print first generation
    for(int i = 0; i < m_userRows; ++i){
      for(int j = 0; j < m_userCols; ++j){
        cout << m_currGen[i][j];
      }
      cout << endl;
    }

    Mirror *game = new Mirror(m_userRows,m_userCols); //create instant of a mirror game
    while(true){

      string goAgain = "";
      cout << "Hit any key to continue to next generation" << endl; //pause
      cin >> goAgain;

      ++simNum;
      m_nextGen = createNextGenMirror(game); //create new generation with the mirror rules
      cout << "Simulation #: " << simNum << endl;
      for(int i = 0; i < m_userRows; ++i){
        for(int j = 0; j < m_userCols; ++j){
          cout << m_nextGen[i][j]; //print out next gen
        }
        cout << endl;
      }
      if(isEqual()){
        break;
      }

      for(int i = 0; i < m_userRows; ++i){
        for(int j = 0; j < m_userCols; ++j){
          m_currGen[i][j] = m_nextGen[i][j]; // update current generation
        }
      }
      for(int i = 0; i < m_userRows; i++){
        for(int j = 0; j < m_userCols; ++j){
          m_nextGen[i][j] = '-';
        }
      }

    }
    cout << "end game" << endl;
  }

  if(gameType == 3){
    cout << "Simulation #: " << simNum << endl; //print original grid
    for(int i = 0; i < m_userRows; ++i){
      for(int j = 0; j < m_userCols; ++j){
        cout << m_currGen[i][j];
      }
      cout << endl;
    }

    Donut *game = new Donut(m_userRows,m_userCols); // instance of a new game donut
    while(true){

      string goAgain = "";
      cout << "Hit any key to continue to next generation" << endl; //pause
      cin >> goAgain;

      ++simNum;
      m_nextGen = createNextGenDonut(game); //create next generation with donut rules
      cout << "Simulation #: " << simNum << endl;
      for(int i = 0; i < m_userRows; ++i){
        for(int j = 0; j < m_userCols; ++j){
          cout << m_nextGen[i][j]; //print out next generation
        }
        cout << endl;
      }
      if(isEqual()){
        break;
      }
      for(int i = 0; i < m_userRows; ++i){ // update current gen
        for(int j = 0; j < m_userCols; ++j){
          m_currGen[i][j] = m_nextGen[i][j];
        }
      }
      for(int i = 0; i < m_userRows; i++){
        for(int j = 0; j < m_userCols; ++j){
          m_nextGen[i][j] = '-';
        }
      }
    }
    cout << "end game" << endl;
  }
}

void Simulate::gamePauseNext(int gameType){ //for all games that need an internal computer pause
  int simNum = 1;
  if(gameType == 1){
    cout << "Simulation #: " << simNum << endl; //print first generation
    for(int i = 0; i < m_userRows; ++i){
      for(int j = 0; j < m_userCols; ++j){
        cout << m_currGen[i][j];
      }
      cout << endl;
    }

    Classic *game = new Classic(m_userRows,m_userCols); //create a clssic game
    while(true){
      std::this_thread::sleep_for (std::chrono::seconds(2)); //sleep for 2 seconds between iterations
      ++simNum;
      m_nextGen = createNextGenClassic(game);
      cout << "Simulation #: " << simNum << endl;
      for(int i = 0; i < m_userRows; ++i){
        for(int j = 0; j < m_userCols; ++j){
          cout << m_nextGen[i][j]; //print next generation
        }
        cout << endl;
      }
      if(isEqual()){
        break;
      }
      for(int i = 0; i < m_userRows; ++i){
        for(int j = 0; j < m_userCols; ++j){
          m_currGen[i][j] = m_nextGen[i][j]; // update current generation
        }
      }
      for(int i = 0; i < m_userRows; i++){
        for(int j = 0; j < m_userCols; ++j){
          m_nextGen[i][j] = '-';
        }
      }
    }
    cout << "end game" << endl;
  }

  if(gameType == 2){
    cout << "Simulation #: " << simNum << endl; //print first generation
    for(int i = 0; i < m_userRows; ++i){
      for(int j = 0; j < m_userCols; ++j){
        cout << m_currGen[i][j];
      }
      cout << endl;
    }

    Mirror *game = new Mirror(m_userRows,m_userCols); //new mirror game
    while(true){
      std::this_thread::sleep_for (std::chrono::seconds(2)); //sleep

      ++simNum;
      m_nextGen = createNextGenMirror(game); //create next gen with mirror rules
      cout << "Simulation #: " << simNum << endl;
      for(int i = 0; i < m_userRows; ++i){
        for(int j = 0; j < m_userCols; ++j){
          cout << m_nextGen[i][j]; //print next generation
        }
        cout << endl;
      }
      if(isEqual()){ //if they are equal, break
        break;
      }
      for(int i = 0; i < m_userRows; ++i){
        for(int j = 0; j < m_userCols; ++j){
          m_currGen[i][j] = m_nextGen[i][j]; //update current gen
        }
      }
      for(int i = 0; i < m_userRows; i++){
        for(int j = 0; j < m_userCols; ++j){
          m_nextGen[i][j] = '-';
        }
      }
    }
    cout << "end game" << endl;
  }

  if(gameType == 3){
    cout << "Simulation #: " << simNum << endl; //print first generation
    for(int i = 0; i < m_userRows; ++i){
      for(int j = 0; j < m_userCols; ++j){
        cout << m_currGen[i][j];
      }
      cout << endl;
    }

    Donut *game = new Donut(m_userRows,m_userCols); //create new donut game
    while(true){

      std::this_thread::sleep_for (std::chrono::seconds(2)); // sleep

      ++simNum;
      m_nextGen = createNextGenDonut(game); //create next gen with donut rules
      cout << "Simulation #: " << simNum << endl;
      for(int i = 0; i < m_userRows; ++i){
        for(int j = 0; j < m_userCols; ++j){
          cout << m_nextGen[i][j];
        }
        cout << endl;
      }
      if(isEqual()){
        break;
      }
      for(int i = 0; i < m_userRows; ++i){
        for(int j = 0; j < m_userCols; ++j){
          m_currGen[i][j] = m_nextGen[i][j]; //update current gen
        }
      }
      for(int i = 0; i < m_userRows; i++){
        for(int j = 0; j < m_userCols; ++j){
          m_nextGen[i][j] = '-';
        }
      }
    }
    cout << "end game" << endl;
  }
}

void Simulate::gameToFile(int gameType){ //for all game that will write to a file
  string outputFile = "";
  cout << "Enter output filename:" << endl; //need the file name to write to
  cin >> outputFile;
  int simNum = 1;
  outFS.open(outputFile); //open that file
  if(gameType == 1){
    outFS << "Simulation #: " + simNum;
    for(int i = 0; i < m_userRows; ++i){
      for(int j = 0; j < m_userCols; ++j){
        outFS << m_currGen[i][j]; //print first generation
      }
      outFS << endl;
    }

    Classic *game = new Classic(m_userRows,m_userCols); //create classic game
    while(true){
      ++simNum;
      m_nextGen = createNextGenClassic(game); //create next gen with classic rules
      outFS << "Simulation #: " << simNum << endl;
      for(int i = 0; i < m_userRows; ++i){
        for(int j = 0; j < m_userCols; ++j){
          outFS << m_nextGen[i][j]; //print next gen
        }
        outFS << endl;
      }
      if(isEqual()){
        break;
      }
      for(int i = 0; i < m_userRows; ++i){
        for(int j = 0; j < m_userCols; ++j){
          m_currGen[i][j] = m_nextGen[i][j]; //update current gen
        }
      }
      for(int i = 0; i < m_userRows; i++){
        for(int j = 0; j < m_userCols; ++j){
          m_nextGen[i][j] = '-';
        }
      }
    }
    cout << "end game" << endl;
  }

  if(gameType == 2){
    outFS << "Simulation #: " << simNum << endl; //output first generation
    for(int i = 0; i < m_userRows; ++i){
      for(int j = 0; j < m_userCols; ++j){
        outFS << m_currGen[i][j];
      }
      outFS << endl;
    }

    Mirror *game = new Mirror(m_userRows,m_userCols); // new mirror game
    while(true){
      ++simNum;
      m_nextGen = createNextGenMirror(game); //create next gen with mirror rules
      outFS << "Simulation #: " << simNum << endl;
      for(int i = 0; i < m_userRows; ++i){
        for(int j = 0; j < m_userCols; ++j){
          outFS << m_nextGen[i][j]; //print next gen
        }
        outFS << endl;
      }
      if(isEqual()){
        break;
      }
      for(int i = 0; i < m_userRows; ++i){
        for(int j = 0; j < m_userCols; ++j){
          m_currGen[i][j] = m_nextGen[i][j]; //update current gen
        }
      }
      for(int i = 0; i < m_userRows; i++){
        for(int j = 0; j < m_userCols; ++j){
          m_nextGen[i][j] = '-';
        }
      }
    }
    cout << "end game" << endl;
  }

  if(gameType == 3){
    outFS << "Simulation #: " << simNum << endl; //output first gen
    for(int i = 0; i < m_userRows; ++i){
      for(int j = 0; j < m_userCols; ++j){
        outFS << m_currGen[i][j];
      }
      outFS << endl;
    }

    Donut *game = new Donut(m_userRows,m_userCols); //create new donut game
    while(true){
      ++simNum;
      m_nextGen = createNextGenDonut(game); //create next gen with donut rules
      outFS << "Simulation #: " << simNum << endl;
      for(int i = 0; i < m_userRows; ++i){
        for(int j = 0; j < m_userCols; ++j){
          outFS << m_nextGen[i][j];//print next gen
        }
        outFS << endl;
      }
      if(isEqual()){
        break;
      }
      for(int i = 0; i < m_userRows; ++i){
        for(int j = 0; j < m_userCols; ++j){
          m_currGen[i][j] = m_nextGen[i][j]; //update current gen
        }
      }
      for(int i = 0; i < m_userRows; i++){
        for(int j = 0; j < m_userCols; ++j){
          m_nextGen[i][j] = '-';
        }
      }
    }
    cout << "end game" << endl;
  }
}

char** Simulate::createNextGenClassic(Classic* game){ //create next gen with classic rules
  int neighbors = 0;
  for(int i = 0; i < m_userRows; ++i){
    for(int j = 0; j < m_userCols; ++j){
      int neighbors = game->gameClassic(i,j,m_currGen); // look at grid with classic rules
      if(neighbors <= 1){ //check how many neighbors each cell has - populate correctly
        m_nextGen[i][j] = '-';
      }else if(neighbors == 2){
        if(m_currGen[i][j] =='X'){
          m_nextGen[i][j] = 'X';
        }else{
          m_nextGen[i][j] = '-';
        }
      }else if(neighbors == 3){
        m_nextGen[i][j] = 'X';
      }else{
        m_nextGen[i][j] = '-';
      }
    }
  }
  return m_nextGen; // return the new array
}

char** Simulate::createNextGenMirror(Mirror* game){ //create next gen with mirror rules
  int neighbors = 0;
  for(int i = 0; i < m_userRows; ++i){
    for(int j = 0; j < m_userCols; ++j){
        int neighbors = game->gameMirror(i,j,m_currGen); //for every cell, check how many neigbors using mirror rules
      if(neighbors <= 1){ //check neighbors, populate next gen correctly
        m_nextGen[i][j] = '-';
      }else if(neighbors == 2){
        if(m_currGen[i][j] =='X'){
          m_nextGen[i][j] = 'X';
        }else{
          m_nextGen[i][j] = '-';
        }
      }else if(neighbors == 3){
        m_nextGen[i][j] = 'X';
      }else{
        m_nextGen[i][j] = '-';
      }
    }
  }
  return m_nextGen; //return the new array
}

char** Simulate::createNextGenDonut(Donut* game){ //create method to check grid with donut rules
  int neighbors = 0;
  for(int i = 0; i < m_userRows; ++i){
    for(int j = 0; j < m_userCols; ++j){
        int neighbors = game->gameDonut(i,j,m_currGen); //check each cell for neighbors
      if(neighbors <= 1){ //check neigbors - populate correctly
        m_nextGen[i][j] = '-';
      }else if(neighbors == 2){
        if(m_currGen[i][j] =='X'){
          m_nextGen[i][j] = 'X';
        }else{
          m_nextGen[i][j] = '-';
        }
      }else if(neighbors == 3){
        m_nextGen[i][j] = 'X';
      }else{
        m_nextGen[i][j] = '-';
      }
    }
  }
  return m_nextGen; //return new array
}

bool Simulate::isEqual(){ //method to check if current gen = next gen
  for(int i = 0; i < m_userRows; ++i){
    for(int j = 0; j < m_userCols; ++j){
      if(m_nextGen[i][j] != m_currGen[i][j]){ //if they are not equalm then the whole array isnt equal
        return false;
      }
    }
  }
  return true;
}
