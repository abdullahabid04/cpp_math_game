#include<iostream>
#include<fstream>
#include<sstream>
#include<cstring>
#include<vector>
#include<cstdlib>
#include<ctime>
#include<iomanip>
#include<conio.h>
#include<windows.h>

#define cls system("cls")
#define pause system("pause")
#define delay Sleep(1000)

using namespace std;

struct Variables
{
	int num1,num2,op;
	int number_of_questions,number_of_wrong_questions,number_of_right_questions;
	int addition_questions,right_addition_questions,wrong_addition_questions;
	int subtraction_questions,right_subtraction_questions,wrong_subtraction_questions;
	int multiplication_questions,right_multiplication_questions,wrong_multiplication_questions;
	int division_questions,right_division_questions,wrong_division_questions;
	int remainder_questions,right_remainder_questions,wrong_remainder_questions;
	int num1_limit,num2_limit;
	int total_games,games_won,games_lost;
	int target,chances;
	int total_hints,hints_used;
	int space;
	float ans,right_ans;
	bool chances_left,target_uncompleted;
	char choice,difficulty_level,oper;
	string fgr,result,target_completed,difficulty;
	string name,filename;
	string START,END;
	vector <int> NoOfGames,NoOfQs,NoOfRAns,NoOfWAns,TotalHints,HintsUsed,HintsLeft,TotalChances,ChancesUsed,ChancesLeft;
	vector <int> totalgames,gameswon,gameslost;
	vector <string> DifficultyLevel,TargetCompleted,FGR;	
};

