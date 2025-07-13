#pragma once
//rVector2 and Vector2 (raylib) have the same fields
#include <inttypes.h>

typedef struct{
    float x;                // Vector x component
    float y;                // Vector y component
} rVector2;

// Color, 4 components, R8G8B8A8 (32bit)
typedef struct {
    unsigned char r;        // Color red value
    unsigned char g;        // Color green value
    unsigned char b;        // Color blue value
    unsigned char a;        // Color alpha value
} rColor;


const uint16_t rKEY_NULL = 0;        // Key: NULL, used for no key pressed
const uint16_t rKEY_APOSTROPHE = 39;       // Key: '
const uint16_t rKEY_COMMA = 44;       // Key: ,
const uint16_t rKEY_MINUS = 45;       // Key: -
const uint16_t rKEY_PERIOD = 46;       // Key: .
const uint16_t rKEY_SLASH = 47;       // Key: /
const uint16_t rKEY_ZERO = 48;       // Key: 0
const uint16_t rKEY_ONE = 49;       // Key: 1
const uint16_t rKEY_TWO = 50;       // Key: 2
const uint16_t rKEY_THREE = 51;       // Key: 3
const uint16_t rKEY_FOUR = 52;       // Key: 4
const uint16_t rKEY_FIVE = 53;       // Key: 5
const uint16_t rKEY_SIX = 54;       // Key: 6
const uint16_t rKEY_SEVEN = 55;       // Key: 7
const uint16_t rKEY_EIGHT = 56;       // Key: 8
const uint16_t rKEY_NINE = 57;       // Key: 9
const uint16_t rKEY_SEMICOLON = 59;       // Key: ;
const uint16_t rKEY_EQUAL = 61;       // Key: =
const uint16_t rKEY_A = 65;       // Key: A | a
const uint16_t rKEY_B = 66;       // Key: B | b
const uint16_t rKEY_C = 67;       // Key: C | c
const uint16_t rKEY_D = 68;       // Key: D | d
const uint16_t rKEY_E = 69;       // Key: E | e
const uint16_t rKEY_F = 70;       // Key: F | f
const uint16_t rKEY_G = 71;       // Key: G | g
const uint16_t rKEY_H = 72;       // Key: H | h
const uint16_t rKEY_I = 73;       // Key: I | i
const uint16_t rKEY_J = 74;       // Key: J | j
const uint16_t rKEY_K = 75;       // Key: K | k
const uint16_t rKEY_L = 76;       // Key: L | l
const uint16_t rKEY_M = 77;       // Key: M | m
const uint16_t rKEY_N = 78;       // Key: N | n
const uint16_t rKEY_O = 79;       // Key: O | o
const uint16_t rKEY_P = 80;       // Key: P | p
const uint16_t rKEY_Q = 81;       // Key: Q | q
const uint16_t rKEY_R = 82;       // Key: R | r
const uint16_t rKEY_S = 83;       // Key: S | s
const uint16_t rKEY_T = 84;       // Key: T | t
const uint16_t rKEY_U = 85;       // Key: U | u
const uint16_t rKEY_V = 86;       // Key: V | v
const uint16_t rKEY_W = 87;       // Key: W | w
const uint16_t rKEY_X = 88;       // Key: X | x
const uint16_t rKEY_Y = 89;       // Key: Y | y
const uint16_t rKEY_Z = 90;       // Key: Z | z
const uint16_t rKEY_LEFT_BRACKET = 91;       // Key: [
const uint16_t rKEY_BACKSLASH = 92;       // Key: '\'
const uint16_t rKEY_RIGHT_BRACKET = 93;       // Key: ]
const uint16_t rKEY_GRAVE = 96;       // Key: `
    // Function keys
