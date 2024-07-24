#include "travelagency.h"
#include "flightbooking.h"
#include "hotelbooking.h"
#include "trainticket.h"
#include "rentalcarreservation.h"
#include <typeindex>
#include <QJsonArray>


TravelAgency::TravelAgency()
{

}

void TravelAgency::readFile(QString fileName){
//   for (auto booking : bookings) {
//      delete booking;  //freigabe der speicherplatz aufm Heap
//   }

 bookings.clear(); // Vektor wird geleert
 allCustomers.clear();
 allTravels.clear();



    QFile file(fileName);
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        throw runtime_error( "Failed to open file!");
    }

    //read the contents of the file into a QByteArray
    QByteArray jsonData=file.readAll();
    //parse the Json data
    QJsonDocument jsonDoc= QJsonDocument::fromJson(jsonData);

    //checking the jsonDoc is valid
    if(!jsonDoc.isArray()){
        throw runtime_error("invalid json File");
    }

    QJsonArray bookingsArray= jsonDoc.array();// .array() eine Methode  von QJsonDokument,um das Hauptarray der json-datei abzurufen.
                                             //der Ausdruck weist das JSon-array aus dem Dokument der Yariable bookingsarray. und nun ist das Array in
                                            // bookingsarray gespeichert und kann verwendet werden, um auf seine Elemente zuzugreifen.
    if (!jsonDoc.isArray())
        throw runtime_error("Invalid JSON File");

   int zaeler=0; // count of line
    for(int i=0;i<bookingsArray.size();i++){
        if(!bookingsArray[i].isObject()){
            throw std::invalid_argument(" Invalid Booking in Json File at Object"+to_string(i+1));
        }

        QJsonObject bookingObject= bookingsArray[i].toObject(); //umwandlung in ein QJsonObjekt für den Zugriff

        if (bookingObject["type"].toString().isEmpty() || bookingObject["id"].toString().isEmpty() ||
                bookingObject["price"].isNull() || bookingObject["fromDate"].toString().isEmpty() ||
                bookingObject["toDate"].toString().isEmpty()) {
            throw std::invalid_argument("Empty attribute in JSON File at object " + std::to_string(i+1));
        }

        string id=bookingObject["id"].toString().toStdString();
        string fromDate=bookingObject["fromDate"].toString().toStdString();
        string toDate=bookingObject["toDate"].toString().toStdString();
        string type=bookingObject["type"].toString().toStdString();

        string customerFirstname=bookingObject["customerFirstName"].toString().toStdString();
        string customerLastname=bookingObject["customerLastName"].toString().toStdString();
        long customerId=bookingObject["customerId"].toDouble();
        long travelId=bookingObject["travelId"].toInt();
        shared_ptr<Customer> customer=findCustomer(customerId);
        if (customer == nullptr){
            customer=make_shared<Customer> (customerId,customerFirstname,customerLastname);
            allCustomers.push_back(customer);
        }

        //Travel* travel=findTravel(travelId,customerId);
        shared_ptr<Travel> travel=findTravel(travelId);
        //bool check=findTravel(travelId,customerId);
        if(travel==nullptr){
            travel=make_shared<Travel>(travelId,customerId);
            allTravels.push_back(travel);
        }

        //Check if the price in the right format
        if (!bookingObject["price"].isDouble()) {
            throw std::invalid_argument("Invalid price in JSON File at object " + std::to_string(i+1)+" on line "+std::to_string(zaeler-3));
        }

        double price=bookingObject["price"].toDouble();

        std::string pred1 = ""; // Default value for predecessor1
        if (bookingObject.contains("predecessor1") && !bookingObject["predecessor1"].isNull()) {
            pred1 = bookingObject["predecessor1"].toString().toStdString();
        }
        std::string pred2 = ""; // Default value for predecessor1
        if (bookingObject.contains("predecessor2") && !bookingObject["predecessor2"].isNull()) {
            pred2 = bookingObject["predecessor2"].toString().toStdString();
        }




        if(type=="Flight"){
            zaeler+=15;
            if (bookingObject["airline"].toString().isEmpty() || bookingObject["toDest"].toString().isEmpty()
                    || bookingObject["fromDest"].toString().isEmpty() ) {
                throw std::invalid_argument("Empty attribute in JSON File at object " + std::to_string(i+1)+" on line "+std::to_string(zaeler-3));
            }

            string fromDestination=bookingObject["fromDest"].toString().toStdString();
            string toDestination=bookingObject["toDest"].toString().toStdString();
            string airline=bookingObject["airline"].toString().toStdString();
            string bookingClass=bookingObject["bookingClass"].toString().toStdString();
            double fromDestLatitude = bookingObject["fromDestLatitude"].toString(). toDouble();
            double fromDestLongitude = bookingObject["fromDestLongitude"].toString().toDouble();
            double toDestLatitude = bookingObject["toDestLatitude"].toString().toDouble();
            double toDestLongitude = bookingObject["toDestLongitude"].toString().toDouble();
            //check if the Flughafenkuerzel in the right format
            if(fromDestination.length() != 3 || toDestination.length() != 3){
                throw std::invalid_argument("Invalid Flughafenkuerzel format at object " + std::to_string(i+1)+" on line "+std::to_string(zaeler-3));
            }

            shared_ptr<Booking> booking =make_shared<FlightBooking>( id, price, fromDate, toDate,travelId,type,pred1,pred2, fromDestination,
                                                 toDestination,airline,bookingClass,fromDestLatitude,fromDestLongitude,toDestLatitude,toDestLongitude);
            bookings.push_back(booking);
            travel->addBooking(booking);
            customer->addTravel(travel);
//           if(!check){

//           if(!(std::type_index(typeid (booking))==std::type_index(typeid (travel->getTravelBookings()[1])))){
//               allTravels.push_back(travel);
//           }

//           }
           //unterschiedliche booking können gleich travelid und customerid haben , deshalb ist die travellist eines Kunden grösser als die gesamte anzahl der Travellist.
               // weil ein travel wird nur einmal angelegt.

        }else if(type=="RentalCar"){
            zaeler+=15;
            //check if the Rentalcar has all the attributes
            if (bookingObject["company"].toString().isEmpty() ||bookingObject["pickupLocation"].toString().isEmpty() ||
                    bookingObject["returnLocation"].toString().isEmpty() ) {
                throw std::invalid_argument("Empty attribute in JSON File at object " + std::to_string(i+1)+" on line "+std::to_string(zaeler-3));
            }

            string pickupLocation=bookingObject["pickupLocation"].toString().toStdString();
            string returnLocation=bookingObject["returnLocation"].toString().toStdString();
            string company=bookingObject["company"].toString().toStdString();
            string vehicleClass=bookingObject["vehicleClass"].toString().toStdString();
            double pickupLatitude = bookingObject["pickupLatitude"].toString().toDouble();
            double pickupLongitude = bookingObject["pickupLongitude"].toString().toDouble();
            double returnLatitude = bookingObject["returnLatitude"].toString().toDouble();
            double returnLongitude = bookingObject["returnLongitude"].toString().toDouble();
            shared_ptr<Booking> booking =make_shared<RentalCarReservation>(id, price,  fromDate, toDate,travelId,type,pred1,pred2,
                                                       pickupLocation,  returnLocation,  company,vehicleClass,pickupLatitude,pickupLongitude,
                                                       returnLatitude,returnLongitude);
            bookings.push_back(booking);
            travel->addBooking(booking);
            customer->addTravel(travel);
//            if(!check){

//            if(!(std::type_index(typeid (booking))==std::type_index(typeid (travel->getTravelBookings()[1])))){
//                allTravels.push_back(travel);
//            }

//            }

        }else if(type=="Hotel"){
            zaeler+=9;
            if (bookingObject["hotel"].toString().isEmpty() || bookingObject["town"].toString().isEmpty() ) {
                throw std::invalid_argument("Empty attribute in JSON File at object " + std::to_string(i+1)+" on line "+std::to_string(zaeler-3));
            }

            string hotel=bookingObject["hotel"].toString().toStdString();
            string town=bookingObject["town"].toString().toStdString();
            string roomType=bookingObject["roomType"].toString().toStdString();
            double hotelLatitude = bookingObject["hotelLatitude"].toString().toDouble();
            double hotelLongitude = bookingObject["hotelLongitude"].toString().toDouble();
            shared_ptr<Booking> booking = make_shared<HotelBooking>(id, price, fromDate, toDate,travelId,type,pred1,pred2, hotel, town,roomType,hotelLatitude,hotelLongitude);
            bookings.push_back(booking);
            travel->addBooking(booking);
            customer->addTravel(travel);
//            if(!check){

//            if(!(std::type_index(typeid (booking))==std::type_index(typeid (travel->getTravelBookings()[1])))){
//                allTravels.push_back(travel);
//            }

//            }


        }else if(type=="Train"){
            zaeler+=13;
            if (bookingObject["fromStation"].toString().isEmpty() || bookingObject["toStation"].toString().isEmpty()
                    || bookingObject["departureTime"].toString().isEmpty() || bookingObject["arrivalTime"].toString().isEmpty()){
                throw std::invalid_argument("Empty attribute in JSON File at object " + std::to_string(i+1) +" on line "+std::to_string(zaeler-3));
            }

            string fromDestination=bookingObject["fromStation"].toString().toStdString();
            string toDestination=bookingObject["toStation"].toString().toStdString();
            string departureTime=bookingObject["departureTime"].toString().toStdString();
            string arrivalTime=bookingObject["arrivalTime"].toString().toStdString();
            string ticketType=bookingObject["ticketType"].toString().toStdString();
            double toStationLatitude=bookingObject["toStationLatitude"].toDouble();
            double toStationLongitude=bookingObject["toStationLongitude"].toDouble();
            double fromStationLatitude=bookingObject["fromStationLatitude"].toDouble();
            double fromStationLongitude=bookingObject["fromStationLongitude"].toDouble();
            vector <station>connectingStations;
            QJsonArray Stations =bookingObject["connectingStations"].toArray() ;
//                        if(Stations.isEmpty()){       // zeile 945
//                         throw invalid_argument("Empty attribute in JSON File at object " + std::to_string(i+1)+" on line "+std::to_string(zaeler-3));
//                     }
            if(!Stations.isEmpty()){
            for(int j=0;j<Stations.size();j++){

                /*string Station= Stations[j].toString().toStdString();
                connectingStations.push_back(Station);*/
                QJsonObject stationsObject = Stations[j].toObject();
                string stationName = stationsObject["stationName"].toString().toStdString();
                double latitude = stationsObject["latitude"].toDouble();
                double longitude = stationsObject["longitude"].toDouble();

                station connecting(stationName,latitude,longitude);
                connectingStations.push_back(connecting);
            }
            }else {

            }
            shared_ptr<Booking> booking =make_shared<TrainTicket>(  id, price,fromDate, toDate,travelId,type,pred1,pred2, fromDestination,  toDestination,
                                                 departureTime, arrivalTime,ticketType,connectingStations,
                                                 toStationLatitude,toStationLongitude,fromStationLatitude,fromStationLongitude);
            bookings.push_back(booking);
            travel->addBooking(booking);
            customer->addTravel(travel);
//            if(!check){

//            if(!(std::type_index(typeid (booking))==std::type_index(typeid (travel->getTravelBookings()[1])))){
//                allTravels.push_back(travel);
//            }

//            }

        }else{
            throw std::runtime_error("Invalid booking type");
        }

   }


    for(auto &travel : allTravels){
        travel->topologicalSort();
    }


};
void TravelAgency::readIataCodes(QString fileName){
    allAirports.clear(); // clear any existing airport

    QFile file(fileName);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        throw std::invalid_argument("Failed to open file!");
    }

    // Read the contents of the file into a QString
    QString jsonData = file.readAll();
    // Parse the JSON data
    QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonData.toUtf8());

    //Checking if the JSON document is an array
    if (!jsonDoc.isArray()) {
        throw std::invalid_argument("Invalid JSON File");
    }
    QJsonArray airportsArray = jsonDoc.array();
    for (int i = 0; i < airportsArray.size(); i++) {
        if (!airportsArray[i].isObject()) { // Checking if the objects are valid
            throw std::invalid_argument("Invalid Airport in JSON File at object " + std::to_string(i + 1));
        }
        QJsonObject airportObject = airportsArray[i].toObject();

        std::string name = airportObject["name"].toString().toStdString();
        std::string isoCountry = airportObject["iso_country"].toString().toStdString();
        std::string municipality = airportObject["municipality"].toString().toStdString();
        std::string iata_code = airportObject["iata_code"].toString().toStdString();
        // Make an airport object
        shared_ptr<Airport> airport = make_shared<Airport>(name, isoCountry, municipality, iata_code);
        allAirports.insert(make_pair(iata_code,airport));
    }
     file.close();
};

