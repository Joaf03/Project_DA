#ifndef PIPELINE_H
#define PIPELINE_H

#include <string>
using namespace std;

class Pipeline {
private:
    string source;
    string target;
    double capacity;
    bool is_bidirectional;

public:
    Pipeline();
    Pipeline(string source, std::string target, double capacity, bool is_bidirectional);

    std::string getSource() const;
    std::string getTarget() const;
    double getCapacity() const;
    bool isBidirectional() const;

    void setSource(string source);
    void setTarget(string target);
    void setCapacity(double capacity);
    void setBidirectional(bool is_bidirectional);
};

#endif
