#ifndef DELIVERYSITE_H
#define DELIVERYSITE_H

#include <string>
using namespace std;

class DeliverySite {
private:
    string city;
    int id;
    string code;
    double demand;
    double population;

public:
    DeliverySite();
    DeliverySite(string city, int id, string code, double demand, double population);

    string getCity() const;
    int getId() const;
    string getCode() const;
    double getDemand() const;
    double getPopulation() const;

    void setCity(string city);
    void setId(int id);
    void setCode(string code);
    void setDemand(double demand);
    void setPopulation(int population);
};

#endif
