#include "console_painting.h"

void random_color()
{
    txSetConsoleAttr(16 * (rand() % 16) + (rand() % 16));
    Sleep(100);
}

void error_color()
{
    txSetConsoleAttr(0x40);
    Sleep(100);
}

void unexpected_color()
{
    txSetConsoleAttr(0xDF);
    Sleep(100);
}

void success_color()
{
    txSetConsoleAttr(0x20);
    Sleep(100);
}

void failure_color()
{
    txSetConsoleAttr(0x50);
    Sleep(100);
}

void basic_color()
{
    txSetConsoleAttr(0x00);
    Sleep(100);
}
