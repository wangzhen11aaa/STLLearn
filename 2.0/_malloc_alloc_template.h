#if 0
# include <new>
# define __THROW_BAD_MALLOC throw bad_alloc
#elif !defined(__THROW_BAD_ALLOC)
    #include <iostream>
    #define __THROW_BAD_ALLOC cerr <<  "out of memory" << endl; exit(1);
# endif

namespace M{
template<int inst>
class __malloc_alloc_template{

};
};