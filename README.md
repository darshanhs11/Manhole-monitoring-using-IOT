# Manhole-monitoring-using-IOT
This system is an effective manhole monitoring system which ensures the safety of the common man related to accident s caused by manholes.If this method is implemented then it will surely help in sustainable and overall development of the city.Our system provides real time monitoring which is the key factor in monitoring the system and helps the authority to take necessary steps to resolve the issue at the earliest

## Abstract
— In Mysuru, out of 30 thousands manholes many
may not follow safety norms due to mismanagement and
other reasons . Most manholes are not in proper conditions
without any monitoring which lead to accidents or fatal
accidents.This is the reason we need an efficient
management system to be monitored remotely which can be
easily accessible.So we decided to develop a system where
the manhole can be monitored distantly.

## INTRODUCTION
Manhole,one of the important aspects of the city regarding the
status and for its overall development.It plays a major role in
the drainage system of the city.Improper manholes are being
threat to the commutators’ life.Manhole are full of
contaminants.Bacteria,protozoa,viruses and parasites worms
all are in the sewage and can cause diseases in humans ,so it's
important to be properly protected if you are in contact with
sewage.These blockages have a number of negative social,
financial and environmental impacts, for example polluting
water courses,causing transportation issues(like road
accidents,traffic issues),etc. They can cause flooding, reduce
the life of drainage systems, increase maintenance costs and
can cause environmental damage to watercourses.This project
involves to use the GSM module,WiFi
module(Nodemcu),GPS tracker,Tilt sensor,Temperature
sensor,Ultrasonic sensors,Smoke sensors,etc which are used to
observe the manhole system by monitoring the level of sewage
present in the manhole,sending the position of the
manhole,using the GSM module we are able to send those
information to the respected engineers concerned. This project
is to monitor the manholes present in the cities using the latest
sensors and recent software technologies.

## DESIGN OF THE SYSTEM
We have implemented the IOT based manhole monitoringsystem mainly to prevent the accidents due to clogging ofmanholes during rainy season or opening of lids to overflowwhich are fatal to human lives (especially motorcyclists) whenunseen.This affects families the most when the breadwinner ofthe family expires.Sometimes due to accumulation of poisonousgases ,and high temperature the manhole may catch fire andexplode which is another disaster happens when the manholesystem is not properly monitored.Due to all these followingfactors,there is an exigency for a well structured system tomonitor the manholes constantly and automatically inform therespective concerns regarding the issues.
Our methodology consists of hardware and softwareelements.The hardware element incorporates the interfacing ofNodemcu(WiFi module) with the GSMmodule(800A).Regarding the software part it includesprogramming the sensors so that they trigger the the valueswhen the manhole needs attention.The Nodemcu connects tothe surrounding WiFi network displaying the sensor datathrough web browser, apps, emails, etc which provide constantmonitoring and triggering alerts.This system also sends theSMS to concerned authority phone number.The data is collectedfrom the sensors and constantly sent through WiFi to otherdisplaying platforms(web browser,apps,etc).

**A.Hardware Implementation**

**1)NodeMCU**

The NodeMCU is an open-source software and hardware
development environment built around an inexpensive
System-on-a-Chip called the ESP8266. The ESP8266,
designed and manufactured by Espressif Systems, contains the
crucial elements of a computer: CPU, RAM, networking
(WiFi), and even a modern operating system and SDK. That
makes it an excellent choice for Internet of Things (IoT)
projects of all kinds.

**2)GSM Module**

GSM Modules are one of the commonly used communication
modules in embedded systems. A GSM Module is used to
enable communication between a microcontroller and the
GSM Network.Wireless MODEMs are the MODEM devices
that generate, transmit or decode data from a cellular network,
for establishing communication between the cellular network
and the computer.

**3) NEO-6M GPS module**

The NEO-6M GPS module is a GPS receiver that can locate
all locations on Earth as it is able to track approximately 22
satellites. It consists of a high-performance u-blox 6
positioning engine. Measuring 16 x 12.2 x 2.4 mm, its
compact architecture along with its low power consumption
makes it a good choice for IoT projects. Overall it is a good
cost-effective GPS receiver.

**4) MQ-2 Gas Sensor**

The MQ-2 Gas sensor can detect or measure gases like LPG,
Alcohol,Propane, Hydrogen, CO, and even methane. The
module version of this sensor comes with a Digital Pin which
makes this sensor to operate even without a microcontroller
and that comes in handy when you are only trying to detect
one particular gas. When it comes to measuring the gas in ppm
the analog pin has to be used, the analog pin also TTL driven
and works on 5V and hence can be used with most commonmicrocontrollers.

**5) Ultrasonic Sensor**

