#include<stdio.h>
#include<stdlib.h>

void main(){
int n, i, bt[20], wt[20], tat[20];
printf("Enter number of processes: ");
scanf("%d",&n);
printf("Enter burst time of processes in order:\n");
for(i=0; i<n; i++){
scanf("%d",&bt[i]);
}
float wtavg=0, tatavg=bt[0];
wt[0]=0;
tat[0]=bt[0];
for(int i=1; i<n; i++){
wt[i]=bt[i-1]+wt[i-1];
tat[i]=tat[i-1]+bt[i];
wtavg=wtavg+wt[i];
tatavg=tatavg+tat[i];
}
wtavg=wtavg/n;
tatavg=tatavg/n;
printf("\nProcess\t\tBurst Time\tTurn Around Time\tWaiting Time\n");
for(int i=0; i<n; i++){
printf("%d\t\t%d\t\t%d\t\t\t%d\n",i+1,bt[i],tat[i],wt[i]);
}
printf("\nAverage turn around time = %f\n",tatavg);
printf("Average wait time = %f",wtavg);
}