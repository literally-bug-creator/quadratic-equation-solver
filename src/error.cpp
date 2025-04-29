#include "../include/error.h"

ErrorCode get_error_code( const Error& error ) { return error.code; }

std::string get_error_message( const Error& error ) { return error.message; }
