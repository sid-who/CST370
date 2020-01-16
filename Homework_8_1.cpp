/*
 * HackerRank link:
 * Title:
 * Abstract:
 * Author:
 * ID:
 * Date:
 */
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

vector<int> keys;

struct Node
{
    int data;
    Node* left;
    Node* right;


    //Constructor for a new node.
    Node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

/*
 * mkTree function incorporates logic from the following
 * webpage: https://www.geeksforgeeks.org/construct-complete-binary-tree-given-array/
 */
Node* mkTree(vector<int> vec, Node* root, int index, int sampleSize)
{
    if(index < sampleSize)
    {
        Node* temp = new Node(vec[index]);
        root = temp;

        //left child insert
        root->left = mkTree(vec, root->left, index*2, sampleSize);

        //right child insert
        root->right = mkTree(vec, root->right, (index*2)+1, sampleSize);
    }
    return root;
}

/*
 * Insertion method references elements from the following page:
 * https://www.geeksforgeeks.org/insertion-in-a-binary-tree-in-level-order/
 */
void append(Node* root, int appKey)
{
    Node* newNode = new Node(appKey);
    queue<Node*> here;

    while(!here.empty())
    {
        Node* temp = here.front();
        here.pop();

        if(temp->left == NULL)
        {
            temp->left = newNode;
        }
        else
        {
            here.push(temp->left);
        }

        if(temp->right == NULL)
        {
            temp->right = newNode;
        }
        else
        {
            here.push(temp->right);
        }
    }
}

void postOrder(Node* root)
{
    if(root != NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->data << " ";
    }
}

void preOrder(Node* root)
{
    if(root != NULL)
    {
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inorder(Node* root) 
{
    if (root != NULL)//nullptr)  // Or simply "if (root)"
    {
        inorder(root->left);
        cout << root->data << " "; //<< endl;
        inorder(root->right);
    }
}

/*
 * This method contains elements found at:
 * https://www.geeksforgeeks.org/write-a-c-program-to-find-the-maximum-depth-or-height-of-a-tree/
 * & https://csegeek.com/csegeek/view/tutorials/algorithms/trees/tree_part3.php
 */
int height(Node* root)
{
    if (root == NULL)
         return 0;

      // find the height of each subtree
      int lh = height(root->left);
      int rh = height(root->right);

      return 1 + max(lh,rh);
    /*if(root != NULL)
    {
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);

        if(leftHeight > rightHeight)
        {
            return(leftHeight + 1);
        }
        else
        {
            return(rightHeight)+ 1);
        }
    }
    return 0;*/
}

/*
 * This method contains elements sourced from:
 * https://www.geeksforgeeks.org/a-program-to-check-if-a-binary-tree-is-bst-or-not/
 */
 /* Returns true if the given 
tree is a BST and its values 
are >= min and <= max. */
int isBSTUtil(Node* node, int min, int max)  
{  
    /* an empty tree is BST */
    if (node==NULL)  
        return 1;  
              
    /* false if this node violates 
    the min/max constraint */
    if (node->data < min || node->data > max)  
        return 0;  
      
    /* otherwise check the subtrees recursively,  
    tightening the min or max constraint */
    return
        isBSTUtil(node->left, min, node->data-1) && // Allow only distinct values  
        isBSTUtil(node->right, node->data+1, max); // Allow only distinct values  
}  
int isBST(Node* node)  
{  
    return(isBSTUtil(node, INT_MIN, INT_MAX));  
}  
  

/* bool isBSTUtil(struct Node* root, Node *&prev) 
{ 
    // traverse the tree in inorder fashion and  
    // keep track of prev node 
    if (root) 
    { 
        if (!isBSTUtil(root->left, prev)) 
          return false; 
   
        // Allows only distinct valued nodes  
        if (prev != NULL && root->data <= prev->data) 
          return false; 
   
        prev = root; 
   
        return isBSTUtil(root->right, prev); 
    } 
   
    return true; 
} 
bool isBST(Node* root)
{
    Node *prev = NULL; 
    return isBSTUtil(root, prev);
}*/

int main()
{
    int numNodes;
    int input;

    cin >> numNodes;
    keys.push_back(-99);

    for(int i=1; i<=numNodes; i++)
    {
        cin >> input;

        keys.push_back(input);
    }

    int size = keys.size();
    Node* root = mkTree(keys, root, 1, size);

    int commands;

    cin >> commands;

    string command;

    vector<string> cList;
    queue<int> appends;

    for(int i=0; i<commands; i++)
    {
        cin >> command;
        cList.push_back(command);
        if(command == "append")
        {
            cList.push_back(command);
            int temp;
            cin >> temp;
            appends.push(temp);
            keys.push_back(temp);
        }
    }

    for(int i=0; i<cList.size(); i++)
    {
        string commander = cList[i];

        if(commander == "isBST")
        {
            //cout << "BST WORKS \n";
            if(isBST(root) == 1)
            {
                cout << "true" << endl;
            }
            else
            {
                cout << "false" << endl;
            }
        }
        else if(commander == "append")
        {
            //int temp;
            //cin >> temp;
            //cout << "APPEND WORKS FOR: " << temp << "\n";
            //int newKey = appends.front();
            //appends.pop();
            //append(root, newKey);
            //root->left = NULL;
            //root->right = NULL;
            size = keys.size();
            root = mkTree(keys, root, 1, size);
        }
        else if(commander == "preOrder")
        {
            //cout << "PRE-ORDER WORKS \n";
            preOrder(root);
            cout << "\n";
        }
        else if(commander == "postOrder")
        {
            //cout << "POST-ORDER WORKS \n";
            postOrder(root);
            cout << "\n";
        }
        else if(commander == "inOrder")
        {
            //cout << "IN-ORDER WORKS \n";
            inorder(root);
            cout << "\n";
        }
        else if(commander == "height")
        {
            //cout << "HEIGHT WORKS \n";
            int h = height(root) - 1;
            cout << h << endl;
            //cout << height(root) << endl;
        }
    }

    /*
    need to build:
    -isBST <boolean> //done
    -append <int>
    -preorder //done
    -postorder //done
    -inorder //done
    -height

*/

}
