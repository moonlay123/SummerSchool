#include "console_painting.h"

static int color_flag = 0;
void random_color()
{
    unsigned now = txGetConsoleAttr();

    color_flag = 1 - color_flag;
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

    if (color_flag == 1)
    {
        txSetConsoleAttr (16 * (rand() % 16) + (rand() % 16));
    } else
    {
        txSetConsoleAttr (0x00);
    }

    if (now != txGetConsoleAttr())
        printf("\n");
}
