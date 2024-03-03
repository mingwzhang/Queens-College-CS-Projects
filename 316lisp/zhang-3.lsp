;;; Solution to Problem 1
(defun MIN-2 (A B)
    (cond ((and (numberp A) (numberp B)) (if (<= A B) A B))
          (t 'ERROR)))
    
;;; Solution to Problem 2
(defun SAFE-AVG (X Y)
    (if (and (numberp X) (numberp Y)) (/ (+ X Y) 2) NIL))

;;; Solution to Problem 3 
(defun ODD-GT-MILLION (I)
    (and (integerp I) (oddp I) (< 1000000 I)))

;;; Solution to Problem 4
(defun MULTIPLE-MEMBER (X Y)
    (if (and (or (symbolp X) (numberp X)) (listp Y)) 
        (member X (cdr (member X Y)))))

;;; Solution to Problem 5
(defun MONTH->INTEGER (X)
    (cond ((eq X 'January) 1)
          ((eq X 'February) 2)
          ((eq X 'March) 3)
          ((eq X 'April) 4)
          ((eq X 'May) 5)
          ((eq X 'June) 6)
          ((eq X 'July) 7)
          ((eq X 'August) 8)
          ((eq X 'September) 9)
          ((eq X 'October) 10)
          ((eq X 'November) 11)
          ((eq X 'December) 12)
          (t 'ERROR)))
          
;;; Solution to Problem 6
(defun SCORE->GRADE (s)
    (cond ((not (numberp s)) NIL)
          ((>= s 90) 'A)
          ((and (<= 87 s) (< s 90)) 'A-) 
          ((and (<= 83 s) (< s 87)) 'B+) 
          ((and (<= 80 s) (< s 83)) 'B)
          ((and (<= 77 s) (< s 80)) 'B-) 
          ((and (<= 73 s) (< s 77)) 'C+) 
          ((and (<= 70 s) (< s 73)) 'C) 
          ((and (<= 60 s) (< s 70)) 'D) 
          ((< s 60) 'F)))

;;; Solution to Problem 7
(defun GT (X Y)
    (and (numberp X) (numberp Y) (< Y X)))

;;; Solution to Problem 8
(defun SAME-PARITY (X Y)
    (and (and (integerp X) (integerp Y) 
    (or (and (evenp X) (evenp Y)) (and (oddp X) (oddp Y))))))

;;; Solution to Problem 9
(defun SAFE-DIV (X Y)



)