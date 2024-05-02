/**
 * @file    commons.c
 * @author  Jose Miguel Rios Rubio
 * @date    2020.01.22
 * @version 1.0.0
 * @brief   Commons functions file.
 */

/**************************************************************************************************/

/* Libraries */

#include "commons.h"

#include <string.h>

/**************************************************************************************************/

/* Functions */

// Convert from upper cases to lower cases for the given string
void cstr_lower(char* cstr, const size_t cstr_max_length)
{
    char c;

    for(size_t i = 0; i < cstr_max_length; i++)
    {
        c = cstr[i];

        // Break if end of string charater has arrive
        if(c == '\0')
            break;

        // Convert expected basic ascii upper to lower
        switch(c)
        {
            case 'A': cstr[i] = 'a'; break;
            case 'B': cstr[i] = 'b'; break;
            case 'C': cstr[i] = 'c'; break;
            case 'D': cstr[i] = 'd'; break;
            case 'E': cstr[i] = 'e'; break;
            case 'F': cstr[i] = 'f'; break;
            case 'G': cstr[i] = 'g'; break;
            case 'H': cstr[i] = 'h'; break;
            case 'I': cstr[i] = 'i'; break;
            case 'J': cstr[i] = 'j'; break;
            case 'K': cstr[i] = 'k'; break;
            case 'L': cstr[i] = 'l'; break;
            case 'M': cstr[i] = 'm'; break;
            case 'N': cstr[i] = 'n'; break;
            case 'O': cstr[i] = 'o'; break;
            case 'P': cstr[i] = 'p'; break;
            case 'Q': cstr[i] = 'q'; break;
            case 'R': cstr[i] = 'r'; break;
            case 'S': cstr[i] = 's'; break;
            case 'T': cstr[i] = 't'; break;
            case 'U': cstr[i] = 'u'; break;
            case 'V': cstr[i] = 'v'; break;
            case 'W': cstr[i] = 'w'; break;
            case 'X': cstr[i] = 'x'; break;
            case 'Y': cstr[i] = 'y'; break;
            case 'Z': cstr[i] = 'z'; break;
            default: break;
        }
    }
}

// Convert from lower cases to upper cases for the given string
void cstr_upper(char* cstr, const size_t cstr_max_length)
{
    char c;

    for(size_t i = 0; i < cstr_max_length; i++)
    {
        c = cstr[i];

        // Break if end of string charater has arrive
        if(c == '\0')
            break;

        // Convert expected basic ascii upper to lower
        switch(c)
        {
            case 'a': cstr[i] = 'A'; break;
            case 'b': cstr[i] = 'B'; break;
            case 'c': cstr[i] = 'C'; break;
            case 'd': cstr[i] = 'D'; break;
            case 'e': cstr[i] = 'E'; break;
            case 'f': cstr[i] = 'F'; break;
            case 'g': cstr[i] = 'G'; break;
            case 'h': cstr[i] = 'H'; break;
            case 'i': cstr[i] = 'I'; break;
            case 'j': cstr[i] = 'J'; break;
            case 'k': cstr[i] = 'K'; break;
            case 'l': cstr[i] = 'L'; break;
            case 'm': cstr[i] = 'M'; break;
            case 'n': cstr[i] = 'N'; break;
            case 'o': cstr[i] = 'O'; break;
            case 'p': cstr[i] = 'P'; break;
            case 'q': cstr[i] = 'Q'; break;
            case 'r': cstr[i] = 'R'; break;
            case 's': cstr[i] = 'S'; break;
            case 't': cstr[i] = 'T'; break;
            case 'u': cstr[i] = 'U'; break;
            case 'v': cstr[i] = 'V'; break;
            case 'w': cstr[i] = 'W'; break;
            case 'x': cstr[i] = 'X'; break;
            case 'y': cstr[i] = 'Y'; break;
            case 'z': cstr[i] = 'Z'; break;
            default: break;
        }
    }
}
