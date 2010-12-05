/*
 * Rgb.h
 *
 *  Created on: 29.11.2010
 *      Author: rofl
 */

#ifndef RGB_H_
#define RGB_H_

#include "Endianness.h"
#include <stdint.h>

typedef union {
	uint32_t asInt;
	struct {
	#ifdef IS_LITTLE_ENDIAN
		unsigned char a;
		unsigned char b;
		unsigned char g;
		unsigned char r;
	#else
		unsigned char r;
		unsigned char g;
		unsigned char b;
		unsigned char a;
	#endif
	};
} RGB;

#ifdef __cplusplus
extern "C" {
#endif
RGB rgb(int r, int g, int b);
#ifdef __cplusplus
}
#endif

#endif /* RGB_H_ */
