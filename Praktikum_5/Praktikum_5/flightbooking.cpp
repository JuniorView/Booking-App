#include "flightbooking.h"

#include "flightbooking.h"

FlightBooking::FlightBooking()
{

}
FlightBooking::FlightBooking(string id,double price,string fromDate,string toDate,long travelId,string type,string predecessor1, string predecessor2,string fromDestination,
 string toDestination,string airline,string bookingClass,double fromDestLatitude, double fromDestLongitude, double toDestLatitude, double toDestLongitude)
    :Booking( id, price,fromDate, toDate, travelId,type,predecessor1,predecessor2),fromDestination(fromDestination),
 toDestination(toDestination),airline(airline),bookingClass(bookingClass),
  fromDestLatitude(fromDestLatitude), fromDestLongitude(fromDestLongitude), toDestLatitude(toDestLatitude), toDestLongitude(toDestLongitude)
{

};
string FlightBooking:: showDetails(){
//    cout<<"Flugbuchung von "<<this->fromDestination<<" nach "<<this->toDestination<<" mit "<<this->airline<<" am "<<this->fromDate<<" preis:"<<this->price;
    cout<<endl;
    cout<<"------------------------------------------------------------------------------"<<endl;
    string stringprice=to_string(this->price);

    return "Flugbuchung von " + fromDestination + " nach "
                  + toDestination + " mit " + airline + " am " + fromDate
                  +"Booking Class " +getBookingClass()+ ". Preis: " + stringprice + " Euro";
}

FlightBooking::~ FlightBooking(){

}
string FlightBooking::getFromDestination(){
    return fromDestination;
};
string FlightBooking::getToDestination(){
    return toDestination;
};
string FlightBooking::getAirLine(){
    return airline;
};
string FlightBooking::getBookingClass(){


    if(bookingClass == "Y")
        return "Economy class";
    else if(bookingClass == "W")
        return "Premium Economy class";
    else if(bookingClass == "J")
        return "Business class";
    else if(bookingClass == "F")
        return "First class";
    else              //should not be reached
        return "";

}

double FlightBooking::getFromDestLatitude(){
    return fromDestLatitude;
}

double FlightBooking::getFromDestLongitude(){
    return fromDestLongitude;
}

double FlightBooking::getToDestLatitude() {
    return toDestLatitude;
}

double FlightBooking::getToDestLongitude(){
    return toDestLongitude;
}
void FlightBooking::setFromDestination(std::string fromDestination){
    this->fromDestination = fromDestination;
}
void FlightBooking::setToDestination(std::string toDestination){
    this->toDestination = toDestination;
}
void FlightBooking::setAirline(std::string airline){
    this->airline = airline;
}
void FlightBooking::setBookingClass(char bookingClass){
    this->bookingClass = bookingClass;
}
