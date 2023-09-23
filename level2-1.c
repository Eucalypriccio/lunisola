//FCFS+SSTF algorithm is adopted in this situation.
//Passengers'starting floor and terminal floor are both different from each other's.
//每个用户呼叫时间都不同
#include<stdio.h>
#include<stdlib.h>

int mid(int a, int b, int c);
int max(int a, int b, int c);

int main()
{
    int i;
    int depa[3];
    int dest[3];
    int moment[3];
    int elev[7]={1};
	int time[7]={0};
	int number[7]={0};
    int index1, index2, index3;

    for(i=0;i<3;i++)
	{	
        scanf("%d,", &depa[i]);
    }
	for(i=0;i<3;i++)
	{	
        scanf("%d,", &dest[i]);
    }
    for(i=0;i<3;i++)
    {	
        scanf("%d,", &moment[i]);
    }
    
    for(i=0;i<3;i++)
    {
        if(moment[i]==0)
            index1=i;
    }
    
    elev[1]=depa[index1];
    time[1]=elev[1]-elev[0];
    number[1]=1;

    for(i=0;i<3;i++)
    {
        if(moment[i]==mid(moment[0], moment[1], moment[2]))
            index2=i;
    }

    for(i=0;i<3;i++)
    {
        if(moment[i]==max(moment[0], moment[1], moment[2]))
            index3=i;
    }

    if(dest[index1]!=depa[index2])
    {
        if(moment[index2]>=(dest[index1]-elev[1]))//先送第一个人，再接第二个人
        {
            elev[2]=dest[index1];
            time[2]=time[1]+abs(elev[2]-elev[1]);
            number[2]=0;

            elev[3]=depa[index2];
            time[3]=time[2]+abs(elev[3]-elev[2]);
            number[3]=1;

            if(dest[index2]!=depa[index3])
            {
                if(moment[index3]<=time[3])//第三个人已经在等了
                {
                    if(abs(dest[index2]-elev[3])<=abs(depa[index3]-elev[3]))//先送第二个人，再接第三个人
                    {
                        elev[4]=dest[index2];
                        time[4]=time[3]+abs(elev[4]-elev[3]);
                        number[4]=0;
                        elev[5]=depa[index3];
                        time[5]=time[4]+abs(elev[5]-elev[4]);
                        number[5]=1;
                        elev[6]=dest[index3];
                        time[6]=time[5]+abs(elev[6]-elev[5]);
                        number[6]=0;
                    }
                    if(abs(dest[index2]-elev[3])>abs(depa[index3]-elev[3]))//先接第三个人
                    {
                        elev[4]=depa[index3];
                        time[4]=time[3]+abs(elev[4]-elev[3]);
                        number[4]=2;
                        if(abs(dest[index2]-elev[4])<=abs(dest[index3]-elev[4]))//先送第二个人
                        {
                            elev[5]=dest[index2];
                            time[5]=time[4]+abs(elev[5]-elev[4]);
                            number[5]=1;
                            elev[6]=dest[index3];
                            time[6]=time[5]+abs(elev[6]-elev[5]);
                            number[6]=0;
                        }
                        else//先送第三个人
                        {
                            elev[5]=dest[index3];
                            time[5]=time[4]+abs(elev[5]-elev[4]);
                            number[5]=1;
                            elev[6]=dest[index2];
                            time[6]=time[5]+abs(elev[6]-elev[5]);
                            number[6]=0;
                        }
                    }
                }
                if(moment[index3]>time[3])//第三个人还没按键
                {
                    elev[4]=dest[index2];
                    time[4]=time[3]+abs(elev[4]-elev[3]);
                    number[4]=0;
                    elev[5]=depa[index3];
                    time[5]=time[4]+abs(elev[5]-elev[4]);
                    number[5]=1;
                    elev[6]=dest[index3];
                    time[6]=time[5]+abs(elev[6]-elev[5]);
                    number[6]=0;
                }
            }
        }
        if(moment[index2]<(dest[index1]-elev[1]))//先接第二个人
        {
            elev[2]=depa[2];
            time[2]=time[1]+abs(elev[2]-elev[1]);
            number[2]=2;
            elev[3]=dest[index1];
            time[3]=time[2]+abs(elev[3]-elev[2]);//送完第一个人
            if(dest[index1]==depa[index3])
            {
                number[3]=2;
                if(abs(dest[index2]-elev[3])<=abs(dest[index3]-elev[3]))//先送第二个人
                {
                    elev[4]=dest[index2];
                    time[4]=time[3]+abs(elev[4]-elev[3]);
                    number[4]=1;
                    elev[5]=dest[index3];
                    time[5]=time[4]+abs(elev[5]-elev[4]);
                    number[5]=0;
                }
                else//先送第三个人
                {
                    elev[4]=dest[index3];
                    time[4]=time[3]+abs(elev[4]-elev[3]);
                    number[4]=1;
                    elev[5]=dest[index2];
                    time[5]=time[4]+abs(elev[5]-elev[4]);
                    number[5]=0;
                }
            }
            else
            {
                number[3]=1;
                if(abs(dest[index2]-elev[3])<=abs(depa[index3]-elev[3]))//先送第二个人，再接第三个人
                {
                    elev[4]=dest[index2];
                    time[4]=time[3]+abs(elev[4]-elev[3]);
                    number[4]=0;
                    elev[5]=depa[index3];
                    time[5]=time[4]+abs(elev[5]-elev[4]);
                    number[5]=1;
                    elev[6]=dest[index3];
                    time[6]=time[5]+abs(elev[6]-elev[5]);
                    number[6]=0;
                }
                else//先接第三个人
                {
                    if(abs(dest[index2]-elev[3])<=abs(dest[index3]-elev[3]))//先送第二个人
                    {
                        elev[4]=dest[index2];
                        time[4]=time[3]+abs(elev[4]-elev[3]);
                        number[4]=1;
                        elev[5]=dest[index3];
                        time[5]=time[4]+abs(elev[5]-elev[4]);
                        number[5]=0;
                    }
                    else//先送第三个人
                    {
                        elev[4]=dest[index3];
                        time[4]=time[3]+abs(elev[4]-elev[3]);
                        number[4]=1;
                        elev[5]=dest[index2];
                        time[5]=time[4]+abs(elev[5]-elev[4]);
                        number[5]=0;
                    }
                }
            }  
        }
    }
    if(dest[index1]==depa[index2])//第一个人下，第二个人上
    {
        elev[2]=depa[index2];
        time[2]=time[1]+abs(elev[2]-elev[1]);
        number[2]=1;
        if(moment[index3]<=time[2])//第三个人已经在等了
        {
            if(dest[index2]!=depa[index3])
            {
                if(abs(dest[index2]-elev[2])<=abs(depa[index3]-elev[2]))//先送第二个人
                {
                    elev[3]=dest[index2];
                    time[3]=time[2]+abs(elev[3]-elev[2]);
                    number[3]=0;
                    elev[4]=depa[index3];
                    time[4]=time[3]+abs(elev[4]-elev[3]);
                    number[4]=1;
                    elev[5]=dest[index3];
                    time[5]=time[4]+abs(elev[5]-elev[4]);
                    number[5]=0;
                }
                else //先接第三个人
                {
                    elev[3]=depa[index3];
                    time[3]=time[2]+abs(elev[3]-elev[2]);
                    number[3]=2;
                    if(abs(dest[index2]-elev[3])<=abs(dest[index3]-elev[3]))//先送第二个人
                    {
                        elev[4]=dest[index2];
                        time[4]=time[3]+abs(elev[4]-elev[3]);
                        number[4]=1;
                        elev[5]=dest[index3];
                        time[5]=time[4]+abs(elev[5]-elev[4]);
                        number[5]=0;
                    }
                    else//先送第三个人
                    {
                        elev[4]=dest[index3];
                        time[4]=time[3]+abs(elev[4]-elev[3]);
                        number[4]=1;
                        elev[5]=dest[index2];
                        time[5]=time[4]+abs(elev[5]-elev[4]);
                        number[5]=0;
                    }
                }
            }
            if(dest[index2]==depa[index3])
            {
                elev[3]=dest[index2];
                time[3]=time[2]+abs(elev[3]-elev[2]);
                number[3]=1;
                elev[4]=dest[index3];
                time[4]=time[3]+abs(elev[4]-elev[3]);
                number[4]=0;
            }
        }
        else//第三个人还没按键
        {
            elev[3]=dest[index2];
            time[3]=time[2]+abs(elev[3]-elev[2]);
            if(dest[index2]!=depa[index3])
            {
                number[3]=0;
                elev[4]=depa[index3];
                time[4]=time[3]+abs(elev[4]-elev[3]);
                number[4]=1;
                elev[5]=dest[index3];
                time[5]=time[4]+abs(elev[5]-elev[4]);
                number[5]=0;
            }
            else
            {
                number[3]=1;
                elev[4]=dest[index3];
                time[4]=time[3]+abs(elev[4]-elev[3]);
                number[4]=0;
            }
        }
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