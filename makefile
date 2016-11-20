CC = g++

# Read the config of SDL using the sdl-config tool
LIBS = $(shell sdl-config --libs)
CFLAGS = $(shell sdl-config --cflags)

MAIN = main
MAIN_OBJS = AStarNode.cc Position.cc PRM.cc PRMNode.cc MyWorld.cc Obstacle.cc World.cc solvePlanningProblem.cc

$(MAIN): $(MAIN_OBJS) 
	$(CC) $(CFLAGS) -o $(MAIN) $(MAIN_OBJS) $(LIBS)

clean: 
	rm -f *.o $(MAIN)

debug:
	$(CC)  $(CFLAGS) -o $(MAIN) $(MAIN_OBJS) $(LIBS) -g

