#include "TwoDMeasurement.hpp"

// Constructor
TwoDMeasurement::TwoDMeasurement(double x_, double y_, double sigma_xx_, double sigma_xy_, double sigma_yy_)
    : x(x_), y(y_), sigma_xx(sigma_xx_), sigma_xy(sigma_xy_), sigma_yy(sigma_yy_) {}

// Member functions
double TwoDMeasurement::getX() const { return x; }

double TwoDMeasurement::getY() const { return y; }

std::tuple<double, double, double, double> TwoDMeasurement::getErrorMatrix() const {
    return std::make_tuple(sigma_xx, sigma_xy, sigma_xy, sigma_yy);
}

double TwoDMeasurement::getDistance() const {
    return std::sqrt(x * x + y * y);
}

double TwoDMeasurement::getDistanceError() const {
    double dx_dr = x / getDistance();
    double dy_dr = y / getDistance();
    double dr_dxx = dx_dr * x;
    double dr_dxy = dx_dr * y;
    double dr_dyy = dy_dr * y;
    double error = std::sqrt(dr_dxx * dr_dxx * sigma_xx + dr_dxy * dr_dxy * sigma_yy + dr_dyy * dr_dyy * sigma_yy);
    return error;
}

double TwoDMeasurement::getSignificance() const {
    return getDistance() / getDistanceError();
}
