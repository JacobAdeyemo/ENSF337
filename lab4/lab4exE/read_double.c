/* read_double.c
 * ENSF 337 Fall 2019 Lab 4 Exercise  E
 *
 * Author:   Jay Chuang 30062093
 */

#include "read_input.h"

int read_real(char* digits, int n, double * num);
int is_valid_double(const char* digits);
double convert_to_double(const char *digits);

int read_real(char* digits, int n, double * num)
{
  if(get_string(digits, n)== EOF)
    return EOF;

  if(is_valid_double(digits)){
    if(digits[0] == '-')
      *num = -convert_to_double(digits + 1);
    else if(digits[0] == '+') 
      *num = convert_to_double(digits + 1);
    else
      *num = convert_to_double(digits);
    return 1;
  }

  return 0;
}

int is_valid_double(const char* digits)
{
  int valid = 1;
  int i;
  int count = 0;

  /* i = index where first digit should be */
  if(digits[0] == '+' || digits[0] == '-')
    i = 1;
  else
    i = 0;

  /* Must have at least one digit, and no non-digits. */
  if (digits[i] == '\0')
    valid = 0;
  else
    while (valid && (digits[i] != '\0')) {
      if((digits[i] < '0' ||  digits[i] > '9') && digits[i] != '.')
        valid = 0;
      if(digits[i] == '.')
        count++;
      i++;
    }
  if(count>1)
    valid = 0;
  return valid;
}

double convert_to_double(const char *digits)
{
  double sum = 0;
  double decimalsum = 0;
  int i = 0;
  int n = 1;
  while(digits[i] != '\0' && digits[i] != '.') {
    sum = 10 * sum + (digits[i] - '0');
    i++;
  }
  i+=1;
  while(digits[i] != '\0') {
      decimalsum = 10 * decimalsum + (digits[i] - '0');
      i++;
      n*=10;
  }
  decimalsum = decimalsum / n;
  sum = sum + decimalsum;
  return sum;
}