import cv2 as cv
import mediapipe as mp
import math

mp_draw = mp.solutions.drawing_utils

video = cv.VideoCapture(0)

with mp.solutions.hands.Hands(max_num_hands=1, min_detection_confidence=0.1, min_tracking_confidence=0.1) as hands:

    while True:
        ret, image = video.read()
        image = cv.cvtColor(image, cv.COLOR_BGR2RGB)
        image.flags.writeable = False
        tracking = hands.process(image)   
        image.flags.writeable = True
        image = cv.cvtColor(image, cv.COLOR_RGB2BGR)
        lmList = []
        distance=0
        if tracking.multi_hand_landmarks:
            for hand_landmarks in tracking.multi_hand_landmarks:
                myHands = tracking.multi_hand_landmarks[0]
                thumb_tip = hand_landmarks.landmark[4]
                index_tip = hand_landmarks.landmark[8]
                h, w, c = image.shape
                c1x, c1y = int(thumb_tip.x * w), int(thumb_tip.y * h)
                c2x, c2y = int(index_tip.x * w), int(index_tip.y * h)

                cv.circle(image, (c1x, c1y), 10, (0, 255, 0), -1)
                cv.circle(image, (c2x, c2y), 10, (0, 255, 0), -1)
                distance =math.sqrt((thumb_tip.x-index_tip.x)**2+(thumb_tip.y-index_tip.y)**2)
                print(distance)
                cv.line(image,(c1x,c1y),(c2x,c2y),(0,255,0),3)

      
                    
        
        cv.imshow("Frame", image)
        k = cv.waitKey(1)
        if k == ord('q'):
            break

video.release()
cv.destroyAllWindows()
