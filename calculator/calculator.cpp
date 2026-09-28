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

bool ReadNumber(Number& number){
    if (!(std::cin >> number)){
        std::cerr << "Error: Numeric operand expected";
        return false;
    }
    return true;
}

bool RunCalculatorCycle(){
    Number current_result = 0;
    Number operand = 0;
    std::optional<Number> memory_num;
    std::string command;
    std::vector<std::string> operators = {"+", "-", "*", "/", "=", "c", "l", "s", "q", ":", "**"};
    if (!ReadNumber(current_result)){
        std::cerr << "Error: Numeric operand expected";
        return false;
    }
    while (std::cin >> command){
        if (std::find(operators.begin(), operators.end(), command) == operators.end()){
            std::cerr << "Error: Unknown token " << command;
            return false;
        }
        if (command == "q"){
            return true;
        }
        if (command == "c"){
            current_result = 0;
            continue;
        }
        if (command == "l"){
            if (!memory_num.has_value()){
                std::cerr << "Error: Memory is empty";
                return false;
            }
            current_result = memory_num.value();
            continue;
        }
        if (command == "s"){
            memory_num = current_result;
            continue;
        }
        if (command == ":"){
            if (!ReadNumber(current_result)){
                return false;
            }
            continue;
        }
        if (command == "="){
            std::cout << current_result << std::endl;
            continue;
        }
        if (command == "+"){
            if (!ReadNumber(operand)){
                return false;
            }
            current_result += operand;
            continue;
        }
        if (command == "-"){
            if (!ReadNumber(operand)){
                return false;
            }
            current_result -= operand;
            continue;
        }
        if (command == "*"){
            if (!ReadNumber(operand)){
                return false;
            }
            current_result *= operand;
            continue;
        }
        if (command == "/"){
            if (!ReadNumber(operand)){
                return false;
            }
            current_result /= operand;
            continue;
        }
        if (command == "**"){
            if (!ReadNumber(operand)){
                return false;
            }
            current_result = std::pow(current_result, operand);
            continue;
        }
    }
    return true;
}