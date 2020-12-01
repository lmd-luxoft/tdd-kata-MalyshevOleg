#include "pch.h"
#include "Calculator.h"




int Calculator::Add(char* expression)
{

    int state = stateNormal;

// declare vars
    std::vector<char *> correct_delims = { ",","\n" };


    std::vector<char*> args;

    char* cur_tok = expression;

    int wait_next_arg = -INT_MAX;

    int in_spec_delim = 0;

// test 1
    if ((expression == NULL) ||
       (strlen(expression)==0)) return errEmpty;


// parser
   

    while (1)
    {

        // check special delim
        if (strstr(cur_tok, spec_delim_start) == cur_tok) {
            char* new_delim = ParseSpecialDelimeters(&cur_tok);
            if (new_delim == NULL) return errEnclosedDelim; // uncorrctr //\n - not found real delim
            else correct_delims.push_back(new_delim);
            wait_next_arg++;
        }
        

        if( isdigit(*cur_tok)) // while digit
        {
            if ((int)args.size() < wait_next_arg || (args.size()==0))
                args.push_back(cur_tok);

            // first time
            if (wait_next_arg < 0) wait_next_arg = 1;

            cur_tok++; // go next
        }
        else
        {
            if (*cur_tok == 0) //end string
            {
                // wait for next value but nothing
                if ((int)args.size()<wait_next_arg)
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

char* Calculator::ParseSpecialDelimeters(char** cur_token)
{
    char * new_delim = NULL;
    (*cur_token) += strlen(spec_delim_start);

    while (strstr((*cur_token), spec_delim_end) != (*cur_token)) // found end
    {
        // do it once ^[//(a)+\n]
        if (new_delim == NULL) new_delim = (*cur_token);
        (*cur_token)++;
        if (*(*cur_token) == 0) return NULL;
    }

    if (new_delim == NULL) return NULL;
    else
    {
            
            char* tmp_str = new char[((*cur_token) - new_delim) + 1](); 
            strncpy(tmp_str, new_delim, (*cur_token) - new_delim);
            (*cur_token)++;
            return tmp_str;
     }

}
