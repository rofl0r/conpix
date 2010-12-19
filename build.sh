#!/usr/bin/env bash
INCLUDES="-I/opt/local/include/ -I/usr/local/include -I/usr/include/ncurses"
LIBDIRS="-L/opt/local/lib -L/usr/local/lib"
cd testt
g++ $INCLUDES -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"Rgb.d" -MT"Rgb.d" -o"Rgb.o" "../Rgb.c"
g++ $INCLUDES -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"Format.d" -MT"Format.d" -o"Format.o" "../Format.cpp"
g++ $INCLUDES -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"Logger.d" -MT"Logger.d" -o"Logger.o" "../Logger.cpp"
g++ $INCLUDES -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"ConsoleWindow.d" -MT"ConsoleWindow.d" -o"ConsoleWindow.o" "../ConsoleWindow.cpp"
g++ $INCLUDES -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"conpix.d" -MT"conpix.d" -o"conpix.o" "../conpix.cpp"
g++ ./ConsoleWindow.o ./Format.o ./Logger.o ./Rgb.o ./conpix.o $LIBDIRS -lncurses -lpng -ltiff -llept
mv a.out conpix
cd ..
echo -ne "Finished building target: conpix\nyou can now run testt/conpix executable\n"
 
