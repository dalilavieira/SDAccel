#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */

/* Type definitions */
typedef  int /*<<< orphan*/  WORD ;

/* Variables and functions */
 int AnalyzeFile () ; 
 int /*<<< orphan*/  BOLD ; 
 int /*<<< orphan*/  GetStdHandle (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ITALIC ; 
 int MAXLINE ; 
 int /*<<< orphan*/  NORMAL ; 
 int OpenFlag ; 
 int /*<<< orphan*/  STD_OUTPUT_HANDLE ; 
 int /*<<< orphan*/  SetConsoleTextAttribute (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int _countof (char**) ; 
 scalar_t__ fclose (int /*<<< orphan*/ *) ; 
 scalar_t__ fgets (char*,int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * fopen (char*,char*) ; 
 int /*<<< orphan*/  free (char*) ; 
 scalar_t__ malloc (int) ; 
 int /*<<< orphan*/ * manfile ; 
 char* manpath ; 
 int /*<<< orphan*/  printf (char*,char*) ; 
 scalar_t__ putchar (char) ; 
 int /*<<< orphan*/  puts (char*) ; 
 char* strcat (char*,char*) ; 
 int /*<<< orphan*/  strcmp (char*,char*) ; 
 int /*<<< orphan*/  strcpy (char*,char*) ; 

void
SetCl(WORD cl)
{
 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),cl);
}

int
OpenF(char* name)
{
    int retval=0;
    char *manpath_local=(char*)malloc(sizeof(char)*MAXLINE);

    strcpy(manpath_local, manpath); //save mandir value

    if((manfile=fopen((strcat(manpath_local,name)),"r"))!=NULL)
     {
      OpenFlag=1;
      AnalyzeFile();
     }
    else
     retval=-1;

    free(manpath_local);
    return retval;
}

int
CloseF()
{
    int retval=0;

    if(fclose(manfile))
     OpenFlag=0;
    else retval=-1;

    return retval;
}

void
Usage()
{
    puts("usage: man [command]");
    puts("see \"man man\" for details");
}

int
AnalyzeArgv(char *argument)
{
    int element;
    char HelpFlag=0;
    char *keys[]={"--help","/h","/?","-h"};
    char *sections[]={".1",".2",".3",".4",".5",".6",".7",".8",".9"};
    char *filename=(char*)malloc(sizeof(char)*MAXLINE);

    strcpy(filename,argument); //save argument value

    for(element=0;element<_countof(keys);element++)
    {
     if(!strcmp(keys[element],argument))
     {
      Usage();
      HelpFlag=1;
     }
    }

   element = 0;

   if(!HelpFlag)
   {

   if(OpenF(filename))
   {
    while(element<_countof(sections)&&OpenF(strcat(filename,sections[element])))
    {
     strcpy(filename,argument);
     element++;
    }

    if(element>=_countof(sections)) printf("No manual for %s\n",argument);
   }

   }

    return element;
}

void sh_outp(char *cur_string)
{
    int symbol;
    putchar('\n');
    putchar('\n');
    for(symbol=3;putchar(cur_string[symbol]); symbol++);
}

void th_outp(char *cur_string, char *THtag)
{
    int symbol;
    putchar('\n');
    putchar('\n');
    putchar('\t');
    putchar('\t');
    SetCl(ITALIC);
     for(symbol=3;putchar(THtag[symbol]); symbol++);
    putchar('\n');
    SetCl(NORMAL);
}

void text_outp(char *cur_string)
{
    int symbol=0;

    if(cur_string[0]=='.')
        while(cur_string[symbol]!=' ')
            symbol++;


    for(;cur_string[symbol]!='\n'; symbol++)
        putchar(cur_string[symbol]);
        putchar(' ');
}

int
AnalyzeFile()
{
    char *cur_string=(char*)malloc(sizeof(char)*MAXLINE);
    char *THtag=(char*)malloc(sizeof(char)*MAXLINE);




    while(fgets(cur_string,MAXLINE,manfile))

/* TAGs processing */
     if((cur_string[0]=='.')&&(cur_string[1]=='S')&&
       (cur_string[2]=='H')) // .SH tag
      {
       SetCl(BOLD);
       sh_outp(cur_string);
       SetCl(NORMAL);
      }
     else
     if((cur_string[0]=='.')&&(cur_string[1]=='I')&&
       (cur_string[2]==' ')) // .I tag
      {
       SetCl(ITALIC);
       text_outp(cur_string);
       SetCl(NORMAL);
      }
     else
     if((cur_string[0]=='.')&&(cur_string[1]=='/')&&
       (cur_string[2]=='\"')); // ./" tag (comment)

     else
     if((cur_string[0]=='.')&&(cur_string[1]=='T')&&
       (cur_string[2]=='H')) // .TH tag
      {
       strcpy(THtag,cur_string);
      }
     else
     if((cur_string[0]=='.')&&(cur_string[1]=='B')&&
       (cur_string[2]==' ')) // .B tag
      {
       SetCl(BOLD);
       text_outp(cur_string);
       SetCl(NORMAL);
      }
      else
      if((cur_string[0]=='.')&&(cur_string[1]=='N')&&
        (cur_string[2]=='L'))
       {
        putchar('\n');
        putchar(' ');
       }

     else text_outp(cur_string); // print plane text
     th_outp(cur_string, THtag);
/* END of TAGs processing */
     free(cur_string);
     free(THtag);

     return 0;
}

int
main(int argc, char *argv[])
{

  switch(argc)
    {
     case 1:  Usage(); break;
     case 2:  AnalyzeArgv(argv[1]);break;
     default: Usage();break;
    }

   if(OpenFlag)CloseF();
   SetCl(NORMAL);
   return 0;
}

