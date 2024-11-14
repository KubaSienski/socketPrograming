# Socket Programing Lab

This project demonstrates basic client-server communication using UDP and TCP protocols in C, along with a multi-threaded TCP server in Java. The server takes an integer from the client, calculates its square, and returns the result to the client.

## Contents
UDP Server (C)\
UDP Client (C)\
TCP Server (C)\
TCP Client (C)\
Multi-threaded TCP Server (Java)\
TCP Client (Java)

## How It Works
**UDP:**\
The server and client communicate over UDP without a persistent connection. The client sends an integer, the server computes its square, and sends the result back.

**TCP:** \
The server and client use a persistent TCP connection. The client sends an integer, and the server responds with the squared result.

**Multi-threaded TCP (Java):** \
The TCP server in Java is multi-threaded, allowing it to handle multiple clients concurrently. Each client connection is managed in a separate thread.

## Getting Started
Compilation and Execution
1. UDP Client-Server (C)
**Server**\
Compile the server code:
```
gcc udp_server.c -o udp_server
```
Run the server:
```
./udp_server
```
**Client**\
Compile the client code:
```
gcc udp_client.c -o udp_client
```
Run the client:
```
./udp_client
```

2. TCP Client-Server (C)
**Server**\
Compile the server code:
```
gcc tcp_server.c -o tcp_server
```
Run the server:
```
./tcp_server
```
**Client**\
Compile the client code:
```
gcc tcp_client.c -o tcp_client
```
Run the client:
```
./tcp_client
```
3. Multi-threaded TCP Client-Server (Java)
**Server**\
Compile and run the multi-threaded server code:
```
javac MultiThreadedTCPServer.java
java MultiThreadedTCPServer
```
**Client**\
Compile and run the client code:
```
javac TCPClient.java
java TCPClient
```

## Program Details
**UDP Server and Client (C):**\
UDP Server: Listens on port 8080 and receives an integer from the client, computes its square, and sends the result back.\
UDP Client: Sends an integer to the server and receives the squared result.

**TCP Server and Client (C):**\
TCP Server: Listens on port 8080, accepts a client connection, receives an integer, computes its square, and sends the result back to the client.\
TCP Client: Connects to the server, sends an integer, and receives the squared result.

**Multi-threaded TCP Server and Client (Java):**\
Multi-threaded TCP Server: Listens on port 8080, accepts multiple client connections, and processes each in a separate thread. Each client receives a squared result for the integer it sends.\
TCP Client: Connects to the server, sends an integer, and receives the squared result.
