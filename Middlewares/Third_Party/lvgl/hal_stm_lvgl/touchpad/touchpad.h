/**
 * @file indev.h
 * 
 */

#ifndef INDEV_H
#define INDEV_H

/*********************
 *      INCLUDES
 *********************/
#include <stdbool.h>
#include <stdint.h>

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 * GLOBAL PROTOTYPES
 **********************/
void touchpad_init(void);
bool touchpad_get_xy(int16_t *x, int16_t *y);

/**********************
 *      MACROS
 **********************/

#endif
