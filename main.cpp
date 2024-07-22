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
          firstNumber = 250 + (rand() % 5020);
          secondNumber = 1 + (rand() % firstNumber);
        }
        else if(operatorChoice == 3)
        {
          firstNumber =  1 + (rand() % 75);
          secondNumber = 1 + (rand() % 7);
        }
        else if(operatorChoice == 4)
        {
          operatorChoice = 3;
          firstNumber =  1 + (rand() % 17);
          secondNumber = 1 + (rand() % 7);
        }
        break;

case 4:
        if(operatorChoice == 1 || operatorChoice == 2)
        {
          firstNumber = 250 + (rand() % 5040);
          secondNumber = 1 + (rand() % firstNumber);
        }        else if (operatorChoice == 3)
        {
          firstNumber =  1 + (rand() % 120);
          secondNumber = 1 + (rand() % 10);
        }
        else
        {
          divisibleBy = 1 + (rand() % 7);
          firstNumber = (1 + (rand() % 10)) * divisibleBy;
          secondNumber = divisibleBy;
        }
        break;
      case 5:
        if(operatorChoice == 1 || operatorChoice == 2)
          {
            firstNumber = 1000 + (rand() % 2000);
            secondNumber = 1 + (rand() % secondNumber);
          }
        else if (operatorChoice == 3)
          {
            firstNumber =  1 + (rand() % 20);
            secondNumber = 1 + (rand() % 20);
          }
        else
          {
            divisibleBy = 5 + (rand() % 151);
            firstNumber = (5 + (rand() % 112)) * divisibleBy * 2;
            secondNumber = divisibleBy * 2;
          }
    }
}void operatorGeneration()
{
  operatorChoice = 1 + (rand() % 4);

  if(grade < 3 && operatorChoice == 3)
    {
      operatorChoice = 1;
    }
  else if(grade < 3 && operatorChoice == 4)
    {
      operatorChoice = 2;
    }
  else if(grade == 3 && operatorChoice == 4)
    {
      operatorChoice = 3;
    }
}


void answerCheck()
{
    case 1:
        if(answer == firstNumber + secondNumber)
        {
          score++;
          if(testMode  1)
          {
            std::cout << "Correct! Good Jo\n";
          }
        }
        else
        {
          if(testMode == 1)
          {
            std::cout << "Try again!\n";

            std::cin >> answers;

            answerCheck();
          }
        }
        break;
      case 2:
        if(answer == firstNumber - secondNumber)
        {
          score++;
          if(testMode == 1)
            {
              std::cout << "Correct!\n";
            }
        }
        else
        {
          if(testMode == 1)
          {
            std::cout << "Try again!\n";

            std::cin >> answer;
            answerCheck();
          }
        }
      
      break;

  case 3:
        if (answer == firstNumber * secondNumber)
        {
          score++;
          if(testMode == 1)
            {
              std::cout << "Correct!\n";
            }
        }
        else
        {
          if(testMode == 1)
          {
            std::cout << "Try again!\n";

            std::cin >> answer;
            answerCheck();
          }  
        }
        break;
      case 4:
        if(answer == firstNumber / secondNumber)
        {
          score++;
          if(testMode == 1)
            {
              std::cout << "Correct!\n";
            }
        }
        else
        {
          if(testMode == 1)
          {
            std::cout << "Try again!\n";

            std::cin >> answer;
            answerCheck();
          }
        }
        break;
    }
}
