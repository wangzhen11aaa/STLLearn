#include <cstddef>
#include "../../2.0/2jjalloc.h"
#include <cstdio>

namespace MySpace{
    // JJ::allocator作为一个管理内存的类，功能就是
    template<typename T, class Alloc=JJ::allocator<T> >
    class Vector{
        public:
        // push_back(iterator, item), return a iterator.
            typedef T value_type;
            // pointer and iterator is the same type in Vector Container.
            typedef value_type* pointer;
            typedef value_type* iterator;
            typedef const value_type* const_iterator;
            typedef value_type& reference;
            typedef size_t size_type;
            typedef ptrdiff_t difference_type;

        protected:
            Alloc alloc;
            iterator start; //表示目前空间的头
            iterator finish; // 表示目前空间的尾
            iterator end_of_storage; // 表示目前可用的尾
            
            // Method used only inside the class, we prefix '_' before method name.

            // Insert auxilliary 
            void _insert_aux(iterator position, const T& x);
            
            // _deallocate method 
            void _deallocate(){
                if(start)
                    alloc.deallocate(start);
            }

            // size method accepts no value and return the size of vector.
            size_type _size(){
                return (finish - start) / sizeof(iterator);
            }

        public:
            // constructor
            explicit Vector(size_type n){
                start = alloc.allocate(n);
                finish = start;
                end_of_storage = start + n;
                size = 0;
            }
            // push_back method accepts iterator and const T& reference.
            iterator push_back(const_iterator position, const T& t);
            
            // pop_back method accepts no value and return a reference, 
            T pop_back();
            
            // find method accepts const T& reference and returns a const T& referece.By default, it searches from
            // the start method.
            iterator find(const T& v);

            // erase method accepts an iterator and return the position after the this iterator.
            // If this iterator equals to iterator::end, we just return end.
            iterator erase(const iterator position);

            size_type get_size();
        
        // private:
            size_type size;
            // end method accept no value, return the finish iterator.
            iterator end(){
                return finish;
            }
            iterator begin(){
                return start;
            }
    };

    template<typename T, class Alloc>
    typename Vector<T, Alloc>::iterator Vector<T, Alloc>::push_back(typename Vector<T, Alloc>::const_iterator position, const T& t){
        if (size == 0){
            // gurantee class invariant
            start = alloc.allocate(1);
            finish = start;
            end_of_storage = start + 1;

            printf("Current finish : %p ", finish);
            // std::copy(finish++, t);
            (*(finish++)) = t;
            std::cout << "Insert " << t << " into vector : t " << std::endl;
            printf("Current finish after assignment : %p ", finish);
            size++;
            return finish;
        }else{
        // This vec has space to store the t.
        if (finish != end_of_storage){
            // We know some address ,type and another object obj which is the same type.
            // We want to initialize this address with this obj.
            // We use the normal copy assignment method to accomplish copy task.
            printf("Current finish : %p ", finish);
            // std::copy(finish++, t);
            (*(finish++)) = t;
            std::cout << "Insert " << t << " into vector : t " << std::endl;
            printf("Current finish after assignment : %p \n", finish);
            size++;
        }else{
            // We update new_size to 2 * size;
            size_type new_size = 2 * size;
            T* new_address = alloc.allocate(new_size);
            end_of_storage = new_address + new_size;
            for(int i = 0; i < size; i++){
                printf("Assign %d from %p to %p \n", *(start+i), (start+i), (new_address+i));
                //std::copy(new_address+i, start+i);
                *(new_address+i) = *(start+i);
            }
            printf("Current finish : %p \n", finish);
            //std::copy(finish++, t);
            (*(finish++)) = t;
            std::cout << "Insert " << t << " into vector : t " << std::endl;
            printf("Current finish after assignment : %p \n", finish);
            // Update these fields to guarantee class invariant.
            //(T)(*(finish++)) = t;
            size = new_size;
            // release space before 
            alloc.destory(new_address);
            }
            return finish;
        }
    }

    // template<typename T, class Alloc>
    // typename Vector<T, Alloc>::iterator Vector<T, Alloc>::get_size(){
        
    // }
}