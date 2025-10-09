using namespace std;
#include <iostream>

int main (){
    sum_of_number_digits();
    product_of_all_even_digits();
}

//Write a program that takes any positive integer and calculates the sum of its digits.
#include <iostream> 
int sum_of_number_digits() {
    
    int num = 0;
    int sum = 0;

    cout << "Enter a number to get the sum of it's digits.";
    cin >> num;

    while (num > 0) {
        int digit = num % 10;
        sum += digit;
        num /= 10;
    }
    cout << "The sum is " << sum;
}

//Read an integer and calculate the product of all even digits.

int product_of_all_even_digits() {
    
    int num = 0;
    int prod = 1;
    int digit = 0;

    cout << "Enter a number to get the product of all it's even digits.";
    cin >> num;

    while (num > 0) {
        int digit = num % 10;
            if (digit % 2 == 0) {
                prod *= digit;
            }
        num /= 10;
    }
    cout << "The product of the even digits is " << prod;
}

//Write a program that counts and prints the number of odd digits in an integer.
int number_of_odd_digits() {
    int num = 0;
    int count = 0;
    int digit = 0;

    cout << "Enter a number to get the count of odd digits in the number.";
    cin >> num;

    while (num > 0) {
        int digit = num % 10;
        if (digit % 2 != 0) {
            count ++;
        }
        num /= 10;
        cout << "The total number of odd digits in the number is " << count;
    }
}

//Take any integer and print it in reverse order.
int reverse_order_of_num() {
    int num = 0;
    int reversed = 0;

    cout << "Enter a number to have it returned in reverse order.";
    cin >> num;

    while (num > 0) {
        int digit = num % 10;
        reversed = reversed * 10 + digit;
        num /= 10;
    }
    cout << "The number in reverse order is " << reversed;
}

//Check if digits are in increasing order.
int check_digit_order() {
    int num = 0;
    bool increasing = false;
    int prev = 10;

    cout << "Enter a number to check if the digits are in increasing ordedr (left to right).";
    cin >> num;

    while (num > 0) {
        int digit = num % 10;
        num /= 10;
            if (digit >= prev) {
                increasing = false;
                break;
            }
        prev = digit;    
    }

    if (increasing) {
        cout << "The digits of the number are in increasing order.";
    } else {
        cout << "The digits of the number are NOT in increasing order.";
    }
    return 0;
}

//Write a program that asks the user for 10 integers and counts how many elements appear more than once.
int number_of_repeated_digits() {
    int arr[10] = {0};
    int count = 0;
    
    cout << "Enter 10 digits to see how many differe digits were duplicated.";
    for (int i = 0; i < 10; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < 10; i++) {
        bool counted = false;

        for (int k = 0; k < i; k++) {
            if (arr[i] == arr[k]) {
                counted = true;
                break;
            }
        }
    
    if (!counted) {
        for (int j = i + 1; j < 10; j++) {
            if (arr[i] == arr[j]) {
                count ++;
                break;
            }
        }
    }
    }

    cout << "There are " << count << " numbers that appear more than once.";
    return 0;
}

//Given a list of integers where every element appears twice except one, find the number that appears only once.

int unique_number() {
    int n;
    cout << "Enter number of elements";
    cin >> n;

    int *arr = new int[n];
    cout << "Enter " << n << "integers";
    for (int i = 0; i <= n; i++){
        cin >> arr[i];
    }

    int result = 0;
    for (int i = 0; i < n; i++) {
        result ^= arr[i];
    }
    cout << "unique =" << result;

    delete[] arr;
}

//Ask the user for 10 integers and remove duplicate values, printing only unique numbers in their original order.
int remove_dupe() {

    int frontIndex = 0;
    int array[10] = {0};
    cout << "Enter 10 integers.";
    for (int i = 0; i < 10; i++) {
        cin >> array[i];
    }

    for (int i = 0; i < 10; i++) {
        
        bool counted = false;

        for (int k = 0; k < i; k++) {
            if (arr[i] == arr[k]) {
                counted = true;
                break;
            }
        }
        for (int k = i + 1; k < 10; k++) {
            if (array[i] == array[k]) {

            }
        }
    }
}