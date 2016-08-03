/*
|--------------------------------------------------------------------------
| Personal Diary
|--------------------------------------------------------------------------
| Please do give credit if you think you have used this project code :)
| This is the Personal Diary Project made By CE.
| It is made by:
| - Shirshak Bajgain
*/

/*
|--------------------------------------------------------------------------
|  Necessary Header Files (6)
|--------------------------------------------------------------------------
*/
#include <stdio.h>
#include <iostream>
#include <conio.h>
#include <windows.h> // Windows.h contains string.h ctype.h so no need to include it :)
#include <cstdlib>
#include <ctime>
#include <graphics.h>
#include <stdlib.h>
#include <ctype.h>
#include <dos.h>
#include <fcntl.h>
#include <io.h>
#include <process.h>
#include <time.h>
#include <math.h>
#include <iostream>


/*
|--------------------------------------------------------------------------
|  Making std as default namespace
|--------------------------------------------------------------------------
*/
using namespace std;

/*
|--------------------------------------------------------------------------
|  Some Constants
|--------------------------------------------------------------------------
*/
HANDLE hConsole=GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;

const int DELAY_TIME = 1;
const int RUNNING_TIME = 30;

/*
|--------------------------------------------------------------------------
|  Function Prototypes
|--------------------------------------------------------------------------
*/
void dashboardMenu();
void administrationMenu();
void recordMenu();
void exitingProgram();
int sign_up();
void loginload();
int loading_bar(int x, int y, int len, int ht);


void addrecord();
void viewrecord();
void editrecord();
void deleterecord();

int password();
int check_username_password(char *username,char *password);
void view_all_username_password();
void handle_line(char *line) {cout<< line;}

void loading_screen();
void progressBar(int  noofsec);
void about();
void goToCoordinate(int x,int y);

/*
|--------------------------------------------------------------------------
|  Big Larger Text Prototypes
|--------------------------------------------------------------------------
*/
void dashboardAttractiveText();
void exitAttractiveText();
void recordOptionAttractiveText();
void administrationAttractiveText();
void addRecordAttractiveText();
void deleteRecordAttractiveText();
void editRecordAttractiveText();
void viewRecordAttractiveText();
void passwordAttractiveText();
void registrationAttractiveText();

// For Graphics
void setgraphicsmode();
int background(int bg);
int roundrect(int x, int y, int len, int ht, int rd, int col);
/*
|--------------------------------------------------------------------------
|  Structures
|--------------------------------------------------------------------------
*/
struct record
{
	char thetime[6];
    char title[30];
    char place[30];
    char content[500];
};

struct user
{
    int id;
	char username[30];
    char password[30];
};

struct palettetype p, pal;



int main()
{

    loginload();


    int width;
    int maxx=getwindowwidth();
    int maxy=getwindowheight();

    if((password())==1){
        cleardevice();
    }

    settextstyle(8,0,2);
    setcolor(15);
    width = textwidth("Logged In Sucessfully");
    outtextxy(maxx/2 - width/2,300,"Logged In Sucessfully");

    loading_bar(maxx/2-100,400,200,20);

    closegraph();

    SetConsoleTextAttribute(hConsole,3);
    dashboardMenu();
}

void loginload()
{
    int n, k;
    setgraphicsmode();
    int maxx=getwindowwidth();
    int maxy=getwindowheight();
    setcolor(4);
    line(200, 167, 230, 90);
    line(201, 167, 231, 90);
    line(202, 167, 232, 90);
    putpixel(231, 89, 4);
    putpixel(233, 88, 4);
    putpixel(202, 168, 14);
    putpixel(232, 89, 4);
    putpixel(232, 88, 4);
    putpixel(233, 87, 4);
    putpixel(234, 87, 4);
    line(235, 87, 325, 87);
    putpixel(233, 89, 4);
    putpixel(234, 88, 4);
    putpixel(235, 87, 4);
    putpixel(236, 87, 4);
    roundrect(199, 165, 100, 25, 7, 4);
    roundrect(200, 166, 100, 23, 7, 4);
    setfillstyle(1, 0);
    bar(295, 165, 295 + 10, 165 + 25);
    setcolor(4);
    line(293, 165, 293, 185);
    line(200, 185, 293, 185);
    line(293, 185, 324, 108);
    line(323 + 1, 90 - 1, 323 + 1, 105 + 3);
    line(295, 165, 325, 88);
    line(294, 165, 324, 88);
    line(295, 189, 328, 108);
    line(296, 189, 329, 108);
    line(325, 108, 329, 108);
    setfillstyle(1, 15);
    floodfill(203, 169, 4);
    floodfill(299, 165, 4);
    setfillstyle(1, 4);
    floodfill(213, 159, 4);
    setfillstyle(1, 12);
    floodfill(304, 159, 4);
    setcolor(0);

    delay(500);

    settextstyle(10, 0, 4);
    setcolor(11);


    outtextxy(200, 300,"Welcome ");
    delay(200);
    outtextxy(350, 300,"To ");
    delay(200);
    outtextxy(400, 300,"Personal ");
    delay(200);
    outtextxy(570, 300,"Diary ");


    delay(1000);
    settextstyle(8, 0, 1);
    setcolor(14);
    int t_width = textwidth("Thanks To Shirshak Bajgain");
    outtextxy(maxx/2 - t_width/2, 500, "Thanks To Shirshak Bajgain");

    delay(2000);

    loading_bar((maxx/2)-100,400,200,20);
    cleardevice();
}


