#include "customer.h"

Customer::Customer(long id,string firstName,string lastName):
id(id),firstName(firstName),lastName(lastName){

}
void Customer::addTravel(shared_ptr<Travel>travel){
   travelList.push_back(travel);
};

long Customer::getId(){
    return id;
}

vector <shared_ptr<Travel>> Customer::getTravelList(){
    return travelList;
}

string Customer::getFirstName(){
    return firstName;
};
string Customer::getLastName(){
    return lastName;
}

shared_ptr<Travel> Customer::findTravel_2(long id)
{
    for (auto travel : travelList){
        if (travel->getId() == id )
            return travel;
    }
    return 0;
};

Customer:: ~Customer(){
//    for(auto i : travelList){
//        delete i;
//    }
};
