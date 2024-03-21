CXX = g++

CXXFLAGS = -std=c++11 -Wall

PYTHIA8_INCLUDE = /usr/include/Pythia8
PYTHIA8_LIB = /usr/include/Pythia8

TARGET = higgs

SRCS = higgs.cpp

OBJS = $(SRCS:.cpp=.o)

LDFLAGS = -L$(PYTHIA8_LIB) -lpythia8 -ldl

INCLUDES = -I$(PYTHIA8_INCLUDE)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(OBJS) -o $(TARGET) $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
