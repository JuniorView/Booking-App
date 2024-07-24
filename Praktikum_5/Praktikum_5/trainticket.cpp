#include "trainticket.h"


TrainTicket::TrainTicket()
{

}
TrainTicket::TrainTicket( string id,double price,string fromDate,string toDate,long travelId,string type,string predecessor1, string predecessor2,string fromDestination,
             string toDestination,string departureTime,string arrivalTime, string bookingClass,vector<station>Station,
                          double toStationLatitude,double toStationLongitude,double fromStationLatitude, double fromStationLongitude):
    Booking(id, price, fromDate, toDate,  travelId,type,predecessor1,predecessor2),fromDestination(fromDestination),toDestination(toDestination),
    departureTime(departureTime),arrivalTime(arrivalTime),bookingClass(bookingClass),connectingStations(Station),
    toStationLatitude(toStationLatitude),toStationLongitude(toStationLongitude),fromStationLatitude(fromStationLatitude),fromStationLongitude(fromStationLongitude)
{


};
string TrainTicket::showDetails(){
    cout<<endl;
    string stringResultant;
       for(unsigned int i=0;i<connectingStations.size();i++){
          stringResultant+= ", "+connectingStations[i].StationsName;
   };
   string stringprice=to_string(this->price);
   cout<<"------------------------------------------------------------------------------"<<endl;
    return"Zugticket von "+fromDestination+" nach "+toDestination+" am "+fromDate+" um "+departureTime+" bis "
            +arrivalTime+" ueber "+ stringResultant
            +"BookingClass: "+getBookingClass()+ ". " + "Preis: " + stringprice + " Euro";

};

string TrainTicket::getFromDestination(){
    return fromDestination;
};
string TrainTicket::getToDestination(){
    return toDestination;
};
string TrainTicket::getDepartureTime(){
    return departureTime;
};
string TrainTicket::getArrivalTime(){
    return arrivalTime;
};
string TrainTicket::getBookingClass(){


    if(bookingClass == "SSP1")
        return "Supersparpreis 1. Klasse";
    else if(bookingClass == "SSP2")
        return "Supersparpreis 2. Klasse";
    else if(bookingClass == "SP1")
        return "Sparpreis 1. Klasse";
    else if(bookingClass == "SP2")
        return "Sparpreis 2. Klasse";
    else if(bookingClass == "FP1")
        return "Flexpreis 1. Klasse";
    else if(bookingClass == "FP2")
        return "Flexpreis 2. Klasse";
    else
        return "";  //should not be reached

}
vector<station> TrainTicket::getConnectingStations(){
    return connectingStations;
};
vector<string>TrainTicket::getConnectingStationsName(){
    vector<string> connectingStationName;
    for(unsigned int i=0;i<connectingStations.size();i++){
       connectingStationName[i]= connectingStations[i].StationsName; // we just change the station's name
    }
    return connectingStationName;
}
double TrainTicket::getToStationLatitude (){
    return toStationLatitude;
};
double TrainTicket::getToStationLongitude (){
    return toStationLongitude;
};
double TrainTicket::getFromStationLatitude (){
    return fromStationLatitude;
};
double TrainTicket::getFromStationLongitude (){
    return fromStationLongitude;
};

void TrainTicket::setFromDestinattion(string FromDestination){
    fromDestination =FromDestination;
};
void TrainTicket::settoDestination(string toDestination){
  this-> toDestination =toDestination;
};
void TrainTicket::setdepartureTime(string departureTime ){
    this->departureTime=departureTime;
};
void TrainTicket::setarrivalTime(string arrivalTime){
    this->arrivalTime=arrivalTime;
};
void TrainTicket::setbookingClass(string bookingClass){
    this->bookingClass=bookingClass;
};
void TrainTicket::setConnectingStations(vector<string> vector){
   // this->connectingStations=vector;
    for(unsigned int i=0;i<vector.size();i++){
        connectingStations[i].StationsName=vector[i]; // we just change the station's name
    }

};
TrainTicket::~TrainTicket(){

}
