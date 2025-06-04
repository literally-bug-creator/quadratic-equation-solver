#pragma once

#include <string>

enum ErrorCode {
    OK,
    INVALID_INPUT,
    CALCULATION_ERROR,
    SOLUTION_ERROR,
};

struct Error {
    ErrorCode code;
    std::string message;
};

Error make_error( ErrorCode code, const std::string& message );

const ErrorCode& get_error_code( const Error& error );

const std::string& get_error_message( const Error& error );

bool is_ok( const Error& error );
