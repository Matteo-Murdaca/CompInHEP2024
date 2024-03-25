PYTHIA8_URL = https://pythia.org/download/pythia83/pythia8311.tgz
PYTHIA8_TGZ = $(notdir $(PYTHIA8_URL))
PYTHIA8_DIR = $(basename $(PYTHIA8_TGZ))

SRC = $(wildcard *.cc)
OBJS = $(addsuffix .o,$(basename $(SRC)))

OPT = -g -Wall
INC = -I$(PYTHIA8_DIR)/include
LIBS = -L$(PYTHIA8_DIR)/lib -lpythia8 -ldl

.cxx.o:
	$(CXX) $(OPT) $(INC) -c -o $@ $<

main: $(OBJS)
	$(CXX) $(OPT) $(INC) $(OBJS) $(LIBS) -o main

clean:
	rm -rf $(OBJS) main
