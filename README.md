# [js-ble-esp32](https://qypol342.github.io/js-ble-esp32/demo_async.html)


## Info
There are a few ways to send a date-time value using only 20 bytes of data over Bluetooth Low Energy (BLE). Here are a few examples:

    Sending the date-time value as a Unix timestamp: A Unix timestamp is a number that represents the number of seconds since January 1, 1970. Since a timestamp is a numeric value, it can be easily represented using a 32-bit integer, which would take up 4 bytes of data.

    Sending the date-time value as a string: You can send the date-time value as a string in a specific format, such as "YYYY-MM-DD HH:MM:SS" which would take up 19 bytes of data.

    Sending the date-time value as a packed binary data: You can use some libraries to pack the date-time value into a 20 bytes of binary data, for example a library like https://github.com/JChristensen/Time can pack the date time in a 12 bytes of binary data.

It's important to note that the above examples are just a few possibilities and the best option will depend on the specific requirements and constraints of your application.

## Data needed

- datetime
- door status 1 byte
- winter time 1 byte
- light sensor value (more than 4 (254))
- 