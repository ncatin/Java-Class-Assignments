Two modes - Click and Draw Modes

in Click mode every click is recorded as an x,y (wxPoint) in a fix size array of 100 points, more points then that are dropped. Once the user clicks twice, you enter Draw Mode - here you will connect the points (not a polygon) and any other clicks are ignored.Once the mouse is clicked twice again, the drawing is cleared and you are back into Click mode.

Please use a wxPanel as the draw surface.
