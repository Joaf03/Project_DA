#ifndef PUMPINGSTATION_H
#define PUMPINGSTATION_H

using namespace std;
#include <string>
#include <vector>

class PumpingStation {
private:
    int id;
    string code;

public:
    PumpingStation();
    PumpingStation(int id, string code);

    int getId() const;
    string getCode() const;

    void setId(int id);
    void setCode(string code);
};

#endif
