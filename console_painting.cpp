#include "console_painting.h"

void random_color()
{
    unsigned now = txGetConsoleAttr();

    txSetConsoleAttr (16 * (rand() % 16) + (rand() % 16));

    if (now != txGetConsoleAttr())
        printf("\n");
}

void error_color()
{
    unsigned now = txGetConsoleAttr();

    txSetConsoleAttr (0x40);

    if (now != txGetConsoleAttr())
        printf("\n");
}

void unexpected_color()
{
    unsigned now = txGetConsoleAttr();

    txSetConsoleAttr (0xDF);

    if (now != txGetConsoleAttr())
        printf("\n");
}

void success_color()
{
    unsigned now = txGetConsoleAttr();

    txSetConsoleAttr (0x20);

    if (now != txGetConsoleAttr())
        printf("\n");
}

void failure_color()
{
    unsigned now = txGetConsoleAttr();

    txSetConsoleAttr (0x50);

    if (now != txGetConsoleAttr())
        printf("\n");
}

void basic_color()
{
    unsigned now = txGetConsoleAttr();

    txSetConsoleAttr (0x00);

    if (now != txGetConsoleAttr())
        printf("\n");
}
