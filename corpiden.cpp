#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_map>
#include <map>
#include <algorithm>

using namespace std;

// ================= EMPLOYEE =================
struct Employee {
    int id;
    string name;
    int riskLevel;
    string department;
};

// ================= EMPLOYEE DIRECTORY =================
map<int, Employee> employeeDirectory;

// ================= TEMP ACCESS UNDO =================
stack<int> tempAccessLog;

// ================= BADGE CHECK =================
unordered_map<int, bool> activeBadges;

// ================= REQUEST LINE =================
queue<int> badgeQueue;

// ================= COMPANY MAP =================
vector<int> companyGraph[100];

// ================= RISK SORTER =================
struct CompareRisk {
    bool operator()(Employee a, Employee b) {
        return a.riskLevel < b.riskLevel;
    }
};

priority_queue<Employee, vector<Employee>, CompareRisk> riskHeap;

// ================= TRAFFIC CONTROLLER =================
priority_queue<
pair<int,int>,
vector<pair<int,int>>,
greater<pair<int,int>>
> securityServers;

// =======================================
// Add Employee
// =======================================
void addEmployee(int id, string name, int risk, string dept) {
    Employee emp = {id, name, risk, dept};

    employeeDirectory[id] = emp;
    activeBadges[id] = true;
    riskHeap.push(emp);

    cout << "Employee Added Successfully\n";
}

// =======================================
// Temporary Access
// =======================================
void grantTemporaryAccess(int id) {
    tempAccessLog.push(id);
    cout << "Temporary Access Granted to Employee "
         << id << endl;
}

void revokeLastTemporaryAccess() {
    if(tempAccessLog.empty()) {
        cout << "No Temporary Access Found\n";
        return;
    }

    int id = tempAccessLog.top();
    tempAccessLog.pop();

    cout << "Temporary Access Revoked for Employee "
         << id << endl;
}

// =======================================
// Request Queue
// =======================================
void badgeSwipe(int id) {
    badgeQueue.push(id);
}

void processBadgeSwipe() {
    if(badgeQueue.empty()) {
        cout << "No Pending Requests\n";
        return;
    }

    int id = badgeQueue.front();
    badgeQueue.pop();

    cout << "Processing Badge Swipe of Employee "
         << id << endl;
}

// =======================================
// Badge Verification
// =======================================
void verifyBadge(int id) {
    if(activeBadges.find(id) != activeBadges.end())
        cout << "Badge Valid\n";
    else
        cout << "Badge Invalid\n";
}

// =======================================
// Risk Sorter
// =======================================
void showHighestRiskEmployee() {

    if(riskHeap.empty()) {
        cout << "No Employees\n";
        return;
    }

    Employee emp = riskHeap.top();

    cout << "\nHighest Risk Employee:\n";
    cout << "ID: " << emp.id << endl;
    cout << "Name: " << emp.name << endl;
    cout << "Risk Level: " << emp.riskLevel << endl;
}

// =======================================
// Company Graph
// =======================================
void addConnection(int u, int v) {
    companyGraph[u].push_back(v);
    companyGraph[v].push_back(u);
}

// =======================================
// Quickest Approval Path (BFS)
// =======================================
void shortestApprovalPath(int start, int end) {

    vector<bool> visited(100,false);
    vector<int> parent(100,-1);

    queue<int> q;

    q.push(start);
    visited[start] = true;

    while(!q.empty()) {

        int node = q.front();
        q.pop();

        for(int next : companyGraph[node]) {

            if(!visited[next]) {

                visited[next] = true;
                parent[next] = node;
                q.push(next);
            }
        }
    }

    if(!visited[end]) {
        cout << "No Approval Path Found\n";
        return;
    }

    vector<int> path;

    for(int v=end; v!=-1; v=parent[v])
        path.push_back(v);

    reverse(path.begin(), path.end());

    cout << "\nApproval Path: ";

    for(int node : path)
        cout << node << " ";

    cout << endl;
}

// =======================================
// Traffic Controller
// =======================================
void initializeServers(int n) {

    for(int i=1;i<=n;i++)
        securityServers.push({0,i});
}

void assignSwipeRequest() {

    auto server = securityServers.top();
    securityServers.pop();

    cout << "Assigned to Server "
         << server.second << endl;

    server.first++;

    securityServers.push(server);
}

// =======================================
// MAIN
// =======================================
int main() {

    addEmployee(101,"Alice",8,"HR");
    addEmployee(102,"Bob",4,"IT");
    addEmployee(103,"Charlie",10,"Security");

    cout << "\n=== Badge Verification ===\n";
    verifyBadge(101);

    cout << "\n=== Temporary Access ===\n";
    grantTemporaryAccess(102);
    revokeLastTemporaryAccess();

    cout << "\n=== Request Queue ===\n";
    badgeSwipe(101);
    badgeSwipe(103);

    processBadgeSwipe();
    processBadgeSwipe();

    cout << "\n=== Risk Sorter ===\n";
    showHighestRiskEmployee();

    cout << "\n=== Company Map ===\n";
    addConnection(1,2);
    addConnection(2,3);
    addConnection(3,4);
    addConnection(4,5);

    shortestApprovalPath(1,5);

    cout << "\n=== Traffic Controller ===\n";

    initializeServers(3);

    assignSwipeRequest();
    assignSwipeRequest();
    assignSwipeRequest();
    assignSwipeRequest();

    return 0;
}