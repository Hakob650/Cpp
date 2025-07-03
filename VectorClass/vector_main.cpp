#include <iostream>
#include "Vector.hpp"

int main(){
  
  MyVector v1;  

  std::cout<<"Initial size: "<<v1.get_size()<<std::endl;;

  std::cout<<"Initial capacity: "<<v1.get_capacity()<<std::endl;;

  
  
  v1.push_back(1);
  v1.push_back(2);
  v1.push_back(3);
  v1.push_back(4);
  v1.push_back(5);

  MyVector v2(v1);
  std::cout<<"After copy constructor v2 size: "<<v2.get_size()<<std::endl;;
  std::cout<<"After copy constructor v2 capacity: "<<v2.get_capacity()<<std::endl;;
  v2.print();

  MyVector v3(std::move(v1));
  std::cout<<"After move constructor v3 size: "<<v3.get_size()<<std::endl;;
  std::cout<<"After move constructor v3 capacity: "<<v3.get_capacity()<<std::endl;;
  v3.print();

  MyVector v4;
  v4 = v2;
  std::cout<<"After copy assignment v4 size: "<<v4.get_size()<<std::endl;;
  std::cout<<"After copy assignment v4 capacity: "<<v4.get_capacity()<<std::endl;;
  v4.print();

  MyVector v5;
  v5 = std::move(v2);
  std::cout<<"After move assignment v5 size: "<<v5.get_size()<<std::endl;;
  std::cout<<"After move assignment v5 capacity: "<<v5.get_capacity()<<std::endl;;
  v5.print();
  std::cout<<"After move assignment v2 size: "<<v2.get_size()<<std::endl;;
  std::cout<<"After move assignment v2 capacity: "<<v2.get_capacity()<<std::endl;;
  v2.print();



  v1.print();
  std::cout<<"size: "<<v1.get_size()<<std::endl;;  
  std::cout<<"capacity "<<v1.get_capacity()<<std::endl;; 
  
   
  
    v1.pop_back();
    v1.pop_back();
    v1.pop_back();
    std::cout<<"After pop_back "<<v1.get_size()<<"\n";


  
    v1.print();  
  
    v1.clear();
    std::cout<<"After clear "<<v1.get_size()<<"\n";  
    return 0;
}