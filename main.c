#include <stdio.h>
#include <stdbool.h>

//find the length of a number
int find_length(long long n) {
    int len;
    //it is cutting the length of removing the
    // last digit each time through the loop
    for (len = 0; n != 0; n /= 10, len++);

    return len;
}

bool checksum(long long ccn) {
    int sum = 0;

    //loop through the ccn, increase i, get last digit
    //using the ccn/=10 each iteration
    for (int i = 0; ccn != 0; ++i, ccn /= 10) {
        //get an even number from index
        if (i % 2 == 0) {
            sum += ccn % 10;
        } else {
            int digit = 2 * (ccn % 10);
            sum += digit / 10 + digit % 10;
        }
    }

    //bool if the last digit of the sum is 0
    return (sum % 10) == 0;
}

void print_brand(long long ccn) {

    if((ccn >= 34e13 && ccn < 35e13) || (ccn >= 37e13 && ccn < 38e13))
        printf("AMEX\n");
    else if (ccn >= 51e14 && ccn < 56e14)
        printf("MASTERCARD\n");
    else if((ccn >= 4e12 && ccn < 5e12) || (ccn >= 4e15 && ccn < 5e15))
        printf("VISA\n");
}


bool cc_valid(long long credit_card_number) {
    int len = find_length(credit_card_number);

    return (len == 13 || len == 15 || len == 16) && checksum(credit_card_number);
}

int main() {
    //Test credit card numbers from paypal.com
    //AMEX = 378282246310005
    //AMEX = 371449635398431
    //MC = 5555555555554444
    //MC = 5105105105105100
    //VISA = 4111111111111111
    //VISA = 4222222222222
    //INVALID=1111111111111111
    //INVALID=0110191111111111
    long long credit_card_number;
    printf("What is the credit card number: ");
    scanf("%lld", &credit_card_number);

    if (cc_valid(credit_card_number)) {
        print_brand(credit_card_number);
    } else {
        printf("INVALID\n");
    }
    return 0;
}
