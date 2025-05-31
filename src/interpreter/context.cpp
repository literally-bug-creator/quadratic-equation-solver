#include "interpreter/context.hpp"

#include <cstddef>
#include <stdexcept>
#include <vector>

Token make_token( char c ) { return Token{ .value = c }; }

char get_value( const Token& token ) { return token.value; }

size_t size( const Token& token ) { return sizeof( get_value( token ) ); }

bool is_equal( const Token& left, const Token& right ) {
    return get_value( left ) == get_value( right );
}

bool TokenSequence::operator==( const TokenSequence& other ) const {
    return equals( other );
}

bool TokenSequence::operator==( const Token& other ) const {
    return equals( other );
}

TokenSequenceView::TokenSequenceView( std::span<const Token> view ):
    view_( view ) {}

size_t TokenSequenceView::size() const { return view_.size(); }

Token TokenSequenceView::at( size_t index ) const {
    if ( index >= view_.size() )
        throw std::out_of_range( "subview out of range" );

    return view_[index];
}

bool TokenSequenceView::equals( const TokenSequence& other ) const {
    if ( size() != other.size() ) return false;

    for ( size_t index = 0; index < size(); index++ ) {
        if ( !is_equal( at( index ), other.at( index ) ) ) return false;
    }

    return true;
}

bool TokenSequenceView::equals( const Token& token ) const {
    if ( size() != ::size( token ) ) return false;
    return is_equal( at( 0 ), token );
}

TokenSequenceOwner::TokenSequenceOwner( std::vector<Token> tokens ):
    data_( std::move( tokens ) ) {}

size_t TokenSequenceOwner::size() const { return data_.size(); }

Token TokenSequenceOwner::at( size_t index ) const { return data_.at( index ); }

bool TokenSequenceOwner::equals( const TokenSequence& other ) const {
    if ( size() != other.size() ) return false;

    for ( size_t i = 0; i < size(); i++ ) {
        if ( !is_equal( at( i ), other.at( i ) ) ) return false;
    }

    return true;
}

bool TokenSequenceOwner::equals( const Token& token ) const {
    if ( size() != ::size( token ) ) return false;
    return is_equal( at( 0 ), token );
}

TokenSequenceView
make_view( const TokenSequenceOwner& owning, size_t start, size_t length ) {
    if ( start + length > owning.data_.size() )
        throw std::out_of_range( "subview out of range" );

    return TokenSequenceView(
        std::span<const Token>( owning.data_.data() + start, length ) );
}

ContextImage::ContextImage( size_t index ): index( index ) {};

Context::Context( std::vector<Token> tokens ): tokens( tokens ) {};

size_t Context::size() const { return tokens.size(); }

bool Context::is_finished() const { return index >= size(); }

const TokenSequenceView Context::get_tokens( size_t length ) const {
    if ( length == DEFAULT_LENGTH ) length = size() - ( index + 1 );
    return make_view( tokens, index, length );
}

size_t Context::get_tokens_amount() const { return size() - ( index + 1 ); };

void Context::next( size_t length ) { index += length; }

ContextImage Context::dump() { return ContextImage( index ); }

void Context::restore( ContextImage& dump ) { index = dump.index; }
