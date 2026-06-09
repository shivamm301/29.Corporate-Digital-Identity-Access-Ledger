2.1 Project Title -:

Corporate Digital Identity Access Ledger (BadgeSync)

2.2 Problem Statement

Design and implement a corporate security management system that manages employee 
access rights, badge verification, temporary permissions, organizational approval routing, and 
workload balancing across security servers. The system should efficiently handle thousands of 
employees and millions of badge transactions.

2.3 Objectives
1.Maintain a large employee directory efficiently.
2.Verify badge IDs quickly.
3.Process badge swipes fairly.
4.Revoke temporary access instantly.
5.Sort employees by security risk.
6.Trace employee movement through departments.
7.Find quickest approval paths.
8.Balance requests across security servers.


2.4 System Architecture
                 ┌───────────────────┐
                 │ Employee Directory│
                 │      B-Tree       │
                 └─────────┬─────────┘
                           │
       ┌───────────────────┼───────────────────┐
       │                   │                   │
       ▼                   ▼                   ▼
Badge Check        Request Queue      Temporary Access
  Hash Table            Queue                Stack

       │
       ▼

  Risk Analysis
   Merge Sort

       │
       ▼

Company Structure Graph
       │
       ▼

Approval Path Finder
   Dijkstra BFS

       │
       ▼

Load Balancer
  Min Heap

2.5  Table of given data below-:
Feature              Data Structure               Reason
Employee Directory       B-Tree             Disk optimized indexing
Temporary Access Undo    Stack            Last access granted removed first
Request Line             Queue                   FIFO processing
Badge Check            Hash Table                  O(1) lookup
Risk Sorter            Merge Sort          Efficient large-scale sorting
Company Map               Graph             Represents departments/zones
Quickest Approval    Dijkstra Algorithm      Shortest approval path
Traffic Controller       Min Heap          Assign least-loaded server

2.6 Data Structure Justification

1. Employee Directory (B-Tree)
   
Real corporate databases use B-Trees because:

  .Optimized for disk storage
  .Reduces disk reads
  .Efficient indexing
  
Operations:

Search : O(log n)
Insert : O(log n)
Delete : O(log n)

2. Temporary Access Undo (Stack)
   
Example:

Visitor Access Granted
Manager Access Upgrade
Server Room Access

Undo
↓
Server Room Access Removed

Operations:

Push : O(1)
Pop : O(1)


3. Badge Swipe Queue
   
Morning entry:

A001
A002
A003
A004

Processed in same order.

Operations:

Enqueue : O(1)
Dequeue : O(1)


4. Badge Verification (Hash Table)
   
Badge ID → Employee

Example:

A102 → John
A103 → Emma

Lookup:

O(1)

5. Risk Sorter (Merge Sort)
   
Risk Score:

Employee A = 90
Employee B = 20
Employee C = 75

Sorted:

90
75
20

Complexity:

O(n log n)


6. Company Map (Graph)
   
Example:

Reception ─ HR
    │
    ├── Finance
    │
    └── Server Room
    
Used for:

.Movement tracking
.Access path tracing


7. Quickest Approval (Dijkstra)
   
Approval hierarchy:

Employee
  ↓
Manager
  ↓
Director
  ↓
Security Head

Shortest approval route found automatically.

Complexity:

O(E log V)


8. Traffic Controller (Min Heap)
   
Servers:

Server 1 : 15 requests
Server 2 : 5 requests
Server 3 : 10 requests

New request goes to:

Server 2

Complexity:

O(log n)


2.7 Time Complexity Analysis
Operation           Data Structure          Complexity
Employee Search         B-Tree               O(log n)
Badge Verification    Hash Table               O(1)
Add Swipe Request        Queue                 O(1)
Undo Access              Stack                 O(1)
Risk Sorting           Merge Sort            O(n log n)
Company Navigation    Graph DFS/BFS           O(V+E)
Approval Path           Dijkstra             O(E log V)
Server Assignment       Min Heap              O(log n)


2.8 Execution Steps

Step 1

Load employee profiles.

Step 2

Store badge IDs in hash table.

Step 3

Employee swipes badge

Step 4

Queue stores request.

Step 5

Badge verified.

Step 6

Access granted or denied.

Step 7

Temporary permissions logged in stack.

Step 8

Graph tracks movement.

Step 9

Dijkstra finds approval path.

Step 10

Min Heap balances server load.


2.9 Sample Input

Employees:

101 Alice
102 Bob
103 Charlie

Badge Swipe:

102

Temporary Upgrade:

Visitor_01

Risk Scores:

Alice 70
Bob 90
Charlie 40


Sample Output

Badge Verified : Bob

Queue Processed Successfully

Temporary Access Granted

Highest Risk Employee:
Bob (90)

Shortest Approval Path:
Employee → Manager → Security Head

Request Assigned To:
Server 2


2.10 Expected Screens
1.Employee Directory Screen
2.Badge Verification Screen
3.Swipe Request Queue Screen
4.Temporary Access Log Screen
5.Risk Analysis Screen
6.Company Map Graph Screen
7.Approval Path Screen
8.Load Balancer Dashboard


2.11 Results and Observations
 .Fast employee lookup using B-Tree indexing.
 .Constant-time badge verification with hashing.
 .Fair request processing using queues.
 .Immediate permission rollback using stack.
 .Efficient risk auditing through sorting.
 .Employee movement tracking via graph traversal.
 .Fast approval routing using shortest-path algorithms.
 .Balanced workload distribution using min-heaps.


 Conclusion
The BadgeSync system combines B-Tree, Hash Table, Queue, Stack, Graph, Merge Sort, 
Dijkstra Algorithm, and Min Heap to create a scalable corporate access-control solution 
similar to those used in enterprise security systems and identity-management platforms.


















































