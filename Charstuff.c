#include <stdio.h>
#include <string.h>
#define DLE 16
#define STX 2
#define ETX 3
int main()
{
    char ch;
    char array[100] = {DLE, STX};
    int i = 2, j;
    printf("\n Enter the data stream (CTRL+b->STX,CTRL+C->ETX,CTRL+P->DLE):\n");
    do
    {
        scanf("%c", &ch);
        if (ch == '\n')
            break;
        if (ch == DLE)
        {
            array[i++] = DLE;
        }
        else if (ch == 2)
        {
        }
        else if (ch == 3)
        {
        }
        else
        {
        }
        array[i++] = ch;

    } while (ch != '\n');
    array[i++] = DLE;
    array[i++] = DLE;
    printf("\n the stuffed stream is\n ");
    for (j = 0; j < i; j++)
    {
        if (array[j] == DLE)
        {
            printf("DLE");
        }
        else if (array[j] == STX)
        {
            printf("STX");
        }
        else if (array[j] == ETX)
        {
            printf("ETX");
        }
        else
        {
            printf("%c", array[j]);
        }
    }
    printf("The destuffed data is \n");
    for (j = 2; j < i - 2; j++)
    {
        if (array[j] == DLE)
        {
            j++;
        }
        else if (array[j] == STX)
        {
        }
        else if (array[j] == ETX)
        {
        }
        else
        {
            printf("%c", array[j]);
        }
    }
    return 0;
}
