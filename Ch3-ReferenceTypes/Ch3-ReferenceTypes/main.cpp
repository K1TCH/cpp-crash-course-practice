//
//  main.cpp
//  Ch3-ReferenceTypes
//
//  Created by Nolan Kitchin on 5/23/21.
//

#include <cstdio>
#include <string.h>

// Exercise 3.2
void read_from(char characterArray[], int index) {
    size_t arrayLength = strlen(characterArray);
    if (index < 0 || index >= arrayLength) {
        printf("Array length is %lu. Index %d is out of bounds.\n", arrayLength, index);
    } else {
        printf("%c\n", characterArray[index]);
    }
}

void write_to(char characterArray[], int index, char charToInsert) {
    size_t arrayLength = strlen(characterArray);
    if (index < 0 || index >= arrayLength - 1) {
        printf("Array length is %lu. Index %d is out of bounds.\n", arrayLength, index);
    } else {
        characterArray[index] = charToInsert;
    }
}

// Exercise 3.3
struct Element {
    Element* next{};
    Element* previous{};
    void insert_after(Element* new_element) {
        new_element->next = next;
        new_element->previous = this;
        if (next) {
            next->previous = new_element;
        }
        next = new_element;
    }
    void insert_before(Element* new_element) {
        new_element->next = this;
        new_element->previous = previous;
        if (previous) {
            previous->next = new_element;

        }
        previous = new_element;
    }
    char prefix[2];
    short operating_number;
};

int main() {
    
    // Exercise 3.2
    char lower[] = "abc?e";
    char upper[] = "ABC?E";
    char* upper_ptr = upper; // Equivalent: &upper[0]
    
    lower[3] = 'd'; // lower now contains a b c d e \0
    upper_ptr[3] = 'D'; // upper now contains A B C D E \0
    
    char letter_d = lower[3]; // letter_d equals 'd'
    char letter_D = upper_ptr[3]; // letter_D equals 'D'
    
    printf("lower: %s\nupper: %s\n", lower, upper);
    
    //   lower[7] = 'g'; // Super bad. You must never do this.
    
    read_from(lower, 2);
    
    write_to(upper, 5, '?');
    write_to(upper, 0, '!');
    printf("lower: %s\nupper: %s\n", lower, upper);
    
    // Exercise 3.3
    Element trooper1, trooper2, trooper3, trooper4, trooper5;
    trooper1.prefix[0] = 'T';
    trooper1.prefix[1] = 'K';
    trooper1.operating_number = 421;
    trooper1.insert_after(&trooper2);
    trooper2.prefix[0] = 'F';
    trooper2.prefix[1] = 'N';
    trooper2.operating_number = 2187;
    trooper2.insert_after(&trooper3);
    trooper3.prefix[0] = 'L';
    trooper3.prefix[1] = 'S';
    trooper3.operating_number = 005;
    trooper3.insert_after(&trooper4);
    trooper4.prefix[0] = 'J';
    trooper4.prefix[1] = 'B';
    trooper4.operating_number = 007;
    trooper5.prefix[0] = 'N';
    trooper5.prefix[1] = 'K';
    trooper5.operating_number = 256;
    trooper2.insert_before(&trooper5);

    for(Element* cursor = &trooper1; cursor; cursor = cursor->next) {
        printf("Storm Trooper %c%c-%d\n", cursor->prefix[0], cursor->prefix[1], cursor->operating_number);
    }
    printf("\n");
    for(Element* cursor = &trooper4; cursor; cursor = cursor->previous) {
        printf("Storm Trooper %c%c-%d\n", cursor->prefix[0], cursor->prefix[1], cursor->operating_number);
    }
    
    // Exercise 3.4
    auto original = 100;
    auto& original_ref = original;
    printf("Original:  %d\n", original);
    printf("Reference: %d\n", original_ref);

    auto new_value = 200;
    original_ref = new_value;
    printf("Original:  %d\n", original);
    printf("New Value: %d\n", new_value);
    printf("Reference: %d\n", original_ref);
}
