//
// Created by Minazukie on 2020/1/19.
// https://github.com/minazukie
//

#include "flag.h"

private void error(char *err);
private bool initialized = false;

private struct _flag {
    Flag f;
    char **argv;
} *_Flag;

private void defaultParse(char **argv) {
    int i = 0;

    if (initialized) {
        error("flag already exists");
        return;
    }

    initialized = true;
    _Flag->argv = argv;

    while (1) {
        if (argv[i] == NULL) {
            break;
        }
        printf("%s\n", argv[i]);
        i++;
    }

    i++;
    while (1) {
        if (argv[i] == NULL) {
            break;
        }
        printf("%s\n", argv[i]);
        i++;
    }
}

private void defaultIntVar(int *i) {
    // TODO
}

private void defaultStringVar(char *c) {
    // TODO
}

private void defaultLongVar(long *l) {
    // TODO
}

private void defaultFloatVar(float *f) {
    // TODO
}

private void defaultBoolVar(bool *b) {
}

public Flag newFlag() {
    Flag f = malloc(sizeof(Flag));
    struct _flag *ff = malloc(sizeof(struct _flag));
    ff->f = f;
    _Flag = ff;

    f->parse = defaultParse;
    f->intVar = defaultIntVar;
    f->stringVar = defaultStringVar;
    f->longVar = defaultLongVar;
    f->floatVar = defaultFloatVar;
    f->boolVar = defaultBoolVar;

    return f;
}

private void error(char *err) {
    fprintf(stderr, "[Error] %s\n", err);
}