#include <stdio.h>
#include "./dynamic_lib/ramwin.h"

int main() {
    int c = add(1, 2);
    printf("%d", c);
};

