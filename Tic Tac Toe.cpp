#include <iostream>
#include <iomanip> 
#include <unistd.h> 
#include <cstdlib> 
#include <stdlib.h> 
#include <ctime> 
#include <conio.h>
#include <cstring>
#include <windows.h>
using namespace std;
char square[10]={'0','1','2','3','4','5','6','7','8','9'};
string singleplayername,player1name,player2name,empty;
int singleplayer=0,computer=0,player1=0,player2=0;
int seconds = 1000;
int sec=0;
void name(string str);
void timer();
void timers();
void displayClock(); 
void mainpage();
void mainmenu();
void submenu(string str1,string str2);
void markit();
void board(string str1,string str2);
void scoreboard(string str1,string str2);
void end();
int checkwin();

//------Human Vs Human------
class humanvshuman
{
	public :
	void twoplayer()
	{
		name("Human");
		system("cls");
		submenu("Human","Human");
		int opt;
		cin>>opt;
		switch(opt)
		{
			case 0:
			mainpage();
			break;
			
			case 1:
			timers();
			gamehumanvshuman();
			break;
			
			default:
			end();
			break;
		}
	}
	
	int gamehumanvshuman()
	{
		int player = 1, i, choice;
		char mark;
		do
		{
			board("Player1","Player2");
			player = (player % 2) ? 1 : 2;
			if (player==1)
			{
				cout<<endl<<"\n "<<player1name<<", Enter Your Number : ";
			}
			else 
			{
				cout<<endl<<"\n "<<player2name<<", Enter Your Number : ";
			}
			cin>>choice;
        
			mark=(player == 1)?'X':'O';
        
			if (choice == 1 && square[1] == '1')
				square[1] = mark;
            
			else if (choice == 2 && square[2] == '2')
				square[2] = mark;
            
			else if (choice == 3 && square[3] == '3')
				square[3] = mark;
            
			else if (choice == 4 && square[4] == '4')
				square[4] = mark;
            
			else if (choice == 5 && square[5] == '5')
				square[5] = mark;
            
			else if (choice == 6 && square[6] == '6')
				square[6] = mark;
            
			else if (choice == 7 && square[7] == '7')
				square[7] = mark;
            
			else if (choice == 8 && square[8] == '8')
				square[8] = mark;
            
			else if (choice == 9 && square[9] == '9')
				square[9] = mark;
            
			else
			{
				cout<<"\n\t\t\t\tInvalid Move ";
				player--;
				getch();
			}
			i=checkwin();
			player++;
		}while(i==-1);
		board("Player1","Player2");
    
		if (i == 1)
		{
			player1++;
			cout<<" ==> \a"<<player1name<<" Win";
			
		}
		else if (i==0)
		{
			player2++;
			cout<<" ==> \a"<<player2name<<" Win";
		}
		else
		{cout<<" ==> \aGame draw";}
		getch();
		markit();
		system("cls");
		scoreboard("Human","Human");
		return 0;
	}
};

//------Human Vs Computer------
class humanvscomputer
{
	public:
	int random()
	{
		int i;
		srand((unsigned)time(0)); 
		i = (rand()%9)+1;
		return i;
	}
	
	void oneplayer()
	{
		name("Computer");
		system("cls");
		submenu("Human","Computer");
		int opt;
		cin>>opt;
		switch(opt)
		{
			case 0:
			mainpage();
			break;
			
			case 1:
			timers();
			gamehumanvscomputer();
			break;
			
			default:
			end();
			break;
		}
	}
	
	void compmark()
	{
		char mark;
		int choice;
		choice=random();
		mark='O';
		if (choice == 1 && square[1] == '1')
			square[1] = mark;
            
		else if (choice == 2 && square[2] == '2')
			square[2] = mark;
            
		else if (choice == 3 && square[3] == '3')
            square[3] = mark;
            
        else if (choice == 4 && square[4] == '4')
            square[4] = mark;
            
        else if (choice == 5 && square[5] == '5')
            square[5] = mark;
            
        else if (choice == 6 && square[6] == '6')
            square[6] = mark;
            
        else if (choice == 7 && square[7] == '7')
            square[7] = mark;
            
        else if (choice == 8 && square[8] == '8')
            square[8] = mark;
            
        else if (choice == 9 && square[9] == '9')
            square[9] = mark;
            
        else
        {
            getch();
            compmark();
        }
	}
	