int password(){
    Password:
	char username[50],password[50];
	int i=0,j=0,width,passwordCord=0;


    int maxx=getwindowwidth();
    int maxy=getwindowheight();


    settextstyle(10,0,8);
    setcolor(3);
    width=textwidth("Personal Diary");
    outtextxy(maxx/2 - width/2,150,"Personal Diary");


    settextstyle(8,0,2);
    setcolor(15);
    width = textwidth("Enter Your Password");
    outtextxy(maxx/2 - width/2,300,"Enter Your Password");

    setcolor(14);
    rectangle(maxx/2-120,350,maxx/2+120,380 );

        i = 0;
        password[0] = getch();
        width=textwidth("X");

        while (password[i] != '\r'){
            if(i<0){
                i=0;
            }
            if (!(password[i] == '\b')){
                    outtextxy(298+i*15,356,"X");
                    passwordCord=298+i*15+width;
                    i++;
                password[i] = getch();
            }
            else{
                if(passwordCord>300){
                    outtextxy(passwordCord -15+2,356,"\b");
                    passwordCord=passwordCord-15;
                }

                if(i!=0){
                    i--;
                }

                password[i] = getch();
            }
        }
        password[i] = '\0';


        char real_password[100]="docse";
        if(strcmp(password,real_password)==0){
			return 1;
		}else{
            settextstyle(8,0,1);
            setcolor(4);
            width = textwidth("Wrong Password Entered");
            outtextxy(maxx/2 - width/2,400,"Wrong Password Entered");
            delay(3000);
            cleardevice();
            goto Password;
		}

    return 0;

}
void dashboardMenu()
{
	int select;
	dashboardAttractiveText();

	while (1)
	{
		cout<<"\n\n!!! Welcome to Personal Dairy Dashboard!!!\n"<<endl;
		cout<<"======================================"<<endl;

		cout<<"\t[1] Notes"<<endl;
		cout<<"\t[2] Administration"<<endl;
		cout<<"\t[3] About"<<endl;
		cout<<"\t[4] Exit"<<endl;
		cout<<"\n\t    Enter Your Option: ";

		cin>> select;

		switch(select)
		{
			case 1:
				recordMenu();
				break;
			case 2:
				administrationMenu();
				break;
			case 3:
				about();
				break;
			case 4:
				exitingProgram();
				break;
			default:
				cout<<"\t    Sorry you entered wrong option.."<<endl;
				cout<<"\t    Press any key to try again to retry at dashboard menu.";
				getch();
				dashboardMenu();
				break;
		}
	}
	dashboardMenu();
	return;
}
void recordMenu()
{
	int select;
	recordOptionAttractiveText();

	cout<<"\n!!! Here You Can Manage Your Records !!!\n"<<endl;
	cout<<"============================================="<<endl;

	cout<<"\t[1]\tAdd a new Record\t"<<endl;
	cout<<"\t[2]\tView Records\t"<<endl;
	cout<<"\t[3]\tEdit Records\t"<<endl;
	cout<<"\t[4]\tDelete Records\t"<<endl;
	cout<<"\t[5]\tReturn to home\t"<<endl;
	cout<<"\t[6]\tExit\t\t"<<endl;
	cout<<"\n\t\tEnter Your Option: ";
	cin>> select;
	switch (select)
	{
		case 1:
			addrecord();
			break;
		case 2:
			viewrecord();
			break;
		case 3:
			editrecord();
			break;
		case 4:
			deleterecord();
			break;
		case 5:
			dashboardMenu();
			break;
		case 6:
			exitingProgram();
			break;
		default:
			cout<<"\t    You have Entered a Wrong Choice.."<<endl;
			cout<<"\t    Press any Key to Try Again";
			getch();
	}
	system("cls");
	recordMenu();
	return;
}
void addrecord()
{
	FILE* fp;
	char anotherRecord = 'Y', thetime[10],filename[15];
	int choice;
	struct record record;

	addRecordAttractiveText();

	cout<<"\n____________________________________________________________________________________"<<endl;
	cout<<"\n\t Date of Record(yyyy-mm-dd)      :\t";
	fflush(stdin);
	gets(filename);

	if ((fp=fopen(filename, "ab+")) == NULL){
		if ((fp=fopen(filename, "wb+")) == NULL){
		  cout<<"\n\t Please Enter Valid Data...";
		  getch();
		  return;
		}
	}

	while (anotherRecord == 'Y' || anotherRecord == 'y')
	{
		choice = 0;
		fflush(stdin);

		cout<<"\t Time(hh-mm)                     :\t";
		cin>> thetime;
		rewind(fp);
		while (fread(&record, sizeof(record), 1, fp) == 1){
		  if (strcmp(record.thetime, thetime) == 0){
		    cout<<"\n\t Sorry the record you are trying already exist.\n";
		    choice = 1;
		  }
		}
		if (choice == 0){
		  strcpy(record.thetime, thetime);
		  fflush(stdin);

		  cout<<"\t Title                           :\t";
		  gets(record.title);
		  fflush(stdin);

		  cout<<"\t Place                           :\t";
		  gets(record.place);
		  fflush(stdin);

		  cout<<"\t Content                         :\t";
		  gets(record.content);

		  fwrite(&record, sizeof(record), 1, fp);
		  cout<<"\n=========================================================================="<<endl;
		  cout<<"\t Congrats . Your Record has Been Sucessfully Added"<<endl;
		  cout<<"__________________________________________________________________________"<<endl;
		}
		cout<<"\n\n\t Do you wanna add another record (y/n) ? : ";
		fflush(stdin);
		anotherRecord = getchar();
		cout<<"__________________________________________________________________________\n\n";

	}
	fclose(fp);
	cout<<"\n\n\t Press Any Key to Return Back...";
	getch();

	recordMenu();
	return;
}

