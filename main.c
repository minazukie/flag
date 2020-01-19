//
// Created by Minazukie on 2020/1/19.
// https://github.com/minazukie
//

#include "flag.h"

int main(int argc, char **argv) {
    Flag f = newFlag();
    f->parse(argv);
    return 0;
}