	int gamehumanvscomputer()
	{
		int i, choice,j=1;;
		char mark;
		do
		{
			board("Player","Computer");
			cout<<endl<<"\n "<<singleplayername<<", Enter Your Number : ";
			cin>>choice;
			mark='X';        
			if (choice == 1 && square[1] == '1')
				square[1] = mark;
            
			else if (choice == 2 && square[2] == '2')
				square[2] = mark;
            
			else if (choice == 3 && square[3] == '3')
				square[3] = mark;
            
			else if (choice == 4 && square[4] == '4')
				square[4] = mark;
            
			else if (choice == 5 && square[5] == '5')
				square[5] = mark;
            
			else if (choice == 6 && square[6] == '6')
				square[6] = mark;
            
			else if (choice == 7 && square[7] == '7')
				square[7] = mark;
            
			else if (choice == 8 && square[8] == '8')
				square[8] = mark;
            
			else if (choice == 9 && square[9] == '9')
				square[9] = mark;
            
			else
			{
				j=0;
				cout<<"\n\t\t\t\tInvalid Move ";
				getch();
			}
			if(j!=0)
			{
				compmark();
			}
			i=checkwin();
			j++;
		}while(i==-1);
		board("Player","Computer");
		if (i == 1)
		{
			cout<<"\n ==> \a"<<singleplayername<<" Win";
			singleplayer++;
		}
		else if (i==0)
		{	
			cout<<"\n ==> \aComputer Win";
			computer++;
		}
		else
		{
			cout<<"\n\t\t==> \aGame draw";
		}
		getch();
		markit();
		system("cls");
		scoreboard("Human","Computer");
		return 0;
	}
};

//-------main()------
int main()
{
	system("color 17");
	//system("color EC");
	//system("color 5f");
	cout<<"\n\n\n\n\n\n\n\n\t\t\t       W  E  L  C  O  M  E\n\n\t\t\t\t       TO\n\n\t\t\t          TIC TAC TOE\n";
	cout<<"\n\n\n\n\n\n\n\n\n\t\t\t    MADE BY : Tejinder Singh\n\n";
	timer(); 
	system("cls");
	mainpage();
	return 0;
}

//------main-page()------
void mainpage()
{
	mainmenu();
	int opt;
	cin>>opt;
	if(opt==1)
	{
		humanvscomputer ob;
		ob.oneplayer();
	}
	else if(opt==2)
	{
		humanvshuman ob;
		ob.twoplayer();
	}
	else 
	{
		end();
	}
}

//------Main Menu------
void mainmenu()
{
	system("cls");
	cout<<"\t\t |-------------------------------------------|";
	cout<<endl<<"\t\t\t\t  Tic Tac Toe";
	cout<<endl<<"\t\t |-------------------------------------------|";
	cout<<endl<<endl<<"\t\t\tPress 1 To Play One Player Mode";
	cout<<endl<<endl<<"\t\t\tPress 2 To Play Two Player Mode";
	cout<<endl<<endl<<"\t\t\t        Press 0 To Exit";
	cout<<endl<<endl<<"\t\t |-------------------------------------------|";
	cout<<endl<<endl<<"\t\t        Choose Mode : ";
}

