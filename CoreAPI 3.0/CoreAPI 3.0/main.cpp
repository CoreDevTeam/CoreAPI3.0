#include <iostream>
#include "Include/core_main_header.h"
/*
void core::CoreAPI::SetBGColor(byte Color)
{
     BGColor = Color*0x10;
}

void core::CoreAPI::SetFontColor(byte Color)
{
     FontColor = Color;
}
*/

int main()
{
     core::CoreAPI c = core::CoreAPI();
     core::TextElement txtmgr;

     txtmgr.width = 40;
     txtmgr.lines = 40;
     c.setColor(core::eColor::COLOR_BLACK,core::eColor::COLOR_WHITE);
     txtmgr.write(txtmgr,"test",true);

     c.Fill(core::eColor::COLOR_BLUE,true);
     std::cin.get();

     return 0;
}
