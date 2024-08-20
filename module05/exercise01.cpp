#include <iostream>

// recursive function: halting condition -> recursive structure
auto
factorial(int n){
    if (n==0){
        return 1;
    } else {
        return factorial(n-1) * n;
    }
}

/*
 * Error: cannot deduce the return type!
auto
factorial2(int n){
    if (n>1){
        return factorial2(n-1) * n;
    } else {
        return 1;
    }
}
*/
int main() {
    std::cout << "5!: " << factorial(5) << std::endl;
    return 0;
}
