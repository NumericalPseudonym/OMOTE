#pragma once

// Only activate the commands that are used. Every command takes 100 bytes, wether used or not.

extern uint16_t TV_POWER_OFF;
extern uint16_t TV_POWER_ON;

extern uint16_t TV_NUM_1;
extern uint16_t TV_NUM_2;
extern uint16_t TV_NUM_3;
extern uint16_t TV_NUM_4;
extern uint16_t TV_NUM_5;
extern uint16_t TV_NUM_6;
extern uint16_t TV_NUM_7;
extern uint16_t TV_NUM_8;
extern uint16_t TV_NUM_9;
extern uint16_t TV_NUM_0;

extern uint16_t TV_VOL_MINUS;
extern uint16_t TV_VOL_PLUS;
extern uint16_t TV_MUTE_TOGGLE;

extern uint16_t TV_MENU;
extern uint16_t TV_GUIDE;
extern uint16_t TV_INFO;

extern uint16_t TV_UP;
extern uint16_t TV_DOWN;
extern uint16_t TV_LEFT;
extern uint16_t TV_RIGHT;
extern uint16_t TV_SELECT;

extern uint16_t TV_RETURN;
extern uint16_t TV_EXIT;

extern uint16_t TV_INPUT_HDMI_1;
extern uint16_t TV_INPUT_HDMI_2;
extern uint16_t TV_INPUT_HDMI_3;
extern uint16_t TV_INPUT_HDMI_4;
extern uint16_t TV_INPUT_NEXT;

void register_device_TV();
