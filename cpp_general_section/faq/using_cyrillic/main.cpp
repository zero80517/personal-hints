#include <iostream>
#include "examples.h"

int main()
{
    int run_example = 2;

    switch(run_example) {
    case 0:
        exampleLinuxOnly();
        break;
    case 1:
        example1();
        break;
    case 2:
        example2();
        break;
    case 3:
        example3();
        break;
    }

    return 0;
}
