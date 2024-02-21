#include <iostream>
#include <TFile.h>
#include <TTree.h>
#include <TH1F.h>
#include <TCanvas.h>
#include <TStyle.h>
#include <TF1.h>

void plot_data() {
    TFile file("random_numbers.root");

    TTree *tree = (TTree*)file.Get("random_tree");

    TH1F *hist = new TH1F("hist", "Random Numbers;Value;Frequency", 100, -5, 5);

    tree->Draw("number>>hist");

    TCanvas *canvas = new TCanvas("canvas", "Random Numbers", 800, 600);
    canvas->SetFillColor(0); 

    hist->SetLineColor(kBlack); 
    hist->SetLineWidth(2); 
    hist->SetFillColor(kYellow); 
    hist->Draw(); 

    hist->GetXaxis()->SetTitle("Value");
    hist->GetYaxis()->SetTitle("Frequency");

    TF1 *fit = new TF1("fit", "gaus", -5, 5);
    hist->Fit("fit");

    canvas->Update();

    canvas->SaveAs("random_numbers_plot.png");

    file.Close();
}

int main() {
    plot_data();
    return 0;
}