/*void TravelAgency::displayBooking(){
    int flugBuchungen=0;
    double flugpreis=0.0;
    int mietwagenBuchungen=0;
    double mietwagenPreis=0.0;
    int hotelreservierung=0;
    double HotelPreis=0.0;
    int zugBuchungen=0;
    double zugPreis=0;

    for(auto booking:bookings){
        if(FlightBooking *flight=dynamic_cast<FlightBooking*>(booking)){
            cout<< flight->showDetails();
            cout<<endl;
            flugpreis+= flight->getPrice();
            flugBuchungen+=1;
        }else if(HotelBooking *hotel=dynamic_cast<HotelBooking*>(booking)){
            cout<<hotel->showDetails();
            cout<<endl;
            HotelPreis+= hotel->getPrice();
            hotelreservierung+=1;
        }else if(RentalCarReservation *rental=dynamic_cast<RentalCarReservation*>(booking)){
            cout<<rental->showDetails();
            cout<<endl;
            mietwagenPreis+=rental->getPrice();
            mietwagenBuchungen+=1;
        }else if(TrainTicket *ticket=dynamic_cast<TrainTicket*>(booking)){
            cout<<ticket->showDetails();
            cout<<endl;
            zugBuchungen+=1;
            zugPreis+=ticket->getPrice();
        }
    }
    cout << "Es wurden " << flugBuchungen << " Flugbuchungen im Wert von " << flugpreis << " Euro, "
         << mietwagenBuchungen << " Mietwagenbuchungen im Wert von " << mietwagenPreis << " Euro und "
         << hotelreservierung << " Hotelreservierungen im Wert von " << HotelPreis << " Euro angelegt."
         <<zugBuchungen<<" ZugBuchungen im Wert von "<<zugPreis<<" Euro,angelegt.\n";
};*/
QString TravelAgency:: getBookinInfo(){
    int flugBuchungen=0;
    double flugpreis=0.0;
    int mietwagenBuchungen=0;
    double mietwagenPreis=0.0;
    int hotelreservierung=0;
    double HotelPreis=0.0;
    int zugBuchungen=0;
    double zugPreis=0;
    shared_ptr<Customer> customer=findCustomer(1);
    //int  travel=findTravel1(17);

    int anzahltravel=allTravels.size();
//    for(auto i: allCustomers){
//       anzahltravel+=i->getTravelList().size();
//    }


    shared_ptr<Travel> travel= findTravel(17);
    for(auto const &booking:bookings){
        if(shared_ptr<FlightBooking>flight=dynamic_pointer_cast<FlightBooking>(booking)){
            flugpreis+= flight->getPrice();
            flugBuchungen+=1;
        }else if(shared_ptr<HotelBooking> hotel=dynamic_pointer_cast<HotelBooking>(booking)){
            HotelPreis+= hotel->getPrice();
            hotelreservierung+=1;
        }else if(shared_ptr<RentalCarReservation> rental=dynamic_pointer_cast<RentalCarReservation>(booking)){
            mietwagenPreis+=rental->getPrice();
            mietwagenBuchungen+=1;
        }else if(shared_ptr<TrainTicket>ticket=dynamic_pointer_cast<TrainTicket>(booking)){
            zugBuchungen+=1;
            zugPreis+=ticket->getPrice();
        }
    }
    ostringstream oss;
    oss << "Es wurden " << flugBuchungen << " Flugbuchungen im Wert von " << flugpreis << " Euro, "
         << mietwagenBuchungen << " Mietwagenbuchungen im Wert von " << mietwagenPreis << " Euro und "
         << hotelreservierung << " Hotelreservierungen im Wert von " << HotelPreis << " Euro angelegt."
         <<zugBuchungen<<" ZugBuchungen im Wert von "<<zugPreis<<" Euro,angelegt.\n"
         <<"Es wurden "<<anzahltravel<<" Reisen und "<<allCustomers.size()<<" Kunden angelegt."
         <<"Der Kunde mit der ID 1 hat "<< customer->getTravelList().size()<<" Reisen gebucht."
         <<"Zur Reise mit der ID 17 gehören "<<travel->getTravelBookings().size() <<" Buchungen"  ;  //travel->getTravelBookings().size()

    return QString::fromStdString(oss.str());//QString::fromStdString() ist eine Methode der Qt-Bibliothek und wird verwendet,
                                             //um eine std::string in ein QString zu konvertieren.
};

