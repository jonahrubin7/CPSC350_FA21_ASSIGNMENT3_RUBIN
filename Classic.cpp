#include "Classic.h"

Classic::Classic(){ //default
  m_userRows;
  m_userCols;
}

Classic::Classic(int userRows, int userCols){  //overloaded
  m_userRows = userRows;
  m_userCols = userCols;
}

Classic::~Classic(){ //destructor

}

int Classic::gameClassic(int i, int j, char** currGen){ //run rules
  int numNeighbors = 0;
  int cols = m_userCols - 1;
  int rows = m_userRows - 1;
  //i = y
  //j = x i think

  if(i == 0 && (j != 0 && j != cols)){ //top row
    if(currGen[i+1][j-1] == 'X'){
      numNeighbors++;
    }
    if(currGen[i+1][j] == 'X'){
      ++numNeighbors;
    }
    if(currGen[i+1][j+1] == 'X'){
      ++numNeighbors;
    }
    if(currGen[i][j+1] == 'X'){
      ++numNeighbors;
    }
    if(currGen[i][j-1] == 'X'){
      ++numNeighbors;
    }
  }

  else if(i == rows && (j != 0 && j != cols)){ //bottom row
    if(currGen[i-1][j-1] == 'X'){
      ++numNeighbors;
    }
    if(currGen[i-1][j] == 'X'){
      ++numNeighbors;
    }
    if(currGen[i-1][j+1] == 'X'){
      ++numNeighbors;
    }
    if(currGen[i][j+1] == 'X'){
    ++numNeighbors;
    }
    if(currGen[i][j-1] == 'X'){
      ++numNeighbors;
    }
  }

  else if(j == 0 && (i != 0 && i!= rows)){ // left column
    if(currGen[i-1][j] == 'X'){
      ++numNeighbors;
    }
    if(currGen[i-1][j+1] == 'X'){
      ++numNeighbors;
    }
    if(currGen[i][j+1] == 'X'){
      ++numNeighbors;
    }
    if(currGen[i+1][j+1] == 'X'){
      ++numNeighbors;
    }
    if(currGen[i+1][j] == 'X'){
      ++numNeighbors;
    }
  }

  else if(j == cols && (i != 0 && i!= rows)){ // right column
    if(currGen[i-1][j] == 'X'){
      ++numNeighbors;
    }
    if(currGen[i-1][j-1] == 'X'){
      ++numNeighbors;
    }
    if(currGen[i][j-1] == 'X'){
      ++numNeighbors;
    }
    if(currGen[i+1][j-1] == 'X'){
      ++numNeighbors;
    }
    if(currGen[i+1][j] == 'X'){
      ++numNeighbors;
    }
  }
  else if(i == 0 && j == 0){ //top left
    if(currGen[i][j+1] == 'X'){
      numNeighbors++;
    }
    if(currGen[i+1][j+1] == 'X'){
      numNeighbors++;
    }
    if(currGen[i+1][j] == 'X'){
      numNeighbors++;
    }
  }

  else if(i == 0 && j == cols){ // top right
    if(currGen[i][j-1] == 'X'){
      ++numNeighbors;
    }
    if(currGen[i+1][j-1] == 'X'){
      ++numNeighbors;
    }
    if(currGen[i+1][j] == 'X'){
      ++numNeighbors;
    }
  }
  else if(i == rows && j == 0){ //bottom left
    if(currGen[i][j+1] == 'X'){
      ++numNeighbors;
    }
    if(currGen[i-1][j+1] == 'X'){
      ++numNeighbors;
    }
    if(currGen[i-1][j] == 'X'){
      ++numNeighbors;
    }
  }

  else if(i == rows && j == cols){ //bottom right
    if(currGen[i][j-1] == 'X'){
      ++numNeighbors;
    }
    if(currGen[i-1][j-1] == 'X'){
      ++numNeighbors;
    }
    if(currGen[i-1][j] == 'X'){
      ++numNeighbors;
    }
  }

  else{ //anything else
    if(currGen[i-1][j-1] == 'X'){
      ++numNeighbors;
    }
    if(currGen[i-1][j] == 'X'){
      ++numNeighbors;
    }
    if(currGen[i-1][j+1] == 'X'){
      ++numNeighbors;
    }
    if(currGen[i][j-1] == 'X'){
      ++numNeighbors;
    }
    if(currGen[i][j+1] == 'X'){
      ++numNeighbors;
    }
    if(currGen[i+1][j-1] == 'X'){
      ++numNeighbors;
    }
    if(currGen[i+1][j] == 'X'){
      ++numNeighbors;
    }
    if(currGen[i+1][j+1] == 'X'){
      ++numNeighbors;
    }
  }
  return numNeighbors; //return number of neighbors
}