void viewrecord()
{
    struct record record ;
	FILE *fpte ;
    char time[6],choice,filename[14];
    int ch;

	viewRecordAttractiveText();

    do{
    	cout<<"\n\n\t Enter the date of the record you want to view :\t";
    	fflush(stdin);
	 	gets(filename);
	 	fpte = fopen ( filename, "rb" ) ;
        if ( fpte == NULL ){
        	cout<<"\n_________________________________________________________________________________"<<endl;
            cout<<"\n\n\t The Record you are trying to view don't exist" <<endl ;
            cout<<"\n\t You will be redirected to Records Management Section"<<endl;
            progressBar(30);
            recordMenu();
            return ;
        }

        cout<<"\n_________________________________________________________________________________"<<endl;
        cout<<"\n\t How would you like to view records? "<<endl;
        cout<<"\t  [1] Record of Whole Day?"<<endl;
        cout<<"\t  [2] Record of Given Time?"<<endl;
        cout<<"\n\t  Enter your choice : ";
        cin>>ch;
        cout<<"\n_________________________________________________________________________________";


        switch(ch){
            case 1:
                while ( fread ( &record, sizeof ( record ), 1, fpte ) == 1 ){
                	cout<<"\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
                    cout<<"\n\t Title: "<<record.title<<endl;
                    cout<<"\t Time: "<<record.thetime<<endl;
                    cout<<"\t Place:"<<record.place<<endl;
                    cout<<"\t Content: "<<record.content<<endl;
                    cout<<"\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
                 }
                 break;

            case 2:
 				fflush(stdin);
                cout<<"Enter the given time(hh-mm):"<<endl;
                gets(time);
                while ( fread ( &record, sizeof ( record ), 1, fpte ) == 1 ){
					if(strcmp(record.thetime,time)==0){
						cout<<"\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
						cout<<"\t Title: "<< record.title<<endl;
						cout<<"\t Time: "<< record.thetime<<endl;
	                    cout<<"\t Place: "<< record.place<<endl;
	                    cout<<"\t Content: "<< record.content<<endl;
	                    cout<<"\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
	                }
                }
                break;

            default:
            	cout<<"\t You typed wrong option?\n"<<endl;
            	cout<<"\t We will reload view record option:"<<endl;
            	progressBar(30);
            	viewrecord();
            	break;
        }
        cout<<"\n\t Would you like to View more records(y/n) : ";
 		fflush(stdin);
        cin>>choice;
    }while(choice=='Y'||choice=='y');

    fclose(fpte) ;

 	recordMenu();
    return ;
}

