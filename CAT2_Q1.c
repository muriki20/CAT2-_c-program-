// c program 
/*
Name:moses
reg:CT100/G/26258/25
description:printing the element of array using loop
}
*/
    #include <stdio.h>

int main() {
    int scores[2][4] = {
        {65, 92, 35, 70},
        {84, 72, 59, 67}
    };

    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 4; j++) {
            printf("%d\t", scores[i][j]);
        }
        printf("\n");
    }

    return 0;
}