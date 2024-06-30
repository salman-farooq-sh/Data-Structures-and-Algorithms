// package project.logo;

import javax.swing.*;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Instructions
{
	private ArrayList<String> instructions = new ArrayList<>();
	
	public ArrayList<String> fetch( )
	{
		return instructions;
	}
	
	public int size()
	{
		return instructions.size();
	}
	
	public void scan()
	{
		String instructionsStr = JOptionPane.showInputDialog( "Enter commands for the turtle separated by spaces:" );
		
		StringTokenizer commands = new StringTokenizer( instructionsStr, " " );
		
		while( commands.hasMoreTokens() )
			this.instructions.add( commands.nextToken() );
	}
	
	public String toString()
	{
		StringBuffer str = new StringBuffer( "" );
		
		for( String instruction: instructions )
			str.append( instruction + "\n" );
		
		return str.toString();
	}
	
	public void display()
	{
		JOptionPane.showMessageDialog( null, this.toString(), "Entered Instructions", JOptionPane.PLAIN_MESSAGE );
	}
}