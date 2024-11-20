/*
You have a browser of one tab where you start on the homepage and you can visit another url, get back in the history number of steps or move forward in the history number of steps.

Implement the BrowserHistory class:

BrowserHistory(string homepage) Initializes the object with the homepage of the browser.
void visit(string url) Visits url from the current page. It clears up all the forward history.
string back(int steps) Move steps back in history. If you can only return x steps in the history and steps > x, you will return only x steps. Return the current url after moving back in history at most steps.
string forward(int steps) Move steps forward in history. If you can only forward x steps in the history and steps > x, you will forward only x steps. Return the current url after forwarding in history at most steps.
 

Example:

Input:
["BrowserHistory","visit","visit","visit","back","back","forward","visit","forward","back","back"]
[["leetcode.com"],["google.com"],["facebook.com"],["youtube.com"],[1],[1],[1],["linkedin.com"],[2],[2],[7]]
Output:
[null,null,null,null,"facebook.com","google.com","facebook.com",null,"linkedin.com","google.com","leetcode.com"]

Explanation:
BrowserHistory browserHistory = new BrowserHistory("leetcode.com");
browserHistory.visit("google.com");       // You are in "leetcode.com". Visit "google.com"
browserHistory.visit("facebook.com");     // You are in "google.com". Visit "facebook.com"
browserHistory.visit("youtube.com");      // You are in "facebook.com". Visit "youtube.com"
browserHistory.back(1);                   // You are in "youtube.com", move back to "facebook.com" return "facebook.com"
browserHistory.back(1);                   // You are in "facebook.com", move back to "google.com" return "google.com"
browserHistory.forward(1);                // You are in "google.com", move forward to "facebook.com" return "facebook.com"
browserHistory.visit("linkedin.com");     // You are in "facebook.com". Visit "linkedin.com"
browserHistory.forward(2);                // You are in "linkedin.com", you cannot move forward any steps.
browserHistory.back(2);                   // You are in "linkedin.com", move back two steps to "facebook.com" then to "google.com". return "google.com"
browserHistory.back(7);                   // You are in "google.com", you can move back only one step to "leetcode.com". return "leetcode.com"
 

Constraints:

1 <= homepage.length <= 20
1 <= url.length <= 20
1 <= steps <= 100
homepage and url consist of  '.' or lower case English letters.
At most 5000 calls will be made to visit, back, and forward.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the node structure for the doubly linked list
typedef struct Node {
    char url[21];
    struct Node *prev;
    struct Node *next;
} Node;

// Define the BrowserHistory structure
typedef struct {
    Node *current;
} BrowserHistory;

// Create a new node
Node* createNode(const char *url) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    strcpy(newNode->url, url);
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Initialize the BrowserHistory object
BrowserHistory* browserHistoryCreate(const char *homepage) {
    BrowserHistory *history = (BrowserHistory *)malloc(sizeof(BrowserHistory));
    history->current = createNode(homepage);
    return history;
}

// Visit a new URL
void browserHistoryVisit(BrowserHistory *history, const char *url) {
    Node *newNode = createNode(url);
    history->current->next = newNode;
    newNode->prev = history->current;
    history->current = newNode;
}

// Move back in history by the given number of steps
char* browserHistoryBack(BrowserHistory *history, int steps) {
    while (history->current->prev != NULL && steps > 0) {
        history->current = history->current->prev;
        steps--;
    }
    return history->current->url;
}

// Move forward in history by the given number of steps
char* browserHistoryForward(BrowserHistory *history, int steps) {
    while (history->current->next != NULL && steps > 0) {
        history->current = history->current->next;
        steps--;
    }
    return history->current->url;
}

// Free the BrowserHistory object
void browserHistoryFree(BrowserHistory *history) {
    Node *temp = history->current;
    // Traverse backward to free all nodes
    while (temp->prev != NULL) {
        temp = temp->prev;
    }
    // Free all nodes from the start
    while (temp != NULL) {
        Node *next = temp->next;
        free(temp);
        temp = next;
    }
    free(history);
}

// Main function to demonstrate usage
int main() {
    BrowserHistory *browserHistory = browserHistoryCreate("leetcode.com");
    browserHistoryVisit(browserHistory, "google.com");
    browserHistoryVisit(browserHistory, "facebook.com");
    browserHistoryVisit(browserHistory, "youtube.com");
    printf("%s\n", browserHistoryBack(browserHistory, 1)); // facebook.com
    printf("%s\n", browserHistoryBack(browserHistory, 1)); // google.com
    printf("%s\n", browserHistoryForward(browserHistory, 1)); // facebook.com
    browserHistoryVisit(browserHistory, "linkedin.com");
    printf("%s\n", browserHistoryForward(browserHistory, 2)); // linkedin.com
    printf("%s\n", browserHistoryBack(browserHistory, 2)); // google.com
    printf("%s\n", browserHistoryBack(browserHistory, 7)); // leetcode.com
    browserHistoryFree(browserHistory);
    return 0;
}
