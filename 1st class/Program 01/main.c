//Reverse a 'n' digit number

#include <stdio.h> 
int main(){ 
int num, s=0; // 1 
printf("Enter a number:"); // 1 
scanf("%d", &num); // 1 
while(num!=0){ // log n(to the base 10) + 1 
int t=num%10; // log n 
s=s*10+t; // log n 
num/=10; // log n  
} 
printf("The reversed number is: %d\n", s); // 1 
return 0; // 1 
}