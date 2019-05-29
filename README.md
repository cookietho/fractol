# fractol
The goal of this project is to create a program that creates and optimizes a visualized mathematical object called a fractal. Fractal is an abstract mathematical object, like a curve or a surface, which has a similar pattern whatever the scale. 

## Mandatory Part
Your program cannot have memory leaks.</br>
You cannot use global variables.</br>
Your project must follow the Norm.</br>
Your Makefile must compile the project and must contain the usual rules. It must not recompile and re-link the program unless necessary.</br>
You must use the miniLibX.</br>
Your software should offer at least 3 different types of fractals.</br>
It must be possible to make the parameter of the Julia set vary only with the mouse (without clicking).</br>

## Bonus Part
The zoom follow the actual mouse position.</br>
In addition to the zoom: moving with the arrows.</br>
Make the color range shift.</br>
Multi-threading implementation.</br>
Two valid parameters in the command line, resulting in two fractals in two windows.</br>

![Mandelbrot](https://github.com/cookietho/fractol/blob/master/Mandelbrot.gif)

![Julia](https://github.com/cookietho/fractol/blob/master/Julia.gif)

## How to use
1. git clone https://github.com/cookietho/fractol.git
2. cd to fractol directory
3. run make to compile and link the sources
4. make will create an excutable file called fractol
5. excution: ./fractol Set name

![multiple](https://github.com/cookietho/fractol/blob/master/Multiple.gif)
