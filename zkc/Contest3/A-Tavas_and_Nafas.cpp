#include <bits/stdc++.h>
using namespace std;

void cg1(int n) {
    switch(n) {
    case 2:
        printf("twenty");
        break;
    case 3:
        printf("thirty");
        break;
    case 4:
        printf("forty");
        break;
    case 5:
        printf("fifty");
        break;
    case 6:
        printf("sixty");
        break;
    case 7:
        printf("seventy");
        break;
    case 8:
        printf("eighty");
        break;
    case 9:
        printf("ninety");
        break;
    }
}
void cg2(int n) {
    switch(n) {
    case 0:
        puts("");
        break;
    case 1:
        puts("-one");
        break;
    case 2:
        puts("-two");
        break;
    case 3:
        puts("-three");
        break;
    case 4:
        puts("-four");
        break;
    case 5:
        puts("-five");
        break;
    case 6:
        puts("-six");
        break;
    case 7:
        puts("-seven");
        break;
    case 8:
        puts("-eight");
        break;
    case 9:
        puts("-nine");
        break;
    }

}
int main() {
    int n;
    cin>>n;
    if(0<=n&&n<=20) {
        switch(n) {
        case 0:
            puts("zero");
            break;
        case 1:
            puts("one");
            break;
        case 2:
            puts("two");
            break;
        case 3:
            puts("three");
            break;
        case 4:
            puts("four");
            break;
        case 5:
            puts("five");
            break;
        case 6:
            puts("six");
            break;
        case 7:
            puts("seven");
            break;
        case 8:
            puts("eight");
            break;
        case 9:
            puts("nine");
            break;
        case 10:
            puts("ten");
            break;
        case 11:
            puts("eleven");
            break;
        case 12:
            puts("twelve");
            break;
        case 13:
            puts("thirteen");
            break;
        case 14:
            puts("fourteen");
            break;
        case 15:
            puts("fifteen");
            break;
        case 16:
            puts("sixteen");
            break;
        case 17:
            puts("seventeen");
            break;
        case 18:
            puts("eighteen");
            break;
        case 19:
            puts("nineteen");
            break;
        case 20:
            puts("twenty");
            break;
        }
    } else {
        cg1(n/10);
        cg2(n%10);
    }
}
