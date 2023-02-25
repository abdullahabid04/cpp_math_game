#include<iostream>
#include<cstdlib>
#include<ctime>
#include<iomanip>
#include<cstring>
#include<conio.h>
#include<windows.h>

#define cls system("cls")
#define pause system("pause")
#define delay Sleep(1000)

using namespace std;

class Game
{
	public:
		void start_game()
		{
			cls;
			while(1)
			{
				cls;
				main_menu();
				cout<<"\n\t\t\t\t\t";
				switch(choice=getch())
				{
					case 'P':
					case 'p':
						bell();
						play_game();
						total_games++;
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
						cout<<"\t\t\t-------------------------------------------"<<endl;
						cout<<"\t\t\t-----------------STATISTICS----------------"<<endl;
						cout<<"\t\t\t-------------------------------------------"<<endl;
						cout<<"\t\t\tGames played       : "<<total_games<<endl;
						cout<<"\t\t\tGames won          : "<<games_won<<endl;
						cout<<"\t\t\tGames lost         : "<<games_lost<<endl;
						cout<<"\t\t\t-------------------------------------------"<<endl;
						cout<<"\n\n\n\t\t\t\t\t";
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
						RESULTS();
						break;
					default:
						bell();
						start_game();
				}
				reset();
			}
			RESULTS();
		}
		void play_game()
		{
			cls;		
			select_level();
			cls;
			cout<<"\n\n\n\n\n";
			game_play();
			cls;		
			cout<<"\n\n\n\n\n\t\t\t\tGAME OVER!";
			if(chances_left)
			{
				cout<<"\n\n\t\t\t\tYOU WIN";
			}
			else
			{
				cout<<"\n\n\t\t\t\tYOU LOSE";
			}
			cout<<"\n\n\t\tPress any key to see your statistics\n\n\t\t\t";
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
			switch((difficulty_level=getch()))
			{
				case 'E':
				case 'e':
					bell();
					difficulty="Easy";
					num1_limit=10;
					num2_limit=5;
					target=10;
					chances=5;
					total_hints=5;
					break;
				case 'M':
				case 'm':
					bell();
					difficulty="Medium";
					num1_limit=20;
					num2_limit=10;
					target=20;
					chances=4;
					total_hints=4;
					break;
				case 'H':
				case 'h':
					bell();
					difficulty="Hard";
					num1_limit=30;
					num2_limit=15;
					target=30;
					chances=3;
					total_hints=3;
					break;
				case 'I':
				case 'i':
					bell();
					difficulty="Insane";	
					num1_limit=40;
					num2_limit=20;
					target=40;
					chances=2;
					total_hints=2;
					break;
				case 'X':
				case 'x':
					bell();
					difficulty="Expert";
					num1_limit=50;
					num2_limit=25;
					target=50;
					chances=1;
					total_hints=1;
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
			while(chances_left && target_uncompleted)                                                             
			{
				srand(time(0));
				random_number();
				check_target();
				statistics();
				delay;
				cout<<"\n\n\n";
				switch(op)
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
			num1=1+rand()%num1_limit;
			num2=1+rand()%num2_limit;
			op=rand()%5;			
		}
		void ADD()
		{
			right_ans = num1+num2;
			cout<<"\t----------------------------------------------------------"<<endl;
			cout<<"\t\t\t"<<right<<setw(space)<<num1<<" + "<<left<<setw(space)<<num2<<right<<setw(space)<<" = ";
			cin>>ans;
			exit_game();
			cout<<"\t----------------------------------------------------------"<<endl;
			cout<<endl;
			if(ans == num1+num2)
			{
				result = "right";
				number_of_right_questions++;
				right_addition_questions++;
			}
			else
			{
				result = "wrong";
				number_of_wrong_questions++;
				wrong_addition_questions++;
			}
			number_of_questions++;
			addition_questions++;			
		}
		void SUBTRACT()
		{
			right_ans = num1-num2;
			cout<<"\t----------------------------------------------------------"<<endl;
			cout<<"\t\t\t"<<right<<setw(space)<<num1<<" - "<<left<<setw(space)<<num2<<right<<setw(space)<<" = ";
			cin>>ans;
			exit_game();
			cout<<"\t----------------------------------------------------------"<<endl;
			cout<<endl;
			if(ans == num1-num2)
			{
				result = "right";
				number_of_right_questions++;
				right_subtraction_questions++;
			}
			else
			{
				result = "wrong";
				number_of_wrong_questions++;
				wrong_subtraction_questions++;
			}
			number_of_questions++;
			subtraction_questions++;
		}
		void MULTIPLY()
		{
			right_ans = num1*num2;
			cout<<"\t----------------------------------------------------------"<<endl;
			cout<<"\t\t\t"<<right<<setw(space)<<num1<<" * "<<left<<setw(space)<<num2<<right<<setw(space)<<" = ";
			cin>>ans;
			exit_game();
			cout<<"\t----------------------------------------------------------"<<endl;
			cout<<endl;
			if(ans == num1*num2)
			{
				result = "right";
				number_of_right_questions++;
				right_multiplication_questions++;
			}
			else
			{
				result = "wrong";
				number_of_wrong_questions++;
				wrong_multiplication_questions++;
			}
			number_of_questions++;
			multiplication_questions++;
		}
		void DIVIDE()
		{
			while(num1<num2)
			{
				random_number();
			}
			right_ans = num1/num2;
			cout<<"\t----------------------------------------------------------"<<endl;
			cout<<"\t\t\t"<<right<<setw(space)<<num1<<" / "<<left<<setw(space)<<num2<<right<<setw(space)<<" = ";
			cin>>ans;
			exit_game();
			cout<<"\t----------------------------------------------------------"<<endl;
			cout<<endl;
			if(ans == num1/num2)
			{
				result = "right";
				number_of_right_questions++;
				right_division_questions++;
			}
			else
			{
				result = "wrong";
				number_of_wrong_questions++;
				wrong_division_questions++;
			}
			number_of_questions++;
			division_questions++;
		}
		void REMAINDER()
		{
			while(num1<num2)
			{
				random_number();			
			}
			right_ans = num1%num2;
			cout<<"\t----------------------------------------------------------"<<endl;
			cout<<"\t\t\t"<<right<<setw(space)<<num1<<" % "<<left<<setw(space)<<num2<<right<<setw(space)<<" = ";
			cin>>ans;
			exit_game();
			cout<<"\t----------------------------------------------------------"<<endl;
			cout<<endl;
			if(ans == num1%num2)
			{
				result = "right";
				number_of_right_questions++;
				right_remainder_questions++;
			}
			else
			{
				result = "wrong";
				number_of_wrong_questions++;
				wrong_remainder_questions++;
			}
			number_of_questions++;
			remainder_questions++;
		}
		void check()
		{
			if(result == "right")
			{
				cout<<"\t\t---------------------------------------------"<<endl;
				cout<<"\t\t\tYou entered the "<<result<<" answer"<<endl;
				cout<<"\t\t---------------------------------------------"<<endl;
			}
			else
			{
				cout<<"\t\t---------------------------------------------"<<endl;
				cout<<"\t\t\tYou entered the "<<result<<" answer"<<endl;
				cout<<"\t\t---------------------------------------------"<<endl;
				cout<<"\t\t---------------------------------------------"<<endl;
				cout<<"\t\t\tThe right answer is "<<right_ans<<endl;
				cout<<"\t\t---------------------------------------------"<<endl;
			}
			delay;
			delay;
			cls;		
		}
		void check_target()
		{
			if(number_of_right_questions == target)
			{
				target_completed = "Yes";
			}
			else
			{
				target_completed = "No";
			}
		}
		void game_over()
		{
			if(number_of_wrong_questions == chances || number_of_right_questions == target)
			{
				if(number_of_wrong_questions == chances)
				{
					chances_left = false;
				}
				if(number_of_right_questions == target)
				{
					target_uncompleted = false;
					target_completed = "Yes";
					games_won++;
				}
				else
				{
					target_completed = "No";
					games_lost++;
				}
			}
		}
		void tutorial()
		{
			while(ans != 5 + 3)
			{
				cls;
				cout<<"\n\n\n\t\t\t\t5 + 3 = ";
				cin>>ans;
			}
			cout<<"\n\n\t\t\tYou entered the right answer";
			delay;
			while(ans != 8 - 4)
			{
				cls;
				cout<<"\n\n\n\t\t\t\t8 - 4 = ";
				cin>>ans;
			}
			cout<<"\n\n\t\t\tYou entered the right answer";
			delay;
			while(ans != 3 * 2)
			{
				cls;
				cout<<"\n\n\n\t\t\t\t3 * 2 = ";
				cin>>ans;
			}
			cout<<"\n\n\t\t\tYou entered the right answer";
			delay;
			while(ans != 8 / 2)
			{
				cls;
				cout<<"\n\n\n\t\t\t\t8 / 2 = ";
				cin>>ans;
			}
			cout<<"\n\n\t\t\tYou entered the right answer";
			delay;
			while(ans != 9 % 4)
			{
				cls;
				cout<<"\n\n\n\t\t\t\t9 % 4 = ";
				cin>>ans;
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
		void statistics()
		{
			cout<<"\t___________________________________________________________"<<endl;
			cout<<"\t|                                                         |"<<endl;
			cout<<"\t|                                                         |"<<endl;
			cout<<"\t|                                                         |"<<endl;
			cout<<"\t|--------------------Current STATISTICS-------------------"<<"|"<<endl;
			cout<<"\t|Difficulty Level                        : "<<difficulty<<"\t\t  |"<<endl;
			cout<<"\t|Total questions                         : "<<number_of_questions<<"\t\t  |"<<endl;
			cout<<"\t|Right answers                           : "<<number_of_right_questions<<"\t\t  |"<<endl;
			cout<<"\t|Wrong answers                           : "<<number_of_wrong_questions<<"\t\t  |"<<endl;
			cout<<"\t|Target                                  : "<<target<<" questions"<<"\t  |"<<endl;
			cout<<"\t|Target completed                        : "<<target_completed<<"\t\t  |"<<endl;
			cout<<"\t|Right answers remain to complete target : "<<target-number_of_right_questions<<"\t\t  |"<<endl;
			cout<<"\t|Chances Used                            : "<<number_of_wrong_questions<<"\t\t  |"<<endl;
			cout<<"\t|Chances Left                            : "<<chances-number_of_wrong_questions<<"\t\t  |"<<endl;
			cout<<"\t|Total hints                             : "<<total_hints<<"\t\t  |"<<endl;
			cout<<"\t|Hints Left                              : "<<total_hints-hints_used<<"\t\t  |"<<endl;
			cout<<"\t|Hints used                              : "<<hints_used<<"\t\t  |"<<endl;
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
			cout<<"\t\t\tTraget Completed                  : "<<target_completed<<endl;
			cout<<"\t\t\t------------------------------------"<<endl;
			cout<<"\t\t\tTotal questions                   : "<<number_of_questions<<endl;
			cout<<"\t\t\tRight answers                     : "<<number_of_right_questions<<endl;
			cout<<"\t\t\tWrong answers                     : "<<number_of_wrong_questions<<endl;
			cout<<"\t\t\t------------------------------------"<<endl;
			cout<<"\t\t\tTotal addition questions          : "<<addition_questions<<endl;
			cout<<"\t\t\tRight addition answers            : "<<right_addition_questions<<endl;
			cout<<"\t\t\tWrong addition answers            : "<<wrong_addition_questions<<endl;
			cout<<"\t\t\t------------------------------------"<<endl;
			cout<<"\t\t\tTotal subtraction questions       : "<<subtraction_questions<<endl;
			cout<<"\t\t\tRight subtraction answers         : "<<right_subtraction_questions<<endl;
			cout<<"\t\t\tWrong subtraction answers         : "<<wrong_subtraction_questions<<endl;
			cout<<"\t\t\t------------------------------------"<<endl;
			cout<<"\t\t\tTotal multiplication questions    : "<<multiplication_questions<<endl;
			cout<<"\t\t\tRight multiplication answers      : "<<right_multiplication_questions<<endl;
			cout<<"\t\t\tWrong multiplication answers      : "<<wrong_multiplication_questions<<endl;
			cout<<"\t\t\t------------------------------------"<<endl;
			cout<<"\t\t\tTotal division questions          : "<<division_questions<<endl;
			cout<<"\t\t\tRight division answers            : "<<right_division_questions<<endl;
			cout<<"\t\t\tWrong division answers            : "<<wrong_division_questions<<endl;
			cout<<"\t\t\t------------------------------------"<<endl;	
			cout<<"\t\t\tTotal remainder questions         : "<<remainder_questions<<endl;
			cout<<"\t\t\tRight remainder answers           : "<<right_remainder_questions<<endl;
			cout<<"\t\t\tWrong remainder answers           : "<<wrong_remainder_questions<<endl;
			cout<<"\t\t\t------------------------------------"<<endl;
		}
		void RESULTS()
		{
			cls;
			cout<<"\t\t\t---------------FINAL RESULTS---------------"<<endl;
			cout<<"\t\t\t-------------------------------------------"<<endl;
			cout<<"\t\t\tGames played       : "<<total_games<<endl;
			cout<<"\t\t\tGames won          : "<<games_won<<endl;
			cout<<"\t\t\tGames lost         : "<<games_lost<<endl;
			cout<<"\t\t\t-------------------------------------------"<<endl;
			cout<<"\n\n\n\t\t\t\t\t";
			pause;
			cls;		
			exit(1);
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
			switch(choice=getch())
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
			cout<<"\t\t_______________________________________________________"<<endl;
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
			switch(choice=getch())
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
					reset();
					select_level();
					game_play();
					break;
				case 'M':
				case 'm':
					bell();
					reset();
					start_game();
					break;
				case 'H':
				case 'h':
					bell();
					cls;
					statistics();
					hint();
					hints_used++;
					break;					
				default:
					bell();
					game_menu();
			}												
		}
		void hint()
		{
			cout<<"\n\n\n";
			if(hints_used==total_hints)
			{
				cout<<"\t----------------------------------------------------------"<<endl;
				cout<<"\n\n\t\t\t\tYou are out of hints"<<endl;
				cout<<"\t----------------------------------------------------------"<<endl;
			}
			else
			{
				cout<<"\t----------------------------------------------------------"<<endl;
				cout<<"\n\n\t\t\tHint : "<<right_ans<<endl;	
				cout<<"\t----------------------------------------------------------"<<endl;
			}
			continue_game();
		}
		void continue_game()
		{
			switch(op)
			{
				case 0:
					oper='+';
					break;
				case 1:
					oper='-';
					break;
				case 2:
					oper='*';
					break;
				case 3:
					oper='/';
					break;
				case 4:
					oper='%';
					break;
			}
			cout<<"\n\n\n";
			cout<<"\t----------------------------------------------------------"<<endl;
			cout<<"\n\t\t\t"<<right<<setw(space)<<num1<<" "<<oper<<" "<<left<<setw(space)<<num2<<right<<setw(space)<<" = ";
			cin>>ans;
			exit_game();			
			cout<<"\t----------------------------------------------------------"<<endl;
		}		
		void reset()
		{
			number_of_questions=0;
			number_of_wrong_questions=0;
			number_of_right_questions=0;
			addition_questions=0;
			subtraction_questions=0;
			multiplication_questions=0;
			division_questions=0;
			remainder_questions=0;
			wrong_addition_questions=0;
			wrong_subtraction_questions=0;
			wrong_multiplication_questions=0;
			wrong_division_questions=0;
			wrong_remainder_questions=0;
			right_addition_questions=0;
			right_subtraction_questions=0;
			right_multiplication_questions=0;
			right_division_questions=0;
			right_remainder_questions=0;
			hints_used=0;
			chances_left = true;
			target_uncompleted = true;
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
	private:
		int num1,num2,op;
		int number_of_questions=0,number_of_wrong_questions=0,number_of_right_questions=0;
		int addition_questions=0,right_addition_questions=0,wrong_addition_questions=0;
		int subtraction_questions=0,right_subtraction_questions=0,wrong_subtraction_questions=0;
		int multiplication_questions=0,right_multiplication_questions=0,wrong_multiplication_questions=0;
		int division_questions=0,right_division_questions=0,wrong_division_questions=0;
		int remainder_questions=0,right_remainder_questions=0,wrong_remainder_questions=0;
		int num1_limit,num2_limit;
		int total_games=0,games_won=0,games_lost=0;
		int target,chances;
		int total_hints,hints_used=0;		
		const int space=3;
		float ans,right_ans;
		bool chances_left = true,target_uncompleted = true;
		char choice,difficulty_level,oper;
		string result,target_completed,difficulty;
};

int main()
{
	Game game;
	game.start_game();
	return 0;
}
