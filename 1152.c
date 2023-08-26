#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int arr[26];

int toUpperCase(char c1) {
    if (c1 >= 'a' && c1 <= 'z') {
        return c1 - 32;
    }
    return c1;
}

int main() {
    char str[1000000];
    scanf("%s", str);


    int strLen = strlen(str);
    for (int i = 0; i < strLen; i++) {
        char c = toUpperCase(str[i]);
        int index = c - 'A';
        arr[index]++;
    }

    
    int maxCount = 0;
    int index = 0;
    int sameCount = 0;
    for (int i = 0; i < 26; i++) {
        if (arr[i] >= maxCount) {
            if (arr[i] == maxCount) {
                sameCount++;
                maxCount = arr[i];
                index = i;
            }
          else {
              maxCount = arr[i];
              index = i;
              sameCount = 0;
          }
        }
    }

    if (sameCount > 0) {
        printf("?\n");
    }
    else {
        printf("%c\n", 'A' + index);
    }

    return 0;
}