//Rathinavel Sankaralingam
//Mar 1st, 2020

#include<iostream>
#include<algorithm>
#include<stack>
#include <queue>

// 151 Inorder Traversal
// 164 Prorder Traversal
// 177 PostOrder Traversal
// 190 Inorder Iterative
// 222 Preorder Iterative
// 245 PostOrder Iterative Two Stack
// 274 Sum of K smallest Elements
// 312 Size Of Binary Tree
// 338 Size Of Binary Tree Recursive
// 364 Diameter Of Binary Tree
// 396 Print Root To Leaf






using namespace std;

struct BalancedStatusWithHeight
{
  bool balanced;
  int height;
};

struct node
{
  int data;
  node *left;
  node *right;

  node(int k) : data(k), left(NULL), right(NULL){}
  node() : left(NULL), right(NULL){}
  
};

node *root = NULL;

BalancedStatusWithHeight CheckBalanced(node *tree);

bool IsBalanced(node *root)
{
  return CheckBalanced(root).balanced;
}

BalancedStatusWithHeight CheckBalanced(node *tree)
{
  if(tree == NULL)
  return {true, -1};

  auto left_result = CheckBalanced(tree->left);
  if(!left_result.balanced)
  {
    return {false,0};
  }

  auto right_result = CheckBalanced(tree->right);
  if(!right_result.balanced)
  {
    return {false, 0};
  }

  bool is_balanced = abs(left_result.height - right_result.height) <= 1;
  int height = std::max(left_result.height , right_result.height) +1;
  return {is_balanced, height};
}



//-----------------------------------------------------------
// search
//-----------------------------------------------------------
node* search(int data)
{
  node* current = root;

  if(root==NULL)
    return NULL;

  if(root->data == data)
    return root;
  
  while(1)
  {
    if(current->data > data)  
      current = current->left;
    else
      current = current->right;

    if(current==NULL)   
      return NULL;
    else if (current->data == data)
      return current;
  }
}

//-----------------------------------------------------------
// insert
//-----------------------------------------------------------
void insert(int data)
{
  node *current = NULL;
  node *parent  = NULL;
  
  node *temp = new node();
  temp->data = data;
  temp->left = NULL;
  temp->right = NULL;

  if(root == NULL)
  {
    root = temp;
    return;
  }

  current = root;
  parent = NULL;
  while(current!=NULL)
  {
    parent = current;

    if(current->data > data)
    {
      current = current->left;

      if(current==NULL)
        parent->left = temp;
    }
    else
    { 
      current = current->right;
      
      if(current==NULL)
        parent->right = temp;
    }
  }
}


//-----------------------------------------------------------
// inorder traversal
//-----------------------------------------------------------
void inorder(node *root)
{
  if(root!=NULL)
  {
    inorder(root->left);
    std::cout << root->data << "\t";
    inorder(root->right);
  }
}

//-----------------------------------------------------------
// preorder traversal
//-----------------------------------------------------------
void preorder(node *root)
{
  if(root!=NULL)
  {
    std::cout << root->data << "\t";
    preorder(root->left);
    preorder(root->right);
  }
}

//-----------------------------------------------------------
// postorder traversal
//-----------------------------------------------------------
void postorder(node *root)
{
  if(root!=NULL)
  {
    postorder(root->left);
    postorder(root->right);
    std::cout << root->data << "\t";
  }
}

//-----------------------------------------------------------
// inorderIterative
//-----------------------------------------------------------
void inorderIterative(node *root)
{
  stack<node*> S;
  node *current = root;
  while(1)
  {
      while(current!=NULL)
      {
        S.push(current);
        current = current->left;
      }

      if(current==NULL)
      {
        if(!S.empty())
        {
          current = S.top();
          S.pop();

          std::cout << current->data << "\t";
          
          current = current->right;
        }
        else
          break;
      }
  }
  return;
}
//-----------------------------------------------------------
// preorderIterative
//-----------------------------------------------------------
void preorderIterative(node *root)
{
  stack<node*> stk;
  stk.push(root);

  while(!empty(stk))
  {
    auto temp = stk.top();
    stk.pop();

    std::cout << temp->data << "\t";

    if(temp->right)
      stk.push(temp->right);
    if(temp->left)
      stk.push(temp->left);
  }
}

//-----------------------------------------------------------
// postorderIterative
// Not in proper shape yet
//-----------------------------------------------------------
void postorderIterativeTwoStack(node *root)
{
  stack<node*> stk1, stk2;
  stk1.push(root);

  while(!stk1.empty())
  {
    auto temp = stk1.top();
    stk1.pop();

    stk2.push(temp);

    if(temp->left)
      stk1.push(temp->left);

    if(temp->right)
      stk1.push(temp->right);
  }

  while(!stk2.empty())
    {
      std::cout << stk2.top()->data << "\t";
      stk2.pop();
    }
}

//-----------------------------------------------------------
// Sum of K smallest Elements
//-----------------------------------------------------------
void sumOfKSmallest(node* root, int K)
{
  int sum = 0;
  stack<node*> stk;

  stk.push(root);
  node* current = root;

  while(1)
  {
    while(current)
    { 
      stk.push(current);
      current = current->left;
    }
    
    if(!stk.empty())
    {
      current = stk.top();
      sum += current->data;
      if(--K == 0)
        break;
      
      stk.pop();

      current = current->right;
      
    }
    else
      break;
  }
  cout << sum;
}


