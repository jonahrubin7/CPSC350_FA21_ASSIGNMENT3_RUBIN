#include "Simulate.h" // import the simulate class


int main(){ // main function
  string outFileName = "";
  int choice = 0;
  GameOptions *go = new GameOptions(); //create instance of game options
  Simulate *sim = new Simulate(); // create instance of simulate class
  while(choice != 1 && choice != 2){
    cout << "Would you like to input a file, or create your own map" << endl;
    cout << "Type (1) for input file \nType (2) for create your own" << endl;
    cin >> choice;
    if(choice != 1 && choice != 2){ //make sure inputs are correct
      cout << "Follow the rules" << endl;
    }
  }


  if(choice == 1){
    go->setUp(); //call set up
    go->createArrayFile(); // create array
    sim->Run(go); //run the game
  }
  if(choice == 2){
    go->setUp(); // set up everything
    go->createArrayInput(); // create array
    sim->Run(go); // run the game
  }
  delete go;
  delete sim;

  return 1; // end the game
}
