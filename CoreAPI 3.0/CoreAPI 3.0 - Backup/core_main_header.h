#ifndef CORE_MAIN_HEADER_H_INCLUDED
#define CORE_MAIN_HEADER_H_INCLUDED

/*
CoreAPI 2.1
By 7xCore
coresupportteam@live.de
luis-e@live.de
Steam: omg_fail
http://www.coreengine.de.vu/
*/
#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>
#include <vector>

namespace core {

enum TEXT_ALIGN {
     ALIGN_LEFT,
     ALIGN_CENTER,
     ALIGN_RIGHT,
     caption
};

enum LineDirec {
     vertical,
     horizontal
};

namespace key {
enum MOUSE_BUTTON {
     KEY_M_RIGHT,
     KEY_M_LEFT,
     KEY_M_MIDDLE
};
}

enum WindowType {
     SOILD_BLOCK,
     THIN_LINE,
     CUSTOM,
     DOUBLE_LINE,
     HIGHPOINTED_BLOCK,
     MEDIUMPOINTED_BLOCK,
     LOWPOINTED_BLOCK,
     HALF_BLOCK

};

struct MenuItem {
     const char *Caption;
     TEXT_ALIGN text_align;
     byte color;
};

namespace color {
static byte COLOR_BLACK			=0x0;
static byte COLOR_DARKBLUE			=0x1;
static byte COLOR_DARKGREEN		=0x2;
static byte COLOR_DARKTURK			=0x3;
static byte COLOR_DARKRED			=0x4;
static byte COLOR_LILA				=0x5;
static byte COLOR_BROWN			=0x6;
static byte COLOR_GREY				=0x7;
static byte COLOR_DARKGREY			=0x8;
static byte COLOR_BLUE				=0x9;
static byte COLOR_GREEN			=0xA;
static byte COLOR_TURK				=0xB;
static byte COLOR_RED				=0xC;
static byte COLOR_PINK				=0xD;
static byte COLOR_YELLOW			=0xE;
static byte COLOR_WHITE			=0xF;
}

namespace specialChar {
const unsigned char AE = static_cast<unsigned char>(142);
const unsigned char ae = static_cast<unsigned char>(132);
const unsigned char OE = static_cast<unsigned char>(153);
const unsigned char oe = static_cast<unsigned char>(148);
const unsigned char UE = static_cast<unsigned char>(154);
const unsigned char ue = static_cast<unsigned char>(129);
const unsigned char ss = static_cast<unsigned char>(225);
}

namespace ascII {
const unsigned char flash = static_cast<unsigned char>(159);
const unsigned char rights = static_cast<unsigned char>(196);
const unsigned char half = static_cast<unsigned char>(171);
const unsigned char low_pointed_block = static_cast<unsigned char>(176);
const unsigned char medium_pointed_block = static_cast<unsigned char>(177);
const unsigned char high_pointed_block = static_cast<unsigned char>(178);
const unsigned char soild_block = static_cast<unsigned char>(219);
const unsigned char half_block_down = static_cast<unsigned char>(220);
const unsigned char half_block_up = static_cast<unsigned char>(223);
const unsigned char half_block_left = static_cast<unsigned char>(221);
const unsigned char half_block_right = static_cast<unsigned char>(222);
const unsigned char half_block_middle = static_cast<unsigned char>(254);
}

class CoreAPI {

private :

     TEXT_ALIGN text_align;
     HANDLE hConsole;
     byte FontColor;
     byte BGColor;
     HANDLE hStdInput,hStdOutput,hEvent;
     INPUT_RECORD ir[128];
     DWORD nRead;
     COORD xy;
     UINT i;
     COORD CursorPos;
     short ScreenPosX;
     short ScreenPosY;
     short ScreenW;
     short ScreenH;
     const char* cConsolecaption;
     bool bShowCursor;

public :

     CoreAPI();
     CoreAPI(short ScreenPosX, short ScreenPosY,short ScreenW,short ScreenH,const char* cConsolecaption,bool bShowCursor);

     void SaveCursorPos(void);
     void GotoCursorPos(COORD coord);
     SMALL_RECT GetRect();
     void setCursorPos(short Cursorx,short Cursory);

     void clear();

     void Write(std::string Text);
     void WriteLn(char *Text);

     void SetFontColor(byte Color);
     void SetBGColor(byte Color);
     void Fill(byte Color,bool OnlyVisible);
     void ColorUpdate();

     void DrawWin(short wx, short wy, int ww, int wh,byte wBorderColor,int size__,std::vector<core::MenuItem> Items);
     void DrawCenterWin(int wy, int ww, int wh,byte wBorderColor,int wnItems,std::vector<core::MenuItem> Items);
     void DrawLine(LineDirec Direction,char CHAR,byte color,int len);
     void DrawCenterBox(int y, int w, int h,byte BorderColor,int size__,std::vector<core::MenuItem> Items);
     void DrawCustomWindow(const char* Char, short cx, short cy, int cw, int ch,byte cBorderColor,int size__,std::vector<core::MenuItem> Items);
     void DrawCustomCenterWindow(const char* Char,int cy, int cw, int ch,byte cBorderColor,int size__,std::vector<core::MenuItem> Items);
     void Draw_unexpected_error_msg();
     void Draw_costum_error_msg(const char* errortext);
     void Draw_costum_warning_msg(const char* warningtext);
     void Draw_costum_info_msg(const char* infotext);
     void DrawBox(short x, short y, int w, int h,byte BorderColor,int size__,std::vector<core::MenuItem> Items);

     void CreateMouseButtonArea(int y_begin , int y_end, int x_begin, int x_end, core::key::MOUSE_BUTTON mb, void (*action)());

     void show_cursor(bool bShowCursor);
     void setScreenSize(int ScreenWidth,int ScreenHeigth,int ScreenCordx,int ScreenCordy);
     void setConsolecaption(const char* Consolecaption);

     void Loader(int segements,int time,int Size);

     void DrawWindow(core::WindowType WinStyle,short x, short y, int w, int h,byte BorderColor,int size__,std::vector<core::MenuItem> Items);
     void DrawWindow(core::WindowType WinStyle,short x, short y, int w, int h,byte BorderColor,int size__,std::vector<core::MenuItem> Items,char custom_border);

};//class CoreAPI ends

}//namespace core ends



#endif // CORE_MAIN_HEADER_H_INCLUDED
