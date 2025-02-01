#pragma once
#include <string>
#include<iostream>

using namespace std;

enum class token_type { //DONE!!!
    IDENTIFIER,
    INTEGER_CONST,
    DOUBLE_CONST,
    STRING_CONST,
    CHAR_CONST,
    TRUE,
    FALSE,
    CONST, // im alredy exosted of writing this, help me
    UNDEFINED,
    INT,
    DOUBLE,
    BOOL,
    CHAR,
    VOID,
    AUTO,
    STRUCT,
    //  FLOAT, //coming soon!
    //LONG,

    LBRA, // {
    RBRA, // }
    LPAR, // (
    RPAR, // )
    LSQR, // [
    RSQR, // ]
    DO_WHILE,
    WHILE,
    FOR,

    BREAK,
    CONTINUE,
    SWITCH,
    CASE,
    DEFAULT,
    IF,
    ELSE,

    LESS,
    GREATER,
    LESS_EQUAL,
    GREATER_EQUAL,
    EQUAL,
    NOT_EQUAL,
    AND,
    OR,
    EXCLAMATION,

    PLUS,
    MINUS,
    STAR,
    SLASH,
    INC,
    DEC,            //DIC(K)
    ASSIGN, // =
    ADD_ASSIGN,
    SUB_ASSIGN, // -=
    MUL_ASSIGN,
    DIV_ASSIGN, // /=

    FUNCTION,
    RETURN,

    SEMICOLON,        // 69
    COLON,
    COMMA,
    POINT,
    QUESTION,
    AMPERSAND,

    LINE_COMMENT,
    NEW,
    DELETE,
    PREPROCESSOR_DIRECTIVE,
    ACCESS_OPERATOR,
    //FORTRAN,
    ASM

};

class token {
private:
    string lexeme;
    token_type type;

public:
    token(const string& _lexeme) {
        this ->lexeme = _lexeme;
        this ->type = whar_token_type(_lexeme);
    }

    void print() {
        cout << lexeme << " type:" << token_type_to_str(type) << "\n";
    }
public:

