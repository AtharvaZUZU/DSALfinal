#include <iostream>
#include <stack>
using namespace std;
struct Node
{
    char data;
    Node *left;
    Node *right;
};
// newNode function
Node *createNode(char data)
{
    Node *newNode = new Node;
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
// contructing expression tree with help of stack
Node *contructTree(string prefix)
{
    stack<Node *> s; // created a stack with dataype as Node and itsvobject as "s" 
    for (int i = prefix.length() - 1; i >= 0; i--)
    {
        // traversing from back to each char of the string
        char c = prefix[i]; // taking the single char

        // chechk if the char "c" is a digit or a alphabet
        if (isdigit(c) || isalpha(c))
        {
            // if we encounter a digit or alphabet we push it into the stack
            Node *newNode = createNode(c);
            s.push(newNode);
        }
        else
        {
            // if we encounter any expression/symbol then
            // first we create its node
            Node *newNode = createNode(c);
            // then we first link the leftsubtree as the first element on the stack
            // and then pop that element
            newNode->left = s.top();
            s.pop();
            // after assigning the left part, then we go for the right subtree
            // by assigning the top element of stack as right and pop that node
            newNode->right = s.top();
            s.pop();
            // then we push the newly created node of the symbol in the stack
            s.push(newNode);
        }
    }
    return s.top();
}
// function for postorder traver
void postOrder(Node *root)
{
    stack<Node *> s;              // created a stack of data type node and object "s"
    Node *lastNodeVisited = NULL; // pointer to maintain the last visited node 
    while (!s.empty() || root != NULL)
    {
        // we will trravers the stack untill the root becomes null or stack is empty 
        if (root != NULL)
        {
            s.push(root);
            root = root->left;
            // in this if the root is not empty then we push the root to stack and go next to its left subtree
        }
        else
        {
            Node *peekNode = s.top(); // with the help of peekNode we keep track of the current node 
            if (peekNode->right != NULL && lastNodeVisited !=peekNode->right)
            {
                root = peekNode->right;
                // in this we check the last node of right subtree is not null and it does not form a cycle / or we dont traverse the same node back again                                                     
            }
            else
            {
                cout << peekNode->data << " ";
                lastNodeVisited = peekNode;
                s.pop();
            }
        }
    }
}
void deleteTree(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}
int main()
{
    int choice;
    string prefix;
    Node *root = NULL;

    do
    {
        cout << "\n Menu";
        cout << "\n 1. Enter the prefix expression";
        cout << "\n 2. Postorder traversal";
        cout << "\n 3. Delete Tree"; 
        cout << "\n 4. Exit";
        cout << "\n Enter Your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            cout << "\n Enter prefix expression: ";
            cin.ignore();
            getline(cin, prefix);
            root = contructTree(prefix);
            break;
        }
        case 2:
        {
            if (root == NULL)
            {
                cout << "\n Tree not constructed yet";
            }
            else
            {
                cout << "\n Postorder traversal of expression tree : "; 
                postOrder(root);
                cout << endl;
            }
            break;
        }
        case 3:
        {
            if (root == NULL)
            {
                cout << "\n Tree not constructed yet";
            }
            else
            {
                deleteTree(root);
                root = NULL;
                cout << "\n Tree deleted";
            }
            break;
        }
        case 4:
        {
            cout << "\n Exiting the program...";
            exit(0);
            break;
        }
        }
        cout << endl;
    } while (choice != 4);
    return 0;
}
