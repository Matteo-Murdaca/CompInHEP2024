#ifndef SIMULATEDPARTICLE_HPP
#define SIMULATEDPARTICLE_HPP

#include "Track.hpp"

class SimulatedParticle {
private:
    class SimulatedParticleImpl;
    std::unique_ptr<SimulatedParticleImpl> impl;

public:
    SimulatedParticle(double px, double py, double pz, double energy, int particle_id, int parent_particle_id);
    ~SimulatedParticle();
    std::tuple<double, double, double> get_momentum() const;
    double get_energy() const;
    double get_transverse_momentum() const;
    double get_pseudorapidity() const;
    int get_particle_id() const;
    int get_parent_particle_id() const;
};

#endif // SIMULATEDPARTICLE_HPP