/*void TravelAgency:: readBinaryFile(QString fileName){
    for (auto booking : bookings) {
        delete booking;  //freigabe der speicherplatz aufm Heap
    }

    bookings.clear(); // Vektor wird geleert
    QFile file(fileName);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        std::cerr << "Failed to open file!";
    }

    char type;
    // alle gröBe +1 für das NullterminierungsZeichen.
    char id[39];
    double price;
    char fromDate [9];
    char toDate [9];
    char fromDest[4];
    char toDest[4];
    char airline[16];
    char pickupLocation[16];
    char returnLocation[16];
    char company[16];
    char hotel[16];
    char town[16];
    char fromStation[16];
    char toStation[16];
    char departurTime[6];
    char arrivalTime[6];
    int anzahlVerbindungen;
    char verbindungen[16];
    vector<string> verbindungsbahnhe;

    while(!file.atEnd()){
        file.read(&type, sizeof(char)) ;
        file.read(id, sizeof(char) * 38) ;
        id[38]='\0';
        file.read(reinterpret_cast<char*>(&price), sizeof(double));
        file.read(fromDate, sizeof(char) * 8);
        fromDate[8]='\0';
        file.read(toDate, sizeof(char) * 8);
        toDate[8]='\0';

        Booking* booking=nullptr;

        switch (type) {
        case 'F':
            file.read(fromDest,sizeof(char)*3);
            file.read(toDest,sizeof(char)*3);
            file.read(airline, sizeof(char) * 15);

            booking = new FlightBooking(id, price, fromDate, toDate, fromDest, toDest, airline);
            bookings.push_back(booking);
            break;
        case'H':

            file.read(hotel,sizeof(char)*15);
            hotel[15]='\0';
            file.read(town, sizeof(char)*15);
            town[15]='\0';
            booking = new HotelBooking( id,  price, fromDate,  toDate, hotel, town);
            bookings.push_back(booking);
            break;
        case'R':

            file.read(pickupLocation,sizeof(char)*15);
            file.read(returnLocation,sizeof(char)*15);
            file.read(company,sizeof(char)*15);
            booking= new RentalCarReservation(id,price, fromDate,  toDate,pickupLocation,  returnLocation,  company);
            bookings.push_back(booking);
            break;

        case'T':
            file.read(fromStation, sizeof(char)*15);
            file.read(toStation, sizeof(char)*15);
            file.read(departurTime, sizeof(char)*5);
            file.read(arrivalTime, sizeof(char)*5);
            file.read(reinterpret_cast<char*>(&anzahlVerbindungen), sizeof(int));
            for(int i=0;i<anzahlVerbindungen;i++){
                file.read(verbindungen, sizeof(char)*15);
                verbindungsbahnhe.push_back(verbindungen);
            }
            booking=new TrainTicket( id, price, fromDate,toDate, fromStation,  toStation, departurTime, arrivalTime,verbindungsbahnhe);
            bookings.push_back(booking);
            break;
        }


    };

    file.close();
};*/

