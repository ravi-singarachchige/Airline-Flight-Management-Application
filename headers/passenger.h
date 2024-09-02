#ifndef PASSENGER_H
#define PASSENGER_H
#include "../SRC/seat.cpp"
#include <string>
class Passenger {       
  public:  
   Passenger();
   Passenger(std::string& fname, std::string& lname, std::string& pho, int& p_id, Seat * s);
   Passenger(const Passenger& rhs);
   std::string get_Fname()const;
   std::string get_Lname()const;
   std::string get_phone()const;
   int get_pass_id()const;
   Seat* get_seat()const;
   void set_Fname(std::string& fname);
   void set_Lname(std::string& lname);
   void set_phone(std::string& pho);
   void set_pass_id(int& id);
   void set_seat(Seat * s);
  private:          
    std::string Fname;
    std::string Lname;
    std::string phone;
    int pass_id;
    Seat * seat;    //ex: (example: 6A, 13C, 2B, etc), points to specific seat on a flight seat map 
};
#endif