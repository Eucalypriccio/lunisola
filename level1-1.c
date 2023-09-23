#include<stdio.h>
#include<stdlib.h>

int main()
{
	int i;
	int depa;	//passenger
	int dest;	//destination
	int elev[3]={0};	//elevator
	int time[3]={0};
	int number[3]={0};
	scanf("%d,%d,%d", &depa, &dest, &elev[0]);
	
	elev[1]=depa;
	time[1]=time[0]+abs(depa-elev[0]);
	number[1]=number[0]+1;
	
	elev[2]=dest;
	time[2]=time[1]+abs(depa-dest);
	number[2]=number[1]-1;
	
	printf("elevator	");
	for(i=0;i<3;i++)
	{
		printf("%d\t", elev[i]);
		if(i==2)
			printf("\n");
	}
	printf("time		");
	for(i=0;i<3;i++)
	{
		printf("%d\t", time[i]);
		if(i==2)
			printf("\n");
	}
	printf("number		");
	for(i=0;i<3;i++)
	{
		printf("%d\t", number[i]);
		if(i==2)
			printf("\n");
	}
	return 0;
}