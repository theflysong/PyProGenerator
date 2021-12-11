#include "PPGSymbol.h"

namespace ppg {
    PPGSymbol::PPGSymbol() 
        : type(EMPTY), desc(NULL) {
    }
    PPGSymbol::PPGSymbol(std::string name, std::vector<PPGSymbol> members)
        : type(CLAZZ), desc(new ClazzSymbolDesc(name, members)) {
    }
    PPGSymbol::PPGSymbol(std::string name, std::vector<std::string> args)
        : type(FUNC), desc(new FuncSymbolDesc(name, args)){
    }
    PPGSymbol::PPGSymbol(std::string name)
        : type(VAR), desc(new VarSymbolDesc(name)) {
    }
    PPGSymbol::~PPGSymbol() {
        if (this->type != EMPTY) {
            delete this->desc;
        }
    }

    PPGSymbol EmptySymbol;

    std::string PPGSymbol::SymbolDesc::getName() {
        return this->name;
    }

    PPGSymbol::SymbolDesc::SymbolDesc(std::string name) : name(name) {
    }

    bool ClazzSymbolDesc::isVarDesc() {
        return false;
    }   
    bool ClazzSymbolDesc::isFuncDesc() {
        return false;
    }   
    bool ClazzSymbolDesc::isClazzDesc() {
        return true;
    }   
    std::vector<PPGSymbol> ClazzSymbolDesc::getMembers() {
        return this->memberList;
    }  
    PPGSymbol ClazzSymbolDesc::lookupMember(std::string name) {
        for (auto mem : memberList) {
            if (mem.desc->getName() == name) {
                return mem;
            }
        }
        return EmptySymbol;
    }    
    std::vector<std::string> ClazzSymbolDesc::getArgs() {
        return std::vector<std::string>{};
    }
    ClazzSymbolDesc::ClazzSymbolDesc(std::string name, std::vector<PPGSymbol> members) 
        : PPGSymbol::SymbolDesc(name), memberList(members) {
    }

    bool FuncSymbolDesc::isVarDesc() {
        return false;
    }   
    bool FuncSymbolDesc::isFuncDesc() {
        return true;
    }   
    bool FuncSymbolDesc::isClazzDesc() {
        return false;
    }   
    std::vector<PPGSymbol> FuncSymbolDesc::getMembers() {
        return std::vector<PPGSymbol>{};
    }  
    PPGSymbol FuncSymbolDesc::lookupMember(std::string name) {
        return EmptySymbol;
    }    
    std::vector<std::string> FuncSymbolDesc::getArgs() {
        return argList;
    }
    FuncSymbolDesc::FuncSymbolDesc(std::string name, std::vector<std::string> args) 
        : PPGSymbol::SymbolDesc(name), argList(args) {
    }

    bool VarSymbolDesc::isVarDesc() {
        return true;
    }   
    bool VarSymbolDesc::isFuncDesc() {
        return false;
    }   
    bool VarSymbolDesc::isClazzDesc() {
        return false;
    }   
    std::vector<PPGSymbol> VarSymbolDesc::getMembers() {
        return std::vector<PPGSymbol>{};
    }  
    PPGSymbol VarSymbolDesc::lookupMember(std::string name) {
        return EmptySymbol;
    }    
    std::vector<std::string> VarSymbolDesc::getArgs() {
        return std::vector<std::string>{};
    }
    VarSymbolDesc::VarSymbolDesc(std::string name)
        : PPGSymbol::SymbolDesc(name) {
    }
}