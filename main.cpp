#include <iostream>
#include <vector>
#include "./GrammarParser/GrammarParser.h"
#include "./GrammarParser/Token.h"
#include "nfa-builder.h"

int main() {
    GrammarParser grammarParser;
    // Read and parse grammar file
    std::vector<Token *> tokens = grammarParser.getTokens("lexical_grammar.txt");
    for(auto &token : tokens) {
        std::cout << token->getType() << " " << token->getPriority()<< std::endl;
        for(auto& regexChar : token->getPostfixRegex()) {
            std::cout << regexChar->c << "(" << regexChar->cType << ")" << " ";
        }
        std:: cout << std::endl;
    }

    NFABuilder builder;
    NFA nfa = builder.build(tokens);

    return 0;
}

