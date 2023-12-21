#include <stdio.h>
#include <stdlib.h>

#define maxFrames 3
#define INFINITY 999999

int findOptimalIndex(int pages[], int frames[], int n, int startIndex) {
    int index = -1;
    int farthest = startIndex;

    for (int i = 0; i < maxFrames; i++) {
        int j;
        for (j = startIndex; j < n; j++) {
            if (frames[i] == pages[j]) {
                if (j > farthest) {
                    farthest = j;
                    index = i;
                }
                break;
            }
        }
        if (j == n) {
            return i; 
        }
    }

    return index;
}

void printFrames(int frames[], int n) {
    for (int i = 0; i < n; i++) {
        if (frames[i] == -1) {
            printf("|   ");
        } else {
            printf("| %d ", frames[i]);
        }
    }
    printf("|\n");
}

int isPageInFrames(int frames[], int n, int page) {
    for (int i = 0; i < n; i++) {
        if (frames[i] == page) {
            return 1; 
        }
    }
    return 0; 
}

void OPT(int pages[], int n) {
    int frames[maxFrames];
    int pageFaults = 0;

    for (int i = 0; i < maxFrames; i++) {
        frames[i] = -1; 
    }

    printf("Page\tFrames\n");

    for (int i = 0; i < n; i++) {
        printf("%d\t", pages[i]);
        if (!isPageInFrames(frames, maxFrames, pages[i])) {
            int optimalIndex = findOptimalIndex(pages, frames, n, i + 1);

            frames[optimalIndex] = pages[i];
            pageFaults++;

            printFrames(frames, maxFrames);
        } else {
            printf("|\n");
        }
    }

    printf("Total Page Faults: %d\n", pageFaults);
}

int main() {
    int pages[] = {1,2,5,3,6,1,2};
    int n = sizeof(pages) / sizeof(pages[0]);

    OPT(pages, n);

    return 0;
}
