#include "check.h"
#include <QDate>
#include<QMessageBox>
#include "QLocale"
#include "rentalcarreservation.h"
#include "hotelbooking.h"

Check::Check(shared_ptr<TravelAgency> travelagency): travelagency(travelagency)
{

}

//void Check::topologicalSort(std::shared_ptr<Digraph<std::shared_ptr<Booking>, 100> > graph, int v, std::stack<std::shared_ptr<Booking> > &sortedBookings, std::vector<bool> &visited)
//{
//    visited[v] = true;

//    for (int i = graph->firstEdge(v); i >= 0; i = graph->nextEdge(v, i)) {
//        auto booking = graph->getVertexValue(i);
//        if (!visited[i] && booking->getType() != "RentalCar") {
//            topologicalSort(graph, i, sortedBookings, visited);
//        }
//    }

//    sortedBookings.push(graph->getVertexValue(v));
//}

void Check::checkTravelsDisjunct(IncorrectReservation &info)
{
    vector<shared_ptr<Travel>> travels = travelagency->getTravels();


    for (size_t i = 0; i <travels.size() ; ++i) {
        for (size_t j = i + 1; j < travels.size(); ++j) {
            //shared_ptr<Customer> customer= travelagency->findCustomer(travelagency->getTravels()[i]->getCustomerId());
            //vector<shared_ptr<Travel>> travels= customer->getTravelList();
            if(travels[i]->getCustomerId()==travels[j]->getCustomerId()){
                if (travels[i]->overlap( travels[j])) {

                    info.type=OverlappedTravel;
                    info.errorInfo  = QString(" Customer %1: travel %2 and travel %3 ueberlappen sich.")
                            .arg(travels[i]->getCustomerId())
                            .arg(travelagency->getTravels()[i]->getId())
                            .arg(travelagency->getTravels()[j]->getId());

                    travelagency->addIncorrectReservation(info);

                    //%1, %2, %3 sind Platzhalter, die durch die entsprechenden Werte ersetzt werden.
                    //Die arg-Methode von QString wird verwendet, um die Werte in die Platzhalter einzufügen.
                    // In diesem Fall sind dies der Kundenname (%1), die Reisenummer i + 1 (%2) und die Reisenummer j + 1 (%3)
                }
            }
        }

    }
}

void Check::checkNoMissingHotels(IncorrectReservation &info){
//   // bool allHotelsPresent = true;
//    for (const auto& travel : travelagency->getTravels()) {
//        // graph erstellen
//        //std::shared_ptr<Digraph<std::shared_ptr<Booking>, 100>> graph = travel->createGraph();


//        vector<std::shared_ptr<Booking>> sortedBookings = travel->getTravelBookings();
////        std::vector<bool> visited(graph->getNumVertices(), false);

////        // recursive helper function to store topological sort starting from all vertices one by one
////        for (int i = 0; i < graph->getNumVertices(); ++i) {
////            if (!visited[i]) {
////            topologicalSort(graph, i, sortedBookings, visited);
////            }
////        }

//        //  previous date as string
//        std::string prevDate;

//        // Iterate over sorted bookings
//       // while (!sortedBookings.empty()) {
//           for (auto &booking : sortedBookings){
//            //sortedBookings.pop();

//            //  car rentals ignorieren
//            if (booking->getType() == "RentalCar") {
//            continue;
//            }

//            // Check if fromDate of booking is after previous toDate
//            if (!prevDate.empty() && booking->getFromDate() != prevDate) {
//            //allHotelsPresent = false;
//            // Format dates using QLocale
//            QString formattedPrevDate = QLocale("de_DE").toString(QDateTime::fromString(QString::fromStdString(prevDate), "yyyyMMdd"), "dddd, d.MMMM yyyy");
//            QString formattedFromDate = QLocale("de_DE").toString(QDateTime::fromString(QString::fromStdString(booking->getFromDate()), "yyyyMMdd"), "dddd, d.MMMM yyyy");

//            // Generate error message
//            info.type = MissingHotel;
//            info.errorInfo = "Für Kunden " + QString::number(travel->getCustomerId()) +
//                             " und Reise " + QString::number(travel->getId()) +
//                             ", fehlt eine Hotelbuchung zwischen " +
//                             QString::fromStdString(formattedPrevDate.toStdString()) + " und " +
//                             QString::fromStdString(formattedFromDate.toStdString());

//            // Save the message
//            travelagency->addIncorrectReservation(info);
//            }

//            // Update previous date to toDate of current booking
//            prevDate = booking->getToDate();
//        }
//    }
//    // Save the result of the consistency check
//   // travelagency->setConsistencyResult("checkNoMissingHotels", allHotelsPresent);
    vector<std::shared_ptr<Travel>> travels = travelagency->getTravels();

        for (auto &travel : travels) {
            vector<shared_ptr<Booking>> sortedBookings = travel->getTravelBookings();

            // Sortiere die Buchungen nach Datum
            std::sort(sortedBookings.begin(), sortedBookings.end(),
                      [](const std::shared_ptr<Booking> &a, const std::shared_ptr<Booking> &b) {
                          return a->getFromDate() < b->getFromDate();
                      });

            //qDebug() << "Travel: " + QString::number(travel->getId());
            std::string lastToDate = travel->findStartdatum(); // Startdatum der Reise


            for (const auto &booking : sortedBookings) {
                if (std::dynamic_pointer_cast<RentalCarReservation>(booking)) {
                    continue; // Überspringe die Überprüfung für Mietwagenreservierungen
                }

                if (booking->getFromDate() != lastToDate) {
                    // Es gibt eine Lücke zwischen den Buchungen
                    info.type = MissingHotel;
                    info.errorInfo = "Für Kunde: " + QString::number(travel->getCustomerId()) +
                                     " und Reise: " + QString::number(travel->getId()) +
                                     " fehlt eine Übernachtung zwischen dem " +
                                     QString::fromStdString(lastToDate) + " und dem " +
                                     QString::fromStdString(booking->getFromDate()) ;
                    travelagency->addIncorrectReservation(info);

                    break; // Beende die Schleife, da die Überprüfung bereits durchgeführt wurde
                }

                lastToDate = booking->getToDate();
            }


        }
};

