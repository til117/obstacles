# obstacles

The theme of this project is probabilistic road maps, obstacle definition and collision checking.

The program constructs obstacles in an empty grid, in order for a path planning algorithm to choose a collision-free path from a starting point to the ending point of that grid.

It is a small project for a programming course at KTH´, and is implemented in MATLAB.

# Description

Separate specification text files for which obstacles were to be created and their sizes were provided. Moreover, the starting point and ending point of the path planning algorithm were also specified here. The desired obstacles were circles and rectangles with the following parameters: center coordinates, radius, width, height and angle. The angle was used to rotate the rectangles to a desired position. 

For this project, I create two files. 

# Obstacle.cc

This file defines and creates the obstacles. Firstly, a class named “Obstacle” was created, defining the center coordinates of the obstacle to be created. Secondly, two more classes were created, named “Circle” and “Rectangle”, which inherited the center coordinates from the class “Obstacle”. They provided an interface for the shapes of circles and rectangles. The main goal of this file is to define circles and rectangles and providing an interface for the path planning algorithm to check for collisions and writing a MATLAB file, plotting the result of the path planning algorithm used on this obstacles. 

Furthermore, the classes “Circle” and “Rectangle” checks if the coordinates provided by the path 
planning algorithm collides with any obstacle by using the function “collidesWith”.  
In order to perform a collision check, a set of new coordinates are used, unique for every 
geometric figure. 

Lastly, the classes “Circle” and “Rectangle” plots the desired obstacle in MATLAB using the 
function “writeMatlabDisplayCode”.  

# MyWorld.m

The second file in this project was calles “MyWorld.cc”. 
In this file, a class named “MyWorld” was created, providing important features for the path 
planning algorithm in order to read from the specification text files. This was done using the 
function “readObstacles”. Another important feature was the interface for collision checking and 
MATLAB writing. 

# Instructions

To run code, type:  ./main -p problem1.txt

You may want to replace "problem1.tx" with "problem2.txt" or "problem3.txt"

It is not necessary to type:   -w MyWorld

PS: If the main file is corrupt, delete it and type: make
