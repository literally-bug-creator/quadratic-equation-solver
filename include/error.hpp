#pragma once

#include <string>

enum ErrorCode {
    OK,
    INVALID_INPUT,
    CALCULATION_ERROR,
    SOLUTION_ERROR,
};

struct Error {
    const ErrorCode code;
    const std::string message;

    Error( const ErrorCode code, const std::string& message ):
        code( code ), message( message ) {}
};

Error make_error( const ErrorCode code, const std::string& message );

ErrorCode get_error_code( const Error& error );

std::string get_error_message( const Error& error );

bool is_ok( const Error& error );
