#ifndef DELIVERYSITE_H
#define DELIVERYSITE_H

#include <string>
using namespace std;

/**
 * @brief The DeliverySite class represents a delivery site for water distribution.
 *
 * It stores information about a delivery site, including its city, ID, code, demand, and population.
 *
 * Time Complexity:
 * - Accessors (getters): O(1)
 * - Mutators (setters): O(1)
 * - Constructor (default and parameterized): O(1)
 */
class DeliverySite {
private:
    string city;        /**< City where the delivery site is located. */
    int id;             /**< ID of the delivery site. */
    string code;        /**< Code identifying the delivery site. */
    double demand;      /**< Demand for water at the delivery site. */
    double population;  /**< Population served by the delivery site. */

public:
    /**
     * @brief Default constructor for DeliverySite class.
     *
     * Initializes a DeliverySite object with default values.
     *
     * Time Complexity: O(1)
     */
    DeliverySite();

    /**
     * @brief Parameterized constructor for DeliverySite class.
     *
     * Initializes a DeliverySite object with the provided values.
     *
     * @param city City where the delivery site is located.
     * @param id ID of the delivery site.
     * @param code Code identifying the delivery site.
     * @param demand Demand for water at the delivery site.
     * @param population Population served by the delivery site.
     *
     * Time Complexity: O(1)
     */
    DeliverySite(string city, int id, string code, double demand, double population);

    /**
     * @brief Getter function to retrieve the city of the delivery site.
     *
     * @return The city of the delivery site.
     *
     * Time Complexity: O(1)
     */
    string getCity() const;

    /**
     * @brief Getter function to retrieve the ID of the delivery site.
     *
     * @return The ID of the delivery site.
     *
     * Time Complexity: O(1)
     */
    int getId() const;

    /**
     * @brief Getter function to retrieve the code of the delivery site.
     *
     * @return The code of the delivery site.
     *
     * Time Complexity: O(1)
     */
    string getCode() const;

    /**
     * @brief Getter function to retrieve the demand for water at the delivery site.
     *
     * @return The demand for water at the delivery site.
     *
     * Time Complexity: O(1)
     */
    double getDemand() const;

    /**
     * @brief Getter function to retrieve the population served by the delivery site.
     *
     * @return The population served by the delivery site.
     *
     * Time Complexity: O(1)
     */
    double getPopulation() const;

    /**
     * @brief Setter function to set the city of the delivery site.
     *
     * @param city The city of the delivery site.
     *
     * Time Complexity: O(1)
     */
    void setCity(string city);

    /**
     * @brief Setter function to set the ID of the delivery site.
     *
     * @param id The ID of the delivery site.
     *
     * Time Complexity: O(1)
     */
    void setId(int id);

    /**
     * @brief Setter function to set the code of the delivery site.
     *
     * @param code The code of the delivery site.
     *
     * Time Complexity: O(1)
     */
    void setCode(string code);

    /**
     * @brief Setter function to set the demand for water at the delivery site.
     *
     * @param demand The demand for water at the delivery site.
     *
     * Time Complexity: O(1)
     */
    void setDemand(double demand);

    /**
     * @brief Setter function to set the population served by the delivery site.
     *
     * @param population The population served by the delivery site.
     *
     * Time Complexity: O(1)
     */
    void setPopulation(int population);
};


#endif
