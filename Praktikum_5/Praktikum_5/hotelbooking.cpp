#include "hotelbooking.h"

HotelBooking::HotelBooking()
{

}
HotelBooking::HotelBooking(std::string id, double price, std::string fromDate, std::string toDate,long travelId,string type,string predecessor1, string predecessor2,
                           std::string hotel, std::string town,string roomType, double hotelLatitude, double hotelLongitude) :
              Booking(id, price, fromDate, toDate, travelId,type,predecessor1,predecessor2), hotel(hotel), town(town),roomType(roomType),hotelLatitude(hotelLatitude), hotelLongitude(hotelLongitude)
{

}


string HotelBooking:: showDetails(){
//    cout<<"Hotelreservierung im "<<hotel<<" in "<<town<<" vom "<<fromDate<<" bis "<<toDate<<" Preis:"<<price;
    cout<<endl;
    cout<<"------------------------------------------------------------------------------"<<endl;
    string stringprice=to_string(this->price);
    return "Hotelreservierung " + hotel + " in "
               + town + " vom " + fromDate
               + " bis zum " + toDate
               +"Room Type : " +getRoomType()
               + ". Preis: " + stringprice + " Euro";

};
string HotelBooking::getHotel(){
    return hotel;
};
string HotelBooking::getTown(){
    return town ;
};

double HotelBooking::getHotelLatitude(){
    return hotelLatitude;
}

double HotelBooking::getHotelLongitude(){
    return hotelLongitude;
}

std::string HotelBooking::getRoomType(){

    if(roomType == "EZ")
        return "Einzelzimmer";
    else if(roomType == "DZ")
        return "Doppelzimmer";
    else if (roomType == "AP")
        return "Appartment";
    else if(roomType == "SU")
        return "Suite";
    else               //should not be reached
        return "";
}
void HotelBooking::setHotel(std::string hotel){
    this->hotel = hotel;
}
void HotelBooking::setTown(std::string town){
    this->town = town;
}
void HotelBooking::setRoomType(std::string roomType){
    this->roomType = roomType;
}

HotelBooking::~HotelBooking(){

};
