#ifndef FLIGHT_H
#define FLIGHT_H
#include"../SRC/passenger.cpp"
#include<vector>
#include <string>

struct PassengerList{
    Passenger Pass;  //pass is literal passenger object
    PassengerList * next;
};
typedef std::vector< std::vector<int> > SeatMap;
class Flight {       
  public:  
    Flight();
    Flight(int rows, int columns, const std::string& id, PassengerList* passList);
    Flight(const Flight& rhs);
    int get_number_of_rows()const;
    int get_number_of_columns()const;
    std::string get_flight_id()const;
    int get_seat_status(int row, int col);
    void set_number_of_columns(int c);
    void set_number_of_rows(int r);
    void set_flight_id(std::string f_id);
    const PassengerList* get_passlist()const;
    void set_FSmap(int rows, int columns);
    void set_FSmap_seat(int row, int column, int value);
    void set_pass_listH(PassengerList* h);
    PassengerList* get_pass_listH()const;
    void insert_passener(std::string fname, std::string lname, std::string phone,int id, Seat* s);
    void update_FSmap();
    void addpassenger();
    void DisplayPassInfo();
    bool RemovePassengerById(int PassengerId);


  private:          
    std::string flight_id;
    int number_of_rows;
    int number_of_columns;
    PassengerList* pass_listH;
    SeatMap FSmap;   //matrix of integers

};
#endif