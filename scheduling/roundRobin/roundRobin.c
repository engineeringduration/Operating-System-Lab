/*
 * Round Robin Scheduling Algorithm
 * --------------------------------
 * This C program simulates the Round Robin CPU Scheduling algorithm.
 * Each process is assigned a fixed time slot (time quantum).
 * If a process does not finish during its time quantum, it goes to the back of the queue.
 * This continues until all processes have completed.
 *
 * Author: Open Source Contributor
 * License: MIT
 */

#include <stdio.h>

// Main function
int main() {
    // Maximum number of processes supported
    const int MAX_PROCESSES = 10;

    // Variable declarations
    int totalProcesses;
    int burstTime[MAX_PROCESSES];         // Burst time for each process
    int waitingTime[MAX_PROCESSES];       // Waiting time for each process
    int turnaroundTime[MAX_PROCESSES];    // Turnaround time for each process
    int remainingTime[MAX_PROCESSES];     // Remaining burst time for each process
    int currentTime = 0;                  // Simulated system clock
    int timeQuantum;                      // Time slice for each round
    int i, currentProcess;

    float totalWaitingTime = 0.0;
    float totalTurnaroundTime = 0.0;

    // Input: total number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &totalProcesses);

    // Input: burst time for each process
    for (i = 0; i < totalProcesses; i++) {
        printf("Enter Burst Time for Process %d: ", i + 1);
        scanf("%d", &burstTime[i]);

        // Initialize remaining time with burst time
        remainingTime[i] = burstTime[i];
    }

    // Input: time quantum
    printf("Enter the Time Quantum: ");
    scanf("%d", &timeQuantum);

    // Round Robin scheduling loop
    int allProcessesDone;
    do {
        allProcessesDone = 1; // Assume all processes are complete initially

        for (currentProcess = 0; currentProcess < totalProcesses; currentProcess++) {
            // Check if process has remaining burst time
            if (remainingTime[currentProcess] > 0) {
                allProcessesDone = 0; // Found a process that needs CPU time

                if (remainingTime[currentProcess] > timeQuantum) {
                    // Execute process for time quantum
                    currentTime += timeQuantum;
                    remainingTime[currentProcess] -= timeQuantum;
                } else {
                    // Execute process to completion
                    currentTime += remainingTime[currentProcess];
                    waitingTime[currentProcess] = currentTime - burstTime[currentProcess];
                    remainingTime[currentProcess] = 0;
                }
            }
        }
    } while (!allProcessesDone);

    // Calculate Turnaround Time and accumulate totals
    for (i = 0; i < totalProcesses; i++) {
        turnaroundTime[i] = burstTime[i] + waitingTime[i];
        totalWaitingTime += waitingTime[i];
        totalTurnaroundTime += turnaroundTime[i];
    }

    // Output: process-wise results
    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < totalProcesses; i++) {
        printf("%d\t%d\t\t%d\t\t%d\n", i + 1, burstTime[i], waitingTime[i], turnaroundTime[i]);
    }

    // Output: average times
    printf("\nAverage Waiting Time: %.2f", totalWaitingTime / totalProcesses);
    printf("\nAverage Turnaround Time: %.2f\n", totalTurnaroundTime / totalProcesses);

    return 0;
}
