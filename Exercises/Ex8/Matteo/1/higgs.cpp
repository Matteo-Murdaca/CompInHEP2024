#include <iostream>
#include "Pythia8/Pythia.h"

using namespace Pythia8;

int main() {
    Pythia pythia;

    pythia.init();

    pythia.stat();

    double higgsWidth = pythia.particleData.mWidth(25);

    std::cout << "SM Higgs boson width = " << higgsWidth << " GeV" << std::endl;

    pythia.stat();

    return 0;
}
