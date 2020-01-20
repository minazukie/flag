//
// Created by Minazukie on 2020/1/19.
// https://github.com/minazukie
//

#include "flag.h"

int main(int argc, char **argv) {
    Flag f = newFlag();

    char *name;
    bool isLive;
    int age;
    float height;
    long weight;

    f->setTitle("\nFlag\n\nA simple command line interface.\n");

    f->stringVar(&name, "name", "my name");
    f->boolVar(&isLive, "live", "my state");
    f->intVar(&age, "age", "my age");
    f->floatVar(&height, "height", "my height");
    f->longVar(&weight, "weight", "my weight");

    f->parse(argv);

    f->help();

    printf("name:      %s\n", name);
    printf("age:       %d\n", age);
    printf("is live:   %d\n", isLive);
    printf("height:    %.2f\n", height);
    printf("weight:    %ld\n", weight);
    return 0;
}
