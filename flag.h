//
// Created by Minazukie on 2020/1/19.
// https://github.com/minazukie
//
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "uthash.h"

#ifndef FLAG_FLAG_H
#define FLAG_FLAG_H

#define public
#define private static

typedef struct flag *Flag;

Flag newFlag();

typedef void (*IntVar)(int *i, char *name, char *usage);

typedef void (*StringVar)(char **c, char *name, char *usage);

typedef void (*LongVar)(long *l, char *name, char *usage);

typedef void (*FloatVar)(float *f, char *name, char *usage);

typedef void (*BoolVar)(bool *b, char *name, char *usage);

typedef void (*SetTitle)(char *title);

typedef void (*Help)();

typedef void (*Parse)(char **argv);

typedef struct flag {
    IntVar intVar;
    StringVar stringVar;
    LongVar longVar;
    FloatVar floatVar;
    BoolVar boolVar;
    SetTitle setTitle;
    Help help;
    Parse parse;
} *Flag;

enum types {
    Int,
    String,
    Long,
    Float,
    Bool,
};

#endif //FLAG_FLAG_H
