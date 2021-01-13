# Image-Rotation-using-opencv
Image Rotation
In this project we will rotate an image by an angle given by user using openCV library in C++.
Assumptions:
•	Opencv must be installed in your machine.
•	We need to have C++ compiler.

Function Used:
•	imread() – To read or load the image that takes name of image as argument.
•	rotate() – Takes two argument “src” i.e. source of image and “angle” given by user to rotate the image.
•	wrapAffine() – Used in rotate() function. “wrapAffine” function is the inbuilt function of opencv library. It takes four argument.
1.	src – Source of the image file.
2.	dst – Destination image file.
3.	r – is the mat object i.e. output after rotating.
4.	boundW, boundH – are the width and height of output image after scaling it to fit in the output window.
•	imshow() – To display image.
•	waitkey() – To make output window wait till any input from keyboard. 
