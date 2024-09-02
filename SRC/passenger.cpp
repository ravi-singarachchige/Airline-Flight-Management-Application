#include "../headers/passenger.h"

//DEFAULT CTR
Passenger::Passenger(){
    Fname= "";
    Lname = "";
    phone = "";
    pass_id = 0;
    seat = nullptr;
}
//CUSTOM CTR

Passenger::Passenger(std::string& fname, std::string& lname, std::string& pho, int& p_id, Seat * s){
    Fname= fname;
    Lname = lname;
    phone = pho;
    pass_id = p_id;
    seat = s;
}
//COPY CTR
Passenger::Passenger(const Passenger& rhs){
    if(this == &rhs){
        return ;
    }
    Fname= rhs.Fname;  
    Lname = rhs.Lname;
    phone = rhs.phone;
    pass_id = rhs.pass_id;
    seat = rhs.seat;
}
//IMPLEMENTORS
std::string Passenger::get_Fname()const{return Fname;}
std::string Passenger::get_Lname()const{return Lname;}
std::string Passenger::get_phone()const{return phone;}
int Passenger::get_pass_id()const{return pass_id;}
Seat* Passenger::get_seat()const{return seat;}

void Passenger::set_Fname(std::string& fname){
    Fname = fname;
}
void Passenger::set_Lname(std::string& lname){
        Lname = lname;
}
void Passenger::set_phone(std::string& pho){
        phone = pho;
}
void Passenger::set_pass_id(int& id){
    pass_id = id;
}
void Passenger::set_seat(Seat * s){
        seat = s;
}
