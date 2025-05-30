#pragma once

#include <cstddef>
#include <vector>

#include "token_sequence.hpp"

class ContextImage {
private:
    size_t index;
    friend class Context;

public:
    ContextImage( size_t index );
};

class Context {
private:
    TokenSequenceOwner tokens;
    size_t index = 0;

public:
    Context( std::vector<Token> tokens );

    bool is_finished() const;
    const TokenSequenceView get_tokens( size_t length ) const;
    void next( size_t length );
    ContextImage dump();
    void restore( ContextImage& dump );
};
