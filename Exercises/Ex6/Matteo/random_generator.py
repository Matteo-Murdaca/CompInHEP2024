import ROOT

def random_generator():
    rng = ROOT.TRandom3(0)

    file = ROOT.TFile("random_numbers.root", "RECREATE")

    tree = ROOT.TTree("random_tree", "Tree with random numbers")

    number = ROOT.std.vector('float')()
    tree.Branch("number", number)

    N = 1000
    for i in range(N):
        num = rng.Gaus(0, 1)
        number.push_back(num)

    tree.Fill()

    tree.Write()

    file.Close()

if __name__ == "__main__":
    random_generator()
