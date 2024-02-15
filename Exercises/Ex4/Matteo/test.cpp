#include <iostream>
#include "Track.hpp"
#include "SimulatedParticle.hpp"

int main() {
    // Create a reconstructed track
    Track reconstructed_track(10, 20, 30, 40);
    std::cout << "Reconstructed Track:" << std::endl;
    std::cout << "Momentum: (" << std::get<0>(reconstructed_track.get_momentum()) << ", "
              << std::get<1>(reconstructed_track.get_momentum()) << ", "
              << std::get<2>(reconstructed_track.get_momentum()) << ")" << std::endl;
    std::cout << "Energy: " << reconstructed_track.get_energy() << std::endl;
    std::cout << "Transverse Momentum: " << reconstructed_track.get_transverse_momentum() << std::endl;
    std::cout << "Pseudorapidity: " << reconstructed_track.get_pseudorapidity() << std::endl;

    std::cout << std::endl;

    // Create a simulated particle
    SimulatedParticle simulated_particle(15, 25, 35, 45, 1, 0);
    std::cout << "Simulated Particle:" << std::endl;
    std::cout << "Momentum: (" << std::get<0>(simulated_particle.get_momentum()) << ", "
              << std::get<1>(simulated_particle.get_momentum()) << ", "
              << std::get<2>(simulated_particle.get_momentum()) << ")" << std::endl;
    std::cout << "Energy: " << simulated_particle.get_energy() << std::endl;
    std::cout << "Transverse Momentum: " << simulated_particle.get_transverse_momentum() << std::endl;
    std::cout << "Pseudorapidity: " << simulated_particle.get_pseudorapidity() << std::endl;
    std::cout << "Particle ID: " << simulated_particle.get_particle_id() << std::endl;
    std::cout << "Parent Particle ID: " << simulated_particle.get_parent_particle_id() << std::endl;

    return 0;
}
