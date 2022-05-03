//
// Created by MARK FONTENOT on 9/14/21.
//

/**
 * This file contains some simple tests.
 *
 * DO NOT add the #define CATCH_CONFIG_RUNNER to this file.
 * It is already in catch_setup.cpp
 *
 * Note that you can have more than one cpp file with tests in them.
 * For example, you could have a test file for your DSString and a
 * separate one for your DSVector.
 */

#include "catch.hpp"
#include "DSVector.h"
#include "DSString.h"

TEST_CASE("DSVector class", "[DSVector]") {
    SECTION("resize function") {
        DSVector<int> test(5);
        test.resize();
        REQUIRE(test.getCapacity() == 10);
        test.resize();
        REQUIRE(test.getCapacity() == 20);
        test.resize();
        REQUIRE(test.getCapacity() == 40);
    }
    SECTION("Get Capacity") {
        DSVector<int> test(5);
        test.resize();
        REQUIRE(test.getCapacity() == 10);
        test.resize();
        REQUIRE(test.getCapacity() == 20);
        test.resize();
        REQUIRE(test.getCapacity() == 40);
    }
    SECTION("Get Size") {
        DSVector<int> test(5);
        test.push_back(1);
        test.push_back(2);
        test.push_back(3);
        test.push_back(4);
        test.push_back(5);
        REQUIRE(test.getSize() == 5);
        REQUIRE(test.getSize() != 20);
        test.push_back(5);
        REQUIRE(test.getSize() == 6);
    }
    SECTION("Push Back") {
        DSVector<int> test(10);
        test.push_back(1);
        REQUIRE(test.getSize() == 1);
        test.push_back(2);
        REQUIRE(test.getSize() == 2);
        test.push_back(3);
        REQUIRE(test.getSize() == 3);
    }
    SECTION("Index At") {
        DSVector<int> test(10);
        test.push_back(1);
        test.push_back(2);
        test.push_back(3);
        test.push_back(4);
        test.push_back(5);
        test.push_back(6);
        test.push_back(7);
        REQUIRE(test.indexAt(1) == 2);
        REQUIRE(test.indexAt(2) == 3);
        REQUIRE(test.indexAt(3) == 4);
    }
    SECTION("Remove Index") {
        DSVector<int> test(10);
        test.push_back(1);
        test.push_back(2);
        test.push_back(3);
        test.push_back(4);
        test.push_back(5);
        test.push_back(6);
        test.push_back(7);
        test.removeIndex(1);
        test.removeIndex(3);
        test.removeIndex(5);
        REQUIRE(test.indexAt(1) == 3);
        REQUIRE(test.indexAt(3) != 5);
        REQUIRE((test.getSize() == 7) == 1);
    }
    SECTION("Remove Last") {
        DSVector<int> test(10);
        test.push_back(1);
        test.push_back(2);
        test.push_back(3);
        test.push_back(4);
        test.push_back(5);
        test.push_back(6);
        test.push_back(7);
        test.removeLast();
        REQUIRE(test.indexAt(5) == 6);
        test.removeLast();
        REQUIRE(test.indexAt(4) == 5);
        test.removeLast();
        REQUIRE(test.indexAt(3) == 4);
    }
    SECTION("Sort") {
        DSVector<int> test(10);
        test.push_back(5);
        test.push_back(1);
        test.push_back(2);
        test.push_back(6);
        test.push_back(3);
        test.push_back(4);
        test.push_back(7);
        test.sortVector();
        REQUIRE(test.indexAt(5) == 6);
        REQUIRE(test.indexAt(4) == 5);
        REQUIRE(test.indexAt(3) == 4);
    }
    SECTION("Sort if DSVector contains DSString of numbers") {
        DSVector<DSString> test(10);
        test.push_back("5");
        test.push_back("1");
        test.push_back("2");
        test.push_back("6");
        test.push_back("3");
        test.push_back("4");
        test.push_back("7");
        test.sortVectorDSStringInt();
        REQUIRE(strcmp(test.indexAt(5).c_str(), "6") == 0);
        REQUIRE(strcmp(test.indexAt(4).c_str(), "5") == 0);
        REQUIRE(strcmp(test.indexAt(3).c_str(), "4") == 0);
    }

    SECTION("Iterator testing") {
        DSVector<DSString> test(10);
        test.push_back("1");
        test.push_back("2");
        test.push_back("3");
        test.push_back("4");
        REQUIRE(strcmp(test.iteratorVector().c_str(), "1") == 0);
        REQUIRE(strcmp(test.iteratorVector().c_str(), "2") == 0);
        test.resetIterator();
        REQUIRE(strcmp(test.iteratorVector().c_str(),"1") == 0);
    }
}