#pragma once

#include <string>
#include <vector>

namespace ppg {
    class PPGSymbol {
    public:
        enum SymbolTy {
            CLAZZ,
            FUNC,
            VAR,
            EMPTY
        };
        class SymbolDesc {
            std::string name;
        public:
            virtual bool isVarDesc() = 0;   
            virtual bool isFuncDesc() = 0;   
            virtual bool isClazzDesc() = 0;   
            virtual std::string getName();   
            virtual std::vector<PPGSymbol> getMembers() = 0;   
            virtual PPGSymbol lookupMember(std::string name) = 0;   
            virtual std::vector<std::string> getArgs() = 0;
            SymbolDesc(std::string name);
        };
        SymbolTy type;
        SymbolDesc *desc;
        PPGSymbol();
        PPGSymbol(std::string name, std::vector<PPGSymbol> members);
        PPGSymbol(std::string name, std::vector<std::string> args);
        PPGSymbol(std::string name);
        ~PPGSymbol();
    };

    extern PPGSymbol EmptySymbol;

    class ClazzSymbolDesc : public PPGSymbol::SymbolDesc {
        std::vector<PPGSymbol> memberList;
    public:
        virtual bool isVarDesc() override final;   
        virtual bool isFuncDesc() override final;   
        virtual bool isClazzDesc() override final;   
        virtual std::vector<PPGSymbol> getMembers() override final;  
        virtual PPGSymbol lookupMember(std::string name) override final;    
        virtual std::vector<std::string> getArgs() override final;
        ClazzSymbolDesc(std::string name, std::vector<PPGSymbol> members);
    };
    
    class FuncSymbolDesc : public PPGSymbol::SymbolDesc {
        std::vector<std::string> argList;
    public:
        virtual bool isVarDesc() override final;   
        virtual bool isFuncDesc() override final;   
        virtual bool isClazzDesc() override final;   
        virtual std::vector<PPGSymbol> getMembers() override final;  
        virtual PPGSymbol lookupMember(std::string name) override final;      
        virtual std::vector<std::string> getArgs() override final;
        FuncSymbolDesc(std::string name, std::vector<std::string> args);
    };
    
    class VarSymbolDesc : public PPGSymbol::SymbolDesc {
    public:
        virtual bool isVarDesc() override final;   
        virtual bool isFuncDesc() override final;   
        virtual bool isClazzDesc() override final;   
        virtual std::vector<PPGSymbol> getMembers() override final; 
        virtual PPGSymbol lookupMember(std::string name) override final;       
        virtual std::vector<std::string> getArgs() override final;
        VarSymbolDesc(std::string name);
    };
}