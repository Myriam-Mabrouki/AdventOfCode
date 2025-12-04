#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
int part1 (FILE *f) {
    char str[16], dest[16];
    int cur = 50, nb, zero = 0;
    while( fgets(str,sizeof(str),f) != NULL){
        strcpy(dest,str + 1);
        nb = atoi(dest);
        if (str[0] == 'R') {
            cur = (cur + nb) % 100;
        }
        else {
            cur = (cur - nb) % 100;
            if (cur < 0) cur = cur + 100;
        }
        if (cur == 0) zero++;
    }
    return zero;
}

int part2 (FILE *f) {
    char str[16], dest[16];
    int cur = 50, nb, zero = 0;
    while( fgets(str,sizeof(str),f) != NULL){
        strcpy(dest,str + 1);
        nb = atoi(dest);
        if (str[0] == 'R') {
            zero += (cur + nb) / 100;
            cur = (cur + nb) % 100;
        }
        else {
            zero += abs((cur - nb) / 100);
            if (cur - nb == 0) zero++;
            cur = (cur - nb) % 100;
            if (cur < 0) {
                cur = cur + 100;
                zero++;
            }
        }
    }
    return zero;
}

int main(void)
{
    FILE * f = fopen("day1_input.txt", "r");
    
    
    if(!f){
        fprintf(stderr, "Error while opening files");
        exit(1);
    }
    
    printf("Part 1: There are %d zeros.\n", part1(f));
    rewind(f);
    printf("Part 2: There are %d zeros.\n", part2(f));
    
 
    fclose(f);
 

    return 0;
}