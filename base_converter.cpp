#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

std::string vector2str(const std::vector<int>&vec){
    std::string str;
    for(const auto &digit : vec){
        str += std::to_string(digit);
    }
    return str;
}

std::vector<char> base_1(int num){
    std::vector<char> result;
    char ver_bar = '|';
    for(int i = 0; i < num; i++){
        result.push_back(ver_bar);
    }
    return result;
}

std::vector<int> base_natural(int num, int base_num, int base){
    std::vector<int> result;
    if(base_num != 10 && base == 10){
        int dum = 0;
        for(int i = 0; num > 0; i++){
            int digit = num % 10;
            dum += digit * pow(base_num, i);
            num /= 10;
        }
        result.push_back(dum);
    } else {
        while(num >= 1){
            result.push_back(num % base);
            num /= base;
        }
        std::reverse(result.begin(), result.end());
    }
    return result;
};

std::vector<int> base_quotient(int num, int numerator, int denominator){
    std::vector<int> result;
    int base_10 = 10;
    if(numerator == 1){
        result = base_natural(num, base_10, denominator);
        std::reverse(result.begin(), result.end());
    }
    else if(numerator > denominator){
        while(num >= 1){
            result.push_back(num % numerator);
            num /= numerator;
            num *= denominator;
        }
        std::reverse(result.begin(), result.end());
    } else{
        while(num >= 1){
            result.push_back(num % denominator);
            num /= denominator;
            num *= numerator;
        }
    }
    return result;
}

int main(){
    int num, base, base_num, numerator, denominator;
    char number_set;

    std::cout << "*********Base Converter*********\n\n";

    std::cout << "To which number set does your number exclusively belong? [N/Z/Q]\n";
    std::cin >> number_set;

    switch(number_set){
        case 'N':
            std::cout << "Choose a number:\n";
            std::cin >> num;

            std::cout << "Which base are your number?\n";
            std::cin >> base_num;

            std::cout << "Choose a base you want to convert:\n";
            std::cin >> base;

            std::cout << "\n";
            if(base == 1){
                std::vector<char> result = base_1(num);
                for(const auto &digit : result){
                    std::cout << digit;
                }
                std::cout << "\n";
            } else {
                std::vector<int> result = base_natural(num, base_num, base);
                std::string strresult = vector2str(result);
                
                std::cout << "Here's your number in base " << base << ": " << strresult << '\n';
            }
            std::cout << "\n********************************\n";
            break;
        case 'Z':
            std::cout << "This code doesn't suport integer set yet\n";
            break;
        case 'Q':
            std::cout << "Choose a number:\n";
            std::cin >> num;

            std::cout << "Choose a numerator for your base:\n";
            std::cin >> numerator;

            std::cout << "Choose a denominator for your base:\n";
            std::cin >> denominator;

            std::cout << "\n";
            if(denominator == 0){
                std::cout << "You can't divise by zero.";
            }
            else if(numerator == 1){
                std::vector<int> result = base_quotient(num, numerator, denominator);
                std::string strresult = vector2str(result);
                strresult.insert(1, ".");
        
                std::cout << "Here's your number in base " << numerator << "/" << denominator << ": " << strresult << '\n';
            }
            else if(numerator > denominator){
                std::vector<int> result = base_quotient(num, numerator, denominator);
                std::string strresult = vector2str(result);

                std::cout << "Here's your number in base " << numerator << "/" << denominator << ": " << strresult << '\n';
            } else{
                std::vector<int> result = base_quotient(num, numerator, denominator);
                std::string strresult = vector2str(result);
                strresult.insert(1, ".");
        
                std::cout << "Here's your number in base " << numerator << "/" << denominator << ": " << strresult << '\n'; 
            }
            
            std::cout << "\n********************************\n";
            break;
        default:
            std::cout << "Digit a valid number set\n";
    }
    return 0;
}
