#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct User {
    char username[50];
    char password[50];
};

struct Book {
    int book_id;
    char book_name[100];
    char book_auth[100];
    char book_pub[100];
    int quantity;
    char date[12];
};

struct Student {
    int student_id;
    char student_name[100];
    char branch[50];
    int semester;
    char section;
    char email[50];
    char phone[15];
    int book_id;
    char book_name[100];
    char book_auth[100];
    char book_pub[100];
    char date[12];
    char dueDate[12];
};

void libmsLOGO(){
	
	printf("\n###############################################################################\n");
	printf("###############################################################################\n");
    printf("###############################################################################\n");
    printf("##########################                                #####################\n");
    printf("##########################   LIBRARY MANAGEMENT SYSTEM    #####################\n");
    printf("##########################         2023-2024              #####################\n");
    printf("###############################################################################\n");
    printf("##########################   SESSION-  2022-2026   ############################\n");
    printf("###############################################################################\n");
    printf("Ankit Singh|BTech CSE IIyr|Univ.ROLL:2200290100025|KIET GROUP OF INSTITUTIONS\n");
    printf("###############################################################################\n");
}


// Function prototypes
int login();
void bookModule();
void userModule();
void registerUser();
void updateUser();
void searchUser();
void deleteUser();
void showUserList();


void addBook();
void bookList();
void removeBook();
void updateBook();
void issueBook();
void displayIssuedBooks();
void returnBook();





void bookModule() {
	libmsLOGO();
    int choice;

    do {
        printf("\nMenu:\n");
        printf("\t\t\t\t1. Add Book   \n");
        printf("\t\t\t\t2. Book List  \n");
        printf("\t\t\t\t3. Remove Book\n");
        printf("\t\t\t\t4. Update Book\n");
        printf("\t\t\t\t5. Issue Book\n");
        printf("\t\t\t\t6. Display Issued Books\n");
        printf("\t\t\t\t7. Return Book\n");
        printf("\t\t\t\t8. Exit\n\n\n");
        printf("\t\t\t\tEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                bookList();
                break;
            case 3:
                removeBook();
                break;
            case 4:
                updateBook();
                break;
            case 5:
            	bookList();
                issueBook();
                break;
            case 6:
                displayIssuedBooks();
                break;
            case 7:
                returnBook();
                break;
            case 8:
                printf("\t\t\t\tExiting the program.\n");
                break;
            default:
                printf("\t\t\t\tInvalid choice. Please enter a valid option.\n");
        }
    } while (choice != 8);


}
void addBook() {
    FILE *file = fopen("books.txt", "rb+");

    if (file == NULL) {
        printf("Error opening books.txt.\n");
        return;
    }

    struct Book newBook;
    system("cls");
    printf("\t\t\t\tEnter book details:\n");
    printf("\t\t\t\tBook ID: ");
    scanf("%d", &newBook.book_id);

    // Check if the book already exists
    FILE *checkFile = fopen("books.txt", "rb");
    if (checkFile == NULL) {
        printf("Error opening books.txt for checking.\n");
        fclose(file);
        return;
    }

    struct Book tempBook;
    while (fread(&tempBook, sizeof(struct Book), 1, checkFile) == 1) {
        if (tempBook.book_id == newBook.book_id) {
            printf("Book with ID %d already exists. Enter quantity to add: ", newBook.book_id);
            scanf("%d", &newBook.quantity);
            tempBook.quantity += newBook.quantity;
            fseek(file, -sizeof(struct Book), SEEK_CUR);
            fwrite(&tempBook, sizeof(struct Book), 1, file);
            fclose(checkFile);
            fclose(file);
            printf("Quantity added successfully.\n");
            return;
        }
    }
    fclose(checkFile);

    printf("\t\t\t\tBook Name: ");
    scanf("%s", newBook.book_name);
    printf("\t\t\t\tAuthor: ");
    scanf("%s", newBook.book_auth);
    printf("\t\t\t\tPublisher:  ");
    scanf("%s", newBook.book_pub);
    printf("\t\t\t\tQuantity: ");
    scanf("%d", &newBook.quantity);
    printf("\t\t\t\tDate (DD/MM/YYYY): ");
    scanf("%s", newBook.date);

    fseek(file, 0, SEEK_END);  // Move the file pointer to the end of the file
    fwrite(&newBook, sizeof(struct Book), 1, file);

    fclose(file);

    printf("\t\t\t\tBook added successfully.\n");
}






