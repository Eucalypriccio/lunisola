#include<stdio.h>
#include<stdlib.h>

int min(int a, int b, int c);
int mid(int a, int b, int c);
int max(int a, int b, int c);

int main()
{
	int i;
	int depa[3];
	int dest[3];
	int elev[7]={1};
	int time[7]={0};
	int number[7]={0};
	
	for(i=0;i<3;i++)
		scanf("%d,", &depa[i]);
	for(i=0;i<3;i++)
		scanf("%d,", &dest[i]);
	
	int begin[10]={0};
	for(i=0;i<3;i++)
	{
		begin[depa[i]-1]+=1;
	}
	int end[10]={0};
	for(i=0;i<3;i++)
	{
		end[dest[i]-1]+=1;
	}
	
	elev[1]=min(depa[0], depa[1], depa[2]);
	time[1]=abs(elev[1]-elev[0]);
	number[1]=begin[elev[1]-1];
	
	if(number[1]==1)//situation 1
	{
		elev[2]=mid(depa[0], depa[1], depa[2]);
		time[2]=time[1]+abs(elev[2]-elev[1]);
		if(begin[elev[2]-1]==1)
		{
			number[2]=2;
			elev[3]=max(depa[0], depa[1], depa[2]);
			time[3]=time[2]+abs(elev[3]-elev[2]);
			number[3]=3;
			
			elev[4]=min(dest[0], dest[1], dest[2]);
			time[4]=time[3]+abs(elev[4]-elev[3]);
			if(end[elev[4]-1]==1)
			{
				number[4]=2;
				elev[5]=mid(dest[0], dest[1], dest[2]);
				time[5]=time[4]+abs(elev[5]-elev[4]);
				if(end[elev[5]-1]==1)
				{
					number[5]=1;
					elev[6]=max(dest[0], dest[1], dest[2]);
					time[6]=time[5]+abs(elev[6]-elev[5]);
					number[6]=0;
				}
			}	
			else if(end[elev[4]-1]==2)
			{
				number[4]=1;
				elev[5]=max(dest[0], dest[1], dest[2]);
				time[5]=time[4]+abs(elev[5]-elev[4]);
				number[5]=0;
			}
			else number[4]=0;
		}
		else if(begin[elev[2]-1]==2)
		{
			number[2]=3;
			elev[3]=min(dest[0], dest[1], dest[2]);
			time[3]=time[2]+abs(elev[3]-elev[2]);
			if(end[elev[3]-1]==1)
			{
				number[3]=2;
				elev[4]=mid(dest[0], dest[1], dest[2]);
				time[4]=time[3]+abs(elev[4]-elev[3]);
				if(end[elev[4]-1]==1)
				{
					number[4]=1;
					elev[5]=max(dest[0], dest[1], dest[2]);
					time[5]=time[4]+abs(elev[5]-elev[4]);
					number[5]=0;
				}
			}	
			else if(end[elev[3]-1]==2)
			{
				number[3]=1;
				elev[4]=max(dest[0], dest[1], dest[2]);
				time[4]=time[3]+abs(elev[4]-elev[3]);
				number[4]=0;
			}
			else number[3]=0;
		}
	}
	if(number[1]==2)//situation 2
	{
		elev[2]=max(depa[0], depa[1], depa[2]);
		time[2]=time[1]+abs(elev[2]-elev[1]);
		number[2]=3;
		
		elev[3]=min(dest[0], dest[1], dest[2]);
		time[3]=time[2]+abs(elev[3]-elev[2]);
		if(end[elev[3]-1]==1)
		{
			number[3]=2;
			elev[4]=mid(dest[0], dest[1], dest[2]);
			time[4]=time[3]+abs(elev[4]-elev[3]);
			if(end[elev[4]-1]==1)
			{
				number[4]=1;
				elev[5]=max(dest[0], dest[1], dest[2]);
				time[5]=time[4]+abs(elev[5]-elev[4]);
				number[5]=0;
			}
		}	
		else if(end[elev[3]-1]==2)
		{
			number[3]=1;
			elev[4]=max(dest[0], dest[1], dest[2]);
			time[4]=time[3]+abs(elev[4]-elev[3]);
			number[4]=0;
		}
		else number[3]=0;
	}
	if(number[1]==3)//situation 3
	{
		elev[2]=min(dest[0], dest[1], dest[2]);
		time[2]=time[1]+abs(elev[2]-elev[1]);
		if(end[elev[2]-1]==1)
		{
			number[2]=2;
			elev[3]=mid(dest[0], dest[1], dest[2]);
			time[3]=time[2]+abs(elev[3]-elev[2]);
			if(end[elev[3]-1]==1)
			{
				number[3]=1;
				elev[4]=max(dest[0], dest[1], dest[2]);
				time[4]=time[3]+abs(elev[4]-elev[3]);
				number[4]=0;
			}
		}	
		else if(end[elev[2]-1]==2)
		{
			number[2]=1;
			elev[3]=max(dest[0], dest[1], dest[2]);
			time[3]=time[2]+abs(elev[3]-elev[2]);
			number[3]=0;
		}
		else number[2]=0;
	}
	
	printf("elevator	");
	for(i=0;i<7;i++)
	{
		printf("%d\t", elev[i]);
		if(i==6)
			printf("\n");
	}
	printf("time		");
	for(i=0;i<7;i++)
	{
		printf("%d\t", time[i]);
		if(i==6)
			printf("\n");
	}
	printf("number		");
	for(i=0;i<7;i++)
	{
		printf("%d\t", number[i]);
		if(i==6)
			printf("\n");
	}
	return 0;
}

int min(int a, int b, int c)
{
	int ret;
	if(a<=b&&a<=c)
		ret=a;
	else if(b<=a&&b<=c)
		ret=b;
	else if(c<=a&&c<=b)
		ret=c;
		
	return ret;
}
int mid(int a, int b, int c)
{
	int ret;
	if((a<=b&&a>=c)||(a<=c&&a>=b))
		ret=a;
	else if((b<=a&&b>=c)||(b<=c&&b>=a))
		ret=b;
	else if((c<=a&&c>=b)||(c<=b&&c>=a))
		ret=c;
		
	return ret;
}
int max(int a, int b, int c)
{
	int ret;
	if(a>=b&&a>=c)
		ret=a;
	else if(b>=a&&b>=c)
		ret=b;
	else if(c>=a&&c>=b)
		ret=c;
		
	return ret;
}