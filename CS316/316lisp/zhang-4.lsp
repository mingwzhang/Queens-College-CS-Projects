;;; Solution to Problem 1
(defun SUM (L)
    (if (null L) 0
        (+ (car L) (SUM (cdr L)))))

;;; Solution to Problem 2
(defun NEG-NUMS (L)
    (cond ((null L) NIL)
          ((minusp (car L)) (cons (car L) (NEG-NUMS(cdr L))))
          (t (NEG-NUMS(cdr L)))))
    

;;; Solution to Problem 3
(defun INC-LIST-2 (L n)
    (if (null L) NIL
        (cons(+ (car L) n) (INC-LIST-2 (cdr L) n))))

;;; Solution to Problem 4
(defun INSERT (n L)
  (cond ((null L) (cons n L))
        ((> n (car L)) (cons (car L) (INSERT n (cdr L))))
        (t (cons n L))))

;;; Solution to Problem 5
(defun ISORT (L)
    (if (null L) NIL
        (INSERT (car L) (ISORT (cdr L)))))

;;; Solution to Problem 6
(defun SPLIT-LIST (L)
    (if (null L) (list NIL NIL)
        (let ((X (SPLIT-LIST (cdr L))))
        (list (cons (car L) (cadr X)) (car X)))))
    
;;; Solution to Problem 7
(defun PARTITION (L p)
    (cond ((null L) (NIL NIL))
        ((< p (cdr L)))
    )
)

;;; Solution to Problem 8
;;; Solution to Problem 9
;;; Solution to Problem 10
;;; Solution to Problem 11
;;; Solution to Problem 12
;;; Solution to Problem 13

