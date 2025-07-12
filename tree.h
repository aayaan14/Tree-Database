/* tree.h */
#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stddef.h> // For NULL

#include <assert.h>
#include <errno.h>

#define TagRoot 1 /* 00 01*/
#define TagNode 2 /* 00 10*/
#define TagLeaf 4 /* 01 00*/

#define NoError 0

typedef void* Nullptr; 

#define find_last(x)    find_last_linear(x)
#define reterr(x) \
    errno = (x); \
    return NULL 

typedef unsigned int int32;
typedef unsigned short int int16;
typedef unsigned char int8;
typedef unsigned char Tag;

struct s_node{
    Tag tag;
    struct s_node *north; // Parent
    struct s_node *west;  // Node
    struct s_leaf *east;  // Leaves
    int8 path[256];
};
typedef struct s_node Node;

struct s_leaf{
    Tag tag;
    union u_tree *west;  // Parent Node or Prev leaves
    struct s_leaf *east; // Future leaves
    int8 key[128];
    int8 *value;
    int16 size;
};
typedef struct s_leaf Leaf;

union u_tree{
    Node n;
    Leaf l;
};
typedef union u_tree Tree;