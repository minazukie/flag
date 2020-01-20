//
// Created by Minazukie on 2020/1/19.
// https://github.com/minazukie
//

#include "flag.h"

private void error(char *err);

private bool initialized = false;

private void var(void *value, char *name, char *usage, enum types type);

private struct _flag {
    Flag f;
    char **argv;
} *_Flag;

struct FlagArgs {
    void *data;
    char *usage;
    enum types type;
};

struct Map {
    char *key;
    struct FlagArgs *value;
    UT_hash_handle hh;
} *flagMap;

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
        if (argv[i][0] == '-') {
            char name[strlen(argv[i]) - 1];
            for (int ni = 0; ni < (strlen(argv[i]) - 1); ni++) {
                name[ni] = argv[i][ni + 1];
            }

            struct Map *fm = NULL;
            HASH_FIND_STR(flagMap, name, fm);

            if (fm != NULL) {
                if (fm->value->type == Bool) {
                    *(bool *) fm->value->data = true;
                    i++;
                    continue;
                }

                if (argv[i + 1] == NULL) {
                    char *msg = NULL;
                    sprintf(msg, "invalid argument for %s", name);
                    error(msg);
                    break;
                }

                if (fm->value->type == Int) {
                    *(int *) fm->value->data = atoi(argv[i + 1]);
                    i++;
                    continue;
                }

                if (fm->value->type == Float) {
                    *(float *) fm->value->data = atof(argv[i + 1]);
                    i++;
                    continue;
                }

                if (fm->value->type == Long) {
                    *(long *) fm->value->data = atol(argv[i + 1]);
                    i++;
                    continue;
                }

                *(typeof(fm->value->data) *) fm->value->data = strdup(argv[i + 1]);
            }
        }
        i++;
    }

//    // ENV
//    i++;
//    while (1) {
//        if (argv[i] == NULL) {
//            break;
//        }
//        printf("%s\n", argv[i]);
//        i++;
//    }
}

private void defaultIntVar(int *i, char *name, char *usage) {
    var(i, name, usage, Int);
}

private void defaultStringVar(char **c, char *name, char *usage) {
    var(c, name, usage, String);
}

private void defaultLongVar(long *l, char *name, char *usage) {
    var(l, name, usage, Long);
}

private void defaultFloatVar(float *f, char *name, char *usage) {
    var(f, name, usage, Float);
}

private void defaultBoolVar(bool *b, char *name, char *usage) {
    var(b, name, usage, Bool);
}

private void var(void *value, char *name, char *usage, enum types type) {
    struct FlagArgs *fa = malloc(sizeof(struct FlagArgs));
    fa->type = type;
    fa->data = value;
    fa->usage = usage;

    struct Map *fm = NULL;
    fm = malloc(sizeof(struct Map));
    fm->key = name;
    fm->value = fa;

    HASH_ADD_STR(flagMap, key, fm);
}

public Flag newFlag() {
    Flag f = malloc(sizeof(Flag));
    struct _flag *ff = malloc(sizeof(struct _flag));
    flagMap = NULL;
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