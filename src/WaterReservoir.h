#ifndef UNTITLED2_WATERRESERVOIR_H
#define UNTITLED2_WATERRESERVOIR_H

#include <string>
#include <vector>

using namespace std;

class WaterReservoir {
private:
    std::string name;
    std::string municipality;
    int reservoir_id;
    std::string code;
    double max_delivery;

public:
    WaterReservoir();
    WaterReservoir(string name, string municipality, int reservoir_id, string code, double max_delivery);

    string getName() const;
    string getMunicipality() const;
    int getReservoirId() const;
    string getCode() const;
    double getMaxDelivery() const;

    void setName(string s);
    void setMunicipality(string m);
    void setReservoirId(int r);
    void setCode(string c);
    void setMaxDelivery(double d);
};


#endif
