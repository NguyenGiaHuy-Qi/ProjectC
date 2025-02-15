#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>

#define MAX_BOOK 8

struct Date{
	int year;
};
typedef struct {
	char bookID[10];
	char title[30];
	char author[20];
	int price;
	struct Date publication;
	int amountofbook;
}Book;



typedef struct {
	char memberID[10];
	char name[20];
	char phone[10];
	bool status;
}Member;