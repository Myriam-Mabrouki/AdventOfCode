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
    char buff[512], tmp[512];
    long long sum;
    //while (fgets(buff,sizeof(buff),f))
    while (fscanf(f,"%s", buff) == 1)
    {
        for (int i = 0; i < N; i++)
        {
            max[i] = i;
        }
        
        int size = strlen(buff);
        for (int i = 1; i < size; i++)
        {   
            for (int j = 0; j < N; j++)
            {
                if (size - i >= N - j && i > j && (j == 0 || max[j-1]-i >= j))
                {
                    printf("i : %d, j : %d - %c > %c ?, size = %d\n", i, j, buff[i], buff[max[j]], size);
                    if (buff[i] > buff[max[j]])
                    {
                        printf("oui\n");
                        for (int k = 0; k < N - j; k++)
                        {
                            printf("haha k+j=%d, i+k=%d k=%d, j=%d, i=%d\n", k+j, i+k, k, j , i);
                            max[j+k] = i + k;
                        }
                        break;
                    }
                }
            }
            
        }
        sprintf(tmp, "%d%d%d%d%d%d%d%d%d%d%d%d", buff[max[0]] - '0', buff[max[1]] - '0', buff[max[2]] - '0', buff[max[3]] - '0', buff[max[4]] - '0', buff[max[5]] - '0', buff[max[6]] - '0', buff[max[7]] - '0', buff[max[8]] - '0', buff[max[9]] - '0', buff[max[10]] - '0', buff[max[11]] - '0');
        printf("%s\n", tmp);
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