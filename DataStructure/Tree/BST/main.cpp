#include <stdio.h>
#include <iostream>
#include <string> // for string, and to_string
#include <iomanip> // for setw, std:left, std:right

typedef int item_type;

typedef struct tree {
  item_type item;
  tree *parent;
  tree *left;
  tree *right;
  
  std::string toString() {
    return std::to_string(item);
  }
} tree;

tree* search(tree *l, item_type x) {
 if (l == NULL) return(NULL); // empty return
 if (l->item == x) return(l); // found right at root, return root

 if (x < l->item) {
   return search(l->left, x);
 } else {
   return search(l->right, x);
 }
}


void traversal_in_order (tree *l) {
  if (l == NULL) return;
  
  traversal_in_order(l->left);
  std::cout << std::left;
  std::cout <<  std::setw(4) << l->item << std::endl;
  std::cout << std::right;
  traversal_in_order(l->right);
}

void traversal_pre_order (tree *l) {
  if (l == NULL) return;
  std::cout << l->item << std::endl;
  traversal_pre_order(l->left);
  traversal_pre_order(l->right);
}

void traversal_post_order (tree *l) {
  if (l == NULL) return;
  traversal_post_order(l->right);
  traversal_post_order(l->left);
  std::cout << l->item << std::endl;
}

tree* find_minimum(tree* l) {
  if ( l==NULL ) return(l);
  tree* min_tree;
  while (l->left != NULL) {
    min_tree = l->left;
  }
  return min_tree;
}

tree* find_maximum(tree *l) {
  if (l == NULL) return(l);
  tree* max_tree;
  while(l->right != NULL) {
    max_tree = l->right;
  }
  return max_tree;
}

void insert_tree(tree **l, item_type x, tree* parent) {
  tree *p; // temporary pointer

  // if we hit leaf, add new node, and move the linked pointer to new node
  if ( (*l) == nullptr) {
    p = (tree*) malloc(sizeof(tree));
    p->item = x;
    p->left = nullptr;
    p->right = nullptr;
    p->parent = parent;
  // update linked subtree
    *l = p;
  }

  if (x < (*l)->item) {
    insert_tree( &((*l)->left), x, *l ); 
  }else {
    insert_tree( &((*l)->right), x, *l);
  }
}