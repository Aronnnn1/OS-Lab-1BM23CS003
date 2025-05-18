#include<stdio.h>

void sort(int deadline[], int exec[], int rem[], int task[], int period[], int n, int curr) {
    int temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            // Sort tasks by their deadline at the current time
            if (deadline[i] > deadline[j]) {
                temp = deadline[i]; deadline[i] = deadline[j]; deadline[j] = temp;
                temp = exec[i]; exec[i] = exec[j]; exec[j] = temp;
                temp = rem[i]; rem[i] = rem[j]; rem[j] = temp;
                temp = task[i]; task[i] = task[j]; task[j] = temp;
                temp = period[i]; period[i] = period[j]; period[j] = temp;
            }
        }
    }
}

void main() {
    int n, total_time;
    printf("Enter number of tasks: ");
    scanf("%d", &n);
    
    printf("Enter total execution time: ");
    scanf("%d", &total_time);
    
    int period[n], exec[n], rem[n], task[n], deadline[n];
    
    // Input execution time, period, and deadline for each task
    for (int i = 0; i < n; i++) {
        printf("Enter execution time, deadline, and period for Task %d: ", i + 1);
        scanf("%d %d %d", &exec[i], &deadline[i], &period[i]);
        rem[i] = exec[i]; // Initialize remaining time for each task
        task[i] = i + 1;
    }
    
    int curr = 0;
    while (curr < total_time) {
        // Sort tasks based on their deadline (EDF scheduling)
        sort(deadline, exec, rem, task, period, n, curr);
        
        int executed = 0;
        
        // Execute the task with the earliest deadline
        for (int i = 0; i < n; i++) {
            if (rem[i] > 0) {
                printf("Time %d: Executing Task %d\n", curr, task[i]);
                rem[i]--;
                executed = 1;
                break;
            }
        }
        
        // If no task can be executed, CPU is idle
        if (!executed) {
            printf("Time %d: Idle\n", curr);
        }
        
        curr++;

        // Reset task remaining time and deadlines at the end of each period
        for (int i = 0; i < n; i++) {
            if (curr % period[i] == 0) {
                rem[i] = exec[i];  // Reset the remaining time to execution time
                deadline[i] = curr + period[i]; // Reset the deadline to the next period
            }
        }
    }
    printf("\nExecution completed for %d seconds.\n", total_time);
}
