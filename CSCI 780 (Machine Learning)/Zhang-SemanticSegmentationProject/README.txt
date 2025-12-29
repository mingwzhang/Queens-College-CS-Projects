README - CS780 Final Project: Semantic Segmentation on PASCAL VOC 2012
--------------------------------------------------------------------

Team Members: Mingwei Zhang, Junhong Tong

1. What did you finish?
   - Implemented a baseline vanilla U-Net model for multi-class semantic segmentation.
   - Implemented an improved ResNet-50 U-Net model using a pretrained ResNet-50 encoder.
   - Prepared and processed the PASCAL VOC 2012 segmentation dataset using a public mirror.
   - Filtered the dataset to 8 classes: background, person, car, dog, cat, motorbike, train, and bus.
   - Applied data augmentation including random flip, random resized crop, and color jitter.
   - Used class-weighted cross entropy loss to address class imbalance.
   - Trained both models using AdamW optimizer with mixed precision training.
   - Evaluated models using pixel accuracy, per-class IoU, and mean IoU (mIoU).
   - Compared training loss and validation mIoU curves between baseline and improved models.
   - Performed qualitative visualization comparing ground truth, U-Net, and ResNet-50 U-Net outputs.

2. Python Version:
   - 3.10

3. Platform:
   - Google Colab
   - NVIDIA Tesla T4 GPU

4. Resources:
   - PASCAL VOC 2012 dataset
     https://www.robots.ox.ac.uk/~vgg/projects/pascal/VOC/
   - VOC dataset mirror
     https://data.brainchip.com/dataset-mirror/voc/VOCtrainval_11-May-2012.tar
   - PyTorch documentation
     https://pytorch.org/docs/stable/index.html
   - Torchvision models
     https://pytorch.org/vision/stable/models.html
   - U-Net paper
     Ronneberger et al., 2015
   - ResNet paper
     He et al., 2016
   - Lecture slides on CNNs, semantic segmentation, and transfer learning
