#include <cstddef>
#include "../../2.0/2jjalloc.h"
#include "../../2.0/myMemoryManagement.h"
#include <cstdio>
#include <concepts>



namespace _STD{

    template<typename T>
    concept Hashable = requires(T a) {
        { std::hash<T>{}(a) } -> std::convertible_to<std::size_t>;
    };

    template<typename T, class Alloc = JJ::allocator<T> >
    class Vector{
    public:
        typedef T value_type;
        typedef value_type* pointer;
        typedef value_type* iterator;
        typedef value_type& reference;
        typedef size_t size_type;
        typedef ptrdiff_t difference_type;

    protected:
        Alloc alloc;
        iterator start;
        iterator finish;
        iterator end_of_storage;

        // declare function.
        void _insert_aux(iterator position, const T& x);
        
        void _deallocate(){
            if(start){
                alloc.deallocate(start, end_of_storage - start);
            }
        }

        void _fill_initialize(size_type n, const T& value){
            start = _allocate_and_fill(n, value);
            finish = start + n;
            end_of_storage = finish;
        }

        iterator _allocate_and_fill(size_type n, const T& value){
            // iterator is a value_type * type.
            iterator result = alloc.allocate(n);
            myMM::uninitialized_fill<T* , T>(result, result+n, value);
            return result;
        }

    public:
        // vector defult constructor
        Vector(): start(0), finish(0), end_of_storage(0){}

        // vector constructor
        Vector(size_type n, const T& value){
            _fill_initialize(n, value);
        } 
        // vector print
        void printVector(){
            iterator _start = start;
            while(start != finish){
                cout << *start << endl;
                start++;
            }
        }
    
     };
}