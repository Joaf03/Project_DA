#ifndef PUMPINGSTATION_H
#define PUMPINGSTATION_H

#include <string>
#include <vector>

class PumpingStation {
private:
    int id;
    std::string code;

public:
    PumpingStation();
    PumpingStation(int id, std::string code);

    int getId() const;
    std::string getCode() const;

    void setId(int id);
    void setCode(std::string code);
};

#endif
