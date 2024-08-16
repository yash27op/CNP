//Encryption

#include <stdio.h>
#include <string.h>
int main()
{
    char data[100];
    char wrd[] = "MEGABUCK";
    char cipher[20][8];
    int seq[8];
    int i, j, k, cnt;
    for (i = 0; i < strlen(wrd); i++)
    {
        cnt = 0;
        for (j = 0; j < 8; j++)
            if (wrd[i] > wrd[j])
                ++cnt;
        seq[i] = cnt;
    }
    printf("Enter data \n");
    fgets(data, 100, stdin);
    cnt = strlen(data);
    if (data[cnt - 1] == '\n')
        data[--cnt] = '\0';
    for (i = 0; i < cnt; i++)
        cipher[i / strlen(wrd)][i % strlen(wrd)] = data[i];
    if (i % strlen(wrd) != 0)
    {
        for (j = i % strlen(wrd); j < strlen(wrd); j++)
        {
            cipher[i / strlen(wrd)][j] = '.';
            cnt++;
        }
    }
    printf("Encrypted data: \n");
    for (i = 0; i < 8; i++)
    {
        for (j = 0; j < 8; j++)
            if (seq[j] == i)
                break;
        for (k = 0; k < cnt / 8 || k == 0; k++)
            printf("%c", cipher[k][j]);
    }
    printf("\n");
    return 0;
}

//Decryptiom

#include <stdio.h>
#include <string.h>
int main()
{
    char data[100];
    char wrd[] = "MEGABUCK";
    char cipher[20][8];
    int seq[8];
    int i, j, cnt, c;
    for (i = 0; i < strlen(wrd); i++)
    {
        cnt = 0;
        for (j = 0; j < strlen(wrd); j++)
            if (wrd[i] > wrd[j])
                ++cnt;
        seq[i] = cnt;
    }
    printf("Enter data\n");
    fgets(data, 100, stdin);
    cnt = strlen(data);
    if (data[cnt - 1] == '\n')
        data[--cnt] = '\0';
    if (cnt % strlen(wrd) != 0)
        printf("\n Error: invalid input");
    else
    {
        for (i = 0; i < 8; i++)
        {
            for (c = 0; c < 8; c++)
                if (seq[c] == i)
                    break;
            for (j = 0; j < cnt / strlen(wrd); j++)
                cipher[j][c] = data[i * (cnt / strlen(wrd)) + j];
        }
        for (j = 0; j < strlen(wrd); j++)
        {
            if (cipher[cnt / strlen(wrd) - 1][j] == '.')
                cipher[cnt / strlen(wrd)][i % strlen(wrd)] = ' ';
        }
        printf("Decrypyted data : ");
        for (i = 0; i < cnt; i++)
            printf("%c", cipher[i / strlen(wrd)][i % strlen(wrd)]);
        printf("\n");
    }
}
