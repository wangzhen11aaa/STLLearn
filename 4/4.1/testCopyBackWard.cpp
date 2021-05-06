#include <iostream>
#include <algorithm>
#include <vector>

int main(){
    std::vector<int> from_vector;
    for (int i = 0; i < 10; i++) {
        from_vector.push_back(i);
    }
 
    std::vector<int> to_vector(15);
 
    std::copy_backward(from_vector.begin(), from_vector.end(), to_vector.end());
 
    std::cout << "to_vector contains: ";
    for (auto i: to_vector) {
        std::cout << i << " ";
    }
    std::vector<int> v{1,2};
    std::cout << "v's size() " << v.size() << std::endl;
    //for(auto i:  v){
     //   std::cout << i << std::endl;
  //  }
    std::vector<int> to_v(4);
    //std::copy_backward(v.begin(), v.begin()+1, to_v.end());
    std::copy_backward(v.begin(), v.begin() + 1, v.end());
    std::cout << "after copy_backward, v's size() " << v.size() << std::endl;
    for(auto i:  v){
        std::cout << i << std::endl;
    }
    
}