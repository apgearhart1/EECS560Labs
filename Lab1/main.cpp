/*@author Aaron Gearhart
@file main.cpp
@date 9/19/2018
@brief This file creates the executive object and starts the program.

*/

#include <fstream>
#include <iostream>

#include "Node.h"
#include "Executive.h"
#include <string>



int main(int argc, char* argv[])//checks to see if there is a text file for an argument
{
  if(argc < 2)
  {
    std::cout << "Incorrect number of parameters!\n";
  }
  else
  {
     Executive exec(argv[1]); //sample creation of executive object
     exec.run(); //presumably handles the calling of all other member methods
  }

  return(0);
}
