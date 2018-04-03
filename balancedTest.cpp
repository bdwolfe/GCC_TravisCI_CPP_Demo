#include "balanced.h"

#include <exception>
#include <string>

// This tells Catch to provide a main() - only do this in one cpp file
#define CATCH_CONFIG_MAIN
#include "catch.hpp"



TEST_CASE( "Mismatched types", "[isBalanced]" ) {
	std::string s = "This has ( parens ) in the right order but [ the match is } the wrong type";
    
    REQUIRE( !isBalanced(s) );
}

TEST_CASE( "No parenthesis or braces", "[isBalanced]" ) {
	std::string s = "no parens; should still be balanced";
    
    REQUIRE( isBalanced(s) );
}

TEST_CASE( "Close on different line", "[isBalanced]" ) {
	std::string s = "The match for ( is \n on a different line ), and that is okay";
    
    REQUIRE( isBalanced(s) );
}

TEST_CASE( "Missing close", "[isBalanced]" ) {
	std::string s = "start with some text [ then some more ( foobar ) again { some more nesting } but there is no closing square bracket here";
    
    REQUIRE( !isBalanced(s) );
}

TEST_CASE( "Nested correctly", "[isBalanced]" ) {
	std::string s = "(This file has balanced parenthesis)\n(Even though some are { nested },\nthey are [ still [ balanced ] ]\nand even though they span different lines, that shouldn't matter )";
    
    REQUIRE( isBalanced(s) );
}

