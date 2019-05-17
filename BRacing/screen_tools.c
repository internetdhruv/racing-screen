#include "screen_tools.h"
#include <stdio.h>

/**
 * Display Modes:
 * 1 - Display Single (Banner + Label)
 */

static status s;
static displayElements elements;
static void clearAll(){
	int i;
	for(i=0; i<MAX_NUMBER_OF_ELEMENTS; i++){
			if(elements.banners[i] != NULL){
				lv_obj_del(elements.banners[i]);
			}
			if(elements.values[i] != NULL){
				lv_obj_del(elements.values[i]);
			}
			if(elements.buttons[i] != NULL){
				lv_obj_del(elements.buttons[i]);
			}
	}
	elements.numBanners = elements.numButtons = elements.numValues = 0;
}


void screen_tools_init(){
	int i;
	for(i=0; i<MAX_NUMBER_OF_ELEMENTS; i++){
		elements.banners[i] = NULL;
		elements.values[i]  = NULL;
		elements.buttons[i] = NULL;
	}

	for(i=0; i<NUMBER_OF_DISPLAY_STYLES; i++){
		s.isActive[i] = 0;
	}
}

void display(uint8_t mode, uint8_t vals[], char labels[][30]){
	switch(mode){
		case 1:
			displaySingle(labels[0], vals[0], s.isActive[1]);
			break;
		case 2:
			break;
	}
}

void displaySingle(char* str, uint8_t value, int update){
	if(update){
		lv_label_set_text(elements.banners[0], str);

		char buffer[10];
		snprintf(buffer, 10, "%d", value);
		lv_label_set_text(elements.values[0], buffer);
		lv_obj_align(elements.values[0], NULL, LV_ALIGN_CENTER, 0, 0);

		return;
	}

	//verifyMemory(/*banners*/ 1, /*values*/ 1, /*buttons*/ 0);
	clearAll();

	// Create Heading
	lv_obj_t* heading = lv_label_create(lv_scr_act(), NULL);
	lv_obj_set_size(heading, 200, 40);
	lv_label_set_text(heading, str);
	lv_obj_align(heading, NULL, LV_ALIGN_IN_TOP_MID, 0, 0);

	// Write value
	char buffer[10];
	lv_obj_t* val_label = lv_label_create(lv_scr_act(), NULL);
	lv_obj_align(val_label, NULL, LV_ALIGN_CENTER, 0, 0);
	snprintf(buffer, 10, "%d", value);
	lv_label_set_text(val_label, buffer);

	elements.banners[elements.numBanners++] = heading;
	elements.values[elements.numValues++] = val_label;
	s.isActive[1] = 1;
}

void fgg(void)
{

    /*Create a Label on the currently active screen*/
    lv_obj_t * label1 =  lv_label_create(lv_scr_act(), NULL);

    /*Modify the Label's text*/
    lv_label_set_text(label1, "Hello world!");

    lv_obj_t* gauge1 = lv_gauge_create(lv_scr_act(), NULL);
    lv_gauge_set_range(gauge1, 0, 12);
    lv_gauge_set_scale(gauge1, 220, 10, 10);
    lv_gauge_set_critical_value(gauge1, 10000);
    static lv_color_t needle_colors[] = {LV_COLOR_BLUE};
    lv_gauge_set_needle_count(gauge1, 1, needle_colors);

    lv_gauge_set_value(gauge1, 0, 4);


    /* Align the Label to the center
     * NULL means align on parent (which is the screen now)
     * 0, 0 at the end means an x, y offset after alignment*/
    lv_obj_align(label1, NULL, LV_ALIGN_CENTER, 0, 0);
}

