#ifndef TWODMEASUREMENT_HPP
#define TWODMEASUREMENT_HPP

#include <cmath>
#include <tuple>

class TwoDMeasurement {
private:
    double x, y;
    double sigma_xx, sigma_xy, sigma_yy;

public:
    // Constructor
    TwoDMeasurement(double x_, double y_, double sigma_xx_, double sigma_xy_, double sigma_yy_);

    // Member functions
    double getX() const;
    double getY() const;
    std::tuple<double, double, double, double> getErrorMatrix() const;
    double getDistance() const;
    double getDistanceError() const;
    double getSignificance() const;
};

#endif // TWODMEASUREMENT_HPP