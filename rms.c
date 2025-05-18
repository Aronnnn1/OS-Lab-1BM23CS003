#include<stdio.h>

void sort(int period[], int exec[], int rem[], int task[], int n){
    int temp;
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if(period[i] > period[j]){
                temp = period[i]; period[i] = period[j]; period[j] = temp;
                temp = exec[i]; exec[i] = exec[j]; exec[j] = temp;
                temp = rem[i]; rem[i] = rem[j]; rem[j] = temp;
		temp=task[i]; task[i]=task[j]; task[j]=temp;
            }
        }
    }
}

void main(){
    int n, total_time;
    printf("Enter number of tasks: ");
    scanf("%d", &n);
    
    printf("Enter total execution time: ");
    scanf("%d", &total_time);
    
    int period[n], exec[n], rem[n], task[n];
    for (int i = 0; i < n; i++) {
        printf("Enter execution time and period for Task %d: ", i + 1);
        scanf("%d %d", &exec[i], &period[i]);
        rem[i] = exec[i]; 
	task[i]=i+1;
    }
    
    int curr = 0;
    while (curr < total_time){
        sort(period, exec, rem, task, n);
        int executed = 0;
        
        for (int i = 0; i < n; i++) {
            if (rem[i] > 0) {
                printf("Time %d: Executing Task %d\n", curr, task[i]);
                rem[i]--;
                executed = 1;
                break;
            }
        }
        
        if (!executed) {
            printf("Time %d: Idle\n", curr);
        }
        
        curr++;

        for (int i = 0; i < n; i++) {
            if (curr % period[i] == 0) {
                rem[i] = exec[i];  
            }
        }
    }
    printf("\nExecution completed for %d seconds.\n", total_time);
}