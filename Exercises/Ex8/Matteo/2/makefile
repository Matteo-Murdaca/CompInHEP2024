CXX = g++

CXXFLAGS = -std=c++11 -Wall

PYTHIA8_INCLUDE = /usr/include/Pythia8

PYTHIA8_LIB = /usr/lib

LHAPDF_INCLUDE = /usr/include/LHAPDF

LHAPDF_LIB = /usr/share/lhapdf/LHAPDF

TARGET = higgs

SRCS = higgs.cpp

OBJS = $(SRCS:.cpp=.o)

LDFLAGS = -L$(PYTHIA8_LIB) -lpythia8 -ldl

INCLUDES = -I$(PYTHIA8_INCLUDE)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(TARGET) $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

plot.o: plot.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c plot.cpp -o plot.o

plot: plot.o higgs.o
	$(CXX) $(CXXFLAGS) plot.o higgs.o -o plot $(LDFLAGS)

clean:
	rm -f $(OBJS) $(TARGET) plot.o plot
