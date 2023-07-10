#include <stdio.h>
#define MAX 10

int p[MAX];  
int dir[MAX];  
int n;  

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printPermutation() {
    for (int i = 0; i < n; i++) {
        printf("%d ", p[i]);
    }
    printf("\n");
}

int findLargestMobileElement() {
    int largestMobileIndex = -1;
    int largestMobile = 0;

    for (int i = 0; i < n; i++) {
        if ((dir[i] == -1 && i > 0 && p[i] > p[i - 1]) ||(dir[i] == 1 && i < n - 1 && p[i] > p[i + 1])) {
            if (p[i] > largestMobile) {
                largestMobile = p[i];
                largestMobileIndex = i;
            }
        }
    }
    return largestMobileIndex;
}

void generatePermutations() {
    
    for (int i = 0; i < n; i++) {
        p[i] = i + 1;
        dir[i] = -1;
    }

    printPermutation();
    int largestMobileIndex = findLargestMobileElement();

    while (largestMobileIndex != -1) {
        int largestMobile = p[largestMobileIndex];
        int adjacentIndex = largestMobileIndex + dir[largestMobileIndex];

        swap(&p[largestMobileIndex], &p[adjacentIndex]);
        swap(&dir[largestMobileIndex], &dir[adjacentIndex]);

        for (int i = 0; i < n; i++) {
            if (p[i] > largestMobile) {
                dir[i] = -dir[i];
            }
        }
        printPermutation();
        largestMobileIndex = findLargestMobileElement();
    }
}

int main() {
    printf("Enter the size of the permutation (maximum %d): ", MAX);
    scanf("%d", &n);

    generatePermutations();
    return 0;
}