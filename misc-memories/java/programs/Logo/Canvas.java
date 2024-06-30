// package project.logo;

import javax.swing.*;
import java.awt.*;
import java.util.ArrayList;

public class Canvas
{
	private Dimension canvasSize = new Dimension();
	private JFrame canvas = new JFrame( "Canvas" );
	private DrawTurtlePath drawLines = new DrawTurtlePath();
	
	public Canvas( int width, int height )
	{
		canvasSize.setSize( width, height );
		
		canvas.setDefaultCloseOperation( JFrame.EXIT_ON_CLOSE );
		
		canvas.setSize( canvasSize );
		canvas.setResizable( false );
		
		canvas.add( drawLines );
		canvas.setVisible( true );
	}
	
	public void drawLines( ArrayList<Line> lines )
	{
		drawLines.draw( lines );
	}
}