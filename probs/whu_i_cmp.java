//import java.lang.*;
import java.io.*;
import java.util.Scanner;

public class whu_i_cmp{
    
    static int n , h;
    static int []f = new int[ 1002 ];

    public static void main( String []args ) throws Exception {
        int i , j;

        Scanner in = new Scanner( System.in );
        
        h = in.nextInt( );
        n = in.nextInt( );
        
        for( i = 1 ; i <= n ; ++ i )
            f[ i ] = 0;
        f[ 1 ] = h;

        for( i = 2 ; i <= n ; ++ i )
            for( j = 1 ; j < i ; ++ j )
                if( f[ i ] < ( i - j ) * f[ j ] + j )
                    f[ i ] = ( i - j ) * f[ j ] + j;
       
        System.out.printf( "%d\n" , f[ n ] );
        for( i = 1 ; i <= n ; ++ i )
            System.out.printf( "%d " , f[ i ] );
        System.out.println();
    }
}