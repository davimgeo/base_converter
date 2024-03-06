#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

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

int main(){
    int num, base, base_num;

    std::cout << "Choose a number: " << '\n';
    std::cin >> num;

    std::cout << "Which base are your number? ";
    std::cin >> base_num;

    std::cout << "Choose a base you want to convert: " << '\n';
    std::cin >> base;
    
    std::vector<int> result = base_natural(num, base_num, base);

    for(const auto &digit : result){
        std::cout << digit;
    }
    return 0;
}
