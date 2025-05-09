#include <stdio.h>

int main() {
    int processId[20], burstTime[20], waitingTime[20], turnaroundTime[20];
    int i, j, numberOfProcesses, temp;
    float totalWaitingTime = 0, totalTurnaroundTime = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &numberOfProcesses);

    for(i = 0; i < numberOfProcesses; i++) {
        processId[i] = i;
        printf("Enter Burst Time for Process %d: ", i);
        scanf("%d", &burstTime[i]);
    }

    // Sort processes by burst time (SJF Scheduling)
    for(i = 0; i < numberOfProcesses - 1; i++) {
        for(j = i + 1; j < numberOfProcesses; j++) {
            if(burstTime[i] > burstTime[j]) {
                // Swap burst time
                temp = burstTime[i];
                burstTime[i] = burstTime[j];
                burstTime[j] = temp;

                // Swap process ID to maintain consistency
                temp = processId[i];
                processId[i] = processId[j];
                processId[j] = temp;
            }
        }
    }

    // Calculate waiting time and turnaround time
    waitingTime[0] = 0;
    turnaroundTime[0] = burstTime[0];
    totalWaitingTime = 0;
    totalTurnaroundTime = turnaroundTime[0];

    for(i = 1; i < numberOfProcesses; i++) {
        waitingTime[i] = waitingTime[i - 1] + burstTime[i - 1];
        turnaroundTime[i] = waitingTime[i] + burstTime[i];

        totalWaitingTime += waitingTime[i];
        totalTurnaroundTime += turnaroundTime[i];
    }

    // Display results
    printf("\nPROCESS\tBURST TIME\tWAITING TIME\tTURNAROUND TIME\n");
    for(i = 0; i < numberOfProcesses; i++) {
        printf("P%d\t\t%d\t\t%d\t\t%d\n", processId[i], burstTime[i], waitingTime[i], turnaroundTime[i]);
    }

    printf("\nAverage Waiting Time: %.2f", totalWaitingTime / numberOfProcesses);
    printf("\nAverage Turnaround Time: %.2f\n", totalTurnaroundTime / numberOfProcesses);

    return 0;
}
