#include "pch.h"
#include "Calculator.h"


int Calculator::Add(char* expression)
{
    if (strlen(expression)==0) return errEmpty;

    char *args[2] = {NULL,NULL};

    char* cur_tok = expression;

        // parser

    int wait_next = 0;
    

    while (1)
    {
        if( isdigit(*cur_tok)) // while digit
        {
            if(args[0] == NULL) args[0] =  cur_tok; // first time assign first
            if ((args[1] == NULL) && (wait_next == 1)) { args[1] = cur_tok; wait_next = 2; }// first time assign second
            cur_tok++; // go next
        }
        else
        {
            if (*cur_tok == 0) //end string
            {
                if (args[1] != NULL) return atoi(args[1]) + atoi(args[0]);
                else
                {
                    if (wait_next == 1) return errEnclosedDelim;
                    if (args[0] != NULL) return atoi(args[0]);
                    else return errNotDigitArgs;
                }
            } // not end string
            else
            {
                if (*cur_tok == ',') // is delim 
                {
                    if (wait_next == 2) return errTooManyArgs;
                    wait_next = 1;
                    cur_tok++; // go next
                }
                else
                {
                    if (args[0] == NULL) return errNotDigitArgs;
                    else                return errIncorrectDelim;
                }
            }
        }
    }

    //enum { errEmpty = -1, errTooManyArgs = -2, errNotDigitArgs = -3, errIncorrectDelim = -4, errEnclosedDelim = -5 };
    //throw 0;
}
