;;; Zhang Mingwei

;;; Solution to Problem 1
 (defun INDEX (N L)
    (cond ((null L) 'ERROR)
          ((equal N 1) (car L))
          (t (INDEX (- N 1) (cdr L)))))

;;; Solution to Problem 2
 (defun MIN-FIRST (L)
    (if (endp (cdr L)) L
        (let ((X (MIN-FIRST (cdr L))))
             (if (<= (car L) (car X)) L
                 (cons (car X) (cons (car L) (cdr X)))))))

;;; Solution to Problem 3
(defun SSORT (L)
    (if (endp (cdr L)) L
        (let* ((X (MIN-FIRST L))
               (Y (SSORT (cdr X))))
              (cons (car X) Y))))

;;; Solution to Problem 4   
(defun PARTITION (L p)
    (if (null L) (list nil nil)   
        (let ((X (PARTITION (cdr L) p)))
             (if (< (car L) p)
                 (list (cons (car L) (car X)) (cadr X))
                 (list (car X) (cons (car L) (cadr X)))))))
(defun QSORT (L)
    (if (endp L) nil
        (let ((PL (PARTITION (cdr L) (car L))))
             (append (QSORT(car PL)) (cons (car L) (QSORT (cadr PL)))))))                

;;; Solution to Problem 5
(defun MERGE-LISTS (L1 L2)
    (if (or (endp L1) (endp L2)) (or L1 L2)
        (let ((X (MERGE-LISTS (cdr L1) L2)) (Y (MERGE-LISTS L1 (cdr L2))))
             (if (< (car L1) (car L2)) 
                 (cons (car L1) X)
                 (cons (car L2) Y)))))

;;; Solution to Problem 6
(defun SPLIT-LIST (L)
    (if (null L) (list nil nil)
        (let ((X (SPLIT-LIST (cdr L))))
             (list (cons (car L) (cadr X)) (car X)))))

(defun MSORT (L)
    (if (null L) nil
        (let ((X (SPLIT-LIST L)))
             (if (null (cadr X))
                 (MERGE-LISTS (car X) (cadr X))
                 (MERGE-LISTS (MSORT (car X)) (MSORT(cadr X)))))))

;;; Solution to Problem 7  
(defun REMOVE-ADJ-DUPL (L)
    (if (null L) nil
        (if (equal (car L) (cadr L))
            (REMOVE-ADJ-DUPL (cdr L))
            (cons (car L) (REMOVE-ADJ-DUPL (cdr L))))))

;;; Solution to Problem 8
(defun UNREPEATED-ELTS (L)
    (cond ((endp L) nil) 
          ((or (endp (cdr L)) (not (equal (car L) (cadr L)))) (cons (car L) (UNREPEATED-ELTS (cdr L))))
          ((or (endp (cddr L)) (not (equal (car L) (caddr L)))) (UNREPEATED-ELTS (cddr L))) 
          (t (UNREPEATED-ELTS (cdr L)))))

;;; Solution to Problem 9
(defun REPEATED-ELTS (L)
    (cond ((endp L) nil) 
          ((or (endp (cdr L)) (not (equal (car L) (cadr L)))) (REPEATED-ELTS (cdr L)))
          ((or (endp (cddr L)) (not (equal (car L) (caddr L)))) (cons (car L) (REPEATED-ELTS (cddr L)))) 
          (t (REPEATED-ELTS (cdr L)))))
 
;;; Solution to Problem 10
(defun LEFT-ELEMENT (L)
    (if (equal (car L) (cadr L)) 
        (+ 1 (LEFT-ELEMENT (cdr L))) 1))

(defun RIGHT-ELEMENT (L)
    (if (endp L) nil
        (if (equal (car L) (cadr L)) 
            (RIGHT-ELEMENT (cdr L)) 
            (cdr L))))

(defun COUNT-REPETITIONS (L)
    (if (endp L) nil
        (let ((X (LEFT-ELEMENT L)) (Y (RIGHT-ELEMENT L)))
             (append (list (cons X (list (car L)))) (COUNT-REPETITIONS Y)))))

;;; Solution to Problem 11
(defun SUBSET (X Y)
    (if (endp Y) nil
        (if (funcall X (car Y))
            (cons (car Y) (SUBSET X (cdr Y)))
            (SUBSET X (cdr Y)))))

;;; Solution to Problem 12
(defun OUR-SOME (X Y)
    (if (endp Y) nil
        (if (funcall X (car Y)) Y
            (OUR-SOME X (cdr Y)))))

(defun OUR-EVERY (X Y)
    (if (endp Y) t
        (if (funcall X (car Y)) 
            (OUR-EVERY X (cdr Y)) nil)))

;;; Solution to Problem 13
(defun PARTITION1 (P L E)
    (if (null L) (list nil nil)   
        (let ((X (PARTITION1 P (cdr L) E)))
             (if (funcall P (car L) E)
                 (list (cons (car L) (car X)) (cadr X))
                 (list (car X) (cons (car L) (cadr X)))))))

(defun QSORT1 (P L)
    (if (endp L) nil
        (let ((PL (PARTITION1 P (cdr L) (car L))))
             (append (QSORT1 P (car PL)) (cons (car L) (QSORT1 P (cadr PL)))))))    

;;; Solution to Problem 14
(defun SUBLIST (P L N)
    (if (endp L) nil
        (if (equal N 1) 
            (cons (funcall P (car L)) (cdr L))
            (cons (car L) (SUBLIST P (cdr L) (- N 1))))))
            
(defun SUBLIST-LENGTH (P L N)
    (if (equal N 0) nil
        (cons (SUBLIST P L N) (SUBLIST-LENGTH P L (- N 1)))))

(defun FOO (P L)
    (if (endp L) nil
        (reverse (SUBLIST-LENGTH P L (length L)))))

;;; Solution to Problem 15(a)
(defun TR-ADD (L N)
    (cond ((null L) N)
          (t (TR-ADD (cdr L) (+ N (car L))))))

(defun TR-MUL (L N)
    (cond ((null L) N)
          (t (TR-MUL (cdr L) (* N (car L))))))

(defun TR-FAC (N1 N2)
    (cond ((zerop N1) N2)
          (t (TR-FAC (- N1 1) (* N1 N2)))))

;;; Solution to Problem 15(b)
(defun SLOW-PRIMEP (n)
    (cond ((and (> n 1) (equal (mod (TR-FAC (- n 1) 1) n) (- n 1))) T) 
          (t nil)))
          
;;; Solution to Problem 16(a)
(defun TRANSPOSE1 (M)
    (if (endp (cdr M))
        (mapcar #'list (car M))
        (mapcar #'cons (car M) (TRANSPOSE1 (cdr M)))))

;;; Solution to Problem 16(b)
(defun TRANSPOSE2 (M)
    (if (endp (cdar M))
        (list (mapcar #'car M))
        (cons (mapcar #'car M) (transpose2 (mapcar #'cdr M)))))

;;; Solution to Problem 16(c)
(defun TRANSPOSE3 (M)
    (apply #'mapcar #'list M))