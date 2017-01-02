CXXFLAGS =	-O2 -g -Wall -fmessage-length=0

OBJS =		ConsoleWindow.o Format.o Rgb.o conpix.o Logger.o

LEPT_LIBS := $(shell pkg-config --libs lept)
CURSES_LIBS := $(shell pkg-config --libs ncurses)

LIBS = $(CURSES_LIBS) $(LEPT_LIBS)

TARGET =	conpix

$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