//-----------------------------------------------------------
// sizeOfBinaryTree
//-----------------------------------------------------------
void sizeOfBinaryTree(node* root)
{
  size_t size = 0;

  stack<node*> stk;
  stk.push(root);

  while(!stk.empty())
  {
    node* temp = stk.top();
    stk.pop();

    size++;

    if(temp->right)
      stk.push(temp->right);
    if(temp->left)
      stk.push(temp->left);
  }

  cout << size;
}

//-----------------------------------------------------------
// sizeOfBinaryTree Recursive
//-----------------------------------------------------------
int sizeOfBinaryTreeRecursive(node* root)
{
  if(root == NULL)
    return 0;

  return 1 + sizeOfBinaryTreeRecursive(root->left) + sizeOfBinaryTreeRecursive(root->right);
}

//-----------------------------------------------------------
// Diameter Helper
//-----------------------------------------------------------
int diameterHelper(node* root, int &diameter)
{
  if(!root) 
    return 0;

  int L = diameterHelper(root->left,diameter);
  int R = diameterHelper(root->right,diameter);

  diameter = max(diameter,L+R);
  return max(L,R)+1;
}

//-----------------------------------------------------------
// Diameter Of Binary Tree
//-----------------------------------------------------------
int diameterOfBinaryTree(node* root)
{
   int diameter = 0;
   diameterHelper(root,diameter);
   return diameter;
}

//-----------------------------------------------------------
// Root To Leaf Helper
//-----------------------------------------------------------
void rootToLeafHelper(node* root, vector<int> &vec)
{
  if(!root) return;
  vec.push_back(root->data);

  if (!root->left && !root->right)
  {
      for(int i=0; i<vec.size(); i++)
        cout << vec[i] << "\t";

      cout << "\n";

      vec = {};
  }
  vector<int> dup = vec;
  rootToLeafHelper(root->left,vec);
  rootToLeafHelper(root->right,dup);
}

//-----------------------------------------------------------
// Print Root To Leaf
//-----------------------------------------------------------
void runPrintRootToLeafPaths(node* root)
{
  vector<int> vec;
  rootToLeafHelper(root,vec);
}


void runBST()
{
  insert(5);
  insert(6);
  insert(7);
  insert(2);
  insert(3);
  insert(9);
  insert(12);
  insert(1);
  insert(-1);
  insert(8);
  insert(12);

  runPrintRootToLeafPaths(root);

  //sumOfKSmallest(root,4) ;


  //inorder(root); 
  //std::cout << std::endl;
  //inorderIterative(root);
  //std::cout << std::endl;
  //preorder(root);
  //std::cout << std::endl;
  //preorderIterative(root);
  //postorder(root);
  //std::cout << std::endl;
  //postorderIterativeTwoStack(root);

   //cout << sizeOfBinaryTreeRecursive(root);

   //cout << diameterOfBinaryTree(root);
  

  //if(IsBalanced(root))
  //  std::cout << "It is balanced boys\n";
  //else
  //  std::cout << "It is not balanced boys\n";

  std::cin.get();
}


// Insert into Binary Tree iterative
void runInsertBinaryTree(int elem)
{
  std::queue <node*> Q;
  node *nd;
  nd = new node(2);
  nd->left = new node(3);
  nd->right = new node(4);
  nd->left->left = new node(5);
  nd->left->right = new node(6);
  nd->right->right = new node(8);

  root = nd;
  
  node *newnd = new node(elem);
  Q.push(root);
  while(!Q.empty())
  {

    node* temp = Q.front();
    Q.pop();

    if(temp->left == NULL)
    {
      temp->left = newnd;
      break;
    }
    else
      Q.push(temp->left);

    if(temp->right == NULL)
    {
      temp->right = newnd;
      break;
    }
    else
      Q.push(temp->right);
  }

  inorder(root);
  std::cout << endl;

}

void findLastNode(node *root, int &elem, node **lastNode)
{
  node *pre = root;
  auto *temp = root;
  while(temp->right)
  {
    pre = temp;
    temp = temp->right;
  }

  if(pre->left && pre->right)
  {
    elem = pre->right->data;
    *lastNode = pre->right;
    //pre->right = NULL;
  }
  
  if(!pre->right && pre->left)
  {
    elem = pre->left->data;
    *lastNode = pre->left;
    //pre->left = NULL;
  }

}




void runDeleteBinaryTree(int elem)
{
  // Find Last Element
  // Find node to be deleted
  // Set Element
  // Delete last node

  node *lastNode = new node();
  int lastElem;

  findLastNode(root,lastElem,&lastNode);
  delete lastNode;

  inorder(root);
  std::cout << endl;

  stack<node*> stk;
  stk.push(root);
  while(!empty(stk))
  {
    auto temp = stk.top();
    stk.pop();

    if(temp->data == elem)
    {
      temp->data == lastElem;
      break;
    }

    if(temp->right)
      stk.push(temp->right);

    if(temp->left)
      stk.push(temp->left);
  }

  inorder(root);
}