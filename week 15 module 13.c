#include <stdio.h>

void problem1();
float getAverage(float arr[], float arrSize);
void problem2();
void problem3();

int main(void) {
  //problem1();
  //problem2();
  problem3();
  return 0;
}

void problem1() {
  /*
  Write a program that uses a typdef statement to create a new type based off of a
  float primitive type. Call your new type “Score”. Declare an integer to determine the
  size of your array. Inside your main program, create a variable array of type Score.
  Prompt the user for the number of grades to enter into the array. Get the users input
  and store it into the array. Create a function that returns the average as a float,
  averaging the numbers in the array. HINT: you must know the number of items in
  the new function.
  */

  typedef float Score;
  int arraySize;


  printf("Enter the number of grades: ");
  scanf("%d", &arraySize);
  Score grades[arraySize];

  for (int i = 0 ; i < arraySize ; i++) {
    printf("Enter in %d element: ", i);
    scanf("%f", &grades[i]);
  }

  printf("The average of the grades is: %.2f\n", getAverage(grades, (float)arraySize));







  return;
}

float getAverage(float arr[], float arrSize) {
  
  float sum = 0;

  for (int i = 0 ; i < arrSize ; i++) {
    sum += arr[i];
  }


  return (sum / arrSize);
}

void problem2() {
  /*
  Write a program that declares a structure called Name and inside the structure
  create a data member of an array of characters 80 characters in size. Now declare a
  second struct called Friend. Inside Friend declare two members of type Name. 
  
  These variables will hold a first name in the first member and a last name in the second
  member. Name them appropriately. 
  Add a third member of type integer to hold the age of a person. 
  Compile your code and ensure your syntax is correct before proceeding.

  Next in main, declare a variable of type Friend, name it what you will. Now prompt
  the user to enter in a first name, then last name and an age. using fscanf() or scanf()
  read in the users input and store it in your new variables member for the first name.
  Now print a personalized greeting to the user. “Hello <first name>, <last name> you
  are <age> years old.” Newline.
  Did it work?
  */

  struct Name {
    char name[80];
  };
  struct Friend {
    struct Name firstName;
    struct Name secondName;
    int age;
  };

  struct Friend friend1;

  printf("Please enter the first name: ");
  scanf("%s", friend1.firstName.name);
  printf("Please enter the second name: ");
  scanf("%s", friend1.secondName.name);
  printf("Please enter the age: ");
  scanf("%d", &friend1.age);

  printf("Hello %s, %s you\'re %d years old\n", friend1.firstName.name, friend1.secondName.name, friend1.age);

  return;
}

void problem3() {

  /*
  Using your program from problem 2, to your local declarations in main, add an
  integer variable to hold the number of friends you want to store. 

  Now comment out the struct variable you have been using 
  and declare a variable length array of Friends, using your new integer variable to determine the size of the array. 
  In your local statements, comment out your existing code, leaving it as a reference to refer to. 
  
  Prompt the user to determine how many friends they want to enter into the program. 
  
  Create a for loop that will now prompt the user to enter in the friends details into the array of friends. 
  
  Construct a second loop that will print the detail back out to resemble the screen shot below.
  */

  int numOfFriends;

  
  struct Name {
    char name[80];
  };
  struct Friend {
    struct Name firstName;
    struct Name secondName;
    int age;
  };

  printf("Enter the number of friends: ");
  scanf("%d", &numOfFriends);

  struct Friend friends[numOfFriends];

  for (int i = 0 ; i < numOfFriends ; i++) {
    printf("Please enter the first name of the %d friend: ", i+1);
    scanf("%s", friends[i].firstName.name);
    printf("Please enter the second name of the %d friend: ", i+1);
    scanf("%s", friends[i].secondName.name);
    printf("Please enter the age of the %d friend: ", i+1);
    scanf("%d", &friends[i].age);
  }

  for (int i = 0 ; i < numOfFriends ; i++) {
    printf("Hello %s, %s you\'re %d years old\n", friends[i].firstName.name, friends[i].secondName.name, friends[i].age);
  }

  return;
}
