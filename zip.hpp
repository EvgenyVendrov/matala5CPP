#pragma once

namespace itertools
{
template <class T, class P>
class zip
{
    //***START OF NEW ITERATOR CLASS***
    template <class S, class U>
    class iterator
    {
        S _firstIT;
        U _secondIT;

    public:
        iterator(U firstIT, S secIT) : _firstIT(firstIT), _secondIT(secIT) {}

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
    P _arg2;

    zip(T arg1, P arg2) : _arg1(arg1), _arg2(arg2) {}
    auto begin()
    {
        return this->_arg1.begin();
    } // iteratable object    }

    auto end()
    {
        return this->_arg1.begin();
    }
};
} // namespace itertools