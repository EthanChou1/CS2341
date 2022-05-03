//
// Created by ethan on 3/22/2022.
//
#include "catch.hpp"
#include "DSLinkedList.h"
#include "DSStack.h"
#include "DSVector.h"
#include "DSString.h"
TEST_CASE("LinkedList class"){
    DSLinkedList<int> list1;
    DSLinkedList<int> list2;
    DSLinkedList<int> list3(8);
    DSLinkedList<DSString> list4;

    DSString s[11];
    s[0] = DSString("testString");
    s[1] = DSString("a test string");
    s[2] = DSString("");
    s[3] = DSString("THIS IS AN UPPERCASE STRING");
    s[4] = DSString("this is an uppercase string");
    s[5] = DSString("\n");
    s[6] = DSString("");
    s[7] = DSString("  split  split  split  ");
    s[8] = DSString("                          ");
    s[9] = DSString("testString");
    s[10] = DSString("yo gabba gabba");
    for (auto & i : s) {
        list4.add(i);
    }

    for (int i = 0; i < 10; i++) {
        list1.add(i);
    }
    DSLinkedList<int> list5;
    DSLinkedList<DSString> list6;
    SECTION("Size function") {
        REQUIRE(list1.getSize() == 10);
        REQUIRE(list2.getSize() == 0);
        REQUIRE(list3.getSize() == 1);
        REQUIRE(list4.getSize() == 11);
    }


    SECTION("Get function") {
        REQUIRE(list1.get(2) == 2);
        REQUIRE(list1.get(8) == list3.get(0));
        REQUIRE((list4.get(3) == "THIS IS AN UPPERCASE STRING") == 1);
    }

    SECTION("Assignment operator") {

        list5 = list1;
        REQUIRE(list1.get(2) == list5.get(2));
        REQUIRE(list1.get(2) != list5.get(5));
        list6 = list4;
        REQUIRE((list4.get(3) == list6.get(3)) == 1);
        REQUIRE((list4.get(3) == list6.get(7)) != 1);
    }

    SECTION("Add function") {
        list1.add(11);
        REQUIRE(list1.getSize() == 11);
        REQUIRE(list1.get(10) == 11);
        DSString str("test add function");
        list4.add(str);
        REQUIRE(list4.getSize() == 12);
        REQUIRE((list4.get(11) == "test add function") == 1);
    }

    SECTION("Add to head function") {
        list6 = list4;
        list1.addToHead(3);
        REQUIRE(list1.getSize() == 11);
        REQUIRE(list1.get(0) == 3);
        DSString str = "THIS IS AN UPPERCASE STRING";
        list4.addToHead(str);
        REQUIRE(list4.getSize() == 12);
        REQUIRE((list4.get(0) == list6.get(3)) == 1);
        REQUIRE((list4.get(10) == "yo gabba gabba") == 0);
    }

    SECTION("Remove function") {
        list1.remove(0);
        REQUIRE(list1.getSize() == 9);
        REQUIRE(list1.get(0) == 1);
        list4.remove(0);
        REQUIRE(list4.getSize() == 10);
        list4.remove(0);
        list4.remove(0);
        REQUIRE((list4.get(0) == "THIS IS AN UPPERCASE STRING") == 1);
    }


    SECTION("ClearALl function") {
        list1.clearAll();
        REQUIRE(list1.getSize() == 0);
        list4.clearAll();
        REQUIRE(list4.getSize() == 0);
        list1.add(0);
        REQUIRE(list1.getSize() == 1);
    }

    SECTION("Contains function") {
        REQUIRE(list1.contains(1) == true);
        REQUIRE(list1.contains(99) == false);
        REQUIRE(list1.contains(2) == true);
    }

}

TEST_CASE("Stack class"){
    DSStack<int> stackOne;
    DSStack<int> stackTwo;
    DSStack<DSString> stackThree;
    DSStack<DSString> stackFour;

    for (int i = 0; i < 10; i++) {
        stackOne.push(i);
    }

    SECTION("Push function") {
        stackTwo.push(5);
        stackTwo.push(6);
        stackTwo.push(7);
        stackTwo.push(8);
        REQUIRE(stackTwo.getSize() == 4);
        REQUIRE(stackTwo.empty() == false);
        stackTwo.push(9);
        REQUIRE(stackTwo.getSize() == 5);
    }

    SECTION("Remove function") {
        stackTwo.push(5);
        stackTwo.push(6);
        stackTwo.push(7);
        stackTwo.push(8);
        REQUIRE(stackTwo.getSize() == 4);
        REQUIRE(stackTwo.empty() == false);
        stackTwo.push(9);
        REQUIRE(stackTwo.getSize() == 5);
    }

    SECTION("Empty function") {
        REQUIRE(stackOne.empty() == false);
        stackTwo.push(5);
        REQUIRE(stackTwo.empty() == false);
        REQUIRE(stackThree.empty() == true);
        REQUIRE(stackFour.empty() == true);
    }

    SECTION("Pop function") {
        CHECK(stackOne.pop() == 9);
        CHECK(stackOne.getSize() == 9);
        CHECK(stackOne.pop() == 8);
        CHECK(stackOne.pop() == 7);
        CHECK(stackOne.getSize() == 7);
    }

    SECTION("Get At Index function") {
        REQUIRE(stackOne.getAtIndex(0) == 0);
        REQUIRE(stackOne.getAtIndex(1) == 1);
        REQUIRE(stackOne.getAtIndex(2) == 2);

    }

    SECTION("See Top item function") {
        REQUIRE(stackOne.seeTop() == 9);
        stackTwo.push(5);
        stackTwo.push(6);
        stackTwo.push(7);
        stackTwo.push(8);
        REQUIRE(stackTwo.seeTop() == 8);
        stackOne.push(8);
        REQUIRE(stackOne.seeTop() == 8);

    }

    SECTION("GetSize function") {
        REQUIRE(stackOne.getSize() == 10);
        stackTwo.push(5);
        stackTwo.push(6);
        stackTwo.push(7);
        stackTwo.push(8);
        REQUIRE(stackTwo.getSize() == 4);
        stackOne.push(8);
        REQUIRE(stackOne.getSize() == 11);

    }

    SECTION("Is In Stack function") {
        int a = 1;
        int b = 2;
        int c = 3;
        int d = 4;
        int e = 5;
        REQUIRE(stackOne.isInStack(a));
        REQUIRE(stackOne.isInStack(b));
        REQUIRE(stackOne.isInStack(c));
        REQUIRE(stackOne.isInStack(d));
        REQUIRE(stackOne.isInStack(e));
    }
}