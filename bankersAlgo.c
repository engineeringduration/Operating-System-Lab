#include <stdio.h>
#include <stdbool.h>

int main() {
    int n, m; // n = number of processes, m = number of resource types
    int Allocation[10][10], Max[10][10], Need[10][10], Available[10];
    bool Finished[10] = {false};
    int SafeSequence[10];
    int count = 0;

    // Input
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the number of resource types: ");
    scanf("%d", &m);

    printf("Enter the Allocation matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &Allocation[i][j]);

    printf("Enter the Max matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &Max[i][j]);

    printf("Enter the Available resources:\n");
    for (int j = 0; j < m; j++)
        scanf("%d", &Available[j]);

    // Calculate Need matrix
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            Need[i][j] = Max[i][j] - Allocation[i][j];

    // Banker's algorithm logic
    while (count < n) {
        bool found = false;
        for (int i = 0; i < n; i++) {
            if (!Finished[i]) {
                bool canAllocate = true;
                for (int j = 0; j < m; j++) {
                    if (Need[i][j] > Available[j]) {
                        canAllocate = false;
                        break;
                    }
                }

                if (canAllocate) {
                    // Pretend to allocate resources
                    for (int j = 0; j < m; j++)
                        Available[j] += Allocation[i][j];
                    SafeSequence[count++] = i;
                    Finished[i] = true;
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