//void Check::checkNoMissingHotels(IncorrectReservation &info){

//}

//void Check::checkNoOverlappingHotels(IncorrectReservation &info){
//    bool noOverlappingHotels = true;
//    for (const auto& travel : travelagency->getTravels()) {
//        // Create the graph
//        std::shared_ptr<Digraph<std::shared_ptr<Booking>, 100>> graph = travel->createGraph();

//        // Perform topological sorting
//        std::stack<std::shared_ptr<Booking>> sortedBookings;
//        std::vector<bool> visited(graph->getNumVertices(), false);

//        // Call the recursive helper function to store topological sort starting from all vertices one by one
//        for (int i = 0; i < graph->getNumVertices(); ++i) {
//            if (!visited[i]) {
//            topologicalSort(graph, i, sortedBookings, visited);
//            }
//        }

//        // Store previous booking end date as string
//        std::string prevEndDate;

//        // Iterate over sorted bookings
//        while (!sortedBookings.empty()) {
//            auto booking = sortedBookings.top();
//            sortedBookings.pop();

//            // Ignore car rentals
//            if (booking->getType() == "RentalCar") {
//            continue;
//            }

//            // Check for overlapping bookings
//            if (!prevEndDate.empty() && booking->getFromDate() < prevEndDate) {
//            noOverlappingHotels = false;
//            // Format dates using QLocale
//            QString formattedPrevEndDate = QLocale("de_DE").toString(QDateTime::fromString(QString::fromStdString(prevEndDate), "yyyyMMdd"), "dddd, d.MMMM yyyy");
//            QString formattedFromDate = QLocale("de_DE").toString(QDateTime::fromString(QString::fromStdString(booking->getFromDate()), "yyyyMMdd"), "dddd, d.MMMM yyyy");
//            QString formattedToDate = QLocale("de_DE").toString(QDateTime::fromString(QString::fromStdString(booking->getToDate()), "yyyyMMdd"), "dddd, d.MMMM yyyy");

//            // Generate error message
//            info.type = OverlappedHotel;
//            info.errorInfo = "Für Kunden " + QString::number(travel->getCustomerId()) +
//                             " und Reise " + QString::number(travel->getId()) +
//                             ", gibt es eine Überlappung von Hotelbuchungen zwischen " +
//                             QString::fromStdString(formattedPrevEndDate.toStdString()) + " und " +
//                             QString::fromStdString(formattedToDate.toStdString()) +
//                             " (neue Buchung von " + QString::fromStdString(formattedFromDate.toStdString()) + ")";

//            // Save the message
//            travelagency->addIncorrectReservation(info);
//            }

//            // Update previous booking end date to toDate of current booking
//            prevEndDate = booking->getToDate();
//        }
//    }
//    // Save the result of the consistency check
//    travelagency->setConsistencyResult("checkNoOverlappingHotels", noOverlappingHotels);
//};

