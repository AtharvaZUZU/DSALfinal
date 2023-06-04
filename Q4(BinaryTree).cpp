#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;
};
// function to create a new node
Node *createNode(int value)
{
    Node *newNode = new Node;
    newNode->data = value; // assign data;
    newNode->left = NULL;  // left pointer null
    newNode->right = NULL; // right pointer null
    return newNode;
}
// function to insert a node accorfing to BST
Node *insertNode(Node *root, int value)
{
    if (root == NULL)
    {
        root = createNode(value); // if tree is empty create new node and assignit root
    }
    else if (value <= root->data)
    {
        root->left = insertNode(root->left, value); // if value less than root->data we add value in its left subtree
    }
    else
    {
        root->right = insertNode(root->right, value); // if value greater than root->data we add value in its right subtree
    }
    return root;
}
// function to find height
int findHeight(Node *root)
{
    if (root == NULL)
    {
        return -1; // tree is empty
    }
    else
    {
        int leftHeight = findHeight(root->left);// height of legt subtree 
        int rightHeight = findHeight(root->right); // height of right subtree 
        return max(leftHeight, rightHeight) + 1;// we compare both height, and return the max height of the BST among them
    }
}
// function to find minimum value of data in tree
int findMin(Node *root)
{
    if (root == NULL)
    {
        cout << "\n Tree is empty!";
        return -1;
    }
    else if (root->left == NULL)
    {
        return root->data; // comdition when we reach the left most node of BST
    }
    else
    {
        return findMin(root->left); // condition to go to the next left subtree
    }
}
// function to swap tree
Node *swap(Node *root)
{
    if (root == NULL)
    {
        return NULL;
    }
    else
    {
        Node *temp = root->left;
        root->left = root->right;
        root->right = swap(temp);
        return root;
    }
}
// Function to find a node in BST
bool search(Node *root, int value)
{
    if (root == NULL)
    {
        return false;
    }
    else if (root->data == value)
    {
        return true;
    }
    else if (value < root->data)
    {
        return search(root->left, value);
    }
    else
    {
        return search(root->right, value);
    }
}
void printMenu()
{
    cout << "\n Menu: ";
    cout << "\n 1. Insert a new node.";
    cout << "\n 2. Find the number of nodes in longest path from root.";
    cout << "\n 3. Find the minimum data value in the tree";
    cout << "\n 4. Search the value.";
    cout << "\n 5. Swap the left and right pointers at every node.";
    cout << "\n Press 0 to exit.";
}

int main()
{
    Node *root = NULL;
    int arr[] = {};
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < n; i++)
    {
        root = insertNode(root, arr[i]);
        // creating newnode at each index of the array;
    }

    int choice = 6;
    int value;

    while (choice != 0)
    {
        printMenu();
        cout << "\n\n Enter Your Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            cout << "\n Enter the value to be inserted: ";
            cin >> value;
            root = insertNode(root, value);
            cout << "\n Node inserted successfully!";
            break;
        }
        case 2:
        {
            cout << "\n The number of nodes in the longest path from root is : "; 
                               cout
                 << findHeight(root);
            break;
        }
        case 3:
        {
            cout << "\n The minimum data in the tree is: ";
            cout << findMin(root);
            break;
        }
        case 4:
        {
            cout << "\n Enter the value to be searched: ";
            cin >> value;
            if (search(root, value))
            {
                cout << "\n The value " << value << " is present in the tree."; 
            }
            else
            {
                cout << "\n The value " << value << " is not present in the tree.";
            }
            break;
        }
        case 5:
        {
            root = swap(root);
            cout << "\n The tree has been swapped successfully !"; 
                break;
        }
        case 0:
        {
            cout << "\n Exiting the program...";
            exit(0);
            break;
        }
        default:
        {
            cout << "\n Error: Invalid choice! Please enter a valid choice."; 
                    break;
        }
        }
        cout << endl;
    }
    return 0;
}
