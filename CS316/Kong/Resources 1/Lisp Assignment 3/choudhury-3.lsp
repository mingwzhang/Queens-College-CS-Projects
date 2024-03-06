;Nahian Choudhury
;Partner 1: Joanne Chan
;Partner 2: Chris Agianian

;;;Solution to Problem 1
(defun MIN-2 (A B)
	(if (and (numberp A) (numberp B))
		(cond ((<= A B) A) 
			  ((> A B) B)) 
		'ERROR))
			
;;;Solution to Problem 2
(defun SAFE-AVG (A B)
	(and (numberp A) (numberp B) 
		(/ (+ A B) 2)))
  
;;;Solution to Problem 3
(defun ODD-GT-MILLION (A)
	(and (integerp A) (= 1 (mod A 2)) (> A 1000000) T))
  
;;;Solution to Problem 4
(defun MULTIPLE-MEMBER (A B)
    (and (or (numberp A) (symbolp A)) (listp B)
		(member A (cdr (member A B)))))
		   
;;;Solution to Problem 5 
(defun MONTH->INTEGER (X)
    (cond 
        ((eq X 'January) 1)
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
        (t 'ERROR )))

;;;Solution to Problem 6
(defun SCORE->GRADE (s)
	(if (numberp s) (cond ((>= s 90) 'A)
						  ((>= s 87) 'A-)
						  ((>= s 83) 'B+)
						  ((>= s 80) 'B)
						  ((>= s 77) 'B-)
						  ((>= s 73) 'C+)
						  ((>= s 70) 'C)
						  ((>= s 60) 'D)
						  ((< s 60) 'F))))

;;;Solution to Problem 7
(defun GT (A B)
  (and (numberp A) (numberp B) (> A B) T))

;;;Solution to Problem 8
(defun SAME-PARITY (X Y)
	(or (and (integerp X) (integerp Y) (evenp X) (evenp Y)) 
	    (and (integerp X) (integerp Y) (oddp X) (oddp Y)) ) T)

;;;Solution to Problem 9
(defun SAFE-DIV (A B)
	(and (numberp A) (numberp B) (not (= B 0)) (/ A B)))