#include <stdio.h>
#include <stdlib.h>

#define maxFrames 3

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
            return 1; // Page found in frames
        }
    }
    return 0; // Page not found in frames
}

int main() {
    int pages[] = {1,3,6,5,1,5};
    int n = sizeof(pages) / sizeof(pages[0]);

    int frames[maxFrames];
    int pageFaults = 0;

    for (int i = 0; i < maxFrames; i++) {
        frames[i] = -1; 
    }

    printf("Page\t\tFrames\n");

    for (int i = 0; i < n; i++) {
        printf("%d\t", pages[i]);

        if (!isPageInFrames(frames, maxFrames, pages[i])) {
            int lruIndex = maxFrames - 1;
            frames[lruIndex] = pages[i];
            pageFaults++;
            printFrames(frames, maxFrames);
        } else {
            printf("|\n");
        }
    }

    printf("Total Page Faults: %d\n", pageFaults);

    return 0;
}