const uint16_t rKEY_SPACE = 32;       // Key: Space
const uint16_t rKEY_ESCAPE = 256;      // Key: Esc
const uint16_t rKEY_ENTER = 257;      // Key: Enter
const uint16_t rKEY_TAB = 258;      // Key: Tab
const uint16_t rKEY_BACKSPACE = 259;      // Key: Backspace
const uint16_t rKEY_INSERT = 260;      // Key: Ins
const uint16_t rKEY_DELETE = 261;      // Key: Del
const uint16_t rKEY_RIGHT = 262;      // Key: Cursor right
const uint16_t rKEY_LEFT = 263;      // Key: Cursor left
const uint16_t rKEY_DOWN = 264;      // Key: Cursor down
const uint16_t rKEY_UP = 265;      // Key: Cursor up
const uint16_t rKEY_PAGE_UP = 266;      // Key: Page up
const uint16_t rKEY_PAGE_DOWN = 267;      // Key: Page down
const uint16_t rKEY_HOME = 268;      // Key: Home
const uint16_t rKEY_END = 269;      // Key: End
const uint16_t rKEY_CAPS_LOCK = 280;      // Key: Caps lock
const uint16_t rKEY_SCROLL_LOCK = 281;      // Key: Scroll down
const uint16_t rKEY_NUM_LOCK = 282;      // Key: Num lock
const uint16_t rKEY_PRINT_SCREEN = 283;      // Key: Print screen
const uint16_t rKEY_PAUSE = 284;      // Key: Pause
const uint16_t rKEY_F1 = 290;      // Key: F1
const uint16_t rKEY_F2 = 291;      // Key: F2
const uint16_t rKEY_F3 = 292;      // Key: F3
const uint16_t rKEY_F4 = 293;      // Key: F4
const uint16_t rKEY_F5 = 294;      // Key: F5
const uint16_t rKEY_F6 = 295;      // Key: F6
const uint16_t rKEY_F7 = 296;      // Key: F7
const uint16_t rKEY_F8 = 297;      // Key: F8
const uint16_t rKEY_F9 = 298;      // Key: F9
const uint16_t rKEY_F10 = 299;      // Key: F10
const uint16_t rKEY_F11 = 300;      // Key: F11
const uint16_t rKEY_F12 = 301;      // Key: F12
const uint16_t rKEY_LEFT_SHIFT = 340;      // Key: Shift left
const uint16_t rKEY_LEFT_CONTROL = 341;      // Key: Control left
const uint16_t rKEY_LEFT_ALT = 342;      // Key: Alt left
const uint16_t rKEY_LEFT_SUPER = 343;      // Key: Super left
const uint16_t rKEY_RIGHT_SHIFT = 344;      // Key: Shift right
const uint16_t rKEY_RIGHT_CONTROL = 345;      // Key: Control right
const uint16_t rKEY_RIGHT_ALT = 346;      // Key: Alt right
const uint16_t rKEY_RIGHT_SUPER = 347;      // Key: Super right
const uint16_t rKEY_KB_MENU = 348;      // Key: KB menu
    // Keypad keys
const uint16_t rKEY_KP_0 = 320;      // Key: Keypad 0
const uint16_t rKEY_KP_1 = 321;      // Key: Keypad 1
const uint16_t rKEY_KP_2 = 322;      // Key: Keypad 2
const uint16_t rKEY_KP_3 = 323;      // Key: Keypad 3
const uint16_t rKEY_KP_4 = 324;      // Key: Keypad 4
const uint16_t rKEY_KP_5 = 325;      // Key: Keypad 5
const uint16_t rKEY_KP_6 = 326;      // Key: Keypad 6
const uint16_t rKEY_KP_7 = 327;      // Key: Keypad 7
const uint16_t rKEY_KP_8 = 328;      // Key: Keypad 8
const uint16_t rKEY_KP_9 = 329;      // Key: Keypad 9
const uint16_t rKEY_KP_DECIMAL = 330;      // Key: Keypad .
const uint16_t rKEY_KP_DIVIDE = 331;      // Key: Keypad /
const uint16_t rKEY_KP_MULTIPLY = 332;      // Key: Keypad *
const uint16_t rKEY_KP_SUBTRACT = 333;      // Key: Keypad -
const uint16_t rKEY_KP_ADD = 334;      // Key: Keypad +
const uint16_t rKEY_KP_ENTER = 335;      // Key: Keypad Enter
const uint16_t rKEY_KP_EQUAL = 336;      // Key: Keypad =
    // Android key buttons
const uint16_t rKEY_BACK = 4;        // Key: Android back button
const uint16_t rKEY_MENU = 82;       // Key: Android menu button
const uint16_t rKEY_VOLUME_UP = 24;       // Key: Android volume up button
const uint16_t rKEY_VOLUME_DOWN = 25;        // Key: Android volume down button

