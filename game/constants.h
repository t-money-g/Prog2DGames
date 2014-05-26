// Programming 2D Games
// Copyright (c) 2011 by: 
// Charles Kelly
// Game Engine constants.h v3.4
// Last modification: Apr-18-2014

//Extended for Discordia v.01
#pragma once
#ifndef _CONSTANTS_H            // Prevent multiple definitions if this 
#define _CONSTANTS_H            // file is included in more than one place
#define WIN32_LEAN_AND_MEAN

#include <windows.h>

//=============================================================================
//                  Constants
//=============================================================================

// window
const char CLASS_NAME[] = "Discordia";
const char GAME_TITLE[] = "Discordia v0.1";
const bool FULLSCREEN = false;              // windowed or fullscreen
// a 16:10 resolution seems to be OK see: http:///www.bit-tech.net/blog/2012/10/22/16-10-vs-16-9-the-monitor-aspect-ratio/
const UINT GAME_WIDTH =  960;               // width of game in pixels
const UINT GAME_HEIGHT = 600;               // height of game in pixels


 
// game
const bool VSYNC = false;                   // true locks display to vertical sync rate
const float FRAME_RATE = 240.0f;            // the target frame rate (frames/sec), ignored if VSYNC is true
const float MIN_FRAME_RATE = 10.0f;             // the minimum frame rate
const float MIN_FRAME_TIME = 1.0f/FRAME_RATE;   // minimum desired time for 1 frame
const float MAX_FRAME_TIME = 1.0f/MIN_FRAME_RATE; // maximum time used in calculations
const double PI = 3.14159265;

// graphic images
const char MENU_IMAGE[] =    "pictures\\fullDemoRender_Green.png";      // menu texture
// TODO currently image only has one image of the player
// 
const char PLAYER_IMAGE[] =  "pictures\\idle__000.png";
const char PLAYER_IMAGE_SWING_SWORD[] = "pictures\\swing__007.png";
const char GROUND_IMAGE[] = "tiles\\ground.png";


// audio files required by audio.cpp
// WAVE_BANK must be location of .xwb file.
const char WAVE_BANK[]  = "";
// SOUND_BANK must be location of .xsb file.
const char SOUND_BANK[] = "";
// XGS_FILE must be location of .xgs file.
const char XGS_FILE[]   = "";

// audio cues

// key mappings
// In this game simple constants are used for key mappings. If variables were used
// it would be possible to save and restore key mappings from a data file.
const UCHAR CONSOLE_KEY  = '`';         // ` key
const UCHAR ESC_KEY      = VK_ESCAPE;   // escape key
const UCHAR ALT_KEY      = VK_MENU;     // Alt key
const UCHAR ENTER_KEY    = VK_RETURN;   // Enter key
const UCHAR PLAYER_LEFT	 = 'A';
const UCHAR PLAYER_RIGHT = 'D';
const UCHAR PLAYER_UP	 = 'W';
const UCHAR PLAYER_DOWN  = 'S';
const UCHAR UP =  VK_UP;
const UCHAR DOWN = VK_DOWN;
const UCHAR LEFT = VK_LEFT;
const UCHAR RIGHT = VK_RIGHT;

//=============================================================================
// Function templates for safely dealing with pointer referenced items.
// The functions defined by these templates may be called using a normal
// function call syntax. The compiler will create a function that replaces T
// with the type of the calling parameter.
//=============================================================================
// Safely release pointer referenced item
template <typename T>
inline void safeRelease(T& ptr)
{
    if (ptr)
    { 
        ptr->Release(); 
        ptr = NULL;
    }
}
#define SAFE_RELEASE safeRelease            // for backward compatiblility

// Safely delete pointer referenced item
template <typename T>
inline void safeDelete(T& ptr)
{
    if (ptr)
    { 
        delete ptr; 
        ptr = NULL;
    }
}
#define SAFE_DELETE safeDelete              // for backward compatiblility

// Safely delete pointer referenced array
template <typename T>
inline void safeDeleteArray(T& ptr)
{
    if (ptr)
    { 
        delete[] ptr; 
        ptr = NULL;
    }
}
#define SAFE_DELETE_ARRAY safeDeleteArray   // for backward compatiblility

// Safely call onLostDevice
template <typename T>
inline void safeOnLostDevice(T& ptr)
{
    if (ptr)
        ptr->onLostDevice(); 
}
#define SAFE_ON_LOST_DEVICE safeOnLostDevice    // for backward compatiblility

// Safely call onResetDevice
template <typename T>
inline void safeOnResetDevice(T& ptr)
{
    if (ptr)
        ptr->onResetDevice(); 
}
#define SAFE_ON_RESET_DEVICE safeOnResetDevice  // for backward compatiblility

#endif