class Game
{
	public:
		void initialize()
		{
			variables.number_of_questions = 0;
			variables.number_of_wrong_questions = 0;
			variables.number_of_right_questions = 0;
			variables.addition_questions = 0;
			variables.right_addition_questions = 0;
			variables.wrong_addition_questions = 0;
			variables.subtraction_questions = 0;
			variables.right_subtraction_questions = 0;
			variables.wrong_subtraction_questions = 0;
			variables.multiplication_questions = 0;
			variables.right_multiplication_questions = 0;
			variables.wrong_multiplication_questions = 0;
			variables.division_questions = 0;
			variables.right_division_questions = 0;
			variables.wrong_division_questions = 0;
			variables.remainder_questions = 0;
			variables.right_remainder_questions = 0;
			variables.wrong_remainder_questions = 0;
			variables.total_games = 0;
			variables.games_won = 0;
			variables.games_lost = 0;
			variables.space = 3;
			variables.chances_left = true;
			variables.target_uncompleted = true;
			variables.START = "START";
			variables.END = "END";
		}
		void start()
		{
			initialize();
			cls;
			Name();
			delay;
			delay;
			start_game();
		}
		void start_game()
		{
			while(1)
			{
				cls;
				main_menu();
				cout<<"\n\t\t\t\t\t";
				switch(variables.choice=getch())
				{
					case 'P':
					case 'p':
						bell();
						play_game();
						variables.total_games++;
						save_data();
						menu();
						break;
					case 'R':
					case 'r':
						bell();
						cls;
						readme();
						cout<<"\n\t\t\t\t";
						pause;
						cls;
						break;
					case 'S':
					case 's':
						bell();
						cls;
						RESULTS();
						pause;
						cls;		
						break;
					case 'T':
					case 't':
						bell();
						tutorial();
						break;
					case 'E':
					case 'e':
						bell();
						save_final_data();
						RESULTS();
						break;
					default:
						bell();
						start_game();
				}
				reset();
			}
		}
		void play_game()
		{
			cls;		
			select_level();
			cls;
			cout<<"\n\n\n\n\n";
			game_play();
			cls;
			game_end();		
			pause;
			cls;		
			STATISTICS();
			cout<<"\n\n\n\t\t\t\t\t";
			pause;
			cls;
		}
		void select_level()
		{
			cls;
			difficulty_level_menu();
			cout<<"\n\t\t\t\t\t";
			switch((variables.difficulty_level=getch()))
			{
				case 'E':
				case 'e':
					bell();
					variables.difficulty="Easy";
					variables.num1_limit=10;
					variables.num2_limit=5;
					variables.target=10;
					variables.chances=5;
					variables.total_hints=5;
					break;
				case 'M':
				case 'm':
					bell();
					variables.difficulty="Medium";
					variables.num1_limit=20;
					variables.num2_limit=10;
					variables.target=20;
					variables.chances=4;
					variables.total_hints=4;
					break;
				case 'H':
				case 'h':
					bell();
					variables.difficulty="Hard";
					variables.num1_limit=30;
					variables.num2_limit=15;
					variables.target=30;
					variables.chances=3;
					variables.total_hints=3;
					break;
				case 'I':
				case 'i':
					bell();
					variables.difficulty="Insane";	
					variables.num1_limit=40;
					variables.num2_limit=20;
					variables.target=40;
					variables.chances=2;
					variables.total_hints=2;
					break;
				case 'X':
				case 'x':
					bell();
					variables.difficulty="Expert";
					variables.num1_limit=50;
					variables.num2_limit=25;
					variables.target=50;
					variables.chances=1;
					variables.total_hints=1;
					break;
				case 'B':
				case 'b':
					bell();
					start_game();
					break;
				default:
					bell();
					cls;
					select_level();
			}
		}
		void game_play()
		{
			cls;
			while(variables.chances_left && variables.target_uncompleted)                                                             
			{
				srand(time(0));
				random_number();
				check_target();
				statistics();
				delay;
				cout<<"\n\n\n";
				switch(variables.op)
				{
					case 0:
						ADD();
						break;
					case 1:
						SUBTRACT();
						break;
					case 2:
						MULTIPLY();
						break;
					case 3:
						DIVIDE();
						break;
					case 4:
						REMAINDER();
						break;
					default:
						break;
				}
				check();
				game_over();
			}			
		}
		void random_number()
		{
			variables.num1=1+rand()%variables.num1_limit;
			variables.num2=1+rand()%variables.num2_limit;
			variables.op=rand()%5;			
		}
		void ADD()
		{
			variables.right_ans = variables.num1+variables.num2;
			cout<<"\t----------------------------------------------------------"<<endl;
			cout<<"\t----------------------------------------------------------"<<endl;
			cout<<"\t\t\t"<<right<<setw(variables.space)<<variables.num1<<" + "<<left<<setw(variables.space)<<variables.num2<<right<<setw(variables.space)<<" = ";
			cin>>variables.ans;
			exit_game();
			cout<<"\t----------------------------------------------------------"<<endl;
			cout<<endl;
			if(variables.ans == variables.num1+variables.num2)
			{
				variables.result = "right";
				variables.number_of_right_questions++;
				variables.right_addition_questions++;
			}
			else
			{
				variables.result = "wrong";
				variables.number_of_wrong_questions++;
				variables.wrong_addition_questions++;
			}
			variables.number_of_questions++;
			variables.addition_questions++;			
		}
		void SUBTRACT()
		{
			variables.right_ans = variables.num1-variables.num2;
			cout<<"\t----------------------------------------------------------"<<endl;
			cout<<"\t----------------------------------------------------------"<<endl;
			cout<<"\t\t\t"<<right<<setw(variables.space)<<variables.num1<<" - "<<left<<setw(variables.space)<<variables.num2<<right<<setw(variables.space)<<" = ";
			cin>>variables.ans;
			exit_game();
			cout<<"\t----------------------------------------------------------"<<endl;
			cout<<endl;
			if(variables.ans == variables.num1-variables.num2)
			{
				variables.result = "right";
				variables.number_of_right_questions++;
				variables.right_subtraction_questions++;
			}
			else
			{
				variables.result = "wrong";
				variables.number_of_wrong_questions++;
				variables.wrong_subtraction_questions++;
			}
			variables.number_of_questions++;
			variables.subtraction_questions++;
		}
		void MULTIPLY()
		{
			variables.right_ans = variables.num1*variables.num2;
			cout<<"\t----------------------------------------------------------"<<endl;
			cout<<"\t----------------------------------------------------------"<<endl;
			cout<<"\t\t\t"<<right<<setw(variables.space)<<variables.num1<<" * "<<left<<setw(variables.space)<<variables.num2<<right<<setw(variables.space)<<" = ";
			cin>>variables.ans;
			exit_game();
			cout<<"\t----------------------------------------------------------"<<endl;
			cout<<endl;
			if(variables.ans == variables.num1*variables.num2)
			{
				variables.result = "right";
				variables.number_of_right_questions++;
				variables.right_multiplication_questions++;
			}
			else
			{
				variables.result = "wrong";
				variables.number_of_wrong_questions++;
				variables.wrong_multiplication_questions++;
			}
			variables.number_of_questions++;
			variables.multiplication_questions++;
		}
		void DIVIDE()
		{
			while(variables.num1<variables.num2)
			{
				random_number();
			}
			variables.right_ans = variables.num1/variables.num2;
			cout<<"\t----------------------------------------------------------"<<endl;
			cout<<"\t----------------------------------------------------------"<<endl;
			cout<<"\t\t\t"<<right<<setw(variables.space)<<variables.num1<<" / "<<left<<setw(variables.space)<<variables.num2<<right<<setw(variables.space)<<" = ";
			cin>>variables.ans;
			exit_game();
			cout<<"\t----------------------------------------------------------"<<endl;
			cout<<endl;
			if(variables.ans == variables.num1/variables.num2)
			{
				variables.result = "right";
				variables.number_of_right_questions++;
				variables.right_division_questions++;
			}
			else
			{
				variables.result = "wrong";
				variables.number_of_wrong_questions++;
				variables.wrong_division_questions++;
			}
			variables.number_of_questions++;
			variables.division_questions++;
		}
		void REMAINDER()
		{
			while(variables.num1<variables.num2)
			{
				random_number();			
			}
			cout<<"\t----------------------------------------------------------"<<endl;
			cout<<"\t----------------------------------------------------------"<<endl;
			cout<<"\t\t\t"<<right<<setw(variables.space)<<variables.num1<<" % "<<left<<setw(variables.space)<<variables.num2<<right<<setw(variables.space)<<" = ";
			cin>>variables.ans;
			exit_game();
			cout<<"\t----------------------------------------------------------"<<endl;
			cout<<endl;
			if(variables.ans == variables.num1%variables.num2)
			{
				variables.result = "right";
				variables.number_of_right_questions++;
				variables.right_remainder_questions++;
			}
			else
			{
				variables.result = "wrong";
				variables.number_of_wrong_questions++;
				variables.wrong_remainder_questions++;
			}
			variables.number_of_questions++;
			variables.remainder_questions++;
		}
		void check()
		{
			if(variables.result == "right")
			{
				cout<<"\t\t---------------------------------------------"<<endl;
				cout<<"\t\t\tYou entered the "<<variables.result<<" answer"<<endl;
				cout<<"\t\t---------------------------------------------"<<endl;
			}
			else
			{
				cout<<"\t\t---------------------------------------------"<<endl;
				cout<<"\t\t\tYou entered the "<<variables.result<<" answer"<<endl;
				cout<<"\t\t---------------------------------------------"<<endl;
				cout<<"\t\t---------------------------------------------"<<endl;
				cout<<"\t\t\tThe right answer is "<<variables.right_ans<<endl;
				cout<<"\t\t---------------------------------------------"<<endl;
			}
			delay;
			delay;
			cls;		
		}
		void check_target()
		{
			if(variables.number_of_right_questions == variables.target)
			{
				variables.target_completed = "Yes";
			}
			else
			{
				variables.target_completed = "No";
			}
		}
		void game_over()
		{
			if(variables.number_of_wrong_questions == variables.chances || variables.number_of_right_questions == variables.target)
			{
				if(variables.number_of_wrong_questions == variables.chances)
				{
					variables.chances_left = false;
				}
				if(variables.number_of_right_questions == variables.target)
				{
					variables.target_uncompleted = false;
					variables.target_completed = "Yes";
					variables.games_won++;
				}
				else
				{
					variables.target_completed = "No";
					variables.games_lost++;
				}
			}
		}
		void game_end()
		{
			cout<<"\n\n\n\n\n\t\t\t\tGAME OVER!";
			if(variables.chances_left)
			{
				cout<<"\n\n\t\t\t\tYOU WIN";
				variables.fgr="WON";
			}
			else
			{
				cout<<"\n\n\t\t\t\tYOU LOSE";
				variables.fgr="LOST";
			}
			cout<<"\n\n\t\tPress any key to see your statistics\n\n\t\t\t";			
		}
		void tutorial()
		{
			while(variables.ans != 5 + 3)
			{
				cls;
				cout<<"\n\n\n\t\t\t\t5 + 3 = ";
				cin>>variables.ans;
			}
			cout<<"\n\n\t\t\tYou entered the right answer";
			delay;
			while(variables.ans != 8 - 4)
			{
				cls;
				cout<<"\n\n\n\t\t\t\t8 - 4 = ";
				cin>>variables.ans;
			}
			cout<<"\n\n\t\t\tYou entered the right answer";
			delay;
			while(variables.ans != 3 * 2)
			{
				cls;
				cout<<"\n\n\n\t\t\t\t3 * 2 = ";
				cin>>variables.ans;
			}
			cout<<"\n\n\t\t\tYou entered the right answer";
			delay;
			while(variables.ans != 8 / 2)
			{
				cls;
				cout<<"\n\n\n\t\t\t\t8 / 2 = ";
				cin>>variables.ans;
			}
			cout<<"\n\n\t\t\tYou entered the right answer";
			delay;
			while(variables.ans != 9 % 4)
			{
				cls;
				cout<<"\n\n\n\t\t\t\t9 % 4 = ";
				cin>>variables.ans;
			}
			cout<<"\n\n\t\t\tYou entered the right answer";
			delay;
			cls;
			cout<<"\n\n\n\t\t\t\tCONGRATULATIONS!\n\n\t\t\tYou completed your tutorial\n\n\t\t\t\tYou are ready"<<endl;
			delay;
			delay;
			cout<<"\n\n\t\t\tSee the README of the game and then play game\n\n\n";
			delay;
			cls;
			readme();
			cout<<"\n\n\n\t\t\t\t\t";
			pause;
		}
		void Name()
		{
			cout<<"\n\n\n\n\n";
			cout<<"\t\t________________________________________________________"<<endl;
			cout<<"\t\t|                ___________________                   |"<<endl;
			cout<<"\t\t|                |Enter your name  |                   |"<<endl;
			cout<<"\t\t|                |_________________|                   |"<<endl;
			cout<<"\t\t|                ___________________                   |"<<endl;
			cout<<"\t\t|                |                 |                   |"<<endl;
			cout<<"\t\t\t\t\t";
			cin>>variables.name;
			cout<<"\t\t|                |_________________|                   |"<<endl;
			cout<<"\t\t|                                                      |"<<endl;				
			cout<<"\t\t|______________________________________________________|"<<endl;			
			cout<<"\t\t\t\t\t";			
		}
		void statistics()
		{
			cout<<"\t___________________________________________________________"<<endl;
			cout<<"\t|                                                         |"<<endl;
			cout<<"\t|                                                         |"<<endl;
			cout<<"\t|                                                         |"<<endl;
			cout<<"\t|--------------------Current STATISTICS-------------------"<<"|"<<endl;
			cout<<"\t|Difficulty Level                        : "<<variables.difficulty<<"\t\t  |"<<endl;
			cout<<"\t|Total questions                         : "<<variables.number_of_questions<<"\t\t  |"<<endl;
			cout<<"\t|Right answers                           : "<<variables.number_of_right_questions<<"\t\t  |"<<endl;
			cout<<"\t|Wrong answers                           : "<<variables.number_of_wrong_questions<<"\t\t  |"<<endl;
			cout<<"\t|Target                                  : "<<variables.target<<" questions"<<"\t  |"<<endl;
			cout<<"\t|Target completed                        : "<<variables.target_completed<<"\t\t  |"<<endl;
			cout<<"\t|Right answers remain to complete target : "<<variables.target-variables.number_of_right_questions<<"\t\t  |"<<endl;
			cout<<"\t|Total chances                           : "<<variables.chances<<"\t\t  |"<<endl;
			cout<<"\t|Chances Used                            : "<<variables.number_of_wrong_questions<<"\t\t  |"<<endl;
			cout<<"\t|Chances Left                            : "<<variables.chances-variables.number_of_wrong_questions<<"\t\t  |"<<endl;
			cout<<"\t|Total hints                             : "<<variables.total_hints<<"\t\t  |"<<endl;
			cout<<"\t|Hints Left                              : "<<variables.total_hints-variables.hints_used<<"\t\t  |"<<endl;
			cout<<"\t|Hints used                              : "<<variables.hints_used<<"\t\t  |"<<endl;
			cout<<"\t|---------------------------------------------------------|"<<endl;
			cout<<"\t|                                                         |"<<endl;
			cout<<"\t|                                                         |"<<endl;
			cout<<"\t|                                                         |"<<endl;
			cout<<"\t|_________________________________________________________|"<<endl;							
		}
		void STATISTICS()
		{
			cout<<"\t\t\t-------------STATISTICS-------------"<<endl;
			cout<<"\t\t\t------------------------------------"<<endl;
			cout<<"\t\t\tTraget Completed                  : "<<variables.target_completed<<endl;
			cout<<"\t\t\t------------------------------------"<<endl;
			cout<<"\t\t\tTotal questions                   : "<<variables.number_of_questions<<endl;
			cout<<"\t\t\tRight answers                     : "<<variables.number_of_right_questions<<endl;
			cout<<"\t\t\tWrong answers                     : "<<variables.number_of_wrong_questions<<endl;
			cout<<"\t\t\t------------------------------------"<<endl;
			cout<<"\t\t\tTotal addition questions          : "<<variables.addition_questions<<endl;
			cout<<"\t\t\tRight addition answers            : "<<variables.right_addition_questions<<endl;
			cout<<"\t\t\tWrong addition answers            : "<<variables.wrong_addition_questions<<endl;
			cout<<"\t\t\t------------------------------------"<<endl;
			cout<<"\t\t\tTotal subtraction questions       : "<<variables.subtraction_questions<<endl;
			cout<<"\t\t\tRight subtraction answers         : "<<variables.right_subtraction_questions<<endl;
			cout<<"\t\t\tWrong subtraction answers         : "<<variables.wrong_subtraction_questions<<endl;
			cout<<"\t\t\t------------------------------------"<<endl;
			cout<<"\t\t\tTotal multiplication questions    : "<<variables.multiplication_questions<<endl;
			cout<<"\t\t\tRight multiplication answers      : "<<variables.right_multiplication_questions<<endl;
			cout<<"\t\t\tWrong multiplication answers      : "<<variables.wrong_multiplication_questions<<endl;
			cout<<"\t\t\t------------------------------------"<<endl;
			cout<<"\t\t\tTotal division questions          : "<<variables.division_questions<<endl;
			cout<<"\t\t\tRight division answers            : "<<variables.right_division_questions<<endl;
			cout<<"\t\t\tWrong division answers            : "<<variables.wrong_division_questions<<endl;
			cout<<"\t\t\t------------------------------------"<<endl;	
			cout<<"\t\t\tTotal remainder questions         : "<<variables.remainder_questions<<endl;
			cout<<"\t\t\tRight remainder answers           : "<<variables.right_remainder_questions<<endl;
			cout<<"\t\t\tWrong remainder answers           : "<<variables.wrong_remainder_questions<<endl;
			cout<<"\t\t\t------------------------------------"<<endl;
		}
		void RESULTS()
		{
			cls;
			cout<<"\t\t\t-------------------------------------------"<<endl;			
			cout<<"\t\t\t---------------FINAL RESULTS---------------"<<endl;
			cout<<"\t\t\t-------------------------------------------"<<endl;
			cout<<"\t\t\tGames played       : "<<variables.total_games<<endl;
			cout<<"\t\t\tGames won          : "<<variables.games_won<<endl;
			cout<<"\t\t\tGames lost         : "<<variables.games_lost<<endl;
			cout<<"\t\t\t-------------------------------------------"<<endl;
			cout<<"\n\n\n\t\t\t\t\t";
			pause;
			cls;		
			exit(0);
		}
		void readme()
		{
			cout<<"\n\t\t-------------------------------------------------------"<<endl;						
			cout<<"\n\t\t-------------------------README------------------------"<<endl;						
			cout<<"\n\t\t-------------------------------------------------------"<<endl;						
			cout<<"\n\t\t-------------------------------------------------------"<<endl;						
			cout<<"\n\t\t------------------------CONTROLS-----------------------"<<endl;						
			cout<<"\n\t\t-------------------------------------------------------"<<endl;						
			cout<<"\n\t\tPress P or p to play game"<<endl;
			cout<<"\n\t\tPress T or t to play tutorial"<<endl;
			cout<<"\n\t\tPress R or r to view readme"<<endl;
			cout<<"\n\t\tPress S or s to view statistics"<<endl;
			cout<<"\n\t\tPress E or e to exit game"<<endl;
			cout<<"\n\t\tPress CTRL + z at any time to open Game Menu"<<endl;
			cout<<"\n\t\tIn game menu after game overs"<<endl;
			cout<<"\n\t\t\t\tPress A or a to play again"<<endl;
			cout<<"\n\t\t\t\tPress D or d to go to difficulty level menu"<<endl;
			cout<<"\n\t\t\t\tPress M or m to go to main menu"<<endl;
			cout<<"\n\t\tIn pause menu"<<endl;
			cout<<"\n\t\t\t\tPress C or c to continue"<<endl;
			cout<<"\n\t\t\t\tPress D or d to go to difficulty level menu"<<endl;
			cout<<"\n\t\t\t\tPress M or m to go to main menu"<<endl;
			cout<<"\n\t\t\t\tPress H or h to use hint"<<endl;
			cout<<"\n\t\t-------------------------------------------------------"<<endl;						
			cout<<"\n\t\t----------------------HOW TO PLAY----------------------"<<endl;						
			cout<<"\n\t\t-------------------------------------------------------"<<endl;						
			cout<<"\n\t\tThis game asks you different types of MATH Questions."<<endl;
			cout<<"\n\t\tThe questions include ADDITION , SUBTRACTION , "<<endl;
			cout<<"\n\t\tMULTIPLICATION , DIVISION and REMAINDER"<<endl;
			cout<<"\n\t\tYou have to answer these questions."<<endl;
			cout<<"\n\t\tFor winning game gives you different targets."<<endl;
			cout<<"\n\t\tIf you complete the target you win."<<endl;
			cout<<"\n\t\tOtherwise you lose."<<endl;
			cout<<"\n\t\tFor more information , See the DIFFICULTY LEVELS"<<endl;
			cout<<"\n\t\tsection"<<endl;
			cout<<"\n\t\t-------------------------------------------------------"<<endl;						
			cout<<"\n\t\t-------------------DIFFICULTY LEVEL--------------------"<<endl;						
			cout<<"\n\t\t-------------------------------------------------------"<<endl;						
			cout<<"\n\t\tIn Easy Difficulty : ";
			cout<<"\n\t\t\tRange of 1st number 0 - 10";
			cout<<"\n\t\t\tRange of 2nd number 0 - 5";
			cout<<"\n\t\t\tTarget : Answer 10 questions right";
			cout<<"\n\t\t\tLose on 5 wrong answers";
			cout<<"\n\t\t\tHints : 5";
			cout<<"\n\t\tIn Medium Difficulty : ";
			cout<<"\n\t\t\tRange of 1st number 0 - 20";
			cout<<"\n\t\t\tRange of 2nd number 0 - 10";
			cout<<"\n\t\t\tTarget : Answer 20 questions right";
			cout<<"\n\t\t\tLose on 4 wrong answers";
			cout<<"\n\t\t\tHints : 4";
			cout<<"\n\t\tIn Hard Difficulty : ";
			cout<<"\n\t\t\tRange of 1st number 0 - 30";
			cout<<"\n\t\t\tRange of 2nd number 0 - 15";
			cout<<"\n\t\t\tTarget : Answer 30 questions right";
			cout<<"\n\t\t\tLose on 3 wrong answers";
			cout<<"\n\t\t\tHints : 3";
			cout<<"\n\t\tIn Insane Difficulty : ";
			cout<<"\n\t\t\tRange of 1st number 0 - 40";
			cout<<"\n\t\t\tRange of 2nd number 0 - 20";
			cout<<"\n\t\t\tTarget : Answer 40 questions right";
			cout<<"\n\t\t\tLose on 2 wrong answers";
			cout<<"\n\t\t\tHints : 2";
			cout<<"\n\t\tIn Expert Difficulty : ";
			cout<<"\n\t\t\tRange of 1st number 0 - 50";
			cout<<"\n\t\t\tRange of 2nd number 0 - 25";
			cout<<"\n\t\t\tTarget : Answer 50 questions right";
			cout<<"\n\t\t\tLose on 1 wrong answers";
			cout<<"\n\t\t\tHints : 1";
			cout<<"\n\t\t-------------------------------------------------------"<<endl;						
			cout<<"\n\t\t----------DIFFICULTY LEVEL SELECTION CONTROLS----------"<<endl;
			cout<<"\n\t\t-------------------------------------------------------"<<endl;									
			cout<<"\n\t\t\tPress E or e for Easy"<<endl;
			cout<<"\n\t\t\tPress M or m for Medium"<<endl;
			cout<<"\n\t\t\tPress H or h for Hard"<<endl;
			cout<<"\n\t\t\tPress I or i for Insane"<<endl;
			cout<<"\n\t\t\tPress X or x for Expert"<<endl;
			cout<<"\n\t\t\tPress B or b to go to main menu"<<endl;
			cout<<"\n\t\t-------------------------------------------------------"<<endl;						
		}
		void main_menu()
		{
			cout<<"\t\t____________________________________________________"<<endl;
			cout<<"\t\t|                                                  |"<<endl;
			cout<<"\t\t|                                                  |"<<endl;
			cout<<"\t\t|                                                  |"<<endl;
			cout<<"\t\t|                     MATH QUIZ                    |"<<endl;
			cout<<"\t\t|                                                  |"<<endl;
			cout<<"\t\t|                     MAIN MENU                    |"<<endl;
			cout<<"\t\t|                                                  |"<<endl;
			cout<<"\t\t|                    ___________                   |"<<endl;
			cout<<"\t\t|                    |  PLAY   |                   |"<<endl;
			cout<<"\t\t|                    |_________|                   |"<<endl;				
			cout<<"\t\t|                    ___________                   |"<<endl;
			cout<<"\t\t|                    |TUTORIAL |                   |"<<endl;
			cout<<"\t\t|                    |_________|                   |"<<endl;
			cout<<"\t\t|                    ___________                   |"<<endl;
			cout<<"\t\t|                    | README  |                   |"<<endl;
			cout<<"\t\t|                    |_________|                   |"<<endl;
			cout<<"\t\t|                    ___________                   |"<<endl;
			cout<<"\t\t|                    |  STATS  |                   |"<<endl;
			cout<<"\t\t|                    |_________|                   |"<<endl;
			cout<<"\t\t|                    ___________                   |"<<endl;
			cout<<"\t\t|                    |  EXIT   |                   |"<<endl;
			cout<<"\t\t|                    |_________|                   |"<<endl;
			cout<<"\t\t|                                                  |"<<endl;
			cout<<"\t\t|                                                  |"<<endl;
			cout<<"\t\t|                                                  |"<<endl;
			cout<<"\t\t|                                                  |"<<endl;
			cout<<"\t\t|                                                  |"<<endl;				
			cout<<"\t\t|__________________________________________________|"<<endl;			
		}
		void difficulty_level_menu()
		{
			cout<<"\t\t____________________________________________________"<<endl;
			cout<<"\t\t|                                                  |"<<endl;
			cout<<"\t\t|                                                  |"<<endl;
			cout<<"\t\t|                                                  |"<<endl;
			cout<<"\t\t|              SELECT DIFFICULTY LEVEL             |"<<endl;
			cout<<"\t\t|                                                  |"<<endl;
			cout<<"\t\t|                    ___________                   |"<<endl;
			cout<<"\t\t|                    |  EASY   |                   |"<<endl;
			cout<<"\t\t|                    |_________|                   |"<<endl;				
			cout<<"\t\t|                    ___________                   |"<<endl;
			cout<<"\t\t|                    | MEDIUM  |                   |"<<endl;
			cout<<"\t\t|                    |_________|                   |"<<endl;
			cout<<"\t\t|                    ___________                   |"<<endl;
			cout<<"\t\t|                    |  HARD   |                   |"<<endl;
			cout<<"\t\t|                    |_________|                   |"<<endl;				
			cout<<"\t\t|                    ___________                   |"<<endl;
			cout<<"\t\t|                    |  INSANE |                   |"<<endl;
			cout<<"\t\t|                    |_________|                   |"<<endl;
			cout<<"\t\t|                    ___________                   |"<<endl;
			cout<<"\t\t|                    |  EXPERT |                   |"<<endl;
			cout<<"\t\t|                    |_________|                   |"<<endl;
			cout<<"\t\t|                                                  |"<<endl;
			cout<<"\t\t|                                                  |"<<endl;
			cout<<"\t\t|                                                  |"<<endl;
			cout<<"\t\t|                                                  |"<<endl;
			cout<<"\t\t|                                                  |"<<endl;				
			cout<<"\t\t|__________________________________________________|"<<endl;			
		}
		void menu()
		{
			cout<<"\t\t_______________________________________________________"<<endl;
			cout<<"\t\t|                ___________________                   |"<<endl;
			cout<<"\t\t|                |   PLAY AGAIN    |                   |"<<endl;
			cout<<"\t\t|                |_________________|                   |"<<endl;
			cout<<"\t\t|                ___________________                   |"<<endl;
			cout<<"\t\t|                | DIFFICULTY MENU |                   |"<<endl;
			cout<<"\t\t|                |_________________|                   |"<<endl;
			cout<<"\t\t|                ___________________                   |"<<endl;
			cout<<"\t\t|                |   MAIN MENU     |                   |"<<endl;
			cout<<"\t\t|                |_________________|                   |"<<endl;
			cout<<"\t\t|                                                      |"<<endl;				
			cout<<"\t\t|______________________________________________________|"<<endl;
			switch(variables.choice=getch())
			{
				case 'A':
				case 'a':
					bell();
					reset();
					game_play();
					break;
				case 'D':
				case 'd':
					bell();
					reset();
					select_level();
					break;
				case 'M':
				case 'm':
					bell();
					reset();
					start_game();
					break;
				default:
					bell();
					menu();
			}												
		}
		void game_menu()
		{
			cout<<"\t\t_______________________________________________________ "<<endl;
			cout<<"\t\t|                ___________________                   |"<<endl;
			cout<<"\t\t|                |    CONTINUE     |                   |"<<endl;
			cout<<"\t\t|                |_________________|                   |"<<endl;
			cout<<"\t\t|                ___________________                   |"<<endl;
			cout<<"\t\t|                | DIFFICULTY MENU |                   |"<<endl;
			cout<<"\t\t|                |_________________|                   |"<<endl;
			cout<<"\t\t|                ___________________                   |"<<endl;
			cout<<"\t\t|                |   MAIN MENU     |                   |"<<endl;
			cout<<"\t\t|                |_________________|                   |"<<endl;
			cout<<"\t\t|                ___________________                   |"<<endl;
			cout<<"\t\t|                |      HINT       |                   |"<<endl;
			cout<<"\t\t|                |_________________|                   |"<<endl;
			cout<<"\t\t|                                                      |"<<endl;				
			cout<<"\t\t|______________________________________________________|"<<endl;
			switch(variables.choice=getch())
			{
				case 'C':
				case 'c':
					bell();
					cls;
					statistics();
					continue_game();
					break;
				case 'D':
				case 'd':
					bell();
					variables.total_games++;
					variables.games_lost++;
					variables.fgr="LOST";
					save_data();
					reset();
					select_level();
					game_play();
					break;
				case 'M':
				case 'm':
					bell();
					variables.total_games++;
					variables.games_lost++;
					variables.fgr="LOST";
					save_data();
					reset();
					start_game();
					break;
				case 'H':
				case 'h':
					bell();
					cls;
					statistics();
					hint();
					variables.hints_used++;
					break;					
				default:
					bell();
					game_menu();
			}												
		}
		void hint()
		{
			cout<<"\n\n\n";
			if(variables.hints_used==variables.total_hints)
			{
				cout<<"\t----------------------------------------------------------"<<endl;
				cout<<"\n\n\t\t\t\tYou are out of hints"<<endl;
				cout<<"\t----------------------------------------------------------"<<endl;
			}
			else
			{
				cout<<"\t----------------------------------------------------------"<<endl;
				cout<<"\n\n\t\t\tHint : "<<variables.right_ans<<endl;	
				cout<<"\t----------------------------------------------------------"<<endl;
			}
			continue_game();
		}
		void continue_game()
		{
			switch(variables.op)
			{
				case 0:
					variables.oper='+';
					break;
				case 1:
					variables.oper='-';
					break;
				case 2:
					variables.oper='*';
					break;
				case 3:
					variables.oper='/';
					break;
				case 4:
					variables.oper='%';
					break;
			}
			cout<<"\n\n\n";
			cout<<"\t----------------------------------------------------------"<<endl;
			cout<<"\n\t\t\t"<<right<<setw(variables.space)<<variables.num1<<" "<<variables.oper<<" "<<left<<setw(variables.space)<<variables.num2<<right<<setw(variables.space)<<" = ";
			cin>>variables.ans;
			exit_game();			
			cout<<"\t----------------------------------------------------------"<<endl;
		}		
		void reset()
		{
			variables.number_of_questions=0;
			variables.number_of_wrong_questions=0;
			variables.number_of_right_questions=0;
			variables.addition_questions=0;
			variables.subtraction_questions=0;
			variables.multiplication_questions=0;
			variables.division_questions=0;
			variables.remainder_questions=0;
			variables.wrong_addition_questions=0;
			variables.wrong_subtraction_questions=0;
			variables.wrong_multiplication_questions=0;
			variables.wrong_division_questions=0;
			variables.wrong_remainder_questions=0;
			variables.right_addition_questions=0;
			variables.right_subtraction_questions=0;
			variables.right_multiplication_questions=0;
			variables.right_division_questions=0;
			variables.right_remainder_questions=0;
			variables.hints_used=0;
			variables.chances_left = true;
			variables.target_uncompleted = true;
		}
		void bell()
		{
			cout<<"\a";
		}
		void exit_game()
		{
			if(cin.eof())
			{
				cls;
				cin.clear();
				game_menu();
			}
		}
		void save_statistics()
		{
			variables.NoOfGames.push_back(variables.total_games);
			variables.NoOfQs.push_back(variables.number_of_questions);
			variables.NoOfRAns.push_back(variables.number_of_right_questions);
			variables.NoOfWAns.push_back(variables.number_of_wrong_questions);
			variables.TotalHints.push_back(variables.total_hints);
			variables.HintsUsed.push_back(variables.hints_used);
			variables.HintsLeft.push_back(variables.total_hints-variables.hints_used);
			variables.TotalChances.push_back(variables.chances);
			variables.ChancesUsed.push_back(variables.number_of_wrong_questions);
			variables.ChancesLeft.push_back(variables.chances-variables.number_of_wrong_questions);
			variables.DifficultyLevel.push_back(variables.difficulty);
			variables.TargetCompleted.push_back(variables.target_completed);
			variables.FGR.push_back(variables.fgr);
		}
		void save_data()
		{
			save_statistics();
			variables.filename=variables.name+variables.START;
			variables.filename+=".txt";
			ofstream file_out;
			file_out.open(variables.filename.c_str());
			file_out<<"---------------------------------------------------------";
			file_out<<"---------------------------------------------------------"<<endl;
			file_out<<"\t\t| NQ | Number of questions | RA | Right answers    | WA | Wrong answers  |"<<endl;
			file_out<<"\t\t| TH | Total hints         | HU | Hints used       | HL | Hints left     |"<<endl;
			file_out<<"\t\t| TC | Total chances       | CU | Chances used     | CL | Chances left   |"<<endl;
			file_out<<"\t\t| DL | Difficulty level    | TC | Target completed | WL | Win/Lose       |"<<endl;
			file_out<<"---------------------------------------------------------";
			file_out<<"---------------------------------------------------------"<<endl;
			file_out<<"---------------------------------------------------------";
			file_out<<"---------------------------------------------------------"<<endl;
			file_out<<"\t\tNQ\tRA\tWA\tTH\tHU\tHL\tTC\tCU\tCL\tDL\tTC\tWL"<<endl;
			file_out<<"---------------------------------------------------------";
			file_out<<"---------------------------------------------------------"<<endl;
			for(int i=0;i<variables.NoOfGames.size();i++)
			{
				file_out<<"Game no. "<<i+1<<" :\t"<<variables.NoOfQs[i]<<"\t"<<variables.NoOfRAns[i]<<"\t"<<variables.NoOfWAns[i]<<"\t";
				file_out<<variables.TotalHints[i]<<"\t"<<variables.HintsUsed[i]<<"\t"<<variables.HintsLeft[i]<<"\t";
				file_out<<variables.TotalChances[i]<<"\t"<<variables.ChancesUsed[i]<<"\t"<<variables.ChancesLeft[i]<<"\t";
				file_out<<variables.DifficultyLevel[i]<<"\t"<<variables.TargetCompleted[i]<<"\t"<<variables.FGR[i]<<endl;
			}
			file_out.close();
		}
		void save_final_statistics()
		{
			variables.totalgames.push_back(variables.total_games);
			variables.gameswon.push_back(variables.games_won);
			variables.gameslost.push_back(variables.games_lost);
		}
		void save_final_data()
		{
			save_final_statistics();
			variables.filename=variables.name+variables.END;
			cout<<"\t\t\t"<<right<<setw(variables.space)<<variables.num1<<" % "<<left<<setw(variables.space)<<variables.num2<<right<<setw(variables.space)<<" = ";
			variables.filename+=".txt";
			ofstream file_out;
			file_out.open(variables.filename.c_str());
			file_out<<"----------------------------------"<<endl;
			file_out<<"| NG | Total Games |"<<endl;			
			file_out<<"| GW | Games Won   |"<<endl;			
			file_out<<"| GL | Games Lost  |"<<endl;			
			file_out<<"----------------------------------"<<endl;
			file_out<<"NG\tGW\tGL"<<endl;
			file_out<<"----------------------------------"<<endl;
			for(int i=0;i<variables.totalgames.size();i++)
			{
				file_out<<variables.totalgames[i]<<"\t"<<variables.gameswon[i]<<"\t"<<variables.gameslost[i]<<endl;
			}
			file_out.close();
		}
	private:
		Variables variables;
};

int main()
{
	Game game;
	game.start();
	return 0;
}
