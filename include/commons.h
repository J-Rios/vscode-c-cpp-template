/**************************************************************************************************/
// File: commons.h
// Description: Commons functions file
// Created on: 22 jan. 2020
// Last modified date: 22 jan. 2020
// Version: 1.0.0
/**************************************************************************************************/

/* Include Guard */

#ifndef COMMONS_H
#define COMMONS_H

/**************************************************************************************************/

/* C++ compiler compatibility */

#ifdef __cplusplus
extern "C" {
#endif

/**************************************************************************************************/

/* Libraries */

#include <stdint.h>
#include <inttypes.h>
#include <stddef.h>

/**************************************************************************************************/

/* Defines */

// MAC Address max length
#define MAC_ADDR_MAX_LEN 18

// Return Codes
#define RC_ERROR -1
#define RC_OK     0
#define RC_BAD    1

// Macros
#define print(x) do { printf("%s", x); } while(0)
#define println(x) do { printf("%s", x); printf("\n"); } while(0)

/**************************************************************************************************/

/* Functions */

// Convert from upper cases to lower cases for the given string
void cstr_lower(char* cstr, const size_t cstr_max_length);

// Convert from lower cases to uppers cases for the given string
void cstr_upper(char* cstr, const size_t cstr_max_length);

/**************************************************************************************************/

/* C++ compiler compatibility */

#ifdef __cplusplus
}
#endif // extern "C"

/**************************************************************************************************/

/* Include Guard */

#endif // COMMONS_H