void editrecord()
{
    FILE *fpte ;
    struct record record ;
    char thetime[6],filename[14],choice;
    int num,count=0;

	editRecordAttractiveText();

    do{
    	cout<<"__________________________________________________________________________________\n\n"<<endl;
        cout<<"\t Enter Date of the record (yyyy-mm-dd) : ";
        fflush(stdin);
        gets(filename);
        cout<<"\t Enter the time(hh-mm)                 : ";
        gets(thetime);
        fpte = fopen ( filename, "rb+" ) ;

        if ( fpte == NULL ){
            cout<<"\t Record Don't Exist:" <<endl;
            cout<<"\t Press Any Key to return back";
            getch();
            return;
        }

        while ( fread ( &record, sizeof ( record ), 1, fpte ) == 1 ){
			if(strcmp(record.thetime,thetime)==0){
				cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n"<<endl;
	            cout<<"\t Your Old Record was:"<<endl;
	            cout<<"\t Title: "<<record.title<<endl;
	            cout<<"\t Time: "<<record.thetime<<endl;
	            cout<<"\t Place: "<<record.place<<endl;
	            cout<<"\t Content: "<<record.content<<endl;
	            cout<<"\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n"<<endl;

	            cout<<"__________________________________________________________________________________\n\n"<<endl;
	            cout<<"\n\tWhat would you like to edit?\n"<<endl;
	            cout<<"\t 1. Title"<<endl;
	            cout<<"\t 2. Time"<<endl;
	            cout<<"\t 3. Place"<<endl;
	            cout<<"\t 4. Content"<<endl;
	            cout<<"\t 5. All of Above"<<endl;
	            cout<<"\t 6. Go Back to Record Management Section."<<endl;
	            do{
	                cout<<"\t Enter Your Choice: ";
	                fflush(stdin);
	                cin>>num;
	                fflush(stdin);
	                switch(num){
		                case 1:
		                	cout<<"\t Enter Your New Title                  : ";
		                    gets(record.title);
		                    break;
		                case 2:
		                	cout<<"\n\t Enter Your New Time(hh-mm)            : ";
		                    gets(record.thetime);
		                    break;
		                case 3:
		                	cout<<"\n\t Enter New Place                       : ";
		                    gets(record.place);
		                    break;
		                case 4:
		                	cout<<"\n\t Enter New Content                     : ";
		                    gets(record.content);
		                    break;
		                case 5:
		                	cout<<"__________________________________________________________________________________\n\n"<<endl;
		                	cout<<"\t Enter all the data as required        :\n"<<endl;
							cout<<"\t Enter Your New Title                  : ";
							gets(record.title);
							cout<<"\n\t Enter Your New Time(hh-mm)            : ";
							gets(record.thetime);
							cout<<"\n\t Enter New Place                       : ";
							gets(record.place);
							cout<<"\n\t Enter New Content                     : ";
							gets(record.content);
							break;
		                case 6:
		                	cout<<"\t Press Any Key to Go Back...";
		                    getch();
		                    recordMenu();
		                    return ;
		                    break;
		                default:
		                	cout<<"\t You entered wrong option...\nPress any key to try again";
		            		getch();
		                    break;
	                }
	            }while(num<1||num>7);
	            cout<<"__________________________________________________________________________________"<<endl;
	            int size_of_record = sizeof(record);
	            fseek(fpte, -size_of_record, SEEK_CUR);
	            fwrite(&record,sizeof(record),1,fpte);
	            fseek(fpte, -size_of_record, SEEK_CUR);
	            fread(&record,sizeof(record),1,fpte);
	            choice=5;
	            break;
        	}
        }
        if(choice==5){
            system("cls");

            cout<<"\n__________________________________________________________________________________\n\n"<<endl;
            cout<<"\n\t ||| Editing Has Been Completed||| \n"<<endl;
            cout<<"\n\t !Your New Record Is! \n"<<endl;
            cout<<"\n\t Title   : "<<record.title<<endl;
            cout<<"\n\t Time    : "<<record.thetime<<endl;
            cout<<"\n\t Place   : "<<record.place<<endl;
            cout<<"\n\t Content : "<<record.content<<endl;
            cout<<"\n__________________________________________________________________________________"<<endl;

            fclose(fpte);
            cout<<"\n\n\tWould You like to Edit Another Record.(y/n) : "<<endl;
            cin>>choice;
            count++;
        }else{
        	cout<<"__________________________________________________________________________________\n\n"<<endl;
            cout<<"\t The Record don't Exist\n"<<endl;
            cout<<"\t Would You Like To Try Again...(y/n) : "<<endl;
            cin>>choice;
            cout<<"__________________________________________________________________________________"<<endl;
        }
    }while(choice=='Y'||choice=='y');


    fclose ( fpte ) ;

    cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n"<<endl;
    if(count==1)
    	cout<<"\t <<count << File Is Edited..."<<endl;
    else if(count>1)
    	cout<<"\t << count << Files Are Edited.."<<endl;
    else
    	cout<<"\t No File Has been Edited..."<<endl;


    cout<<"\t Press Any key to return to Records Management Section.";
    getch();
    recordMenu();
}

