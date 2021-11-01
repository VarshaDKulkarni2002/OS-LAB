#include<stdio.h>
#include<stdlib.h>
void round_robin(int * burst,int n,int tq,int * processor){
   int *remaining_times = (int *)malloc(sizeof(int) * n);
int *wait= (int *)malloc(sizeof(int) * n);
int *turn= (int *)malloc(sizeof(int) * n);
    int remaining_processes = n, time = 0, process_number = 0, flag = 1;
    float total_wait_time = 0;
    

    for (int i = 0; i < n; i++)
        remaining_times[i] = burst[i];

    while (1)
    {
        flag = 1;
        for (int i = 0; i < n; i++)
        {
            if (remaining_times[i] > 0)
            {
                flag = 0;
                if (remaining_times[i] > tq)
                {
                    time += tq;
                    remaining_times[i] -= tq;
                }
                else
                {
                    time += remaining_times[i];
                    wait[i] = time - burst[i];
                    remaining_times[i] = 0;
                }
            }
        }
        if (flag)
            break;
    }

    for (int i = 0; i < n; i++)
        total_wait_time += wait[i];

 float total=0;
/*
wait[0]=0;
for(i=1;i<n;i++)
{
	wait[i]=0;
	for(int j=0;j<i;j++)
		wait[i]+=burst[j];
	total+=wait[i];
}*/
float totalturn=0;
for(int i=0;i<n;i++){
	total=burst[i]+wait[i];
	turn[i]=total;
	totalturn+=turn[i];
}
float average_waitint_time=total_wait_time/n;
float avaerage_turn_time=totalturn/n;


printf("processor	burst time	waiting time	turn around time\n");
for(int i=0;i<n;i++)
	printf("%d		%d		%d		%d\n",processor[i],burst[i],wait[i],turn[i]);
printf("Average waiting time is %f\nAverage turn around time is %f\n",average_waitint_time,avaerage_turn_time);



}



int main(){
int n,i;
int tq;

int *processor = (int *)malloc(sizeof(int) * n);
int *burst= (int *)malloc(sizeof(int) * n);

printf("****Round Robin Job Scheduling****\n\n");

printf("Enter the number of processes :  \n");
scanf("%d",&n);
for(int i=0;i<n;i++){
	
	printf("Enter burst time of  processor %d : ",i+1);
	scanf("%d",&burst[i]);
	processor[i]=i+1;
	printf("\n");
}
printf("Enter  time quantum\n");
scanf("%d",&tq);
	

round_robin(burst,n,tq,processor);
}


