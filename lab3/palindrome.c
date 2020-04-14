/* File: palindrome.c
 *  ENSF 337
 *  Exercise E - Lab 3
 *  Abstract: The program receives a string (one or more words) and indicates
 *  if the string is a palindrome or not. Plaindrome is a phrase that spells the
 *  same from both ends
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define SIZE 100


/* function prototypes*/
int is_palindrome (const char *str);
/* REQUIRES: str is pointer to a valid C string.
 * PROMISES: the return value is 1 if the string a is palindrome.*/


void strip_out(char *str);
/* REQUIRES: str points to a valid C string terminated with '\0'.
 * PROMISES: strips out any non-alphanumerical characters in str*/

int main(void)
{
    int p =0;
    char str[SIZE], temp[SIZE];
    
    fgets(str, SIZE, stdin);
    
    /* Remove end-of-line character if there is one in str.*/
    if (str[strlen(str) - 1] == '\n')
        str[strlen(str) - 1] = '\0';
    
    strcpy(temp,str);
    
    /* This loop is infinite if the string "done" never appears in the
     * input.  That's a bit dangerous, but OK in a test harness where
     * the programmer is controlling the input. */
    
    while(strcmp(str, "done") !=0) /* Keep looping unless str matches "done". */
    {
        
#if 1
        strip_out(str);
        
        p = is_palindrome(str);
#endif
        
        if(!p)
            printf("\n \"%s\" is not a palindrome.", temp);
        else
            printf("\n \"%s\" is a palindrome.", temp);
                    
        fgets(str, SIZE, stdin);
        
        /* Remove end-of-line character if there is one in str.*/
        if(str[strlen(str) - 1] == '\n')
            str[strlen(str) - 1]= '\0';
        strcpy(temp, str);
    }
    
    return 0;
}

void strip_out(char *str)
{
        int i;
        int index = 0;

        for(i = 0; str[i]; i++)
        {
            if(isupper(str[i]) == 1) //if str[i] is capital
            {
                str[i] = tolower(str[i]); //make into lowercase
            }

            if(isalnum(str[i]) != 0) //if str[i] is not alphanumeric
            {
                str[index++] = str[i]; //move array
            }

            if(isupper(str[i]) == 1) //if str[i] is capital
            {
                str[i] = tolower(str[i]); //make into lowercase
            }
        }
        str[index] = '\0';
}

int is_palindrome (const char *str)
{
    int length = strlen(str);
    int half;

    if(length % 2 == 1)
    {
        half = (length-1)/2;
    }
    else
    {
        half = (length/2);
    }

    for(int i = 0; i <= half; i++)
    {
        if(str[i] != str[length-1-i])
            return 0;   
    }
    return 1;
}



