/**************************************************************************************************/
// File: main.c
// Description: Project main source. Turn string cases to lower or upper
// Created on: 22 jan. 2020
// Last modified date: 22 jan. 2020
// Version: 1.0.0
/**************************************************************************************************/

/* Libraries */

#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <string.h>

#include "commons.h"
#include "texts.h"

/**************************************************************************************************/

/* Defines */

// Maximum string length of input operation
#define MAX_LEN_OPERATION 8

// Maximum string length of input text
#define MAX_LEN_INPUT_STR 512

/**************************************************************************************************/

/* Functions Prototypes */

// Turn the given text into lower/upper
int8_t convert_string(const char* operation, char* str_text, const size_t str_text_size);

/**************************************************************************************************/

/* Main Function */

int main(int argc, char *argv[])
{
    char operation[MAX_LEN_OPERATION];
    char str_text[MAX_LEN_INPUT_STR];

    // Check for expected number of arguments and shows usage info if not
    if(argc <= 2)
    {
        println(TEXT_NEEDS_ARGVS);
        println(TEXT_USAGE);
        return RC_BAD;
    }

    // Get operation and input text
    snprintf(operation, MAX_LEN_OPERATION, "%s", argv[1]);
    snprintf(str_text, MAX_LEN_INPUT_STR, "%s", argv[2]);

    // Check provided operation
    if(convert_string(operation, str_text, strlen(str_text)) != RC_OK)
    {
        println(TEXT_INVALID_OP);
        println(TEXT_USAGE);
        return RC_BAD;
    }

    // Show result
    println(str_text);

    return RC_OK;
}

/**************************************************************************************************/

/* Auxiliar Functions */

// Turn the given text into lower/upper
int8_t convert_string(const char* operation, char* str_text, const size_t str_text_size)
{
    if(strcmp(operation, "tolower") == 0)
        cstr_lower(str_text, str_text_size);
    else if(strcmp(operation, "toupper") == 0)
        cstr_upper(str_text, str_text_size);
    else
        return RC_BAD;
    return RC_OK;
}
