/*
 * BRacing.h
 *
 *  Created on: May 4, 2019
 *      Author: dhruvsharma
 */

#ifndef BRACING_SCREEN_TOOLS_H_
#define BRACING_SCREEN_TOOLS_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl/lvgl.h"
#include <stdlib.h>

/**********************
 *      MACROS
 **********************/

#define MAX_LABEL_LENGTH 30
#define MAX_NUMBER_OF_ELEMENTS 10
#define NUMBER_OF_DISPLAY_STYLES 10

/**********************
 *      TYPEDEFS
 **********************/

typedef struct{
	int isActive[NUMBER_OF_DISPLAY_STYLES];
} status;

typedef struct{
	lv_obj_t* banners[MAX_NUMBER_OF_ELEMENTS];
	lv_obj_t* values[MAX_NUMBER_OF_ELEMENTS];
	lv_obj_t* buttons[MAX_NUMBER_OF_ELEMENTS];
	int numBanners;
	int numValues;
	int numButtons;
} displayElements;

/**********************
 *  GLOBAL PROTOTYPES
 **********************/

void screen_tools_init();
void display(uint8_t mode, uint8_t vals[], char labels[][30]);
void displaySingle(char* str, uint8_t value, int update);

#ifdef __cplusplus
} /* extern "C" */
#endif


#endif /* BRACING_SCREEN_TOOLS_H_ */
