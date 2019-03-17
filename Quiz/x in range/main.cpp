#include <iostream>
#include <utility> // std::pair, make_pair
#include <vector> 
#include <cmath> // pow()

/*
look for occurances of 1 in range (0-1345):

1000 - 1345: has (345 + 100) = 445 
    * 1100-1199: has 100 of 1 as hundred postion
    * 1000 - 1345 has 345 1 as thousandth postion

100 - 999: has (100 + 20 * 10) = 300  of 1:
    * 100 - 199: has 100 of 1 as hundredth position
    * 0-99: has (10 + 1 * 10) = 20 of 1s:
        * 10-19 has 10 of 1 as tenth position
        * 0-9 has 1 of 1 as digit position 

let n = number of digit start from 1, 
let f(x) is a function that count number of occurances of one digit number in each n digit

    f(n=1): pow(10,0) = 1,  where {n, n C range(0,9)}
    f(n=2): pow(10,1) +  1 * 10 = 20  , where {n, n C range(10,99)}
    f(n=3): pow(10,2) + 20 * 10 = 300 , where {n, n C range(100,999)}

=> f(n) = pow(10, n-1) + (n-1).pow(10, n-1), given n < 0, n C N
----------------------------------------
|     => f(n) = n * pow(10, n-1)       |
----------------------------------------

*/

int occur_x(int, int, int, int);
void test();


using namespace std;

int main(int argc, char* argv []) {
    int occur = occur_x(3, 100, 1, 0);
    cout << occur << endl;
}


int occur_x (int x, int n, int c , int factor ) 
{
    if (x > n || x == 0 )
        return 0;

    int divisor = 10;
    int r = n % divisor;

    if ( x <= r) 
    {
        return (factor + 1) * pow(10, factor);
    } 

    int temp = factor * pow(10, factor);
    n = n / divisor;
    factor = (factor+1);
    

    return temp +  occur_x(x, n, c, factor);

}

void test() {
    
}