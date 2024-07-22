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

  if(testMode == 2)
      {
        std::cout << "Your Score Is: " << score << " out of " << numQuestions << "\n";
      }    

      score = 0;

      std::cout << "Would you like to keep playing? (1 for yes, 2 for no)\n";
      std::cin >> isPlaying; 

      if(isPlaying == 1)
      {
        validGrade = false;
      }
    }
}


void questionGeneration()
{
  switch(grade)
    {
      case 1:
        firstNumber = rand() % 25 + 12;
        secondNumber = rand() % firstNumber + 1;
        break;
      case 2:
        firstNumber = rand() % 50 + 25;
        secondNumber = rand() % firstNumber + 1;
        break;
      case 3:
        if(operatorChoice == 1 || operatorChoice == 2)
        {
          firstNumber = 250 + (rand() % 500);
          secondNumber = 1 + (rand() % firstNumber);
        }
        else if(operatorChoice == 3)
        {
          firstNumber =  1 + (rand() % 7);
          secondNumber = 1 + (rand() % 7);
        }
        else if(operatorChoice == 4)
        {
          operatorChoice = 3;
          firstNumber =  1 + (rand() % 7);
          secondNumber = 1 + (rand() % 7);
        }
        break;