void deleterecord()
{
	FILE *fp,*fptr ;

    struct record record ;
    char filename[15],another = 'y' ,thetime[10];;
    int choice,check;

    deleteRecordAttractiveText();

	while ( another == 'y' ){
		cout<<"\n_________________________________________________________________________________"<<endl;
        cout<<"\n\t How would you like to delete records? "<<endl;
        cout<<"\t  [1] Delete Whole Record By Date?"<<endl;
        cout<<"\t  [2] Delete Particular Record By Time?"<<endl;


        do{
        	cout<<"\n\t Enter your choice : ";
 			cin>>choice;
 			cout<<"_________________________________________________________________________________";
                    switch(choice){
                        case 1:
	                        cout<<"\n\t Enter the date of record you want to delete[yyyy-mm-dd]: ";
	                        fflush(stdin);
	                        gets(filename);
	                        fp = fopen (filename, "wb" ) ;
	                        if ( fp == NULL ){
	                            cout<<"\n\t The record you are trying to delete don't exist"<<endl;
	                            cout<<"\t Press any key to return back";
	                            getch();
	                            return ;
	                        }
	                        fclose(fp);
	                        remove(filename);
	                        cout<<"\t Record Sucessfully deleted."<<endl;
	                        cout<<"_________________________________________________________________________________"<<endl;
	                        break;
                        case 2:
                            cout<<"\tEnter the date of record you want to delete[yyyy-mm-dd]: "<<endl;
                            fflush(stdin);
                            gets(filename);
                            fp = fopen (filename, "rb" );
                            if ( fp == NULL ){
                                cout<<"\t The record you are trying don't actually exist."<<endl;
                                cout<<" Press any key to return back....";
                                getch();
                                return ;
                            }
                            fptr=fopen("temp","wb");
                            if(fptr==NULL){

                                cout<<"There are a problem with record."<<endl;
                                cout<<"Press any key to return back.";
                                getch();
                                return ;
                            }
                            cout<<"\t Enter the time of the record to be deleted(hh-mm): ";
                            fflush(stdin);
                            gets(thetime);
                            while(fread(&record,sizeof(record),1,fp)==1){
                                if(strcmp(record.thetime,thetime)!=0)
                                fwrite(&record,sizeof(record),1,fptr);
                            }
                            fclose(fp);
                            fclose(fptr);
                            remove(filename);
                            rename("temp",filename);
                            cout<<"\t Particular record sucessfully deleted.."<<endl;
                            break;

                    default:
                        cout<<"\n\t You have entered wrong choice"<<endl;
                        break;
            }
        }while(choice<1||choice>2);

        cout<<"\n_________________________________________________________________________________"<<endl;
        cout<<"\n\t Would you like to delete another record(y/n): ";
        fflush(stdin);
        cin>>another;
        cout<<"_________________________________________________________________________________\n\n"<<endl;

	}
	cout<<"\n\t Press any key to return to Records Management Section...";
    getch();
	recordMenu();
	return;
}
void about()

