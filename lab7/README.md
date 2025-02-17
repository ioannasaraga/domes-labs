# Lab 7 - AVL Trees

Σε αυτό το εργαστήριο θα εξετάσουμε και θα υλοποιήσουμε rotations και AVL δένδρα.

Η δομή του AVL δένδρου αποτελείται από το struct:
```c
typedef struct avl_node {
    int key;
    struct avl_node *left;
    struct avl_node *right;
    int height;
} AVLTree;
```
Το παραπάνω struct είναι πολύ παρόμοιο με ένα BST, με την προσθήκη ενός επιπλέον πεδίου του height, στο οποίο αποθηκεύεται το ύψος του δένδρου σε αυτό τον κόμβο.

## Τι είναι ένα AVL?

Ένα AVL tree είναι ένα BST με μια επιπλέον συνθήκη:

Για κάθε κόμβο: 
$$∣height(left-subtree) − height(right-subtree)∣ ≤ 1$$

Δηλαδή:
- Κανένα υποδέντρο δεν μπορεί να έχει μεγαλύτερο ή μικρότερο ύψος απο το άλλο (αριστερό/δεξί υποδέντρο)
- Θυμηθείτε: height (ύψος) είναι το μέγεθος του μεγαλύτερου μονοπατιού απο την ρίζα μέχρι τα φύλλα. Π.χ δέντρο με ρίζα μόνο, έχει ύψος 0, ενώ κενό δέντρο height = -1.
- Ονομασία απο τους Ρώσσους μαθηματικούς Adelson-Velskii and Landis 🪆

### Insert

Η διαδικασία εισαγωγής ακολουθεί τα ακόλουθα βήματα:

1. Αρχικά, εκτελείται μια απλή εισαγωγή του κόμβου στο δέντρο, όπως στα κανονικά δυαδικά δέντρα αναζήτησης BST.
2. Στη συνέχεια, ενημερώνεται το ύψος του κόμβου που μόλις εισήχθη.
3. Υπολογίζεται το balance factor του κόμβου, δηλαδή η διαφορά του ύψους του αριστερού υποδέντρου από το ύψος του δεξιού υποδέντρου.
4. Αν ο balance factor είναι μεγαλύτερος από 1 ή μικρότερος από -1, τότε σημαίνει ότι το δέντρο έχει ανισορροπία και πρέπει να επαναζυγιστεί.
5. Αν οι κόμβοι βρίσκονται στο αριστερό υποδέντρο του πατέρα και του παππού τους, τότε πραγματοποιείται μια δεξιά περιστροφή στον παππού κόμβο.
6. Αν οι κόμβοι βρίσκονται στο δεξί υποδέντρο του πατέρα και στο αριστερό υποδέντρο του παιδιού του, τότε πραγματοποιείται μια αριστερή περιστροφή στον πατέρα και στη συνέχεια μια δεξιά περιστροφή.

__Οι περιπτώσεις όπου παρατηρούμε ανισσοροπία σε έναν κόμβο z με παιδιά x και y είναι:__

<details>
<summary>ο y να είναι το αριστερό παιδί του z και ο x το αριστερό παιδί του y <b>(Left Left Case)</b> </summary>
<pre>
T1, T2, T3 and T4 are subtrees.
         z                                      y 
        / \                                   /   \
       y   T4      Right Rotate (z)          x      z
      / \          - - - - - - - - ->      /  \    /  \ 
     x   T3                               T1  T2  T3  T4
    / \
  T1   T2
<pre>
</details>

<details>
<summary>ο y να είναι το αριστερό παιδί του z και ο x το δεξί παιδί του y <b>(Left Right Case)</b> </summary>
<pre>
     z                               z                           x
    / \                            /   \                        /  \ 
   y   T4  Left Rotate (y)        x    T4  Right Rotate(z)    y      z
  / \      - - - - - - - - ->    /  \      - - - - - - - ->  / \    / \
T1   x                          y    T3                    T1  T2 T3  T4
    / \                        / \
  T2   T3                    T1   T2
<pre>
</details>

<details>
<summary>ο y να είναι το δεξί παιδί του z and και ο x το δεξί παιδί του y <b>(Right Right Case)</b> </summary>
<pre>
  z                                y
 /  \                            /   \ 
T1   y     Left Rotate(z)       z      x
    /  \   - - - - - - - ->    / \    / \
   T2   x                     T1  T2 T3  T4
       / \
     T3  T4
<pre>
</details>

<details>
<summary>ο y να είναι το δεξί παιδί του z and και ο x το αριστερό παιδί του y <b>(Right Left Case)</b> </summary>
<pre>
   z                            z                            x
  / \                          / \                          /  \ 
T1   y   Right Rotate (y)    T1   x      Left Rotate(z)   z      y
    / \  - - - - - - - - ->     /  \   - - - - - - - ->  / \    / \
   x   T4                      T2   y                  T1  T2  T3  T4
  / \                              /  \
T2   T3                           T3   T4
<pre>
</details>

