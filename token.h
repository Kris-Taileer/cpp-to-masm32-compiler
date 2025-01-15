#pragma once
#include <string>

using namespace std;

enum class token_type { //types of tokens in code, gonna write later //DONE!!!
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
    //FLOAT,
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

    SEMICOLON,
    COLON,              // 69
    COMMA,
    POINT,
    QUESTION,
    AMPERSAND,

    LINE_COMMENT,
    NEW,
    DELETE,
    PREPROCESSOR_DIRECTIVE,
    ACCESS_OPERATOR,

};

class token {
private:
    string lexeme;
    token_type type;

public:
    token(const string& lexeme) {
        this ->lexeme = lexeme;
        this ->type = whar_token_type(lexeme);
    }

    token_type whar_token_type(const string& lexeme) { //fuck this shit //yandere dev code be like:

        if (lexeme == "int") {
            return token_type::INT;
        }

        if (lexeme == "(") {
            return token_type::LPAR;
        }

        if (lexeme == ")") {
            return token_type::RPAR;
        }

        if (lexeme == "[") {
            return token_type::LSQR;
        }

        if (lexeme == "]") {
            return token_type::RSQR;
        }

        if (lexeme == "{") {
            return token_type::LBRA;
        }

        if (lexeme == "}") {
            return token_type::LBRA;
        }

        if (lexeme == "double") {
            return token_type::DOUBLE;
        }

        if (lexeme == "bool") {
            return token_type::BOOL;
        }

        if (lexeme == "void") {
            return token_type::VOID;
        }

        if (lexeme == "char") {
            return token_type::CHAR;
        }

        if (lexeme == "auto") {
            return token_type::AUTO;
        }

        //NEDDA FINISH  //yeah, new verb shortcut in english :D
    }

    bool is_string(const string& lexeme) {
        return lexeme.front() == '"' && lexeme.back() == '"';
    }

    bool is_char(const string& lexeme) {
        return lexeme.front() == '\'' && lexeme.back() == '\''; //GOD BLESS C!!
    }

    bool is_integer(const string& lexeme) {
        for (int i = 0; i < lexeme.size(); ++i) {
            if ((lexeme[i] < '0') || (lexeme[i] > '9')) {
                return false;
            }
            return true;
        }
    }
    bool is_double(const string& lexeme) {
        bool flag_point = false;
        for (int i = 0; i < lexeme.size(); ++i) {
            if (lexeme[i] == '.') {
                if (flag_point) {
                    return false;
                } else {
                    flag_point = true;
                }
            }
            if ((lexeme[i] < '0') || (lexeme[i] > '9')) {
                return false;
            }
            return true;
        }
    }

    //bool is_long(const string& lexeme) {
        //for (int i = 0; i < lexeme.size(); ++i) {
            //if ((lexeme[i] < '0') || (lexeme[i] > '9') && (( ? < 2147483647)||( ? > -2147483647))) {
                //return false;
            //}
            //return true;
        //}
    //}


};