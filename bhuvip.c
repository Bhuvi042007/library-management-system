#include <stdio.h> #include < stdlib.h> #include <string.h> #include <ctype.h>
#define BOOKS_FILE "books.dat" #define ISSUES_FILE "issues.dat"
#define TITLE_LEN 100
#define AUTHOR_LEN 50
Typedef struct {
Int id;
Char title[TITLE_LEN];
Char author[AUTHOR_LEN];
Int quantity;
Int available;
} Book;
Typedef struct {
Int bookId;
Char studentName[50];
Char studentld[20];
Char issueDate[12];
Char returnDate[12];
} Issue;
Void clear input_buffer;
Void pause_consoleO;
Void addBookO;
Void displayBooks;
Void searchBook(;
Void issueBook();
Void returnBookO;
Void modifyBook;
Void deleteBook;
Int bookExists(int id, Book * out);
Void toLowerStr(char *s);
Int main0 {
Int choice;
While (1) {
System("clear || cls");
Printf("\n==
==In");
Printf("1. Add Book|n");
== Library Management System
Printf("2. Display All Books|n");
Printf("3. Search Bookln");
Printf("4. Issue Bookln");
Printf("5. Return BookIn");
Printf("6. Modify Book|n");
Printf("7. Delete Book|n");
Printf ("8. Exitn");
Printf("Enter choice: ");
If (scanf("d", &choice)!= 1) { clear _input_buffer(;
choice = 0; }
Switch (choice) {
Case 1: addBook(); break;
Case 2: displayBooksO; break;
Case 3: searchBook; break;
Case 4: issueBook; break;
Case 5: returnBook; break;
Case 6: modifyBook; break;
Case 7: deleteBookO; break;
Case 8: printf("Exiting... In"); exit(0);
Default: printf("Invalid choice, try again. In");
pause_console;
Return 0;
}
Void clear_input_buffer {
Int c; while ((c = getchar)!= n' && c!= EOF;
Void pause _console0 {
Printf("'nPress ENTER to continue...");
Clear_input_buffer;
Int bookExists(int id, Book * out) {
FILE *fp = fopen(BOOKS_FILE, "b"); if (!fp) return O;
Book b;
While (fread(&b, sizeof(Book), 1, fp) == 1) {
If (b.id == id) { if (out) * out = b; fclose(fp); return 1; }
} fclose(fp); return 0;
}
Void addBook {
Book b; system("clear || cls"); printf("\n--- Add New Book ---
In");
Printf("Enter Book ID: "); if (scanf d", &b.id) != 1) {
clear_input _buffer; printf("Invalid ID. In"); pause_console(); return;
If (bookExists(b.id, NULL)) { printf("Book with ID %d exists. In", b.id); pause_consoleO; return; }
Clear_input_buffer; printf("Enter Title: "); fgets(b.title,
TITLE_LEN, stdin); b.title[strcspn(b.title, "n")] = "10';
Printf"Enter Author: "); fgets(b. author, AUTHOR_LEN,
stdin); b.author[strcspn(b.author, "n")] = "10';
Printf("Enter Quantity: "); scanfod", &b.quantity);
b.available = b.quantity;
FILE * fp = fopen(BOOKS_FILE, "ab"); fwrite(&b,
sizeof(Book), 1, fp); fclose(fp);
Printf"Book added successfully. In"); pause_consoleO;
}
Void displayBooks {
Book b; system ("clear || cls"); FILE *fp =
fopen(BOOKS_FILE, "rb");
If (!fp) { printf("No records found. In"); pause_console; return; }
Printf("ID\tTitle\tAuthor|tQty|tAvail\n"); printf("---
While (fread(&b, sizeof(Book), 1, fp) == 1) {
Printf("d\t%s|t%s|t%d\t%dIn", b.id, b.title, b.author,
b.quantity, b.available);
; fclose(fp); pause_consoleO;
}}