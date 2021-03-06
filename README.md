# Summer Project 2017

<p>This is a project that aims to build a simulation game in the real world. I am planning to build a game that is similar to <b>Cities Skylines</b>. Right now I am thinking using an OV7670 camera with 2.4GHz interface to an Intel Edison. Then using a self driving car program to do machine learning. I hope it will work out.</p>

<h2>Part I</h2>
<h3>Abstraction</h3>
<p>For the first part, The idea is to have vehicles running under the governance of a unified controller (In this case, Intel Edison).<br> Vehicles would have camera modules and microcontrollers on board, to send data to the unified controller. The controller would be working on multiple image processing threads from the vehicles. Then, we would have the environment set up (street signs, pavement markings...), and those would be the main target for image processing. Finally, the controller would give back controll signals to vehicles to make them turn left or right, stop or proceed.</p>
<h3>§ Mechanism</h3>
<p>Vehicles communicate with the unified controller through BLE (Bluetooth Low Energy) and IEEE 802.11n 2.4GHz. Image signals will be transmitted via 2.4GHz because of its high speed. Vehicle movement commands will be sent via BLE. <b>Image processing</b> will be done by <b>OpenCV</b> if Intel Edison had enough memory.</p>
<h3>§ Potential technical hurdles</h3>
<h4>• HO Scaling</h4>
<p>Since I want to integrate my system perfectly with current HO scaled train modules, it would be <b>hard</b> to have my vehicles running on the same scaling. HO scale is 1:87.1, which means my finished vehicles would be around the same size as an old style <a href="https://s-media-cache-ak0.pinimg.com/originals/0f/e7/19/0fe71911d7171c289f0290b6d3489111.jpg">match box</a>. This is hard, and it will too bring many mechanical problems since I am not terribly familiar with mechanical design.</p>
<h4>• Power for Image Processing</h4>
<p>I am not talking about just image processing here, also some pattern matching and machine learning. It definitely will chew up a lot of memory for my Intel Edison, and I really don't think it would be a great idea to even have it connected to four cameras the same time. If any part of my plan with Edison did not pan out well, I would have to use my computer's graphic card, I guess (assuming all modern computers have 2.4GHz, aka, WiFi).</p>
<h3>§ Current Status<h3>
<h4>• stuff purchased</h4>
<ul>
  <li><a href="http://www.uctronics.com/media/catalog/product/cache/1/image/9df78eab33525d08d6e5fb8d27136e95/b/0/b0023_3.jpg">OV7670 Camera</a></li>
  <li><a href="https://cdn-learn.adafruit.com/assets/assets/000/028/633/medium800/adafruit_products_2829_iso_ORIG.jpg?1447887201">Adafruit Feather 32u4 Bluefruit LE</a></li>
  <li><a href="https://www.pi-supply.com/wp-content/uploads/2015/02/2111-00.jpg">Intel Edison with Mini Breakout</a></li>
  <li><a href="http://www.arducam.com/wp-content/uploads/2015/03/ArduCAM_mini-1.jpg">ArduCam Mini 2MP (OV2640)</a></li>
</ul>
<h4>• progress update log</h4>
<p><i>5/25/2017 - I had the ArduCam Mini 2MP OV2640 working. The source code is <a href="https://github.com/jiyuhan/summerProject/blob/master/arduino_arducam_mini_2mp/ov2640_2mp_serial_fifo.ino">here</a>. PS. you have to install the ArduCam library to have this working.</i></p>
<p><i>5/27/2017 - I am still trying to set up the environment since my programmer USBtiny is not working with ATMEL Studio 7. Also, I found out my Intel Edison had a power supply problem. I am going to ask Intel for a new one. After I return my USBtiny and purchase the ATMEL MKII, I am planning to write some code for ATmega88PA_OV7670_Serial in C. Not so much progress today, but got some things organized, looking good. Tomorrow, I am going to push the code I had for OV2640 on Arduino.</i></p>
<p><i>5/28/2017 - The code for OV2640 is up. Try <a href="https://github.com/jiyuhan/summerProject/blob/master/arduino_arducam_mini_2mp/ov2640_2mp_serial_fifo.ino">this link</a>. Not much done today, waiting on some parts.</i></p>
<p><i>6/29/2017 - A redesign is probably needed. I will use a PIC module and a 2.4 GHz transmitter to send signals to another device (a computer, but I will have a lot of trouble receiving the signal from my laptop). I sent back the defected Edison unit back to Intel, and received a new one.</i></p>
<h3>Disclaimer</h3>
<p>I do not own any of the images, links above. I searched and picked them because they were the most descriptive to the products I mentioned. And I checked very carefully that they were not from suspicious websites, but should you find your device at risk after visiting the sites, the author will not be accountable for the circumstances.</p>
