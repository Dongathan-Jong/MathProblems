#include <iostream>

int grade;
int firstNumber;
int secondNumber;
int operatorChoice;
int divisibleBy;
int answer;
int numQuestions;
int score = 0;
int testMode;
int isPlaying = 1; 
bool validGrade = false;

void operatorGeneration();
void questionGeneration();
void answerCheck();


int main() {

  srand(time(NULL));

  while(isPlaying == 1)
      while(validGrade == false)
        {
          std::cout << "Please select a grade level, 1 - 5\n";
          std::cin >> grade;
    
          std::cout << "How many questions would you like to answer?\n";
          std::cin >> numQuestions;
    
          std::cout << "Enter 1 for practice Mode, enter 2 for Test Mode\n";
          std::cin >> testMode;

          if(grade > 5 || grade < 1) 
          {
            std::cout << "Invalid grade level, please reselect!\n";
          }
          else
          {
            validGrade = true;
          }
        }

  operatorGeneration();
      questionGeneration();

      for(int i = 0; i < numQuestions; i++)
        {
          if(operatorChoice == 1)
          {
            std::cout << firstNumber << " + " << secondNumber << " = ";
            std::cin >> answer;
          }
          else if(operatorChoice == 2)
          {
            std::cout << firstNumber << " - " << secondNumber << " = ";
            std::cin >> answer;
          }
          else if(operatorChoice == 3)
          {
            std::cout << firstNumber << " x " << secondNumber << " = ";
            std::cin >> answer;
          }
          else if(operatorChoice == 4)
          {
            std::cout << firstNumber << " / " << secondNumber << " = ";
            std::cin >> answer;
          }
          answerCheck();

          operatorGeneration();
          questionGeneration();
          
        }
}
