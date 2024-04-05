#ifndef UNTITLED2_DATALOADER_H
#define UNTITLED2_DATALOADER_H

#include "WaterReservoir.h"
#include "PumpingStation.h"
#include "DeliverySite.h"
#include "Pipeline.h"

/**
 * @brief The DataLoader class provides methods to load data from files.
 *
 * It includes static methods to load water reservoirs, pumping stations,
 * delivery sites, and pipelines from specified files.
 */
class DataLoader {
public:
    /**
     * @brief Load water reservoirs from a file.
     *
     * Reads data from the specified CSV file and constructs WaterReservoir objects.
     * Each line in the file represents a water reservoir with attributes separated by commas.
     * The format of each line should be: name,municipality,id,code,maxDelivery.
     *
     * @param filename The name of the file to load water reservoir data from.
     * @return A vector of WaterReservoir objects loaded from the file.
     */
    static vector<WaterReservoir> loadWaterReservoirs(const string &filename);

    /**
     * @brief Load pumping stations from a file.
     *
     * Reads data from the specified CSV file and constructs PumpingStation objects.
     * Each line in the file represents a pumping station with attributes separated by commas.
     * The format of each line should be: id,code.
     *
     * @param filename The name of the file to load pumping station data from.
     * @return A vector of PumpingStation objects loaded from the file.
     */
    static vector<PumpingStation> loadPumpingStations(string &filename);

    /**
     * @brief Load delivery sites from a file.
     *
     * Reads data from the specified CSV file and constructs DeliverySite objects.
     * Each line in the file represents a delivery site with attributes separated by commas.
     * The format of each line should be: city,id,code,demand,population.
     *
     * @param filename The name of the file to load delivery site data from.
     * @return A vector of DeliverySite objects loaded from the file.
     */
    static vector<DeliverySite> loadDeliverySites(string &filename);

    /**
     * @brief Load pipelines from a file.
     *
     * Reads data from the specified CSV file and constructs Pipeline objects.
     * Each line in the file represents a pipeline with attributes separated by commas.
     * The format of each line should be: source,target,capacity,direction.
     *
     * @param filename The name of the file to load pipeline data from.
     * @return A vector of Pipeline objects loaded from the file.
     */
    static vector<Pipeline> loadPipelines(string &filename);

};


#endif
