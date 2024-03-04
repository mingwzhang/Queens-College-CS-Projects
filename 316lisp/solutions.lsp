; (a) 
(defun square (X) (* x x))

; (b) 
(defun sqr-perimeter-area (s)
        (list (* 4 s) (* s s)))

; (c) 
(defun rotate-left (l)
        (append (cdr l) (list (car l))))

; (d) 
(defun switch (l)
        (list (cadr l) (car l)))

; (e) 
(defun euclidean-distance (x y)
        (sqrt (+ (square (- (car x) (car y)))
                 (square (- (cadr x) (cadr y))))))
                 
; (f) 
(defun quadratic (a b c)
        (list (/ (+ (- b)
                    (sqrt (- (* b b) (* 4 a c))))
                 (* 2 a))
              (/ (- (- b)
                    (sqrt (- (* b b) (* 4 a c))))
                 (* 2 a)))) 