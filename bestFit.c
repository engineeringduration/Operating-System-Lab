#include <stdio.h>

int main() {
    int blockSize[25], fileSize[25], frag[25];
    int blockFlag[25] = {0};
    int fileToBlock[25];
    int numBlocks, numFiles;

    printf("Memory Management Scheme - Best Fit\n");

    printf("Enter the number of memory blocks: ");
    scanf("%d", &numBlocks);
    printf("Enter the number of files: ");
    scanf("%d", &numFiles);

    printf("\nEnter the size of each memory block:\n");
    for (int i = 0; i < numBlocks; i++) {
        printf("Block %d: ", i + 1);
        scanf("%d", &blockSize[i]);
    }

    printf("\nEnter the size of each file:\n");
    for (int i = 0; i < numFiles; i++) {
        printf("File %d: ", i + 1);
        scanf("%d", &fileSize[i]);
    }

    // Best Fit Allocation
    for (int i = 0; i < numFiles; i++) {
        int best = 10000000;
        int bestIndex = -1;

        for (int j = 0; j < numBlocks; j++) {
            if (!blockFlag[j] && blockSize[j] >= fileSize[i]) {
                if (blockSize[j] < best) {
                    best = blockSize[j];
                    bestIndex = j;
                }
            }
        }

        if (bestIndex != -1) {
            fileToBlock[i] = bestIndex;
            frag[i] = blockSize[bestIndex] - fileSize[i];
            blockSize[bestIndex] -= fileSize[i];  // ✅ Corrected here
            blockFlag[bestIndex] = 1;
        } else {
            fileToBlock[i] = -1;
            frag[i] = -1;
        }
    }

    // Output
    printf("\nFile No.\tFile Size\tBlock No.\tBlock Size\tFragment\n");
    for (int i = 0; i < numFiles; i++) {
        printf("%d\t\t%d\t\t", i + 1, fileSize[i]);
        if (fileToBlock[i] != -1) {
            int blockNum = fileToBlock[i];
            printf("%d\t\t%d\t\t%d\n", blockNum + 1, blockSize[blockNum] + fileSize[i], frag[i]);
        } else {
            printf("Not Allocated\t-\t\t-\n");
        }
    }

    return 0;
}
// This code implements the Best Fit memory allocation algorithm. It takes the sizes of memory blocks and files as input, and allocates files to the best fitting memory blocks, minimizing fragmentation. The output displays the allocation results, including any unallocated files.
// The code uses a greedy approach to find the best fit for each file, ensuring efficient memory usage. The program is structured to handle multiple blocks and files, making it versatile for different scenarios.