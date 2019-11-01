#!/bin/python2
# -*- coding: utf-8 -*-

from sense_hat import SenseHat
import time
import datetime

#add push over library
import httplib, urllib

from firebase import firebase

sense = SenseHat()
sense.clear()

R = [255, 0, 0]  # red
O = [255, 165, 0]  # orange
Y = [255, 255, 0] # yellow
G = [0, 255, 0] # green
B = [0, 55, 155] # blue
I = [25, 0, 255] # indigo
V = [255, 0, 255] # violet
X = [0, 0, 0]  # off

rainbow = [
R, R, R, R, R, R, R, R,
R, O, O, O, O, O, O, O,
R, O, Y, Y, Y, Y, Y, Y,
R, O, Y, G, G, G, G, G,
R, O, Y, G, B, B, B, B,
R, O, Y, G, B, I, I, I,
R, O, Y, G, B, I, V, V,
R, O, Y, G, B, I, V, X
]

# define the shape of sunshine
sunshine = [
Y, X, X, X, X, X, X, Y,
X, Y, X, X, X, X, Y, X,
X, X, X, Y, Y, X, X, X,
X, X, Y, Y, Y, Y, X, X,
X, X, Y, Y, Y, Y, X, X,
X, X, X, Y, Y, X, X, X,
X, Y, X, X, X, X, Y, X,
Y, X, X, X, X, X, X, Y
]

ap = SenseHat()
temp = ap.get_temperature()
humidity = ap.get_humidity()
pressure = ap.get_pressure()

now = datetime.datetime.today().strftime("%d%m%Y %H:%M:%S")
if humidity > 80 and temp > 20:
    weather = 'Rainbow'
elif humidity > 80 and temp < 0 :
    weather = 'Snow'
elif humidity <= 80 and temp > 20 :
    weather = 'Sunny'
data= {
       'Temp' : temp,
       'Humidity' : humidity,
       'Pressure' : pressure,
       'Weather' : weather,
       'TimeStamp' : now       
       }

firebase = firebase.FirebaseApplication('https://project-2992179253810702894.firebase.com/')
firebase.post('https://project-2992179253810702894.firebaseio.com/',data)
i=0
climate = 'Rainbow'
print('Weather Report for Rainbow')
getweather = firebase.get('https://project-2992179253810702894.firebaseio.com/', None)

try: 
   for i in getweather:
       if(climate in getweather[i]['Weather']):
           result1 = getweather[i]['Temp']
           result2 = getweather[i]['Humidity']
           result3 = getweather[i]['TimeStamp']
           print('Timestamp:%s' %result3)
           print('Temparature:%s°C' %result1)
           print('Humidity:%s RH' %result2)
except KeyError: 
    print(' ')           

print("Current weather is ")       
print("Temp: %s C" % temp)               # Show temp on console
print("Humidity: %s H" % humidity)        # Show humidity on console
print("Pressure: %s Millibars" % pressure)    # Show pressure on console
#ap.set_rotation(180)
#ap.show_message("Weather Report: Sunny -> Display Yellow, Snowy -> Display White, Rainbow -> Display R$
while True:
  t = time.localtime()
  h = t.tm_hour

  if sense.humidity > 80 and sense.temp > 20:
  #Test if rainbow comes 
  #if 1:  
  # Send push notification 
    conn = httplib.HTTPSConnection("api.pushover.net:443")
    conn.request("POST", "/1/messages.json",
    urllib.urlencode({
    "token": "axpw6yrhai5pcnoyhasfuzvjdiox8e",
    "user": "uyzdaj9u6ch82ydc3rvjjcegadsca3",
    "message": "Wow, there is rainbow today, have fun",
     }), { "Content-type": "application/x-www-form-urlencoded" })
    conn.getresponse()     

    sense.set_pixels(rainbow)
    time.sleep(5)
    ap.set_rotation(180)        # Set LED matrix to scroll from right to left
    ap.show_message("Temperature: %.1f C" % temp, scroll_speed=0.10, text_colour=[0, 255, 0])
    time.sleep(2)           # Wait 1 second
    ap.show_message("Humidity: %.1f H" % humidity, scroll_speed=0.10, text_colour=[255, 0, 0])
    time.sleep(2)      # Wait 1 second
    ap.show_message("Pressure: %.1f Millibars" % pressure, scroll_speed=0.10, text_colour=[0, 0, 255])
    ap.clear()      # Clear LED matrix

  elif sense.humidity > 80 and sense.temp < 0 :
    # Send push notification 
    conn = httplib.HTTPSConnection("api.pushover.net:443")
    conn.request("POST", "/1/messages.json",
    urllib.urlencode({
    "token": "axpw6yrhai5pcnoyhasfuzvjdiox8e",
    "user": "uyzdaj9u6ch82ydc3rvjjcegadsca3",
    "message": "It's snowing today",
     }), { "Content-type": "application/x-www-form-urlencoded" })
    conn.getresponse() 

    sense.clear([255, 255, 255]) # white snow
    time.sleep(5)
    ap.set_rotation(180)        # Set LED matrix to scroll from right to left
    ap.show_message("Temperature: %.1f C" % temp, scroll_speed=0.10, text_colour=[0, 255, 0])
    time.sleep(2)           # Wait 1 second
    ap.show_message("Humidity: %.1f H" % humidity, scroll_speed=0.10, text_colour=[255, 0, 0])
    time.sleep(2)      # Wait 1 second
    ap.show_message("Pressure: %.1f Millibars" % pressure, scroll_speed=0.10, text_colour=[0, 0, 255])
    ap.clear()      # Clear LED matrix

  elif sense.humidity <= 80 and sense.temp > 20 :
    # Send push notification    
    conn = httplib.HTTPSConnection("api.pushover.net:443")
    conn.request("POST", "/1/messages.json",
    urllib.urlencode({
    "token": "axpw6yrhai5pcnoyhasfuzvjdiox8e",
    #"user": "uyzdaj9u6ch82ydc3rvjjcegadsca3",
    "user": "uyzdaj9u6ch82ydc3rvjjcegadsca3",
    "message": "It's a sunny day today, maybe go out to enjoy the sunshine",
     }), { "Content-type": "application/x-www-form-urlencoded" })
    conn.getresponse()   
    
    sense.set_pixels(sunshine) # yellow sun
    time.sleep(15)
    ap.set_rotation(180)        # Set LED matrix to scroll from right to left
    ap.show_message("Temperature: %.1f C" % temp, scroll_speed=0.10, text_colour=[0, 255, 0])
    time.sleep(2)           # Wait 1 second
    ap.show_message("Humidity: %.1f H" % humidity, scroll_speed=0.10, text_colour=[255, 0, 0])
    time.sleep(2)      # Wait 1 second
    ap.show_message("Pressure: %.1f Millibars" % pressure, scroll_speed=0.10, text_colour=[0, 0, 255])
    ap.clear()    # Clear LED matrix

  else:
    ap.set_rotation(180)        # Set LED matrix to scroll from right to left
    time.sleep(5)
    ap.show_message("Temperature: %.1f C" % temp, scroll_speed=0.10, text_colour=[0, 255, 0])
    time.sleep(2)           # Wait 1 second
    ap.show_message("Humidity: %.1f H" % humidity, scroll_speed=0.10, text_colour=[255, 0, 0])
    time.sleep(2)      # Wait 1 second
    ap.show_message("Pressure: %.1f Millibars" % pressure, scroll_speed=0.10, text_colour=[0, 0, 255])
    ap.clear()      # Clear LED matrix
