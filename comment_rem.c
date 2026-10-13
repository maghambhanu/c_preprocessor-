#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int cnt;
void *readfromfile(char *filename)
{
	char (*lines)[100]=NULL;
	FILE*fptr=NULL;
	char str[100];
	fptr=fopen(filename,"r");
	if(fptr==NULL)
	{
		printf("failed to open\n");
		exit(0);
	}
	while(fgets(str,100,fptr))
	{
		lines=realloc(lines,(cnt+1)*sizeof(str));
		strcpy(lines[cnt],str);
		cnt++;
	}
	fclose(fptr);
	return lines;
}
void *rmcomment(char (*lines)[100])
{
	int i,n,count=0,col=0;
	char *found;
	char *line=NULL;
	for(i=0;i<cnt;i++)
	{
		line=lines[i];
		while(*line!='\n')
		{
			if(*line=='"')
			{
				col++;
			}
			if(col==2)
			{
				col=0;
			}
		 	if((*line=='/')&&(col!=1))
			{
				if((*(line+1)=='/'))
				{
		   			found=line;
					while((*found!='\n')&&(*found!='\0'))
					{
 			  			found++;
					}
					memmove(line,found,strlen(found)+1);
				}
				else if(*(line+1)=='*')
				{

					found=line+2;
					while(*found)
					{
					if(*found=='\n')
					{
						memmove(line,found,strlen(line)+1);
						line=lines[++i];
						found=line;
					}
					else if(*found=='*'&&(*(found+1)=='/'))
					{
						memset(line,' ',(found-line)+2);
						break;
					}
					found++;
					}
					/*while((*found!='*')&&(*found+1!='/'))
					{
						if((*found=='\n')&&(*found!='/'))
					    	{
						//	found='\0';
							n=strlen(line);
							memmove(line,found,strlen(found)+1);							
							line=lines[++i];
							found=line;
						}
					found++;	
					}
					
					n=(found-line)+2;
					//memmove(line,line+n,strlen(line+n)+1);
					memset(line,32,n);*/
				}
			}
			line++;
		}

	}
	return lines;
}
/*void writefile(char (*lines)[100],char *filename)
{
	FILE *fptr=NULL;
	int i;
	fptr=fopen(filename,"w");
	for(i=0;i<cnt;i++)
	{
		fputs(lines[i],fptr);
	}
	fclose(fptr);
}*/
void header(char (*lines)[100],char *filename);

void *macroreplace(char (*lines)[100]);
int main(int argc,char *argv[])

{
	char ch='\n';
	char (*lines)[100]=NULL;
	if(argc!=3)
	{
		printf("invalid input\n");
		exit(0);
	}
	lines=readfromfile(argv[1]);
	lines=rmcomment(lines);
	//writefile(lines,argv[2]);
	lines=macroreplace(lines);
	header(lines,argv[2]);
}
