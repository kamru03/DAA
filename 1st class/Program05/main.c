//  Find the no. of words in a given sentence.

#include <stdio.h>          
int main() {    
                // 1 
                // 1 
char str[200];              // 1 
int i, count = 0;           // 1 
printf("Enter a sentence: "); // 1 
fgets(str, sizeof(str), stdin); // 1 
for (i = 0; str[i] != '\0'; i++) { // n + 1 
if ((str[i] != ' ' && str[i] != '\n') && // n 
(i == 0 || str[i - 1] == ' ')) {    
// n 
count++;              
} 
} 
               //n 
printf("Number of words: %d\n", count); // 1 
return 0; // 1 
}