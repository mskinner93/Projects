#ifndef BST_H
#define BST_H

#include<iostream>
#include<string>
#include<vector>
#include<queue>
using namespace std;

class Tree
{
   public:
       Tree();
       bool insert(string title);
       void print(vector<string> &vec);
       void breadth(vector<string> &vec);
       int size();
       bool find(string title);
       double average();
       bool balanced();
       void rebalanced();
   
   private:
       class Node
       {
	   public:
		Node(string title)
		{
		   m_value = title;
		}
		~Node(){delete m_left; delete m_right;}
		Node* m_left = NULL;
		Node* m_right = NULL;
		string m_value;

	
       };
       Node* m_root;
          bool insert(string title, Node *&cur_root);
          void print(vector<string> &vec, Node *cur_root);
	  int size(Node* cur_root);
	  bool find(string title, Node *cur_root);
	  int distance(Node* cur_root, int level);
	  int balanced(Node* cur_root);
	  void insert_from_vector(vector<string> &vec, int start, int end);

};

#endif
