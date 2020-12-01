#include "pch.h"
#include "Calculator.h"


int Calculator::Add(char* expression)
{
    if (strlen(expression)==0) return errEmpty;

    std::vector<char *> args;

    char* cur_tok = expression;

        // parser

    int wait_next = -1;
    

    while (1)
    {
        if( isdigit(*cur_tok)) // while digit
        {
            if (args.size() < wait_next )
                args.push_back(cur_tok);

            // first time
            if (wait_next == -1) wait_next = 1;

            cur_tok++; // go next
        }
        else
        {
            if (*cur_tok == 0) //end string
            {
                // wait for next value but nothing
                if (args.size()<wait_next)
                    return errEnclosedDelim;

                //if(args[wait_next] == NULL)
                 //   return errNotDigitArgs;


                int res = 0;

                for (const auto& element : args)
                {
                    res += atoi(element);
                }
                return res;
            } // not end string
            else
            {
                if (*cur_tok == ',') // is delim 
                {
                    wait_next++; // wait next arg
                    cur_tok++; // go next
                }
                else
                {
                    if (args.size() == NULL) return errNotDigitArgs;
                    else                return errIncorrectDelim;
                }
            }
        }
    }
}
