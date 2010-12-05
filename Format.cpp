/*
 * Format.cpp
 *
 *  Created on: 05.12.2010
 *      Author: rofl
 */

#include <stdarg.h>
#include "Format.h"

std::string format(std::string fmt, ...) {
	const size_t BUF_SIZE = 1000;
	char result[BUF_SIZE];
	va_list ap;
	va_start(ap, fmt);
	vsnprintf(result, BUF_SIZE, fmt.c_str(), ap);
	va_end(ap);
	std::string rslt = result;
	return rslt;
}
