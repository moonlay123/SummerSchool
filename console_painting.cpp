#include "console_painting.h"

void random_color()
{
    txSetConsoleAttr(16 * (rand() % 16) + (rand() % 16));
}
