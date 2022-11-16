#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

// vectorlab.c

// make file as dot
// give red color to line if  not returned , purple for having any remarks
// store daily data in register and if kit returned update it in history and delete form daily
// two files:  status history, lcattandance(dot),lchistory
typedef struct reg   // only used for viewing datas. for entering direct
{

    char date[15];  // need 12 only
    char timein[10];  // need 9 only
    char timeout[10];  // need 9 only
    char id[10]; // v21be8a1
    char lcin[10];
    char lcou[10];
    char* remarks;  // allocate dynamically
    char kit[10];
    struct reg *next;
}reg;

typedef struct attandance
{
    char date[15];  // need 12 only
    char timein[10];  // need 9 only
    char timeout[10];  // need 9 only
    char* lcname;
    struct attandance *next;
}att;


extern reg *kitptr;
extern reg *attptr;




// for each lc, make seperate file, top side, doj, batch mobile...., 
// reg new lc, if name enterd not in list, ask for new registarion


// in main menu : kit, lc attandance,exit
//in lc attandance : lc in/out update, search lc, search date, view history, view lcstat
//kit: 5 options : issue, return, history, register(view reg,search kit(print details also) exit to main menu
// in histor: viw history, search(kit,date,lc,student id,remark-show non zero remarks only)
int countissue();  // for counting current kits in use count from file


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//kit files:   .kitdaily.txt   .kithistory.txt   
void issue();   // for issue kit add at end of register
void ret();  // for kit return , delete from register, update in history
void kitlog(); // todays log
void searchkit(); // todays log
void history();   // options: viw history, search(kit,date,lc,student id,remark-show non zero remarks only)
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//lc files  : lclog( name will be id of lc), lclist( list of lcs), todaylog( first update here, then delete form here and update in lclog)

void lcin(); 
void lcout();
void update();  // password protect
void lclog(); // todays log
void lchistory();
void newreg();  // if lc name not in list ask new reg,  update details in lc list, and also make a new file with his id , and (doj, mob no, batch..) details on top side( also in nlc list
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void view();   // view history, view full history,search for rollno, lcname,date,remarks(any),s
void search(); // search for rollno, lcname,date,remarks(any),so no need of sorting



void deletelc(); // for lc attandance delete, only possible with passsword, read password(fread)

void deletekit(); // for kit delete, only possible with passsword, read password

// store password in a .file  as binary,

void changepassword(); // change password in fie

/*
   updates possible
1: kit ids predefine, so if not inl list give error
2: not taken care of kit retunred in anmother day

 */
