#include "interpreter/interpreter.hpp"

std::vector<Token> tokenize( const std::string& str ) {
    std::vector<Token> tokens( str.size() );

    for ( size_t index = 0; index < str.size(); index++ ) {
        tokens[index] = make_token( std::tolower( str[index] ) );
    }

    return tokens;
}

bool Interpreter::interpret( const std::string& str ) const {
    Context context = Context( tokenize( str ) );

    if ( const_exp.interpret( context ) ) { return true; }

    return float_exp.interpret( context ) && context.is_finished();
}
