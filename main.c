#include"header.h"

reg *kitptr=0;
reg *attptr=0;
void main()
{
    int i;
    char op;

    FILE* fp=fopen("kitdaily.txt","r");
    if(fp==0)
    {
        fp=fopen("kitdaily.txt","w");
        fprintf(fp,"DATE		LC-ID		KIT-ID		STUDTENT ID	OUT-TIME	LC-ID		IN-TIME		REMARKS\n");
        fclose(fp);
    }
    fp=fopen("kithistory.txt","r");
    if(fp==0)
    {
        fp=fopen("kithistory.txt","w");
           fprintf(fp,"DATE		LC-ID		KIT-ID		STUDTENT ID	OUT-TIME	LC-ID		IN-TIME		REMARKS\n");
        fclose(fp);
    }
    while(1)
    {
        system("clear");
        for(i=0;i<14;i++)
            printf("\n");
        for(i=0;i<150;i++)
            printf("\033[33m.\033[0m");
        printf("\n");
        printf("\033[4;1;36m.............................................................VECTOR LAB MANGEMENT SYSTEM............................................................\033[0m\n");
        printf("\033[32m\n\tk/K : 8051 kit menu\n\tl/L : Lab co-ordinators menu\n\te/E : Exit\033[0m\n");

        printf("\n\n\n\n");
        for(i=0;i<150;i++)
            printf("\033[33m.\033[0m");
        printf("\n");
        scanf(" %c",&op); // flush it out
        op=op|1<<5;
        if(op=='k')
        {
            while(1)
            {
                system("clear");
                for(i=0;i<14;i++)
                    printf("\n");
                for(i=0;i<150;i++)
                    printf("\033[33m.\033[0m");
                printf("\n");
                printf("\033[4;1;36m.............................................................VECTOR LAB MANGEMENT SYSTEM............................................................\033[0m\n");
                printf("\n\n\033[32m\n\t 8051 KIT REGISTER\033[0m\n");

                printf("\033[32m\n\ti/I : Issue kit \n\tr/R : Return kit\n\tt/T : Today's loggs\n\ts/S : Search kit\n\th/H : History\n\te/E : Exit to main home manu\033[0m\n");

                printf("\n\n\n\n");
                for(i=0;i<150;i++)
                    printf("\033[33m.\033[0m");
                printf("\n");
                scanf(" %c",&op);
                op=op|1<<5;
                switch(op)
                {
                    case 'i': issue(); break;
                    case 'r': ret(); break;
                    case 't': kitlog();break;
                    case 's': searchkit();break;
                    case 'h': history();break;
                    case 'e': break;

                }
                if(op=='e')
                    break;
            }
        }
        else if(op=='l')
        {
            while(1)
            {
                system("clear");
                for(i=0;i<14;i++)
                    printf("\n");
                for(i=0;i<150;i++)
                    printf("\033[33m.\033[0m");
                printf("\n");
                printf("\033[4;1;36m.............................................................VECTOR LAB MANGEMENT SYSTEM............................................................\033[0m\n");
                printf("\n\n\033[32m\n\t LC ATTANDANCE REGISTER\033[0m\n");

                printf("\033[32m\n\ti/I : LC In \n\to/O : LC Out\n\tu/U : Update\n\tt/T : View Todays log\n\tv/V : View history\n\te/E : Exit to main home manu\033[0m\n");

                printf("\n\n\n\n");
                for(i=0;i<150;i++)
                    printf("\033[33m.\033[0m");
                printf("\n");
                scanf(" %c",&op); // flush it out
                op=op|1<<5;
                switch(op)
                {
                    case 'i': lcin(); break; // if not in list ask for new reg( update in list , make file add mob no, doj, etc... on top side), 
                    case 'r': lcout(); break;
                    case 'u': update();break;  //make it  password protected, update data by entering date, lcid 
                    case 't': lclog();break;    // todays log
                    case 'v': lchistory();break; // search by date, lc, month ( can include payment status...
                    case 'e': break;

                }
                if(op=='e')
                    break;
            }
        }

        else if(op=='e')
            exit(0);
    }
}