void bookList() {
	 system("cls");
    FILE *file = fopen("books.txt", "rb");
    if (file == NULL) {
        printf("No books available.\n");
        return;
    }

    struct Book book;
    printf("\nBook List:\n");
   
     printf("| %s | %s | %s | %s | %s | %s |\n", "ID", "Name", "Author", "Publisher", "Quantity", "Date");


    while (fread(&book, sizeof(struct Book), 1, file)) {
       printf("| %d | %s | %s | %s | %d | %s |\n",
               book.book_id, book.book_name, book.book_auth, book.book_pub, book.quantity, book.date);
         
    }

    fclose(file);
}

void removeBook() {
	 system("cls");
    FILE *file = fopen("books.txt", "rb");
    if (file == NULL) {
        printf("No books available.\n");
        return;
    }

    FILE *tempFile = fopen("temp.txt", "wb");
    int bookId;

    printf("Enter the Book ID to remove: ");
    scanf("%d", &bookId);

    struct Book book;
    int found = 0;

    while (fread(&book, sizeof(struct Book), 1, file)) {
        if (book.book_id == bookId) {
            found = 1;
            printf("Book with ID %d removed successfully.\n", bookId);
        } else {
            fwrite(&book, sizeof(struct Book), 1, tempFile);
        }
    }

    fclose(file);
    fclose(tempFile);

    if (!found) {
        printf("Book with ID %d not found.\n", bookId);
        remove("temp.txt");
        return;
    }

    remove("books.txt");
    rename("temp.txt", "books.txt");
}

void updateBook() {
	 system("cls");
    FILE *file = fopen("books.txt", "rb");
    if (file == NULL) {
        printf("No books available.\n");
        return;
    }

    FILE *tempFile = fopen("temp.txt", "wb");
    int bookId;

    printf("Enter the Book ID to update: ");
    scanf("%d", &bookId);

    struct Book book;
    int found = 0;

    while (fread(&book, sizeof(struct Book), 1, file)) {
        if (book.book_id == bookId) {
            found = 1;
            printf("Enter new details for Book ID %d:\n", bookId);
            printf("Book Name:                  ");
            scanf("%s", book.book_name);
            printf("Author:                     ");
            scanf("%s", book.book_auth);
            printf("Publisher:                  ");
            scanf("%s", book.book_pub);
            printf("Quantity:                   ");
            scanf("%d", &book.quantity);
            printf("Date (DD/MM/YYYY):          ");
            scanf("%s", book.date);
        }
        fwrite(&book, sizeof(struct Book), 1, tempFile);
    }

    fclose(file);
    fclose(tempFile);

    if (!found) {
        printf("Book with ID %d not found.\n", bookId);
        remove("temp.txt");
        return;
    }

    remove("books.txt");
    rename("temp.txt", "books.txt");
    printf("\t\t\tBook with ID %d updated successfully.\n", bookId);
}

void issueBook() {
	 system("cls");
    FILE *booksFile = fopen("books.txt", "rb+");
    if (booksFile == NULL) {
        printf("No books available.\n");
        return;
    }

    FILE *issuedFile = fopen("issuedBooks.txt", "ab");
    if (issuedFile == NULL) {
        fclose(booksFile);
        printf("Error opening issuedBooks.txt.\n");
        return;
    }

    struct Book book;
    int bookId, found = 0;

    printf("Enter the Book ID to issue: ");
    scanf("%d", &bookId);

    while (fread(&book, sizeof(struct Book), 1, booksFile)) {
        if (book.book_id == bookId) {
            found = 1;

            struct Student student;

            printf("Enter student details:\n");
            printf("Student ID:           ");
            scanf("%d", &student.student_id);
            printf("Student Name:         ");
            scanf("%s", student.student_name);
            printf("Branch:               ");
            scanf("%s", student.branch);
            printf("Semester:             ");
            scanf("%d", &student.semester);
            printf("Section:              ");
            scanf(" %c", &student.section);
            printf("Phone:                ");
            scanf("%s", student.phone);
            printf("Email:                ");
            scanf("%s", student.email);

            student.book_id = book.book_id;
            sprintf(student.book_name, "%s", book.book_name);
            sprintf(student.book_auth, "%s", book.book_auth);
            sprintf(student.book_pub, "%s", book.book_pub);

            printf("Enter issue date (DD/MM/YYYY): ");
            scanf("%s", student.date);

            
            sprintf(student.dueDate, "%s", "AFTER_15_days");

            // Update quantity in books file
            book.quantity -= 1;
            fseek(booksFile, -sizeof(struct Book), SEEK_CUR);
            fwrite(&book, sizeof(struct Book), 1, booksFile);

            // Write issued book data to file
            fwrite(&student, sizeof(struct Student), 1, issuedFile);

            printf("Book issued successfully.\n");
            break;
        }
    }

    fclose(booksFile);
    fclose(issuedFile);

    if (!found) {
        printf("Book with ID %d not found.\n", bookId);
    }
}

