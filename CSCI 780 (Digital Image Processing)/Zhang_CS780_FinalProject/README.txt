README - CS780 Final Project: Handwritten Digit Recognition on MNIST
-------------------------------------------------------------------

Member: Mingwei Zhang

1. Platform and MATLAB Toolboxes:
   - MATLAB
   - Computer Vision Toolbox
   - Statistics and Machine Learning Toolbox

2. Required File:
   - mnist.mat

3. MATLAB Scripts:
   - analyze_distribution.m
     Counts the number of samples for each digit class in the selected training and test sets
     and plots the class distributions.

   - compare_results.m
     Generates the overall accuracy and per-class accuracy comparison figures used
     in the report. The accuracy values in this script are manually entered from
     the outputs of train_svm_rawpixel.m and train_svm_hog.m.

   - load_mnist.m
     Loads the MNIST dataset, checks the dataset structure, prints image and label sizes,
     and displays one sample digit.

   - train_svm_hog.m
     Runs the HOG + SVM method. HOG features are extracted using a 4 x 4 cell size.
     The script trains a multiclass SVM, computes overall accuracy, per-class accuracy,
     and displays the confusion matrix.

   - train_svm_rawpixel.m
     Runs the Raw Pixel + SVM baseline. Each 28 x 28 image is reshaped into a
     784-dimensional feature vector. The script trains a multiclass SVM, computes
     overall accuracy, per-class accuracy, and displays the confusion matrix.

   - visualize_samples.m
     Displays random MNIST training samples with their labels.

4. Run Order:
   - load_mnist.m
   - visualize_samples.m
   - analyze_distribution.m
   - train_svm_rawpixel.m
   - train_svm_hog.m
   - compare_results.m

5. Final Experiment Setup:
   - Training images: 60,000
   - Test images: 10,000
   - Classifier: MATLAB fitcecoc multiclass SVM
   - Feature methods: Raw pixels and HOG