void Check::checkNoOverlappingHotels(IncorrectReservation &info){
//    std::string currentStartDate, currentEndDate;
//    std::vector<std::shared_ptr<Travel>> travels = travelagency->getTravels();

//    for (auto &travel : travels) {
//        std::vector<std::shared_ptr<Booking>> sortedBookings = travel->getTravelBookings();

//        for (unsigned int i = 0; i < sortedBookings.size(); i++) {
//            std::shared_ptr<Booking> currentBooking = sortedBookings[i];

//            if (std::shared_ptr<RentalCarReservation> car = dynamic_pointer_cast<RentalCarReservation>(currentBooking)) {
//                continue;
//            }
//            currentStartDate = currentBooking->getFromDate();
//            currentEndDate = currentBooking->getToDate();

//            if (i + 1 < sortedBookings.size()) {
//                if (std::shared_ptr<RentalCarReservation> car = dynamic_pointer_cast<RentalCarReservation>(
//                        currentBooking)) {
//                    continue;
//                }
//             if(currentBooking->getType() == "Hotel"){
//                if (currentStartDate > sortedBookings[i + 1]->getFromDate()) {
//                    info.type = OverlappedHotel;
//                    info.errorInfo = "Hotelbuchung für Kunde: "+  QString::number(travel->getCustomerId())+
//                                     " und Reise: "+ QString::number(travel->getId()) + " uberlappt mit benachbarter Buchung vom "+
//                                     QString::fromStdString(currentBooking->getFromDate())+ " bis zum "+
//                                     QString::fromStdString(sortedBookings[i + 1]->getToDate())+". Beteiligte Buchungen : "+
//                               QString::fromStdString(sortedBookings[i + 1]->getId())+ " , "+QString::fromStdString(currentBooking->getId());
//                    travelagency->addIncorrectReservation(info);
//                    break;
//                }

//                if (currentEndDate > sortedBookings[i + 1]->getToDate()) {
//                    info.type = OverlappedHotel;
//                    info.errorInfo = "Hotelbuchung für Kunde: "+  QString::number(travel->getCustomerId())+
//                                     " und Reise: "+ QString::number(travel->getId()) + " uberlappt mit benachbarter Buchung vom "+
//                                     QString::fromStdString(sortedBookings[i + 1]->getFromDate())+ " bis zum "+
//                                     QString::fromStdString(currentBooking->getToDate())+". Beteiligte Buchungen : "+
//                            QString::fromStdString(sortedBookings[i + 1]->getId())+ " , "+QString::fromStdString(currentBooking->getId());

//                    travelagency->addIncorrectReservation(info);
//                    break;
//                }

//              }

//            }

//        }

//    }
    std::vector<std::shared_ptr<Travel>> travels = travelagency->getTravels();

        for (auto &travel : travels) {
            std::vector<std::shared_ptr<Booking>> sortedBookings = travel->getTravelBookings();

            // Sortiere die Buchungen nach Datum
            std::sort(sortedBookings.begin(), sortedBookings.end(),
                      [](const std::shared_ptr<Booking> &a, const std::shared_ptr<Booking> &b) {
                          return a->getFromDate() < b->getFromDate();
                      });


            std::string lastToDate; // Enddatum der letzten Hotelbuchung


            for (unsigned int i = 0; i < sortedBookings.size(); i++) {

                if (sortedBookings[i]->getType() != "Hotel") {
                    continue; // Überspringe Buchungen, die keine Hotels sind
                }

                if (!lastToDate.empty() && sortedBookings[i]->getFromDate() < lastToDate) {
                    // Es gibt eine Überlappung zwischen den Hotelbuchungen
                    info.type = OverlappedHotel;
                    info.errorInfo = "Für Kunde: " + QString::number(travel->getCustomerId()) +
                                     " und Reise: " + QString::number(travel->getId()) +
                                     " hat überlappende Hotelbuchungen";
                    travelagency->addIncorrectReservation(info);

                    break; // Beende die Schleife, da die Überprüfung bereits durchgeführt wurde
                }

                lastToDate = sortedBookings[i]->getToDate();
            }


        }
}

//void Check::checkNoOverlappingRentalCars(IncorrectReservation &info){
//    bool noOverlappingRentalCars = true;
//    for (const auto& travel : travelagency->getTravels()) {
//        // Create the graph
//        std::shared_ptr<Digraph<std::shared_ptr<Booking>, 100>> graph = travel->createGraph();

//        // Perform topological sorting
//        std::stack<std::shared_ptr<Booking>> sortedBookings;
//        std::vector<bool> visited(graph->getNumVertices(), false);

