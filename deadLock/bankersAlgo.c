#include <stdio.h>
#include <stdbool.h>

int main() {
    int n, m; // n = number of processes, m = number of resource types
    int Allocation[10][10], Max[10][10], Need[10][10], Available[10];       // Allocation, Max, Need matrices and Available resources

    bool Finished[10] = {false};    // Track finished processes
    int SafeSequence[10];       // Safe sequence of processes
    int count = 0;          // Count of processes in safe sequence

    // Input
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the number of resource types: ");
    scanf("%d", &m);

    printf("Enter the Allocation matrix:\n"); //no of resources allocated to each process
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &Allocation[i][j]);

    printf("Enter the Max matrix:\n");    //maximum resources required by each process
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &Max[i][j]);

    printf("Enter the Available resources:\n"); //available resources in the system
    for (int j = 0; j < m; j++)
        scanf("%d", &Available[j]);

    // Calculate Need matrix
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            Need[i][j] = Max[i][j] - Allocation[i][j];      // Need = Max - Allocation
    

    // Banker's algorithm logic
    while (count < n) {
        bool found = false;        // Flag to check if a process can be allocated resources

        for (int i = 0; i < n; i++) {
            if (!Finished[i]) { // Check if process is not finished
                // Check if Need[i] <= Available
                bool canAllocate = true;
                for (int j = 0; j < m; j++) {
                    if (Need[i][j] > Available[j]) { // Check if resources are available
                        canAllocate = false;            
                        break;
                    }
                }

                if (canAllocate) {
                    // Pretend to allocate resources
                    for (int j = 0; j < m; j++)
                        Available[j] += Allocation[i][j];   // Release allocated resources
                    SafeSequence[count++] = i; // Add process to safe sequence
                    Finished[i] = true;      // Mark process as finished
                    found = true;                           
                }
            }
        }
        if (!found) {
            printf("System is not in a safe state.\n");
            return 1;
        }
    }

    // Output safe sequence
    printf("System is in a safe state.\nSafe Sequence: ");
    for (int i = 0; i < n; i++)
        printf("P%d ", SafeSequence[i]);
    printf("\n");

    return 0;
}

// This code implements the Banker's Algorithm for deadlock avoidance in operating systems.
// It checks if the system is in a safe state by simulating resource allocation and finding a safe sequence of process execution. If a safe sequence exists, it prints it; otherwise, it indicates that the system is not in a safe state. a safe state
