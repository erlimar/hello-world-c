// Copyright (c) E5R Development Team. All rights reserved.
// Licensed under the Apache License, Version 2.0. More license information in LICENSE.txt.

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "utils.h"

const char *program_name = "hello.exe";

int string_length(char *str)
{
    int len = 0;

    while (*str)
    {
        len++;
        str++;
    }

    return len;
}

void string_copy(char *target, char *source)
{
    while (*source)
    {
        *target = *source;
        source++;
        target++;
    }

    *target = '\0';
}

PContext context_create()
{
    PContext ctx = malloc(sizeof(PContext));

    return ctx;
}

void context_init(PContext context, int argc, char **argv)
{
    context->informed_name = "\0";
    context->show_help = false;
    context->show_default = false;

    int has = argc - 1;

    while (has)
    {
        char *param = argv[argc - has];
        int len = string_length(param);
        has--;

        if (strcmp(param, "--help") == 0)
        {
            context->show_help = true;
            continue;
        }

        if (strcmp(param, "--default") == 0)
        {
            context->show_default = true;
            continue;
        }

        string_copy(context->informed_name, param);
        break;
    }
}

void show_usage()
{
    printf("Usage: %s [options] NAME\n", program_name);
    printf("\n");
    printf("Options:\n");
    printf("  --help    Show help information\n");
    printf("  --default Show default message\n");
}

void show_help()
{
    show_usage();
    printf("\nThis is a help message.\n");
}

void show_default_message()
{
    printf("Hello World!\n");
}

void show_named_message(PContext context)
{
    printf("Hello %s! Welcome to the C world.\n", context->informed_name);
}