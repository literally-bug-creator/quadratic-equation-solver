#include "interpreter/context.hpp"

#include <cstddef>
#include <vector>

#include "interpreter/token_sequence.hpp"

ContextImage::ContextImage( size_t index ): index( index ) {}

Context::Context( std::vector<Token> tokens ): tokens( tokens ) {};

bool Context::is_finished() const { return index >= tokens.size(); }

const TokenSequenceView Context::get_tokens( size_t length ) const {
    return make_view( tokens, index, length );
}

void Context::next( size_t length ) { index += length; }

ContextImage Context::dump() { return ContextImage( index ); }

void Context::restore( ContextImage& dump ) { index = dump.index; }
