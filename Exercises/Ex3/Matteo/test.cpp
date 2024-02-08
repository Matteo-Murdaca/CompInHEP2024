#include "TwoDMeasurement.hpp"
#include <iostream>

int main() {
    TwoDMeasurement measurement(3.0, 4.0, 0.1, 0.05, 0.1);

    std::cout << "X coordinate: " << measurement.getX() << std::endl;
    std::cout << "Y coordinate: " << measurement.getY() << std::endl;

    auto errorMatrix = measurement.getErrorMatrix();
    std::cout << "Error matrix (sigma_xx, sigma_xy, sigma_xy, sigma_yy): "
              << std::get<0>(errorMatrix) << ", "
              << std::get<1>(errorMatrix) << ", "
              << std::get<2>(errorMatrix) << ", "
              << std::get<3>(errorMatrix) << std::endl;

    std::cout << "Distance: " << measurement.getDistance() << std::endl;
    std::cout << "Distance error: " << measurement.getDistanceError() << std::endl;
    std::cout << "Significance: " << measurement.getSignificance() << std::endl;

    return 0;
}
