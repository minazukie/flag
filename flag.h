//
// Created by Minazukie on 2020/1/19.
// https://github.com/minazukie
//
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#ifndef FLAG_FLAG_H
#define FLAG_FLAG_H

#define public
#define private static

typedef struct flag *Flag;

Flag newFlag();

typedef void (*IntVar)(int *i);

typedef void (*StringVar)(char *c);

typedef void (*LongVar)(long *l);

typedef void (*FloatVar)(float *f);

typedef void (*BoolVar)(bool *b);

typedef void (*Parse)(char **argv);

typedef struct flag {
    IntVar intVar;
    StringVar stringVar;
    LongVar longVar;
    FloatVar floatVar;
    BoolVar boolVar;
    Parse parse;
} *Flag;

#endif //FLAG_FLAG_H