//------Sub Menu------
void submenu(string str1,string str2)
{
	system("cls");
	cout<<"\t\t |-------------------------------------------|";
	cout<<endl<<"\t\t\t\t  Tic Tac Toe";
	cout<<endl<<"\t\t |-------------------------------------------|\n";
	if(str2=="Human")
	{
		cout<<endl<<endl<<"\t\t\t        ----------------"<<endl<<"\t\t\t       | "<<str1<<" vs "<<str2<<" |\n\t\t\t        ----------------";
	}
	else
	{
		cout<<endl<<endl<<"\t\t\t       -------------------"<<endl<<"\t\t\t      | "<<str1<<" vs "<<str2<<" |\n\t\t\t       -------------------";
	}
	cout<<endl<<endl<<endl<<"\t\t\t      Press 1 To Start Game";
	cout<<endl<<endl<<"\t\t\t       Press 0 To Go Back";
	cout<<endl<<endl<<"\t\t |-------------------------------------------|";
	cout<<endl<<endl<<"\t\t        Choose Mode : ";
}

//------Reset------
void markit()
{
	square[0]='0';square[1]='1';square[2]='2';square[3]='3';square[4]='4';square[5]='5';square[6]='6';square[7]='7';square[8]='8';square[9]='9';
}

//------Board------
void board(string str1,string str2)
{
	system("cls");
	cout<<"\t\t |-------------------------------------------|";
	cout<<endl<<"\t\t\t\t  Tic Tac Toe";
	cout<<endl<<"\t\t |-------------------------------------------|"<<endl;
	if(str1=="Player1")
	{cout<<endl<<endl<<"\t\t\t "<<str1<<" (X)  -   "<<str2<<" (O)\n\n\n";}
	else
	{cout<<endl<<endl<<"\t\t\t "<<str1<<" (X)   -   "<<str2<<" (O)\n\n\n";}
	cout<<"\t\t\t           |     |     \n";
	cout<<"\t\t\t        "<<square[1]<<"  |  "<<square[2]<<"  |  "<<square[3]<<" \n";
	cout<<"\t\t\t      _____|_____|_____\n";
	cout<<"\t\t\t           |     |     \n";
	cout<<"\t\t\t        "<<square[4]<<"  |  "<<square[5]<<"  |  "<<square[6]<<" \n";
	cout<<"\t\t\t      _____|_____|_____\n";
	cout<<"\t\t\t           |     |     \n";
	cout<<"\t\t\t        "<<square[7]<<"  |  "<<square[8]<<"  |  "<<square[9]<<" \n";
	cout<<"\t\t\t           |     |     \n\n";
}

//------Score Board------
void scoreboard(string str1,string str2)
{
	system("cls");
	cout<<"\t\t |-------------------------------------------|";
	cout<<endl<<"\t\t\t\t  Tic Tac Toe";
	cout<<endl<<"\t\t |-------------------------------------------|"<<endl;
	cout<<endl<<"\n\t\t\t      S C O R E   B O A R D\n";
	if(str2=="Human")
	{
		humanvshuman ob;
		int opt;
		cout<<endl<<endl<<"\t\t\t        ----------------"<<endl<<"\t\t\t       | "<<str1<<" vs "<<str2<<" |\n\t\t\t        ----------------";
		cout<<endl<<endl<<endl<<"\t\t       "<<player1name<<" : "<<player1<<"\t     "<<player2name<<" : "<<player2<<"\n\n\n";
		cout<<"\n Press 1 To Play Again";
		cout<<"\n\n Press 2 To Start New Game ";
		cout<<"\n\n Press 0 To Exit";
		cout<<"\n\n Option : ";
		cin>>opt;
		switch(opt)
		{
			case 0:
			mainpage();
			break;
			
			case 1:
			timers();
			ob.gamehumanvshuman();
			break;
			
			case 2:
			player1=0;
			player2=0;
			submenu("Human","Human");
			ob.twoplayer();
			
			default :
			end();
			break;
		}
	}
	else
	{
		humanvscomputer ob;
		int opt;
		cout<<endl<<endl<<"\t\t\t       -------------------"<<endl<<"\t\t\t      | "<<str1<<" vs "<<str2<<" |\n\t\t\t       -------------------";
		cout<<endl<<endl<<endl<<"\t\t       "<<singleplayername<<" : "<<singleplayer<<"\t     Computer : "<<computer<<"\n\n\n";
		cout<<"\n Press 1 To Play Again";
		cout<<"\n\n Press 2 To Start New Game ";
		cout<<"\n\n Press 0 To Exit";
		cout<<"\n\n Option : ";
		cin>>opt;
		switch(opt)
		{
			case 0:
			mainpage();
			break;
			
			case 1:
			timers();
			ob.gamehumanvscomputer();
			break;
			
			case 2:
			singleplayer=0;
			submenu("Human","Computer");
			ob.oneplayer();
			
			default :
			end();
			break;
		}
	}
}

