#include "pch.h"
#include "Calculator.h"


int Calculator::Add(char* expression)
{
// declare vars
    std::vector<char *> correct_delims = { ",","\n" };

    char *spec_delim_start = "//";
    char* spec_delim_end = "\n";

    std::vector<char*> args;

    char* cur_tok = expression;

    int wait_next_arg = -1;

    int in_spec_delim = 0;

    char* new_delim = NULL;

// test 1
    if ((expression == NULL) ||
       (strlen(expression)==0)) return errEmpty;


// parser
   

    while (1)
    {

        // check special delim
        if (strstr(cur_tok, spec_delim_start) == cur_tok)
        {
            cur_tok += strlen(spec_delim_start);
            in_spec_delim = 1;
        }

        // in special delim
        if (in_spec_delim)
        {

            if (strstr(cur_tok, spec_delim_end) == cur_tok) // found end
            {
                if (new_delim == NULL) return errEnclosedDelim; // uncorrctr //\n - not found real delim
                char tmp_str[100];
                memset(tmp_str, 0, 100);
                strncpy(tmp_str, new_delim, cur_tok - new_delim);
                correct_delims.push_back(tmp_str);
                new_delim = NULL;
                in_spec_delim = 0;
                cur_tok++;
                continue;
            }

            if (new_delim == NULL) new_delim = cur_tok;

            cur_tok++;

            if (*cur_tok == 0)
            {
                // end string incorect
                return errEnclosedDelim;
            }

            continue;
        }
        

        if( isdigit(*cur_tok)) // while digit
        {
            if (args.size() < wait_next_arg )
                args.push_back(cur_tok);

            // first time
            if (wait_next_arg == -1) wait_next_arg = 1;

            cur_tok++; // go next
        }
        else
        {
            if (*cur_tok == 0) //end string
            {
                // wait for next value but nothing
                if (args.size()<wait_next_arg)
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
                    wait_next_arg++; // wait next arg
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
