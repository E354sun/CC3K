CXX = g++
CXXFLAGS = -std=c++14
EXEC = cc3k
OBJECTS = main.o Map.o Component.o Character.o Items.o Player.o Enemy.o enemyRaces.o playerRaces.o Treasure.o State.o 
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