shared_ptr<Booking> TravelAgency::findBooking(string id){
    for (auto &booking : bookings){
        if (booking->getId() == id)
            return booking;
    }
    return 0;
}


/*int TravelAgency::findTravel1(long id){
    int counter =0;
    for (auto travel : allTravels){
        if (travel->getId() == id)
            counter+=travel->getTravelBookings().size();
            //return travel;
    }
    return counter;
}*/
/*Travel* TravelAgency::findTravel(long id,long custormerId){
    for (auto travel : allTravels){
        if (travel->getId() == id && travel->getCustomerId()==custormerId)
            return travel;
    }
    return 0;
};*/
shared_ptr<Travel> TravelAgency::findTravel(long id){
    for (auto travel : allTravels){
        if (travel->getId() == id )
            return travel;
    }
    return 0;
}

shared_ptr<Airport> TravelAgency::findAirport(QString iata_code)
{
    for(auto &iata: allAirports){
        if(iata_code == QString::fromStdString(iata.first))
            return iata.second;
    }
    return nullptr;
}

const std::map<string, shared_ptr<Airport> > &TravelAgency::getAllAirports() const
{
    return allAirports;
}
shared_ptr<Customer>TravelAgency::findCustomer(long id){
    for (auto customer : allCustomers){
        if (customer->getId() == id)
            return customer;
    }
    return 0;
}
shared_ptr<Airport> TravelAgency:: findAirport(string airportCode){
    for (auto &airport : allAirports){
        if (airport.second->getIataCode() == airportCode)
            return airport.second;
    }
    return 0;
};
vector<shared_ptr<Booking>> TravelAgency:: getBookings(){
    return bookings;
};
void TravelAgency::displayBookingsOnMap(const shared_ptr<Travel>& travel){
    QJsonObject geoJsonObject;
    geoJsonObject["type"]="FeatureCollection";
    QJsonArray featureArray;

    //iterate over the bookings of the travels
    for(auto const& booking : travel->getTravelBookings()){
        if(std::shared_ptr<FlightBooking> flightBooking = std::dynamic_pointer_cast<FlightBooking>(booking)){
            // Flight Booking
            double fromDestLatitude = flightBooking->getFromDestLatitude();
            double fromDestLongitude = flightBooking->getFromDestLongitude();
            double toDestLatitude = flightBooking->getToDestLatitude();
            double toDestLongitude = flightBooking->getToDestLongitude();
            std::shared_ptr<Airport> fromAirport = findAirport(flightBooking->getFromDestination());
            QString fromAirportName = QString::fromStdString(fromAirport->getName());
            std::shared_ptr<Airport> toAirport = findAirport(flightBooking->getToDestination());
            QString toAirportName = QString::fromStdString(toAirport->getName());
            // Create the GeoJson object for the flight booking

            QJsonObject flightObject;
            flightObject["type"]="Feature";

            QJsonObject geometry;
            geometry["type"]="LineString";

            QJsonArray coordinate;

            QJsonArray startCoordinate;
            startCoordinate.append(fromDestLongitude);
            startCoordinate.append(fromDestLatitude);

            QJsonArray endCoordinate;
            endCoordinate.append(toDestLongitude);
            endCoordinate.append(toDestLatitude);


            coordinate.append(startCoordinate);
            coordinate.append(endCoordinate);
            geometry["coordinates"]=coordinate;
            flightObject["geometry"]=geometry;

            QJsonObject properties;
            properties["startAirportName"]= fromAirportName;
            properties["destAirportName"]= toAirportName;

            flightObject["properties"]=properties;
            // add the flightobject to the Geojson array
            featureArray.append(flightObject);

        } else if(shared_ptr<HotelBooking> hotelbooking = dynamic_pointer_cast<HotelBooking>(booking)){
            double hotelLatitude = hotelbooking->getHotelLatitude();
            double hotelLongitude = hotelbooking->getHotelLongitude();
            QString hotelName= QString::fromStdString( hotelbooking->getHotel());
            // Create the GeoJson object for the flight booking

            QJsonObject hotelObject;
            hotelObject["type"]="Feature";
            QJsonObject geometry;
            geometry["type"] = "Point";
            QJsonArray coordinates;
            coordinates.append(hotelLongitude);
            coordinates.append(hotelLatitude);
            geometry["coordinates"] = coordinates;
            hotelObject["geometry"] = geometry;

            QJsonObject properties;
            properties["hotelName"] = hotelName;

            hotelObject["properties"] = properties;

            // Add the flightObject to the GeoJSON array
            featureArray.append(hotelObject);
        } else if (std::shared_ptr<RentalCarReservation> carBooking = std::dynamic_pointer_cast<RentalCarReservation>(booking))
        {
            // Rental car reservation
            double pickupLatitude = carBooking->getPickupLatitude();
            double pickuplongitude = carBooking->getPickupLongitude();
            double returnLatitude = carBooking->getReturnLatitude();
            double returnLongitude = carBooking->getReturnLongitude();
            QString pickupLocation = QString::fromStdString(carBooking->getPickupLocation());
            QString returnLocation = QString::fromStdString(carBooking->getReturnLocation());

            // Create the GeoJson object for the Car Booking
            QJsonObject carObject;
            carObject["type"] = "Feature";
            QJsonObject geometry;
            geometry["type"] = "LineString";
            QJsonArray coordinates;
            QJsonArray startCoordinates;
            startCoordinates.append(pickuplongitude);
            startCoordinates.append(pickupLatitude);
            QJsonArray destCoordinates;
            destCoordinates.append(returnLongitude);
            destCoordinates.append(returnLatitude);
            coordinates.append(startCoordinates);
            coordinates.append(destCoordinates);
            geometry["coordinates"] = coordinates;
            carObject["geometry"] = geometry;

            QJsonObject properties;
            properties["pickupLocation"] = pickupLocation;
            properties["returnLocation"] = returnLocation;

            carObject["properties"] = properties;

            // Add the flightObject to the GeoJSON array
            featureArray.append(carObject);
        }
        else if (std::shared_ptr<TrainTicket> train = std::dynamic_pointer_cast<TrainTicket>(booking))
        {
            double toStationLatitude = train->getToStationLatitude();
            double toStationLongitude = train->getToStationLongitude();
            double fromStationLatitude = train->getFromStationLatitude();
            double fromStationLongitude = train->getFromStationLongitude();
           // vector<vector<double>> cooordinate;
            vector<QJsonArray> interCoordinate;
            vector<string> stationsName= train->getConnectingStationsName();

            vector<station> haltestelle = train->getConnectingStations();
            for( unsigned int i=0; i< haltestelle.size();i++){
                interCoordinate[i].append(haltestelle[i].latitude);
                interCoordinate[i].append(haltestelle[i].longitude);
            }
            // Create the GeoJson object for the Car Booking
            QJsonObject trainObject;
            trainObject["type"]="Feature";
            QJsonObject geometry;
            geometry["type"] = "LineString";
            QJsonArray coordinates;
            QJsonArray startCoordinates;
            startCoordinates.append(fromStationLongitude);
            startCoordinates.append(fromStationLatitude);

            QJsonArray destCoordinates;
            destCoordinates.append(toStationLongitude);
            destCoordinates.append(toStationLatitude);


            for(auto const & i: interCoordinate){
                coordinates.append(i);
            }
            coordinates.append(startCoordinates);
            coordinates.append(destCoordinates);
            geometry["coordinates"] = coordinates;
            trainObject["geometry"] = geometry;

            QJsonObject properties;
            QString fromDestination = QString::fromStdString( train->getFromDestination());
            QString toDestination = QString::fromStdString( train->getToDestination());
            properties["pickupLocation"] = fromDestination;
            properties["returnLocation"] = toDestination;
            QJsonArray Name;
            for(auto &i: stationsName){
                Name.push_back(QString::fromStdString(i));
            }
            properties["interStationName"]=Name;

            trainObject["properties"] = properties;

            // Add the flightObject to the GeoJSON array
            featureArray.append(trainObject);

        }
    }
    geoJsonObject["features"] = featureArray;

    // Create the GeoJson document
    QJsonDocument geoJsonDoc(geoJsonObject);

    // Convert the GeoJson document to a string
    QByteArray geoJsonData = geoJsonDoc.toJson(QJsonDocument::Indented);
    QString geoJsonString(geoJsonData);

    // Encode the GeoJson string for use in the URL
    QString encodedGeoJson = QUrl::toPercentEncoding(geoJsonString);

    // Create the URL with the encoded GeoJson
    QString mapUrl = "http://townsendjennings.com/geo/?geojson=" + encodedGeoJson;

    // Open the URL in the default web browser
    QDesktopServices::openUrl(QUrl(mapUrl));

};

