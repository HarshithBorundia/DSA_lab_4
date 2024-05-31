#include <stdio.h>
#include <stdlib.h>
#include <string.h> // Include string.h for string manipulation functions

int main()
{
    char *arr1[5] = {"", "thousand", "million", "billion", "trillion"};
    char *arr2[20] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
    char *arr3[10] = {"", "", "twenty", "thirty", "fourty", "fifty", "sixty", "seventy", "eighty", "ninety"};
    
    long long val;
    scanf("%lld", &val);
    
    if (val == 0) {
        printf("zero");
    } else {
        long long temp = val;
        int cnt = 0;
        char ans[1000] = ""; // Define an array to store the final result and initialize it
    
        while (temp) {
            int val1 = temp % 1000;
            if (val1 == 0) {
                temp = temp / 1000;
                cnt++;
                continue;
            }
            char temp_ans[100] = ""; // Define a temporary array to store the current part of the output and initialize it
            int arr[3];
            arr[2] = val1 % 10; // Ones place
            val1 = val1 / 10;
            arr[1] = val1 % 10; // Tens place
            val1 = val1 / 10;
            arr[0] = val1 % 10; // Hundreds place
            
            if (arr[0] > 0) {
                strcat(temp_ans, arr2[arr[0]]); // Append the hundreds place to the temporary array
                strcat(temp_ans, " hundred "); // Append "hundred" to the temporary array
            }
            
            if ((arr[1] < 2) && !(arr[1]==0 && arr[2]==0)) {
                strcat(temp_ans, arr2[arr[1]*10 + arr[2]]); // Append the numbers less than 20 to the temporary array
            } else {
                strcat(temp_ans, arr3[arr[1]]); // Append the tens place to the temporary array
                if (arr[2] > 0) {
                    strcat(temp_ans, " "); // Append a space
                    strcat(temp_ans, arr2[arr[2]]); // Append the ones place to the temporary array
                }
            }
            
            strcat(temp_ans, " "); // Append a space
            strcat(temp_ans, arr1[cnt++]); // Append the appropriate suffix (thousand, million, etc.) to the temporary array
            strcat(temp_ans, " "); // Append a space
            
            strcat(temp_ans, ans); // Concatenate the temporary array to the beginning of the final result
            strcpy(ans, temp_ans); // Copy the temporary array to the final result
            temp = temp / 1000;
        }
        
        printf("%s", ans); // Print the final result
    }
    
    return 0;
}

