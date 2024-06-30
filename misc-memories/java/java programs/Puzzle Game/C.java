import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

class PositionButton extends JButton {
   private int rowNumber;
   private int columnNumber;
   
   public PositionButton( String text, int rowNumber, int columnNumber ) {
      super( text );
      this.rowNumber = rowNumber;
      this.columnNumber = columnNumber;
   }
   
   public int getRowNumber() {
      return rowNumber;
   }
   
   public int getColumnNumber() {
      return columnNumber;
   }
}

class PuzzleGame extends JFrame implements ActionListener {
   private PositionButton[][] grid;
   private int buttonSize = 100;
   private int rows;
   private int columns;
   private Font buttonFont = new Font( "pt mono", Font.PLAIN, 40 );
   
   PuzzleGame() {
      this(3,3);
   }
   
   PuzzleGame( int rows, int columns ) {
      if( rows < 2 || columns < 2 ) {
         throw new IllegalArgumentException( "Row and Column both should be at least 2" );
      }
      
      this.rows = rows;
      this.columns = columns;
      
      setLayout( new GridLayout( rows, columns ) );
      
      grid = new PositionButton[rows][columns];
   
      int counter = 1;
      for( int i = 0; i < rows; i++ ) {
         for( int j = 0; j < columns; j++ ) {
            grid[i][j] = new PositionButton( Integer.toString( counter++ ), i, j );
            grid[i][j].setFont( buttonFont );
            grid[i][j].addActionListener( this );
            add( grid[i][j] );
         }
      }
      grid[rows-1][columns-1].setText( "" );
      
      setSize( buttonSize*columns, buttonSize*rows );
      setDefaultCloseOperation( JFrame.EXIT_ON_CLOSE );
      setResizable( false );
      setLocationRelativeTo( null );
      setVisible( true );
   }
   
   @Override
   public void actionPerformed( ActionEvent e ) {
      int rowNumber = ( (PositionButton) e.getSource() ).getRowNumber();
      int columnNumber = ( (PositionButton) e.getSource() ).getColumnNumber();
   
      if( columnNumber != columns-1 && grid[rowNumber][columnNumber+1].getText().equals( "" ) ) {
         grid[rowNumber][columnNumber+1].setText( grid[rowNumber][columnNumber].getText() );
         grid[rowNumber][columnNumber].setText( "" );
      }

      if( rowNumber != rows-1 && grid[rowNumber+1][columnNumber].getText().equals( "" ) ) {
            grid[rowNumber+1][columnNumber].setText( grid[rowNumber][columnNumber].getText() );
            grid[rowNumber][columnNumber].setText( "" );
      }

      if( columnNumber != 0 && grid[rowNumber][columnNumber-1].getText().equals( "" ) ) {
            grid[rowNumber][columnNumber-1].setText( grid[rowNumber][columnNumber].getText() );
            grid[rowNumber][columnNumber].setText( "" );
      }

      if( rowNumber != 0 && grid[rowNumber-1][columnNumber].getText().equals( "" ) ) {
            grid[rowNumber-1][columnNumber].setText( grid[rowNumber][columnNumber].getText() );
            grid[rowNumber][columnNumber].setText( "" );
      }
   
   
      if( grid[rows-1][columns-1].getText().equals("") ) {
         grid[rows-1][columns-1].setText( Integer.toString( rows*columns ) );
         
         boolean isSolved = true;
         int counter = 1;
         for( int i = 0; i < rows; i++ ) {
            for( int j = 0; j < columns; j++ ) {
               if( Integer.parseInt( grid[i][j].getText() ) != counter++ )
                  isSolved = false;
            }
         }
         grid[rows-1][columns-1].setText( "" );
         
         if( isSolved ) {
            JOptionPane.showMessageDialog( this, "Congratulations! You Won!" );
            grid[rows-1][columns-2].doClick();
         }
      }
   }
}

class Main {
   public static void main( String[] args ) {
      new PuzzleGame( 5, 5 );
   }
}