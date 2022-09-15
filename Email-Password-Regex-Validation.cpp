#include<iostream>
#include<regex>
#include<cstring>
using namespace std ; 
bool isValidDomain(string str)
{
  const regex pattern("^(?!-)[A-Za-z0-9-]+([\\-\\.]{1}[a-z0-9]+)*\\.[A-Za-z]{2,6}$");
  if (str.empty())
  {
    return false;
  }
  if(regex_match(str, pattern))
  {
    return true;
  }
  else
  {
    return false;
  }
}
int main()
{
    string password ; 

    cout<<"Enter Your password"<<endl; 
    cin>>password ;

    bool upper_case = false , number_case = false , special_char = false;

    regex upper_case_expression{ "[A-Z]+" };
    regex number_expression{ "[0-9]+" };
    regex special_char_expression{ "[@!?]+"};
    regex alphabet{"/^[A-Za-z]+$/"} ; 

    upper_case = regex_search(password, upper_case_expression); 
    number_case = regex_search(password, number_expression);
    special_char = regex_search(password, special_char_expression);
    
    if(password.length()>5 && password.length()<11 && upper_case ==true  && number_case == true && special_char == true)
    {
        cout<<"Validation test passed"<<endl ; 
    }
    else
    {
        cout<<"Failed"<<endl;
    }

    /*
    PART B
    */
    string email ; 
    cout<<"Enter email"<<endl ; 
    cin>>email ; 

    int n = email.length() ; 

    char email1[n+1] ;
    strcpy(email1, email.c_str());


    char * ptr , * ptr1 ; 
    
    ptr = strtok(email1,"@");
    
    ptr1 = ptr ; 

    ptr = strtok(nullptr,"@");
    
    cout<<ptr1[0]<<endl ; 
    
    int length = strlen(ptr1) ; 

    cout<<ptr1[length -1]<<endl ; 

    bool c1 = false , c2 = false ; 

    string str1 , str2 ; 
    str1.append(1,ptr1[0]);
    str2.append(1,ptr1[length-1]);
    c1 = regex_search(str1, alphabet); 
    c2 = regex_search(str2,special_char_expression) ; 

    int three_SC ; 
    
    bool consective_SC_check = true ; 
    bool three_SC_check = false ; 

    for (int i = 0; i < length; i++)
    {
        string meow ; 
        meow.append(1,ptr1[i]) ;
        cout<<meow<<endl ; 
        if(regex_search(meow,special_char_expression))
        {
            three_SC ++ ; 
        }
    }
    
    if(three_SC<=3)
    {
        three_SC_check = true ; 
    }

    for (int i = 0; i < length; i++)
    {
        string meow1 ;
        if(regex_search(meow1.append(1,ptr1[i]),special_char_expression) && regex_search(meow1.append(1,ptr1[i+1]),special_char_expression))
        {
            consective_SC_check = false ; 
        }

    }
    

    

    if(isValidDomain(ptr) == true && c1 == true && c2 ==false && consective_SC_check == true && three_SC == true )
    {
        cout<<"Valid Email"<<endl ; 
    }
    else{
        cout<<"invalid Email"<<endl ; 
    }




    return 0 ; 
}
