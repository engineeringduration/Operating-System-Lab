#include <stdio.h>

int main() {
    int blockSize[25], fileSize[25], frag[25];
    int blockFlag[25] = {0}; // keeps track of allocated blocks
    int fileToBlock[25];     // stores block index for each file
    int numBlocks, numFiles;

    printf("Memory Management Scheme - Worst Fit\n");

    // Input number of blocks and files
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

    // Worst Fit Allocation
    for (int i = 0; i < numFiles; i++) {
        int maxBlockIndex = -1;

        for (int j = 0; j < numBlocks; j++) {
            if (!blockFlag[j] && blockSize[j] >= fileSize[i]) {
                if (maxBlockIndex == -1 || blockSize[j] > blockSize[maxBlockIndex]) {
                    maxBlockIndex = j;
                }
            }
        }

        if (maxBlockIndex != -1) {
            // Allocate block
            fileToBlock[i] = maxBlockIndex;
            frag[i] = blockSize[maxBlockIndex] - fileSize[i];
            blockFlag[maxBlockIndex] = 1;
        } else {
            fileToBlock[i] = -1; // Not allocated
            frag[i] = -1;
        }
    }

    // Output allocation table
    printf("\nFile No.\tFile Size\tBlock No.\tBlock Size\tFragment\n");
    for (int i = 0; i < numFiles; i++) {
        printf("%d\t\t%d\t\t", i + 1, fileSize[i]);
        if (fileToBlock[i] != -1) {
            printf("%d\t\t%d\t\t%d\n", fileToBlock[i] + 1, blockSize[fileToBlock[i]], frag[i]);
        } else {
            printf("Not Allocated\t-\t\t-\n");
        }
    }

    return 0;
}
// This code implements the Worst Fit memory allocation algorithm. It takes the sizes of memory blocks and files as input, and allocates the largest available block to each file. If a file cannot be allocated, it indicates that it is not allocated.
// The output displays the allocation results, including any unallocated files.