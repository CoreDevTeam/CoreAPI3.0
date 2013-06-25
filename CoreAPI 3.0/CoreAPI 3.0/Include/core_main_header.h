#ifndef CORE_HEADER_H_INCLUDED
#define CORE_HEADER_H_INCLUDED

#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>
#include <vector>
//------------------------------------------------//
// CoreAPI Version 3.0                            //
// + ADDED | - REMOVED | * CHANGED                //
//------------------------------------------------//
/// 20.3.2013
// + CoreAPI Ctor
// + void setColor()
// + void updateColor()
// * cleaned up Code
// + class TextElement
// + initTextElement
// + showTextElementContent
// + draw
/// 26.4.2013
// + Caption func
// + extended constructor
namespace core {

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

enum eColor {
    COLOR_BLACK,
    COLOR_DARKBLUE,
    COLOR_DARKGREEN,
    COLOR_DARKTURK,
    COLOR_DARKRED,
    COLOR_LILA,
    COLOR_BROWN,
    COLOR_GREY,
    COLOR_DARKGREY,
    COLOR_BLUE,
    COLOR_GREEN,
    COLOR_TURK,
    COLOR_RED,
    COLOR_PINK,
    COLOR_YELLOW,
    COLOR_WHITE
};

class TextElement {
private :
    typedef std::string coreTEString;
    bool debug;
public:
    coreTEString Text;
    int ID;
    int width,lines;
public :
    TextElement();
    void write(coreTEString Text,bool show);
    void writeFromVector(std::vector<coreTEString> &content);

};
class CoreAPI : public TextElement {
private :
    typedef int iColor;
    typedef short short2D;
    short2D ResY,ResX,PosY,PosX;
    std::string ConsoleCaption;
    eColor coreBGColor,coreFGColor,coreColor;
    iColor FGColor,BGColor;
    HANDLE coreDevice;
    std::vector<TextElement> TextElements;
    bool bVisible,bOnlyVisiblePart;
    COORD CursorPos;
public :
///CoreAPI Standard
    CoreAPI();
    CoreAPI(short2D ResY,short2D ResX,short2D PosX,short2D PosY);
    CoreAPI(short2D ResY,short2D ResX,short2D PosX,short2D PosY,std::string ConsoleCaption);
    CoreAPI(short2D ResY,short2D ResX,short2D PosX,short2D PosY,std::string ConsoleCaption,bool bVisible);
    SMALL_RECT getRect();
    void clear();
    void setConsoleCaption(std::string ConsoleCaption);
    void setCursorPosition(short2D PosY,short2D PosX);
    void setCursorPosition(COORD coord);
    void setScreenSize(short2D ResY,short2D ResX,short2D PosY,short2D PosX);
    void showCursor(bool bVisible);
    void SaveCursorPos();
/// CoreAPI Standard Color Expansion
    void setColor(core::eColor coreFGColor, core::eColor coreBGColor);
    void setBackgroundColor(core::eColor coreBGColor);
    void setForegroundColor(core::eColor coreFGColor);
    void Fill(core::eColor coreColor,bool bOnlyVisiblePart);
    void updateColor();
/// Textelement expansion
    void initTextElement(core::TextElement txtElm);
    void showTextElementContent(core::TextElement txtElm);
    void draw(core::TextElement txtElm);
/// Construction expansion
///

};

}
#endif // CORE_HEADER_H_INCLUDED
