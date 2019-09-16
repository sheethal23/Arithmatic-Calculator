
#include<iostream>                      //Predefined header file containing input and output streaming operations
#include <cstring>			//Predefined header file containing functions for dealing with C-style strings
#include<sstream>			//Predefined header file containing string streaming operations
#include<string>			//Predefined header file containing operations used to declare and manipulate strings
#include<stack>				//Predefined header file containing operations to declare and manipulate stacks
#include<iomanip>			//Predefined header file containing operations to manipulate the output

#include "error.h"                      //User defined header file containing error functions
#ifndef H_PROG7
#define H_PROG7
#define INVALID_FLOAT 2

using std::wstring;                     //
using std::string;			//
using std::stack;			//
using std::cin;				//
using std::cerr;			//
using std::endl;			//
using std::cout;			//			Required using statements
using std::setw;			//
using std::fixed;			//
using std::setprecision;	        //
using std::istringstream;	        //
using std::stod;                        //

/*******************************************************************************************************************************
  * function           : void process_token(const string& token, stack<double>& S)		
  * input(arguments}   : token String token, S - Stack					
  * output             : Void								
  * Description        : Processes individual tokens for result			        
********************************************************************************************************************************/ 
void process_token(const string& token, stack<double>& S);

/*******************************************************************************************************************************
  * function           : bool isValidOperator(const char& c)    
  * input(arguments}   : c,Operator recieved as input    	
  * output             : True or false             		
  * Description        : Returns true if c is either +,-,*,/	
********************************************************************************************************************************/ 
bool isValidOperator(const char& c);

/********************************************************************************************************************************
  * function           : void emptyStack(stack<double>& S)				
  * input(arguments}   : S Stack					
  * output             : void						
  * Description        : Pops all stack S elements to make it empty	
*********************************************************************************************************************************/ 
void emptyStack(stack<double>& S);

/********************************************************************************************************************************
  * function           : void printResult(const stack<double>& S)		
  * input(arguments}   : S Stack					
  * output             : void						
  * Description        : Prints result on stack			
*********************************************************************************************************************************/ 
void printResult(const stack<double>& S);

/*********************************************************************************************************************************
  * function           : double popStack(stack<double>& S)			
  * input(arguments}   : S Stack					
  * output             : Stack top element returned			
  * Description        : Pops the stack and returns the top element	
**********************************************************************************************************************************/ 
double popStack(stack<double>& S);

/**********************************************************************************************************************************
  * function           : double operation(const char& c, const double& x, const double& y)			
  * input(arguments}   : c Operator, x&y - Double values on which operator c is to be applied		
  * output             : result after applying operator on x and y					
  * Description        : This function returns value after applying operator c on double values x and y	
***********************************************************************************************************************************/ 
double operation(const char& c, const double& x, const double& y);

/***********************************************************************************************************************************
  * function           : bool unarySign(const char& c, const string& token, const unsigned& i)	
  * input(arguments}   : c - Individual char token, token String token, i - Position/Index	
  * output             : True/False								
  * Description        : True if current symbol is unary operator else false				
***********************************************************************************************************************************/ 
bool unarySign(const char& c, const string& token, const unsigned& i);

/***********************************************************************************************************************************
  * function           : bool floatPoint(const char& c, const string& token, const unsigned& i)	
  * input(arguments}   : c - Individual char token, token String token, i - Position/Index	
  * output             : True/False								
  * Description        : True if current symbol is valid float point else false			
***********************************************************************************************************************************/ 
bool floatPoint(const char& c, const string& token, const unsigned& i);

/**********************************************************************************************************************************
  * function           : double getNumber(const char& c, const string& token, unsigned& i,  const bool& floatPointFlag)
  * input(arguments}   : c - Individual char token, token String token, i - Position/Index, floatPointFlag - Float point true/false
  * output             : Double number after processing the tokens																	*
  * Description        : Returns double number after processing the tokens															*
***********************************************************************************************************************************/ 
double getNumber(const char& c, const string& token, unsigned& i, const bool& floatPointFlag);

/**********************************************************************************************************************************
  * function           : double stringToDouble(string& str)					
  * input(arguments}   : str - Input string of double number				
  * output             : Double number after processing the string			
  * Description        : Returns double number after processing the string	
************************************************************************************************************************************/ 
double stringToDouble(string& str);

#endif
