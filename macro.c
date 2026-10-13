#include<stdio.h>
#include<string.h>
#include<stdlib.h>
extern int cnt;
void *macroreplace(char (*lines)[100])
{
	/*FILE *fptr=NULL;
	char (*lines)[100];
	char str[100];
	fptr=fopen(filename,"r");
	if(fptr==NULL)
	{
		printf("failed to open");
		exit(0);
	}
	while((fgets(str,100,fptr))!=NULL)
	{
		lines=realloc(lines,(ct+1)*sizeof(str));
		fputs(lines[ct],fptr);
		ct++;
	}*/
	char *line=NULL;
	char mac[]="#define";
	char take[100]="";
	char exp[100]="";
	int l;
	char *lc=NULL;
	printf("hello");
	for(int i=0;i<cnt;i++)
	{
		line=lines[i];
		if((line=strstr(line,mac))!=NULL)
		{
			line=line+8;
			int j=0,k;
			while(*line!=' ')
			{
				take[j]=*line;
				line++;
				j++;
			}
			take[j]='\0';
			printf("%s",take);
			line+=1;
			while((*line!=' ')&&(*line!='\n')&&(*line!='\0'))
			{
				k=0;
				exp[k]=*line;
				line++;
				k++;
			}
			exp[k]='\0';
			printf("%s",exp);
			for(l=i+1;l<cnt;l++)
			{
				line=lines[l];
				if(line=strstr(line,take))
				{
					if(line!=NULL)
					{
						//memset(line,' ',strlen(take));
						memmove(line,line+(strlen(take)-1),strlen(take)+1);
						memcpy(line,exp,strlen(exp));
					}/*
					int n=strlen(exp)+1;
					line=line+n;
					*line=';';*/
				}
			}

		}
	}
	return lines;
}
	







