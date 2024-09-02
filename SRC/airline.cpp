#include<vector>
#include <string>
#include <iostream>

#include "../headers/airline.h"
Airline::Airline(){
    airline_name = '\0';
    flight_listH = nullptr;
    number_of_flights = 0;
}

Airline::Airline(std::string name, FlightList* list, int num){
    airline_name = name;
    flight_listH = list; 
    number_of_flights = num;
}


Airline::Airline(const Airline& source) {
    // Copy the airline name and the number of flights
    airline_name = source.airline_name;
    number_of_flights = source.number_of_flights;

    // Copy the linked list of flights
    if (source.flight_listH != nullptr) {
        FlightList* sourceFlightNode = source.flight_listH;
        flight_listH = new FlightList{ sourceFlightNode->flight, nullptr };

        FlightList* currentCopyFlightNode = flight_listH;

        // Iterate through the source flight list
        while (sourceFlightNode->next != nullptr) {
            sourceFlightNode = sourceFlightNode->next;

            // Copy each flight node
            currentCopyFlightNode->next = new FlightList{ sourceFlightNode->flight, nullptr };
            currentCopyFlightNode = currentCopyFlightNode->next;
        }
    } else {
        flight_listH = nullptr;
    }
}

Airline::~Airline(){
    FlightList* fl = flight_listH, *flb;
    while(fl != nullptr){
       
        if(fl->flight.get_pass_listH() != nullptr){
            PassengerList * pl = fl->flight.get_pass_listH();
            PassengerList * plb;
        
            while(pl != nullptr){
                delete pl->Pass.get_seat();
                plb = pl;
                pl = pl->next;
                delete plb->Pass.get_seat();
            }   
            
        }
        flb = fl;
        fl = fl -> next;
        delete flb;
    }
    set_list(nullptr);
}

void Airline::set_name(std::string Name){
    airline_name = Name;
}

void Airline::set_list(FlightList* List){
    flight_listH = List;
}

void Airline::set_num(int n){
    number_of_flights = n;
}

const std::string Airline::get_name()const{
    return airline_name;
}

FlightList* Airline::get_list(){
    return flight_listH;
}

int Airline::get_num()const{
    return number_of_flights;
}

void Airline::insert(Flight* flight){
    FlightList* new_flight = new FlightList{*flight, nullptr};
    new_flight->next = flight_listH;
    flight_listH = new_flight;
}