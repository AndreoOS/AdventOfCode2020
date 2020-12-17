#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *f = fopen("input.in", "r");
    char passwd[101];
    while (!feof(f)) {
        fscanf(f, "%s", &passwd);
        int nrminim = passwd[0];
        int nrmaxim = passwd[2];

    }

    return 0;
}
