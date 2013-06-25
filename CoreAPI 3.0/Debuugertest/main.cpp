#include <iostream>

enum COLOR {
black,
red,
blue
};

namespace core{
class CoreAPI{
private:
COLOR color;

public:
void setBGColor(COLOR color);
int getBGColor();
};
}

void core::CoreAPI::setBGColor(COLOR color){
    switch (color)
    {
        case black : std::cout << "black" << std::endl; break;
        case red: std::cout << "red" << std::endl; break;
    }
};
int core::CoreAPI::getBGColor(){
    return color;
}
int main()
{
    COLOR color;
    core::CoreAPI a;
    a.setBGColor(color = red);
    std::cout << a.getBGColor() << std::endl;
    return 0;
}
