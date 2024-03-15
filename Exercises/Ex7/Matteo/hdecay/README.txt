hdecay:

After downloading and extracting hdecay.tar.gz, I modified hdecay.in .
I set the following variables:
MABEG    = 124.5D0
MAEND    = 125.5D0
NMA      = 11
By doing so, I obtained 11 values for the Higgs boson width and mass of which the middle one corresponds to 125GeV.
After executing the code for which a lot of trouble shooting and a virtual machine were needed, I got the values of the masses and width in the file br.sm2 .
I extracted the obtained values and inserted them in the c++ file plotHiggsWidth.cpp and used ROOT to plot them.
I highlighted the value of the 125GeV mass and added a lable with the width value.
