//============================================================================
// Name        : conpix.cpp
// Author      : rofl0r
// Version     :
// Copyright   : GPL v2
// Description : a picture viewer for the console. uses xterm-256color mode.
//============================================================================

#include <stdio.h>
#include <stdlib.h>

#include <iostream>
#include <fstream>

#include "Lepton.h"

#include "Logger.h"
#include "Format.h"
#include "ConsoleWindow.h"


using namespace std;

bool fexists(const char *filename) {
  ifstream ifile(filename);
  return ifile;
}

int main(int argc, char** argv) {
	string filename = "";
	bool scaleFullScreen = false;
	string arg;
	for (int i = 1; i<argc; i++) {
		arg = argv[i];
		if (arg == "-f") scaleFullScreen=true;
		else filename = arg;
	}

	if (!fexists(filename.c_str())) {
		string self = argv[0];
		cout << "file not found!" << endl << endl;
		cout << "c0npix by rofl0r" << endl;
		cout << "================" << endl;
		cout << "arguments: " << self << " [-f] somefile.[jpg|png|bmp|tiff]" << endl;
		cout << "where -f means scale to fullscreen" << endl << endl;
		cout << "export TERM=xterm-256color before usage is recommended." << endl;
		exit(1);
	}

	SimpleFileLogger* l = new SimpleFileLogger("log.txt");
	l->clear();

	ConsoleWindow* t = new ConsoleWindow(l);
	int cx; int cy;
	t->getSize(cx, cy);

	Pix* pngfile = pixRead(filename.c_str());

    float xfactor = 1.0; float yfactor = 1.0; int w; int h;
    pixGetDimensions(pngfile, &w, &h, NULL);
    Pix* ping;

    if(scaleFullScreen) {
    	xfactor = (cx * 1.0) / (w * 1.0);
    	yfactor = (cy * 1.0) / (h * 1.0);
    	ping = pixScale(pngfile, xfactor, yfactor);
    } else {
    	if (cx *2 < w) xfactor = (cx * 1.0) / (w * 1.0);
    	if (cy < h) yfactor = (cy * 1.0) / (h * 1.0);
    	float factor = (xfactor < yfactor) ? xfactor: yfactor;
    	if (cx *2 < w || cy < h)
    		ping = pixScale(pngfile, factor * 2.0, factor);
    	else
    	    // scale to double width so the proportion of the font is correct
    		ping = pixScale(pngfile, 2.0, 1.0 );
    }
    pixDestroy(&pngfile);
    //l.logln(format("scaling took %f ms", ti.stop));
    //ti.start();
	Pix* palette = pixOctreeColorQuant(ping, 240, 1);
	//l.logln(format("quant took %f ms", ti.stop));
	if (palette == NULL) { cout << "palette is nul"; return 1; }

	Pix* pix32;

	//ti.start();
    pix32 = pixConvertTo32(palette);
    //l.logln(format("convert took %f ms", ti.stop));

	l->logln(format("pal_number, pal_nalloc, pal_bits: %d, %d, %d" , palette->colormap->n, palette->colormap->nalloc, palette->colormap->depth));

	int iterX = pix32->w;
	int iterY = pix32->h;
	//ti.start();
	/*
	SimpleFileLogger* l2 = new SimpleFileLogger("bmpdata");
	l2->clear();
	char* ptr = (char*)pix32->data;
	string nl = "\"\n\"";
	for (int i=0; i<iterX * iterY * ((int)pix32->d / 8);i++) {
		if(i%32==0) l2->log(nl);
		string fmt = format("\\x%02X", *ptr);
		l2->log(fmt);

		ptr++;
	}
	*/
	//l.logln(format("logging C char took %f ms", ti.stop));
	//l2.log(pix32.data, iterX * iterY * (pix32.d / 8));

	int* bufptr = (int*) pix32->data;
	if (bufptr == NULL) {
		cout << "bufptr is null";
		return 1;
	}

	//ti.start();
	for (int iy=0;iy<iterY;iy++){
		//bufptr = cast(int*) b.scanline().ptr;
		for (int ix=0;ix<iterX;ix++){
			t->setColor(*((RGB*) bufptr), false);
			t->gotoxy(ix, iy);
			t->addchar(' ', 0);
			bufptr++;
			//t.getKey();
			//sleep(500);
		}
	}
	//l.logln(format("traversing colors took %f ms", ti.stop));
	//ti.start();
	//pixWrite("output.bmp", pix32, IFF_BMP);
	//l.logln(format("writing bmp took %f ms", ti.stop));
	pixDestroy(&palette);
	pixDestroy(&pix32);

	/*
	int x; int y;
	auto red = rgb(255, 0, 0);
	auto green = rgb(0,255,0);
	auto blue = rgb(0,0,255);

	assert(t.setColor(red, true), "err");
	assert(t.setColor(blue, false),"err");
	t.printfxy(5, 5, "red on blue", 20);
	assert(t.setColor(green, true), "err");
	assert(t.setColor(red, false),"err");
	t.printfxy(8, 8, "green on red");
	assert(t.setColor(green, false), "err");
	assert(t.setColor(red, true),"err");
	t.printfxy(18, 18, "red on green");
	*/
	//ti.start();
	t->refresh();
	//l.logln(format("display took %f ms", ti.stop));
	t->getKey();

	/*
	t.getSize(x, y);
	t.setColor(0, 200, 100, 0);
	t.setColor(1, 0, 0, 0);
	t.setColor(2, 0, 0, 255);
	t.setColorPair(1, 0, 1);
	t.setColorPair(2, 1, 2);

	t.gotoxy(0, 0);

	// first line
	t.useColorPair(1);
	for (int i = 0 ; i < x; i++) t.addchar(' ', 0);
	t.useColorPair(2);
	for (int j = 1; j < y -1 ; j++) {
		t.useColorPair(1);
		for (int i = 0 ; i < x; i++) t.addchar('\u2588', 0);
	}
	// last line
	t.useColorPair(1);
	for (int i = 0 ; i < x; i++) t.addchar(' ', 0);

	t.useColorPair(2);
	t.printfxy(10,10, "test");
	t.getKey();

	*/
	delete(t);
	delete(l);
	//delete(l2);
	return EXIT_SUCCESS;
}

