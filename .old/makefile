TARGET   = test
SOURCE   = test.cpp types/paiset.cpp types/shoupai.cpp
OBJECT   = test.o paiset.o shoupai.o
INCLUDE  = -I/Users/len/Documents/MahjongAIBattle
FLAGS    = --std=c++20

$(TARGET): $(OBJECT)
	g++ -o $@ $^
	-rm -f $(OBJECT)

$(OBJECT): $(SOURCE)
	g++ $(FLAGS) $(INCLUDE) -c $(SOURCE)