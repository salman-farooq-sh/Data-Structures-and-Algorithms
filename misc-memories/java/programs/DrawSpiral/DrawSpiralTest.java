import javax.swing.*;
import java.awt.*;
import java.security.SecureRandom;

public class DrawSpiralTest
{
	public static void main( String[] args )
	{
		JFrame application = new JFrame(  );
		DrawSpiral spiral = new DrawSpiral(  );
		DrawSprial2 spiral2 = new DrawSprial2(  );
		
		application.setDefaultCloseOperation( JFrame.EXIT_ON_CLOSE );
		// uncommment one of these
		// application.add( spiral ); 
		application.add( spiral2 );
		application.setSize( 1200, 800 );
		application.setVisible( true );
		
	}
}

class DrawSpiral extends JPanel
{
	private final static Color VIOLET = new Color( 128, 0, 128 );
	private final static Color INDIGO = new Color( 75, 0, 130 );
	private Color[] rainbowColors = { Color.RED, Color.ORANGE, Color.BLACK.YELLOW, Color.GREEN, Color.BLUE, INDIGO, VIOLET };
	
	SecureRandom rand = new SecureRandom(  );
	
	DrawSpiral( )
	{
		setBackground( Color.BLACK );
	}
	
	private int minusOneTo( int exponent )
	{
		if( exponent % 2 == 0 )
			return 1;
		
		return -1;
	}
	
	public void paintComponent( Graphics g )
	{
		super.paintComponent( g );
		
		int centreX = getWidth() / 2;
		int centreY = getHeight() / 2;
		int lineLength = 20;
		
		for( int i = 0; i < 70; ++i )
		{
			g.setColor( rainbowColors[ rand.nextInt(rainbowColors.length) ] );
			
			g.drawLine( centreX + ( lineLength * minusOneTo( ( i + 0 ) / 2 ) * ( ( i + 2 ) / 4 ) ),
						centreY + ( lineLength * minusOneTo( ( i + 3 ) / 2 ) * ( ( i + 3 ) / 4 ) ),
						centreX + ( lineLength * minusOneTo( ( i + 1 ) / 2 ) * ( ( i + 3 ) / 4 ) ),
						centreY + ( lineLength * minusOneTo( ( i + 4 ) / 2 ) * ( ( i + 4 ) / 4 ) ) );
		}
	}
}

class DrawSprial2 extends JPanel
{
	final int initialRadius = 10;
	final int initialDiameter = 2 * initialRadius;
	
	public void paintComponent( Graphics g )
	{
		super.paintComponent( g );
		
		int centreX = getWidth( ) / 2;
		int centreY = getHeight( ) / 2 - initialRadius;
		
		for( int i = 0; i < 100; ++i )
		{
			g.drawArc( centreX - initialRadius * ( ( i + 1 ) / 2 ) * 2, centreY - i * initialRadius,
					   initialDiameter * ( i + 1 ), initialDiameter * ( i + 1 ),
					   180 * ( i % 2 ), 180 );
		}
	}
}