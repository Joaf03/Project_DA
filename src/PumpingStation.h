#ifndef PUMPINGSTATION_H
#define PUMPINGSTATION_H

using namespace std;
#include <string>
#include <vector>

/**
 * @brief The PumpingStation class represents a pumping station entity.
 *
 * It stores information about a pumping station, including its unique ID and code.
 *
 * Time Complexity:
 * - Accessors (getters): O(1)
 * - Mutators (setters): O(1)
 * - Constructor (default and parameterized): O(1)
 */
class PumpingStation {
private:
    int id;             /**< Unique ID of the pumping station. */
    string code;        /**< Code representing the pumping station. */

public:
    /**
     * @brief Default constructor for PumpingStation class.
     *
     * Initializes a PumpingStation object with default values.
     *
     * Time Complexity: O(1)
     */
    PumpingStation();

    /**
     * @brief Parameterized constructor for PumpingStation class.
     *
     * Initializes a PumpingStation object with the provided values.
     *
     * @param id Unique ID of the pumping station.
     * @param code Code representing the pumping station.
     *
     * Time Complexity: O(1)
     */
    PumpingStation(int id, string code);

    /**
     * @brief Getter function to retrieve the unique ID of the pumping station.
     *
     * @return The unique ID of the pumping station.
     *
     * Time Complexity: O(1)
     */
    int getId() const;

    /**
     * @brief Getter function to retrieve the code representing the pumping station.
     *
     * @return The code representing the pumping station.
     *
     * Time Complexity: O(1)
     */
    string getCode() const;

    /**
     * @brief Setter function to set the unique ID of the pumping station.
     *
     * @param id The unique ID of the pumping station.
     *
     * Time Complexity: O(1)
     */
    void setId(int id);

    /**
     * @brief Setter function to set the code representing the pumping station.
     *
     * @param code The code representing the pumping station.
     *
     * Time Complexity: O(1)
     */
    void setCode(string code);
};


#endif
