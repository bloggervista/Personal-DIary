/*
|--------------------------------------------------------------------------
| Personal Diary
|--------------------------------------------------------------------------
|
| This is the Personal Diary Project made By CE.
| It is made by:
| - Shirshak Bajgain(04)
| - Amit Upreti(60)
| - Kushal Bhatta(06)
| - Yugesh Bantawa(41)
| - Deepak Shrestha(48)
|
|
|
| We would like to personally thank  Dr. Gajendra Sharma who helped us  by supervising our project .
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
#include <iostream>
#include <cstdlib>
#include <ctime>

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
void blink();
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
/*
|--------------------------------------------------------------------------
|  From Here Code Starts
|--------------------------------------------------------------------------
*/
int main()
{
	FILE* fp;
	if((fp = fopen("accounts.dll", "r")) == NULL)
	{
		dashboardAttractiveText();
		cout<<"\n\t It seems there is no user. It means you will be redirected to registration"<<endl;
		progressBar(30);
		loading_screen();
		sign_up();
		return -1;
	}
	fclose(fp);


	if(password()!=1)
	{
		exitingProgram();
	}
	SetConsoleTextAttribute(hConsole,3);
	dashboardMenu();
	return 0;
}

int password()
{
	SetConsoleTextAttribute(hConsole,6);

	char username[50],password[50];
	int i=0,j=0;
	passwordAttractiveText();
	cout<<"\n\n\t!!!   Welcome to your Personal Diary !!!"<<endl;
	cout<<"_________________________________________________________________________"<<endl;

	cout<<"\n\t|||   Due to Security Reasons we only allow Three Attempts  |||"<<endl;
	cout<<"_________________________________________________________________________"<<endl;



	for (j = 0; j < 3; j++)
	{
    char username_password[100];
		cout<<"\n\t Enter Username\t:\t";
		cin>>username;
		cout<<"\t Enter Password\t:\t";
		i = 0;
		password[0] = getch();
		while (password[i] != '\r'){
			if (password[i] == '\b'){
				i--;
				cout<<"\b";
				cout<<" ";
				cout<<"\b";
				password[i] = getch();
			}
			else{
				cout<<"X";
				i++;
				password[i] = getch();
			}
		}
		password[i] = '\0';

	    /* Concatenation Old way of loggin in*/
	    // strcpy(username_password, "");
	    // strcat(username_password,username );
	    // strcat(username_password," " );
	    // strcat(username_password,password);


		if (check_username_password(username,password)==1){
			cout<<"\n\n\t You now have access...\n"<<endl;
	      	loading_screen();
			return 1;
		}
	}
	cout<<"\n\t You entered wrong password for more than three times. The program will exit for security purpose";
	exitingProgram();
	getch();
	return 0;
}

int check_username_password(char *username,char *password) 
{
	FILE *fp;
	int line_num = 1;
	int find_result = 0;
	char temp[512];
	struct user user;

	if((fp = fopen("accounts.dll", "r")) == NULL)
	{
		dashboardAttractiveText();
		cout<<"\n\t It seems there is no user. It means you will be redirected to registration"<<endl;
		progressBar(30);
		loading_screen();
		sign_up();
		return -1;
	}

	while ( fread ( &user, sizeof ( user ), 1, fp ) == 1 ){
		if(strcmp(user.username,username)==0){
			return 1;
		}else{
			cout<<"\n_____________________________________________________________________";
			cout<<"\n\n\tWrong Username or Password Entered..\n\n\tAccess Denied..."<<endl;
			cout<<"\n_____________________________________________________________________";
		}
	}
	fclose(fp);
	progressBar(40);
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
void about()

{   system("cls");
    cout<<"\n\n\n\n\n________________________________________________________________________________________________________\n"<<endl;
	cout<<"\tPersonal Diary was done for fulfillment of  2nd semester project in Kathmandu University by \n\tCE 2015 batch";
	cout<<"\tPersonal Diary is free to use and distribute but The right to modify the \n\tsoftware and upgrade is free to everyone";
	cout<<".Any suggestions and feedbacks regarding \n\tthe software are warmly welcomed.You can send us mail at\n\t";
	cout<<"\t\t\t\t\t bloggervista@gmail.com\n\t";
    cout <<"Please Do give Credit by mentioning my name \"Shirshak Bajgain\" in credit part of your project "<<endl;
    cout<<"\n\n\n\t\t\t" <<"(c)"<< " 2016 CE 2nd semester MIT LICENCE"<<endl;
	cout<<"\n\n___________________________________________________________________________________________________________\n"<<endl;
    cout<<"\t Press Any Key to return to Dashboard";
    getch();
    dashboardMenu();
    return;
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
int sign_up(){
	FILE* fp;
	char username[30];
	struct user user;
	int choice=0;
	
	SetConsoleTextAttribute(hConsole,6);

	registrationAttractiveText();

	if ((fp=fopen("accounts.dll", "ab+")) == NULL){
		if ((fp=fopen("accounts.dll", "wb+")) == NULL){
		  return 1;
		}
	}


	fflush(stdin);

	cout<<"\n\n\t\t Enter Username                     :\t";
	cin>> username;
	rewind(fp);
	while (fread(&user, sizeof(user), 1, fp) == 1){
	  if (strcmp(user.username, username) == 0){
	    cout<<"\n\t Sorry the user you are trying already exist.\n";
	    choice = 1;
	  }
	}

	if (choice == 0){
		strcpy(user.username, username);
		fflush(stdin);
		
		cout<<"\t\t Password                           :\t";
	  	gets(user.password);

		fwrite(&user, sizeof(user), 1, fp);
		cout<<"\n=========================================================================="<<endl;
		cout<<"\t Congrats .Registration has been done"<<endl;
		cout<<"__________________________________________________________________________"<<endl;
	}	
	fclose(fp);

	loading_screen();
	main();
	return 1;
}
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