//        // Call the recursive helper function to store topological sort starting from all vertices one by one
//        for (int i = 0; i < graph->getNumVertices(); ++i) {
//            if (!visited[i]) {
//            topologicalSort(graph, i, sortedBookings, visited);
//            }
//        }

//        // Store previous booking end date as string
//        std::string prevEndDate;

//        // Iterate over sorted bookings
//        while (!sortedBookings.empty()) {
//            auto booking = sortedBookings.top();
//            sortedBookings.pop();

//            // Ignore hotel bookings
//            if (booking->getType() != "Hotel") {
//            continue;
//            }

//            // Check for overlapping rental car bookings
//            if (!prevEndDate.empty() && booking->getFromDate() < prevEndDate) {
//            noOverlappingRentalCars = false;
//            // Format dates using QLocale
//            QString formattedPrevEndDate = QLocale("de_DE").toString(QDateTime::fromString(QString::fromStdString(prevEndDate), "yyyyMMdd"), "dddd, d.MMMM yyyy");
//            QString formattedFromDate = QLocale("de_DE").toString(QDateTime::fromString(QString::fromStdString(booking->getFromDate()), "yyyyMMdd"), "dddd, d.MMMM yyyy");
//            QString formattedToDate = QLocale("de_DE").toString(QDateTime::fromString(QString::fromStdString(booking->getToDate()), "yyyyMMdd"), "dddd, d.MMMM yyyy");

//            // Generate error message
//            info.type = OverlappedCar;
//            info.errorInfo = "Für Kunden " + QString::number(travel->getCustomerId()) +
//                             " und Reise " + QString::number(travel->getId()) +
//                             ", gibt es eine Überlappung von Mietwagenbuchungen zwischen " +
//                             QString::fromStdString(formattedPrevEndDate.toStdString()) + " und " +
//                             QString::fromStdString(formattedToDate.toStdString()) +
//                             " (neue Buchung von " + QString::fromStdString(formattedFromDate.toStdString()) + ")";

//            // Save the message
//            travelagency->addIncorrectReservation(info);
//            }

//            // Update previous booking end date to toDate of current booking
//            prevEndDate = booking->getToDate();
//        }
//    }
//    // Save the result of the consistency check
//    travelagency->setConsistencyResult("checkNoOverlappingRentalCars", noOverlappingRentalCars);
//};

