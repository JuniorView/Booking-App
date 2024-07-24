#ifndef CHECK_H
#define CHECK_H
#include "travelagency.h"
#include <stack>

class Check
{
public:
    Check(shared_ptr<TravelAgency> travelagency);
   // void topologicalSort(std::shared_ptr<Digraph<std::shared_ptr<Booking>, 100>> graph, int v, std::stack<std::shared_ptr<Booking>>& sortedBookings, std::vector<bool>& visited);
    void checkTravelsDisjunct(IncorrectReservation &info);
    bool travelsOverlap(const shared_ptr<Travel> &travel, const shared_ptr<Travel> &travel2);
    bool dateOverlap(const string& startDate1, const string& endDate1,
                         const string& startDate2, const string& endDate2);

    void checkNoMissingHotels(IncorrectReservation &info);
    void checkNoOverlappingHotels(IncorrectReservation &info);
    void checkNoOverlappingRentalCars(IncorrectReservation &info);


    void operator()();

private:


     shared_ptr<TravelAgency> travelagency;
};

#endif // CHECK_H
