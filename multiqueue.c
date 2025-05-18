#include<stdio.h>

void main(){
int n, iu=0, is=0, i, b;
float wt_avg, tat_avg;
printf("Enter no of processes: ");
scanf("%d", &n);
int p[n], up[n], sp[n], ubt[n], sbt[n], bt[n], u[n], wt[n], tat[n];
for(int j=0; j<n; j++){
printf("Enter System/User process (1/0): ");
scanf("%d",&i);
printf("Enter burst time: ");
scanf("%d",&b);
if(i==1){
sp[is]=j+1;
sbt[is++]=b;
}
else{
up[iu]=j+1;
ubt[iu++]=b;
}
}
for(int j=0; j<is; j++){
p[j]=sp[j];
bt[j]=sbt[j];
u[j]=1;
}
for(int j=0; j<iu; j++){
p[j+is]=up[j];
bt[j+is]=ubt[j];
u[j+is]=0;
}
wt[0]=0;
tat[0]=bt[0];
wt_avg=wt[0];
tat_avg=tat[0];
for(int j=1; j<n; j++){
wt[j]=wt[j-1]+bt[j-1];
tat[j]=tat[j-1]+bt[j];
wt_avg+=wt[j];
tat_avg+=tat[j];
}
printf("Process\t System/User Process\t Burst Time\t Waiting Time\t Turn Around Time\n");
for(int j=0; j<n; j++){
printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", p[j], u[j], bt[j], wt[j], tat[j]);
}
printf("\nAverage waiting time = %f", wt_avg/n);
printf("\nAverage turn around time = %f", tat_avg/n);
}