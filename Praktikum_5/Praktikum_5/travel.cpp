#include "travel.h"
#include "qdatetime.h"


Travel::Travel(long id,long customerId):
    id(id), customerId(customerId)
{
    //travelGraph = createGraph();
}
void Travel::addBooking(shared_ptr<Booking> booking){
    travelBookings.push_back(booking);
    travelGraph->insertVertex(travelBookings.size() - 1, booking);
}


long Travel::getId(){
    return id;
}
long Travel::getCustomerId(){
    return customerId;
};

vector <shared_ptr<Booking>> Travel::getTravelBookings() const{
    return travelBookings;
}

void Travel::topologicalSort()
{
    struct VertexData
    {
        int vertexNumber;
        std::shared_ptr<Booking> vertexValue;
        int endTime;
    };

    QString pre1ID = "";
    QString pre2ID = "";
    int pre1 = -1;
    int pre2 = -1;
    // Kanten Aufbau

    for (unsigned int i = 0; i < travelBookings.size(); i++) {

        if (!travelGraph->getVertexValue(i)->getPredecessor1().empty()) {
            // Suche , nach dem index in dem Travelgrah , um eine kante hinzuzufügen brauchen wir diesen index
            int eigenerKnoten;
            for (unsigned int j = 0; j < travelBookings.size(); j++) {
                QString bookingId = QString::fromStdString(travelGraph->getVertexValue(j)->getId());

                if (bookingId == QString::fromStdString(travelBookings[i]->getId())) {
                    eigenerKnoten = j;
                    break;
                }
            }

            //nachdem wir das index gefunden haben, suchen wir nach dem Index seines Predecessors . anschliessen kann man die kannte hinzufügen im graph.
            pre1ID = QString::fromStdString(travelBookings[i]->getPredecessor1());
            for (unsigned int j = 0; j < travelBookings.size(); j++) {
                if (pre1ID == QString::fromStdString(travelBookings[j]->getId())) {
                    pre1 = j;
                    travelGraph->insertEdge(pre1, eigenerKnoten);
                    travelGraph->setPredecessor(eigenerKnoten, pre1);
                    std::cout << "Kante eingefügt. Pre1 " << to_string(eigenerKnoten) << "  "
                              << to_string(pre1) << std::endl;
                    break;
                }
            }
        }
        if (!travelGraph->getVertexValue(i)->getPredecessor2().empty()) {
            pre2ID = QString::fromStdString(travelGraph->getVertexValue(i)->getPredecessor2());
            int eigenerKnoten;
            for (unsigned int j = 0; j < travelBookings.size(); j++) {
                QString bookingId = QString::fromStdString(travelGraph->getVertexValue(j)->getId());

                if (bookingId == QString::fromStdString(travelBookings[i]->getId())) {
                    eigenerKnoten = j;
                    break;
                }
            }
            pre2ID = QString::fromStdString(travelBookings[i]->getPredecessor2());
            for (unsigned int j = 0; j < travelBookings.size(); j++) {
                if (pre2ID == QString::fromStdString(travelBookings[j]->getId())) {
                    pre2 = j;
                    travelGraph->insertEdge(pre2, eigenerKnoten);
                    travelGraph->setPredecessor(eigenerKnoten, pre2);
                    std::cout << "Kante eingefügt: Pre2" << to_string(eigenerKnoten) << "  "
                              << to_string(pre2) << std::endl;

                    break;
                }
            }
        }
    }
    // TO DO: DIE KNOTEN WERDEN DOPPELT AUSGEGEBEN
    DepthFirstSearch(*travelGraph);

    std::vector<VertexData> toBeSorted;
    VertexData vertexData;
    for (unsigned int i = 0; i < travelBookings.size(); i++) {
        vertexData.vertexNumber = i;
        vertexData.vertexValue = travelGraph->getVertexValue(i);
        vertexData.endTime = travelGraph->getEnd(i);
        toBeSorted.push_back(vertexData);
    }
    std::sort(toBeSorted.begin(), toBeSorted.end(), [](const VertexData &a, const VertexData &b) {
        return a.endTime > b.endTime;
    });

    travelBookings.clear();
    for (auto &v : toBeSorted) {
        travelBookings.push_back(v.vertexValue);
    }
}

//std::shared_ptr<Digraph<std::shared_ptr<Booking>, 100> > Travel::createGraph()
//{
//    std::shared_ptr<Digraph<std::shared_ptr<Booking>, 100>> graph(new Digraph<std::shared_ptr<Booking>, 100>());

//    for (const auto& booking : travelBookings) {
//        int v = travelBookings.size() + 1;
//        graph->insertVertex(v, booking);

//        if (!booking->getPredecessor1().empty()) {
//            int w = findBookingIndex(booking->getPredecessor1());
//            if (w != -1) {
//                graph->insertEdge(w, v);
//            }
//        }

//        if (!booking->getPredecessor2().empty()) {
//            int w = findBookingIndex(booking->getPredecessor2());
//            if (w != -1) {
//                graph->insertEdge(w, v);
//            }
//        }
//    }

//    return graph;
//}
int Travel::findBookingIndex(const std::string& id){
    for (size_t i = 0; i < travelBookings.size(); i++) {
        if (travelBookings[i]->getId() == id) {
            return static_cast<int>(i + 1);
        }
    }
    return -1;
}

bool Travel::overlap(const std::shared_ptr<Travel> &other) const
{
    const auto& myBookings = getTravelBookings();
    const auto& otherBookings = other->getTravelBookings();

    for (const auto& myBooking : myBookings) {
        for (const auto& otherBooking : otherBookings) {
            if (bookingsOverlap(myBooking, otherBooking)) {
                return true;
            }
        }
    }

    return false;
}

bool Travel::bookingsOverlap(const std::shared_ptr<Booking> &booking1, const std::shared_ptr<Booking> &booking2) const
{
    // Start- und Enddaten der Buchungen abrufen
    const std::string& myFromDate = booking1->getFromDate();
    const std::string& myToDate = booking1->getToDate();
    const std::string& otherFromDate = booking2->getFromDate();
    const std::string& otherToDate = booking2->getToDate();

    // Überlappung prüfen
    if (myFromDate <= otherToDate && myToDate >= otherFromDate) {
        // Überlappung gefunden
        return true;
    }

    return false;

}

string Travel::findStartdatum() const
{
    std::string start;
    start = travelBookings.at(0)->getFromDate();

    for (unsigned int i = 0; i < travelBookings.size(); i++) {
        if (travelBookings.at(i)->getFromDate() < start) {
            start = travelBookings.at(i)->getFromDate();
        }
    }
    return start;
}

string Travel::findEnddatum() const
{
    std::string end;
    end = travelBookings.at(0)->getToDate();

    for (unsigned int i = 0; i < travelBookings.size(); i++) {
        if (travelBookings.at(i)->getToDate() > end) {
            end = travelBookings.at(i)->getToDate();
        }
    }
    return end;
};
pair<std::string, std::string> Travel::calculateTravelDates() const{
    string earliestStartDate ;
    string latestEndDate;

    for(auto booking: travelBookings){

        string startDate=booking->getFromDate();
        string EndDate=booking->getToDate();
        if(earliestStartDate.empty() || startDate<earliestStartDate){
            earliestStartDate=startDate;
        }
        if(latestEndDate.empty() || EndDate>latestEndDate){
            latestEndDate=EndDate;
        }
    }

    return make_pair(earliestStartDate,latestEndDate);
};


Travel::~Travel(){
    //    for(auto j : travelBookings){
    //        delete j;
    //    }
}