void displayIssuedBooks() {
	 system("cls");
    FILE *file = fopen("issuedBooks.txt", "rb");
    if (file == NULL) {
        printf("No books issued.\n");
        return;
    }

    struct Student student;
    printf("\n\t\t\tIssued Book List:\n\n\n");
     
   
     printf("| %s | %s | %s | %s | %s | %s | %s | %s | %s |\n", "Stu ID", "Name", "Branch", "Sem", "Sec", "Phone", "Email", "Book ID", "Issue Date", "Due Date");
       
    while (fread(&student, sizeof(struct Student), 1, file)) {
         printf("\n___________________________________________________________________________________________________________\n");    
        printf("| %d | %s | %s | %d | %c | %s | %s | %d | %s | %s |\n",
               student.student_id, student.student_name, student.branch, student.semester, student.section, student.phone, student.email,
               student.book_id, student.date, student.dueDate);
        
    }

    fclose(file);
}

void returnBook() {
	 system("cls");
    FILE *issuedFile = fopen("issuedBooks.txt", "rb");
    if (issuedFile == NULL) {
        printf("No books issued.\n");
        return;
    }

    FILE *tempFile = fopen("temp.txt", "wb");
    int bookId, studentId;

    printf("Enter the Book ID to return: ");
    scanf("%d", &bookId);

    printf("Enter the Student ID who is returning the book: ");
    scanf("%d", &studentId);

    struct Student student;
    struct Book book;
    int found = 0;

    while (fread(&student, sizeof(struct Student), 1, issuedFile)) {
        if (student.book_id == bookId && student.student_id == studentId) {
            found = 1;

            // Update quantity in books file
            FILE *booksFile = fopen("books.txt", "rb+");
            if (booksFile != NULL) {
                while (fread(&book, sizeof(struct Book), 1, booksFile)) {
                    if (book.book_id == bookId) {
                        book.quantity += 1;
                        fseek(booksFile, -sizeof(struct Book), SEEK_CUR);
                        fwrite(&book, sizeof(struct Book), 1, booksFile);
                        fclose(booksFile);
                        break;
                    }
                }
            } else {
                printf("Error opening books.txt.\n");
            }

            printf("Book with ID %d returned successfully.\n", bookId);
        } else {
            fwrite(&student, sizeof(struct Student), 1, tempFile);
        }
    }

    fclose(issuedFile);
    fclose(tempFile);

    if (!found) {
        printf("Book with ID %d issued to Student ID %d not found.\n", bookId, studentId);
        remove("temp.txt");
        return;
    }

    remove("issuedBooks.txt");
    rename("temp.txt", "issuedBooks.txt");
}




int main() {
	label:
	libmsLOGO();
    if (login()) {	
        
    
        int choice;

        do {
            printf("\n<== Library Management System ==>\n");
           
            printf("1. User Module\n");
            printf("2. Book Module\n");
            printf("0. Exit\n");
            printf("Enter your choice: ");
            scanf("%d", &choice);

            switch (choice) {
                case 1:
                    userModule();                          //
                    break;
                case 2:
                    bookModule();
                    break;
                case 0:
                
                    printf("Exiting the program.\n");
                    break;
                default:
                    printf("Invalid choice. Please try again.\n");
            }
        } while (choice != 0);
    } 
	else {
        printf("Login failed. ENTER CORRECT DETAILS.\n");
        goto label;
    }

    return 0;
}

int login() {
    char inputUsername[50];
    char inputPassword[50];

    struct User user;
    FILE *userFile;

    printf("\n\n\n\n\t\t\t\tEnter your username: ");
    scanf("%s", inputUsername);
    printf("\t\t\t\tEnter your password: ");
    scanf("%s", inputPassword);

    userFile = fopen("users.txt", "r");

    if (userFile == NULL) {
        printf("Error opening user file. Exiting the program.\n");
        exit(1);
    }

    while (fscanf(userFile, "%s %s\n", user.username, user.password) == 2) {
        if (strcmp(inputUsername, user.username) == 0 && strcmp(inputPassword, user.password) == 0) {
            printf("\t\t\t\tLogin successful!\n");
            fclose(userFile);
            return 1;
        }
    }

    fclose(userFile);
    return 0;
}

