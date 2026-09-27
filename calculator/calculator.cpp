// В этом файле определения функций.
// За основу возьмите решение предыдущей задачи.

/*использование ИИ:
1. названия переменных и функций
2. узнал что такое std::optional, и как его использовать(для проверки наличия у memory_num значения)
3. узнал что математический порядок действий не нужно соблюдать(слава богу спросил вовремя)
4. т. к. я это делал в вс код, мне помогли с рутиной(+, -, * и т. д.)

*/
#include <iostream>
#include <string>
#include <algorithm>
#include <optional>
#include <cmath>
#include <vector>
#include "calculator.h"


bool ReadNumber(Number& num){
    if (!(std::cin >> num)){
        std::cerr << "Error: Numeric operand expected";
        return false;
    }
    return true;
}






bool RunCalculatorCycle(){
    Number sum_now, b;
    std::optional<Number> memory_num;
    std::string op;
    std::vector<std::string> operators = {"+", "-", "*", "/", "=", "c", "l", "s", "q", ":", "**"};
    if (!(ReadNumber(sum_now))){
        return false;
    }
    while (true){
        std::cin >> op;
        if (!(std::find(operators.begin(), operators.end(), op) != operators.end())){
            std::cerr << "Error: Unknown token " << op;
            return false;
        }
        else if (op == "q"){
            return true;
        }
        else if (op == "c"){
            sum_now = 0;
            continue;
        }
        else if (op == "l"){
            if (memory_num.has_value()){
                sum_now = memory_num.value();
            }
            else{
                std::cerr << "Error: Memory is empty";
                return false;
            }
            continue;
        }
        else if (op == "s"){
            memory_num = sum_now;
            continue;
        }
        else if (op == ":"){
            if (!(ReadNumber(sum_now))){
                return false;
            }
            continue;
        }
        else if (op == "="){
            std::cout << sum_now << std::endl;
            continue;
        }
        else if (op == "+"){
            if (!(ReadNumber(b))){
                return false;
            }
            sum_now += b;
        }
        else if (op == "-"){
            if (!(ReadNumber(b))){
                return false;
            }
            sum_now -= b;
        }
        else if (op == "*"){
            if (!(ReadNumber(b))){
                return false;
            }
            sum_now *= b;
        }
        else if (op == "/"){
            if (!(ReadNumber(b))){
                return false;
            }
            sum_now /= b;
        }
        else if (op == "**"){
            if (!(ReadNumber(b))){
                return false;
            }
            sum_now = pow(sum_now, b);
        }

    }
    





}