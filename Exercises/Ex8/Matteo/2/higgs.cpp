#include <iostream>
#include "Pythia8/Pythia.h"

using namespace Pythia8;

int main() {
    Pythia pythia;

    double mH = 125.0;

    pythia.readString("PDF:useHard = on");
    pythia.readString("PDF:useHard = on");
    pythia.readString("PDF:pSet = cteq6l1");

    pythia.readString("HiggsSM:all = on");
    pythia.readString("25:m0 = " + std::to_string(mH));

    pythia.init();

    std::ofstream outFile("mass.out");

    for (int iEvent = 0; iEvent < 1000; ++iEvent) {
        if (!pythia.next()) continue;

        for (int i = 0; i < pythia.event.size(); ++i) {
            if (pythia.event[i].id() == 25) {
                outFile << pythia.event[i].m() << std::endl;
            }
        }
    }

    outFile.close();

    pythia.stat();

    return 0;
}
