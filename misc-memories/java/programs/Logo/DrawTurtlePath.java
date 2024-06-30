// package project.logo;

import javax.swing.*;
import java.awt.*;
import java.util.ArrayList;

public class DrawTurtlePath extends JPanel
{
	ArrayList<Line> lines;
	
	public DrawTurtlePath()
	{
		setBackground( Color.BLACK );
	}
	
	
	public void paintComponent( Graphics g )
	{
		super.paintComponent( g );
		
		g.setColor( Color.WHITE );
		for( Line line: lines )
			g.drawLine( line.x1( ), line.y1( ), line.x2( ), line.y2( ) );
		
		
		
		g.setColor( Color.RED );
		g.fillOval( getWidth()/2 - 4, getHeight()/2 - 4 + 11, 8,8 );
		
		g.drawString( "Red Dot = canvas centre", 2,14 );
	}
	
	public void draw( ArrayList<Line> lines )
	{
		this.lines = lines;
		
		repaint();
	}
	
}
