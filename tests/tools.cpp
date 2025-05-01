#include <random>

#include "../include/error.h"
#include "../include/number.h"
#include "../include/number_kit.h"


const int DEFAULT_MIN_INT = 0;
const int DEFAULT_MIN_NEG_INT = -10000;
const int DEFAULT_MAX_INT = 100;
const int RAND_TESTS_AMOUNT = 10000;
const int ERROR_CODES_AMOUNT = 4;

inline std::string random_string( size_t length ) {
    const std::string chars = "abcdefghijklmnopqrstuvwxyz"
                              "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                              "0123456789";

    std::random_device rd;
    std::mt19937 gen( rd() );
    std::uniform_int_distribution<> dist( 0, chars.size() - 1 );

    std::string result;
    result.reserve( length );
    for ( size_t i = 0; i < length; ++i ) {
        result += chars[dist( gen )];
    }

    return result;
}

inline int random_int( int min, int max ) {
    std::random_device rd;
    std::mt19937 gen( rd() );
    std::uniform_int_distribution<> dist( min, max );

    return dist( gen );
}

inline double random_double( double min, double max ) {
    static std::random_device rd;
    static std::mt19937 gen( rd() );
    std::uniform_real_distribution<double> dist( min, max );
    return dist( gen );
}

inline ErrorCode random_error_code() {
    static std::random_device rd;
    static std::mt19937 gen( rd() );
    std::uniform_int_distribution<int> dist( 0, ERROR_CODES_AMOUNT - 1 );
    return static_cast<ErrorCode>( dist( gen ) );
}

inline Error random_error() {
    std::string msg = random_string( DEFAULT_MAX_INT );
    ErrorCode code = random_error_code();
    return make_error( code, msg );
}

inline Number random_number(){
    double value = random_double(DEFAULT_MIN_NEG_INT, DEFAULT_MAX_INT);
    return make_number(value);
}

inline NumberKit random_number_kit(){
    Number a = random_number();
    Number b = random_number();
    Number c = random_number();

    return make_number_kit(a, b, c);
}
