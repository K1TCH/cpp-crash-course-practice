//
//  main.cpp
//  Ch1-UpAndRunning
//
//  Created by Nolan Kitchin on 5/22/21.
//

#include <cstdio>

int absoluteValue(int x) {
    if (x >= 0) {
        return x;
    } else {
        return x * -1;
    }
}

int sum(int x, int y) {
    return x + y;
}

int main(int argc, const char * argv[]) {
    int myNum = -10;
    printf("The absolute value of %d is %d.\n", myNum, absoluteValue(myNum));
    int myNum2 = 10;
    printf("The sume of %d and %d is %d.\n", myNum, myNum2, sum(myNum,myNum2));
}
