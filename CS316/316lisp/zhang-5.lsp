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
;;; Solution to Problem 5
;;; Solution to Problem 6
;;; Solution to Problem 7
;;; Solution to Problem 8
;;; Solution to Problem 9
;;; Solution to Problem 10
;;; Solution to Problem 11
;;; Solution to Problem 12
;;; Solution to Problem 13
;;; Solution to Problem 14
;;; Solution to Problem 15
;;; Solution to Problem 16
