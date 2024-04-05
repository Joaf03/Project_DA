#include "menu.h"
#include <iostream>

using namespace std;

void menu::Menu() {
    cout << endl;
    cout << "------------------------------------- Service Metrics of the water supply network  -------------------------------------" << endl;
    cout << endl;
    cout << "                 " << 1 << "- Maximum amount of water that can reach a city;" << endl;
    cout << "                 " << 2 << "- Verify if all delivery sites get enough water;" << endl;
    cout << "                 " << 3 << "- Balance the load across the network;" << endl;
    cout << endl;
    cout << "------------------------------------------ Reliability and Sensitivity to Failures -------------------------------------" << endl;
    cout << endl;
    cout << "                 " << 4 << "- What appends if a specific water reservoir is out of commission?" << endl;
    cout << "                 " << 5 << "- Can any pumping station be temporarily taken out of service?" << endl;
    cout << "                 " << 6 << "- Which cities are affected by a pipeline rupture?" << endl;
    cout << endl;
    cout << "                 " << "Press 0 to quit." << endl;
    cout << endl;
    cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
    cout << endl;
}
