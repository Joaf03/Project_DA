#ifndef UNTITLED2_WATERRESERVOIR_H
#define UNTITLED2_WATERRESERVOIR_H

#include <string>
#include <vector>

using namespace std;

class WaterReservoir {
private:
    string reservoir;
    string municipality;
    int reservoir_id;
    string code;
    int max_delivery;

public:
    WaterReservoir();
    WaterReservoir(string reservoir, string municipality, int reservoir_id, string code, int max_delivery);

    string getReservoir() const;
    string getMunicipality() const;
    int getReservoirId() const;
    string getCode() const;
    int getMaxDelivery() const;

    void setReservoir(string s);
    void setMunicipality(string m);
    void setReservoirId(int r);
    void setCode(string c);
    void setMaxDelivery(double d);
};


#endif
