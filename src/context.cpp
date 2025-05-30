#include "context.hpp"

#include <cstddef>
#include <stdexcept>
#include <vector>

#include "token_sequence.hpp"

Context::Context( std::vector<Token> tokens ): tokens( tokens ) {};

bool Context::is_finished() const { return index >= tokens.size(); }

const TokenSequenceView Context::get_tokens( size_t length ) const {
    return make_view( tokens, index, length );
}

void Context::next( size_t length ) { index += length; }

void Context::dump() { history.push_back( index ); }

void Context::rollback() {
    if ( history.empty() ) throw std::runtime_error( "" );
    index = history.back();
}
