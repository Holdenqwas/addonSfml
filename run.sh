#!/bin/bash

g++ -c main.cpp
#g++ -c Form.cpp
echo "Compile object file - Done!"
#g++ main.o Form.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system
g++ main.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system
echo "Compile app - Done!"
./sfml-app
