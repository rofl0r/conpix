/*
 * Endianness.h
 *
 *  Created on: 29.11.2010
 *      Author: rofl
 */

#ifndef ENDIANNESS_H_
#define ENDIANNESS_H_

#ifdef __linux
#include <endian.h>
#else
#include <machine/endian.h>
#endif

//#include <stdint.h>
//#define IS_BIG_ENDIAN (*(uint16_t *)"\0\xff" < 0x100)

#if __BYTE_ORDER == __LITTLE_ENDIAN
#define IS_LITTLE_ENDIAN
#endif

#endif /* ENDIANNESS_H_ */
