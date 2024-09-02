//here the extraction functions will be created
//The functions to extract info from the .txt file
#include "airline.cpp"
#include <string>
#include <vector>
#include <fstream>
#include <cctype> 

using namespace std;

string extract_the_line(ifstream& stream){
    //returns a string of the line the stream pointer is pointing to
    //then makes the file ptr go to next line

    string line_of_text;
     if (!stream.fail() && !stream.eof() ){
        getline(stream, line_of_text);
    }
    else{
        cout<<"Unable to read line from file"<<endl;
    }
    return line_of_text;

}
Airline extract_airline(string flight_info_line){
    //take string extracted form extract_the_line() and extracts airline info 
    //put info extracted from said airline into new airline object
    //returns an airline object
    Airline a;
    string a_name;

    int i = 0;
    while( isalpha(flight_info_line.at(i)) ){
        a_name.push_back(flight_info_line.at(i));
        i++;
    }
    a.set_name(a_name);
    return a;
}

Flight* extract_flight(string flight_info_line){
     //take string extracted form extract_the_line() and extracts flight info and creates airline object on the heap
     //put info into said flight object
     //return address of object

    // breaks the string up into 3 strings - id, rows, columns
    // then assigns these to the private members of a new flight object created on the heap

    Flight* f = new Flight;

    string flight_ID;
    string rows;
    string cols;

    size_t i;
    for (i = 0; flight_info_line.at(i) != ' ' ; i++){ //appends number chars to flight_ID until it reaches a space
        if( isdigit(flight_info_line.at(i)) )
        flight_ID.push_back(flight_info_line.at(i));
    }

    f->set_flight_id(flight_ID);

    while(flight_info_line.at(i) == ' '){  // travels to the next non-white-space char
        i++;
    }
    
    do{
            rows.push_back(flight_info_line.at(i));  // appends chars to rows while char is a number
            i++;
    }while( isdigit(flight_info_line.at(i)) );

    f->set_number_of_rows(stoi(rows));  //stoi() function takes a string as an argument and returns the integer equivalent

    while(flight_info_line.at(i) == ' '){  // travels to the next non-white-space char
        i++;
    }
    
    do{
            cols.push_back(flight_info_line.at(i));  //appends chars to cols while char is a number, and end of string has not been reached
            i++;
    }while(i<flight_info_line.length() &&  isdigit(flight_info_line.at(i)) );

    f->set_number_of_columns(stoi(cols));
    f->set_FSmap((*f).get_number_of_rows(), (*f).get_number_of_columns()); //resize seatmap to with current value
    return f;
}

Passenger* extract_passenger(string passenger_info_line){
    //take string extracted form extract_the_line() and extracts passenger info and creates passenger object on the heap
    //put info into passenger 
    Passenger* p = new Passenger;
    Seat* seatpointer = new Seat;

    string fname, lname, phone, seatrow, seatcol, id;

    size_t i = 0;
    for(i = 0; passenger_info_line.at(i) != ' ' && isalpha(passenger_info_line.at(i)); i++ ){
        fname.push_back(passenger_info_line.at(i));
    }
    fname.push_back(passenger_info_line.at(i));
    i++;
    if(passenger_info_line.at(i) != ' '){
        while(passenger_info_line.at(i) != ' ' && isalpha(passenger_info_line.at(i))){
            fname.push_back(passenger_info_line.at(i));
            i++;
        }
    }
    else{
        if(passenger_info_line.at(i) == ' '){
            fname.pop_back();
        }
    }
    p->set_Fname(fname);


    while(passenger_info_line.at(i) == ' '){  // travels to the next non-white-space char
        i++;
    }
    do{
        lname.push_back(passenger_info_line.at(i));
        i++;
    }while(passenger_info_line.at(i) != ' ' && isalpha(passenger_info_line.at(i)) );
    lname.push_back(passenger_info_line.at(i));
    i++;
    if(passenger_info_line.at(i) != ' '){
        while(passenger_info_line.at(i) != ' ' && isalpha(passenger_info_line.at(i))){
            lname.push_back(passenger_info_line.at(i));
            i++;
        }
    }
    else{
        if(passenger_info_line.at(i) == ' '){
            lname.pop_back();
        }
    }
    p->set_Lname(lname);


    while(passenger_info_line.at(i) == ' '){  // travels to the next non-white-space char
        i++;
    }
    while(passenger_info_line.at(i) != ' ' && (isdigit(passenger_info_line.at(i)) || passenger_info_line.at(i) == '-') ){
        phone.push_back(passenger_info_line.at(i));
        i++;
    }
    p->set_phone(phone);


    while(passenger_info_line.at(i) == ' '){  // travels to the next non-white-space char
        i++;
    }
    do{
        seatrow.push_back(passenger_info_line.at(i));
        i++;
    }while(passenger_info_line.at(i) != ' ' && (isdigit(passenger_info_line.at(i)) ));
    do{
        seatcol.push_back(passenger_info_line.at(i));
        i++;
    }while(passenger_info_line.at(i) != ' ' && (isalpha(passenger_info_line.at(i)) ));
    //set seat here
    p->set_seat(seatpointer);
    seatpointer -> set_row(stoi(seatrow));
    char col = seatcol.at(0);
    seatpointer -> set_column(col);


    while(passenger_info_line.at(i) == ' '){  // travels to the next non-white-space char
        i++;
    }
    do{
            id.push_back(passenger_info_line.at(i));
            i++;
    }while(i<passenger_info_line.length() &&  isdigit(passenger_info_line.at(i)) );
    int int_id = stoi(id);
    p->set_pass_id(int_id);
    return p;
}
