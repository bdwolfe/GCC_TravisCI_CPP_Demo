
#include "balanced.h"

// Returns true if the parenthesis,
//  square brackets, and curly braces
//  in text are balanced
bool isBalanced(const std::string &text){

  char c;
  char fromStack;
  std::stack<char> unmatched;

  for(int i=0; i<text.size(); i++){
    c = text[i];
    switch(c){
    case '[':
    case '{':
    case '(':
      unmatched.push(c);
      break;
    case ']':
      if(unmatched.empty() || unmatched.top() != '['){
        return false;
      }
      unmatched.pop();
      break;
    case '}':
      if(unmatched.empty() || unmatched.top() != '{'){
        return false;
      }
      unmatched.pop();
      break;
    case ')':
      if(unmatched.empty() || unmatched.top() != '('){
        return false;
      }
      unmatched.pop();
      break;

    }
  }
  
  // NOTE: the if block here fixes the failing test in the starter code
  if(!unmatched.empty()){
    return false;
  }
  return true;
}
