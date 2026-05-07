# 🔐 SecureChat

A lightweight, secure, GUI-based chat application built using C++ and socket programming.  
Designed for educational purposes, SecureChat demonstrates real-time communication over a controlled network using client-server architecture.

---

## 📌 Overview

SecureChat is a forum-like messaging application where multiple users can connect to a server and communicate in real time.  
The system emphasizes **networking fundamentals**, **security concepts**, and **GUI-based interaction**.

Unlike modern cloud-based messaging apps, SecureChat operates within a **local network**, allowing better understanding of core communication mechanisms like sockets and protocols.

---

## 🎯 Objectives

- Learn and implement **C++ socket programming**
- Understand **TCP/IP communication**
- Build GUI applications using **Qt Framework**
- Implement **secure communication** using Diffie-Hellman key exchange
- Demonstrate **client-server architecture**

---

## ✨ Features

- 💬 Real-time messaging
- 🧑‍💻 Multi-client support
- 📡 Client-server communication using sockets
- 🔐 Basic cryptography (Diffie-Hellman key exchange)
- 🖥️ GUI-based interface (Qt)
- 🕒 Username and timestamp display
- 📢 Message broadcasting to all connected users

---

## 🏗️ Tech Stack

| Component        | Technology Used        |
|----------------|----------------------|
| Language        | C++                  |
| Networking      | TCP/IP Sockets       |
| GUI             | Qt Framework         |
| Database        | SQLite (optional)    |
| OS Support      | Windows / Linux      |

---

## 🧠 System Architecture

- **Client-Server Model**
  - Server handles multiple client connections
  - Clients send/receive messages through server
- **Communication Protocol**
  - TCP-based socket communication
- **Security Layer**
  - Diffie-Hellman key exchange for secure messaging

---


> 📁 These can be found in the `/docs` or `/assets` folder (if added)

---

## ⚙️ Installation & Setup

### 🔧 Prerequisites

- C++ Compiler (GCC / MSVC)
- Qt Framework installed
- Basic knowledge of networking

---

### 🚀 Steps to Run

#### 1. Clone the repository
```bash
git clone https://github.com/your-username/securechat.git
cd securechat
