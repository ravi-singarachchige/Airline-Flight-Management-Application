#ifndef AIRLINE_H
#define AIRLINE_H
#include<vector>
#include <string>
#include "../SRC/flight.cpp"
struct FlightList{
    Flight flight;
    FlightList * next;
};

class Airline {       
  public:  
    Airline();
    Airline(std::string name, FlightList* list, int num);
    Airline(const Airline& source);
    ~Airline();

    void set_name(std::string Name);
    void set_list(FlightList* List);
    void set_num(int n);

    const std::string get_name()const;
    FlightList* get_list();
    int get_num()const;

    void insert(Flight* flight);
  private:          
    std::string airline_name;
    FlightList* flight_listH;
    int number_of_flights;  
};
#endif