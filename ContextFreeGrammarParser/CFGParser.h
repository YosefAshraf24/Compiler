#ifndef COMPILER_CFGPARSER_H
#define COMPILER_CFGPARSER_H
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <set>

enum SymbolType {
    TERMINAL, NON_TERMINAL, START, EPSILON
};

struct Symbol {
    std::string name;
    SymbolType type;

    Symbol() {
        name = "";
        type = NON_TERMINAL;
    }

    Symbol(std::string symbolName, SymbolType symbolType) {
        name = symbolName;
        type = symbolType;
    }

    bool operator<(const Symbol &x) const {
        return name < x.name;
    }

    bool operator==(const Symbol &rhs) const {
        return name == rhs.name && (type == rhs.type || (type == START && rhs.type == NON_TERMINAL));
    }

    bool operator!=(const Symbol &rhs) const {
        return name != rhs.name || (type != rhs.type);
    }
};

struct Production {
    std::vector<Symbol> productionSymbols;

    std::string toString() {
        std::string string;
        for (int i = 0; i < productionSymbols.size(); i++) {
            string = string + productionSymbols[i].name + ((i == productionSymbols.size() - 1) ? "" : " ");
        }
        return string;
    }

    void print() {
        std::cout << "current productionSymbols  ";
        for (Symbol symbol : productionSymbols) {
            std::cout << symbol.name << "  type  " << symbol.type << "  ";
        }
        std::cout << std::endl;
    }
};

class CFGParser {
public:
    std::map<Symbol, std::vector<Production>> getRules(std::string grammarFilePath);
    void resolveRule(std::string rule);
    std::vector<Production> rhsToProductions(std::string rhs);
    void eliminateLeftRecursion();
    void eliminateLeftFactoring();

private:
    std::string trim(std::string str, std::string whitespace);
    std::vector<std::string> split(std::string str, std::string delimiter);
};


#endif //COMPILER_CFGPARSER_H
