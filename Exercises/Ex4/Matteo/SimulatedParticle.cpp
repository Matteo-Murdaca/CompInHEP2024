#include "SimulatedParticle.hpp"

class SimulatedParticle::SimulatedParticleImpl {
public:
    double px, py, pz, energy;
    int particle_id, parent_particle_id;
    SimulatedParticleImpl(double px, double py, double pz, double energy, int particle_id, int parent_particle_id)
        : px(px), py(py), pz(pz), energy(energy), particle_id(particle_id), parent_particle_id(parent_particle_id) {}
};

SimulatedParticle::SimulatedParticle(double px, double py, double pz, double energy, int particle_id, int parent_particle_id)
    : impl(std::make_unique<SimulatedParticleImpl>(px, py, pz, energy, particle_id, parent_particle_id)) {}

SimulatedParticle::~SimulatedParticle() = default;

std::tuple<double, double, double> SimulatedParticle::get_momentum() const {
    return std::make_tuple(impl->px, impl->py, impl->pz);
}

double SimulatedParticle::get_energy() const {
    return impl->energy;
}

double SimulatedParticle::get_transverse_momentum() const {
    return std::sqrt(impl->px * impl->px + impl->py * impl->py);
}

double SimulatedParticle::get_pseudorapidity() const {
    double theta = std::atan2(std::sqrt(impl->px * impl->px + impl->py * impl->py), impl->pz);
    return -std::log(std::tan(theta / 2));
}

int SimulatedParticle::get_particle_id() const {
    return impl->particle_id;
}

int SimulatedParticle::get_parent_particle_id() const {
    return impl->parent_particle_id;
}

