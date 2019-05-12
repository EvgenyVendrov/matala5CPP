#pragma once

namespace itertools
{
template <typename T>
class range 
{
public:
    T _first, _last;

    range(T first, T last)
    {
        this->_first = first;
        this->_last = last;
    }

    //***START OF NEW ITERATOR CLASS***
    class iterator
    {
        T _currentMember;

    public:
        iterator(T setMemeber)
        {
            this->_currentMember = setMemeber;
        }

        T &operator*()
        {
            return _currentMember;
        }

        // ++i;
        iterator &operator++()
        {
            this->_currentMember++;
            return *this;
        }

        // i++;
        iterator &operator++(int dummyFlagForPostFix)
        {
            iterator temp = *this;
            this->_currentMember++;
            return temp;
        }

        bool operator!=(const iterator &rhs) const
        {
            return (this->_currentMember != rhs._currentMember);
        }
    }; //***END OF ITERATOR CLASS***

    iterator begin()
    {
        return iterator{this->_first};
    }

    iterator end()
    {
        return iterator{this->_last};
    }

private:
};
} // namespace itertools