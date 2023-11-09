/* Assignment No. 6
Name: Omkar Arun Gore
Roll No: 35024
Batch:B
Title: Page Replacement Algorithms
Problem Statement: Implement the C program for Page Replacement Algorithms: FCFS, LRU, and Optimal for frame size as minimum three*/



#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function to find the page that will not be used for the longest period in the future
int findOptimalPage(int pages[], int pageFrames, int referenceString[], int currentIndex) {
    int farthestIndex = -1;
    int farthestPage = -1;

    for (int i = 0; i < pageFrames; i++) {
        int j;
        for (j = currentIndex; j < sizeof(referenceString) / sizeof(referenceString[0]); j++) {
            if (pages[i] == referenceString[j]) {
                if (j > farthestIndex) {
                    farthestIndex = j;
                    farthestPage = i;
                }
                break;
            }
        }
        if (j == sizeof(referenceString) / sizeof(referenceString[0])) {
            return i; // If a page is not referenced in the future, replace it
        }
    }

    return (farthestPage == -1) ? 0 : farthestPage;
}

int main() {
    int pageFrames, numPages;

    printf("Enter the number of page frames: ");
    scanf("%d", &pageFrames);

    printf("Enter the number of pages: ");
    scanf("%d", &numPages);

    int pages[pageFrames];
    int referenceString[numPages];
    int pageFaults = 0;

    printf("Enter the reference string: ");
    for (int i = 0; i < numPages; i++) {
        scanf("%d", &referenceString[i]);
    }

    for (int i = 0; i < pageFrames; i++) {
        pages[i] = -1; // Initialize page frames to -1 (indicating an empty frame)
    }

    for (int i = 0; i < numPages; i++) {
        bool pageFound = false;

        for (int j = 0; j < pageFrames; j++) {
            if (pages[j] == referenceString[i]) {
                pageFound = true;
                break;
            }
        }

        if (!pageFound) {
            int pageToReplace = findOptimalPage(pages, pageFrames, referenceString, i);
            pages[pageToReplace] = referenceString[i];
            pageFaults++;
        }
    }

    printf("Total Page Faults: %d\n", pageFaults);

    return 0;
}

