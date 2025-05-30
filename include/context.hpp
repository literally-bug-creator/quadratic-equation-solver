#pragma once

#include <cstddef>
#include <vector>

#include "token_sequence.hpp"

class Context {
private:
    TokenSequenceOwner tokens;
    size_t index = 0;
    std::vector<size_t> history;

public:
    Context( std::vector<Token> tokens );

    bool is_finished() const;
    const TokenSequenceView get_tokens( size_t length ) const;
    void next( size_t length );
    void dump();
    void rollback();
};
