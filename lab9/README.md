# Lab 9 - Skip Lists

Σε αυτό το εργαστήριο θα εξετάσουμε την δομή των Skip Lists. Μια πιθανοτική δομή η οποία μας προσφέρει με πολύ καλές πιθανότητες average case πολυπλοκότητα O(logn).

Η δομή του Skip List, αποτελείται από το struct:
```c
typedef struct skip_list{
    SLNode *head;
    float p;
    int max_level;
}SkipList;
```
Στην μεταβλητή head αποθηκεύουμε τον πρώτο κόμβο της λίστας (οποίος πάντα αρχικοποιείται ως -inf).
Στην μεταβλητή max_level, έχουμε το μέγιστο ύψος που μπορεί να έχει ένας κόμβος της λίστας.
Στην μεταβλητή p, την πιθανότητα για την "ρίψη του κέρματος"

Ένας κόμβος λίστας, αποτελείται από το struct:
```c
typedef struct skip_list_node{
    int key;
    int level;
    struct skip_list_node **forward;
}SLNode;
```
Όπου key είναι η τιμή στον κόμβο, level η τιμή που αναπαριστά το ύψος του κόμβο και forward ένας πίνακας από δείκτες σε κόμβους, όπου κάθε θέση του πίνακα δείχνει σε ένα κόμβο του ίδιου επιπέδου. 


## 1. Κατεβάστε τον κώδικα του εργαστηρίου

Στο κώδικα του εργαστηρίου θα βρείτε τα παρακάτω αρχεία:

- [x] `skip_list.c`: το αρχείο με την υλοποίηση της skip list
- [x] `skip_list.h`: αναφορές στις συναρτήσεις της skip list
- [x] `skip_list_test.c` : unit tests πάνω στις συναρτήσεις της skip list
- [x] `main.c`: main() συνάρτηση για πειραματισμό
- [x] `Makefile`

## 2. Συναρτήσεις που καλείστε να υλοποιήσετε

Στο αρχείο `skip_list.c` είναι ήδη υλοποιημένες αρκετές συναρτήσεις μαζί με τον σκελετό της Skip List. Καλείστε να συμπληρώσετε όλς τις μεθόδους που στο περιεχόμενο τους γράφουν `EXERCISE`. Δηλαδή:

- [ ]  Συνάρτηση που εισάγει μια νέα τιμή στην skip list
```c
SkipList *skip_list_insert(SkipList *list,int key);
```
- [ ]  Συνάρτηση για την αναζήτηση μιας τιμής στην skip list
```c
int skip_list_search(SkipList *list,int key);
```
- [ ]  Συνάρτηση που αποδεσμέυει τη μνήμη μιας skip list
```c
void skip_list_destroy(SkipList *list);
```

## 3. Compile & Execution

Ο κώδικας κάνει compile με την εντολή 

```c
make
``` 

ενώ τα tests με την εντολή 

```c
make test
```

Εκτέλεση των tests με 

```c
./test
```

## 4. Παράδοση

Πρέπει να παραδώσετε το εργαστήριο κάνοντας `commit` και `push` στο github repository lab-9-sdiXXXXXXX.

- [ ] `git status `: Ποια είναι η κατάσταση στο git με τις αλλαγές που έχετε κάνει
- [ ] `git add {files changed}`: Προσθέση των αρχείων που έχουν γίνει modified
- [ ] `git status`: Αν έγινε σωστά η προηγούμενη εντολή πρέπει να δείτε το όνομα του αρχείο πράσινο
- [ ] `git commit -m "finished lab-9 exercise"`: Commit στο τοπικό repo
- [ ] `git status`: Check ότι έγινε σωστά το commit
- [ ] `git push`: Ανέβασμα των τοπικών commits στο repote repo
- [ ] `git log`: Θα πρέπει να εμφανιστεί το commit σας στην λίστα με τα log!
