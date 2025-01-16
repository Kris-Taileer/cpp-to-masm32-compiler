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

        if (lexeme == "const") {
            return token_type::CONST;
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

        if (lexeme == "for") {
            return token_type::FOR;
        }

        if (lexeme == "while") {
            return token_type::WHILE;
        }

        if (lexeme == "do") {
            return token_type::DO_WHILE;
        }

        if (lexeme == "break") {
            return token_type::BREAK;
        }

        if (lexeme == "continue") {
            return token_type::CONTINUE;
        }

        if (lexeme == "if") {
            return token_type::IF;
        }

        if (lexeme == "else") {
            return token_type::ELSE;
        }

        if (lexeme == ">") {
            return token_type::GREATER;
        }

        if (lexeme == "<") {
            return token_type::LESS;
        }

        if (lexeme == "<=") {
            return token_type::LESS_EQUAL;
        }

        if (lexeme == ">=") {
            return token_type::GREATER_EQUAL;
        }

        if (lexeme == "==") {
            return token_type::EQUAL;
        }

        if (lexeme == "!=") {
            return token_type::NOT_EQUAL;
        }

        if (lexeme == "&&") {
            return token_type::AND;
        }

        if (lexeme == "||") {
            return token_type::OR;
        }

        if (lexeme == "!") {
            return token_type::EXCLAMATION;
        }

        if (lexeme == "+") {
            return token_type::PLUS;
        }

        if (lexeme == "-") {
            return token_type::MINUS;
        }

        if (lexeme == "*") {
            return token_type::STAR;
        }

        if (lexeme == "/") {
            return token_type::SLASH;
        }

        if (lexeme == "++") {
            return token_type::INC;
        }

        if (lexeme == "--") {
            return token_type::DEC;
        }

        if (lexeme == "=") {
            return token_type::ASSIGN;
        }

        if (lexeme == "+=") {
            return token_type::ADD_ASSIGN;
        }

        if (lexeme == "-=") {
            return token_type::SUB_ASSIGN;
        }

        if (lexeme == "*=") {
            return token_type::MUL_ASSIGN;
        }

        if (lexeme == "/=") {
            return token_type::DIV_ASSIGN;
        }

        if (lexeme == "return") {
            return token_type::RETURN;
        }

        if (lexeme == "new") {
            return token_type::NEW;
        }

        if (lexeme == "delete") {
            return token_type::DELETE;
        }

        if (lexeme == "true") {
            return token_type::TRUE;
        }

        if (lexeme == "false") {
            return token_type::FALSE;
        }

        if (lexeme == "switch") {
            return token_type::SWITCH;
        }

        if (lexeme == "case") {
            return token_type::CASE;
        }

        if (lexeme == "default") {
            return token_type::DEFAULT;
        }

        if (lexeme == ";") {
            return token_type::SEMICOLON;
        }

        if (lexeme == ":") {
            return token_type::COLON;
        }

        if (lexeme == ",") {
            return token_type::COMMA;
        }

        if (lexeme == ".") {
            return token_type::POINT;
        }

        if (lexeme == "?") {
            return token_type::QUESTION;
        }

        if (lexeme == "::") {
            return token_type::ACCESS_OPERATOR;
        }

        if (lexeme == "&") {
            return token_type::AMPERSAND;
        }

        if (lexeme == "//") {
            return token_type::LINE_COMMENT;
        }

        if (lexeme[0] == '#') {
            return token_type::PREPROCESSOR_DIRECTIVE;
        }

        if (is_integer(lexeme)) {
            return token_type::INTEGER_CONST;
        }

        if (is_double(lexeme)) {
            return token_type::DOUBLE_CONST;
        }

        if (is_string(lexeme)) {
            return token_type::STRING_CONST;
        }

        if (is_char(lexeme)) {
            return token_type::CHAR_CONST;
        }

        return token_type :: IDENTIFIER;
        //DONE!!!
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
