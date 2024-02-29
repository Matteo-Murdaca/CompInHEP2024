import ROOT

def plot_data():
    file = ROOT.TFile("random_numbers.root")

    tree = file.Get("random_tree")

    hist = ROOT.TH1F("hist", "Random Numbers;Value;Frequency", 100, -5, 5)

    tree.Draw("number>>hist")

    canvas = ROOT.TCanvas("canvas", "Random Numbers", 800, 600)
    canvas.SetFillColor(0)

    hist.SetLineColor(ROOT.kBlack)
    hist.SetLineWidth(2)
    hist.SetFillColor(ROOT.kYellow)
    hist.Draw()

    hist.GetXaxis().SetTitle("Value")
    hist.GetYaxis().SetTitle("Frequency")

    fit = ROOT.TF1("fit", "gaus", -5, 5)
    hist.Fit("fit")

    canvas.Update()

    canvas.SaveAs("random_numbers_plot.png")

    file.Close()

if __name__ == "__main__":
    plot_data()
