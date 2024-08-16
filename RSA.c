#include <stdio.h>
#include <math.h>
int gcd(int a, int b)
{
    while (b != 0)
    {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}
int modExp(int base, int exp, int mod)
{
    int result = 1;
    while (exp > 0)
    {
        if (exp % 2 == 1)
            result = (result * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}
int modInverse(int e, int phi)
{
    int t = 0, newT = 1;
    int r = phi, newR = e;
    while (newR != 0)
    {
        int quotient = r / newR;
        int tempT = t;
        t = newT;
        newT = tempT - quotient * newT;
        int tempR = r;
        r = newR;
        newR = tempR - quotient * newR;
    }
    if (r > 1)
        return -1;
    if (t < 0)
        t += phi;
    return t;
}
int main()
{
    int p, q, n, phi, e, d;
    int plaintext, ciphertext, decryptedtext;
    printf("Enter prime number p: ");
    scanf("%d", &p);
    printf("Enter prime number q: ");
    scanf("%d", &q);
    n = p * q;
    phi = (p - 1) * (q - 1);
    printf("Enter value for e (1 < e < %d): ", phi);
    scanf("%d", &e);
    if (gcd(e, phi) != 1)
    {
        printf("e must be coprime with φ\n");
        return 1;
    }
    d = modInverse(e, phi);
    if (d == -1)
    {
        printf("Modular inverse does not exist\n");
        return 1;
    }
    printf("Enter plaintext integer to encrypt (0 < plaintext < %d): ", n);
    scanf("%d", &plaintext);
    ciphertext = modExp(plaintext, e, n);
    printf("Ciphertext: %d\n", ciphertext);
    decryptedtext = modExp(ciphertext, d, n);
    printf("Decrypted plaintext: %d\n", decryptedtext);
    return 0;
}
