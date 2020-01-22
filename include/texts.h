/**************************************************************************************************/
// File: texts.h
// Description: Project texts defines file
// Created on: 22 jan. 2020
// Last modified date: 22 jan. 2020
// Version: 1.0.0
/**************************************************************************************************/

/* Include Guard */

#ifndef TEXTS_H
#define TEXTS_H

/**************************************************************************************************/

// Tool usage info
#define TEXT_USAGE \
    "Usage:\n" \
    "    cases [tolower/toupper] string\n" \
    "Examples:\n" \
    "    cases tolower \"TURN all CHaRacter OF This texT TO LOWER.\"\n" \
    "    cases toupper \"TURN all CHaRacter OF This texT TO UPPER.\"\n"

// Project tool needs an expected argument to run
#define TEXT_NEEDS_ARGVS "You need to specify the operation and the string text to convert it."

// An unexpected operation has been provided
#define TEXT_INVALID_OP "Invalid operation."

/**************************************************************************************************/

/* Include Guard */

#endif // TEXTS_H
