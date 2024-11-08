;;; Zhang Mingwei

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
    (if (null L) (list NIL NIL)   
        (let ((X (PARTITION (cdr L) p)))
            (if (< (car L) p)
                (list (cons (car L) (car X)) (cadr X))
                (list (car X) (cons (car L) (cadr X)))))))

;;; Solution to Problem 8
(defun POS (e L)
    (cond ((endp L) 0)
          ((equal e (car L)) 1)
          (t (let ((X (pos e (cdr L))))
                  (if (zerop X) 0 (+ X 1))))))

;;; Solution to Problem 9
(defun SPLIT-NUMS (N)
    (if (zerop N) (list '(0) NIL)
        (let ((X (SPLIT-NUMS (- N 1))))
             (if (evenp N)
                (list (cons N (car X)) (cadr X))
                (list (car X) (cons N (cadr X)))))))

;;; Solution to Problem 10
(defun SET-UNION (s1 s2)
    (cond ((null s1) s2)
          ((member (car s1) s2) (SET-UNION (cdr s1) s2)) 
          (t (SET-UNION (cdr s1) (cons (car s1) s2)))))

;;; Solution to Problem 11
(defun SET-REMOVE (x s)
    (cond ((null s) NIL)
          ((equal x (car s)) (cdr s))
          (t (cons (car s) (SET-REMOVE x (cdr s))))))

;;; Solution to Problem 12
(defun SET-EXCL-UNION (s1 s2)
    (cond ((null s1) s2)
          ((member (car s1) s2) (SET-EXCL-UNION (cdr s1) (SET-REMOVE (car s1) s2)))
          (t (cons (car s1) (SET-EXCL-UNION (cdr s1) s2)))))

;;; Solution to Problem 13  #corrected
(defun SINGLETONS (e)
    (cond ((null e) NIL)
          ((member (car e) (cdr e)) (SET-REMOVE (car e) (SINGLETONS (cdr e))))
          (t (cons (car e) (SINGLETONS (cdr e))))))
