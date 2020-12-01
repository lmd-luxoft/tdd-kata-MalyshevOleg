#include "pch.h"
#include "Calculator.h"


int Calculator::Add(char* expression)
{
// declare vars
    std::vector<char *> correct_delims = { ",","\n" };

    std::vector<char*> args;

    char* cur_tok = expression;

    int wait_next = -1;

// test 1
    if ((expression == NULL) ||
       (strlen(expression)==0)) return errEmpty;


// parser
   

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
                int is_ok_delim = 0;
                for (const auto& element : correct_delims)
                {
                    if (strstr(cur_tok, element) == cur_tok)
                    {
                        is_ok_delim = 1;
                        break;
                    }
                }

                if (is_ok_delim) // is delim OK?s
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
