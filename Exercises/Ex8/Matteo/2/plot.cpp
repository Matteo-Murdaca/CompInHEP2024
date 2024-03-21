#include <iostream>
#include <fstream>
#include "TH1D.h"
#include "TF1.h"
#include "TCanvas.h"
#include "TMath.h"
#include "TStyle.h"

using namespace std;

Double_t breit_wigner(Double_t *x, Double_t *par) {
  return par[0] * par[2] / (2.0 * TMath::Pi() * ((x[0] - par[1]) * (x[0] - par[1]) + par[2] * par[2] / 4.0));
}

int main() {
  ifstream inFile("mass.out");
  if (!inFile) {
    cout << "Cannot open file mass.out" << endl;
    return 1;
  }

  TH1D* histo = new TH1D("histo", "", 200, 124.98, 125.02);

  double mass;
  while (inFile >> mass) {
    histo->Fill(mass);
  }

  TCanvas* canvas = new TCanvas("canvas", "", 700, 400);
  canvas->SetFillColor(0);

  gStyle->SetOptFit();
  histo->SetFillColor(5);
  histo->GetXaxis()->SetTitle("m_{H} (GeV/c^{2})");
  histo->GetYaxis()->SetTitle("Arbitrary units");
  histo->Draw();

  Double_t fitRangeMin = 124.995;
  Double_t fitRangeMax = 125.005;
  const int nPar = 3;
  TF1* theFit = new TF1("theFit", breit_wigner, fitRangeMin, fitRangeMax, nPar);

  theFit->SetParameter(0, 0.001);
  theFit->SetParameter(1, 125);
  theFit->SetParameter(2, 0.001);

  histo->Fit("theFit", "R0");
  theFit->DrawClone("same");

  cout << "Width = " << theFit->GetParameter(2) << endl;

  return 0;
}