void userModule() {
	libmsLOGO();
    int choice;

    do {
        printf("\t\t\t\t\n<== User Module ==>\n");
        printf("1. Register User\n");
        printf("2. Update User\n");
        printf("3. Search User\n");
        printf("4. Delete User\n");
        printf("5. Show User List\n");
        printf("0. Back to Main Menu\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                updateUser();
                break;
            case 3:
                searchUser();
                break;
            case 4:
                deleteUser();
                break;
            case 5:
                showUserList();
                break;
            case 0:
                printf("Returning to the main menu.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);
}

void registerUser() {
    struct User user;
    FILE *userFile;

    system("cls");

    printf("Enter new username:                               ");
    scanf("%s", user.username);
     printf("Enter new password:                              ");
    scanf("%s", user.password);

    userFile = fopen("users.txt", "a");

    if (userFile == NULL) {
        printf("Error opening user file. Exiting the program.\n");
        exit(1);
    }

    fprintf(userFile, "\n%s %s\n", user.username, user.password);
    
    fclose(userFile);

    printf("\t\t\t\tUser registered successfully!\n");
}

void updateUser() {
    char targetUsername[50];
   
    struct User user;
    FILE *userFile, *tempFile;
     system("cls");

    printf("Enter the username to update: ");
    scanf("%s", targetUsername);


    userFile = fopen("users.txt", "r");
    tempFile = fopen("temp_users.txt", "w");

    if (userFile == NULL || tempFile == NULL) {
        printf("Error opening user files. Exiting the program.\n");
        exit(1);
    }

    int found = 0;

    while (fscanf(userFile, "%s %s\n", user.username, user.password) == 2) {
        if (strcmp(targetUsername, user.username) == 0) {
            found = 1;
            printf("Enter new password for %s: ", targetUsername);
            scanf("%s", user.password);
        }
        fprintf(tempFile, "%s %s\n", user.username, user.password);
    }

    fclose(userFile);
    fclose(tempFile);

    remove("users.txt");
    rename("temp_users.txt", "users.txt");

    if (found) {
        printf("User updated successfully!\n");
    } else {
        printf("User not found.\n");
    }
}

void searchUser() {
    char targetUsername[50];
    struct User user;
    FILE *userFile;

     system("cls");

    printf("Enter the username to search: ");
    scanf("%s", targetUsername);

    userFile = fopen("users.txt", "r");

    if (userFile == NULL) {
        printf("Error opening user file. Exiting the program.\n");
        exit(1);
    }

    int found = 0;

    while (fscanf(userFile, "%s %s\n", user.username, user.password) == 2) {
        if (strcmp(targetUsername, user.username) == 0) {
            found = 1;
            printf("User found!\n");
            printf("\n===================================\n");
            printf("Username: %s\n", user.username);
            printf("Password: %s\n", user.password);
            printf("\n===================================\n"); 
            break;
        }
    }

    fclose(userFile);

    if (!found) {
        printf("User not found.\n");
    }
}

void deleteUser() {
    char targetUsername[50];
    struct User user;
    FILE *userFile, *tempFile;

     system("cls");

    printf("Enter the username to delete: ");
    scanf("%s", targetUsername);

    userFile = fopen("users.txt", "r");
    tempFile = fopen("temp_users.txt", "w");

    if (userFile == NULL || tempFile == NULL) {
        printf("Error opening user files. Exiting the program.\n");
        exit(1);
    }

    int found = 0;

    while (fscanf(userFile, "%s %s\n", user.username, user.password) == 2) {
        if (strcmp(targetUsername, user.username) == 0) {
            found = 1;
            printf("User deleted successfully!\n");
            continue;
        }
        fprintf(tempFile, "%s %s\n", user.username, user.password);
    }

    fclose(userFile);
    fclose(tempFile);

    remove("users.txt");
    rename("temp_users.txt", "users.txt");

    if (!found) {
        printf("User not found.\n");
    }
}

void showUserList() {
    struct User user;
    FILE *userFile;
     system("cls");
    userFile = fopen("users.txt", "r");

    if (userFile == NULL) {
        printf("Error opening user file. Exiting the program.\n");
        exit(1);
    }

    printf("\n<== User List ==>\n");
    while (fscanf(userFile, "%s %s\n", user.username, user.password) == 2) {
    	
    	printf("\t\t\t==============================================\n");
        printf("\t\t\tUsername:         %s\n", user.username);
        printf("\t\t\tpassword:         %s\n", user.password);
        printf("\t\t\t==============================================\n");
      
    }

    fclose(userFile);
}




