/*
  Author: Jonathan Dong
  Description: This program is a math algebra practice program to help kids grade 1-5
*/

#include <iostream>

// create variables
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

// initialize functions
void operatorGeneration();
void questionGeneration();
void answerCheck();


/*
  Main Function
  Description: main logic of the program
*/
int main() {

  // initialize the random seed
  srand(time(NULL));

  // infinite loop until user does not want to play
  while(isPlaying == 1)
    {
      // loop until user enters a valid grade
      while(validGrade == false)
        {
          // prompt user for number of answers, practice + test mode, and grade
          std::cout << "Please select a grade level, 1 - 5\n";
          std::cin >> grade;
    
          std::cout << "How many questions would you like to answer?\n";
          std::cin >> numQuestions;
    
          std::cout << "Enter 1 for practice Mode, enter 2 for Test Mode\n";
          std::cin >> testMode;

          // check if grade is valid
          if(grade > 5 || grade < 1) 
          {
            std::cout << "Invalid grade level, please reselect!\n";
          }
          // exit loop if grade is valid
          else
          {
            validGrade = true;
          }
        }
    
      // generate an operator and a question
      operatorGeneration();
      questionGeneration();

      // loop for each question and print out the question
      for(int i = 0; i < numQuestions; i++)
        {
          // addition
          if(operatorChoice == 1)
          {
            std::cout << firstNumber << " + " << secondNumber << " = ";
            std::cin >> answer;
          }
          // subtraction
          else if(operatorChoice == 2)
          {
            std::cout << firstNumber << " - " << secondNumber << " = ";
            std::cin >> answer;
          }
          // multiplication
          else if(operatorChoice == 3)
          {
            std::cout << firstNumber << " x " << secondNumber << " = ";
            std::cin >> answer;
          }
          // division
          else if(operatorChoice == 4)
          {
            std::cout << firstNumber << " / " << secondNumber << " = ";
            std::cin >> answer;
          }
          // check the answer 
          answerCheck();

          // generate new operator and question
          operatorGeneration();
          questionGeneration();
          
        }
      // tell user the score they got

      if(testMode == 2)
      {
        std::cout << "Your Score Is: " << score << " out of " << numQuestions << "\n";
      }    

      // reset score for next round
      score = 0;

      // prompt user if they would like to continue
      std::cout << "Would you like to keep playing? (1 for yes, 2 for no)\n";
      std::cin >> isPlaying; 

      // reset grade value
      if(isPlaying == 1)
      {
        validGrade = false;
      }
    }
}

/*
  questionGeneration Function
  Description: generates the question based on the grade level
*/
void questionGeneration()
{
  // switch case for each grade
  switch(grade)
    {
      case 1:
        // generate numbers based on curriculum
        firstNumber = rand() % 25 + 12;
        secondNumber = rand() % firstNumber + 1;
        break;
      case 2:
        // generate numbers based on curriculum
        firstNumber = rand() % 50 + 25;
        secondNumber = rand() % firstNumber + 1;
        break;
      case 3:
        // generate numbers based on curriculum for addition and subtraction
        if(operatorChoice == 1 || operatorChoice == 2)
        {
          firstNumber = 250 + (rand() % 500);
          secondNumber = 1 + (rand() % firstNumber);
        }
        // generate numbers based on curriculum for multiplication
        else if(operatorChoice == 3)
        {
          firstNumber =  1 + (rand() % 7);
          secondNumber = 1 + (rand() % 7);
        }
        // set operator to multiplication
        else if(operatorChoice == 4)
        {
          operatorChoice = 3;
          firstNumber =  1 + (rand() % 7);
          secondNumber = 1 + (rand() % 7);
        }
        break;
      case 4:
        // generate numbers based on curriculum for addition and subtraction
        if(operatorChoice == 1 || operatorChoice == 2)
        {
          firstNumber = 250 + (rand() % 500);
          secondNumber = 1 + (rand() % firstNumber);
        }
        // generate numbers based on curriculum for multiplication
        else if (operatorChoice == 3)
        {
          firstNumber =  1 + (rand() % 10);
          secondNumber = 1 + (rand() % 10);
        }
        else
        {
          // generate numbers based on curriculum for division
          divisibleBy = 1 + (rand() % 7);
          firstNumber = (1 + (rand() % 10)) * divisibleBy;
          secondNumber = divisibleBy;
        }
        break;
      case 5:
        // generate numbers based on curriculum for addition and subtraction
        if(operatorChoice == 1 || operatorChoice == 2)
          {
            firstNumber = 1000 + (rand() % 2000);
            secondNumber = 1 + (rand() % secondNumber);
          }
        // generate numbers based on curriculum for multiplication
        else if (operatorChoice == 3)
          {
            firstNumber =  1 + (rand() % 20);
            secondNumber = 1 + (rand() % 20);
          }
        // generate numbers based on curriculum for division
        else
          {
            divisibleBy = 5 + (rand() % 15);
            firstNumber = (5 + (rand() % 15)) * divisibleBy * 2;
            secondNumber = divisibleBy * 2;
          }
    }
}

/*
  operatorGeneration Function
  Description: generates the operator based on the grade level
*/
void operatorGeneration()
{
  // generate random number from 1-4
  operatorChoice = 1 + (rand() % 4);

  // if grade is smaller than 3 change division and multiplication
  if(grade < 3 && operatorChoice == 3)
    {
      operatorChoice = 1;
    }
  else if(grade < 3 && operatorChoice == 4)
    {
      operatorChoice = 2;
    }
  // if grade is 3 change division to multiplication
  else if(grade == 3 && operatorChoice == 4)
    {
      operatorChoice = 3;
    }
}
/*
  answerCheck Function
  Description: checks the answer of the user
*/
void answerCheck()
{
  switch(operatorChoice)
    {
      // addition
      case 1:
        // correct answer
        if(answer == firstNumber + secondNumber)
        {
          score++;
          if(testMode == 1)
          {
            std::cout << "Correct!\n";
          }
        }
        // incorrect answer
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
      // subtraction
      case 2:
        // correct answer
        if(answer == firstNumber - secondNumber)
        {
          score++;
          if(testMode == 1)
            {
              std::cout << "Correct!\n";
            }
        }
        // incorrect answer
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
      // multiplication
      case 3:
        // correct answer
        if (answer == firstNumber * secondNumber)
        {
          score++;
          if(testMode == 1)
            {
              std::cout << "Correct!\n";
            }
        }
        // incorrect answer
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
      // division
      case 4:
        // correct answer
        if(answer == firstNumber / secondNumber)
        {
          score++;
          if(testMode == 1)
            {
              std::cout << "Correct!\n";
            }
        }
        // incorrect answer
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
