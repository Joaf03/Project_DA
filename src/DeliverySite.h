#ifndef DELIVERYSITE_H
#define DELIVERYSITE_H

#include <string>
using namespace std;

class DeliverySite {
private:
    string city;
    int id;
    std::string code;
    double demand;
    int population;

public:
    DeliverySite();
    DeliverySite(string city, int id, std::string code, double demand, int population);

    string getCity() const;
    int getId() const;
    std::string getCode() const;
    double getDemand() const;
    int getPopulation() const;

    void setCity(string city) const;
    void setId(int id);
    void setCode(std::string code);
    void setDemand(double demand);
    void setPopulation(int population);
};

#endif
