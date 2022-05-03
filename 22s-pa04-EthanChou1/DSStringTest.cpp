//
// Created by Ethan Chou on 2/3/2022.
//
#include "catch.hpp"
#include "DSString.h"
TEST_CASE("DSString class", "[DSString]") {

    DSString s[10];
    s[0] = DSString("testDSString");
    s[1] = DSString("a test DSString");
    s[2] = DSString("");
    s[3] = DSString("THIS IS AN UPPERCASE DSString");
    s[4] = DSString("this is an uppercase DSString");
    s[5] = DSString("\n");
    s[6] = DSString("");
    s[7] = DSString("  split  split  split  ");
    s[8] = DSString("                          ");
    s[9] = DSString("testDSString");


    SECTION("c_str function") {
        DSString compare("Test");
        DSString compare2("Testing");
        REQUIRE(strcmp(compare.c_str(), "Test") == 0);
        REQUIRE(strcmp(compare2.c_str(), "Testing") == 0);
        REQUIRE(strcmp(compare2.c_str(), "Nottesting") != 0);
    }


    SECTION("Assigning") {
        DSString test;
        test = "a test DSString";
        REQUIRE(strcmp(test.c_str(), s[1].c_str()) == 0 );
        test = "no";
        REQUIRE(strcmp(test.c_str(), s[1].c_str()) != 0 );
        test = "THIS IS AN UPPERCASE DSString";
        REQUIRE(strcmp(test.c_str(), s[3].c_str()) == 0 );
    }

    SECTION("Addition operator") {
        DSString test("test");
        DSString test2("test2");
        DSString test3;
        test3 = test + test2;
        REQUIRE(strcmp(test3.c_str(), "testtest2") == 0);
        test = "notest";
        test2 = "temp";
        test3 = test + test2;
        REQUIRE(strcmp(test3.c_str(), "notesttemp") == 0);
        test3 = test2 + test;
        REQUIRE(strcmp(test3.c_str(), "tempnotest") == 0);
    }

    SECTION("Comparing") {
        DSString compare("Test");
        DSString test("Test");
        REQUIRE((compare == test) == 1);
        DSString test2("test");
        REQUIRE((compare == test2) == 0);
        REQUIRE((test > test2) == 0);
    }

    SECTION("Length") {
        DSString compare("Test");
        DSString compare2("Testing");
        REQUIRE(compare.getLength() == 4);
        REQUIRE(compare2.getLength() != 4);
        REQUIRE(compare2.getLength() == 7);
    }

    SECTION("[] Operator") {
        DSString compare("Test");
        REQUIRE(compare[1] == 'e');
        REQUIRE(compare[4] == '\0');
        REQUIRE(compare[3] == 't');
    }

    SECTION("Substring function") {
        DSString test("test");
        DSString test2(test.substring(0, 2));
        test = "testing";
        DSString test3(test.substring(0,5));
        test = "temptest";
        DSString test4(test.substring(0,4));
        REQUIRE(strcmp(test2.c_str(), "te") == 0);
        REQUIRE(strcmp(test3.c_str(), "testi") == 0);
        REQUIRE(strcmp(test4.c_str(), "temp") == 0);
    }

    SECTION("Less than operator") {
        DSString compare("Test");
        DSString test("test");
        REQUIRE((compare > test) == 0);
        DSString test2("tast");
        REQUIRE((compare > test2) == 0);
        REQUIRE((test > test2) == 1);
    }

    SECTION("Lower case") {
        DSString test("TEST");
        DSString test2("HELP");
        DSString test3("ME");
        DSString compare("test");
        DSString compare2("help");
        DSString compare3("me");
        test.toLowerCase();
        test2.toLowerCase();
        test3.toLowerCase();
        CHECK(strcmp(test2.c_str(), compare2.c_str()) == 0);
        CHECK(strcmp(test3.c_str(), compare3.c_str()) == 0);
        CHECK(strcmp(test.c_str(), compare.c_str()) == 0);
    }

}