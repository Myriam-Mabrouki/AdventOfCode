#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
long part1 (FILE *f) {

    long start, end, size, sum = 0;
    char buff1[256], buff2[256];

    while (fscanf(f, "%ld-%ld,", &start, &end) == 2)
    {
        for (long i = start; i <= end; i++)
        {
            sprintf(buff1, "%ld", i);
            size = strlen(buff1);
            if (size % 2 == 0)
            {   
                strncpy(buff2, buff1, size/2);
                buff2[size/2]='\0';
                if (strcmp(buff1 + size/2, buff2) == 0)
                    sum += i;
            }
        }
    }

    return sum;
}

long part2 (FILE *f) {

    long start, end, size, sum = 0;
    char buff1[256], buff2[256], buff3[256];

    while (fscanf(f, "%ld-%ld,", &start, &end) == 2)
    {
        for (long i = start; i <= end; i++)
        {
            sprintf(buff1, "%ld", i);
            size = strlen(buff1);

            for (int j = 1; j < size; j++) 
            {
                if (size % j != 0) 
                    continue;

                int offset1 = 0, offset2 = j;
                
                do
                {
                    strncpy(buff2, buff1 + offset1, j);
                    strncpy(buff3, buff1 + offset2, j);
                    buff2[j]='\0';
                    buff3[j]='\0';

                    if (strcmp(buff2, buff3) != 0)
                        break;

                    offset1 = offset2;
                    offset2 += j;
                } while (offset2 < size);
                
                if (offset2 == size) {
                    sum += i;
                    break; // do not count the same number more than once
                }
            }
        }
    }

    return sum;
}

int main(void)
{
    FILE * f = fopen("day2_input.txt", "r");
    
    
    if(!f){
        fprintf(stderr, "Error while opening files");
        exit(1);
    }
    
    printf("Part 1: %ld \n", part1(f));
    rewind(f);
    printf("Part 2: %ld \n", part2(f));
    
 
    fclose(f);
 

    return 0;
}