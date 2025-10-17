#include <iostream>
#include <sstream>
#include <vector>
#include <string>

std::vector<std::string> tokenize(const std::string& input)
{
    std::vector<std::string> tokens;

    std::string token;

    std::istringstream stream(input);

    while (stream >> token){
        tokens.push_back(token);
    }
    return tokens;
}

int main(){
    while(true){
    bool quit = false;
    std::string code = "";
    std::getline(std::cin, code); 
    auto tokens = tokenize(code);

    for(const auto& t: tokens){
        std::cout << t << "\n";
        if(t == "quit"){
            quit = true;
        }
    }
    if(quit){break;}
}
}