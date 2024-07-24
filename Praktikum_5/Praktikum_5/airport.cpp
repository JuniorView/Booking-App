#include "airport.h"

Airport::Airport(std::string name, std::string isoCountry, std::string municipality, std::string iataCode):
    name(name), isoCountry(isoCountry), municipality(municipality), iataCode(iataCode)
{

}


std::string Airport::getName(){
    return name;
}

std::string Airport::getIsoCountry(){
    return isoCountry;
}

std::string Airport::getMunicipality(){
    return municipality;
}

std::string Airport::getIataCode(){
    return iataCode;
}
Airport::~Airport(){

};