    token_type whar_token_type(const string& _lexeme) { //fuck this shit //yandere dev code be like:

        if (_lexeme == "int") {
            return token_type::INT;
        }

        if (_lexeme == "struct") {
            return token_type::STRUCT;
        }

        if (_lexeme == "const") {
            return token_type::CONST;
        }

        if (_lexeme == "(") {
            return token_type::LPAR;
        }

        if (_lexeme == ")") {
            return token_type::RPAR;
        }

        if (_lexeme == "[") {
            return token_type::LSQR;
        }

        if (_lexeme == "]") {
            return token_type::RSQR;
        }

        if (_lexeme == "{") {
            return token_type::LBRA;
        }

        if (_lexeme == "}") {
            return token_type::LBRA;
        }

        if (_lexeme == "double") {
            return token_type::DOUBLE;
        }

        if (_lexeme == "bool") {
            return token_type::BOOL;
        }

        if (_lexeme == "void") {
            return token_type::VOID;
        }

        if (_lexeme == "char") {
            return token_type::CHAR;
        }

        if (_lexeme == "auto") {
            return token_type::AUTO;
        }

        if (_lexeme == "for") {
            return token_type::FOR;
        }

        if (_lexeme == "while") {
            return token_type::WHILE;
        }

        if (_lexeme == "do") {
            return token_type::DO_WHILE;
        }

        if (_lexeme == "break") {
            return token_type::BREAK;
        }

        if (_lexeme == "continue") {
            return token_type::CONTINUE;
        }

        if (_lexeme == "if") {
            return token_type::IF;
        }

        if (_lexeme == "else") {
            return token_type::ELSE;
        }

        if (_lexeme == ">") {
            return token_type::GREATER;
        }

        if (_lexeme == "<") {
            return token_type::LESS;
        }

        if (_lexeme == "<=") {
            return token_type::LESS_EQUAL;
        }

        if (_lexeme == ">=") {
            return token_type::GREATER_EQUAL;
        }

        if (_lexeme == "==") {
            return token_type::EQUAL;
        }

        if (_lexeme == "!=") {
            return token_type::NOT_EQUAL;
        }

        if (_lexeme == "&&") {
            return token_type::AND;
        }

        if (_lexeme == "||") {
            return token_type::OR;
        }

        if (_lexeme == "!") {
            return token_type::EXCLAMATION;
        }

        if (_lexeme == "+") {
            return token_type::PLUS;
        }

        if (_lexeme == "-") {
            return token_type::MINUS;
        }

        if (_lexeme == "*") {
            return token_type::STAR;
        }

        if (_lexeme == "/") {
            return token_type::SLASH;
        }

        if (_lexeme == "++") {
            return token_type::INC;
        }

        if (_lexeme == "--") {
            return token_type::DEC;
        }

        if (_lexeme == "=") {
            return token_type::ASSIGN;
        }

        if (_lexeme == "+=") {
            return token_type::ADD_ASSIGN;
        }

        if (_lexeme == "-=") {
            return token_type::SUB_ASSIGN;
        }

        if (_lexeme == "*=") {
            return token_type::MUL_ASSIGN;
        }

        if (_lexeme == "/=") {
            return token_type::DIV_ASSIGN;
        }

        if (_lexeme == "return") {
            return token_type::RETURN;
        }

        if (_lexeme == "new") {
            return token_type::NEW;
        }

        if (_lexeme == "delete") {
            return token_type::DELETE;
        }

        if (_lexeme == "true") {
            return token_type::TRUE;
        }

        if (_lexeme == "false") {
            return token_type::FALSE;
        }

        if (_lexeme == "switch") {
            return token_type::SWITCH;
        }

        if (_lexeme == "case") {
            return token_type::CASE;
        }

        if (_lexeme == "default") {
            return token_type::DEFAULT;
        }

        if (_lexeme == ";") {
            return token_type::SEMICOLON;
        }

        if (_lexeme == ":") {
            return token_type::COLON;
        }

        if (_lexeme == ",") {
            return token_type::COMMA;
        }

        if (_lexeme == ".") {
            return token_type::POINT;
        }

        if (_lexeme == "?") {
            return token_type::QUESTION;
        }

        if (_lexeme == "::") {
            return token_type::ACCESS_OPERATOR;
        }

        if (_lexeme == "&") {
            return token_type::AMPERSAND;
        }

        if (_lexeme == "//") {
            return token_type::LINE_COMMENT;
        }

        if (_lexeme[0] == '#') {
            return token_type::PREPROCESSOR_DIRECTIVE; //all directives at once
        }

        if (is_integer(_lexeme)) {
            return token_type::INTEGER_CONST;
        }

        if (is_double(_lexeme)) {
            return token_type::DOUBLE_CONST;
        }

        if (is_string(_lexeme)) {
            return token_type::STRING_CONST;
        }

        if (is_char(_lexeme)) {
            return token_type::CHAR_CONST;
        }

        if (_lexeme == "__asm__") {
            return token_type::ASM;
        }

        return token_type :: IDENTIFIER;
        //DONE!!!
    }

    bool is_string(const string& _lexeme) {
        return _lexeme.front() == '"' && _lexeme.back() == '"';
    }

    bool is_char(const string& _lexeme) {
        return _lexeme.front() == '\'' && _lexeme.back() == '\''; //GOD BLESS C!!
    }

    bool is_integer(const string& _lexeme) {
        for (const char i: _lexeme) {
            if ((i < '0') || (i > '9')) {
                return false;
            }

        }
        return true;
    }
    bool is_double(const string& _lexeme) {
        bool point = false;
        for (const char i: _lexeme)
        {
            if (i == '.' && !point)
            {
                point = true;
                continue;
            }
            if (i == '.')
                return false;
            if (i < '0' || i > '9')
                return false;
        }
        return true;

    }

