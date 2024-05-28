# stupidalarm

It's an alarm.

## Build

```
$ make stupidalarm

or

$ cc -o stupidalarm stupidalarm.c

(there's probably a thousand other ways)
```

## Usage

```
stupidalarm <hour of alarm> <minute of alarm>
(time in 24-hour format)
```
If the alarm is not set or invalid, this program will behave as a clock instead.  
  
When the alarm time is reached, the program will ring the system bell (sending "\a" to stdout) every second. Make sure the bell makes an audible sound by setting the alarm time to the current time beforehand.

## Notes

It's using the sleep() function, which may not be avaiable everywhere.
