#ifndef PIPELINE_H
#define PIPELINE_H

#include <string>
using namespace std;

/**
 * @brief The Pipeline class represents a pipeline entity for water transport.
 *
 * It stores information about a pipeline, including its source, target, capacity,
 * and whether it is bidirectional or not.
 *
 * Time Complexity:
 * - Accessors (getters): O(1)
 * - Mutators (setters): O(1)
 * - Constructor (default and parameterized): O(1)
 */
class Pipeline {
private:
    string source;          /**< Source of the pipeline. */
    string target;          /**< Target of the pipeline. */
    double capacity;        /**< Capacity of the pipeline. */
    bool is_bidirectional;  /**< Flag indicating whether the pipeline is bidirectional. */
    double flow;            /**< Flow of the pipeline. */

public:
    /**
     * @brief Default constructor for Pipeline class.
     *
     * Initializes a Pipeline object with default values.
     *
     * Time Complexity: O(1)
     */
    Pipeline();

    /**
     * @brief Parameterized constructor for Pipeline class.
     *
     * Initializes a Pipeline object with the provided values.
     *
     * @param source Source of the pipeline.
     * @param target Target of the pipeline.
     * @param capacity Capacity of the pipeline.
     * @param is_bidirectional Flag indicating whether the pipeline is bidirectional.
     *
     * Time Complexity: O(1)
     */
    Pipeline(string source, std::string target, double capacity, bool is_bidirectional);

    /**
     * @brief Getter function to retrieve the source of the pipeline.
     *
     * @return The source of the pipeline.
     *
     * Time Complexity: O(1)
     */
    std::string getSource() const;

    /**
     * @brief Getter function to retrieve the target of the pipeline.
     *
     * @return The target of the pipeline.
     *
     * Time Complexity: O(1)
     */
    std::string getTarget() const;

    /**
     * @brief Getter function to retrieve the capacity of the pipeline.
     *
     * @return The capacity of the pipeline.
     *
     * Time Complexity: O(1)
     */
    double getCapacity() const;

    /**
     * @brief Getter function to retrieve the flow of the pipeline.
     *
     * @return The flow of the pipeline.
     *
     * Time Complexity: O(1)
     */
    double getFlow() const;

    /**
     * @brief Getter function to check if the pipeline is bidirectional.
     *
     * @return True if the pipeline is bidirectional, false otherwise.
     *
     * Time Complexity: O(1)
     */
    bool isBidirectional() const;

    /**
     * @brief Setter function to set the source of the pipeline.
     *
     * @param source The source of the pipeline.
     *
     * Time Complexity: O(1)
     */
    void setSource(string source);

    /**
     * @brief Setter function to set the target of the pipeline.
     *
     * @param target The target of the pipeline.
     *
     * Time Complexity: O(1)
     */
    void setTarget(string target);

    /**
     * @brief Setter function to set the capacity of the pipeline.
     *
     * @param capacity The capacity of the pipeline.
     *
     * Time Complexity: O(1)
     */
    void setCapacity(double capacity);

    /**
     * @brief Setter function to set whether the pipeline is bidirectional or not.
     *
     * @param is_bidirectional Flag indicating whether the pipeline is bidirectional.
     *
     * Time Complexity: O(1)
     */
    void setBidirectional(bool is_bidirectional);

    /**
     * @brief Setter function to set the flow of the pipeline.
     *
     * @param flow The flow of the pipeline.
     *
     * Time Complexity: O(1)
     */
    void setFlow(double flow);
};


#endif