```c
Function AVL_INSERT(node, key):

    //1. Perform a simple BST tree insertion
    IF node IS NOT EMPTY THEN:
        RETURN AVL_CREATE_NODE(key)
    
    // Same as BST
    IF key > node.key THEN:
        node.right = AVL_INSERT(node.right, key)
    ELSE IF key < node.key THEN:
        node.left = AVL_INSERT(node.left, key)
    ELSE:
        RETURN node

    //2. Update the height of the node (maximum subtree + 1)
    node.height = MAX(RIGHT_SUBTREE_HEIGHT, LEFT_SUBTREE_HEIGHT) + 1

    //3. Get the balance factor of the current node
    balance = AVL_BALANCE(node)

    //4. Perform the rotations

    // Left-Left case
    IF balance > 1 AND key < LEFT_NODE_KEY THEN:
        RETURN AVL_RIGHT_ROTATE(node)
    
    // Left-Right case
    ELSE IF balance > 1 AND key > LEFT_NODE_KEY THEN:
        node.left = AVL_LEFT_ROTATE(node.left)
        RETURN AVL_RIGHT_ROTATE(node)

    // Right-Right case
    ELSE IF balance < -1 AND key > RIGHT_NODE_KEY THEN:
        RETURN AVL_LEFT_ROTATE(node)
    
    // Right-Left case
    ELSE IF balance < -1 AND key < RIGHT_NODE_KEY THEN:
        // Update node right
        node.right = AVL_RIGHT_ROTATE(node.right)
        RETURN AVL_LEFT_ROTATE(node)
    
    // No rotation, so root is the same
    RETURN node
```

### Right rotate

H διαδικασία είναι η εξής, χρειαζόμαστε 3 μεταβλητές για να αλλάζουμε τις διεθύνσεις. Σκεφτείτε ότι είναι μια διαδικασία swap όπου για να αλλάξουμε το υγρό μεταξύ δύο δοχείων, χρειάζεται να έχουμε και ένα τρίτο. 💡
1. Θέτουμε σε μια μεταβλητή x ως το αριστερό παιδί του y που χρειάζεται να γίνει rotate
2. Θέτουμε σε μια άλλη μεταβλητή, έστω T2 να είναι το δεξί παιδί του x
3. Θέτουμε το y ως το δεξί παιδί του x
4. Θέτουμε το αριστερό παιδί του y ως Τ2
5. Ενημερώνουμε τα ύψη των x και y, ξεκινόντας απο το x και μετά το y, παίρνοντας το μέγιστο ύψος απο το δεξί/αριστερό δέντρο, και προσθέτοντας του +1.
6. Επιστρέφουμε το x ως την νέα ρίζα του υποδέντρου που έγινε rotate.

### Left rotate

Παρόμοια διαδικασία με το right rotate.

## 1. Κώδικας του εργαστηρίου

Στο κώδικα του εργαστηρίου θα βρείτε τα παρακάτω αρχεία:
- [x]  `avl.c`: Περιέχει υλοποιημένες συναρτήσεις, καθώς και συναρτήσεις που καλείστε να υλοποιήσετε.
- [x]  `main.c`: Περιέχει μια main για τα πειράματα σας κατά τη διάρκεια υλοποίησης των ζητούμενων.
- [x]  `avl.h`:  Περιέχει όλες τις αναφορές των μεθόδων
- [x]  `avl_test.c`:  Περιέχει όλες τα unit-tests τα οποία θα πρέπει να περνάει ο κώδικας που θα υλοποιήσετε.
- [x]  `Makefile`

## 2. Συναρτήσεις που καλείστε να υλοποιήσετε

Στο αρχείο `avl.c`:

- [ ] **Υλοποίηση του right rotation για ένα AVL δένδρο** 
```c
AVLTree *avl_right_rotate(AVLTree *y){
    /* EXERCISE */
}
```

- [ ] **Υλοποίηση του left rotation για ένα AVL δένδρο** 
```c
AVLTree *avl_left_rotate(AVLTree *x){
    /* EXERCISE */
}
```

- [ ] **Υλοποιήστε την συνάρτηση εισαγωγής νέων κόμβων σε ένα AVL δένδρο**
```c 
// Search a node from the binary search tree
AVLTree *avl_insert(AVLTree *node, int key){
    /* EXERCISE */
}
```

## 3. Compile & Execution

Ο κώδικας κάνει compile με την εντολή
```make```
ενώ τα tests με την εντολή 
```make test```. 

Εκτέλεση των tests με 
```./test```
και της main με
```./main```

## 4. Παράδοση
Πρέπει να παραδώσετε το εργαστήριο κάνοντας `commit` και `push` στο remote repository στο github classroom. 

‼️ **Πρέπει ο κώδικας σας να περνάει τα unit tests και να μην έχει memory errors (valgrind).**  ‼️

Yπενθύμιση των βημάτων:

- [ ] `git status `: Ποια είναι η κατάσταση στο git με τις αλλαγές που έχετε κάνει
- [ ] `git add {files changed}`: Προσθέση των αρχείων που έχουν γίνει modified
- [ ] `git status`: Αν έγινε σωστά η προηγούμενη εντολή πρέπει να δείτε το όνομα του αρχείο πράσινο
- [ ] `git commit -m "finished lab-7 exercise"`: Commit στο τοπικό repo
- [ ] `git status`: Check ότι έγινε σωστά το commit
- [ ] `git push`: Ανέβασμα των τοπικών commits στο repote repo
- [ ] `git log`: Θα πρέπει να εμφανιστεί το commit σας στην λίστα με τα log!
