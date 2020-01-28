/*@author Aaron Gearhart
@file Executive.cpp
@date 9/19/2018
@brief This file is the cpp file for the executive class.  Contains method definitions to let the user interact with the program

*/

#include <string>
#include <iostream>

#include <fstream>


//Executive(){
//  position = 0;

//}



void Executive(char* &data)
{
  int position = 0;
  int size =0;
  std::ifstream myfile;
  myfile.open(data);
  std::string str;

  while (myfile>>str) {
    //myfile>>str;
    if(str == "NAVIGATE")
    {

      std::string site = "0";
      if (position>1&&position<size) {
        site = "delete";

        myfile>>site;

      }
      else{
        myfile>>site;

      }


      position++;
      size++;
    }
    else if(str == "BACK")
    {

      if(position > 1)
      {
        position--;
      }
      else{
        std::cout << "Already at the front page" << '\n';
      }

    }
    else if(str == "FORWARD")
    {

      if (position < size) {
        position++;
      }
      else{
        std::cout << "Already at the back page" << '\n';
      }

    }
    else if(str == "HISTORY")
    {
    }
    else{
      std::cout << "COMMAND INVALID" << '\n';
    }

  }

}





void run(){

    int choice = 0;

    //menu

    while(choice != 11)
    {
      std::cout << "\nChoose one operation from the options below" << '\n';
      std::cout << "1) isEmpty()" << '\n';
      std::cout << "2) Length" << '\n';
      std::cout << "3) Insert" << '\n';
      std::cout << "4) Delete" << '\n';
      std::cout << "5) Delete Duplicates" << '\n';
      std::cout << "6) Find" << '\n';
      std::cout << "7) Find Next" << '\n';
      std::cout << "8) Print" << '\n';
      std::cout << "9) Reverse List" << '\n';
      std::cout << "10) Print At" << '\n';
      std::cout << "11) Exit" << '\n';
      std::cout << "Make a choice: ";
      std::cin >> choice;

      if (choice == 1) {
        std::string url = "0";
        std::cout << "Type in the URL: ";
        std::cin >> url;

      }
      else if (choice == 2)
      {

      }
      else if (choice == 3)
      {

      }
      else if (choice == 4)
      {

      }
      else if (choice >= 6)
      {
        std::cout << "\nMake another choice" << '\n';
      }

  }
}
