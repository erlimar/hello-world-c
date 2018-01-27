// Copyright (c) E5R Development Team. All rights reserved.
// Licensed under the Apache License, Version 2.0. More license information in LICENSE.txt.

#include <stdio.h>

#include "utils.h"

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        show_usage();
        return 1;
    }

    PContext context = context_create();
    context_init(context, argc, argv);

    if (context->show_help)
    {
        show_help();
        return 0;
    }

    if (context->show_default)
    {
        show_default_message();
        return 0;
    }

    show_named_message(context);

    return 0;
}
