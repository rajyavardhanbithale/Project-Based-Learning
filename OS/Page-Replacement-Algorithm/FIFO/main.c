#include <stdio.h>

#define maxFrames 3

int main()  {  
    int incomingStream[] = {1, 2, 3, 4, 5, 1};  
    int pageFaults = 0;  
    
    int m, n, s, pages;
    pages = sizeof(incomingStream)/sizeof(incomingStream[0]);   

    printf("Incoming|     Frame 1   |     Frame 2   |     Frame 3   |");  
    printf("\n");  
    printf("--------+---------------+---------------+---------------+");  

    int stack[maxFrames];  
    for(m = 0; m < maxFrames; m++)  {  
        stack[m] = -1;  
    }  
    for(m = 0; m < pages; m++)  {  
        s = 0;   
        for(n = 0; n < maxFrames; n++)  {  
            if(incomingStream[m] == stack[n])  {  
                s++;  
                pageFaults--;  
            }  
        }  
        pageFaults++;  
        if((pageFaults <= maxFrames) && (s == 0)){  
            stack[m] = incomingStream[m];  
        }  
        else if(s == 0)  {  
            stack[(pageFaults - 1) % maxFrames] = incomingStream[m];  
        }  
        printf("\n");  
        printf("%d\t|\t",incomingStream[m]);  
        for(n = 0; n < maxFrames; n++)  {  
            if(stack[n] != -1)  
                printf(" %d\t|\t", stack[n]);  
            else  
                printf(" - \t|\t");  
        }  
    }  
    printf("\nTotal Page Faults:\t%d\n", pageFaults);  
    return 0;  
}  