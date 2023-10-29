#include <iostream>
int main(){
    double number1;
    double number2;
    char oper;
    double result;

    std::cout << "Enter +,-,/,*:" <<std::endl;
    std::cin >> oper;

    std::cout << "Enter number1:" <<std::endl;
    std::cin >> number1;
    std::cout << "Enter number2:" << std::endl;
    std::cin >> number2;

    switch(oper){
        case('+'):
            result = number1 + number2;
            break;
        
        case('-'):
            result = number1 - number2;
            std::cout << "result:" << result << std::endl;
            break;

        case('/'):
            result = number1/number2;
            std::cout << "result:" << result << std::endl;
            break;

        case('*'):
            //result = number1*number2;
            std::cout << "result:" << number1*number2 << std::endl;
            break;
        
        default:
            std::cout << "Error" << std::endl;
            break;
    
    std::cout << "Done" << std::endl;
    return 0;
    }
    
}