/*
 * ConsoleWindow.h
 *
 *  Created on: 29.11.2010
 *      Author: rofl
 */

#ifndef CONSOLEWINDOW_H_
#define CONSOLEWINDOW_H_

#include <stdint.h>

#include "Rgb.h"
#include "Logger.h"
#include "NsNcurses.h"

const int colorpaircount = 256;

class ConsoleWindow {
private:
	int lastattr;
	int32_t colors[colorpaircount];
	int32_t* fgcolors[colorpaircount];
	int32_t* bgcolors[colorpaircount];

	RGB org_colors[colorpaircount];
	short int org_fgcolors[colorpaircount];
	short int org_bgcolors[colorpaircount];

	int maxcol;
	int32_t actfgcol;
	int32_t actbgcol;
	ILogger* logger;
public:

	bool hasColors;
	bool canChangeColors;

	ConsoleWindow(ILogger* _logger);
	virtual ~ConsoleWindow();
	void log(std::string s);
	void inittables();
	void saveColors();
	void restoreColors();
	bool setColor(RGB mycolor, bool fg);
	void initoutput();
	bool setCursesColor(int colornumber, RGB color);
	bool setColorPair(int pair, int fgcol, int bgcol);
	bool useColorPair(int pair);
	void getSize(int& x, int& y);
	void gotoxy(int x, int y);
	void addchar(int c, unsigned int attributes);
	void printfxy (int x, int y, char* text);
	char getKey();
	void sleep(int ms);
	void refresh();
	void clear();
	int fromThousand(int in);
	int toThousand(int in);
};

#endif /* CONSOLEWINDOW_H_ */
