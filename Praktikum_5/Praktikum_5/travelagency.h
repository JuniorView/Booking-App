#ifndef TRAVELAGENCY_H
#define TRAVELAGENCY_H


#include <iostream>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QFile>
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>
#include <map>
#include <memory>
#include <QUrl>
#include <QDesktopServices>
#include "booking.h"
#include "customer.h"
#include "airport.h"

enum ErrorType { MissingHotel, OverlappedCar, OverlappedHotel, OverlappedTravel };

struct IncorrectReservation
{
    ErrorType type;
    QString errorInfo;
};
struct Config
{
    bool overlappedTravel =true ;
    bool overlappedHotel =true;
    bool missedHotel = true ;
    bool overlappedCar = true;
};

class TravelAgency
{
public:
    TravelAgency();
    ~TravelAgency();
    void readFile(QString);
    void readIataCodes(QString);
    void displayBooking();
    shared_ptr<Airport> findAirport(string airportCode);
    QString getBookinInfo();
    vector<shared_ptr<Booking>> getBookings();
    void displayBookingsOnMap(const shared_ptr<Travel>& travel);
    vector<shared_ptr<Travel>> getTravels() const;
    vector<shared_ptr<Customer>> getCustomers();
    //void clearBooking();

    shared_ptr<Booking> findBooking(string id);
    shared_ptr<Customer> findCustomer(long id);
    //int findTravel1(long id);
    //Travel* findTravel(long id,long custormerId);
    shared_ptr<Travel>findTravel(long id);

    shared_ptr<Airport> findAirport(QString iata);
    // void readBinaryFile(QString);
    const std::map<string, shared_ptr<Airport> > &getAllAirports() const;

    void addIncorrectReservation(IncorrectReservation r);

    const std::vector<IncorrectReservation> &getIncorrectReservations() const;

    std::map<std::string, bool> consistencyResults;



    const std::map<std::string, bool> &getConsistencyResults() const;
    void setConsistencyResult(const std::string& testName, bool result);

    void clearIncorrectReservations();


    const Config &getConfig() const;
    void setConfig(const Config &newConfig);

private:
     vector<shared_ptr<Booking>> bookings;
     vector<shared_ptr<Customer>> allCustomers;
     vector<shared_ptr<Travel>> allTravels;
     std::map<string ,shared_ptr<Airport>> allAirports;
     std::vector<IncorrectReservation> incorrectReservations;
     Config config;
};


#endif // TRAVELAGENCY_H
