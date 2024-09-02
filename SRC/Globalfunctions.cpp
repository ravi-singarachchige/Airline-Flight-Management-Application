#include <string>
#include <vector>
#include <iostream>
#include <fstream>

#include "../headers/airline.h"
#include "../headers/flight.h"
#include "../headers/passenger.h"
#include "../headers/seat.h"
#include "../headers/Globalfunctions.h"
using namespace std;

int pressreturntocontinue(){
    std::cout <<"<<< Press Return to Continue >>>\n";
    string Input;
    std::getline(std::cin, Input);
    if(Input.empty())
    return 1;
    else
    return 0;
}
void printfirstmessege(){
    std::cout << "Version: 1.0\n";
    std::cout << "Term Project - Flight Management Programm in C++\n";
    std::cout << "Produced by: Rodolfo Gil-Pereira, Anastasia Zaharia, Sebastian Nieto\n\n";
}
void printreturnmessege(){
    std::cout <<"<<< Press Return to Continue >>>\n";
    std::cout <<"(anything else will end the program)\n";
}
void printoptions(){
    std::cout << "Please select one of the following functions:\n";
    std::cout << "1.  Display Flight Seat Map.\n";
    std::cout << "2.  Display Passengers Information.\n";
    std::cout << "3.  Add a New Passenger.\n";
    std::cout << "4.  Remove an Existing Passenger.\n";
    std::cout << "5.  Save data.\n";
    std::cout << "6.  Quit.\n\n";
    std::cout << "Enter your choice: (1, 2, 3, 4, 5 or 6):\n";
}
void printwronginput(){
    std::cout << "Invalid input, please try again: \n";
}
int validate_name(std::string& name){
    if(name.length()>18){
        return 0;
    }
    for(int i = 0; i< name.length();i++){
        if(!isalpha(name.at(i))){
            return 0;
        }
    }
    return 1;
}
int validate_phone(std::string& pnum){
    if(pnum.length() != 12){
        return 0;
    }
    for(int i = 0; i< pnum.length();i++){
        if( isdigit(pnum.at(i)) || pnum.at(i) == '-'){
            continue;
        }
        else{
            return 0;
        }
    }
    return 1;
}
