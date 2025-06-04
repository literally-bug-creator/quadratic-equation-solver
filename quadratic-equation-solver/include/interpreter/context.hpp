#pragma once

#include <cstddef>
#include <span>
#include <vector>

struct Token {
    char value;
};

Token make_token( char c );
size_t size( const Token& token );
bool is_equal( const Token& left, const Token& right );

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
    bool equals( const Token& other ) const override;

private:
    std::span<const Token> view_;
};

class TokenSequenceOwner : public TokenSequence {
public:
    explicit TokenSequenceOwner( std::vector<Token> tokens );
    size_t size() const override;
    Token at( size_t index ) const override;
    bool equals( const TokenSequence& other ) const override;
    bool equals( const Token& other ) const override;

private:
    std::vector<Token> data_;

    friend TokenSequenceView
    make_view( const TokenSequenceOwner&, size_t, size_t );
};

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
    size_t get_tokens_amount() const;
    ContextImage dump();
    void restore( ContextImage& dump );
    bool is_finished() const;
    void next( size_t length );
    const TokenSequenceView get_tokens( size_t length = DEFAULT_LENGTH ) const;
};
