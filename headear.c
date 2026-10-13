#include<stdio.h>
#include<string.h>
#include<stdlib.h>
extern int cnt;
void header(char (*lines)[100],char *filename)
{
	char *line=NULL;
	char *found=NULL;
	char str[100]="#include<";
	char header[100];
	char *head=NULL;
	int n;
        char buff[100];
	char path[100]="/usr/include/";
	for(int i=0;i<cnt;i++)
	{
       		char *p=header;
		line=lines[i];
		found=strstr(line,str);
		if(found!=NULL)
		{
			p=header;
			found=found+9;
			while(*found)
			{
				if(*found=='>')
				{
					break;
				}
				*p=*found;
				found++;
				p++;
			}
			*p='\0';
		}
	}
	puts(header);
	strcat(path,header);
	FILE *src=NULL,*dest=NULL;
        src=fopen(path,"r");
        if(src==NULL)
        {
                printf("failed to open");
        }
	dest=fopen(filename,"w");
	while((n=fread(buff,1,sizeof(buff),src))>0)
	{
		fwrite(buff,1,n,dest);
	}
	char *l=NULL;
	for(int i=0;i<cnt;i++)
	{
		l=strstr(lines[i],str);
		if(l!=NULL)
		{
			continue;
		}
		
		fputs(lines[i],dest);
	}
}

	 
	
