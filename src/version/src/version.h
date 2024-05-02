/**
 * @file    version.h
 * @author  Jose Miguel Rios Rubio
 * @date    2024.05.02
 * @version 1.0.0
 * @brief   Versioning file to be populate from build system.
 */

/*****************************************************************************/

/* Include Guards */

#ifndef __VERSION_H
#define __VERSION_H

/*****************************************************************************/

/* Libraries */

// Standard C/C++ Libraries
#include <cstdint>

/*****************************************************************************/

/* Data Types */

union t_version
{
    struct t_version_field
    {
        uint8_t x;
        uint8_t y;
        uint16_t z;
    } field;
    uint32_t value;
    uint8_t bytes[4];
};

/*****************************************************************************/

/* FW Application Version */

extern const int VERSION_X;
extern const int VERSION_Y;
extern const int VERSION_Z;
extern const bool VERSION_DEV;
extern const char* const BUILD_DATE;
extern const char* const BUILD_TIME;

/*****************************************************************************/

/* Include Guards Close */

#endif /* __VERSION_H */
