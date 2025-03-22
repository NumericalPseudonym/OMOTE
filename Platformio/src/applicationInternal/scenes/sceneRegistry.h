#pragma once

#include <string>
#include <vector>
#include "applicationInternal/keys.h"
#include "applicationInternal/gui/guiMemoryOptimizer.h"

typedef std::vector<std::string> t_gui_list;
typedef std::vector<std::string> t_scene_list;

typedef void (*scene_setKeys)(void);
typedef void (*scene_start_sequence)(void);
typedef void (*scene_end_sequence)(void);
typedef t_gui_list *gui_list;
typedef t_scene_list *scene_list;

// https://stackoverflow.com/questions/840501/how-do-function-pointers-in-c-work
struct scene_definition
{
  scene_setKeys this_scene_setKeys;
  scene_start_sequence this_scene_start_sequence;
  scene_end_sequence this_scene_end_sequence;
  key_repeatModes this_key_repeatModes;
  key_commands_short this_key_commands_short;
  key_commands_long this_key_commands_long;
  gui_list this_gui_list;
  uint16_t this_activate_scene_command;
};

extern std::map<std::string, scene_definition> registered_scenes;

void register_scene(
    std::string a_scene_name,
    scene_setKeys a_scene_setKeys,
    scene_start_sequence a_scene_start_sequence,
    scene_end_sequence a_scene_end_sequence,
    key_repeatModes a_key_repeatModes,
    key_commands_short a_key_commands_short,
    key_commands_long a_key_commands_long,
    gui_list a_gui_list = NULL,
    uint16_t a_activate_scene_command = 0);

bool sceneExists(std::string sceneName);
void scene_start_sequence_from_registry(std::string sceneName);
void scene_end_sequence_from_registry(std::string sceneName);
repeatModes get_key_repeatMode(std::string sceneName, char keyChar);
uint16_t get_command_short(std::string sceneName, char keyChar);
uint16_t get_command_long(std::string sceneName, char keyChar);
gui_list get_gui_list_withFallback(GUIlists gui_list);
gui_list get_gui_list_active_withFallback();
bool get_scene_has_gui_list(std::string sceneName);
uint16_t get_activate_scene_command(std::string sceneName);
scene_list get_scenes_on_sceneSelectionGUI();
void set_scenes_on_sceneSelectionGUI(t_scene_list a_scene_list);

// Off Button At Top Right
extern const char KEY_OFF;

// Start: First Row Of Buttons
extern const char KEY_STOP;
extern const char KEY_REWIND;
extern const char KEY_PLAY;
extern const char KEY_FORWARD;
// End: First Row Of Buttons

// Start: Midle Area Of Remote
// Top Row
extern const char KEY_MENU;
extern const char KEY_UP;
extern const char KEY_INFO;

// Middle Row
extern const char KEY_LEFT;
extern const char KEY_OK;
extern const char KEY_RIGHT;

// Bottom Row
extern const char KEY_BACK;
extern const char KEY_DOWN;
extern const char KEY_SRC;
// End: Midle Area Of Remote

// Start: Volume and Channel Area
extern const char KEY_VOLUME_UP;
extern const char KEY_VOLUME_DOWN;
extern const char KEY_VOLUME_MUTE;

extern const char KEY_CHANEL_UP;
extern const char KEY_CHANEL_DOWN;
extern const char KEY_CHANEL_LAST;
// End: Volume and Channel Area

// Start: Last Row Of Buttons
extern const char KEY_RED;
extern const char KEY_GREEN;
extern const char KEY_YELLOW;
extern const char KEY_BLUE;
// End: Last Row Of Buttons
