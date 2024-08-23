FLAGS=-Wshadow -Winit-self -Wredundant-decls -Wcast-align -Wundef -Wfloat-equal -Winline -Wunreachable-code -Wmissing-declarations -Wmissing-include-dirs -Wswitch-enum -Wswitch-default -Weffc++ -Wmain -Wextra -Wall -g -pipe -fexceptions -Wcast-qual -Wconversion -Wctor-dtor-privacy -Wempty-body -Wformat-security -Wformat=2 -Wignored-qualifiers -Wlogical-op -Wno-missing-field-initializers -Wnon-virtual-dtor -Woverloaded-virtual -Wpointer-arith -Wsign-promo -Wstack-usage=8192 -Wstrict-aliasing -Wstrict-null-sentinel -Wtype-limits -Wwrite-strings -Werror=vla -D_DEBUG -D_EJUDGE_CLIENT_SIDE

COMP = g++

SOURCES = $(wildcard *.cpp)
OBJECTS = $(wildcard TXLib/*.o)
MOVE_OBJECTS = $(wildcard *.o)
EXECUTABLE = main
look:
	echo $(SOURCES)

link: $(OBJECTS)
	$(COMP) $(FLAGS) $(OBJECTS) -o $(EXECUTABLE)

obj: $(SOURCES)
	$(COMP) $(FLAGS) $(SOURCES) -c

all: $(SOURCES)
	$(COMP) $(SOURCES) -o main $(FLAGS)

%.o: %.cpp
	$(COMP) $(FLAGS) -c $< -o TXlib/$@

copy: $(MOVE_OBJECTS)
	mv $(MOVE_OBJECTS) TXLib/
clean:
	rm *.exe

clean_obj:
	rm *.o
