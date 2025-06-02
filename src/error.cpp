#include "error.hpp"

Error make_error( ErrorCode code, const std::string& message ) {
    return Error{ code, message };
}

const ErrorCode& get_error_code( const Error& error ) { return error.code; }

const std::string& get_error_message( const Error& error ) {
    return error.message;
}

bool is_ok( const Error& error ) {
    return get_error_code( error ) == ErrorCode::OK;
}
