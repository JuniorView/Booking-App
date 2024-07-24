#include "rentalcarreservation.h"

RentalCarReservation::RentalCarReservation()
{

}
RentalCarReservation::RentalCarReservation(std::string id, double price, std::string fromDate, std::string toDate,long travelId,string type,string predecessor1, string predecessor2,
                                           std::string pickupLocation, std::string returnLocation, std::string company,string vehicleClass,
                                           double pickupLatitude, double pickupLongitude, double returnLatitude, double returnLongitude) :
    Booking(id, price, fromDate, toDate, travelId,type,predecessor1,predecessor2), pickupLocation(pickupLocation),returnLocation(returnLocation), company(company), vehicleClass(vehicleClass),
     pickupLatitude(pickupLatitude),
        pickupLongitude(pickupLongitude), returnLatitude(returnLatitude), returnLongitude(returnLongitude)
{

}

string RentalCarReservation::showDetails() {
//    cout<<"Mietwagenreservierung mit "<<company<<" Abholung am"<<fromDate<<" in "<<pickupLocation<<" Rückgabe am "<<toDate<<" in "<<returnLocation<<". Preis:"<<price;
    cout<<endl;
    cout<<"------------------------------------------------------------------------------"<<endl;
    string stringprice=to_string(this->price);
    return "Mietwagenreservierung mit Europcar. Abholung am "
                 + fromDate + " in " + pickupLocation + ". "
                 + "Rueckgabe am " + toDate + " in " + returnLocation
                 + "VeheicleClass : "+ vehicleClass +". "
                 + "Preis: " + stringprice + " Euro";

};
string RentalCarReservation::getPickupLocation(){
    return pickupLocation;
};
string RentalCarReservation::getReturnLocation(){
    return returnLocation;
};
string RentalCarReservation::getCompany(){
    return company;
};
string RentalCarReservation::getVehicleClass(){
    return vehicleClass;
}

double RentalCarReservation::getPickupLatitude(){
    return pickupLatitude;
}
double RentalCarReservation::getPickupLongitude(){
    return pickupLongitude;
}
double RentalCarReservation::getReturnLatitude(){
    return returnLatitude;
}
double RentalCarReservation::getReturnLongitude(){
    return returnLongitude;
}

void RentalCarReservation::setPickupLocation(std::string pickupLocation){
    this->pickupLocation = pickupLocation;
}
void RentalCarReservation::setReturnLocation(std::string returnLocation){
    this->returnLocation = returnLocation;
}
void RentalCarReservation::setCompany(std::string company){
    this->company = company;
}
void RentalCarReservation::setVehicleClass(std::string vehicleClass){
    this->vehicleClass = vehicleClass;
}


RentalCarReservation::~RentalCarReservation(){

}
