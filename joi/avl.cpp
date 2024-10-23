#include <iostream>
using namespace std;

// AVL Tree Node class
class AVLNode
{
public:
    int key;
    AVLNode *left;
    AVLNode *right;
    int height;

    // Constructor
    AVLNode(int key)
    {
        this->key = key;
        left = nullptr;
        right = nullptr;
        height = 1;
    }
};

// AVL Tree class
class AVLTree
{
private:
    // Utility function to get the height of a node
    int height(AVLNode *n)
    {
        return n == nullptr ? 0 : n->height;
    }

    // Utility function to get the balance factor of a node
    int getBalance(AVLNode *n)
    {
        if (n == nullptr)
            return 0;
        return height(n->left) - height(n->right);
    }

    // Utility function to perform a right rotation
    AVLNode *rightRotate(AVLNode *y)
    {
        AVLNode *x = y->left;
        AVLNode *T2 = x->right;

        // Perform rotation
        x->right = y;
        y->left = T2;

        // Update heights
        y->height = max(height(y->left), height(y->right)) + 1;
        x->height = max(height(x->left), height(x->right)) + 1;

        // Return new root
        return x;
    }

    // Utility function to perform a left rotation
    AVLNode *leftRotate(AVLNode *x)
    {
        AVLNode *y = x->right;
        AVLNode *T2 = y->left;

        // Perform rotation
        y->left = x;
        x->right = T2;

        // Update heights
        x->height = max(height(x->left), height(x->right)) + 1;
        y->height = max(height(y->left), height(y->right)) + 1;

        // Return new root
        return y;
    }

    // Utility function to find the node with the minimum key value in a tree
    AVLNode *minValueNode(AVLNode *node)
    {
        AVLNode *current = node;
        while (current->left != nullptr)
            current = current->left;
        return current;
    }

    // Internal function to insert a key in the AVL tree
    AVLNode *insert(AVLNode *node, int key)
    {
        // Normal BST insertion
        if (node == nullptr)
            return new AVLNode(key);

        if (key < node->key)
            node->left = insert(node->left, key);
        else if (key > node->key)
            node->right = insert(node->right, key);
        else
            return node; // Equal keys not allowed

        // Update height of this node
        node->height = 1 + max(height(node->left), height(node->right));

        // Check balance and balance the tree
        int balance = getBalance(node);

        // Left Left Case
        if (balance > 1 && key < node->left->key)
            return rightRotate(node);

        // Right Right Case
        if (balance < -1 && key > node->right->key)
            return leftRotate(node);

        // Left Right Case
        if (balance > 1 && key > node->left->key)
        {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        // Right Left Case
        if (balance < -1 && key < node->right->key)
        {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node; // Return the (unchanged) node pointer
    }

    // Internal function to delete a node from the AVL tree
    AVLNode *deleteNode(AVLNode *root, int key)
    {
        if (root == nullptr)
            return root;

        if (key < root->key)
            root->left = deleteNode(root->left, key);
        else if (key > root->key)
            root->right = deleteNode(root->right, key);
        else
        {
            if ((root->left == nullptr) || (root->right == nullptr))
            {
                AVLNode *temp = root->left ? root->left : root->right;
                if (temp == nullptr)
                {
                    temp = root;
                    root = nullptr;
                }
                else
                    *root = *temp;
                delete temp;
            }
            else
            {
                AVLNode *temp = minValueNode(root->right);
                root->key = temp->key;
                root->right = deleteNode(root->right, temp->key);
            }
        }

        if (root == nullptr)
            return root;

        root->height = 1 + max(height(root->left), height(root->right));
        int balance = getBalance(root);

        // Left Left Case
        if (balance > 1 && getBalance(root->left) >= 0)
            return rightRotate(root);

        // Left Right Case
        if (balance > 1 && getBalance(root->left) < 0)
        {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }

        // Right Right Case
        if (balance < -1 && getBalance(root->right) <= 0)
            return leftRotate(root);

        // Right Left Case
        if (balance < -1 && getBalance(root->right) > 0)
        {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }

        return root;
    }

    // Internal function to search for a key in the AVL tree
    bool search(AVLNode *node, int key)
    {
        if (node == nullptr)
            return false;
        if (node->key == key)
            return true;
        if (key < node->key)
            return search(node->left, key);
        return search(node->right, key);
    }

    // Internal function to pre-order traverse the AVL tree
    void preOrder(AVLNode *node)
    {
        if (node != nullptr)
        {
            cout << node->key << " ";
            preOrder(node->left);
            preOrder(node->right);
        }
    }

    void inorder(AVLNode *node)
    {
        if (node != nullptr)
        {
            inorder(node->left);
            cout << node->key << " ";
            inorder(node->right);
        }
    }

    void postorder(AVLNode *node)
    {
        if (node != nullptr)
        {
            postorder(node->left);
            postorder(node->right);
            cout << node->key << " ";
        }
    }

public:
    AVLNode *root;

    // Constructor
    AVLTree()
    {
        root = nullptr;
    }

    // Public function to insert a key
    void insert(int key)
    {
        root = insert(root, key);
    }

    // Public function to delete a key
    void deleteNode(int key)
    {
        root = deleteNode(root, key);
    }

    // Public function to search for a key
    bool search(int key)
    {
        return search(root, key);
    }

    // Public function to pre-order traverse the tree
    void preOrder()
    {
        preOrder(root);
        cout << endl;
    }

    void inorder()
    {
        inorder(root);
        cout << endl;
    }

    void postorder()
    {
        postorder(root);
        cout << endl;
    }

    // Function to add a subtree to an existing tree
    void addSubtree(AVLNode *subtree)
    {
        root = addSubtree(root, subtree);
    }

    AVLNode *addSubtree(AVLNode *node, AVLNode *subtree)
    {
        if (subtree == nullptr)
            return node;
        node = insert(node, subtree->key);
        node = addSubtree(node, subtree->left);
        node = addSubtree(node, subtree->right);
        return node;
    }
};

// Main function to demonstrate the AVL tree operations
int main()
{
    AVLTree tree;

    // Insert elements
    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    tree.insert(40);
    tree.insert(50);
    tree.insert(25);

    cout << "Preorder traversal of the constructed AVL tree is:\n";
    tree.preOrder();

    cout << "Inorder traversal of the constructed AVL tree is:\n";
    tree.inorder();

    // Delete element
    tree.deleteNode(30);
    cout << "Preorder traversal after deletion of 30:\n";
    tree.preOrder();

    cout << "Inorder traversal after deletion of 30:\n";
    tree.inorder();

    // Search for a key
    int keyToSearch = 25;
    if (tree.search(keyToSearch))
        cout << keyToSearch << " exists in the tree.\n";
    else
        cout << keyToSearch << " does not exist in the tree.\n";

    // Adding a subtree
    AVLTree subtree;
    subtree.insert(35);
    subtree.insert(15);

    tree.addSubtree(subtree.root);
    cout << "Preorder traversal after adding subtree:\n";
    tree.preOrder();

    cout << "Inorder traversal after adding subtree:\n";
    tree.inorder();

    return 0;
}
