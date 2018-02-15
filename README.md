# Autonomous-Garage-Door-Opener
#Opener that detects when you come home and opens the door

Built on Wemos D1 Mini for <$5
Works with home assistant or any mqtt broker
Built to work with the controller module coming soon, I just need to clean up the code a little 

1. Flash
2. Use web browser to configure
3. plug in using car accessory plug to usb adapter

When you drive into wifi range the device will autoconnect and send the open message.  
When you are leaving it doesn't send the message because it waits to lose the wifi connection and then regain it.
