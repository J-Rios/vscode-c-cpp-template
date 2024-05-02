/**
 * @file    main.cpp
 * @author  Jose Miguel Rios Rubio
 * @date    2020.01.22
 * @version 1.0.0
 * @brief   Project main source. Turn string cases to lower or upper.
 */

/**************************************************************************************************/

/* Libraries */

// Standard C/C++ Libraries
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <string.h>

// Project Libraries
#include "commons.h"
#include "texts.h"
#include "version.h"

/**************************************************************************************************/

/* Defines */

// Maximum string length of input operation
#define MAX_LEN_OPERATION 8

// Maximum string length of input text
#define MAX_LEN_INPUT_STR 512

/**************************************************************************************************/

/* Function Prototypes */

// Turn the given text into lower/upper
int8_t convert_string(const char* operation, char* str_text, const size_t str_text_size);

/**************************************************************************************************/

/* Main Function */

int main(int argc, char *argv[])
{
    char operation[MAX_LEN_OPERATION];
    char str_text[MAX_LEN_INPUT_STR];

    // Show Software Version
    printf("\ncases v%d.%d.%d", VERSION_X, VERSION_Y, VERSION_Z);
    if (VERSION_DEV)
    {   printf("-dev");   }
    printf(" (%s %s)\n\n", BUILD_DATE, BUILD_TIME);

    // Check for expected number of arguments and shows usage info if not
    if(argc <= 2)
    {
        printf("%s\n", TEXT_NEEDS_ARGVS);
        printf("%s\n", TEXT_USAGE);
        return RC_BAD;
    }

    // Get operation and input text
    snprintf(operation, MAX_LEN_OPERATION, "%s", argv[1]);
    snprintf(str_text, MAX_LEN_INPUT_STR, "%s", argv[2]);

    // Check provided operation
    if(convert_string(operation, str_text, strlen(str_text)) != RC_OK)
    {
        printf("%s\n", TEXT_INVALID_OP);
        printf("%s\n", TEXT_USAGE);
        return RC_BAD;
    }

    // Show result
    printf("%s\n", str_text);

    return RC_OK;
}

/**************************************************************************************************/

/* Auxiliary Functions */

// Turn the given text into lower/upper
int8_t convert_string(const char* operation, char* str_text, const size_t str_text_size)
{
    if(strcmp(operation, "tolower") == 0)
    {   cstr_lower(str_text, str_text_size);   }
    else if(strcmp(operation, "toupper") == 0)
    {   cstr_upper(str_text, str_text_size);   }
    else
    {   return RC_BAD;   }

    return RC_OK;
}

/**************************************************************************************************/
