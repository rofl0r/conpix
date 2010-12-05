/*
 * Logger.cpp
 *
 *  Created on: 05.12.2010
 *      Author: rofl
 */

#include <iostream>
#include <fstream>

#include "Logger.h"

using namespace std;

void ILogger::log(string s) {
}

void ILogger::logln(string s){
}


void SimpleConsoleLogger::log(string s) {
	cout << s;
}

void SimpleConsoleLogger::logln(string s){
	cout << s << endl;
}

SimpleFileLogger::SimpleFileLogger(string out_file) {
	outfile = out_file;
	myfile.open (outfile.c_str(), ios::out | ios::app | ios::binary);
}

SimpleFileLogger::~SimpleFileLogger() {
	myfile.close();
}
void SimpleFileLogger::logln(string s) {
	log(s);
	log("\n");
}

void SimpleFileLogger::log(string s) {
	myfile << s;
}

/*
virtual void log(void* buf, size_t bufsize){
	string mybuf;
	mybuf.length = bufsize;
	memcpy(mybuf.ptr, buf, bufsize);
	myfile.write(mybuf);
}
*/
void SimpleFileLogger::clear() {
	myfile.close();
	myfile.open (outfile.c_str(), ios::out | ios::trunc | ios::binary);
	//myfile = new File(outfile, File.WriteCreate);
}
