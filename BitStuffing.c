#include <stdio.h>
#include <string.h>
int main()
{
    char ch, array[100] = "01111110", read_array[50];
    int count = 0, i = 8, j, k;
    printf("Enter the data to be transmitted :");
    while ((ch = getchar()) != '\n')
    {
        array[i++] = ch;
        if (ch == '1')
        {
            count++;
            if (count == 5)
            {
                array[i++] = '0';
                count = 0;
            }
        }
        else
        {
            count = 0;
        }
    }
    strcpy(&array[i], "01111110");
    printf("\n Transmitted bit stream (After stuffing) at the transmitter side is :%s\n", array);
    j = strlen(array);
    count = 0;
    k = 0;
    for (i = 8; i < j - 8; i++)
    {
        read_array[k++] = array[i];
        if (array[i] == '1')
        {
            count++;
            if (count == 5 && array[i + 1] == '0')
            {
                i++;
                count = 0;
            }
        }
        else
        {
            count = 0;
        }
    }
    read_array[k] = '\0';
    printf("Destuffed data at the reciever is : %s\n ", read_array);
    return 0;
}
