#ifndef FLIGHTBOOKING_H
#define FLIGHTBOOKING_H


#include "booking.h"



class FlightBooking: public Booking
{
public:
    FlightBooking();
    FlightBooking(string id,double price,string fromDate,string toDate,long travelId,string type,string predecessor1, string predecessor2,string fromDestination,
                   string toDestination,string airline,string bookingClass,double fromDestLatitude,
                  double fromDestLongitude, double toDestLatitude, double toDestLongitude);
    ~ FlightBooking();

    string showDetails() override;
    string getFromDestination();
    string getToDestination();
    string getAirLine();
    string getBookingClass();
    double getFromDestLatitude();
    double getFromDestLongitude();
    double getToDestLatitude();
    double getToDestLongitude();


    void setFromDestination(std::string);
    void setToDestination(std::string);
    void setAirline(std::string);
    void setBookingClass(char);

private:
   string fromDestination;
   string toDestination;
   string airline;
   string bookingClass;
   double fromDestLatitude;
   double fromDestLongitude;
   double toDestLatitude;
   double toDestLongitude;
};


#endif // FLIGHTBOOKING_H
