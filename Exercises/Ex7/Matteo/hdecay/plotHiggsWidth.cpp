#include "TCanvas.h"
#include "TGraph.h"
#include "TLegend.h"
#include "TLatex.h"

void plotHiggsWidth() {
    //masses extracted from br.sm2
    double masses[] = {124.500, 124.600, 124.700, 124.800, 124.900, 125.000, 125.100, 125.200, 125.300, 125.400, 125.500};
    double widths[] = {0.4011, 0.4024, 0.4037, 0.4050, 0.4064, 0.4077, 0.4091, 0.4105, 0.4119, 0.4133, 0.4147};

    double higgsMass = 125.0;
    double interpolatedWidth = 0.4077;

    int nPoints = sizeof(masses)/sizeof(masses[0]);
    TGraph *graph = new TGraph(nPoints, masses, widths);

    TCanvas *canvas = new TCanvas("canvas", "Higgs Width", 800, 600);

    graph->SetTitle("SM Higgs Boson Width; Higgs Mass (GeV); Width (GeV)");
    graph->SetMarkerStyle(20);
    graph->SetMarkerSize(1.5);
    graph->SetLineWidth(2);
    graph->Draw("APL");

    TGraph *highlightPoint = new TGraph(1, &higgsMass, &interpolatedWidth);
    highlightPoint->SetMarkerStyle(20);
    highlightPoint->SetMarkerSize(1.5);
    highlightPoint->SetMarkerColor(kRed);
    highlightPoint->Draw("P");

    TLatex latex;
    latex.SetTextSize(0.04);
    latex.SetTextAlign(22);
    latex.SetTextColor(kRed);
    latex.DrawLatex(higgsMass + 0.09, interpolatedWidth, Form("%.4f", interpolatedWidth));

    latex.SetTextSize(0.03);
    latex.SetTextAlign(22);
    latex.DrawLatex(higgsMass + 0.19, interpolatedWidth, "GeV");

    TLegend *legend = new TLegend(0.6, 0.7, 0.9, 0.9);
    legend->AddEntry(graph, "Width vs Mass", "l");
    legend->AddEntry(highlightPoint, "m_H = 125 GeV", "p");
    legend->Draw();

    canvas->SaveAs("Higgs_Width_Plot.png");
}
