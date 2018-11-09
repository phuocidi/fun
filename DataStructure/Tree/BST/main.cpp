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
  std::cout <<  l->item << std::endl;
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

}