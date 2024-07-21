# Banking System Project

## Overview

This project implements a client-server banking system using the client-server model. It supports various operations for user and admin roles, such as login, account management, transaction processing, and more. The system is built using the Qt/C++ framework and utilizes sockets for client-server communication.

## Features

### Request/Response Pairs

1. **Log In (user, pass)**
   - **Request:** Login request with user or admin credentials.
   - **Response:** Boolean (`true` if credentials are correct, `false` otherwise).

2. **Get Account Number (username)**
   - **Authorized:** User
   - **Request:** Retrieve account number for a given username (must be logged in).
   - **Response:** Account number string or empty string if not logged in.

3. **Get Account Number (admin, username)**
   - **Authorized:** Admin
   - **Request:** Retrieve account number for a given username (admin must be logged in).
   - **Response:** Account number string.

4. **View Account Balance (account number)**
   - **Authorized:** User & Admin
   - **Request:** Retrieve the balance of a given account number.
   - **Response:** Signed 4-byte integer representing the balance.

5. **View Transaction History (account number, count)**
   - **Authorized:** User & Admin
   - **Request:** Retrieve the last `count` transactions for an account number.
   - **Response:** Serialized JSON array of transactions.

6. **Make Transaction (account number, transaction amount)**
   - **Authorized:** User
   - **Request:** Modify the balance of an account by a transaction amount.
   - **Response:** Boolean (`true` if transaction is possible, `false` otherwise).

7. **Transfer Amount (from_AN, to_AN, transfer amount)**
   - **Authorized:** User
   - **Request:** Transfer an amount from one account to another.
   - **Response:** Boolean (`true` if transaction is possible, `false` otherwise).

8. **View Bank Database**
   - **Authorized:** Admin
   - **Request:** Retrieve the entire bank database.
   - **Response:** Serialized JSON array of all user data.

9. **Create New User (userdata)**
   - **Authorized:** Admin
   - **Request:** Create a new user with provided data.
   - **Response:** Boolean (`true` if creation is successful, `false` otherwise).

10. **Delete User (accountnumber)**
    - **Authorized:** Admin
    - **Request:** Delete a user by account number.
    - **Response:** Boolean (`true` if deletion is successful, `false` otherwise).

11. **Update User (AN, newData)**
    - **Authorized:** Admin
    - **Request:** Update user data in the database.
    - **Response:** Boolean (`true` if update is successful, `false` otherwise).

## Requirements

1. **System Architecture**
   - The system should be distributed across two applications: one for the client and one for the server.

2. **User Types**
   - Only two user types are supported: standard user and admin.

3. **Framework**
   - Developed using the Qt/C++ framework.

4. **Communication**
   - Client-server communication is handled via sockets.

5. **Client Application**
   - GUI-based application that runs continuously until an exit command is issued.

6. **Server Application**
   - Console application that runs in the background.

7. **Concurrency**
   - The server should handle multiple requests from different clients using threads.

8. **Encryption**
   - Client requests are encrypted before sending. The server decrypts the requests. 
   - **Bonus Point:** Requests include a signature for verification.

9. **Email Notifications**
   - **Bonus Point:** Server responses can be sent to a client’s email.

10. **Design**
    - Use sound OOP design principles with UML diagrams including Sequence, Class, and State diagrams.

11. **Output Formatting**
    - Client application should format JSON data into readable tables.

12. **Version Control**
    - Hosted on a private GitHub repository; will be made public upon delivery.

## Installation and Setup

1. **Clone the Repository**
   ```bash
   git clone https://github.com/yourusername/banking-system.git
   cd banking-system
