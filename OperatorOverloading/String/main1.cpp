#include <iostream>
#include "String.hpp"

int main()
{
    String s1;
    std::cout<<"Enter String";
    std::cin>>s1;
    std::cout<<"You Entered: \n"<<s1<<std::endl;

    String s2("World");
    std::cout<<"b ="<<s2<<std::endl;

    String s3 = s2;
    std::cout<<"Copy ctor called\n"<<s3<<std::endl;

    String s4 = std::move(s3);
    std::cout<<"Move ctor called\n"<<s4<<std::endl;

    String s5 = s1 + "" + s2;
    std::cout<<s5<<std::endl;
    
    if(s1 == s2)
    {
        std::cout<<"a = b";
    }
    else
    {
        std::cout<<"a != b"<<std::endl;
    }
    
    if(s5.length() > 0)
    {
        std::cout<<"First character of s5\n"<<s5[0]<<std::endl;
        s5[0] = 'X';
        std::cout<<"After Modifying: "<<s5[0]<<std::endl;
    }

    return 0;

}