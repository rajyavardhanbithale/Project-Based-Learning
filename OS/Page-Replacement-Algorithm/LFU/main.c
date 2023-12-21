//  LFU
#include <stdio.h>
#include <stdlib.h>

#define maxFrames 3

typedef struct {
    int page;
    int frequency;
} PageEntry;

void printFrames(PageEntry frames[], int n) {
    for (int i = 0; i < n; i++) {
        if (frames[i].page == -1) {
            printf("|   ");
        } else {
            printf("| %d:%d ", frames[i].page, frames[i].frequency);
        }
    }
    printf("|\n");
}

int isPageInFrames(PageEntry frames[], int n, int page) {
    for (int i = 0; i < n; i++) {
        if (frames[i].page == page) {
            return 1; 
        }
    }
    return 0;
}

int getLFUIndex(PageEntry frames[], int n) {
    int minFrequency = frames[0].frequency;
    int lfuIndex = 0;

    for (int i = 1; i < n; i++) {
        if (frames[i].frequency < minFrequency) {
            minFrequency = frames[i].frequency;
            lfuIndex = i;
        }
    }

    return lfuIndex;
}

void LFU(int pages[], int n) {
    PageEntry frames[maxFrames];
    int pageFaults = 0;

    for (int i = 0; i < maxFrames; i++) {
        frames[i].page = -1; 
        frames[i].frequency = 0; 
    }

    printf("Page\tFrames\n");

    for (int i = 0; i < n; i++) {
        printf("%d\t", pages[i]);
        if (!isPageInFrames(frames, maxFrames, pages[i])) {
            int lfuIndex = getLFUIndex(frames, maxFrames);
            frames[lfuIndex].page = pages[i];
            frames[lfuIndex].frequency = 1; 
            pageFaults++;

            printFrames(frames, maxFrames);
        } else {
            for (int j = 0; j < maxFrames; j++) {
                if (frames[j].page == pages[i]) {
                    frames[j].frequency++;
                    break;
                }
            }
            printf("|\n");
        }
    }

    printf("Total Page Faults: %d\n", pageFaults);
}

int main() {
    int pages[] = {1,8,3,6,9,2,3,4};
    int n = sizeof(pages) / sizeof(pages[0]);

    LFU(pages, n);

    return 0;
}