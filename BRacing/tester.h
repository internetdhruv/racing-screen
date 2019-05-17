/*
 * tester.h
 *
 *  Created on: May 4, 2019
 *      Author: dhruvsharma
 */

#ifndef BRACING_TESTER_H_
#define BRACING_TESTER_H_

#include <stdlib.h>
#include "screen_tools.h"

#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl/lvgl.h"


void test(){
	int r = rand() % 10000;
	//displaySingle("RPM", r);
}

void create_tester(){
}

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* BRACING_TESTER_H_ */
