#include "Track.hpp"

class Track::TrackImpl {
public:
    double px, py, pz, energy;
    TrackImpl(double px, double py, double pz, double energy)
        : px(px), py(py), pz(pz), energy(energy) {}
};

Track::Track(double px, double py, double pz, double energy)
    : impl(std::make_unique<TrackImpl>(px, py, pz, energy)) {}

Track::~Track() = default;

std::tuple<double, double, double> Track::get_momentum() const {
    return std::make_tuple(impl->px, impl->py, impl->pz);
}

double Track::get_energy() const {
    return impl->energy;
}

double Track::get_transverse_momentum() const {
    return std::sqrt(impl->px * impl->px + impl->py * impl->py);
}

double Track::get_pseudorapidity() const {
    double theta = std::atan2(std::sqrt(impl->px * impl->px + impl->py * impl->py), impl->pz);
    return -std::log(std::tan(theta / 2));
}
