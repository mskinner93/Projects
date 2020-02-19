#include"bst.h"

Tree::Tree()
{
 m_root = NULL; 
}

bool Tree::insert(string title)
{
    return insert(title,m_root);
}

bool Tree::insert(string title, Node *&cur_root)
{   
    if (cur_root == NULL)
    { 
        cur_root = new Node(title);
        return true;
    }

    else if(title < cur_root->m_value)
    {
	return insert(title,cur_root->m_left);
    }

    else if(title == cur_root->m_value)
    {
	return false;
    }

    else
    { 
	return insert(title,cur_root->m_right);
    }
}

void Tree::print(vector<string> &vec)
{
   return print(vec, m_root);
}

void Tree::print(vector<string> &vec, Node *cur_root)
{
  if(cur_root!=NULL)
  {
   print(vec,cur_root->m_left);
   vec.push_back(cur_root->m_value);
   print(vec,cur_root->m_right);
  }
}

void Tree::breadth(vector<string> &vec)
{
   queue<Node*> q;
   q.push(m_root);
   while(!q.empty())
   {
     Node* cur_root = q.front();
     q.pop();
     vec.push_back(cur_root->m_value);
     if(cur_root->m_left!=NULL)
     {
        q.push(cur_root->m_left);
     }
     if(cur_root->m_right!=NULL)
     {
        q.push(cur_root->m_right);
     }
   }
}



int Tree::size()
{
   return size(m_root);
}

int Tree::size(Node* cur_root)
{
   if(cur_root == NULL)
   {
     return 0;
   }
   else
   {
     int tree_size = size(cur_root->m_left) + size(cur_root->m_right);
     return ++tree_size;
   }
}

bool Tree::find(string title)
{
   return find(title,m_root);
}

bool Tree::find(string title, Node *cur_root)
{
   if(cur_root == NULL)
   {
     return false;
   }

   else if(title == cur_root->m_value)
   {
     return true;
   }
 
   else if(cur_root->m_value > title)
   {
     return find(title, cur_root->m_left);
   }

   else
   {
     return find(title, cur_root->m_right);
   }
}

double Tree::average()
{
   return(double) distance(m_root,0) / size();
}

int Tree::distance(Node* cur_root, int level)
{
   if(cur_root == NULL)
   {
     return 0;
   }

   return level + distance(cur_root->m_left,level+1) + distance(cur_root->m_right,level+1);
}

bool Tree::balanced()
{
   if(balanced(m_root) == -1)
   {
     return false;
   }
   else
   {
     return true;
   }

}

int Tree::balanced(Node* cur_root)
{

   if(cur_root == NULL)
   {
     return 0;
   }

   int left = balanced(cur_root->m_left);
   int right = balanced(cur_root->m_right);
   if(left == -1 || right == -1)
   {
      return -1;
   }
     if(abs(left - right) > 1)
     {
        return -1;
     }
     else
     {
        return max(left,right) +1;
     }
}

void Tree::rebalanced()
{
   vector<string>vec;
   print(vec,m_root);
   delete m_root;
   m_root=NULL;
   insert_from_vector(vec,0,vec.size()-1);
}

void Tree::insert_from_vector(vector<string> &vec, int start, int end)
{
  if(start==end)
  {
    insert(vec[start]);
  }
  else if(start < end)
  {
    int middle = (end+start)/2;
    insert(vec[middle]);
    insert_from_vector(vec,middle+1,end);
    insert_from_vector(vec,start,middle-1);
  }
}



