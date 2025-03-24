#include <string>
#include "applicationInternal/commandHandler.h"
#include "applicationInternal/hardware/hardwarePresenter.h"
#include "device_TV.h"

// Only activate the commands that are used. Every command takes 100 bytes, wether used or not.

uint16_t TV_POWER_ON        ; //"TV_power_on";
uint16_t TV_POWER_OFF       ; //"TV_power_off";

uint16_t TV_NUM_1           ; //"TV_num_1";
uint16_t TV_NUM_2           ; //"TV_num_2";
uint16_t TV_NUM_3           ; //"TV_num_3";
uint16_t TV_NUM_4           ; //"TV_num_4";
uint16_t TV_NUM_5           ; //"TV_num_5";
uint16_t TV_NUM_6           ; //"TV_num_6";
uint16_t TV_NUM_7           ; //"TV_num_7";
uint16_t TV_NUM_8           ; //"TV_num_8";
uint16_t TV_NUM_9           ; //"TV_num_9";
uint16_t TV_NUM_0           ; //"TV_num_0";

uint16_t TV_VOL_PLUS        ; //"TV_vol_plus";
uint16_t TV_VOL_MINUS       ; //"TV_vol_minus";
uint16_t TV_VOL_MUTE        ; //"TV_vol_mute";

uint16_t TV_MENU            ; //"TV_menu";
uint16_t TV_INFO            ; //"TV_info";
uint16_t TV_OPTION          ; //"TV_info";
uint16_t TV_EXIT            ; //"TV_exit";      

uint16_t TV_UP              ; //"TV_up";
uint16_t TV_DOWN            ; //"TV_down";
uint16_t TV_LEFT            ; //"TV_left";
uint16_t TV_RIGHT           ; //"TV_right";
uint16_t TV_SELECT          ; //"TV_select";

uint16_t TV_INPUT_HDMI_1    ; //"TV_input_hdmi_1";
uint16_t TV_INPUT_HDMI_2    ; //"TV_input_hdmi_2";
uint16_t TV_INPUT_HDMI_3    ; //"TV_input_hdmi_3";
uint16_t TV_INPUT_HDMI_4    ; //"TV_input_hdmi_4";
uint16_t TV_INPUT_NEXT        ; //"TV_input_next";

void register_device_TV() {
  // tested with Sony kdl-40V4100

  register_command(&TV_POWER_ON          , makeCommandData(IR, {std::to_string(IR_PROTOCOL_SONY12), "0x750"}));
  register_command(&TV_POWER_OFF         , makeCommandData(IR, {std::to_string(IR_PROTOCOL_SONY12), "0xF50"}));

  register_command(&TV_NUM_1             , makeCommandData(IR, {std::to_string(IR_PROTOCOL_SONY12), "0x010"}));
  register_command(&TV_NUM_2             , makeCommandData(IR, {std::to_string(IR_PROTOCOL_SONY12), "0x810"}));
  register_command(&TV_NUM_3             , makeCommandData(IR, {std::to_string(IR_PROTOCOL_SONY12), "0x410"}));
  register_command(&TV_NUM_4             , makeCommandData(IR, {std::to_string(IR_PROTOCOL_SONY12), "0xC10"}));
  register_command(&TV_NUM_5             , makeCommandData(IR, {std::to_string(IR_PROTOCOL_SONY12), "0x210"}));
  register_command(&TV_NUM_6             , makeCommandData(IR, {std::to_string(IR_PROTOCOL_SONY12), "0xA10"}));
  register_command(&TV_NUM_7             , makeCommandData(IR, {std::to_string(IR_PROTOCOL_SONY12), "0x610"}));
  register_command(&TV_NUM_8             , makeCommandData(IR, {std::to_string(IR_PROTOCOL_SONY12), "0xE10"}));
  register_command(&TV_NUM_9             , makeCommandData(IR, {std::to_string(IR_PROTOCOL_SONY12), "0x110"}));
  register_command(&TV_NUM_0             , makeCommandData(IR, {std::to_string(IR_PROTOCOL_SONY12), "0x110"}));
  
  register_command(&TV_VOL_PLUS          , makeCommandData(IR, {std::to_string(IR_PROTOCOL_SONY12), "0x490"}));
  register_command(&TV_VOL_MINUS         , makeCommandData(IR, {std::to_string(IR_PROTOCOL_SONY12), "0xC90"}));
  register_command(&TV_VOL_MUTE          , makeCommandData(IR, {std::to_string(IR_PROTOCOL_SONY12), "0x290"}));
  
  register_command(&TV_MENU              , makeCommandData(IR, {std::to_string(IR_PROTOCOL_SONY12), "0x070"}));
  register_command(&TV_INFO              , makeCommandData(IR, {std::to_string(IR_PROTOCOL_SONY12), "0x5D0"}));
  register_command(&TV_OPTION            , makeCommandData(IR, {std::to_string(IR_PROTOCOL_SONY15), "0x36E9"}));
  register_command(&TV_EXIT              , makeCommandData(IR, {std::to_string(IR_PROTOCOL_SONY15), "0x62E9"}));

  register_command(&TV_UP                , makeCommandData(IR, {std::to_string(IR_PROTOCOL_SONY12), "0x2F0"}));
  register_command(&TV_DOWN              , makeCommandData(IR, {std::to_string(IR_PROTOCOL_SONY12), "0xAF0"}));
  register_command(&TV_LEFT              , makeCommandData(IR, {std::to_string(IR_PROTOCOL_SONY12), "0x2D0"}));
  register_command(&TV_RIGHT             , makeCommandData(IR, {std::to_string(IR_PROTOCOL_SONY12), "0xCD0"}));
  register_command(&TV_SELECT            , makeCommandData(IR, {std::to_string(IR_PROTOCOL_SONY12), "0xA70"}));

  register_command(&TV_INPUT_HDMI_1      , makeCommandData(IR, {std::to_string(IR_PROTOCOL_SONY15), "0x2D58"}));
  register_command(&TV_INPUT_HDMI_2      , makeCommandData(IR, {std::to_string(IR_PROTOCOL_SONY15), "0x6D58"}));
  register_command(&TV_INPUT_HDMI_3      , makeCommandData(IR, {std::to_string(IR_PROTOCOL_SONY15), "0x1D58"}));
  register_command(&TV_INPUT_HDMI_4      , makeCommandData(IR, {std::to_string(IR_PROTOCOL_SONY15), "0x5D58"}));
  register_command(&TV_INPUT_NEXT        , makeCommandData(IR, {std::to_string(IR_PROTOCOL_SONY12), "0xA50"}));

}
