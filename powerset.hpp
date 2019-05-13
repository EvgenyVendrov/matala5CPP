#pragma once

namespace itertools
{
template <class T>
class powerset
{
    //***START OF NEW ITERATOR CLASS***
    template <class U>
    class iterator
    {
        U _firstIT;

    public:
        iterator(U firstIT) : _firstIT(firstIT){}

        // decltype(*_firstIT) &operator*()
        // {
        //     return (*(this->_firstIT));
        // }

        // // ++i;
        // iterator &operator++()
        // {
        //     //basic logic as for now:
        //     if (*(this->_firstIT) != this->_firstIT::end())
        //     {
        //         return ((this->_firstIT)++);
        //     }
        //     else
        //     {
        //         return ((this->_secondIT)++);
        //     }
        // }

        // // i++;
        // iterator &operator++(int dummyFlagForPostFix)
        // {
        //     iterator temp = *this;
        //     if (*(this->_firstIT) != this->_firstIT.end())
        //     {
        //         (this->_firstIT)++;
        //     }
        //     else
        //     {
        //         ((this->_secondIT)++);
        //     }
        //     return temp;
        // }

        // bool operator!=(const iterator &rhs) const
        // {
        //     return false;
        // }

    private:
    }; //***END OF ITERATOR CLASS***

public:
    T _arg1;

    powerset(T arg1) : _arg1(arg1){}
    auto begin()
    {
        return this->_arg1.begin();
    }

    auto end()
    {
        return this->_arg1.begin();
    }
};
} // namespace itertools