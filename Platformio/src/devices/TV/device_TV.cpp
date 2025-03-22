#include <string>
#include "applicationInternal/commandHandler.h"
#include "applicationInternal/hardware/hardwarePresenter.h"
#include "device_TV.h"

// Only activate the commands that are used. Every command takes 100 bytes, wether used or not.

uint16_t TV_POWER_OFF       ; //"TV_power_off";
uint16_t TV_POWER_ON        ; //"TV_power_on";

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

uint16_t TV_VOL_MINUS       ; //"TV_vol_minus";
uint16_t TV_VOL_PLUS        ; //"TV_vol_plus";
uint16_t TV_MUTE_TOGGLE     ; //"TV_mute_toggle";

uint16_t TV_MENU            ; //"TV_menu";
uint16_t TV_GUIDE           ; //"TV_guide";
uint16_t TV_INFO            ; //"TV_info";

uint16_t TV_UP              ; //"TV_up";
uint16_t TV_DOWN            ; //"TV_down";
uint16_t TV_LEFT            ; //"TV_left";
uint16_t TV_RIGHT           ; //"TV_right";
uint16_t TV_SELECT          ; //"TV_select";

uint16_t TV_RETURN          ; //"TV_return";
uint16_t TV_EXIT            ; //"TV_exit";

uint16_t TV_INPUT_HDMI_1    ; //"TV_input_hdmi_1";
uint16_t TV_INPUT_HDMI_2    ; //"TV_input_hdmi_2";
uint16_t TV_INPUT_HDMI_3    ; //"TV_input_hdmi_3";
uint16_t TV_INPUT_HDMI_4    ; //"TV_input_hdmi_4";
uint16_t TV_INPUT_NEXT        ; //"TV_input_next";

void register_device_TV() {
  // tested with Sony kdl-40V4100
  // both GC and Sony work well

  // https://github.com/natcl/studioimaginaire/blob/master/arduino_remote/ircodes.py
  // Only activate the commands that are used. Every command takes 100 bytes, wether used or not.
  register_command(&TV_POWER_OFF         , makeCommandData(IR, {std::to_string(IR_PROTOCOL_SAMSUNG), "0xE0E019E6"}));
  register_command(&TV_POWER_ON          , makeCommandData(IR, {std::to_string(IR_PROTOCOL_SAMSUNG), "0xE0E09966"}));

  register_command(&TV_NUM_1             , makeCommandData(IR, {std::to_string(IR_PROTOCOL_SAMSUNG), "0xE0E020DF"}));
  register_command(&TV_NUM_2             , makeCommandData(IR, {std::to_string(IR_PROTOCOL_SAMSUNG), "0xE0E0A05F"}));
  register_command(&TV_NUM_3             , makeCommandData(IR, {std::to_string(IR_PROTOCOL_SAMSUNG), "0xE0E0609F"}));
  register_command(&TV_NUM_4             , makeCommandData(IR, {std::to_string(IR_PROTOCOL_SAMSUNG), "0xE0E010EF"}));
  register_command(&TV_NUM_5             , makeCommandData(IR, {std::to_string(IR_PROTOCOL_SAMSUNG), "0xE0E0906F"}));
  register_command(&TV_NUM_6             , makeCommandData(IR, {std::to_string(IR_PROTOCOL_SAMSUNG), "0xE0E050AF"}));
  register_command(&TV_NUM_7             , makeCommandData(IR, {std::to_string(IR_PROTOCOL_SAMSUNG), "0xE0E030CF"}));
  register_command(&TV_NUM_8             , makeCommandData(IR, {std::to_string(IR_PROTOCOL_SAMSUNG), "0xE0E0B04F"}));
  register_command(&TV_NUM_9             , makeCommandData(IR, {std::to_string(IR_PROTOCOL_SAMSUNG), "0xE0E0708F"}));
  register_command(&TV_NUM_0             , makeCommandData(IR, {std::to_string(IR_PROTOCOL_SAMSUNG), "0xE0E08877"}));
  
  register_command(&TV_VOL_MINUS         , makeCommandData(IR, {std::to_string(IR_PROTOCOL_SAMSUNG), "0xE0E0D02F"}));
  register_command(&TV_VOL_PLUS          , makeCommandData(IR, {std::to_string(IR_PROTOCOL_SAMSUNG), "0xE0E0E01F"}));
  register_command(&TV_MUTE_TOGGLE       , makeCommandData(IR, {std::to_string(IR_PROTOCOL_SAMSUNG), "0xE0E0F00F"}));
  
  register_command(&TV_MENU              , makeCommandData(IR, {std::to_string(IR_PROTOCOL_SAMSUNG), "0xE0E058A7"}));
  register_command(&TV_GUIDE             , makeCommandData(IR, {std::to_string(IR_PROTOCOL_SAMSUNG), "0xE0E0F20D"}));
  register_command(&TV_INFO              , makeCommandData(IR, {std::to_string(IR_PROTOCOL_SAMSUNG), "0xE0E0F807"}));

  register_command(&TV_UP                , makeCommandData(IR, {std::to_string(IR_PROTOCOL_SAMSUNG), "0xE0E006F9"}));
  register_command(&TV_DOWN              , makeCommandData(IR, {std::to_string(IR_PROTOCOL_SAMSUNG), "0xE0E08679"}));
  register_command(&TV_LEFT              , makeCommandData(IR, {std::to_string(IR_PROTOCOL_SAMSUNG), "0xE0E0A659"}));
  register_command(&TV_RIGHT             , makeCommandData(IR, {std::to_string(IR_PROTOCOL_SAMSUNG), "0xE0E046B9"}));
  register_command(&TV_SELECT            , makeCommandData(IR, {std::to_string(IR_PROTOCOL_SAMSUNG), "0xE0E016E9"}));

  register_command(&TV_RETURN            , makeCommandData(IR, {std::to_string(IR_PROTOCOL_SAMSUNG), "0xE0E01AE5"}));
  register_command(&TV_EXIT              , makeCommandData(IR, {std::to_string(IR_PROTOCOL_SAMSUNG), "0xE0E0B44B"}));

  register_command(&TV_INPUT_HDMI_1      , makeCommandData(IR, {std::to_string(IR_PROTOCOL_SAMSUNG), "0xE0E09768"}));
  register_command(&TV_INPUT_HDMI_2      , makeCommandData(IR, {std::to_string(IR_PROTOCOL_SAMSUNG), "0xE0E07D82"}));
  register_command(&TV_INPUT_HDMI_3      , makeCommandData(IR, {std::to_string(IR_PROTOCOL_SAMSUNG), "0xE0E043BC"}));
  register_command(&TV_INPUT_HDMI_4      , makeCommandData(IR, {std::to_string(IR_PROTOCOL_SAMSUNG), "0xE0E0A35C"}));
  register_command(&TV_INPUT_NEXT        , makeCommandData(IR, {std::to_string(IR_PROTOCOL_SAMSUNG), "0xE0E0D827"}));

}