{   system("cls");
    cout<<"\n\n\n\n\n________________________________________________________________________________________________________\n"<<endl;
	cout<<"\tPersonal Diary was done for fulfillment of  2nd semester project in Kathmandu University by \n\tCE 2015 batch";
    cout<<"\t Press Any Key to return to Dashboard";
    getch();
    dashboardMenu();
    return;
}
void administrationMenu()
{

	int select;

	administrationAttractiveText();

	cout<<"\n!!! Here You Can Manage Adminstration Work !!!\n"<<endl;
	cout<<"======================================"<<endl;

	cout<<"\t[1]\tView All UserName And Password\t"<<endl;
	cout<<"\t[2]\tReturn to Dashboard\t"<<endl;
	cout<<"\n\tEnter Your Option: ";

	cin>> select;

	switch(select)
	{
		case 1 :
			view_all_username_password();
			break;
		case 2 :
			dashboardMenu();
			break;
		default:
			cout<<"\nYou have Entered a Wrong Choice.."<<endl;
			cout<<"Press any Key to Try Again";
			getch();
	}
	administrationMenu();
	return;
}
void view_all_username_password()
{
	system("cls");
	char check;
	char line[1024];
    FILE *fp = fopen("accounts.dll","r");
    struct user user;

    cout<<"\n\n+++++++++++++++++++++++++++++++++++++++++++++++++++";
    cout<<"\n\t !!! Senstive Information !!!\n\n\n"<<endl;
    cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;

    cout<<"\t You are trying to view too much sensitive information.\n";
    cout<<"\t Are you sure you want to see such info (y/n)?";

	check=getch();

    if(check=='y' || check =='Y'){
	    if( fp == NULL ) {
	        return;
	    }
	    cout<<"\t Here are the Usernames and Password\n"<<endl;
	    cout<<"_______________________________________________________________\n\n\n"<<endl;
	    cout<<"\t\t Username: \t\t Password"<<endl;
	    cout<<"\t\t ________ \t\t ________"<<endl;

	    while ( fread ( &user, sizeof ( user ), 1, fp ) == 1 ){
	        cout<<"\n\t\t  "<<user.username;
	        cout<<"\t\t"<<user.password<<endl;
	    }
	    cout<<"\n_______________________________________________________________";
    }else{
    	cout<<"So you don't want to see it . Redirecting you to Personal Diary Home \n\n";
    	progressBar(10);
    	dashboardMenu();
    }

	getch();
	administrationMenu();
	return;
}
/*
|--------------------------------------------------------------------------
|  Helper Functions
|--------------------------------------------------------------------------
*/
void setgraphicsmode()
{
    //int gd=DETECT;
    //int gm;
    //initgraph(&gd,&gm,"C:\\TC\\BGI");

    initwindow(800,550,"Personal Diary",0,0); // start at around 230 50 for better result
}

void goToCoordinate(int x,int y)
{
	CursorPosition.X=x;
	CursorPosition.Y=y;
	SetConsoleCursorPosition(hConsole,CursorPosition);
}
void loading_screen(){
	int percentage;
	int i,j;
	char block1=177,block2=219;

    system("cls");

	srand(time(NULL));
	cout << "\n\t";
	 for(int i=14;i<95;i++){
	    goToCoordinate(i,13);cout << block1 ;

	 }
	 for(i=14,j=0;i<81,j<=80;i++,j++){
	     percentage=(j/80.0)*100;
	     goToCoordinate(46,14);SetConsoleTextAttribute(hConsole,8);cout << percentage << "%completed";    // use this for providing color in console
	     SetConsoleTextAttribute(hConsole,rand()%10);    // use this for providing color in console
	     goToCoordinate(i,13);cout << block2 ;
	     Sleep(50);
	 }
}
void progressBar(int noOfSec)
{
	int i;
	cout<<"\n";
	for(i=0;i<69;i++){
		Sleep( noOfSec );
		cout<<"~";
	}
	cout<<""<<endl;
}
int roundrect(int x, int y, int len, int ht, int rd, int col)
{
    getpalette(&p);
    setcolor(col);
    line(x, y + rd, x, y + ht - rd);
    line(x + len, y + rd, x + len, y + ht - rd);
    line(x + rd, y, x + len - rd, y);
    line(x + rd, y + ht, x + len - rd, y + ht);
    arc(x + rd, y + rd, 90, 180, rd);
    arc(x + len - rd, y + rd, 0, 90, rd);
    arc(x + rd, y + ht - rd, 180, 270, rd);
    arc(x + len - rd, y + ht - rd, 270, 360, rd);
    return 0;
}
int loading_bar(int x, int y, int len, int ht){
    rectangle(x, y,x+len,y+ht);


    delay(100);
    setfillstyle(SOLID_FILL,RED);
    for(int i=0;i<len;i++){
        bar(x+1,y+1,x+i+1,y+ht);
        delay(10);
    }
    return 0;
}

