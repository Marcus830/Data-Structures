// Challenge 4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <chrono>
#include <vector>
#include <algorithm>
#include <ctime>
#include "../Challenge 1.1 - The missing link/Linkedlist.h"
#include "../Challenge 3 - BST+U=BFF/BST.h"
#include "Challenge 4.h"

using namespace std;


// this populates the bst with 1 dozen from 1 to 1000
void Populate_and_insert_12(BST& bst) {
    int max_count = 12;
    int max_rand = 1000;
    for (int i = 0; i < max_count; i++) {
        int random_num = rand() % max_rand; 
        bst.insert(random_num);
    }
}
void Populate_and_insert_12(LinkedList& linkedList) {
    int max_count = 12;
    int max_rand = 1000;
    for (int i = 0; i < max_count; i++) {
        int random_num = rand() % max_rand;
        linkedList.insert(random_num);
    }
}
// this populates and inserts the linkedlist from 1 to 1000
void Populate_and_insert_24(BST& bst) {
    int max_count = 24;
    int max_rand = 1000;
    for (int i = 0; i < max_count; i++) {
        int random_num = rand() % max_rand; // generate a random number between 1 and 1000
        bst.insert(random_num);
    }
}
void Populate_and_insert_24(LinkedList& linkedList) {
    int max_count = 24;
    int max_rand = 1000;
    for (int i = 0; i < max_count; i++) {
        int random_num = rand() % max_rand; // generate a random number between 1 and 1000
        linkedList.insert(random_num);
    }
}
// this populates and inserts 200 random numbers from 1 to 1000
void Populate_and_insert_200(BST& bst) {
    int max_count = 24;
    int max_rand = 1000;
    for (int i = 0; i < max_count; i++) {
        int random_num = rand() % max_rand; // generate a random number between 1 and 1000
        bst.insert(random_num);
    }
}
void Populate_and_insert_200(LinkedList& linkedList) {
    int max_count = 24;
    int max_rand = 1000;
    for (int i = 0; i < max_count; i++) {
        int random_num = rand() % max_rand; // generate a random number between 1 and 1000
        linkedList.insert(random_num);
    }
}
void Backwards_LL(LinkedList& linkedList) {
    // 1 through 1k backwards
    for (int i = 1000; i >= 1; i--) {
        linkedList.insert(i);
    }
}
void Backwards_bst(BST& bst){
    for (int i = 1000; i >= 1; i--) {
        bst.insert(i);
    }
}
void Forward_bst(BST& bst) {
    // 1 through 1k forwards
    for (int i = 1; i <= 1000; i++) {
        bst.insert(i);
    }
}
void Forward_LL(LinkedList& linkedList){
    for (int i = 1; i <= 1000; i++) {
        linkedList.insert(i);
    }
}


