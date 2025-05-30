#include "token_sequence.hpp"

#include <stdexcept>

bool TokenSequence::operator==( const TokenSequence& other ) const {
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

TokenSequenceView
make_view( const TokenSequenceOwner& owning, size_t start, size_t length ) {
    if ( start + length > owning.data_.size() )
        throw std::out_of_range( "subview out of range" );

    return TokenSequenceView(
        std::span<const Token>( owning.data_.data() + start, length ) );
}
