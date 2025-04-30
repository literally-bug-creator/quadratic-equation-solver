#include "../include/error.h"

Error make_error( const ErrorCode code, const std::string& message ) {
    return Error( code, message );
}

ErrorCode get_error_code( const Error& error ) { return error.code; }

std::string get_error_message( const Error& error ) { return error.message; }
