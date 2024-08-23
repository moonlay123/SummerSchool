FLAGS=-Wshadow -Winit-self -Wredundant-decls -Wcast-align -Wundef -Wfloat-equal -Winline -Wunreachable-code -Wmissing-declarations -Wmissing-include-dirs -Wswitch-enum -Wswitch-default -Weffc++ -Wmain -Wextra -Wall -g -pipe -fexceptions -Wcast-qual -Wconversion -Wctor-dtor-privacy -Wempty-body -Wformat-security -Wformat=2 -Wignored-qualifiers -Wlogical-op -Wno-missing-field-initializers -Wnon-virtual-dtor -Woverloaded-virtual -Wpointer-arith -Wsign-promo -Wstack-usage=8192 -Wstrict-aliasing -Wstrict-null-sentinel -Wtype-limits -Wwrite-strings -Werror=vla -D_DEBUG -D_EJUDGE_CLIENT_SIDE

COMP = g++

SOURCES = $(wildcard *.cpp)
OBJECTS = $(wildcard objects/*.o)
MOVE_OBJECTS = $(wildcard *.o)
EXECUTABLE = main
TX_LIB = txlib
look:
	echo $(SOURCES)

link: $(OBJECTS)
	$(COMP) $(FLAGS) $(OBJECTS) -o $(EXECUTABLE)

obj: $(SOURCES)
	$(COMP) $(FLAGS) $(SOURCES) -c
	make copy

tx: $(TX_LIB)
	$(COMP) $(FLAGS) -c TXLib/$<.cpp -o objects/$<.o

all: $(SOURCES)
	$(COMP) $(SOURCES) -o main $(FLAGS)

%.o: %.cpp
	$(COMP) $(FLAGS) -c $< -o objects/$@

copy: $(MOVE_OBJECTS)
	mv $(MOVE_OBJECTS) objects/
clean:
	rm *.exe

clean_obj:
	rm objects/*.o

clean_all:
	make clean_obj
	make clean
