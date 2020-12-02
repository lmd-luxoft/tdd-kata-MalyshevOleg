#include "pch.h"
#include "Calculator.h"




int Calculator::Add(char* expression_orig)
{

    int state = stateNormal;


// declare vars
    std::vector<char *> correct_delims = { ",","\n" };


    std::vector<char*> args;


    int wait_next_arg = -INT_MAX;

    int in_spec_delim = 0;

// test 1
    if ((expression_orig == NULL) ||
       (strlen(expression_orig)==0)) return errEmpty;

    char* expression = new char[strlen(expression_orig) + 1]();
    strcpy(expression, expression_orig);

    char* cur_tok = expression;

// parser
   

    while (1)
    {

        // check special delim
        if (strstr(cur_tok, spec_delim_start) == cur_tok) {
            int res = ParseSpecialDelimeters(&cur_tok, correct_delims); if (res) { delete expression; return res; }
//            wait_next_arg++;
        }
        

        if( isdigit(*cur_tok) ||  (*cur_tok == '-' )) // while digit
        {

            if ((int)args.size() < wait_next_arg || (args.size() == 0))
            {
                args.push_back(cur_tok);
            }
            else
            {
                if (*cur_tok == '-')  { delete [] expression; return Calculator::errNotDigitArgs; }
                // disallow '-' inside Numer
            }
            // first time
            if (wait_next_arg < 0) wait_next_arg = 1;

            cur_tok++; // go next
        }
        else
        {
            if (*cur_tok == 0) //end string
            {
                // wait for next value but nothing
                if ((int)args.size() < wait_next_arg)
                {
                    delete [] expression;
                    return errUnclosedDelim;
                }

                //if(args[wait_next] == NULL)
                 //   return errNotDigitArgs;


                int res = 0;

                for (const auto& element : args)
                {
                    if (atoi(element) < 0)
                    {
                        if (message == NULL)
                        {
                            message = new char[2048]();
                            strcpy(message, "Negatives not allowed:");
                        }
                        strcat(message, element);
                        strcat(message, "|");
                    }
                    if (atoi(element)<=1000)
                        res += atoi(element);
                }
                if (message)
                {
                    delete [] expression;
                    return Calculator::errException;
                }
                else
                {
                    delete [] expression;
                    return res;
                }
            } // not end string
            else
            {
                int is_ok_delim = 0;
                int cur_tok_len = 0;
                for (const auto& element : correct_delims)
                {
                    if (strstr(cur_tok, element) == cur_tok)
                    {
                        is_ok_delim = 1;
                        cur_tok_len = strlen(element);
                        break;
                    }
                }

                if (is_ok_delim) // is delim OK?s
                {
                    wait_next_arg++; // wait next arg
                    // Dirty HACK!!!
                    *cur_tok = 0;
                    // Dirty Hack!!!
                    cur_tok+= cur_tok_len; // go next
                }
                else
                {
                    delete [] expression;
                    if (args.size() == NULL) return errNotDigitArgs;
                    else                return errIncorrectDelim;
                }
            }
        }
    }
}

int Calculator::ParseSpecialDelimeters(char** cur_token, std::vector<char*>& correct_delims)
{
    char* new_delim = NULL;
    int in_parse_delim2 = 0;
    int is_added = 0;

    if (cur_token == NULL) { return Calculator::errUnclosedDelim; }
    if (*cur_token == NULL) { return Calculator::errUnclosedDelim; }

    (*cur_token) += strlen(spec_delim_start);

    while (strstr((*cur_token), spec_delim_end) != (*cur_token)) // found end
    {
        if (*(*cur_token) == 0) return Calculator::errUnclosedDelim;
        if (*(*cur_token) == '[') { 
            if (in_parse_delim2 == 1)
            {
                return Calculator::errUnclosedDelim;
            }
            else
            {
                in_parse_delim2= 1;
                (*cur_token)++;
                continue;
            }
        }
        
        if (*(*cur_token) == ']') {
            if (in_parse_delim2 == 0)
            {
                return Calculator::errUnclosedDelim;
            }
            else
            {
                in_parse_delim2=0;
                if (new_delim == NULL) return Calculator::errUnclosedDelim;
                char* tmp_str = new char[((*cur_token) - new_delim) + 1]();
                strncpy(tmp_str, new_delim, (*cur_token) - new_delim);
                (*cur_token)++;
                is_added++;
                correct_delims.push_back(tmp_str);
                continue;
            }
        }// end if ((*(*cur_token) == ']') {
        if (in_parse_delim2 == 0) return errIncorrectDelim;
        if ((new_delim == NULL) && (in_parse_delim2==1)) new_delim = (*cur_token);
        (*cur_token)++;
    }// end while
    return (is_added>0)?0:errIncorrectDelim; // All Ok!

}
