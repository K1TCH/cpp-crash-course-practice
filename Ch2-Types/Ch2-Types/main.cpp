//
//  main.cpp
//  Ch2-Types
//
//  Created by Nolan Kitchin on 5/23/21.
//

#include <cstdio>

enum class Operation {
    Add,
    Subtract,
    Multiply,
    Divide
};

struct Calculator {
    Calculator(Operation operation_in) {
        operation = operation_in;
    }
    
    Operation operation;
    
    int calculate(int a, int b) {
        switch(operation) {
            case Operation::Add:
                return a + b;
            case Operation::Subtract:
                return a - b;
            case Operation::Multiply:
                return a * b;
            case Operation::Divide:
                return a / b;
        }
    }
};

int main(int argc, const char * argv[]) {
    Calculator calcAdd{Operation::Add};
    Calculator calcSub{Operation::Subtract};
    Calculator calcMult{Operation::Multiply};
    Calculator calcDiv{Operation::Divide};
    int a = 20;
    int b = 5;
    printf("%d + %d = %d\n", a, b, calcAdd.calculate(a, b));
    printf("%d - %d = %d\n", a, b, calcSub.calculate(a, b));
    printf("%d * %d = %d\n", a, b, calcMult.calculate(a, b));
    printf("%d / %d = %d\n", a, b, calcDiv.calculate(a, b));
    return 0;
}
