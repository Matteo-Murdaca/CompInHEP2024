#include <iostream>
#include <fstream>
#include "Pythia8/Pythia.h"

using namespace Pythia8;

int main() {
    // Initialize Pythia
    Pythia pythia;
    pythia.readFile("pythia8311/Makefile.inc");

    // Check if initialization was successful
    if (!pythia.init()) {
        std::cerr << "Pythia initialization failed. Aborting." << std::endl;
        return 1;
    }

    // Set up output file
    std::ofstream outfile("muonpt.out");

    // Number of events
    int NEV = 50000;

    // Event loop
    for (int j = 0; j < NEV; ++j) {
        if (!pythia.next()) continue;
        Event& event = pythia.event;

        // Loop over particles in the event
        for (int i = 0; i < event.size(); ++i) {
            // Check if the particle is a muon
            if (event[i].idAbs() == 13) {
                // Write muon's momentum to output file
                outfile << event[i].px() << " "
                        << event[i].py() << " "
                        << event[i].pz() << std::endl;
            }
        }
    }

    // Close output file
    outfile.close();

    // End Pythia
    pythia.stat();

    return 0;
}

