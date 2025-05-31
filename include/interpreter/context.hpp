#pragma once

#include <cstddef>

#include "token_sequence.hpp"

const size_t DEFAULT_LENGTH = 0;

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

    size_t size() const;
    ContextImage dump();
    void restore( ContextImage& dump );
    bool is_finished() const;
    void next( size_t length );
    const TokenSequenceView get_tokens( size_t length = DEFAULT_LENGTH ) const;
};
