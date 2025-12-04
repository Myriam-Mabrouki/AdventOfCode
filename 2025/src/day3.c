#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
long part1 (FILE *f) {

    char buff[512], tmp[512];
    int max1, max2, tmp1, tmp2;
    long sum;
    while (fgets(buff,sizeof(buff),f))
    {
        max1 = buff[0] - '0';
        max2 = buff[1] - '0';
        
        for (size_t i = 1; i < strlen(buff) - 2; i++)
        {   
            tmp1 = buff[i] - '0';
            tmp2 = buff[i+1] - '0';
            if (tmp1 > max1) 
            {
                max1 = tmp1;
                max2 = tmp2;
            }
            else if (tmp2 > max2)
            {
                max2 = tmp2;
            }
        }
        tmp2 = buff[strlen(buff) - 2] - '0';
        if (tmp2 > max2)
            max2 = tmp2;
        sprintf(tmp, "%d%d", max1, max2);
        sum += atoi(tmp);
    }
    return sum;
}

long part2 (FILE *f) {

    int N = 12;
    int max[N];
    char buff[512], tmp[N];
    long long sum = 0;

    while (fscanf(f,"%s", buff) == 1)
    {
        for (int i = 0; i < N; i++)
            max[i] = i;
        
        int size = strlen(buff);
        for (int i = 1; i < size; i++)
        {   
            for (int j = 0; j < N; j++)
            {
                if (size - i >= N - j && i > j && (j == 0 || i - max[j-1] > 0))
                {
                    if (buff[i] > buff[max[j]])
                    {
                        for (int k = 0; k < N - j; k++)
                            max[j+k] = i + k;

                        break;
                    }
                }
            }
            
        }

        for (int i = 0; i < N; i++)
            tmp[i] = buff[max[i]];

        tmp[N] = '\0';

        sum += atoll(tmp);
    }

    return sum;
}

int main(void)
{
    FILE * f = fopen("../input/day3.txt", "r");
    
    
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