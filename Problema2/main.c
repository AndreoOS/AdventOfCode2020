#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NMAX 100


int main()
{
    FILE *f = fopen("input.in", "r");
    char *passwd;
    int nr = 0;
    char cminim[25], cmaxim[25], key[25], pass[NMAX];
    passwd = malloc(NMAX * sizeof(char));
    while (fgets (passwd, NMAX, f)) {
        int freq[128] = {0};
        strcpy(cminim, strtok(passwd, "-"));
        strcpy(cmaxim, strtok(NULL, " "));
        strcpy(key, strtok(NULL, ": "));
        strcpy(pass, strtok(NULL, "\n"));
        if (pass[0] == ' ') {
            memmove(pass, pass+1, strlen(pass));
        }
        for(int i = 0; i < strlen(pass); i++) {
            freq[(int)pass[i]]++;
        }
        int minim, maxim;
        sscanf(cminim, "%d", &minim);
        sscanf(cmaxim, "%d", &maxim);
        if (freq[(int)key[0]] >= minim && freq[(int)key[0]] <= maxim) {
            nr++;
        }
     }
    printf("%d\n", nr);
    fclose(f);
    FILE *g = fopen("input.in", "r");
    char poz1[25], poz2[25];
    nr = 0;
    while (fgets (passwd, NMAX, g)) {
        strcpy(poz1, strtok(passwd, "-"));
        strcpy(poz2, strtok(NULL, " "));
        strcpy(key, strtok(NULL, ": "));
        strcpy(pass, strtok(NULL, "\n"));
        if (pass[0] == ' ') {
            memmove(pass, pass+1, strlen(pass));
        }
        int unu, doi;
        sscanf(poz1, "%d", &unu);
        sscanf(poz2, "%d", &doi);
        if(pass[unu - 1] == key[0] && pass[doi - 1] != key[0]) {
            nr++;
        } else if (pass[unu - 1] != key[0] && pass[doi - 1] == key[0]) {
            nr++;
        }
    }
    printf("%d", nr);
    fclose(g);

    return 0;
}
