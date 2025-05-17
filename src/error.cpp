#include "error.hpp"

#include <any>
#include <functional>
#include <string>

using Selector = std::function<std::any( int selector )>;

Error make_error( const ErrorCode code, const std::string& message ) {
    return Error( code, message );
}

Selector get_selector( Error e ) {
    std::function<std::any( int index )> field = [e]( int index ) -> std::any {
        if ( index == 0 ) {
            return std::any( e.first );
        } else {
            return std::any( e.second );
        }
    };

    return field;
}

ErrorCode get_error_code( const Error& error ) {
    Selector selector = get_selector( error );
    return std::any_cast<ErrorCode>( selector( 0 ) );
}

const std::string get_error_message( const Error& error ) {
    Selector selector = get_selector( error );
    return std::any_cast<std::string>( selector( 1 ) );
}

bool is_ok( const Error& error ) {
    ErrorCode code = get_error_code( error );
    return code == ErrorCode::OK;
}
