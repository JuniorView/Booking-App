#ifndef TRAVEL_H
#define TRAVEL_H
#include <string>
#include <vector>
#include "booking.h"
#include "digraph.h"
#include "algorithmen.cpp"
#include <memory>
using namespace std;

class Travel
{
public:
    Travel(long id,long customerId);
    void addBooking(shared_ptr<Booking> booking);
    long getId();
    long getCustomerId();
    pair<std::string, std::string> calculateTravelDates() const;
    vector <shared_ptr<Booking>> getTravelBookings()const;
    void topologicalSort();
    //std::shared_ptr<Digraph<std::shared_ptr<Booking>, 100>> createGraph();
    int findBookingIndex(const std::string& id);
    bool overlap(const std::shared_ptr<Travel>& other) const;
    bool bookingsOverlap(const std::shared_ptr<Booking>& booking1, const std::shared_ptr<Booking>& booking2) const;
    string findStartdatum() const;
    string findEnddatum() const;

    ~Travel();
private:
    long id;
    long customerId;
    //vector<Booking*> travelBookings;
    vector<shared_ptr<Booking>> travelBookings;
    std::shared_ptr<Digraph<std::shared_ptr<Booking>, 100>> travelGraph
     = std::make_shared<Digraph<std::shared_ptr<Booking>, 100>>();

};

#endif // TRAVEL_H
