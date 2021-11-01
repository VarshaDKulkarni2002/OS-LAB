#include<stdio.h>
#include<stdlib.h>
int SJF(int burst[],int n,int processor[]){
int pos,temp,i;
int  wait[20],turn[20];
for(int i=0;i<n;i++){
pos=i;
	for(int j=i+1;j<n;j++)
	{
		if(burst[pos]>burst[j])
			pos=j;
	
	}
if(pos!=i){
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
float totalturn=0;
for(i=0;i<n;i++){
	total=burst[i]+wait[i];
	turn[i]=total;
	totalturn+=turn[i];
}
float average_waitint_time=total/n;
float avaerage_turn_time=totalturn/n;


printf("processor	burst time	waiting time	turn around time\n");
for(int i=0;i<n;i++)
	printf("%d		%d		%d		%d\n",processor[i],burst[i],wait[i],turn[i]);
printf("Average waiting time is %f\nAverage turn around time is %f\n",average_waitint_time,avaerage_turn_time);

}
int main(){
int n,i,burst[20],processor[20];
label:
printf("****SHORTEST JOB FIRST****\n\n");
printf("Enter the number of processes :  \n");
scanf("%d",&n);
for(int i=0;i<n;i++){
	printf("Enter burst time of  processor %d : ",i+1);
	scanf("%d",&burst[i]);
	processor[i]=i+1;
	printf("\n");
	
}
SJF(burst,n,processor);
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
