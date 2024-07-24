#include "booking.h"

Booking::Booking()
{

}
Booking::Booking(string id,double price,string fromDate,string toDate,long travelId,string type,string predecessor1, string predecessor2):id(id),price(price),
               fromDate(fromDate),toDate(toDate),travelId(travelId),type(type),predecessor1(predecessor1),predecessor2(predecessor2){

};

Booking:: ~Booking(){

}

const string &Booking::getPredecessor1() const
{
    return predecessor1;
}

const string &Booking::getPredecessor2() const
{
    return predecessor2;
}

const string &Booking::getType() const
{
    return type;
};
string Booking::getId(){
    return id;
};
string Booking::getFromDate(){
    return fromDate;
};
string Booking::getToDate(){
    return toDate;
};
double Booking::getPrice(){
    return price;
};
void Booking::setFromDate(std::string fromDate) {
    this->fromDate = fromDate;
}

void Booking::setToDate(std::string toDate) {
    this->toDate = toDate;
}

void Booking::setPrice(double price) {
    this->price = price;
}
long  Booking::getTravelId(){
    return travelId;
};

