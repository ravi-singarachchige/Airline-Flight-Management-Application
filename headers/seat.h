#ifndef SEAT_H
#define SEAT_H
#include<vector>
#include <string>

class Seat {       
  public:  
   Seat();
   Seat(int r, int c);
   Seat(const Seat& rhs);
   int get_row()const;
   char get_column()const;
   void set_row(int r);
   void set_column(int c);
   
  private:          
    int row;
    char column;
};
#endif