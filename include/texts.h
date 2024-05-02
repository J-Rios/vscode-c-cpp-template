/**
 * @file    texts.h
 * @author  Jose Miguel Rios Rubio
 * @date    2020.01.22
 * @version 1.0.0
 * @brief   Project texts defines file.
 */

/**************************************************************************************************/

/* Include Guard */

#ifndef TEXTS_H
#define TEXTS_H

/**************************************************************************************************/

// Tool usage info
static const char TEXT_USAGE[] =
    "Usage:\n" \
    "    cases [tolower/toupper] string\n" \
    "Examples:\n" \
    "    cases tolower \"TURN all CHaRacter OF This texT TO LOWER.\"\n" \
    "    cases toupper \"TURN all CHaRacter OF This texT TO UPPER.\"\n";

// Project tool needs an expected argument to run
static const char TEXT_NEEDS_ARGVS[] =
    "You need to specify the operation and the string text to convert it.";

// An unexpected operation has been provided
static const char TEXT_INVALID_OP[] = "Invalid operation.";

/**************************************************************************************************/

/* Include Guard */

#endif // TEXTS_H
