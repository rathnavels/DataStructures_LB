//Rathinavel Sankaralingam
//Mar 1st, 2020

#include<iostream>
#include<algorithm>
#include<stack>
#include <queue>

using namespace std;

struct BalancedStatusWithHeight
{
  bool balanced;
  int height;
};

struct node
{
  int data;
  node *leftChild;
  node *rightChild;

  node(int k) : data(k), leftChild(NULL), rightChild(NULL){}
  node() : leftChild(NULL), rightChild(NULL){}
  
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

  auto left_result = CheckBalanced(tree->leftChild);
  if(!left_result.balanced)
  {
    return {false,0};
  }

  auto right_result = CheckBalanced(tree->rightChild);
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
      current = current->leftChild;
    else
      current = current->rightChild;

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
  temp->leftChild = NULL;
  temp->rightChild = NULL;

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
      current = current->leftChild;

      if(current==NULL)
        parent->leftChild = temp;
    }
    else
    { 
      current = current->rightChild;
      
      if(current==NULL)
        parent->rightChild = temp;
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
    inorder(root->leftChild);
    std::cout << root->data << "\t";
    inorder(root->rightChild);
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
    preorder(root->leftChild);
    preorder(root->rightChild);
  }
}

//-----------------------------------------------------------
// postorder traversal
//-----------------------------------------------------------
void postorder(node *root)
{
  if(root!=NULL)
  {
    postorder(root->leftChild);
    postorder(root->rightChild);
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
        current = current->leftChild;
      }

      if(current==NULL)
      {
        if(!S.empty())
        {
          std::cout << S.top()->data << "\t";
          current = S.top()->rightChild;
          S.pop();
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

    if(temp->rightChild)
      stk.push(temp->rightChild);
    if(temp->leftChild)
      stk.push(temp->leftChild);
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

    if(temp->leftChild)
      stk1.push(temp->leftChild);

    if(temp->rightChild)
      stk1.push(temp->rightChild);
  }

  while(!stk2.empty())
    {
      std::cout << stk2.top()->data << "\t";
      stk2.pop();
    }
}

void runBST()
{
  insert(5);
  insert(6);
  insert(7);
  insert(2);
  insert(3);
  insert(4);


  //inorder(root); 
  //std::cout << std::endl;
  //inorderIterative(root);
  //std::cout << std::endl;
  //preorder(root);
  //std::cout << std::endl;
  //preorderIterative(root);
  postorder(root);
  std::cout << std::endl;
  postorderIterativeTwoStack(root);
  

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
  nd->leftChild = new node(3);
  nd->rightChild = new node(4);
  nd->leftChild->leftChild = new node(5);
  nd->leftChild->rightChild = new node(6);
  nd->rightChild->rightChild = new node(8);

  root = nd;
  
  node *newnd = new node(elem);
  Q.push(root);
  while(!Q.empty())
  {

    node* temp = Q.front();
    Q.pop();

    if(temp->leftChild == NULL)
    {
      temp->leftChild = newnd;
      break;
    }
    else
      Q.push(temp->leftChild);

    if(temp->rightChild == NULL)
    {
      temp->rightChild = newnd;
      break;
    }
    else
      Q.push(temp->rightChild);
  }

  inorder(root);
  std::cout << endl;

}

void findLastNode(node *root, int &elem, node **lastNode)
{
  node *pre = root;
  auto *temp = root;
  while(temp->rightChild)
  {
    pre = temp;
    temp = temp->rightChild;
  }

  if(pre->leftChild && pre->rightChild)
  {
    elem = pre->rightChild->data;
    *lastNode = pre->rightChild;
    //pre->rightChild = NULL;
  }
  
  if(!pre->rightChild && pre->leftChild)
  {
    elem = pre->leftChild->data;
    *lastNode = pre->leftChild;
    //pre->leftChild = NULL;
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

    if(temp->rightChild)
      stk.push(temp->rightChild);

    if(temp->leftChild)
      stk.push(temp->leftChild);
  }

  inorder(root);
}