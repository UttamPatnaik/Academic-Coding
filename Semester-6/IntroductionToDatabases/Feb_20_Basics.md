# 🖥 Creating a MySQL User and Database  
**Using MySQL 8.0 on Ubuntu**

This guide demonstrates how to:
- Create a new MySQL user
- Create a database
- Grant privileges
- Log in using the new user

---

## 📌 Step 1: Login to MySQL as Root

```bash
sudo mysql
```

✔ Logs into the MySQL server using administrator (root) privileges.

---

## 📌 Step 2: Create a New User

```sql
CREATE USER "2C1_2341016244" IDENTIFIED BY "2C1_2341016244";
```

✔ Creates a new MySQL user  
✔ Sets a password for the user  
✔ `;` is required to execute the command  

**Expected Output:**

```
Query OK, 0 rows affected
```

---

## 📌 Step 3: Create a New Database

```sql
CREATE DATABASE FirstDB;
```

✔ Creates a database named `FirstDB`

**Expected Output:**

```
Query OK, 1 row affected
```

---

## 📌 Step 4: Grant Privileges to the User

```sql
GRANT ALL PRIVILEGES ON FirstDB.* TO 2C1_2341016244;
```

✔ Grants full access to the user on `FirstDB`  
✔ `FirstDB.*` refers to all tables inside the database  

**Expected Output:**

```
Query OK, 0 rows affected
```

---

## 📌 Step 5: Apply Changes

```sql
FLUSH PRIVILEGES;
```

✔ Reloads the privilege tables  
✔ Ensures permission changes take effect immediately  

---

## 📌 Step 6: Exit MySQL

```sql
EXIT;
```

✔ Exits the MySQL monitor  

---

## 📌 Step 7: Login as the New User

```bash
mysql -h 127.0.0.1 -u 2C1_2341016244 -p
```

✔ `-h 127.0.0.1` → Connect to local MySQL server  
✔ `-u` → Specify username  
✔ `-p` → Prompt for password  

After entering the correct password, you should see:

```
Welcome to the MySQL monitor.
```

---

## ✅ Final Result

🎉 Successfully:
- Created a new MySQL user  
- Created a new database  
- Granted privileges  
- Logged in with the new user  
