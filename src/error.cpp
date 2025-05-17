#include "error.hpp"

#include <string>

#include "selector.hpp"

Selector get_selector( Error error ) {
    std::function<std::any( int index )> field =
        [error]( int index ) -> std::any {
        if ( index == 0 ) {
            return std::any( error.first );
        } else {
            return std::any( error.second );
        }
    };

    return field;
}

Error make_error( const ErrorCode code, const std::string& message ) {
    return Error( code, message );
}

ErrorCode get_error_code( const Error& error ) {
    return std::any_cast<ErrorCode>( get_selector( error )( 0 ) );
}

const std::string get_error_message( const Error& error ) {
    return std::any_cast<std::string>( get_selector( error )( 1 ) );
}

bool is_ok( const Error& error ) {
    ErrorCode code = get_error_code( error );
    return code == ErrorCode::OK;
}
