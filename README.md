# gorrion
Alimenta al pájaro hambriento

Primeras pruebas con cámara Genius EYE 312

ARMbian:

paquetes:
v4l2-ctl, fswebcam y motion


chequear cámara:
sudo v4l2-ctl --all

streaming video:


sudo LD_PRELOAD=/usr/lib/arm-linux-gnueabihf/libv4l/v4l1compat.so motion


captura imagen:


LD_PRELOAD=/usr/lib/arm-linux-gnueabihf/libv4l/v4l1convert.so fswebcam  -S 5 -s brightness=40% -s Contrast=80%  -s Gamma=20%  -r 640x480 --jpeg 90 -s Sharpness=70% -s Saturation=15% test.jpg


compilar:

g++ main.cc -o cv -I/usr/local/include/opencv4


Debian:

paquetes: 

v4l-conf, v4l-utils, libopencv-dev, libopencv-videoio-dev

g++ captureToFile.cpp -o ../bin/captureToFile -I/usr/local/include/opencv4 -L/usr/local/lib -lopencv_core -lopencv_videoio

LD_PRELOAD=/usr/lib/x86_64-linux-gnu/libv4l/v4l2convert.so ./captureToFile 


