#include<stdio.h>
#include<stdlib.h>
int PJS(int prior[],int burst[],int n,int processor[]){
int pos,temp,i;
int  wait[20],turn[20];
for(int i=0;i<n;i++){
pos=i;
	for(int j=i+1;j<n;j++)
	{
		if(prior[pos]>prior[j])
			pos=j;
	
	}
if(pos!=i){
temp=prior[i];
prior[i]=prior[pos];
prior[pos]=temp;

temp=burst[i];
burst[i]=burst[pos];
burst[pos]=temp;

temp=processor[i];
processor[i]=processor[pos];
processor[pos]=temp;


}
}
float total=0;

wait[0]=0;
for(i=1;i<n;i++)
{
	wait[i]=0;
	for(int j=0;j<i;j++)
		wait[i]+=burst[j];
	total+=wait[i];
}
float average_waiting_time=total/n;
float totalturn=0;
for(i=0;i<n;i++){
	total=burst[i]+wait[i];
	turn[i]=total;
	totalturn+=turn[i];
}

float average_turn_time=totalturn/n;


printf("job   Priority     burst time	 waiting time	  turn around time\n");
for(int i=0;i<n;i++)
	printf("%d	%d		%d		%d		%d\n",processor[i],prior[i],burst[i],wait[i],turn[i]);
printf("Average waiting time is %f\nAverage turn around time is %f\n",average_waiting_time,average_turn_time);

}
int main(){
int n,i,burst[20],processor[20];
int prior[20];
label:
printf("****PRIORITY JOB SCHEDULING****\n\n");
printf("Enter the number of jobs :  \n");
scanf("%d",&n);
for(int i=0;i<n;i++){
	printf("Enter burst time of  processor %d : ",i+1);
	scanf("%d",&burst[i]);
	printf("Enter the priority of processor %d:",i+1);
	
	scanf("%d",&prior[i]);
	processor[i]=i+1;
	printf("\n");
	
}
PJS(prior,burst,n,processor);
int ch;
printf("Press 0 to exit process\nPress any key to continue\n");
scanf("%d",&ch);
if(ch==0)
	return 0;
else { 
        getchar();
	goto label;
	
}




}
