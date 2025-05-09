#include <stdio.h>

int main() {
    int blockSize[25], fileSize[25], allocation[25];
    int numBlocks, numFiles;

    printf("Memory Management Scheme - First Fit\n");

    // Input number of memory blocks and files
    printf("Enter the number of memory blocks: ");
    scanf("%d", &numBlocks);
    printf("Enter the number of files: ");
    scanf("%d", &numFiles);

    // Input block sizes
    printf("\nEnter the size of each memory block:\n");
    for (int i = 0; i < numBlocks; i++) {
        printf("Block %d: ", i + 1);
        scanf("%d", &blockSize[i]);
    }

    // Input file sizes
    printf("\nEnter the size of each file:\n");
    for (int i = 0; i < numFiles; i++) {
        printf("File %d: ", i + 1);
        scanf("%d", &fileSize[i]);
    }

    // Initialize allocation array to -1 (no allocation)
    for (int i = 0; i < numFiles; i++) {
        allocation[i] = -1;
    }

    // First Fit Allocation
    for (int i = 0; i < numFiles; i++) {
        for (int j = 0; j < numBlocks; j++) {
            if (blockSize[j] >= fileSize[i]) {
                // Allocate this block to the file
                allocation[i] = j;
                blockSize[j] -= fileSize[i]; // Reduce block size
                break; // Move to next file
            }
        }
    }

    // Display allocation results
    printf("\nFile No.\tFile Size\tBlock No.\n");
    for (int i = 0; i < numFiles; i++) {
        printf("%d\t\t%d\t\t", i + 1, fileSize[i]);
        if (allocation[i] != -1)
            printf("%d\n", allocation[i] + 1); // +1 for human-friendly output
        else
            printf("Not Allocated\n");
    }

    return 0;
}
