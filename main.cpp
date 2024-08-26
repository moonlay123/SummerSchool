#include "flags/flags_controller.h"

int main(int argc, char *argv[])
{
    --argc; ++argv;

    if (argc == 0)
    {
        help();
        return SUCCESS;
    }

    console_flags flags;

    flag_handler(&flags, argc, argv);

    if (flags.exit_flag)
    {
        txSetConsoleAttr (0x00);
        return SUCCESS;
    }
    if (flags.help_flag)
    {
        help();
    }
    if (flags.rand_flag)
    {
        random_color();
    }
    if (flags.filenames_size > 0)
    {
        files_handler(&flags, argv);
    }
    if (flags.menu_flag)
    {
        menu();
    }
    if (flags.clean_flag)
    {
        txSetConsoleAttr(0x00);
        txClearConsole();
    }

    return SUCCESS;
}