    string token_type_to_str(token_type t) {
        switch (t) {
        case token_type::IDENTIFIER:
            return "Identifier";
        case token_type::INTEGER_CONST:
            return "integer constant";
        case token_type::DOUBLE_CONST:
            return "double constant";
        case token_type::STRING_CONST:
            return "string constant";
        case token_type::CHAR_CONST:
            return "char constant";
        case token_type::TRUE:
            return "true";
        case token_type::FALSE:
            return "false";
        case token_type::CONST:
            return "const";
        case token_type::UNDEFINED:
            return "undefined";
        case token_type::INT:
            return "int";
        case token_type::DOUBLE:
            return "double";
        case token_type::BOOL:
            return "bool";
        case token_type::CHAR:
            return "char";
        case token_type::VOID:
            return "void";
        case token_type::AUTO:
            return "auto";
        case token_type::DO_WHILE:
            return "do while";
        case token_type::WHILE:
            return "while";
        case token_type::FOR:
            return "for";
        case token_type::BREAK:
            return "break";
        case token_type::CONTINUE:
            return "continue";
        case token_type::SWITCH:
            return "switch";
        case token_type::CASE:
            return "case";
        case token_type::DEFAULT:
            return "default";
        case token_type::IF:
            return "if";
        case token_type::ELSE:
            return "else";
        case token_type::LESS:
            return "less";
        case token_type::GREATER:
            return "greater";
        case token_type::LESS_EQUAL:
            return "less and equal";
        case token_type::GREATER_EQUAL:
            return "greater and equal";
        case token_type::EQUAL:
            return "equal";
        case token_type::NOT_EQUAL:
            return "not equal";
        case token_type::AND:
            return "logic and";
        case token_type::OR:
            return "logic or";
        case token_type::EXCLAMATION:
            return "exclamation";
        case token_type::PLUS:
            return "plus";
        case token_type::MINUS:
            return "minus";
        case token_type::STAR:
            return "star";
        case token_type::SLASH:
            return "true";
        case token_type::INC:
            return "inc";
        case token_type::DEC:
            return "dec";
        case token_type::LBRA:
            return "lbra";
        case token_type::RBRA:
            return "rbra";
        case token_type::LPAR:
            return "lpar";
        case token_type::RPAR:
            return "rpar";
        case token_type::LSQR:
            return "lsqr";
        case token_type::RSQR:
            return "rsqr";
        case token_type::ASSIGN:
            return "assign";
        case token_type::ADD_ASSIGN:
            return "add assign";
        case token_type::SUB_ASSIGN:
            return "sun assign";
        case token_type::MUL_ASSIGN:
            return "mul assign";
        case token_type::DIV_ASSIGN:
            return "true";
        case token_type::FUNCTION:
            return "function";
        case token_type::RETURN:
            return "return";
        case token_type::SEMICOLON:
            return "semicolon";
        case token_type::COLON:
            return "colon";
        case token_type::COMMA:
            return "comma";
        case token_type::POINT:
            return "point";
        case token_type::QUESTION:
            return "question";
        case token_type::AMPERSAND:
            return "ampersand";
        case token_type::LINE_COMMENT:
            return "line comment";
        case token_type::NEW:
            return "new";
        case token_type::DELETE:
            return "delete";
        case token_type::PREPROCESSOR_DIRECTIVE:
            return "preprocessor directive";
        case token_type::ACCESS_OPERATOR:
            return "access operator";
        case token_type::STRUCT:
            return "struct";
        case token_type::ASM:
            return "extension";

        default:
            return "";

        }

    }

    //bool is_long(const string& _lexeme) {
        //for (int i = 0; i < _lexeme.size(); ++i) {
            //if ((_lexeme[i] < '0') || (_lexeme[i] > '9') && (( ? < 2147483647)||( ? > -2147483647))) {
                //return false;
            //}
            //return true;
        //}
    //}


};
