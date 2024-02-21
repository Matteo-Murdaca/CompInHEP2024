#include <iostream>
#include <TRandom3.h>
#include <TFile.h>
#include <TTree.h>

void random_generator() {
    TRandom3 rng(0);

    TFile file("random_numbers.root", "RECREATE");

    TTree tree("random_tree", "Tree with random numbers");

    float number;

    tree.Branch("number", &number);

    const int N = 1000;
    for (int i = 0; i < N; ++i) {
        number = rng.Gaus(0, 1); 
        tree.Fill();
    }

    tree.Write();

    file.Close();
}

int main() {
    random_generator();
    return 0;
}
