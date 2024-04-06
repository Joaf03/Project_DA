#ifndef UNTITLED2_WATERRESERVOIR_H
#define UNTITLED2_WATERRESERVOIR_H

#include <string>
#include <vector>

using namespace std;

/**
 * @brief The WaterReservoir class represents a water reservoir entity.
 *
 * It stores information about a water reservoir, including its name,
 * associated municipality, unique reservoir ID, code, and maximum delivery capacity.
 *
 * Time Complexity:
 * - Accessors (getters): O(1)
 * - Mutators (setters): O(1)
 * - Constructor (default and parameterized): O(1)
 */
class WaterReservoir {
private:
    string reservoir;           /**< Name of the water reservoir. */
    string municipality;        /**< Name of the associated municipality. */
    int reservoir_id;           /**< Unique ID of the reservoir. */
    string code;                /**< Code representing the reservoir. */
    int max_delivery;           /**< Maximum delivery capacity of the reservoir. */

public:
    /**
     * @brief Default constructor for WaterReservoir class.
     *
     * Initializes a WaterReservoir object with default values.
     *
     * Time Complexity: O(1)
     */
    WaterReservoir();

    /**
     * @brief Parameterized constructor for WaterReservoir class.
     *
     * Initializes a WaterReservoir object with the provided values.
     *
     * @param reservoir Name of the water reservoir.
     * @param municipality Name of the associated municipality.
     * @param reservoir_id Unique ID of the reservoir.
     * @param code Code representing the reservoir.
     * @param max_delivery Maximum delivery capacity of the reservoir.
     *
     * Time Complexity: O(1)
     */
    WaterReservoir(string reservoir, string municipality, int reservoir_id, string code, int max_delivery);

    /**
     * @brief Getter function to retrieve the name of the water reservoir.
     *
     * @return The name of the water reservoir.
     *
     * Time Complexity: O(1)
     */
    string getReservoir() const;

    /**
     * @brief Getter function to retrieve the name of the associated municipality.
     *
     * @return The name of the associated municipality.
     *
     * Time Complexity: O(1)
     */
    string getMunicipality() const;

    /**
     * @brief Getter function to retrieve the unique ID of the reservoir.
     *
     * @return The unique ID of the reservoir.
     *
     * Time Complexity: O(1)
     */
    int getReservoirId() const;

    /**
     * @brief Getter function to retrieve the code representing the reservoir.
     *
     * @return The code representing the reservoir.
     *
     * Time Complexity: O(1)
     */
    string getCode() const;

    /**
     * @brief Getter function to retrieve the maximum delivery capacity of the reservoir.
     *
     * @return The maximum delivery capacity of the reservoir.
     *
     * Time Complexity: O(1)
     */
    int getMaxDelivery() const;

    /**
     * @brief Setter function to set the name of the water reservoir.
     *
     * @param n The name of the water reservoir.
     *
     * Time Complexity: O(1)
     */
    void setReservoir(string n);

    /**
     * @brief Setter function to set the name of the associated municipality.
     *
     * @param m The name of the associated municipality.
     *
     * Time Complexity: O(1)
     */
    void setMunicipality(string m);

    /**
     * @brief Setter function to set the unique ID of the reservoir.
     *
     * @param r The unique ID of the reservoir.
     *
     * Time Complexity: O(1)
     */
    void setReservoirId(int r);

    /**
     * @brief Setter function to set the code representing the reservoir.
     *
     * @param c The code representing the reservoir.
     *
     * Time Complexity: O(1)
     */
    void setCode(string c);

    /**
     * @brief Setter function to set the maximum delivery capacity of the reservoir.
     *
     * @param d The maximum delivery capacity of the reservoir.
     *
     * Time Complexity: O(1)
     */
    void setMaxDelivery(double d);
};



#endif
