#ifndef TRAINTICKET_H
#define TRAINTICKET_H


#include "booking.h"

struct station{
    string StationsName;
    double latitude;
    double longitude;


    station(string s, double l,double L) : StationsName(s),latitude(l),longitude(L){

    }
};

class TrainTicket: public Booking
{
public:
    TrainTicket();
    TrainTicket(string id,double price,string fromDate,string toDate,long travelId,string type,string predecessor1, string predecessor2,string fromDestination,
                string toDestination,string departureTime,string arrivalTime, string bookingClass,vector<station>,
                double toStationLatitude,double toStationLongitude,double fromStationLatitude, double fromStationLongitude);

    ~TrainTicket();

    string showDetails();
    string getFromDestination();
    string getToDestination();
    string getDepartureTime();
    string getArrivalTime();
    string getBookingClass();
    double getToStationLatitude ();
    double getToStationLongitude ();
    double getFromStationLatitude ();
    double getFromStationLongitude ();
    vector<station> getConnectingStations();
    vector<string>getConnectingStationsName();// für das Anzeigen auf Ui

    void setFromDestinattion(string);
    void settoDestination(string);
    void setdepartureTime(string);
    void setarrivalTime(string);
    void setbookingClass(string);
    void setConnectingStations(vector<string>); // wir wollen nur den StationNamen ändern.

private:
    string fromDestination;
    string toDestination;
    string departureTime;
    string arrivalTime;
    string bookingClass;
    vector<station> connectingStations;
    double toStationLatitude;
    double toStationLongitude;
    double fromStationLatitude;
    double fromStationLongitude;


};

#endif // TRAINTICKET_H
