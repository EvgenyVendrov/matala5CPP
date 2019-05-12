#include <iostream>
using namespace std;
using std::string;
#include "range.hpp"
#include "chain.hpp"
#include "zip.hpp"
#include "product.hpp"
#include "powerset.hpp"
#include "badkan.hpp"
using namespace itertools;

int main()
{

    badkan::TestCase testcase;
    int grade = 0;
    int signal = setjmp(badkan::longjmp_buffer);
    if (signal == 0)
    {
        string intTest = "", intTestExcepected = "123456", doubleTest = "", doubleTestExcepected = "3.2000004.2000005.2000006.2000007.200000", negRangeTest = "",negRangeTestExcepected="-3-2-10123"
        ,charSmallTest = "",charSmallTestExcepected = "abcd";
        for (int i : range(1, 7))
        {
            intTest +=to_string(i);
        }
        for (double i : range(3.2, 8.2))
        {
            doubleTest +=to_string(i);
        }
         for (int i : range(-3, 4))
        {
            negRangeTest +=to_string(i);
        }
          for (char i : range('a', 'e'))
        {
            charSmallTest +=i;
        }
        testcase.setname("range - number test")
            .CHECK_EQUAL(intTest, intTestExcepected)
            .CHECK_EQUAL(doubleTest, doubleTestExcepected)
            .CHECK_EQUAL(negRangeTest,negRangeTestExcepected)
            .CHECK_EQUAL(charSmallTest,charSmallTestExcepected);
        grade = testcase.grade();
    }
    else
    {
        testcase.print_signal(signal);
        grade = 0;
    }
    cout << "Your grade is: " << grade << endl;
    return 0;
}