// listsort --- read a file of strings and sort them (inefficiently) using a
//              linked list; output is the sorted list or if -f is specified
//		the frequency appears before each string and duplicates are 
//              suppressed

#include <stdlib.h> //
#include <stdio.h> //
#include <string.h> //
#include <assert.h> //

/*
    char s[6]="hello"
*/

#define MAX_BUF 256
#define MAX_NODE 128

typedef char charstr[MAX_BUF];

struct node {
    charstr str;
    int count;
    struct node *next;
};

struct node *newnode(charstr m);
void addlist(charstr m);

struct node Node[MAX_NODE];
struct node *Nodehead = NULL;
int NNode = 0;
int Print_frequency = 0;

int main(int argc, char *argv[]) {
    char *fname;
    charstr buf;
    FILE *fd;
    int argx = 1;

// Get the file name and optional argument
   while (argx < argc && argv[argx][0] == '-') {
	if (argv[argx][1] == 'f') 
	    Print_frequency = 1;
	else{
	    fprintf(stderr, "Usage: %s [-f] filename", argv[0]);
	    exit(1);
	    }
	argx++;
	}
   if (argx >= argc) {
        fprintf(stderr, "Usage: %s [-f] filename", argv[0]);
	exit(1);
	}
   fname = argv[argx];
	
// Open the file
   if ((fd = fopen(fname, "r")) == NULL) {
	perror(fname);
        exit(1);
   }

// Read through the file sorting each string as it's read
    while (fgets(buf, sizeof(buf), fd) != NULL) {
	int i;
	// Drop everthing after a newline
	for (i = 0; i < sizeof(buf) && buf[i] != '\n'; i++)
	    ;
	buf[i] = '\0';

	// Add it to the list
	addlist(buf);
    }

// Close the file
    fclose(fd);

// Print the resulting sorted list
    for (struct node *p = Nodehead; p != 0; p = p->next) {
	if (Print_frequency)
	    printf("%10d %s\n", p->count, p->str);
	else
	    for (int i = 0; i < p->count; i++)
		printf("%s\n", p->str);
    }

// Done
    exit(0);
}

// addlist --- add a string to the sorted list
//             increase the count on duplicate, otherwise add a new node
void addlist(charstr m) {
    struct node *p, *q, *lp;

// Find the node >= our string in the list
    for (lp = NULL, p = Nodehead; p != NULL && strcmp(p->str, m) <= 0;
			lp = p, p = p->next) 
	;

    // If lp is NULL, start the list with a new node
    if (lp == NULL) {
	q = Nodehead;
	Nodehead = newnode(m);
	Nodehead->next = q;
	}
    // If m is a duplicate, increment count
    else if (strcmp(m, lp->str) == 0)
	lp->count++;
    // Otherwise, make a new node and link it into the list
    else {
        q = newnode(m);
	q->next = lp->next;
	lp->next = q;
    } 
}

// newnode --- get a new node entry and initialixe it 
struct node *newnode(charstr m) {
    struct node *q;

    NNode++;

// Make sure there is room for the new node
    assert(NNode < sizeof(Node) / sizeof(Node[0]));

    q = &Node[NNode];
    strncpy(q->str, m, sizeof(q->str));
    q->count = 1;
    q->next = NULL;

    return q;
}
