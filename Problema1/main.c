#include <stdio.h>
#include <stdlib.h>

#define NMAX 1000

void sort_array(int v[NMAX], int nr)
{
    for (int i = 0; i < nr - 1; i++) {
        for (int j = i + 1; j < nr; j++)
        {
            if (v[i] < v[j]) {
                int aux = v[i];
                v[i] = v[j];
                v[j] = aux;
            }
        }
    }
}

int main()
{
    int freq[2020] = {0}, v[NMAX];
    int i = 0;
    int ok = 1;
    FILE *f = fopen("input.in", "r");
    while (!feof(f)) {
        fscanf(f, "%d", &v[i]);
        freq[v[i]]++;
        i++;
    }
    int nr = i;
    sort_array(v, nr);
    i = 0;
    while (ok != 0 && i < nr - 1) {
        int j = i + 1;
        while (ok != 0 && j < nr) {
            if(freq[2020 - v[i]- v[j]] != 0 && (2020 - v[i] - v[j]) > 0 && v[i] != 0 && v[j] != 0 ) {
                ok = 1;
                printf("%d %d %d\n", v[i], v[j], 2020 - v[i] - v[j]);
            }
            j++;
        }
        i++;
    }
    fclose(f);

    return 0;
}
