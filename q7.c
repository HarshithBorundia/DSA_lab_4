#include <stdio.h>
#include <string.h>

int main() {
    char a[1000000]; // assuming a reasonable maximum length
    char b[1000000]; // assuming a reasonable maximum length
    
    scanf("%s", a);
    scanf("%s", b);
    
    int len1 = strlen(a);
    int len2 = strlen(b);
    int mini, maxi;

    if (len1 < len2) {
        mini = len1;
        maxi = len2;
    } else {
        mini = len2;
        maxi = len1;
    }

    int j = 1;
    int lcm = 0;

    while (j <= maxi) {
        int val = mini * j;
        if (val % maxi == 0) {
            lcm = val;
            break;
        }
        j++;
    }

    char tempA[1000000];
    char tempB[1000000];

    strcpy(tempA, a);
    strcpy(tempB, b);

    while (strlen(a) != lcm) {
        strcat(a, tempA);
    }

    while (strlen(b) != lcm) {
        strcat(b, tempB);
    }

    if (strcmp(a, b) == 0) {
        printf("%s", a);
    } else {
        printf("-1");
    }

    return 0;
}

