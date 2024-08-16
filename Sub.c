//Encryption

#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main()
{
    char seq[36] = "qwertyuiopasdfghjklzxcvbnm1234567890";
    char data[50];
    char encoded[50];
    int i, len;
    printf("\n Enter data : ");
    fgets(data, 50, stdin);
    len = strlen(data);
    if (data[len - 1] == '\n')
        data[--len] = '\0';
    for (i = 0; i < len; i++)
    {
        if (isupper(data[i]))
            encoded[i] = seq[data[i] - 'A'];
        else if (islower(data[i]))
            encoded[i] = toupper(seq[data[i] - 'a']);
        else if (isdigit(data[i]))
            encoded[i] = seq[data[i] - '0' + 26];
        else
            encoded[i] = data[i];
    }
    encoded[len] = '\0';
    printf("\n Encoded string is: %s\n", encoded);
    return 0;
}

//Decryption
#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main()
{
    char seq[36] = "qwertyuiopasdfghjklzxcvbnm1234567890";
    char data[100];
    char decoded[100];
    int i, j, len, present = 0;
    printf("Enter data\n");
    fgets(data, 100, stdin);
    len = strlen(data);
    if (data[len - 1] == '\n')
        data[--len] = '\0';
    for (i = 0; i < len; i++)
    {
        for (j = 0; j < 36 && !present; ++j)
        {
            if (seq[j] == tolower(data[i]))
            {
                if (isupper(data[i]))
                    decoded[i] = 'A' + j;
                else if (islower(data[i]))
                    decoded[i] = 'a' + j;
                else
                    decoded[i] = '0' + (j - 26);
                present = 1;
            }
        }
        if (!present)
            decoded[i] = data[i];
        else
            present = 0;
    }
    decoded[len] = '\0';
    printf("Decoded String is :%s\n", decoded);
    return 0;
}
