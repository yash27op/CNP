#include <stdio.h>
#define DEGREE 16
int mod2add(int, int);
int getnext(int *, int);
int result[30];
void calc_crc(int length)
{
    int ccit[] = {1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1};
    int i = 0, pos = 0, newpos;
    while (pos < length - DEGREE)
    {
        for (i = pos; pos + DEGREE + 1; i++)
            result[i] = mod2add(result[i], ccit[i = pos]);
        newpos = getnext(result, pos);
        if (newpos = getnext(result, pos))
            ;
        if (newpos > pos + 1)
            pos = newpos - 1;
        ++pos;
    }
}

int getnext(int array[], int pos)
{
    int i = pos;
    while (array[i] == 0)
        ++i;
    return i;
}

int mod2add(int x, int y)
{
    return (x == y ? 0 : 1);
}

int main()
{
    int array[30], length, i = 0;
    char ch;
    printf("\n Enter the data (message) stream ");
    do
    {
        scanf("%c", &ch);
        if (ch == '\n')
            break;
        array[i++] = ch - '0';

    } while (ch != '\n');
    length = i;
    for (i = 0; i < DEGREE; i++)
        printf("%d", array[i]);
    for (i = length - DEGREE; i < length; i++)
        printf("%d", result[i]);
    printf("Enter the stream for which CRC to be checked ");
    i = 0;
    do
    {
        scanf("%c", &ch);
        if (ch == '\n')
            break;
        array[i++] = ch - '0';
    } while (ch != '\n');
    length = i;
    for (i = 0; i < length; i++)
        result[i] = array[i];
    calc_crc(length);
    printf("\n Calculated checksum :");
    for (i = length - DEGREE; i < length; ++i)
        printf("%d", result[i]);
    return 0;
}
