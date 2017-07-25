import pygame
import pygame.camera
from pygame.locals import *

pygame.init()
pygame.camera.init()


camera = pygame.camera.Camera("/dev/video0",(300,150))
camera.start()
image = camera.get_image()
pygame.image.save(image,"image.jpg")
camera.stop()
print('Camera Stop')
