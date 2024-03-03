;;; Solution to Problem 1
(defun MIN-2 (A B)
    (cond ((and (numberp A) (numberp B)) (if (<= A B) A B))
          (t 'ERROR)))
    
;;; Solution to Problem 2
(defun SAFE-AVG (X Y)
    (if (and (numberp X) (numberp Y)) (/ (+ X Y) 2) NIL))

;;; Solution to Problem 3
(defun ODD-GT-MILLION (I)
    (if (and (integerp I) (oddp I) (< 1000000 I)) T NIL))

;;; Solution to Problem 4
(defun MULTIPLE-MEMBER (X Y)
    (if (and (or (symbolp X) (numberp X)) (listp Y) ()) 
    
    (cons X Y) NIL))