#include <stdio.h>
#define ARRAYSIZE 53


/*
  Every variable is a memory location with an assigned value and every memory location has its address defined.
  
  The memory location can be accessed using ampersand (&) operator, which denotes an address in memory.

  The asterisk is used to designate a variable as a pointer.

  The unary operator * is also used to return the value of the variable located at the address specified by its operand. 

  Pointers are a type of variable which point to a location in computer memory and a variable is a named memory location. Pointers are memory locations that hold a memory location as a value
*/


//Parameters for the function are two int pointer variables.
void swapVariableValues(int *, int *);



int main(void) {

  int a = 1;

  //The asterisk is used to designate a variable as a pointer.
  int *ip = &a; // pointer to an integer. ip is a variable that stores the memory location of variable a. 
  double *dp;   // pointer to a double 
  float  *fp;   // pointer to a float
  char   *ch;   // pointer to a character


  printf("\nThe value stored at the memory location of a is: %d\n\n", a);

  printf("The address of variable a is: %p\n\n", &a);

  printf("The value of the pointer variable ip is: %p\n\n", ip);

  /*
    The value of the ip pointer variable is the address of the a int variable a. So the * operator is used to return the value stored at the address that's stored in the ip pointer variable.
  */
  printf("The value stored at the address that ip has stored is %d\n\n", *ip);



  //----------------------------------------------------------------------------------------------

  int b = 2;
  int c = 3;

  printf("The value of variable b before the function call is: %d\n", b);
  printf("The value of variable c before the function call is: %d\n\n", c);
  swapVariableValues(&b, &c);
  printf("The value of variable b after the function call is: %d\n", b);
  printf("The value of variable c after the function call is: %d\n", c);

  //-----------------------------------------------------------------------------------------------

  return 0;
}



/*
  A function is only passed a value and is only able to return a single value back to the caller using a return statement.

  A solution to this limitation is to use pass by reference. 
  
  Pass by reference - Instead of passing the value stored at a location to a function, the memory address location of that value is passed to the function. 
  
  C is still passing a value to be stored locally in that function, but the value is a memory address and not a variable value. 
  
  Using the memory location, the called function can locate the variable from inside of the function which may reside in another function. With access to the memory of a variable, the contents of a value can be manipulated / changed outside of the scope of the function. 
  
  C only uses pass by value, we simulate pass by reference by passing the address (memory location) of a variable as a value.

*/


void swapVariableValues(int *ptr1, int *ptr2) {

  // Create a temporary variable to store the value of pointer 1. 
  int tmp = *ptr1;

  // Set the value at pointer 1 equal to the value at pointer 2. 
  *ptr1 = *ptr2;

  // Set the value of pointer 2 equal to the value of the temporary variable which was the value at pointer 1. 
  *ptr2 = tmp;

  return;
}

