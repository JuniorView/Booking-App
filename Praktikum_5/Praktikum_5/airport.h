#ifndef AIRPORT_H
#define AIRPORT_H
#include <string>

class Airport
{
public:
    Airport(std::string, std::string, std::string, std::string);
    ~Airport();
    std::string getName();
    std::string getIsoCountry();
    std::string getMunicipality();
    std::string getIataCode();



private:
    std::string name;
    std::string isoCountry;
    std::string municipality;
    std::string iataCode;
};

#endif // AIRPORT_H
