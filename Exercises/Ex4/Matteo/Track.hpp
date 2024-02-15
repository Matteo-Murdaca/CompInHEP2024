#ifndef TRACK_HPP
#define TRACK_HPP

#include <memory>
#include <tuple>
#include <cmath>

class Track {
private:
    class TrackImpl;
    std::unique_ptr<TrackImpl> impl;

public:
    Track(double px, double py, double pz, double energy);
    ~Track();
    std::tuple<double, double, double> get_momentum() const;
    double get_energy() const;
    double get_transverse_momentum() const;
    double get_pseudorapidity() const;
};

#endif // TRACK_HPP