Ultrasonic Sensor HC-SR04 is a sensor that can measuredistance.It sends an ultrasonic pulse out at 40kHz which travelsthrough the air and if there is an obstacle or object, it willbounce back to the sensor. By calculating the travel time andthe speed of sound, the distance can be calculated.
6)LM35 Temperature Sensor
LM35 is a temperature measuring device having an analogoutput voltage proportional to the temperature. It providesoutput voltage in Centigrade (Celsius). It does not require anyexternal calibration circuitry. The sensitivity of LM35 is 10mV/degree Celsius. As temperature increases, output voltagealso increases. It is a 3-terminal sensor used to measuresurrounding temperature ranging from -55 °C to 150 °C. LM35gives temperature output which is more precise than thermistoroutput.

**7)Tilt sensor**

Tilt sensors are devices that produce an electrical signal thatvaries with angular movement. These sensors are used tomeasure slope and tilt within a limited range of motion.Sometimes, the tilt sensors are referred to as inclinometersbecause the sensors just generate a signal but inclinometersgenerate both readout anda signal.

**B. Technology**

The technology used in this project is Internet of Things (IoT).This manhole monitoring system consists of informationregarding multiple manholes in the city. Each individualmanhole has information regarding the temperature of themanhole, presence of harmful gases(likeCH4,H2,CO,etc),sending the location of the manhole, presenceof the lid, indicating the level of the water in the manhole, andsending information regarding the whole manhole systemwhether the system has a blockage or overflow issues or lid isopened and so on. This system does not have any humanmonitoring at its location. Thus the information is sent to theserver automatically without any human to computer interactionusing the GSM and WiFi module(Nodemcu). Thus it is easy toestablish multiple manhole monitoring systems and also causeserror free transmission of information either through WiFi orGSM. Thus we use IoT technology.

**C. Protocols Used**

Blynk platform powers low-batch manufacturers of smart homeproducts,complex HVAC systems, agricultural equipment,andeveryone in between.Nodemcu uses blynk software as aninterface to connect the system to the end controller using anapp,web browser,etc. 

## IMPLEMENTATIONA.
- Interfacing of sensors with NodemcuConnections of all the sensors with Nodemcu are the same.Sensors Vcc pin is connected to the 3V pin of the Nodemcu.The GND pin of the sensor is connected to the GND pin of theNodemcu. And the output pins of the sensors are connected tothe analog GPIO pins(0-16) of the Nodemcu.
- Interfacing of Nodemcu with GSM moduleIn this, we have assigned D1 as the TX pin in the Nodemcu andD2 as the RX pin for the same.Thus creating the connectionbetween the GSM and Nodemcu serially
- Nodemcu related codes
This contains all the codes required for the connection to be
established between the various sensors present on board.First,
the information is received from all those sensors which is
converted using analog to digital pins in Nodemcu board.The
output of all those sensors is given to the Nodemcu where the
criteria are checked and the output are displayed through
different channels.
- Blynk side codes:
This code is written in both Arduino ide and Blynk software.
Connecting the Nodemcu with WiFi network and hosting it on
the web browser of Blynk server.For hosting the webpage or
website we need a server. In our system, Nodemcu hosts the
webpage where the final output will be displayed. This means
that the Nodemcu acts as a server i.e Blynk cloud.We can also
access the all data regarding the sensors through Blynk mobile
app.Through this app we can receive the notifications and
alerts regarding the manholes monitoring system,thus the
regulatory authority can take necessary actions.The advantage
s of using Blynk servers, we access those data through
multiple platforms at the same time.This data is to the
specified person through email also.
This system is an effective manhole monitoring system which
ensures the safety of the common man related to accident
s caused by manholes.If this method is implemented then it
will surely help in sustainable and overall development of the
city.Our system provides real time monitoring which is the key
factor in monitoring the system and helps the authority to take
necessary steps to resolve the issue at the earliest.
Our system has overcome many drawbacks where real time
monitoring was a set back and we were able to implement the
system in all possible ways of communicating the sensor data
of the system with the authority through different ways i.e.,by
sending the SMS,through emails which was also a
drawback,by monitoring the system through web browser and
apps.This is the main advantage of our model as we cancommunicate through all these above mentioned methods sothere is no problem of getting the right information to therespective authorities.

## AKNOWLDGEMENT
We would like to express our special thanks to Prof.Chandrashekar Murthy.B.N, for their able guidance and supportin completing our project, for the time spent proofreading andcorrecting our mistakes. Also, we would like to extend ourgratitude to Dr.M N Jayaram, Head of the Department,Electronics and Communication, JSS S&TU, Mysuru forproviding us with all the facility that was required.
## FUTURE SCOPE
Our project can be implemented used in smart cities likeDholera which a newly built Smart City by the governmentwhere the city is fully covered with the WiFi all-over.This isvery useful in manhole monitoring in the Smart Cities by thecontrol and reparing the system at the earliest.Water flowsensor can also be implemented in the future so that theblockage detection becomes efficient.
