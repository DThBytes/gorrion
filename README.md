# gorrion
Alimenta al pájaro hambriento

Primeras pruebas con cámara Genius EYE 312

paquetes:
v4l2-ctl, fswebcam y motion


chequear cámara:
sudo v4l2-ctl --all

streaming video:


sudo LD_PRELOAD=/usr/lib/arm-linux-gnueabihf/libv4l/v4l1compat.so motion


captura imagen:


LD_PRELOAD=/usr/lib/arm-linux-gnueabihf/libv4l/v4l1convert.so fswebcam  -S 5 -s brightness=40% -s Contrast=80%  -s Gamma=20%  -r 640x480 --jpeg 90 -s Sharpness=70% -s Saturation=15% test.jpg
