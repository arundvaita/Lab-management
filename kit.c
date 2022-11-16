#include"header.h"
void issue()
{
    int i;
    system("clear");
    for(i=0;i<14;i++)
        printf("\n");
    for(i=0;i<150;i++)
        printf("\033[33m.\033[0m");
    printf("\n");
    printf("\033[4;1;36m.............................................................VECTOR LAB MANGEMENT SYSTEM............................................................\033[0m\n");
    printf("\n\n\033[32m\n\t 8051 KIT REGISTER : ISSUEING.... \033[0m\n\n\n");

    char lcout[10],sid[10];
    char kitid[10];
    printf("\tLC ID : ");
    scanf("%s",lcout);
    printf("\tKit ID : ");
    scanf("%s",kitid);
    printf("\tStudent ID : ");
    scanf("%s",sid);

    FILE *fp=fopen("kitdaily.txt","a");
    fprintf(fp,"%s	%s		%s		%s		%s\n",__DATE__,lcout,kitid,sid, __TIME__ );
    fclose(fp);
}  

void ret()
{
    int i;
    system("clear");
    for(i=0;i<14;i++)
        printf("\n");
    for(i=0;i<150;i++)
        printf("\033[33m.\033[0m");
    printf("\n");
    printf("\033[4;1;36m.............................................................VECTOR LAB MANGEMENT SYSTEM............................................................\033[0m\n");
    printf("\n\n\033[32m\n\t 8051 KIT REGISTER : RETURNING.... \033[0m\n\n\n");

    char lcin[10],remarks[100];
    char kitid[10];
    printf("\tLC ID : ");
    scanf("%s",lcin);
l1: 
    printf("\tKit ID : ");
    scanf("%s",kitid);
    FILE *fp=fopen("kitdaily.txt","r");

    char temp[300];
    while(fgets(temp,300,fp))
    {

        if(strstr(temp,kitid))
        {

            FILE *ft=fopen("kithistory.txt","a");
            i=0;
            while(temp[i]!='\n')
            {
                fputc(temp[i],ft);
                i++;
            }
            fputc('\t',ft);
            printf("\tRemarks: ");
            //scanf("%[^\n]",remarks);///////////////////////////////////////////////////////not working
            scanf("%s",remarks);
            fprintf(ft,"%s		%s		%s\n",lcin,__TIME__,remarks);
            fclose(ft);

            // delete that line
            FILE *ftemp=fopen("tempfile","w+");
            rewind(fp);
         
            char temp1[300];
            while(fgets(temp1,300,fp))
            {
                if(strcmp(temp1,temp))
                    fputs(temp1,ftemp);
            }
            fclose(fp);
            rewind(ftemp);
            fp=fopen("kitdaily.txt","w");
            while(fgets(temp1,300,ftemp))
                fputs(temp1,fp);
            fclose(fp);
            fclose(ftemp);
            remove("tempfile");

            printf("\n\n\033[36m\n\t Returned successfully.... \033[0m\n\n\n");
        sleep(5);
            return;
        }
    }

    printf("\033[5;31;1m Invalid kit-id , check id.. \033[0m \n");
    goto l1;
    // usleep(1000);

}

void searchkit()
{
char kitid[10];
    printf("\tEnter Kit ID for searching : ");
    scanf("%s",kitid);
    FILE *fp=fopen("kitdaily.txt","r");

    char temp[300];
    while(fgets(temp,300,fp))
    {

        if(strstr(temp,kitid))
        {
         printf("\033[5;31;1m Kit is in use...\033[0m \n");
         printf("%s\n",temp);
  fclose(fp);
         usleep(2000);
         sleep(5);
         return;
        }
     }   
fclose(fp);
 printf("\033[5;32;1m Kit is available for issuing  \033[0m \n");
 usleep(2000);
 sleep(5);
 }

void kitlog() // todays log
{
int i;
char temp[300];
 
 system("clear");
    for(i=0;i<14;i++)
        printf("\n");
    for(i=0;i<150;i++)
        printf("\033[33m.\033[0m");
    printf("\n");
    printf("\033[4;1;36m.............................................................VECTOR LAB MANGEMENT SYSTEM............................................................\033[0m\n");
    printf("\n\n\033[32m\n\t 8051 KIT REGISTER TODAY'S LOG \033[0m\n\n\n");
     FILE *fp=fopen("kitdaily.txt","r");

    while(fgets(temp,300,fp))
         printf("%s",temp);
           printf("\n Press any key to exit\n");
           int n;
           scanf("%d",&n);
           
fclose(fp);
}

void history()
{
int i;
char op;
while(1)
{
system("clear");
                for(i=0;i<14;i++)
                    printf("\n");
                for(i=0;i<150;i++)
                    printf("\033[33m.\033[0m");
                printf("\n");
                printf("\033[4;1;36m.............................................................VECTOR LAB MANGEMENT SYSTEM............................................................\033[0m\n");
                printf("\n\n\033[32m\n\t 8051 KIT REGISTER HISTORY\033[0m\n");

                printf("\033[32m\n\tv/V : View complete history  \n\td/D : View history from a date\n\tr/R : View remarks\n\ts/S : Sort history \n\tc/C : Search in history \n\te/E : Exit to main previous manu\033[0m\n");

                printf("\n\n\n\n");
                for(i=0;i<150;i++)
                    printf("\033[33m.\033[0m");
                printf("\n");
                scanf(" %c",&op);
                op=op|1<<5;
                switch(op)
                {
                    case 'v':  break; 
                    case 'd':  break;
                    case 'r': break;
                    case 's': break;  // new menu-> search with kit, date,student,lc,remark, save search result
                    case 'c': break;  // new menu-> sort by kit,student, lc, save sorted data
                    case 'e': break;

                }
                if(op=='e')
                    break;
}
}




