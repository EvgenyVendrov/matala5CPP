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
        //********************testing range class********************

        string intTest = "", intTestExcepected = "123456", doubleTest = "", doubleTestExcepected = "3.2000004.2000005.2000006.2000007.200000", negTest = "", negTestExcepected = "-3-2-10123", charSmallTest = "", charSmallTestExcepected = "abcd", charBigTest = "", charBigTestExcepected = "ABCD";
        for (int i : range(1, 7))
        {
            intTest += to_string(i);
        }
        for (double i : range(3.2, 8.2))
        {
            doubleTest += to_string(i);
        }
        for (int i : range(-3, 4))
        {
            negTest += to_string(i);
        }
        for (char i : range('a', 'e'))
        {
            charSmallTest += i;
        }
        for (char i : range('A', 'E'))
        {
            charBigTest += i;
        }
        testcase.setname("range - number test")
            .CHECK_EQUAL(intTest, intTestExcepected)
            .CHECK_EQUAL(doubleTest, doubleTestExcepected)
            .CHECK_EQUAL(negTest, negTestExcepected);
        testcase.setname("range - char test")
            .CHECK_EQUAL(charSmallTest, charSmallTestExcepected)
            .CHECK_EQUAL(charBigTest, charBigTestExcepected);

        intTest = "", intTestExcepected = "127891011121314", doubleTest = "", doubleTestExcepected = "0.51.52.522.523.5", negTest = "", negTestExcepected = "-10-7-6-5-4-3-2-1", charSmallTest = "", charSmallTestExcepected = "abcdcd", charBigTest = "", charBigTestExcepected = "ABG";
        string mixedTest = "", mixedTestExcepected = "ABCabc";

        //********************testing chaing class********************

        for (int i : chain(range(1, 3), range(7, 15)))
        {
            intTest += to_string(i);
        }
        for (double i : chain(range(0.5, 3.5), range(22.5, 24.5)))
        {
            doubleTest += to_string(i);
        }
        for (char i : chain(range('a', 'e'), range('c', 'e')))
        {
            charSmallTest += i;
        }
        for (char i : chain(range('A', 'C'), string("G")))
        {
            charBigTest += i;
        }
        for (char i : chain(range('A', 'D'), range('a', 'd')))
        {
            mixedTest += i;
        }
        testcase.setname("chain - number test")
            .CHECK_EQUAL(intTest, intTestExcepected)
            .CHECK_EQUAL(doubleTest, doubleTestExcepected)
            .CHECK_EQUAL(negTest, negTestExcepected);
        testcase.setname("chain - char test")
            .CHECK_EQUAL(charSmallTest, charSmallTestExcepected)
            .CHECK_EQUAL(charBigTest, charBigTestExcepected)
            .CHECK_EQUAL(mixedTest, mixedTestExcepected);

        //********************testing zip class********************

        intTest = "", intTestExcepected = "1,1 2,2 3,3", doubleTest = "", doubleTestExcepected = "3.2,10.5 4.2,11.5 5.2,12.5";
        string chainTest = "", chainTestExcepected = "1,a 2,b 1.3,A 2.3,B";
        negTest = "", negTestExcepected = "-3,1.3 -2,2.3 -1,3.3", charSmallTest = "", charSmallTestExcepected = "d,a e,b f,c",
        mixedTest = "", mixedTestExcepected = "a,A b,B c,C d,D";
        for (auto pair : zip(range(1, 4), range(1, 4)))
        {
            intTest += to_string(pair);
        }
        for (auto pair : zip(range(3.2, 6.2), range(10.5, 13.5)))
        {
            doubleTest += to_string(pair);
        }
        for (auto pair : zip(chain(range(1, 3), range(1.3, 4.3)), chain(string('a', 'c'), string('A', 'C'))))
        {
            chainTest += to_string(pair);
        }
        for (auto pair : zip(range(-3, 0), range(1.3, 4.3)))
        {
            negTest += to_string(pair);
        }
        for (auto pair : zip(range('d', 'g'), range('a', 'd')))
        {
            charSmallTest += pair;
        }
        for (auto pair : zip(string("abcd"), string("ABCD")))
        {
            mixedTest += pair;
        }
        testcase.setname("zip - number test")
            .CHECK_EQUAL(intTest, intTestExcepected)
            .CHECK_EQUAL(doubleTest, doubleTestExcepected)
            .CHECK_EQUAL(negTest, negTestExcepected);
        testcase.setname("zip - number & string mixed test")
            .CHECK_EQUAL(chainTest, chainTestExcepected);
        testcase.setname("zip - char test")
            .CHECK_EQUAL(charSmallTest, charSmallTestExcepected)
            .CHECK_EQUAL(mixedTest, mixedTestExcepected);

        //********************testing product class********************

        string intDoubleTest = "", intDoubleTestExpected = "0,1.5 0,2.5 0,3.5 1,1.5 1,2.5 1,3.5";
        string stringStringTest = "", stringStringTestExpected = "h,c h,+ h,+ e,c e,+ e,+ l,c l,+ l,+ l,c l,+ l,+ o,c o,+ o,+";
        string stringDoubleTest = "", stringDoubleTestExpected = "0.5,a 0.5,b 0.5,c 1.5,a 1.5,b 1.5,c 2.5,a 2.5,b 2.5,c 3.5,a 3.5,b 3.5,c 4.5,a 4.5,b 4.5,c";
        string chainProductTest = "", chainProductTestExpected = "a,1 a,2 a,3 a,4 a,5 b,1 b,2 b,3 b,4 b,5 A,1 A,2 A,3 A,4 A,5 B,1 B,2 B,3 B,4 B,5";
        string zipChainProductTest = "", zipChainProductTestExpected = "1,A,h,# 1,B,h,# 1,C,h,# 2,A,h,# 2,B,h,# 2,C,h,# 3,A,h,# 3,B,h,# 3,C,h,#";
        string zipZipProductTest = "", zipZipProductTestExpected = "1,A,1,1 1,B,1,2 1,C,1,3 1,A,2,1 1,B,2,2 1,C,2,3 1,A,3,1 1,B,3,2 1,C,3,3 2,A,1,1 2,B,1,2 2,C,1,3 2,A,2,1 2,B,2,2 2,C,2,3 2,A,3,1 2,B,3,2 2,C,3,3 3,A,1,1 3,B,1,2 3,C,1,3 3,A,2,1 3,B,2,2 3,C,2,3 3,A,3,1 3,B,3,2 3,C,3,3";
        for (auto pair : product(range(0, 2), range(1.5, 4.5)))
        {
            intDoubleTest += to_string(pair);
        }
        for (auto pair : product(string("hello"), string("c++")))
        {
            stringStringTest += pair;
        }
        for (auto pair : product(range(0.5, 5.5), string("abc")))
        {
            stringDoubleTest += to_string(pair);
        }
        for (auto pair : product(chain(range(1, 3), range(3, 6)), chain(range('a', 'c'), range('A', 'C'))))
        {
            chainProductTest += to_string(pair);
        }
        for (auto pair : product(zip(range(1, 4), range('A', 'C')), chain(string("h"), string("#"))))
        {
            zipChainProductTest += to_string(pair);
        }
        for (auto pair : product(zip(range(1, 4), range('A', 'D')), zip(range(1, 4), range(1, 4))))
        {
            zipZipProductTest += pair;
        }
        testcase.setname("product - number test")
            .CHECK_EQUAL(intDoubleTest, intDoubleTestExpected);
        testcase.setname("product - number & string mixed test with range")
            .CHECK_EQUAL(stringDoubleTest, stringDoubleTestExpected);
        testcase.setname("product - string & string test")
            .CHECK_EQUAL(stringStringTest, stringStringTestExpected);
        testcase.setname("product - chain & chain test")
            .CHECK_EQUAL(chainProductTest, chainProductTestExpected);
        testcase.setname("product - zip & chain test")
            .CHECK_EQUAL(zipChainProductTest, zipChainProductTestExpected);
        testcase.setname("product - zip & zip test")
            .CHECK_EQUAL(zipZipProductTest, zipZipProductTestExpected);
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