#include <stdio.h>
#include <iostream>
#include <string> // for string, and to_string
#include <iomanip> // for setw, std:left, std:right

typedef struct tree {
  int item;
  tree *parent;
  tree *left;
  tree *right;

  tree(): parent(nullptr), left(nullptr), right(nullptr) {}
  tree(int v) {
    tree();
    this->item = v;
  }
} tree;

namespace bst {
  tree* search(tree *l, int x) {
  if (l == nullptr) return(nullptr); // empty return
  if (l->item == x) return(l); // found right at root, return root

  if (x < l->item) {
    return search(l->left, x);
  } else {
    return search(l->right, x);
  }
  }


  void traversal_in_order (tree *l) {
    if (l == nullptr) return;
    
    traversal_in_order(l->left);
    std::cout <<  std::setw(4) << l->item << std::endl;
    traversal_in_order(l->right);
  }

  void traversal_pre_order (tree *l) {
    if (l == nullptr) return;
    std::cout << l->item << std::endl;
    traversal_pre_order(l->left);
    traversal_pre_order(l->right);
  }

  void traversal_post_order (tree *l) {
    if (l == nullptr) return;
    traversal_post_order(l->right);
    traversal_post_order(l->left);
    std::cout << l->item << std::endl;
  }

  tree* find_minimum(tree* l) {
    if ( l==nullptr ) return(l);
    tree* min_tree;
    while (l->left != nullptr) {
      min_tree = l->left;
    }
    return min_tree;
  }

  tree* find_maximum(tree *l) {
    if (l == nullptr) return(l);
    tree* max_tree;
    while(l->right != nullptr) {
      max_tree = l->right;
    }
    return max_tree;
  }

  void insert_tree(tree **l, int x, tree* parent) {
    tree *p; // temporary pointer

    // if we hit leaf, add new node, and move the linked pointer to new node
    if ( (*l) == nullptr) {
      p = new tree(x);
      p->parent = parent;
    // update linked subtree
      *l = p;
      return;
    }
    tree *current = (*l);
    if (x < current->item) {
      insert_tree( &(current->left), x, *l ); 
    }else {
      insert_tree( &(current->right), x, *l);
    }
  }

  namespace {
    void _delete_tree(tree *l) {
      if (l==nullptr) return;
      _delete_tree(l->left);
      _delete_tree(l->right);
      std::cout << "delete " << l->item << std::endl;
      delete l;
    }
  }

  void delete_tree (tree** l) {
    _delete_tree(*l);
    *l = nullptr;
  }

  void pprint(tree* l, int indent = 2) {
    if (l == nullptr) return;
    std::cout << std::setw(indent) << l->item << '\n';
    pprint(l->left, indent + 2);
    pprint(l->right, indent +2);
    if (indent > 2) {
      std::cout<< std::setw(indent) << ' ';
    }
  }

}

int main(int argc, char* argv[]) {
  tree * root = new tree(2);
  int data[] =  {1,7,4,8,6,5};
  int n = sizeof(data) / sizeof(data[0]);
  for (int i = 0; i < n; ++i){
    int v = data[i];
    bst::insert_tree(&root, v, root);
  }
  bst::pprint(root);
  bst::delete_tree(&root);
  return EXIT_SUCCESS;
}