vector<shared_ptr<Travel>> TravelAgency::getTravels() const {
    return allTravels;
}
vector<shared_ptr<Customer>> TravelAgency::getCustomers(){
    return allCustomers;
};

void TravelAgency::addIncorrectReservation(IncorrectReservation r)
{
    incorrectReservations.push_back(r);
}

const std::vector<IncorrectReservation> &TravelAgency::getIncorrectReservations() const
{
    return incorrectReservations;
}

const std::map<std::string, bool> &TravelAgency::getConsistencyResults() const
{
    return consistencyResults;
}

void TravelAgency::setConsistencyResult(const std::string& testName, bool result)
{
    consistencyResults[testName] = result;
}

void TravelAgency:: clearIncorrectReservations()
{
    incorrectReservations.clear();
}

const Config &TravelAgency::getConfig() const
{
    return config;
}

void TravelAgency::setConfig(const Config &newConfig)
{
    config = newConfig;
};

//void TravelAgency:: clearBooking(){
//    for(auto i:bookings){
//        delete i;
//    }
//};
TravelAgency::~TravelAgency(){
//    for(auto booking:bookings){
//        delete booking;
//    }

//    for(auto i:allCustomers){
//        delete i;
//    }

//   for(auto j: allTravels){
//        delete j;
//    }
}
