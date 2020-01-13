// Node struct contains data and pointer to next node
struct Node
{
    int data;
    Node *nextNode;
};

// LinkedList struct contains head pointer (pointing to 1st node of LinkedList)
struct LinkedList
{
private:
    Node *head;
    Node *_newNode(int data);
    int _recursiveCount(Node *node);

public:
    LinkedList();
    bool isEmpty();
    void insert(int data);
    void insertAt(int pos, int data);
    void remove(int data);
    void removeAt(int pos);
    void traverse();
    void clear();
    int count();
    int size();
};