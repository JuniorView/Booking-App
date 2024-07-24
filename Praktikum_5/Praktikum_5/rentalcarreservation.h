#ifndef RENTALCARRESERVATION_H
#define RENTALCARRESERVATION_H


#include "booking.h"

class RentalCarReservation: public Booking
{
public:
     RentalCarReservation();
     RentalCarReservation(std::string id, double price, std::string fromDate, std::string toDate,long travelId,string type,string predecessor1, string predecessor2,
                             std::string pickupLocation, std::string returnLocation, std::string company,string vehicleClass,
                          double pickupLatitude, double pickupLongitude, double returnLatitude, double returnLongitude);

    ~RentalCarReservation();
    string getPickupLocation();
    string getReturnLocation();
    string getCompany();
    string showDetails() ;
    string getVehicleClass();
    double getPickupLatitude();
    double getPickupLongitude();
    double getReturnLatitude();
    double getReturnLongitude();

    void setPickupLocation(std::string);
    void setReturnLocation(std::string);
    void setCompany(std::string);
    void setVehicleClass(std::string);

private:
    string pickupLocation;
    string returnLocation;
    string company;
    string vehicleClass;
    double pickupLatitude;
    double pickupLongitude;
    double returnLatitude;
    double returnLongitude;

};

#endif // RENTALCARRESERVATION_H
