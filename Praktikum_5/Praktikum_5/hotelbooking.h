#ifndef HOTELBOOKING_H
#define HOTELBOOKING_H


#include "booking.h"

class HotelBooking: public Booking
{
public:
    HotelBooking();
    HotelBooking(std::string id, double price, std::string fromDate, std::string toDate,
                 long travelId,string type,string predecessor1, string predecessor2, std::string hotel, std::string town,string roomType, double hotelLatitude, double hoteLongitude );

    ~HotelBooking();
    string showDetails();
    string getHotel();
    string getTown();
    string getRoomType();
    double getHotelLatitude();
    double getHotelLongitude();


    void setHotel(std::string);
    void setTown(std::string);
    void setRoomType(std::string);

private:
    string hotel;
    string town;
    string roomType;
    double hotelLatitude;
    double hotelLongitude;
};

#endif // HOTELBOOKING_H
