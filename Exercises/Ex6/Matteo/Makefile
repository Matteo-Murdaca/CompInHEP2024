CC=g++
CFLAGS=-Wall -Wextra -std=c++11
ROOTLIBS=`root-config --cflags --libs`

all: random_generator plot_data plot

random_generator: random_generator.cpp
	$(CC) $(CFLAGS) random_generator.cpp -o random_generator $(ROOTLIBS)

plot_data: plot_data.cpp
	$(CC) $(CFLAGS) plot_data.cpp -o plot_data $(ROOTLIBS)

plot: random_generator plot_data
	./random_generator
	./plot_data

clean:
	rm -f random_generator plot_data random_numbers.root random_numbers_plot.png
