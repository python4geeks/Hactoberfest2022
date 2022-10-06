# -*- coding: utf-8 -*-
"""
Created on Thu Sep 29 09:58:32 2022

@author: HP
"""
'''
#flipping the image

from PIL import Image


#opening the images
img=Image.open("newspaper.jpg")

#transposong

transposed_img=img.transpose(Image.FLIP_LEFT_RIGHT)

#save it to a file in a human understanable format

transposed_img.save("corrected.jpeg")

print("Done fillping")
'''

#image enhancement CLAHE

import cv2

#read the image

img=cv2.imread('crime.jfif')

#preparation for CLAHE

clahe=cv2.createCLAHE()

#convert to gray scale image

gray_img=cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)

#apply enhancement

enh_img=clahe.apply(gray_img)

#save it to a file

cv2.imwrite('enhanced.jpeg',enh_img)

print("Done enhancing")
