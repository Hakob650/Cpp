#include <iostream>
#include "Vector.hpp"

int main(){
  
  MyVector vector;  
  
  vector.push_back(1);
  vector.push_back(2);
  vector.push_back(3);
  vector.push_back(4);
  vector.push_back(5);

  vector.print();
  std::cout<<"size: "<<vector.get_size()<<std::endl;;  
  std::cout<<"capacity "<<vector.get_capacity()<<std::endl;; 
  
   
  
    vector.pop_back();
    vector.pop_back();
    vector.pop_back();
    std::cout<<"After pop_back "<<vector.get_size()<<"\n";


  
    vector.print();  
  
    vector.clear();
    std::cout<<"After clear "<<vector.get_size()<<"\n";  
    return 0;
}