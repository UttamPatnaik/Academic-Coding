# 🏦 Banking Database – Lab Assignment 1

**Introduction to Databases (CSE 3151)**

---

## 📘 Assignment Information

* **Programme:** B.Tech (CSE & CSIT)
* **Semester:** 6th
* **Course Outcome:** CO2
* **Program Outcomes:** PO1, PO2, PO5
* **Taxonomy Level:** L2, L3

---

## 📌 Database Description

A banking system maintains information about:

* 🏢 Branches
* 👤 Customers
* 💳 Accounts
* 💰 Loans
* 🔄 Transactions

---

## 🎯 Objective

✔ To understand SQL `CREATE` and `INSERT`
✔ To create tables and insert records
✔ To build a banking database

---

# 📝 Questions with Solutions

---

## 🔹 Q1. Create the following tables with columns, data types and sizes

### 📋 Table Structures (Given)

### 🏢 BRANCH

| Column      | Data Type | Size |
| ----------- | --------- | ---- |
| BRANCH_CODE | VARCHAR   | 5    |
| BRANCH_NAME | VARCHAR   | 30   |
| CITY        | VARCHAR   | 20   |

---

### 👤 CUSTOMER

| Column    | Data Type | Size |
| --------- | --------- | ---- |
| CUST_NO   | VARCHAR   | 5    |
| CUST_NAME | VARCHAR   | 30   |
| ADDRESS   | VARCHAR   | 40   |
| PHONE     | NUMERIC   | 10   |

---

### 💳 ACCOUNT

| Column      | Data Type | Size |
| ----------- | --------- | ---- |
| ACC_NO      | VARCHAR   | 10   |
| CUST_NO     | VARCHAR   | 5    |
| BRANCH_CODE | VARCHAR   | 5    |
| ACC_TYPE    | VARCHAR   | 10   |
| BALANCE     | NUMERIC   | 10   |

---

### 💰 LOAN

| Column      | Data Type | Size |
| ----------- | --------- | ---- |
| LOAN_NO     | VARCHAR   | 10   |
| CUST_NO     | VARCHAR   | 5    |
| BRANCH_CODE | VARCHAR   | 5    |
| AMOUNT      | NUMERIC   | 10   |

---

### 🔄 TRANSACTION_DETAILS

| Column       | Data Type | Size |
| ------------ | --------- | ---- |
| TRANS_ID     | VARCHAR   | 10   |
| ACC_NO       | VARCHAR   | 10   |
| TRANS_TYPE   | VARCHAR   | 10   |
| TRANS_AMOUNT | NUMERIC   | 10   |
| TRANS_DATE   | DATE      | —    |

---

### ✅ SQL Implementation

```sql
USE FirstDB;

CREATE TABLE BRANCH (
    BRANCH_CODE VARCHAR(5) PRIMARY KEY,
    BRANCH_NAME VARCHAR(30),
    CITY VARCHAR(20)
);

CREATE TABLE CUSTOMER (
    CUST_NO VARCHAR(5) PRIMARY KEY,
    CUST_NAME VARCHAR(30),
    ADDRESS VARCHAR(40),
    PHONE NUMERIC(10)
);

CREATE TABLE ACCOUNT (
    ACC_NO VARCHAR(10) PRIMARY KEY,
    CUST_NO VARCHAR(5),
    BRANCH_CODE VARCHAR(5),
    ACC_TYPE VARCHAR(10),
    BALANCE NUMERIC(10),
    FOREIGN KEY (CUST_NO) REFERENCES CUSTOMER(CUST_NO),
    FOREIGN KEY (BRANCH_CODE) REFERENCES BRANCH(BRANCH_CODE)
);

CREATE TABLE LOAN (
    LOAN_NO VARCHAR(10) PRIMARY KEY,
    CUST_NO VARCHAR(5),
    BRANCH_CODE VARCHAR(5),
    AMOUNT NUMERIC(10),
    FOREIGN KEY (CUST_NO) REFERENCES CUSTOMER(CUST_NO),
    FOREIGN KEY (BRANCH_CODE) REFERENCES BRANCH(BRANCH_CODE)
);

CREATE TABLE TRANSACTION_DETAILS (
    TRANS_ID VARCHAR(10) PRIMARY KEY,
    ACC_NO VARCHAR(10),
    TRANS_TYPE VARCHAR(10),
    TRANS_AMOUNT NUMERIC(10),
    TRANS_DATE DATE,
    FOREIGN KEY (ACC_NO) REFERENCES ACCOUNT(ACC_NO)
);
```

---

## 🔹 Q2. Insert data into BRANCH table

### 📋 Given Data

| BRANCH_CODE | BRANCH_NAME    | CITY      |
| ----------- | -------------- | --------- |
| B001        | Main Branch    | Delhi     |
| B002        | City Branch    | Mumbai    |
| B003        | Town Branch    | Chennai   |
| B004        | Central Branch | Delhi     |
| B005        | Market Branch  | Bengaluru |

### ✅ SQL Implementation

