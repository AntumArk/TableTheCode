# Test procedures

## Required equipment

- Multimeter
- 12V power supply
- Two stepper motors

## Components to check

1. Remove every component
2. Connect 12V supply
3. Check if right polarity is delivered to buck converter terminals
4. Repeat 1
5. Connect buck converter
6. Power on
7. Buck converter should provide 5V
8. Aruino 5V should be high
9. Button supply 5V should be high
10. Power off
11. Connect arduino
12. Power on
13. Aruino powered on
14. Power off
15. Connect button board
16. Power on
17. Press all buttons in series, arduino led should blink after each press.
    1. Or you can check with multimeter
18. Power off
19. Connect BOTH motor controllers and motors
20. Power on. Be ready to abort!
21. Motors should not be spinning.
22. Arduino should not be rebooting nor heating up.

## Usage testing

1. Press left button
2. Left motor moves
3. Press up button
4. Both motors move to one dir
5. Press down button
6. Both motors move in one but oposite direction than step 4
7. Press right button
8. Right motor moves
9. Done :D
