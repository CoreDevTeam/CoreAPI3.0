#define _WIN32_WINNT 0x0500

#include "core_main_header.h"
// Changelog (Luis#1#): Weitermachen ...
//

void core::CoreAPI::setConsoleCaption(std::string ConsoleCaption)
{
    SetConsoleTitleA(ConsoleCaption.c_str());
}
void core::CoreAPI::showCursor(bool bVisible)
{
    static HANDLE		hOut;
    static BOOL		firstTime = TRUE;
    CONSOLE_CURSOR_INFO 	cursorInfo;

    if( firstTime ) {

        hOut		= GetStdHandle( STD_OUTPUT_HANDLE );
        firstTime	= FALSE;

    }
    cursorInfo.dwSize	= 10;
    cursorInfo.bVisible 	= bVisible;
    SetConsoleCursorInfo( hOut,&cursorInfo );
}
void core::CoreAPI::SaveCursorPos()
{
    _CONSOLE_SCREEN_BUFFER_INFO info;
    GetConsoleScreenBufferInfo(core::CoreAPI::coreDevice,&info);
    CursorPos = info.dwCursorPosition;
}
void core::CoreAPI::setCursorPosition(COORD coord)
{
    SetConsoleCursorPosition(core::CoreAPI::coreDevice,coord);
}
void core::CoreAPI::setCursorPosition(short2D PosY,short2D PosX)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD PlaceCursorHere;
    PlaceCursorHere.X = PosX;
    PlaceCursorHere.Y = PosY;
    SetConsoleCursorPosition(hConsole, PlaceCursorHere);
}
void core::CoreAPI::setScreenSize(short2D ResY,short2D ResX,short2D PosY,short2D PosX)
{
    HANDLE hConsoleOutput;
    COORD coord;
    CONSOLE_SCREEN_BUFFER_INFO  ConsoleInfo;
    HWND console = GetConsoleWindow();

    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(hConsoleOutput, &ConsoleInfo);
    coord.X = PosX;
    coord.Y = PosY;
    SetConsoleScreenBufferSize(hConsoleOutput, coord);

    MoveWindow(console, 20, 20, ResX, ResY, TRUE);
}
core::TextElement::TextElement()
{
    core::TextElement::debug = false;
    if(core::TextElement::debug) {
        std::cout << "namespace core{} core::TextElement::TextElement() -> Ctor enabled" << std::endl;
    }
}
void core::TextElement::write(coreTEString Text,bool show)
{
    if(show) {
        core::CoreAPI cu;
        cu.updateColor();
        std::cout << Text;
    }
}
void core::TextElement::writeFromVector(std::vector<coreTEString> &content)
{
    for(unsigned int i = 0; i < content.size(); i++ ) {
        std::cout << content[i] << std::endl;
    }
}
core::CoreAPI::CoreAPI()
{
    coreDevice = GetStdHandle(STD_OUTPUT_HANDLE);
}
core::CoreAPI::CoreAPI(short2D ResY,short2D ResX,short2D PosX,short2D PosY)
{
    core::CoreAPI c_assert_cont;
    c_assert_cont.setScreenSize(ResY,ResX,PosY,PosX);
}
core::CoreAPI::CoreAPI(short2D ResY,short2D ResX,short2D PosX,short2D PosY,std::string ConsoleCaption)
{
    core::CoreAPI c_assert_cont;
    c_assert_cont.setScreenSize(ResY,ResX,PosY,PosX);
    c_assert_cont.setConsoleCaption(ConsoleCaption);
}
core::CoreAPI::CoreAPI(short2D ResY,short2D ResX,short2D PosX,short2D PosY,std::string ConsoleCaption,bool bVisible)
{
    core::CoreAPI c_assert_cont;
    c_assert_cont.setScreenSize(ResY,ResX,PosY,PosX);
    c_assert_cont.setConsoleCaption(ConsoleCaption);
    c_assert_cont.showCursor(bVisible);
}
void core::CoreAPI::setColor(core::eColor coreFGColor, core::eColor coreBGColor)
{
    int _FGcoreCOLOR,_BGcoreCOLOR;
    switch (coreFGColor) {
    case COLOR_BLACK:
        _FGcoreCOLOR = 0x0;
        break;
    case COLOR_DARKBLUE:
        _FGcoreCOLOR = 0x1;
        break;
    case COLOR_DARKGREEN:
        _FGcoreCOLOR = 0x2;
        break;
    case COLOR_DARKTURK:
        _FGcoreCOLOR = 0x3;
        break;
    case COLOR_DARKRED:
        _FGcoreCOLOR = 0x4;
        break;
    case COLOR_LILA:
        _FGcoreCOLOR = 0x5;
        break;
    case COLOR_BROWN:
        _FGcoreCOLOR = 0x6;
        break;
    case COLOR_GREY:
        _FGcoreCOLOR = 0x7;
        break;
    case COLOR_DARKGREY:
        _FGcoreCOLOR = 0x8;
        break;
    case COLOR_BLUE:
        _FGcoreCOLOR = 0x9;
        break;
    case COLOR_GREEN:
        _FGcoreCOLOR = 0xA;
        break;
    case COLOR_TURK:
        _FGcoreCOLOR = 0xB;
        break;
    case COLOR_RED:
        _FGcoreCOLOR = 0xC;
        break;
    case COLOR_PINK:
        _FGcoreCOLOR = 0xD;
        break;
    case COLOR_YELLOW:
        _FGcoreCOLOR = 0xE;
        break;
    case COLOR_WHITE:
        _FGcoreCOLOR = 0xF;
        break;
    }
    switch (coreBGColor) {
    case COLOR_BLACK:
        _BGcoreCOLOR = 0x0;
        break;
    case COLOR_DARKBLUE:
        _BGcoreCOLOR = 0x1;
        break;
    case COLOR_DARKGREEN:
        _BGcoreCOLOR = 0x2;
        break;
    case COLOR_DARKTURK:
        _BGcoreCOLOR = 0x3;
        break;
    case COLOR_DARKRED:
        _BGcoreCOLOR = 0x4;
        break;
    case COLOR_LILA:
        _BGcoreCOLOR = 0x5;
        break;
    case COLOR_BROWN:
        _BGcoreCOLOR = 0x6;
        break;
    case COLOR_GREY:
        _BGcoreCOLOR = 0x7;
        break;
    case COLOR_DARKGREY:
        _BGcoreCOLOR = 0x8;
        break;
    case COLOR_BLUE:
        _BGcoreCOLOR = 0x9;
        break;
    case COLOR_GREEN:
        _BGcoreCOLOR = 0xA;
        break;
    case COLOR_TURK:
        _BGcoreCOLOR = 0xB;
        break;
    case COLOR_RED:
        _BGcoreCOLOR = 0xC;
        break;
    case COLOR_PINK:
        _BGcoreCOLOR = 0xD;
        break;
    case COLOR_YELLOW:
        _BGcoreCOLOR = 0xE;
        break;
    case COLOR_WHITE:
        _BGcoreCOLOR = 0xF;
        break;
    }

    core::CoreAPI::BGColor = _BGcoreCOLOR*0x10;
    core::CoreAPI::FGColor = _FGcoreCOLOR;
    SetConsoleTextAttribute(coreDevice,core::CoreAPI::FGColor | core::CoreAPI::BGColor);
}
void core::CoreAPI::updateColor()
{
    SetConsoleTextAttribute(coreDevice,core::CoreAPI::FGColor | core::CoreAPI::BGColor);
}
void core::CoreAPI::initTextElement(core::TextElement txtElm)
{
    core::CoreAPI::TextElements.push_back(txtElm);
}
void core::CoreAPI::showTextElementContent(core::TextElement txtElm)
{
    std::cout << "ID: "<<txtElm.ID << std::endl;
    std::cout << "Text: "<<txtElm.Text << std::endl;
    std::cout << "Width: "<<txtElm.width << std::endl;
    std::cout << "Lines: "<< txtElm.lines << std::endl;
}
void core::CoreAPI::draw(core::TextElement txtElm)
{
    if (txtElm.Text.size() < txtElm.width) {
        for(unsigned int i = 0; i < txtElm.Text.size(); i++) {
            std::cout << txtElm.Text[i];
        }
    } else {
        for(unsigned int i = 0; i < txtElm.width; i++) {
            std::cout << txtElm.Text[i];
        }
    }
}
void core::CoreAPI::clear()
{
    DWORD n,size;
    COORD coord = {0};
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    HANDLE h = GetStdHandle ( STD_OUTPUT_HANDLE );

    GetConsoleScreenBufferInfo ( h, &csbi );

    size = csbi.dwSize.X * csbi.dwSize.Y;

    FillConsoleOutputCharacter ( h, TEXT ( ' ' ), size, coord, &n );
    GetConsoleScreenBufferInfo ( h, &csbi );
    FillConsoleOutputAttribute ( h, csbi.wAttributes, size, coord, &n );

    SetConsoleCursorPosition ( h, coord );

}
void core::CoreAPI::setBackgroundColor(core::eColor coreBGColor)
{
    int _BGcoreCOLOR;

    switch (coreBGColor) {
    case COLOR_BLACK:
        _BGcoreCOLOR = 0x0;
        break;
    case COLOR_DARKBLUE:
        _BGcoreCOLOR = 0x1;
        break;
    case COLOR_DARKGREEN:
        _BGcoreCOLOR = 0x2;
        break;
    case COLOR_DARKTURK:
        _BGcoreCOLOR = 0x3;
        break;
    case COLOR_DARKRED:
        _BGcoreCOLOR = 0x4;
        break;
    case COLOR_LILA:
        _BGcoreCOLOR = 0x5;
        break;
    case COLOR_BROWN:
        _BGcoreCOLOR = 0x6;
        break;
    case COLOR_GREY:
        _BGcoreCOLOR = 0x7;
        break;
    case COLOR_DARKGREY:
        _BGcoreCOLOR = 0x8;
        break;
    case COLOR_BLUE:
        _BGcoreCOLOR = 0x9;
        break;
    case COLOR_GREEN:
        _BGcoreCOLOR = 0xA;
        break;
    case COLOR_TURK:
        _BGcoreCOLOR = 0xB;
        break;
    case COLOR_RED:
        _BGcoreCOLOR = 0xC;
        break;
    case COLOR_PINK:
        _BGcoreCOLOR = 0xD;
        break;
    case COLOR_YELLOW:
        _BGcoreCOLOR = 0xE;
        break;
    case COLOR_WHITE:
        _BGcoreCOLOR = 0xF;
        break;
    }

    core::CoreAPI::BGColor = _BGcoreCOLOR;
    SetConsoleTextAttribute(coreDevice,core::CoreAPI::FGColor | core::CoreAPI::BGColor);
}
void core::CoreAPI::setForegroundColor(core::eColor coreFGColor)
{
    int _FGcoreCOLOR;
    switch (coreFGColor) {
    case COLOR_BLACK:
        _FGcoreCOLOR = 0x0;
        break;
    case COLOR_DARKBLUE:
        _FGcoreCOLOR = 0x1;
        break;
    case COLOR_DARKGREEN:
        _FGcoreCOLOR = 0x2;
        break;
    case COLOR_DARKTURK:
        _FGcoreCOLOR = 0x3;
        break;
    case COLOR_DARKRED:
        _FGcoreCOLOR = 0x4;
        break;
    case COLOR_LILA:
        _FGcoreCOLOR = 0x5;
        break;
    case COLOR_BROWN:
        _FGcoreCOLOR = 0x6;
        break;
    case COLOR_GREY:
        _FGcoreCOLOR = 0x7;
        break;
    case COLOR_DARKGREY:
        _FGcoreCOLOR = 0x8;
        break;
    case COLOR_BLUE:
        _FGcoreCOLOR = 0x9;
        break;
    case COLOR_GREEN:
        _FGcoreCOLOR = 0xA;
        break;
    case COLOR_TURK:
        _FGcoreCOLOR = 0xB;
        break;
    case COLOR_RED:
        _FGcoreCOLOR = 0xC;
        break;
    case COLOR_PINK:
        _FGcoreCOLOR = 0xD;
        break;
    case COLOR_YELLOW:
        _FGcoreCOLOR = 0xE;
        break;
    case COLOR_WHITE:
        _FGcoreCOLOR = 0xF;
        break;
    }

    core::CoreAPI::FGColor = _FGcoreCOLOR;
    SetConsoleTextAttribute(coreDevice,core::CoreAPI::FGColor | core::CoreAPI::BGColor);
}
SMALL_RECT core::CoreAPI::getRect()
{
    _CONSOLE_SCREEN_BUFFER_INFO info;
    GetConsoleScreenBufferInfo(core::CoreAPI::coreDevice,&info);
    return info.srWindow;
}
void core::CoreAPI::Fill(core::eColor coreColor,bool bOnlyVisiblePart)
{
    core::CoreAPI cc;
    cc.setBackgroundColor(coreColor);
    SMALL_RECT rect = cc.getRect();
    if (bOnlyVisiblePart) {
        for (int y = 0; y<(rect.Bottom+rect.Top)+1; y++)
            for (int x = 0; x<(rect.Left+rect.Right)+1; x++)
                printf(" ");
    }
    COORD coord = {0,0};
    SetConsoleCursorPosition(core::CoreAPI::coreDevice,coord);
    SetConsoleTextAttribute(core::CoreAPI::coreDevice,BGColor);
}
