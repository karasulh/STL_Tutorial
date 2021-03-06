#include <vector>
#include <iostream>
#include <numeric>
#include <iterator>
#include <algorithm>

using namespace std;


int main(){

    int i=35, j=13;
    cout<<gcd(i,j)<<", "<<lcm(i,j)<<"\n";

    i=8;
    j=12;
    cout<<gcd(i,j)<<", "<<lcm(i,j)<<"\n";

    vector<int> num{6,3,8,12,24,13,5,35};
    vector<int> out;

    //Use it as a binary predicate
    adjacent_difference(begin(num),end(num),back_inserter<vector<int>>(out),&std::gcd<int,int>);

    copy(begin(out),end(out),ostream_iterator<int>(std::cout, " "));
    cout<<"\n";

    return 0;
}