int main() {
    srand(time(nullptr));

    BST bst;
    LinkedList linkedList;

    // Prompt the user to enter a value to search for
    int searchesValue;
    cout << "Enter a value to search for: ";
    cin >> searchesValue;

    // Measure the runtime 1 dozen of searching the value in the BST
    auto bst_start_time = chrono::high_resolution_clock::now();
    Populate_and_insert_12(bst);
    bool bst_found = bst.search(searchesValue);
    auto bst_end_time = chrono::high_resolution_clock::now();
    auto bst_duration = chrono::duration_cast<chrono::microseconds>(bst_end_time - bst_start_time);
    long bst_microseconds = bst_duration.count();

    // Measure the runtime 1 dozen of searching the value in the Linked List
    auto ll_start_time = chrono::high_resolution_clock::now();
    Populate_and_insert_12(linkedList);
    bool ll_found = linkedList.search(searchesValue);
    auto ll_end_time = chrono::high_resolution_clock::now();
    auto ll_duration = chrono::duration_cast<chrono::microseconds>(ll_end_time - ll_start_time);
    long ll_microseconds = ll_duration.count();

    cout << "BST search time(1 dozen): " << bst_microseconds << " microseconds" << endl;
    cout << "Linked List search time(1 dozen): " << ll_microseconds << " microseconds" << endl;

    cout << "Value found in BST: " << (bst_found ? "true" : "false") << endl;
    cout << "Value found in Linked List: " << (ll_found ? "true" : "false") << endl;

    cout << " " << endl;
    // Measure the runtime of 2 dozen searching the value in the BST
    auto bst_start_time1 = chrono::high_resolution_clock::now();
    Populate_and_insert_24(bst);
    bool bst_found1 = bst.search(searchesValue);
    auto bst_end_time1 = chrono::high_resolution_clock::now();
    auto bst_duration1 = chrono::duration_cast<chrono::microseconds>(bst_end_time1 - bst_start_time1);
    long bst_microseconds1 = bst_duration.count();

    // Measure the runtime 2 dozen of searching the value in the Linked List
    auto ll_start_time1 = chrono::high_resolution_clock::now();
    Populate_and_insert_24(linkedList);
    bool ll_found1 = linkedList.search(searchesValue);
    auto ll_end_time1 = chrono::high_resolution_clock::now();
    auto ll_duration1 = chrono::duration_cast<chrono::microseconds>(ll_end_time1 - ll_start_time1);
    long ll_microseconds1 = ll_duration1.count();

    cout << "BST search time(2 dozen): " << bst_microseconds1 << " microseconds" << endl;
    cout << "Linked List search time(2 dozen): " << ll_microseconds1 << " microseconds" << endl;

    cout << "Value found in BST: " << (bst_found1 ? "true" : "false") << endl;
    cout << "Value found in Linked List: " << (ll_found1 ? "true" : "false") << endl;

    cout << " " << endl;
    // Measure the runtime of 200 searching the value in the BST
    auto bst_start_time2 = chrono::high_resolution_clock::now();
    Populate_and_insert_200(bst);
    bool bst_found2 = bst.search(searchesValue);
    auto bst_end_time2 = chrono::high_resolution_clock::now();
    auto bst_duration2 = chrono::duration_cast<chrono::microseconds>(bst_end_time2 - bst_start_time2);
    long bst_microseconds2 = bst_duration2.count();

    // Measure the runtime 200 of searching the value in the Linked List
    auto ll_start_time2 = chrono::high_resolution_clock::now();
    Populate_and_insert_200(linkedList);
    bool ll_found2 = linkedList.search(searchesValue);
    auto ll_end_time2 = chrono::high_resolution_clock::now();
    auto ll_duration2 = chrono::duration_cast<chrono::microseconds>(ll_end_time2 - ll_start_time2);
    long ll_microseconds2 = ll_duration2.count();

    cout << "BST search time(200): " << bst_microseconds2 << " microseconds" << endl;
    cout << "Linked List search time(200): " << ll_microseconds2 << " microseconds" << endl;

    cout << "Value found in BST: " << (bst_found2 ? "true" : "false") << endl;
    cout << "Value found in Linked List: " << (ll_found2 ? "true" : "false") << endl;

    cout << " " << endl;
    // Measure the runtime of 1000 backwards the value in the BST
    auto bst_start_time3 = chrono::high_resolution_clock::now();
    Backwards_bst(bst);
    bool bst_found3 = bst.search(searchesValue);
    auto bst_end_time3 = chrono::high_resolution_clock::now();
    auto bst_duration3 = chrono::duration_cast<chrono::microseconds>(bst_end_time3 - bst_start_time3);
    long bst_microseconds3 = bst_duration3.count();

    // Measure the runtime  for 1 to 1000 backwards the value in the Linked List
    auto ll_start_time3 = chrono::high_resolution_clock::now();
    Backwards_LL(linkedList);
    bool ll_found3 = linkedList.search(searchesValue);
    auto ll_end_time3 = chrono::high_resolution_clock::now();
    auto ll_duration3 = chrono::duration_cast<chrono::microseconds>(ll_end_time3 - ll_start_time3);
    long ll_microseconds3 = ll_duration3.count();

    cout << "BST search time(backwards): " << bst_microseconds3 << " microseconds" << endl;
    cout << "Linked List search time(backwards): " << ll_microseconds3 << " microseconds" << endl;

    cout << "Value found in BST: " << (bst_found3 ? "true" : "false") << endl;
    cout << "Value found in Linked List: " << (ll_found3 ? "true" : "false") << endl;
    
    cout << " " << endl;
    // Measure the runtime of 1 to 1000 foward the value in the BST
    auto bst_start_time4 = chrono::high_resolution_clock::now();
    Forward_bst(bst);
    bool bst_found4 = bst.search(searchesValue);
    auto bst_end_time4 = chrono::high_resolution_clock::now();
    auto bst_duration4 = chrono::duration_cast<chrono::microseconds>(bst_end_time4 - bst_start_time4);
    long bst_microseconds4 = bst_duration4.count();

    // Measure the runtime  for 1 to 1000 forward the value in the Linked List
    auto ll_start_time4 = chrono::high_resolution_clock::now();
    Forward_LL(linkedList);
    bool ll_found4 = linkedList.search(searchesValue);
    auto ll_end_time4 = chrono::high_resolution_clock::now();
    auto ll_duration4 = chrono::duration_cast<chrono::microseconds>(ll_end_time4 - ll_start_time4);
    long ll_microseconds4 = ll_duration4.count();

    cout << "BST search time(forwards): " << bst_microseconds4 << " microseconds" << endl;
    cout << "Linked List search time(forwards): " << ll_microseconds4 << " microseconds" << endl;

    cout << "Value found in BST: " << (bst_found4 ? "true" : "false") << endl;
    cout << "Value found in Linked List: " << (ll_found4 ? "true" : "false") << endl;

    return 0;
}
