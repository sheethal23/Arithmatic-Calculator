
#include "prog7.h"
int main()
{
	stack<double> S;					// Initialization of Stack S 
	string token;
	while(getline(cin, token))			        // Read tokens till EOF 
	{
		process_token(token, S);		        // Process the read tokens 
	}
	return(0);
}

/************************************************************************************
  * function           : bool isValidOperator(const char& c)    *
  * input(arguments}   : c Operator recieved as input    	*
  * output             : True or false             		*
  * Description        : Returns true if c is either +,-,*,/	*
*************************************************************************************/ 
bool isValidOperator(const char& c)
{
	switch(c)
	{
		case '+':
		case '-':
		case '*':
		case '/':	return(true);		       //  Any valid operators returns true
	}
	return(false);
}

/************************************************************************************
  * function           : void emptyStack(stack<double>& S)	   	*	
  * input(arguments}   : S Stack					*
  * output             : void						*
  * Description        : Pops up all stack S elements to make it empty	*
*************************************************************************************/ 
void emptyStack(stack<double>& S)
{
	bool stack_status = false;
	stack_status = S.empty();	
	while(false == stack_status)			     // Checking Stack status till it becomes empty 
	{
		S.pop();
		stack_status = S.empty();	
	}
}

/************************************************************************************
  * function           : void printResult(const stack<double>& S)	*	
  * input(arguments}   : S Stack					*
  * output             : void						*
  * Description        : Prints the result on stack			*
*************************************************************************************/ 
void printResult(const stack<double>& S)
{
	bool stack_status = false;
	stack_status = S.empty();
	if(stack_status)							// Check stack status if its empty
	{
		cerr<<"error : stack is empty"<<endl;
	}
	else
	{
		cout<<setw(10)<<fixed<<setprecision(2)<<S.top()<<endl;		// Prints stack with precision up to 2 
	}
}

/************************************************************************************
  * function           : double popStack(stack<double>& S)		*	
  * input(arguments}   : S Stack					*
  * output             : Stack top element returned			*
  * Description        : Pops the stack and returns the top element	*
*************************************************************************************/ 
double popStack(stack<double>& S)
{
	double stack_top = 0;
	bool stack_status = false;
	stack_status = S.empty();
	
	if(stack_status)						// Check stack status if its empty 
	{
		cerr<<"error : stack is empty"<<endl;
	}
	else
	{
		stack_top = S.top();				        // Reads stack top value 
		S.pop();					        // Pops top element from the stack 
	}
	return(stack_top);
}

/********************************************************************************************************
  * function           : double operation(const char& c, const double& x, const double& y)		*	
  * input(arguments}   : c Operator, x&y - Double values on which operator c is to be applied		*
  * output             : result after applying operator on x and y					*
  * Description        : This function returns value after applying operator c on double values x and y	*
*********************************************************************************************************/ 
double operation(const char& c, const double& x, const double& y)
{
	if(c == '+')	return(x+y);
	if(c == '-')	return(x-y);
	if(c == '*')	return(x*y);                        // Defining operator and returns appropriate value 
	if(c == '/')	return(x/y);
	return(0);
}

/********************************************************************************************************
  * function           : void process_token(const string& token, stack<double>& S)	*	
  * input(arguments}   : token String token, S - Stack					*
  * output             : Void								*
  * Description        : Processes individual tokens for result			        *
*********************************************************************************************************/ 
void process_token(const string& token, stack<double>& S)
{
	istringstream iss(token);                                        //Token is copied into String iss
	string individual_tokens;
	bool floatPointFlag = false;
	char c;
	while(iss>>individual_tokens)
	{
		for(unsigned i=0;i<individual_tokens.length();i++)
		{
			c = individual_tokens[i];
			floatPointFlag = floatPoint(c, individual_tokens, i);
			if(c == '=')
			{
				printResult(S);
			}
			else if(c == 'c')
			{
				emptyStack(S);
			}
			else if((isdigit(c)) || (unarySign(c, individual_tokens, i)) || (floatPointFlag))
			{
				i++;
				S.push(getNumber(c, individual_tokens, i, floatPointFlag));
			}
			else if(isValidOperator(c))
			{
				S.push(operation(c, popStack(S), popStack(S))); 
			}
			else
			{
				cerr<<"error : " <<"character "<<"'"<<c<<"'"<<" is invalid"<<endl;
			}
		}
	}
}

/********************************************************************************************************
  * function           : bool unarySign(const char& c, const string& token, const unsigned& i)	*
  * input(arguments}   : c - Individual char token, token String token, i - Position/Index	*
  * output             : True/False								*
  * Description        : True if current symbol is unary operator/not				*
*********************************************************************************************************/ 
bool unarySign(const char& c, const string& token, const unsigned& i)
{
	
	if((c == '+') || (c == '-')) 
	{
		if((i < token.length()-1) && ((isdigit(token.at(i+1))) || (token.at(i+1) == '.')))
		{
			return true;
		}
	}
        return false;
}

/********************************************************************************************************
  * function           : bool floatPoint(const char& c, const string& token, const unsigned& i)	*
  * input(arguments}   : c - Individual char token, token String token, i - Position/Index	*
  * output             : True/False								*
  * Description        : True if current symbol is valid float point or not			*
*********************************************************************************************************/ 
bool floatPoint(const char& c, const string& token, const unsigned& i)
{
	if(c == '.') 
	{
		if((i < token.length()-1) && (isdigit(token.at(i+1))))
		{
			return true;
		}
	}
	return false;
}

/****************************************************************************************************************************************
  * function           : double getNumber(const char& c, const string& token, unsigned& i,  const bool& floatPointFlag)			*
  * input(arguments}   : c - Individual char token, token String token, i - Position/Index, floatPointFlag - Float point true/false	*
  * output             : Double number after processing the tokens									*
  * Description        : Returns double number after processing the tokens								*
*****************************************************************************************************************************************/ 
double getNumber(const char& c, const string& token, unsigned& i,  const bool& floatPointFlag)
{
	int floats = 0;
	unsigned j = 0;
	unsigned index = 0;
	char word[token.length()];
	memset(word, 0, token.length());
	word[index++] = c;
	if(floatPointFlag == true)
	{
		floats++;
	}
	for(j = i;j<token.length();j++)
	{
		if((token[j] == '.'))
		{
			if(false == floatPoint(token[j], token, j))	
			{
				floats = INVALID_FLOAT;
				break;
			}
			else
			{
				floats++;
			}
		}
		else if(false == isdigit(token[j]))	break;
	}
	if(floats >= INVALID_FLOAT)
	{
		cerr<<"error : number "<<"'"<<token<<"'"<<" is invalid"<<endl;
		return(0);
	}
	else
	{
		for(unsigned int x=i;x<=j;x++)	word[index++] = token[x];
		word[index] = '\0';
		i = j-1;
		string str(word);
		return(stringToDouble(str));
	}
}

/********************************************************************************
  * function           : double stringToDouble(string& str)			*
  * input(arguments}   : str - Input string of double number			*
  * output             : Double number after processing the string		*
  * Description        : Returns double number after processing the string	*
*********************************************************************************/ 
double stringToDouble(string& str)
{
	double d=stod(str);
	return(d);
}