#include <stdio.h>

int main ()

{

    long l;

    short s = (8 * sizeof(void *));

    printf("Word size of this machine is %hi bits\n", s);

    short p = (8 * sizeof(l));

    printf("Word size of this machine is %hi bits\n", p);

    return 0;
}