void exitingProgram()
{
	exitAttractiveText();

	progressBar(50);
	cout<<"_________________________________________________________________________________"<<endl;
	cout<<"\n\tThanks for using the personal diary \n"<<endl;
	cout<<" \t Closing this window....."<<endl;
	cout<<"_________________________________________________________________________________"<<endl;
	Sleep(500);
	exit(0);
	getch();
	return ;
}
/*
|--------------------------------------------------------------------------
|  Attractive Texts
|--------------------------------------------------------------------------
*/
void dashboardAttractiveText()
{
	system("cls");
	cout<<"\t\t___________________________________________________________________________________"<<endl;
	cout<<"\t\t|\t ____                                 _   ____  _                          |"<<endl;
	cout<<"\t\t|\t|  _ \\ ___ _ __ ___  ___  _ __   __ _| | |  _ \\(_) __ _ _ __ _   _         |"<<endl;
	cout<<"\t\t|\t| |_) / _ \\ \'__/ __|/ _ \\| \'_ \\ / _` | | | | | | |/ _` | \'__| | | |        |"<<endl;
	cout<<"\t\t|\t|  __/  __/ |  \\__ \\ (_) | | | | (_| | | | |_| | | (_| | |  | |_| |        |"<<endl;
	cout<<"\t\t|\t|_|   \\___|_|  |___/\\___/|_| |_|\\__,_|_| |____/|_|\\__,_|_|   \\__, |        |"<<endl;
	cout<<"\t\t|\t                                                             |___/         |"<<endl;
	cout<<"\t\t|__________________________________________________________________________________|"<<endl;
}
void exitAttractiveText()
{
	system("cls");
	cout<<"\t\t___________________________________________________"<<endl;
	cout<<"\t\t|\t ____               ____                   |"<<endl;
	cout<<"\t\t|\t| __ ) _   _  ___  | __ ) _   _  ___       |"<<endl;
	cout<<"\t\t|\t|  _ \\| | | |/ _ \\ |  _ \\| | | |/ _ \\      |"<<endl;
	cout<<"\t\t|\t| |_) | |_| |  __/ | |_) | |_| |  __/      |"<<endl;
	cout<<"\t\t|\t|____/ \\__, |\\___| |____/ \\__, |\\___|      |"<<endl;
	cout<<"\t\t|\t       |___/              |___/            |"<<endl;
	cout<<"\t\t|__________________________________________________|"<<endl;
}
void recordOptionAttractiveText()
{
	system("cls");
	cout<<"\t\t________________________________________________________________________________"<<endl;
	cout<<"\t\t|\t ____                        _       ____            _   _             \t|"<<endl;
	cout<<"\t\t|\t|  _ \\ ___  ___ ___  _ __ __| |___  / ___|  ___  ___| |_(_) ___  _ __  \t|"<<endl;
	cout<<"\t\t|\t| |_) / _ \\/ __/ _ \\| '__/ _` / __| \\___ \\ / _ \\/ __| __| |/ _ \\| '_ \\ \t|"<<endl;
	cout<<"\t\t|\t|  _ <  __/ (_| (_) | | | (_| \\__ \\  ___) |  __/ (__| |_| | (_) | | | |\t|"<<endl;
	cout<<"\t\t|\t|_| \\_\\___|\\___\\___/|_|  \\__,_|___/ |____/ \\___|\\___|\\__|_|\\___/|_| |_|\t|"<<endl;
	cout<<"\t\t|_______________________________________________________________________________|"<<endl;
}
void administrationAttractiveText()
{
	system("cls");
	cout<<"\t\t________________________________________________________________________________"<<endl;
	cout<<"\t\t|\t    _       _           _       _     _             _   _               |"<<endl;
	cout<<"\t\t|\t   / \\   __| |_ __ ___ (_)_ __ (_)___| |_ _ __ __ _| |_(_) ___  _ __    |"<<endl;
	cout<<"\t\t|\t  / _ \\ / _` | '_ ` _ \\| | '_ \\| / __| __| '__/ _` | __| |/ _ \\| '_ \\   |"<<endl;
	cout<<"\t\t|\t / ___ \\ (_| | | | | | | | | | | \\__ \\ |_| | | (_| | |_| | (_) | | | |  |"<<endl;
	cout<<"\t\t|\t/_/   \\_\\__,_|_| |_| |_|_|_| |_|_|___/\\__|_|  \\__,_|\\__|_|\\___/|_| |_|  |"<<endl;
	cout<<"\t\t|_______________________________________________________________________________|"<<endl;
}
void addRecordAttractiveText()
{
	system("cls");
	cout<<"\t\t________________________________________________________________"<<endl;
	cout<<"\t\t|\t _   _                 ____                        _    |"<<endl;
	cout<<"\t\t|\t| \\ | | _____      __ |  _ \\ ___  ___ ___  _ __ __| |\t|"<<endl;
	cout<<"\t\t|\t|  \\| |/ _ \\ \\ /\\ / / | |_) / _ \\/ __/ _ \\| '__/ _` |\t|"<<endl;
	cout<<"\t\t|\t| |\\  |  __/\\ V  V /  |  _ <  __/ (_| (_) | | | (_| |\t|"<<endl;
	cout<<"\t\t|\t|_| \\_|\\___| \\_/\\_/   |_| \\_\\___|\\___\\___/|_|  \\__,_|\t|"<<endl;
	cout<<"\t\t|_______________________________________________________________|"<<endl;
}
void deleteRecordAttractiveText()
{
	system("cls");
	cout<<"\t\t_________________________________________________________________________"<<endl;
	cout<<"\t\t|\t ____       _      _         ____                        _       |"<<endl;
	cout<<"\t\t|\t|  _ \\  ___| | ___| |_ ___  |  _ \\ ___  ___ ___  _ __ __| |___   |"<<endl;
	cout<<"\t\t|\t| | | |/ _ \\ |/ _ \\ __/ _ \\ | |_) / _ \\/ __/ _ \\| '__/ _` / __|  |"<<endl;
	cout<<"\t\t|\t| |_| |  __/ |  __/ ||  __/ |  _ <  __/ (_| (_) | | | (_| \\__ \\  |"<<endl;
	cout<<"\t\t|\t|____/ \\___|_|\\___|\\__\\___| |_| \\_\\___|\\___\\___/|_|  \\__,_|___/  |"<<endl;
	cout<<"\t\t|________________________________________________________________________|"<<endl;
}
void editRecordAttractiveText()
{
	system("cls");
	cout<<"\t\t________________________________________________________________________________"<<endl;
	cout<<"\t\t|\t _____    _ _ _   _               ____                        _ \t|"<<endl;
	cout<<"\t\t|\t| ____|__| (_) |_(_)_ __   __ _  |  _ \\ ___  ___ ___  _ __ __| |\t|"<<endl;
	cout<<"\t\t|\t|  _| / _` | | __| | '_ \\ / _` | | |_) / _ \\/ __/ _ \\| '__/ _` |\t|"<<endl;
	cout<<"\t\t|\t| |__| (_| | | |_| | | | | (_| | |  _ <  __/ (_| (_) | | | (_| |\t|"<<endl;
	cout<<"\t\t|\t|_____\\__,_|_|\\__|_|_| |_|\\__, | |_| \\_\\___|\\___\\___/|_|  \\__,_|\t|"<<endl;
	cout<<"\t\t|\t                          |___/                                 \t|"<<endl;
	cout<<"\t\t|_______________________________________________________________________________|"<<endl;
}
void viewRecordAttractiveText()
{
	system("cls");
	cout<<"\t\t________________________________________________________________________"<<endl;
	cout<<"\t\t|\t__     ___                 ____                        _     \t|"<<endl;
	cout<<"\t\t|\t\\ \\   / (_) _____      __ |  _ \\ ___  ___ ___  _ __ __| |___ \t|"<<endl;
	cout<<"\t\t|\t \\ \\ / /| |/ _ \\ \\ /\\ / / | |_) / _ \\/ __/ _ \\| '__/ _` / __|\t|"<<endl;
	cout<<"\t\t|\t  \\ V / | |  __/\\ V  V /  |  _ <  __/ (_| (_) | | | (_| \\__ \\\t|"<<endl;
	cout<<"\t\t|\t   \\_/  |_|\\___| \\_/\\_/   |_| \\_\\___|\\___\\___/|_|  \\__,_|___/\t|"<<endl;
	cout<<"\t\t|_______________________________________________________________________|"<<endl;
}
void passwordAttractiveText()
{
	system("cls");
	cout<<"\t\t_________________________________________________________"<<endl;
	cout<<"\t\t|\t ____                                     _     |"<<endl;
	cout<<"\t\t|\t|  _ \\ __ _ ___ _____      _____  _ __ __| |    |"<<endl;
	cout<<"\t\t|\t| |_) / _` / __/ __\\ \\ /\\ / / _ \\| '__/ _` |    |"<<endl;
	cout<<"\t\t|\t|  __/ (_| \\__ \\__ \\\\ V  V / (_) | | | (_| |    |"<<endl;
	cout<<"\t\t|\t|_|   \\__,_|___/___/ \\_/\\_/ \\___/|_|  \\__,_|    |"<<endl;
	cout<<"\t\t|_______________________________________________________|"<<endl;

}

void registrationAttractiveText()
{
	system("cls");
cout<<"\t\t________________________________________________________________"<<endl;
cout<<"\t\t|\t ____            _     _             _   _             \t|"<<endl;
cout<<"\t\t|\t|  _ \\ ___  __ _(_)___| |_ _ __ __ _| |_(_) ___  _ __  \t|"<<endl;
cout<<"\t\t|\t| |_) / _ \\/ _` | / __| __| '__/ _` | __| |/ _ \\| '_ \\ \t|"<<endl;
cout<<"\t\t|\t|  _ <  __/ (_| | \\__ \\ |_| | | (_| | |_| | (_) | | | |\t|"<<endl;
cout<<"\t\t|\t|_| \\_\\___|\\__, |_|___/\\__|_|  \\__,_|\\__|_|\\___/|_| |_|\t|"<<endl;
cout<<"\t\t|\t           |___/                                       \t|                            "<<endl;
cout<<"\t\t|_______________________________________________________________|"<<endl;
}
