#ifndef BOOKING_H
#define BOOKING_H

#include <vector>
#include<string>
#include<iostream>
using namespace std;

class Booking
{
public:
    Booking();
    Booking(string id,double price,string fromDate,string toDate,long travelId,string type, string predecessor1, string predecessor2);
    virtual string showDetails()=0 ; // reine virtuelle Methode;
    string getId();
    string getFromDate();
    string getToDate();
    double getPrice();
    long getTravelId();

    void setPrice(double);
    void setFromDate(std::string);
    void setToDate(std::string);

    virtual ~Booking();

    const string &getPredecessor1() const;

    const string &getPredecessor2() const;

    const string &getType() const;

protected:
    string id;
    double price;
    string fromDate;
    string toDate;
    long travelId;
    string type;
    string predecessor1;
    string predecessor2;
};

#endif // BOOKING_H
