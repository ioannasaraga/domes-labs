# Lab 6 - Hashtables #️⃣

Σε αυτό το εργαστήριο θα εξετάσουμε μία δομή που θα είναι πάντα πιστή σας φίλη στην πορεία σας ως γητευτές των υπολογιστών 🧙‍♂️ ... το Hashtable!

## Τι είναι ένα hashtable με chaining 🔗

Είναι ένας πίνακας του οποίου κάθε θέση είναι ένα δείκτης σε μια λίστα. 

![s_fig31](https://user-images.githubusercontent.com/47646955/236693434-cac76060-a2fc-4aa7-ab38-35c437527bb7.gif)

Κάθε στοιχείο ενός Hashtable αποτελείται από ένα ζεύγος <κλειδιού, τιμής>. Η χρησιμότητα αυτής της δομής έγκειται στο ότι μας επιτρέπει να ανακτούμε πολύ γρήγορα την `τιμή` που συνδέεται με ένα `κλειδί`.

Για παράδειγμα, σε ένα πρόγραμμα που διαχειρίζεται στοιχεία φοιτητών θα μπορούσαμε να χρησιμοποιήσουμε ένα Hashtable με ζεύγος κλειδιού-τιμής <αριθμό μητρώου, struct φοιτητής> για να μπορούμε να ανακτούμε πολύ γρήγορα πληροφορίες για συγκεκριμένους φοιτητές.

#### Πως μετατρέπονται οι τιμές του κλειδιού σε θέσεις στον πίνακα;

Αυτό γίνεται με την χρήση μίας ή περισσότερων hash functions οι οποίες μετατρέπουν έξυπνα την τιμή του κλειδιού σε μία θέση στο Hashtable. Παράδειγμα μίας hash function είναι η ακόλουθη:
```
hashFunction(string):
	hash = 0
	for char < string_length:
		hash += string[char]   // add ascii-code value
	return hash % hashtable_size
```

## 1. Κώδικας του εργαστηρίου 📜

Στο κώδικα του εργαστηρίου θα βρείτε τα παρακάτω αρχεία:
- [x]  `hashtable.c`: Περιέχει υλοποιημένες συναρτήσεις, καθώς και συναρτήσεις που καλείστε να υλοποιήσετε.
- [x]  `main.c`: Περιέχει μια main για τα πειράματα σας κατά τη διάρκεια υλοποίησης των ζητούμενων.
- [x]  `hashtable.h`:  Περιέχει όλες τις αναφορές των μεθόδων
- [x]  `hashtable_test.c`:  Περιέχει όλες τα unit-tests τα οποία θα πρέπει να περνάει ο κώδικας που θα υλοποιήσετε.
- [x] `list/`:  Περιέχει την υλοποίηση για την λίστα που θα χρησιμοποιήσετε.
- [x] `customer`:  Περιέχει την υλοποίηση του Customer.
- [x]  `Makefile`

Η δομή του hashtable αποτελείται από το struct:
```c
struct hashtable {
    size_t size;
    List** table;
};
```

και θα χρησιμοποιήσετε και την δομή μιας λίστας και ενός Customer, με αντίστοιχα structs:

```c
struct list{
    Customer* customer;
    List *next;
};


struct customer {
    char* id;
    char* firstname;
    char* lastname;
    size_t age;
    int data;
};
```

## 2. Συναρτήσεις που καλείστε να υλοποιήσετε

💭 **Θυμηθείτε**: υπάρχουν πολλές υλοποιήμενες μέθοδοι και στην λίστα αλλά και στο hashtable τις οποίες μπορείτε να χρησιμοποιήσετε για να υλοποιήσετε τα ζητούμενα. 

Στο αρχείο `hashtable.c`:

- [ ] **Hash function: Δηλαδή μια συνάρτηση που δέχεται ένα string και το μετατρέπει σε μια θέση πίνακα του hashtable, όπως φαίνεται στον ψευδοκώδικα πάνω ⬆️.** 
```c
// Hash function
size_t hashtable_hash(Hashtable* h, char* id) {
    /* EXERCISE */
    return 0;
}
```

- [ ] **Υλοποίηση insert και resize. Προσοχή, για να περάσει το test θα πρέπει να έχετε υλοποιήσει και τις δύο.** 
```c
// Insert a customer into the hashtable (if it doesn't already exist)
Hashtable* hashtable_insert(Hashtable* h, Customer* c) {
    /* EXERCISE */
    return NULL;
}

// Resize the hashtable
Hashtable* hashtable_resize(Hashtable* h) {
    /* EXERCISE */
    return NULL;
}
```

- [ ] **Υλοποίηση της συνάρτησης αναζήτησης ενός Customer με το id του.**
```c 
// Get a customer from the hashtable
Customer* hashtable_get(Hashtable* h, char* id) {
    /* EXERCISE */
    return NULL;
}
```

- [ ] **Υλοποιήστε την συνάρτηση διαγραφής ενός Customer με το id του.**
```c 
// Remove a customer from the hashtable
STATUS hashtable_remove(Hashtable* h, char* id) {
    /* EXERCISE */
    return FAILURE;
}
```
‼️ **Προσοχή**: το STATUS είναι ένα enum. Εάν η remove κάνει επιτυχημένα διαγραφή customer τότε θα επιστρέφετε `return SUCCESS;`, διαφορετικά `return FAILURE;`

## 3. Compilation, execution and testing 👩‍🔬

#### Compilation
Ο κώδικας κάνει compile με την εντολή:

```make```

ενώ τα tests με την εντολή:

```make test```

#### Execution & Testing

Εκτέλεση των tests με :

```./test```

και της main με:

```./main```

## 4. Παράδοση 🪁
Πρέπει να παραδώσετε το εργαστήριο κάνοντας `commit` και `push` στο remote repository στο github classroom. 

‼️ **Πρέπει ο κώδικας σας να περνάει τα unit tests και να μην έχει memory errors (valgrind).**  ‼️

Yπενθύμιση των βημάτων:

- [ ] `git status `: Ποια είναι η κατάσταση στο git με τις αλλαγές που έχετε κάνει
- [ ] `git add {files changed}`: Προσθέση των αρχείων που έχουν γίνει modified
- [ ] `git status`: Αν έγινε σωστά η προηγούμενη εντολή πρέπει να δείτε το όνομα του αρχείο πράσινο
- [ ] `git commit -m "finished lab-6 exercise"`: Commit στο τοπικό repo
- [ ] `git status`: Check ότι έγινε σωστά το commit
- [ ] `git push`: Ανέβασμα των τοπικών commits στο repote repo
- [ ] `git log`: Θα πρέπει να εμφανιστεί το commit σας στην λίστα με τα log!