//-------Check Win------
int checkwin()
{
	if (square[1] == square[2] && square[2] == square[3])
		{if(square[1] == 'X')
			{return 1;}
		 else 
			{return 0;}}
    else if (square[4] == square[5] && square[5] == square[6])
		{if(square[4] == 'X')
			{return 1;}
		else 
			{return 0;}}
        
    else if (square[7] == square[8] && square[8] == square[9])
		{if(square[7] == 'X')
			{return 1;}
		else 
			{return 0;}}
        
    else if (square[1] == square[4] && square[4] == square[7])
		{if(square[1] == 'X')
			{return 1;}
		else 
			{return 0;}}
        
    else if (square[2] == square[5] && square[5] == square[8])
		{if(square[2] == 'X')
			{return 1;}
		else 
			{return 0;}}
        
    else if (square[3] == square[6] && square[6] == square[9])
		{if(square[3] == 'X')
			{return 1;}
		else 
			{return 0;}}
        
    else if (square[1] == square[5] && square[5] == square[9])
		{if(square[1] == 'X')
			{return 1;}
		else 
			{return 0;}}
        
    else if (square[3] == square[5] && square[5] == square[7])
		{if(square[7] == 'X')
			{return 1;}
		else 
			{return 0;}}
        
    else if (square[1] != '1' && square[2] != '2' && square[3] != '3' &&
        square[4] != '4' && square[5] != '5' && square[6] != '6' && square[7] 
        != '7' && square[8] != '8' && square[9] != '9')
        return 2;
    
    else
        return  - 1;
}

void timer() 
{
    while (sec<3) { 
       sleep(1); 
        sec++;
    } 
}
void timers() 
{
    while (seconds<=1000) { 
       //sleep(1);
       displayClock();  
        seconds++;
    } 
    seconds=1000;
}
void displayClock()
{
	system("cls");
	cout<<"\n\n\n\n\n\n\n\n\n\n\n\t\t\t  LOADING................."<<seconds/10<<"%";
} 

void end()
{
	system("cls");
	cout<<endl<<"\n\n\t\t\t    MADE BY : TEJINDER SINGH\n\n";
}

void name(string str)
{
	string str2="Computer",str3="Human";
	system("cls");
	cout<<"\t\t |-------------------------------------------|";
	cout<<endl<<"\t\t\t\t  Tic Tac Toe";
	cout<<endl<<"\t\t |-------------------------------------------|\n";
	if(str=="Human")
	{
		cout<<endl<<endl<<"\t\t\t        ----------------"<<endl<<"\t\t\t       | "<<str<<" vs "<<str<<" |\n\t\t\t        ----------------";
	}
	else
	{
		cout<<endl<<endl<<"\t\t\t       -------------------"<<endl<<"\t\t\t      | "<<str3<<" vs "<<str2<<" |\n\t\t\t       -------------------";
	}
	if (str=="Human")
	{
		getline(cin,empty);
		cout<<"\n\n\n\n\t\t  Enter Player 1 Name : ";
		getline(cin,player1name);
		cout<<endl<<"\n\t\t  Enter Player 2 Name : ";
		getline(cin,player2name);
	}
	else 
	{
		getline(cin,empty);
		cout<<"\n\n\n\n\t\t  Enter Your Name : ";
		getline(cin,singleplayername);
	}
}
