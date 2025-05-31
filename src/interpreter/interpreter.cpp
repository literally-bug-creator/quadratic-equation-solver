#include "interpreter/interpreter.hpp"

#include <cctype>

#include "interpreter/context.hpp"
#include "interpreter/token.hpp"

std::vector<Token> tokenize( const std::string& str ) {
    std::vector<Token> tokens( str.size() );

    for ( size_t index = 0; index < str.size(); index++ ) {
        tokens[index] = make_token( std::tolower( str[index] ) );
    }

    return tokens;
}

bool Interpreter::interpret( const std::string& str ) const {
    Context context = Context( tokenize( str ) );

    bool is_float_interpreted;
    bool is_constant_interpreted;

    try {
        if ( const_exp.interpret( context ) ) { return true; }

        is_float_interpreted = float_exp.interpret( context );

    } catch ( ... ) { return false; }

    return is_float_interpreted && context.is_finished();
}