```sql
INSERT INTO BRANCH (BRANCH_CODE, BRANCH_NAME, CITY) VALUES
('B001', 'Main Branch', 'Delhi'),
('B002', 'City Branch', 'Mumbai'),
('B003', 'Town Branch', 'Chennai'),
('B004', 'Central Branch', 'Delhi'),
('B005', 'Market Branch', 'Bengaluru');
```

---

## 🔹 Q3. Insert data into CUSTOMER table

### 📋 Given Data

| CUST_NO | CUST_NAME    | ADDRESS   | PHONE      |
| ------- | ------------ | --------- | ---------- |
| C001    | Ankit Kumar  | Delhi     | 9876543210 |
| C002    | Anjali Verma | Mumbai    | 9123456780 |
| C003    | Suresh Patel | Ahmedabad | 9988776655 |
| C004    | Neha Sharma  | Jaipur    | 9090909090 |
| C005    | Amit Singh   | Lucknow   | 8899776655 |

### ✅ SQL Implementation

```sql
INSERT INTO CUSTOMER (CUST_NO, CUST_NAME, ADDRESS, PHONE) VALUES
('C001', 'Ankit Kumar', 'Delhi', 9876543210),
('C002', 'Anjali Verma', 'Mumbai', 9123456780),
('C003', 'Suresh Patel', 'Ahmedabad', 9988776655),
('C004', 'Neha Sharma', 'Jaipur', 9090909090),
('C005', 'Amit Singh', 'Lucknow', 8899776655);
```

---

## 🔹 Q4. Insert data into ACCOUNT table

### 📋 Given Data

| ACC_NO | CUST_NO | BRANCH_CODE | ACC_TYPE | BALANCE |
| ------ | ------- | ----------- | -------- | ------- |
| A1001  | C001    | B001        | Savings  | 25000   |
| A1002  | C002    | B002        | Current  | 40000   |
| A1003  | C003    | B003        | Savings  | 18000   |
| A1004  | C004    | B004        | Savings  | 32000   |
| A1005  | C005    | B005        | Current  | 50000   |

### ✅ SQL Implementation

```sql
INSERT INTO ACCOUNT (ACC_NO, CUST_NO, BRANCH_CODE, ACC_TYPE, BALANCE) VALUES
('A1001', 'C001', 'B001', 'Savings', 25000),
('A1002', 'C002', 'B002', 'Current', 40000),
('A1003', 'C003', 'B003', 'Savings', 18000),
('A1004', 'C004', 'B004', 'Savings', 32000),
('A1005', 'C005', 'B005', 'Current', 50000);
```

---

## 🔹 Q5. Insert data into LOAN table

### 📋 Given Data

| LOAN_NO | CUST_NO | BRANCH_CODE | AMOUNT |
| ------- | ------- | ----------- | ------ |
| L2001   | C001    | B001        | 150000 |
| L2002   | C002    | B002        | 200000 |
| L2003   | C003    | B003        | 120000 |
| L2004   | C004    | B004        | 180000 |
| L2005   | C005    | B005        | 250000 |

### ✅ SQL Implementation

```sql
INSERT INTO LOAN (LOAN_NO, CUST_NO, BRANCH_CODE, AMOUNT) VALUES
('L2001', 'C001', 'B001', 150000),
('L2002', 'C002', 'B002', 200000),
('L2003', 'C003', 'B003', 120000),
('L2004', 'C004', 'B004', 180000),
('L2005', 'C005', 'B005', 250000);
```

---

## 🔹 Q6. Insert data into TRANSACTION_DETAILS table

### 📋 Given Data

| TRANS_ID | ACC_NO | TRANS_TYPE | TRANS_AMOUNT | TRANS_DATE  |
| -------- | ------ | ---------- | ------------ | ----------- |
| T001     | A1001  | Deposit    | 5000         | 2025-JAN-10 |
| T002     | A1002  | Withdraw   | 3000         | 2025-JAN-12 |
| T003     | A1003  | Deposit    | 7000         | 2025-OCT-15 |
| T004     | A1004  | Withdraw   | 2000         | 2024-JAN-18 |
| T005     | A1005  | Deposit    | 10000        | 2024-MAR-20 |

### ✅ SQL Implementation

```sql
INSERT INTO TRANSACTION_DETAILS 
(TRANS_ID, ACC_NO, TRANS_TYPE, TRANS_AMOUNT, TRANS_DATE) VALUES
('T001', 'A1001', 'Deposit', 5000, '2025-01-10'),
('T002', 'A1002', 'Withdraw', 3000, '2025-01-12'),
('T003', 'A1003', 'Deposit', 7000, '2025-10-15'),
('T004', 'A1004', 'Withdraw', 2000, '2024-01-18'),
('T005', 'A1005', 'Deposit', 10000, '2024-03-20');
```

---

## ✅ Final Result

🎉 Successfully:

* Created all required tables
* Inserted all records correctly
* Built a complete Banking Database
* Verified all queries executed successfully in MySQL
