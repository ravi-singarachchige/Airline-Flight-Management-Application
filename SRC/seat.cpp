#include"../headers/seat.h"

//DEFAULT CTR
Seat::Seat(){
    row = 0;
    column = '\0';
}
//CUSTOM CTR
Seat::Seat(int r, int c){
    row = r;
    column = c; 
}
//COPY CTR
Seat::Seat(const Seat& rhs){  //Currently assumed that the seats ARE NOT created on the heap
    row = rhs.row;
    column = rhs.column;
}
//IMPLEMENTATION
int Seat::get_row()const{return row;}
char Seat::get_column()const{return column;}
void Seat::set_row(int r){row = r;}
void Seat::set_column(int c){column = c;}




