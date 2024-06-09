# ArduinoPatternDisplay
Code for an 8x8 Arduino LED matrix. Displays patterns for microscope images.

--------------------------------------------------------------------------------

Basic Usage:

- Function setLed(int row, int column): Displays a single pixel on the row and column provided. If row/column is set to -1, than the whole row/column is displayed

- Function turnOffLeds(): Turns off all LEDs on the matrix

- Function setHalf(string side): If string = "right", entire right side of matrix is illuminated. If string = "left" the left side is illuminated

  
