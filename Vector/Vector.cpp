#include <iostream>
class MyVector {
private:
  size_t size;
  size_t capacity;
  int *data;
public:
  MyVector(){
    construct();
  }
  ~MyVector(){
    destruct();
  }
  void construct(){
    data=nullptr;
    size=0;
    capacity=0;
  }
  void destruct(){
    delete[] data;
    data=nullptr;
    size=0;
    capacity=0;
  }
  size_t get_size(){
    return size;
  }
  size_t get_capacity(){
    return capacity;
  }
  void push_back( int value ) {
    if(size==capacity){
        size_t newcapacity=(capacity==0) ? 1 : capacity*2;
        int *newdata=new int[newcapacity];
        for(size_t i=0;i<size;++i){
            newdata[i]=data[i];
        }
        delete[] data;
        data=newdata;
        capacity=newcapacity;
    }
    data[size++]=value;
  }
  void pop_back( ){
    if(size>0){
      size--;
    }
  }
  void resize(size_t newsize) {
    if (newsize > capacity) {
        size_t newcapacity = newsize * 2;
        int* newdata = new int[newcapacity];
            for (size_t i = 0; i < size; ++i) {
                    newdata[i] = data[i];
            }
    for (size_t i = size; i < newsize; ++i) {
            newdata[i] = 5;
    }
    delete[] data;
    data = newdata;
    capacity = newcapacity;
  } else {
    for (size_t i = size; i < newsize; ++i) {
      data[i] = 0;
    }
  }
  size = newsize;
}

  void clear(){
    size=0;
  }
  void print() {
  for (size_t i = 0; i < size; ++i) {
    std::cout << data[i] << " ";
  }
  std::cout << "\n";
}

};
int main(){
  
  MyVector vector;  
  
  vector.push_back(1);
  vector.push_back(2);
  vector.push_back(3);
  vector.push_back(4);
  vector.push_back(5);

  vector.print();
  std::cout<<"size: "<<vector.get_size()<<"capacity"<<vector.get_capacity()<<"\n";  
  
  
   
  
  vector.resize(10);
  std::cout<<"After resize: "<<vector.get_size()<<"\n";  
  
  vector.print();  
  
  vector.clear();
  std::cout<<"After clear"<<vector.get_size()<<"\n";  
  return 0;
}

