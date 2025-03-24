#include <map>
#include "scenes/scene_appleTV.h"
#include "applicationInternal/keys.h"
#include "applicationInternal/scenes/sceneRegistry.h"
#include "applicationInternal/hardware/hardwarePresenter.h"
// devices
#include "devices/TV/device_TV.h"
#include "devices/mediaPlayer/device_appleTV/device_appleTV.h"
#include "applicationInternal/commandHandler.h"
// guis
#include "devices/mediaPlayer/device_appleTV/gui_appleTV.h"

uint16_t SCENE_APPLETV      ; //"Scene_appleTV"
uint16_t SCENE_APPLETV_FORCE; //"Scene_appleTV_force"

std::map<char, repeatModes> key_repeatModes_appleTV;
std::map<char, uint16_t> key_commands_short_appleTV;
std::map<char, uint16_t> key_commands_long_appleTV;

void scene_setKeys_appleTV() {
  key_repeatModes_appleTV = {
    {KEY_STOP,        SHORT            },
    {KEY_REWIND,      SHORT_REPEATED   },
    {KEY_PLAY,        SHORT            },
    {KEY_FORWARD,     SHORT_REPEATED   },
   
    {KEY_MENU,        SHORT            },
    {KEY_UP,          SHORT_REPEATED   },
    {KEY_INFO,        SHORT            },
    
    {KEY_LEFT,        SHORT_REPEATED   },
    {KEY_OK,          SHORT            },
    {KEY_RIGHT,       SHORT_REPEATED   },

    // {KEY_BACK,        SHORT            },
    {KEY_DOWN,        SHORT_REPEATED   }, 
    // {KEY_SRC,         SHORT            }, Used by default scene
    
    // {KEY_VOLUME_UP,   SHORT            }, Set by default scene
    // {KEY_VOLUME_DOWN, SHORT            }, Set by default scene
    // {KEY_VOLUME_MUTE, SHORT            }, Set by default scene

    {KEY_CHANEL_UP,   SHORT            },
    {KEY_CHANEL_DOWN, SHORT            },
    // {KEY_CHANEL_LAST, SHORT            }, Not used

    // {KEY_RED,          SHORT           }, Set by default scene
    // {KEY_GREEN,        SHORT           }, Set by default scene
    // {KEY_YELLOW,       SHORT           }, Set by default scene
    // {KEY_BLUE,         SHORT           }, Set by default scene
    
  };
  
  key_commands_short_appleTV = {
    {KEY_STOP,        APPLETV_PAUSE     },
    {KEY_REWIND,      APPLETV_REVERSE   },
    {KEY_PLAY,        APPLETV_PLAY      },
    {KEY_FORWARD,     APPLETV_FOREWARD  },
   
    {KEY_MENU,        APPLETV_MENU      },
    {KEY_UP,          APPLETV_UP        },
    {KEY_INFO,        APPLETV_HOME      },
    
    {KEY_LEFT,        APPLETV_LEFT      },
    {KEY_OK,          APPLETV_OK        },
    {KEY_RIGHT,       APPLETV_RIGHT     },

    // {KEY_BACK,        ????              }, Not set
    {KEY_DOWN,        APPLETV_DOWN      }, 
    // {KEY_SRC,         ????              }, Used by default scene
    
    // {KEY_VOLUME_UP,   ????              }, Set by default scene
    // {KEY_VOLUME_DOWN, ????              }, Set by default scene
    // {KEY_VOLUME_MUTE, ????              }, Set by default scene

    {KEY_CHANEL_UP,   APPLETV_NEXT      },
    {KEY_CHANEL_DOWN, APPLETV_PREVIOUS  },
    // {KEY_CHANEL_LAST, ????              }, 

    // {KEY_RED,          ????             }, Set by default scene
    // {KEY_GREEN,        ????             }, Set by default scene
    // {KEY_YELLOW,       ????             }, Set by default scene
    // {KEY_BLUE,         ????             }, Set by default scene
  };
  
  key_commands_long_appleTV = {
  
  
  };

}

void scene_start_sequence_appleTV(void) {
  executeCommand(TV_POWER_ON);
  delay(500);
  executeCommand(APPLETV_POWER_ON);
  delay(500);
  executeCommand(TV_INPUT_HDMI_2);
  delay(2000);
  executeCommand(APPLETV_HOME);
  delay(3000);
}

void scene_end_sequence_appleTV(void) {
  executeCommand(APPLETV_HOME);
}

std::string scene_name_appleTV = "Apple TV";
t_gui_list scene_appleTV_gui_list = {tabName_appleTV};

void register_scene_appleTV(void) {
  register_command(&SCENE_APPLETV,       makeCommandData(SCENE, {scene_name_appleTV}));
  register_command(&SCENE_APPLETV_FORCE, makeCommandData(SCENE, {scene_name_appleTV, "FORCE"}));

  register_scene(
    scene_name_appleTV,
    & scene_setKeys_appleTV,
    & scene_start_sequence_appleTV,
    & scene_end_sequence_appleTV,
    & key_repeatModes_appleTV,
    & key_commands_short_appleTV,
    & key_commands_long_appleTV,
    & scene_appleTV_gui_list,
    SCENE_APPLETV);
}