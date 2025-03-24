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
  {KEY_MENU,        SHORT            },
  {KEY_UP,          SHORT_REPEATED   },
  {KEY_INFO,        SHORT            },
  {KEY_LEFT,        SHORT_REPEATED   },
  {KEY_OK,          SHORT            },
  {KEY_RIGHT,       SHORT_REPEATED   },
  {KEY_BACK,        SHORT            },
  {KEY_DOWN,        SHORT_REPEATED   }, 
  {KEY_VOLUME_UP,   SHORT            },
  {KEY_VOLUME_DOWN, SHORT            },
  {KEY_VOLUME_MUTE, SHORT            },
  
  };
  
  key_commands_short_TV = {
  
    // {KEY_STOP,        TV_????     },
    // {KEY_REWIND,      TV_????   },
    // {KEY_PLAY,        TV_????      },
    // {KEY_FORWARD,     TV_????  },
   
    {KEY_MENU,        TV_MENU       },
    {KEY_UP,          TV_UP         },
    {KEY_INFO,        TV_INFO       },
    
    {KEY_LEFT,        TV_LEFT       },
    {KEY_OK,          TV_SELECT     },
    {KEY_RIGHT,       TV_RIGHT      },

    {KEY_BACK,        TV_EXIT       },
    {KEY_DOWN,        TV_DOWN       }, 
    {KEY_SRC,         TV_OPTION     },
    
    {KEY_VOLUME_UP,   TV_VOL_PLUS   },
    {KEY_VOLUME_DOWN, TV_VOL_MINUS  },
    {KEY_VOLUME_MUTE, TV_VOL_MUTE   },

    // {KEY_CHANEL_UP,   APPLETV_NEXT      },
    // {KEY_CHANEL_DOWN, APPLETV_PREVIOUS  },
    // {KEY_CHANEL_LAST, ????              }, 

    // {KEY_RED,          ????             }, Set by default scene
    // {KEY_GREEN,        ????             }, Set by default scene
    // {KEY_YELLOW,       ????             }, Set by default scene
    // {KEY_BLUE,         ????             }, Set by default scene
  };
  
  key_commands_long_TV = {
  
  
  };

}

void scene_start_sequence_TV(void) {
  executeCommand(TV_POWER_ON);
}

void scene_end_sequence_TV(void) {

}

std::string scene_name_TV = "Watch TV";
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
