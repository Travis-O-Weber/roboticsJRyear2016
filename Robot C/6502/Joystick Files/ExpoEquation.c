/*
This code scales the input of the joysticks using an exponential equation.
Formula := (80x^3 / (127^2 * abs(x)) + (20x / abs(x))
Visit http://bit.ly/FTC3486 to find detailed instructions on the usage of this program.
Created by Jacob Mason of The Techno Warriors Advanced FTC #3486
*/

int expo(int n)  // Function expo returns joystick value after smoothing it.
{
      long step1 = n * n; 								// x^2
      long step2 = step1 * n; 						// x^3
      long step3 = step2 * 80; 						// 80x^3
      float step4 = step3 / 16129; 				// 80x^3 / 127^2
      long step5 = step4 / abs(n);				// 80x^3 / (127^2 * abs(x))
      int step6 = 20 * n;									// 20x
      int step7 = step6 / abs(n);					// 20x / abs(x)
      int final = step5 + step7;					// (80x^3 / (127^2 * abs(x))) + (20x / abs(x))
      return final;
}