void Check::checkNoOverlappingRentalCars(IncorrectReservation &info){
//    std::string currentStartDate, currentEndDate;
//    std::vector<std::shared_ptr<Travel>> travels = travelagency->getTravels();

//    for (auto &travel : travels) {
//        std::vector<std::shared_ptr<Booking>> sortedBookings = travel->getTravelBookings();

//        for (unsigned int i = 0; i < sortedBookings.size(); i++) {
//          std::shared_ptr<Booking> currentBooking = sortedBookings[i];

//          // Überspringe Hotelbuchungen
//          if (std::dynamic_pointer_cast<HotelBooking>(currentBooking) != nullptr) {
//            continue;
//          }

//          currentStartDate = currentBooking->getFromDate();
//          currentEndDate = currentBooking->getToDate();

//          if (i + 1 < sortedBookings.size()) {
//            // Überspringe Hotelbuchungen
//            if (std::dynamic_pointer_cast<HotelBooking>(sortedBookings[i + 1]) != nullptr) {
//                continue;
//            }

//            if(currentBooking->getType() == "RentalCar") {
//                if (currentStartDate > sortedBookings[i + 1]->getFromDate()) {
//                    info.type = OverlappedCar;
//                    info.errorInfo = "Mietwagenbuchung für Kunde: " + QString::number(travel->getCustomerId()) +
//                                     " und Reise: " + QString::number(travel->getId()) + " überlappt mit benachbarter Buchung vom " +
//                                     QString::fromStdString(currentStartDate) + " bis zum " +
//                                     QString::fromStdString(sortedBookings[i + 1]->getToDate())+ ". Beteiligte Buchungen : "+
//                            QString::fromStdString(sortedBookings[i + 1]->getId())+ " , "+QString::fromStdString(currentBooking->getId());
//                    travelagency->addIncorrectReservation(info);
//                    break;
//                }

//                if (currentEndDate > sortedBookings[i + 1]->getToDate()) {
//                    info.type = OverlappedCar;
//                    info.errorInfo = "Mietwagenbuchung für Kunde: " + QString::number(travel->getCustomerId()) +
//                                     " und Reise: " + QString::number(travel->getId()) + " überlappt mit benachbarter Buchung vom " +
//                                     QString::fromStdString(sortedBookings[i + 1]->getFromDate()) + " bis zum " +
//                                     QString::fromStdString(currentEndDate) + ". Beteiligte Buchungen : "+
//                            QString::fromStdString(sortedBookings[i + 1]->getId())+ " , "+QString::fromStdString(currentBooking->getId());
//                    travelagency->addIncorrectReservation(info);
//                    break;
//                }
//            }
//          }
//        }
//    }


    string currentStartDate, currentEndDate;
   vector<std::shared_ptr<Travel>> travels = travelagency->getTravels();

    for (auto &travel : travels) {
        std::vector<std::shared_ptr<Booking>> sortedBookings = travel->getTravelBookings();

        for (unsigned int i = 0; i < sortedBookings.size(); i++) {
          std::shared_ptr<Booking> currentBooking = sortedBookings[i];

          // Überspringe Hotelbuchungen
          if (std::dynamic_pointer_cast<HotelBooking>(currentBooking) != nullptr) {
            continue;
          }

          currentStartDate = currentBooking->getFromDate();
          currentEndDate = currentBooking->getToDate();

          if (i + 1 < sortedBookings.size()) {
            // Überspringe Hotelbuchungen
            if (std::dynamic_pointer_cast<HotelBooking>(sortedBookings[i + 1]) != nullptr) {
                continue;
            }

            if(currentBooking->getType() == "RentalCar") {
                if (currentStartDate > sortedBookings[i + 1]->getFromDate()) {
                    info.type = OverlappedCar;
                    info.errorInfo = "Mietwagenbuchung für Kunde: " + QString::number(travel->getCustomerId()) +
                                     " und Reise: " + QString::number(travel->getId()) + " überlappt mit benachbarter Buchung vom " +
                                     QString::fromStdString(currentStartDate) + " bis zum " +
                                     QString::fromStdString(sortedBookings[i + 1]->getToDate());
                    travelagency->addIncorrectReservation(info);
                    break;
                }

                if (currentEndDate > sortedBookings[i + 1]->getToDate()) {
                    info.type = OverlappedCar;
                    info.errorInfo = "Mietwagenbuchung für Kunde: " + QString::number(travel->getCustomerId()) +
                                     " und Reise: " + QString::number(travel->getId()) + " überlappt mit benachbarter Buchung vom " +
                                     QString::fromStdString(sortedBookings[i + 1]->getFromDate()) + " bis zum " +
                                     QString::fromStdString(currentEndDate);
                    travelagency->addIncorrectReservation(info);
                    break;
                }
            }
          }
        }
    }




}

void Check::operator()()
{
    Config  config =travelagency->getConfig();
    IncorrectReservation errorMessage, msgMissingHotels, msgOverlappingHotels, msgOverlappingCars;
    travelagency->clearIncorrectReservations();
    if (config.overlappedTravel)
        checkTravelsDisjunct(errorMessage);
    if (config.missedHotel)
        checkNoMissingHotels(msgMissingHotels);
    if (config.overlappedHotel)
        checkNoOverlappingHotels(msgOverlappingHotels);
    if (config.overlappedCar)
        checkNoOverlappingRentalCars(msgOverlappingCars);

   //  travelagency->clearIncorrectReservations();

//    if(!checkTravelsDisjunct(message)){
//        QMessageBox::critical(nullptr, "Error", message);
//    }

}

bool Check::travelsOverlap(const shared_ptr<Travel> &travel,const shared_ptr<Travel> &travel2)
{

    for (const auto& booking1 : travel->getTravelBookings() ) {
              for (const auto& booking2 : travel2->getTravelBookings() ) {
                  if (dateOverlap(booking1->getFromDate(), booking1->getToDate(),
                                  booking2->getFromDate(), booking2->getToDate())) {
                      return true;
                  }
              }
          }
          return false;
}

bool Check::dateOverlap(const string &startDate1, const string &endDate1, const string &startDate2, const string &endDate2)
{
    QDate start1 = QDate::fromString(QString::fromStdString(startDate1), "dd.MM.yyyy");
           QDate end1 = QDate::fromString(QString::fromStdString(endDate1), "dd.MM.yyyy");
           QDate start2 = QDate::fromString(QString::fromStdString(startDate2), "dd.MM.yyyy");
           QDate end2 = QDate::fromString(QString::fromStdString(endDate2), "dd.MM.yyyy");

           // Überprüfen Sie, ob die Zeiträume überlappen
           return !(end1 < start2 || end2 < start1);
}
