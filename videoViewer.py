import cv2
import pytesseract
import time
import numpy as np
import msvcrt
import os

def adjust_gamma(image, gamma=1.3):

   invGamma = 1.8 / gamma
   table = np.array([((i / 255.0) ** invGamma) * 255
      for i in np.arange(0, 256)]).astype("uint8")

   return cv2.LUT(image, table)


os.environ['TESSDATA_PREFIX'] = r'C:\Program Files\Tesseract-OCR\tessdata'

pytesseract.pytesseract.tesseract_cmd = r'C:/Program Files/Tesseract-OCR/tesseract.exe'

video_path = ".\\test2.mp4" 
cap = cv2.VideoCapture(video_path)

interval = 10  # in seconds
frame_rate = cap.get(cv2.CAP_PROP_FPS)
interval_frames = int(interval * frame_rate)

#Offset for starting frame
#frame_count = 35 * frame_rate
frame_count = 10

while cap.isOpened():
    ret, frame = cap.read()
    if not ret:
        break

    # Check if it's time to detect text
    if frame_count % interval_frames == 0:
        #frame = frame[300:400, 350:700]
        frame = frame[400:520, 830:1080]

        #cv2.convertScaleAbs(frame, alpha=1, beta=30)
        frame = adjust_gamma(frame)
        frame = cv2.addWeighted( frame, 1.1, frame, 1, 10)
        frame = cv2.bilateralFilter(cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY),1, 17, 17)
        cv2.imshow('window', frame)


        # char = msvcrt.getch().decode("utf-8")#read pressed key, decode
        # print(char)
        # if char == chr(13): #char(27) is the escape key
        #     break


        # # Perform text detection using pytesseract
        text = pytesseract.image_to_string(frame)



        if cv2.waitKey(1) & 0xFF == ord('q'):
            break




        # Invoking the command processor and calling the pause command
        # os.system('pause')

        time.sleep(.002)

        # # Do something with the detected text (e.g., print it)
        print("Detected text:", text)

    frame_count += 1