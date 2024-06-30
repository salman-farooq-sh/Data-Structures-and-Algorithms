// package project.logo;

public class LogoMockup
{
	public static void main( String[] args )
	{
		startApplication();
	}
	
	public static void startApplication()
	{
		Instructions instructions = new Instructions();
		instructions.scan();
		
		Turtle turtle = new Turtle( instructions );
		turtle.startMoving();
	}
}

/*	examples:-
		xy.400.400 pd fw.100 rt.90 fw.100 rt.90 fw.100 rt.90 fw.100 pu
		xy.400.400 lt.270 fw.87 rt.90 fw.100 pd rt.120 fw.200 rt.120 fw.200 rt.120 fw.200 pu
		xy.400.400 pd fw.100 lt.72 fw.100 lt.72 fw.100 lt.72 fw.100 lt.72 fw.100 lt.72 pu
		xy.400.400 pd xy.100.100 xy.200.300 xy.400.400
		
		xy.400.400 pd rp.5.[fw.100 lt.72] pu
*/

/*
* Syntax for the commands to the turtle
*
* 		rt.<angle in degrees>
* 		lt.<angle in degrees>
* 		xy.<x coordinate>.<y coordinate>
* 		fw.<distance in unit>
* 		bk.<distance in unit>
* 		pd
* 		pu
*/
