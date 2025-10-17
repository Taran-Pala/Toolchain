#include <iostream>
#include <sstream>
#include <vector>
#include <string>
enum class TokenType {
    Identifier,
    Number,
    Keyword,
    Operator,
    Punctuation,
    Unknown
};
struct Token{
    std::string type;
    std::string value;
};


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

bool isKeyword(const std::string w){
    const std::string keywords[] = {"AGAIN", "massive", "50/50"};
    for(const auto& kw : keywords){
        if (w == kw){
            return true;
        }
    }
    return false;
}

Token classifyToken(const std::string& word){
    if(isKeyword(word)) return {word, "keyword"};
    bool isNumber = true;

    for (char c : word){
        if (!isdigit(c))
        {
            isNumber = false;
        }
    }
        
    if(isNumber){
        return {word, "Number"};
    }

    return {word, "Identifier"};
}

int main(){
    while(true){
    bool quit = false;
    std::string code = "";
    std::getline(std::cin, code); 
    auto tokens = tokenize(code);

    for(const auto& t: tokens){
        Token token = classifyToken(t);
        std::cout << "token value: " << token.value <<", token type: " << token.type << "\n";
        if(t == "quit"){
            quit = true;
            break;
        }
    }
    if(quit){break;}
}
}