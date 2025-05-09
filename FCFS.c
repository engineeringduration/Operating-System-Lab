#include <stdio.h>

int main() {
    int burstTime[20], waitingTime[20], turnaroundTime[20];
    int i, numberOfProcesses;
    float totalWaitingTime = 0, totalTurnaroundTime = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &numberOfProcesses);

    for(i = 0; i < numberOfProcesses; i++) {
        printf("Enter Burst Time for Process %d: ", i);
        scanf("%d", &burstTime[i]);
    }

    waitingTime[0] = 0; // First process has 0 waiting time

    for(i = 0; i < numberOfProcesses; i++) {
        if (i > 0) {
            waitingTime[i] = waitingTime[i - 1] + burstTime[i - 1];
        }
        turnaroundTime[i] = waitingTime[i] + burstTime[i];

        totalWaitingTime += waitingTime[i];
        totalTurnaroundTime += turnaroundTime[i];
    }

    printf("\nPROCESS\tBURST TIME\tWAITING TIME\tTURNAROUND TIME\n");

    for(i = 0; i < numberOfProcesses; i++) {
        printf("P%d\t\t%d\t\t%d\t\t%d\n", i, burstTime[i], waitingTime[i], turnaroundTime[i]);
    }

    printf("\nAverage Waiting Time: %.2f", totalWaitingTime / numberOfProcesses);
    printf("\nAverage Turnaround Time: %.2f\n", totalTurnaroundTime / numberOfProcesses);

    return 0;
}
