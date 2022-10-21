#include <stdio.h>
#include <string.h>

char arr[30];
char ary[30];

void encrypt(char a[], int k) {
    int x = strlen(a);
    int e[x];
    for (int k = 0; k < x - 1; k++) {
        if (a[k] >= 65 && a[k] < 90) {
            a[k] += 32;
        }
    }

    for (int i = 0; i <= x - 1; i++) {
        e[i] = (int) a[i];
    }

    for (int j = 0; j <= x - 1; j++) {
        e[j] = e[j] + k - 97;
        e[j] = e[j] % 26;
        e[j] += 97;
    }

    for (int l = 0; l <= x - 1; l++) {
        arr[l] = (char) e[l];
    }
}

void decrypt(char a[], int k) {
    int x = strlen(a);
    int e[x];
    for (int i = 0; i <= x - 1; i++) {
        e[i] = (int) a[i];
    }

    for (int j = 0; j <= x - 1; j++) {
        e[j] = (e[j] - k - 97);
        if (e[j] > 0) {
            e[j] = e[j] % 26;
            e[j] += 97;
        } else if (e[j] < 0) {
            e[j] += 26;
            e[j] = e[j] % 26;
            e[j] += 97;
        } }

    for (int l = 0; l <= x - 1; l++) {
        ary[l] = (char) e[l];
    } }

int main() {
    int n, n1, i;
    printf("Enter the length of the Plain Text: ");
    scanf("%d", & n);
    printf("Enter the key: ");
    scanf("%d", & n1);
    char c[n + 1];
    printf("Enter the Plain Text: ");
    scanf("%s", & c);
    printf("\n");
    c[n] = '\0';
    printf("\nPlain Text before Encryption: ");
    printf("%s", c);
    printf("\n");
    printf("\nPlain Text After Encryption: ");
    encrypt(c, n1);
    printf("%s", arr);
    printf("\n");
    decrypt(arr, n1);
    printf("\nCipher Text After Decryption: ");
    printf("%s", ary);

}
