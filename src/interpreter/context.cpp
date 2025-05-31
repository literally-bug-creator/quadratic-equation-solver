#include "interpreter/context.hpp"

#include <cstddef>
#include <vector>

#include "interpreter/token_sequence.hpp"

ContextImage::ContextImage( size_t index ): index( index ) {};

Context::Context( std::vector<Token> tokens ): tokens( tokens ) {};

size_t Context::size() const { return tokens.size(); }

bool Context::is_finished() const { return index >= size(); }

const TokenSequenceView Context::get_tokens( size_t length ) const {
    if ( length == DEFAULT_LENGTH ) length = size() - ( index + 1 );
    return make_view( tokens, index, length );
}

void Context::next( size_t length ) { index += length; }

ContextImage Context::dump() { return ContextImage( index ); }

void Context::restore( ContextImage& dump ) { index = dump.index; }
