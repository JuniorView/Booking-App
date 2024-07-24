#ifndef CUSTOMER_H
#define CUSTOMER_H
#include "travel.h"
class Customer
{
public:
    Customer(long id,string firstName,string lastName);

    //void addTravel(Travel* travel);
    void addTravel(shared_ptr<Travel>);
    long getId();
    string getFirstName();
    string getLastName();
    shared_ptr<Travel>findTravel_2(long id);
    //vector <Travel*> getTravelList();
    vector <shared_ptr<Travel>> getTravelList();
    ~Customer();
private:
    long id;
    string firstName;
    string lastName;
    //vector<Travel*> travelList;
    vector<shared_ptr<Travel>>travelList;
};

#endif // CUSTOMER_H
