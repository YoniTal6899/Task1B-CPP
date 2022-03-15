/**
 * An example of how to write unit tests.
 * Use this as a basis to build a more complete Test.cpp file.
 * 
 * IMPORTANT: Please write more tests - the tests here are only for example and are not complete.
 *
 * AUTHORS: Yonatan Tal 314666611
 * 
 * Date: 2022-03
 */

#include "doctest.h"
#include "mat.hpp"
using namespace ariel;

#include <string>
#include <algorithm>
using namespace std;

/**
 * Returns the input string without the whitespace characters: space, newline and tab.
 * Requires std=c++2a.
 */
string nospaces(string input) {
	std::erase(input, ' ');
	std::erase(input, '\t');
	std::erase(input, '\n');
	std::erase(input, '\r');
	return input;
}


TEST_CASE("Good input") {
	CHECK(nospaces(mat(9, 7, '@', '-')) == nospaces("@@@@@@@@@\n"
													 "@-------@\n"
													 "@-@@@@@-@\n"
													 "@-@---@-@\n"
													 "@-@@@@@-@\n"
													 "@-------@\n"
													 "@@@@@@@@@"));
    CHECK(nospaces(mat(3,3,'!','^'))== nospaces("!!!\n"
                                                "!^!\n"
                                                "!!!"));
    CHECK(nospaces(mat(3,5,'$','%'))== nospaces("$$$\n"
                                                "$%$\n"
                                                "$%$\n"
                                                "$%$\n"
                                                "$$$"));
    CHECK(nospaces(mat(5,3,'#','*'))==nospaces("#####\n"
                                               "#***#\n"
                                               "#####"));
    CHECK(nospaces(mat(7,1,'!','@'))==nospaces("!!!!!!!"));
    CHECK(nospaces(mat(1,7,'!','@'))==nospaces("!\n"
                                               "!\n"
                                               "!\n"
                                               "!\n"
                                               "!\n"
                                               "!\n"
                                               "!"));
    CHECK(nospaces(mat(1,1,'!','#'))== nospaces("!"));
    CHECK(nospaces(mat(1,1,'!','%'))== nospaces("!"));
    CHECK(nospaces(mat(5,5,'~','^'))== nospaces("~~~~~\n"
                                                "~^^^~\n"
                                                "~^~^~\n"
                                                "~^^^~\n"
                                                "~~~~~"));
    CHECK(nospaces(mat(7,3,'!','!'))== nospaces("!!!!!!!\n"
                                                "!!!!!!!\n"
                                                "!!!!!!!"));
	/* Add more test here */
}

TEST_CASE("Bad input") {
    CHECK_THROWS(mat(10, 5, '$', '%'));
    CHECK_THROWS(mat(2, 5, '$', '%'));
    CHECK_THROWS(mat(1, 4, '$', '%'));
    CHECK_THROWS(mat(5, 2, '$', '%'));
    CHECK_THROWS(mat(6, 6, '$', '%'));
    CHECK_THROWS(mat(0, 5, '$', '%'));
    CHECK_THROWS(mat(0, 2, '$', '%'));
    CHECK_THROWS(mat(-1, 5, '$', '%'));
    CHECK_THROWS(mat(7, -5, '$', '%'));
    CHECK_THROWS(mat(-4, 5, '$', '%'));
    /* Add more test here */
}


/* Add more test cases here */
