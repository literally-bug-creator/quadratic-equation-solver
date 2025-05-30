#pragma once

#include <cstddef>
#include <span>
#include <vector>

#include "token.hpp"

class TokenSequence {
public:
    virtual ~TokenSequence() = default;

    virtual size_t size() const = 0;
    virtual Token at( size_t index ) const = 0;
    virtual bool equals( const TokenSequence& other ) const = 0;
    virtual bool equals( const Token& other ) const = 0;

    bool operator==( const TokenSequence& other ) const;
    bool operator==( const Token& other ) const;
};

class TokenSequenceView : public TokenSequence {
public:
    explicit TokenSequenceView( std::span<const Token> view );

    size_t size() const override;
    Token at( size_t index ) const override;
    bool equals( const TokenSequence& other ) const override;
    bool equals( const Token& token ) const override;

private:
    std::span<const Token> view_;
};

class TokenSequenceOwner : public TokenSequence {
public:
    explicit TokenSequenceOwner( std::vector<Token> tokens );

    size_t size() const override;
    Token at( size_t index ) const override;
    bool equals( const TokenSequence& other ) const override;
    bool equals( const Token& token ) const override;

private:
    std::vector<Token> data_;

    friend TokenSequenceView
    make_view( const TokenSequenceOwner&, size_t, size_t );
};
