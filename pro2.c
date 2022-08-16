#include<stdio.h>
#include<stdlib.h>
int stoi(char *s)
{
	int i=0;
	int n=0;
	while(s[i]!='\n')
	{
		n=n*10+(int)(s[i]-'0');
		i++;
	}
	return n;
}
int main(int a, char *b[])
{	
	FILE *fp=fopen(b[1],"r");
	char s[100];
	int intans;
	int marks=0;
	int cnt=0;
	int score=0;
	while(!feof(fp))
	{
		fgets(s,100,fp);
		if(s[0]=='&')
		{
			//printf("%c",s[1]);
			marks=stoi(s+1);
			printf("%d marks",marks);
			//return 1;
		}
		else 
		{
			if((s[0]=='#')||(s[0]=='$'))
			{
				if(s[0]=='$')
				{
					intans=stoi(s+1);
					int	givenans;
					scanf("%d",&givenans);
					if(givenans==intans)
					{
						printf("correct ans\n");
						score+=marks;
					}			
					else
					{
						printf("wrong answer\n");
						printf("correct answer %d\n",intans);
					}
					cnt+=marks;
													  
				}
				else
				{
					char mcqans;
					char s1[2];
					scanf("%s",s1);
					if(s1[0]==s[1])
					{
						printf("correct ans\n");
						score+=marks;
					}
					else
					{
						printf("wrong answer\n");
						printf("correct answer %c\n",s[1]);
					}
					cnt+=marks;
				}

										
			}
		
			else
			{
				printf("%s",s);
			}
		}
		}
		printf("marks obtained %d/%d",score,cnt);
		return 0;
	}
	
	
