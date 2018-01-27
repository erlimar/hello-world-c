// Copyright (c) E5R Development Team. All rights reserved.
// Licensed under the Apache License, Version 2.0. More license information in LICENSE.txt.

#ifndef __UTILS__
#define __UTILS__

typedef int bool;
#define true 1
#define false 0

typedef struct Context *PContext;

struct Context
{
    bool show_help;
    bool show_default;
    char *informed_name;
};

PContext context_create();
int string_length(char *str);
void string_copy(char *target, char *source);
void context_init(PContext context, int argc, char **argv);
void show_usage();
void show_help();
void show_default_message();
void show_named_message(PContext context);

#endif