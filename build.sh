#!/usr/bin/env bash
cd testt
g++ -I/usr/include/ncurses -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"ConsoleWindow.d" -MT"ConsoleWindow.d" -o"ConsoleWindow.o" "../ConsoleWindow.cpp"
g++ -I/usr/include/ncurses -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"conpix.d" -MT"conpix.d" -o"conpix.o" "../conpix.cpp"
g++  -o"conpix"  ./ConsoleWindow.o ./Format.o ./Logger.o ./Rgb.o ./conpix.o   -lncurses -lpng -ltiff -llept
echo -ne "Finished building target: conpix\nyou can now run testt/conpix executable\n"
 
