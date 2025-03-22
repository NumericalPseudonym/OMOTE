#include <map>
#include "scenes/scene_TV.h"
#include "applicationInternal/keys.h"
#include "applicationInternal/scenes/sceneRegistry.h"
#include "applicationInternal/hardware/hardwarePresenter.h"
// devices
#include "devices/TV/device_TV.h"
#include "applicationInternal/commandHandler.h"
// guis
#include "guis/gui_numpad.h"

uint16_t SCENE_TV         ; //"Scene_tv"
uint16_t SCENE_TV_FORCE   ; //"Scene_tv_force"

std::map<char, repeatModes> key_repeatModes_TV;
std::map<char, uint16_t> key_commands_short_TV;
std::map<char, uint16_t> key_commands_long_TV;

void scene_setKeys_TV() {
  key_repeatModes_TV = {
  {KEY_STOP,        SHORT_REPEATED   },
  {KEY_REWIND,      SHORT            },
  {KEY_PLAY,        SHORT            },
  {KEY_FORWARD,     SHORT_REPEATED   },
  {KEY_MENU,        SHORT            },
  {KEY_INFO,        SHORT            },
  {KEY_UP,          SHORT_REPEATED   },
  {KEY_LEFT,        SHORT_REPEATED   },
  {KEY_OK,          SHORT            },
  {KEY_RIGHT,       SHORT_REPEATED   },
  {KEY_DOWN,        SHORT_REPEATED   }, 
  {KEY_SRC,         SHORT            },
  {KEY_CHANEL_UP,   SHORT            },
  {KEY_CHANEL_DOWN, SHORT            },
  
  };
  
  key_commands_short_TV = {
  
    {KEY_MENU,  TV_GUIDE    },
    {KEY_INFO,  TV_MENU     },
    {KEY_UP,    TV_UP       },
    {KEY_LEFT,  TV_LEFT     },
    {KEY_OK,    TV_SELECT   },
    {KEY_RIGHT, TV_RIGHT    },
    {KEY_DOWN,  TV_DOWN     },  
  };
  
  key_commands_long_TV = {
  
  
  };

}

void scene_start_sequence_TV(void) {
  executeCommand(TV_POWER_ON);
}

void scene_end_sequence_TV(void) {

}

std::string scene_name_TV = "TV";
t_gui_list scene_TV_gui_list = {tabName_numpad};

void register_scene_TV(void) {
  register_command(&SCENE_TV,       makeCommandData(SCENE, {scene_name_TV}));
  register_command(&SCENE_TV_FORCE, makeCommandData(SCENE, {scene_name_TV, "FORCE"}));

  register_scene(
    scene_name_TV,
    & scene_setKeys_TV,
    & scene_start_sequence_TV,
    & scene_end_sequence_TV,
    & key_repeatModes_TV,
    & key_commands_short_TV,
    & key_commands_long_TV,
    & scene_TV_gui_list,
    SCENE_TV);
}
