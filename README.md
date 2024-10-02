# Library Management System

## Overview

The **Library Management System (LMS)** is a comprehensive software solution developed to automate and streamline the tasks associated with managing a library's resources, including books, users, and administrative functions. This system provides an efficient and user-friendly way to organize, store, and retrieve information, helping library staff and users manage books, user accounts, and borrowing records with ease. The primary goal of the system is to enhance the overall management and accessibility of library resources.

## Features

### 1. **Login System**
- Users are prompted to log in with a username and password.
- User credentials are validated against the data stored in the `users.txt` file.
- Upon successful login, users are granted access to the main menu.

### 2. **Main Menu**
- Users can navigate between the **User Module** and **Book Module**.
- Option to exit the program is available.

### 3. **User Module**
#### Register User
- Users can create new accounts with a unique username and password.
- New user data is stored in the `users.txt` file.

#### Update User
- Users can update their password.
- Updated information is saved back to the `users.txt` file.

#### Search User
- Users can search for a specific user by entering a username.
- Displays the user’s details if found.

#### Delete User
- Users can delete their account by entering their username.
- Removes the corresponding entry from the `users.txt` file.

#### Show User List
- Displays a list of all registered users.

### 4. **Book Module**
#### Add Book
- Users can add new books to the system.
- If the book already exists (based on Book ID), the system updates the quantity.

#### Book List
- Displays a list of all available books in the library.

#### Remove Book
- Users can remove a book from the system by entering the Book ID.

#### Update Book
- Users can update book details, including the quantity and other book-related information.

#### Issue Book
- Users can issue a book to a student.
- Updates the book quantity and logs the issuance in `issuedBooks.txt`.

#### Display Issued Books
- Shows a list of all issued books with student details.

#### Return Book
- Allows students to return books.
- Updates the quantity of the book and removes it from the issued list.

## Program Flow
1. The `main()` function starts the program and invokes the login process.
2. Upon successful login, users are presented with the main menu.
3. Users can navigate between the **User Module** and **Book Module** to perform various operations such as adding books, issuing books, updating user details, etc.
4. The program runs continuously until the user chooses to exit.

## Future Enhancements

1. **Multilayer Authentication**
   - Implement additional layers of authentication for enhanced security when accessing both the **User Module** and **Book Module**.

2. **Advanced Book Search**
   - Implement search functionality to allow users to search for books using multiple criteria such as author, publication date, genre, etc.

3. **Extended Book Details**
   - Add more details for each book, including ISBN, genre, language, etc.

