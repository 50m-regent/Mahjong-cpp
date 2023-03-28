TARGET   = test
SOURCE   = constants/tile.cpp constants/wind.cpp game.cpp test.cpp
OBJECT   = tile.o wind.o game.o test.o
INCLUDE  = -I/Users/len/Documents/Mahjong-cpp
FLAGS    = --std=c++20

$(TARGET): $(OBJECT)
	g++ -o $@ $^
	-rm -f $(OBJECT)

$(OBJECT): $(SOURCE)
	g++ $(FLAGS) $(INCLUDE) -c $(SOURCE)