// package project.logo;

import javax.swing.*;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Turtle
{
	Canvas canvas = new Canvas( 800, 800 );
	
	private int turtleX = 0;
	private int turtleY = 0;
	private double faceAngle; // In radians. Initial arm of this angle is always the positive x-axis
	private boolean penDown = false;
	private Instructions instructions;
	
	ArrayList<Line> lines = new ArrayList<>(); // holds the parsed lines according to the commands to the turtle
	Line line; // temp reference.
	
	public Turtle( Instructions instructions )
	{
		this.instructions = instructions;
	}
	
	public void startMoving( )
	{
		parseInstructions();
		
		canvas.drawLines( lines );
		instructions.display();
	}
	
	//parses the commands given to the turtle into coordinates of the lines which constitute its path into ArrayList lines
	private void parseInstructions()
	{
		for( String instruction: instructions.fetch( ) )
		{
			StringTokenizer tokenizer = new StringTokenizer( instruction, "." );
			
			switch( tokenizer.nextToken() )
			{
				case "rt":
					this.faceAngle -= Math.toRadians( Double.parseDouble( tokenizer.nextToken() ) );
					break;
				
				case "lt":
					this.faceAngle += Math.toRadians( Double.parseDouble( tokenizer.nextToken() ) );
					break;
				
				case "xy":
					int x = Integer.parseInt( tokenizer.nextToken() );
					int y = Integer.parseInt( tokenizer.nextToken() );
					toXY( x, y );
					break;
				
				case "fw":
					moveForward( Integer.parseInt( tokenizer.nextToken() ) );
					break;
				
				case "bk":
					moveBackwards( Integer.parseInt( tokenizer.nextToken() ) );
					break;
				
				case "pu":
					penDown = false;
					break;
				
				case "pd":
					penDown = true;
					break;
				
				case "rp":
					
					break;
				
				default:
					JOptionPane.showMessageDialog( null, "Invalid Instruction encountered", "Error", JOptionPane.ERROR_MESSAGE );
					return;
			}
		}
	}
	
	
	private void toXY( int x, int y )
	{
		if( penDown )
		{
			line = new Line( turtleX, turtleY, x, y );
			lines.add( line );
		}
		
		turtleX = x;
		turtleY = y;
	}
	
	private void moveForward( int distance )
	{
		int destinationX = ( int ) ( turtleX + distance * Math.cos( faceAngle ) );
		int destinationY = ( int ) ( turtleY - distance * Math.sin( faceAngle ) );
		
		if( penDown )
		{
			line = new Line( turtleX, turtleY, destinationX, destinationY );
			lines.add( line );
		}
		
		turtleX = destinationX;
		turtleY = destinationY;
	}
	
	private void moveBackwards( int distance )
	{
		faceAngle += Math.PI;
		moveForward( distance );
	}
}
