#include "badkan.hpp"
#include<iostream>
#include<exception>
#include "range.hpp"
#include "chain.hpp"
#include "zip.hpp"
#include "product.hpp"
#include "powerset.hpp"
#include "ToString.hpp"
#define COMMA ,
using namespace itertools;
using namespace std;
int main(){
    badkan::TestCase testcase;
    int grade=0;
    int signal = setjmp(badkan::longjmp_buffer);
    if (signal == 0) {
        //range
        testcase.setname("Test range")
        .CHECK_OUTPUT(iterable_to_string(range(-3,3)), "-3,-2,-1,0,1,2,")
        .CHECK_OUTPUT(iterable_to_string(range(1,8)), "1,2,3,4,5,6,7,")
        .CHECK_OUTPUT(iterable_to_string(range('a','f')), "a,b,c,d,e,")
        .CHECK_OUTPUT(iterable_to_string(range('A', 'F')), "A,B,C,D,E,")
        .CHECK_OUTPUT(iterable_to_string(range(1.1, 4.1)),"1.1,2.1,3.1,")
        .CHECK_OUTPUT(iterable_to_string(range(-3.3,2.7)), "-3.3,-2.3,-1.3,0.7,1.7,");
        //chain
        testcase.setname("Test chain")
        .CHECK_OUTPUT(iterable_to_string(chain(range(1,4), range(5,8))), "1,2,3,4,5,6,7,")
        .CHECK_OUTPUT(iterable_to_string(chain(range('a','e'), string("hello"))), "a,b,c,d,e,h,e,l,l,o,")
        .CHECK_OUTPUT(iterable_to_string(chain(range('A','C'),string("aba"))), "A,B,C,a,b,a," )
        .CHECK_OUTPUT(iterable_to_string(chain(range(1.1,3.1),range(5.3,6.3))), "1.1,2.1,5.3," )
        //overlaps
        .CHECK_OUTPUT(iterable_to_string(chain(range(1,2), range(1,5))), "1,1,2,3,4,")
        .CHECK_OUTPUT(iterable_to_string(chain(range(1,4),range(1,3))), "1,2,3,1,2,")
        .CHECK_OUTPUT(iterable_to_string(chain(range('a', 'e'), range('a', 'e'))), "a,b,c,d,e,a,b,c,d,e,")
        .CHECK_OUTPUT(iterable_to_string(chain(string("hello"), string("hello"))), "h,e,l,l,o,h,e,l,l,o,")
        ;
        testcase.setname("Test zip")
        .CHECK_OUTPUT(iterable_to_string(zip(range(1,6), string("hello"))), "1,h, 2,e, 3,l, 4,l, 5,o,")
        .CHECK_OUTPUT(iterable_to_string(zip(zip(range(1,4), string("xyz")),zip(string("abc"),range(6,9)))), "1,x, a,6 ,2,y ,b,7 ,3,z ,c,8,")
        .CHECK_OUTPUT(iterable_to_string(zip(range(1,3),range(1,3))), "1,1, 2,2,")
        .CHECK_OUTPUT(iterable_to_string(zip(chain(range('A', 'C'), string("ABC")), chain(range(-1.1, 2.1), range(0.3, 3.3)))), "A,-1.1, B,0.1, C,1.1, A,0.3, B,1.3, C,2.3,")
        ;
        testcase.setname("Test product")
        .CHECK_OUTPUT(iterable_to_string(product(range(1,4), string("hello"))), "1,h, 1,e, 1,l, 1,l, 1,o  2,h, 2,e, 2,l, 2,l, 2,o, 3,h, 3,e, 3,l, 3,l, 3,o" )
        .CHECK_OUTPUT(iterable_to_string(product(string("ab"),string("AB"))), "a,A, b,A, b,B")
        .CHECK_OUTPUT(iterable_to_string(product(range(-3.3, 2.7), range(1,3))), "-3.3,1, -3.3,2, -2.3,1, -2.3,2, -1.3,1, -1.3,2, -0.7,1, -0.7,2, -1,7,1, -1.7,2")
        ;
        testcase.setname("Test powerset")
        .CHECK_OUTPUT(iterable_to_string(powerset(range(1,4))), "{},{1},{2},{1,2},{3},{1,3},{2,3},{1,2,3},")
        .CHECK_OUTPUT(iterable_to_string(powerset(chain(range('a','c'),range('x','z')))), "{},{a},{b},{a,b},{x},{a,x},{b,x},{a,b,x},{y},{a,y},{b,y},{a,b,y},{x,y},{a,x,y},{b,x,y},{a,b,x,y},")
        .CHECK_OUTPUT(iterable_to_string(zip(range(1,3), range(1,3))), "{},{1,1},{2,2},{1,1, 2,2},")
        .CHECK_OUTPUT(iterable_to_string(product(string("ab"),string("AB"))), "{},{a,A},{b,A},{b,B},{a,A, b,A},{a,A, b,B},{b,A, b,B},{a,A, a,B, b,B}")
        ;

        grade = testcase.grade();
    }
    else{
        testcase.print_signal(signal);
        grade = 0;
    }
    std::cout <<  "*** Grade: " << grade << " ***" << std::endl;
    return grade;
}